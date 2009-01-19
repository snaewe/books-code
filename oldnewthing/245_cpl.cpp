#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <ole2.h>
#include <commctrl.h>
#include <shlwapi.h>
#include <cpl.h>

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

LRESULT CALLBACK
WndProc(HWND hwnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uiMsg) {
    HANDLE_MSG(hwnd, WM_CREATE, OnCreate);
    HANDLE_MSG(hwnd, WM_SIZE, OnSize);
    HANDLE_MSG(hwnd, WM_DESTROY, OnDestroy);
    HANDLE_MSG(hwnd, WM_PAINT, OnPaint);
    case WM_PRINTCLIENT: OnPrintClient(hwnd, (HDC)wParam); return 0;
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

void RunControlPanel(HWND hwnd, LPCTSTR pszPath)
{
  // ---- We'll talk about these lines later
  // Maybe this control panel application has a custom manifest
  ACTCTX act = { 0 };
  act.cbSize = sizeof(act);
  act.dwFlags = 0;
  act.lpSource = pszPath;
  act.lpResourceName = MAKEINTRESOURCE(123);
  HANDLE hctx = CreateActCtx(&act);
  ULONG_PTR ulCookie;
  if (hctx == INVALID_HANDLE_VALUE ||
      ActivateActCtx(hctx, &ulCookie)) {

    HINSTANCE hinstCPL = LoadLibrary(pszPath);
    if (hinstCPL) {
      APPLET_PROC pfnCPlApplet = (APPLET_PROC)
        GetProcAddress(hinstCPL, "CPlApplet");
      if (pfnCPlApplet) {
        if (pfnCPlApplet(hwnd, CPL_INIT, 0, 0)) {
          int cApplets = pfnCPlApplet(hwnd, CPL_GETCOUNT, 0, 0);
          //  We're going to run application zero
          //  (In real life we might show the user a list of them
          //  and let them pick one)
          if (cApplets > 0) {
            CPLINFO cpli;
            pfnCPlApplet(hwnd, CPL_INQUIRE, 0, (LPARAM)&cpli);
            pfnCPlApplet(hwnd, CPL_DBLCLK, 0, cpli.lData);
            pfnCPlApplet(hwnd, CPL_STOP, 0, cpli.lData);
          }
        }
        pfnCPlApplet(hwnd, CPL_EXIT, 0, 0);
      }

      FreeLibrary(hinstCPL);
    }

    // ---- We'll talk about these lines later
    if (hctx != INVALID_HANDLE_VALUE) {
      DeactivateActCtx(0, ulCookie);
      ReleaseActCtx(hctx);
    }
  }
}


int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hinstPrev,
                   LPSTR lpCmdLine, int nShowCmd)
{
  HWND hwnd;

  g_hinst = hinst;

  if (!InitApp()) return 0;

  if (SUCCEEDED(CoInitialize(NULL))) {/* In case we use COM */

      hwnd = CreateWindow(
          "Scratch",                      /* Class Name */
          "Scratch",                      /* Title */
          WS_OVERLAPPEDWINDOW,            /* Style */
          CW_USEDEFAULT, CW_USEDEFAULT,   /* Position */
          CW_USEDEFAULT, CW_USEDEFAULT,   /* Size */
          NULL,                           /* Parent */
          NULL,                           /* No menu */
          hinst,                          /* Instance */
          0);                             /* No special parameters */
      if (hwnd) {
        TCHAR szPath[MAX_PATH];
        LPTSTR pszLast;
        DWORD cch = SearchPath(NULL, TEXT("access.cpl"),
                     NULL, MAX_PATH, szPath, &pszLast);
        if (cch > 0 && cch < MAX_PATH) {
          RunControlPanel(hwnd, szPath);
      }
    }
    CoUninitialize();
  }

  return 0;
}

