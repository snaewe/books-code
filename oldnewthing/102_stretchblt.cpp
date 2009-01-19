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

HBITMAP g_hbm;

void
PaintContent(HWND hwnd, PAINTSTRUCT *pps)
{
 HDC hdcMem = CreateCompatibleDC(pps->hdc);
 if (hdcMem) {
  HBITMAP hbmPrev = SelectBitmap(hdcMem, g_hbm);
  if (hbmPrev) {
    BITMAP bm;
    if (GetObject(g_hbm, sizeof(bm), &bm)) {
     RECT rc;
     GetClientRect(hwnd, &rc);
     int cxClient = rc.right - rc.left;
     int cyClient = rc.bottom - rc.top;
     StretchBlt(pps->hdc, rc.left, rc.top, cxClient, cyClient,
         hdcMem, 0, 0, 1, 1, SRCCOPY);
     BitBlt(pps->hdc, rc.left, rc.top, cxClient, cyClient,
         hdcMem, 0, 0, SRCCOPY);
    }
    SelectBitmap(hdcMem, hbmPrev);
  }
  DeleteDC(hdcMem);
 }
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

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hinstPrev,
                   LPSTR lpCmdLine, int nShowCmd)
{
    MSG msg;
    HWND hwnd;

    g_hinst = hinst;

    if (!InitApp()) return 0;

    if (SUCCEEDED(CoInitialize(NULL))) {/* In case we use COM */

        g_hbm = (HBITMAP)LoadImage(g_hinst, lpCmdLine,
                           IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        if (!g_hbm) return 0;

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

        DeleteObject(g_hbm);
    }

    return 0;
}
