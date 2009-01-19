#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <ole2.h>
#include <commctrl.h>
#include <shlwapi.h>

HINSTANCE g_hinst;                          /* This application's HINSTANCE */
HWND g_hwndChild;                           /* Optional child window */

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

// fEnded tells us if the dialog has been ended.
// When ended, iResult contains the result code.

typedef struct DIALOGSTATE {
 BOOL fEnded;
 int iResult;
} DIALOGSTATE;

void EndManualModalDialog(HWND hdlg, int iResult)
{
 DIALOGSTATE *pds = reinterpret_cast<DIALOGSTATE*>
     (GetWindowLongPtr(hdlg, DWLP_USER));
 if (pds) {
  pds->iResult = iResult;
  pds->fEnded = TRUE;
  PostMessage(hdlg, WM_NULL, 0, 0);
 }
}

INT_PTR CALLBACK DlgProc(
    HWND hdlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
 switch (uMsg) {
 case WM_INITDIALOG:
  SetWindowLongPtr(hdlg, DWLP_USER, lParam);
  return TRUE;
 case WM_COMMAND:
  switch (GET_WM_COMMAND_ID(wParam, lParam)) {
  case IDOK:
   EndManualModalDialog(hdlg, IDOK);
   break;
  case IDCANCEL:
   EndManualModalDialog(hdlg, IDCANCEL);
   break;
  }
 }
 return FALSE;
}

int DoModal(HWND hwnd)
{
 DIALOGSTATE ds = { 0 };
 HWND hdlg = CreateDialogParam(g_hinst, MAKEINTRESOURCE(1),
             hwnd, DlgProc, reinterpret_cast<LPARAM>(&ds));
 if (!hdlg) {
  return -1;
 }

 EnableWindow(hwnd, FALSE);
 MSG msg;
 msg.message = WM_NULL; // anything that isn't WM_QUIT
 while (!ds.fEnded) {
  if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
   if (msg.message == WM_QUIT) {
    break;
   } else
   if (!IsDialogMessage(hdlg, &msg)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
   }
  } else if (!ds.fEnded) {
   WaitMessage();
  }
 }
 if (msg.message == WM_QUIT) {
  PostQuitMessage((int)msg.wParam);
 }
 EnableWindow(hwnd, TRUE);
 DestroyWindow(hdlg);
 return ds.iResult;
}

void OnChar(HWND hwnd, TCHAR ch, int cRepeat)
{
 switch (ch) {
 case ' ': DoModal(hwnd); break;
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

#ifdef RC_INVOKED

1 DIALOGEX DISCARDABLE  32, 32, 200, 40
STYLE DS_MODALFRAME | DS_SHELLFONT | WS_POPUP |
      WS_VISIBLE | WS_CAPTION | WS_SYSMENU
CAPTION "Sample"
FONT 8, "MS Shell Dlg"
BEGIN
 DEFPUSHBUTTON "OK",IDOK,20,20,50,14
 PUSHBUTTON "Cancel",IDCANCEL,74,20,50,14
END

#endif
