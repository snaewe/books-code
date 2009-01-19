#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <ole2.h>
#include <commctrl.h>
#include <shlwapi.h>

HINSTANCE g_hinst;                          /* This application's HINSTANCE */
HWND g_hwndChild;                           /* Optional child window */

ATOM RegisterScratchWindowClass(void)
{
  WNDCLASS wc = {
        0,                              // style
        DefWindowProc,                  // lpfnWndProc
        0,                              // cbClsExtra
        0,                              // cbWndExtra
        g_hinst,                        // this file's HINSTANCE
        NULL,                           // hIcon
        LoadCursor(NULL, IDC_ARROW),    // hCursor
        (HBRUSH)(COLOR_BTNFACE+1),      // hbrBackground
        NULL,                           // lpszMenuName
        TEXT("ScratchWindow"),          // lpszClassName
  };

  return RegisterClass(&wc);
}

HWND
CreateScratchWindow(HWND hwndParent, WNDPROC wp)
{
  HWND hwnd;
  hwnd = CreateWindow(TEXT("ScratchWindow"), NULL,
                      hwndParent ? WS_CHILD : WS_OVERLAPPED,
                  0, 0, 0, 0, hwndParent, NULL, NULL, NULL);
  if (hwnd) {
    SubclassWindow(hwnd, wp);
  }
  return hwnd;
}


void
OnSize(HWND hwnd, UINT state, int cx, int cy)
{
    if (g_hwndChild) {
        MoveWindow(g_hwndChild, 0, 0, cx, cy, TRUE);
    }
}

BOOL
OnCreate(HWND hwnd, LPCREATESTRUCT lpcs)
{
    return TRUE;
}

void
OnDestroy(HWND hwnd)
{
    PostQuitMessage(0);
}

void
PaintContent(HWND hwnd, PAINTSTRUCT *pps)
{
}

void
OnPaint(HWND hwnd)
{
    PAINTSTRUCT ps;
    BeginPaint(hwnd, &ps);
    PaintContent(hwnd, &ps);
    EndPaint(hwnd, &ps);
}

void
OnPrintClient(HWND hwnd, HDC hdc)
{
    PAINTSTRUCT ps;
    ps.hdc = hdc;
    GetClientRect(hwnd, &ps.rcPaint);
    ps.fErase = FALSE;
    PaintContent(hwnd, &ps);
}

#define IDT_TOOLATE     1

typedef struct TOOLATEINFO {
 BOOL fTimedOut;
 HWND hwndReenable;
} TOOLATEINFO;

void CALLBACK
MsgBoxTooLateProc(HWND hwnd, UINT uiMsg, UINT_PTR idEvent, DWORD dwTime)
{
  TOOLATEINFO *ptli = reinterpret_cast<TOOLATEINFO*>(
    GetWindowLongPtr(hwnd, GWLP_USERDATA));
  if (ptli) {
    ptli->fTimedOut = TRUE;
    if (ptli->hwndReenable) {
       EnableWindow(ptli->hwndReenable, TRUE);
    }
    PostQuitMessage(0);
  }
}

int TimedMessageBox(HWND hwndOwner, LPCTSTR ptszText,
    LPCTSTR ptszCaption, UINT uType, DWORD dwTimeout)
{
  TOOLATEINFO tli;
  tli.fTimedOut = FALSE;
  BOOL fWasEnabled = hwndOwner && IsWindowEnabled(hwndOwner);
  tli.hwndReenable = fWasEnabled ? hwndOwner : NULL;

  HWND hwndScratch = CreateScratchWindow(hwndOwner, DefWindowProc);
  if (hwndScratch) {
      SetWindowLongPtr(hwndScratch, GWLP_USERDATA,
                       reinterpret_cast<LPARAM>(&tli));
      SetTimer(hwndScratch, IDT_TOOLATE, dwTimeout, MsgBoxTooLateProc);
  }
  int iResult = MessageBox(hwndOwner, ptszText, ptszCaption, uType);
  if (hwndScratch) {
    KillTimer(hwndScratch, IDT_TOOLATE);
    if (tli.fTimedOut) { // We timed out
      MSG msg;
      // Eat the fake WM_QUIT message we generated
      if (!PeekMessage(&msg, NULL, WM_QUIT, WM_QUIT, PM_REMOVE))
{OutputDebugStringA("No quit!\r\n");}
      iResult = -1;
    }
    DestroyWindow(hwndScratch);
  }
  return iResult;
}

void OnChar(HWND hwnd, TCHAR ch, int cRepeat)
{
  switch (ch) {
  case ' ':
    TimedMessageBox(hwnd, TEXT("text"), TEXT("caption"),
                    MB_OK, 2000);
    break;
  }
}


LRESULT CALLBACK
WndProc(HWND hwnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uiMsg) {
    HANDLE_MSG(hwnd, WM_CREATE, OnCreate);
    HANDLE_MSG(hwnd, WM_SIZE, OnSize);
    HANDLE_MSG(hwnd, WM_DESTROY, OnDestroy);
    HANDLE_MSG(hwnd, WM_PAINT, OnPaint);
    case WM_PRINTCLIENT: OnPrintClient(hwnd, (HDC)wParam); return 0;
    HANDLE_MSG(hwnd, WM_CHAR, OnChar);
    }

    return DefWindowProc(hwnd, uiMsg, wParam, lParam);
}

BOOL
InitApp(void)
{
    WNDCLASS wc;

    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = g_hinst;
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = TEXT("Scratch");

    if (!RegisterClass(&wc)) return FALSE;

    InitCommonControls();               /* In case we use a common control */
    RegisterScratchWindowClass();

    return TRUE;
}

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hinstPrev,
                   LPSTR lpCmdLine, int nShowCmd)
{
    MSG msg;
    HWND hwnd;

    g_hinst = hinst;

    if (!InitApp()) return 0;

    if (SUCCEEDED(CoInitialize(NULL))) {/* In case we use COM */

        hwnd = CreateWindow(
            TEXT("Scratch"),                /* Class Name */
            TEXT("Scratch"),                /* Title */
            WS_OVERLAPPEDWINDOW,            /* Style */
            CW_USEDEFAULT, CW_USEDEFAULT,   /* Position */
            CW_USEDEFAULT, CW_USEDEFAULT,   /* Size */
            NULL,                           /* Parent */
            NULL,                           /* No menu */
            hinst,                          /* Instance */
            0);                             /* No special parameters */

        ShowWindow(hwnd, nShowCmd);

        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        CoUninitialize();
    }

    return 0;
}
