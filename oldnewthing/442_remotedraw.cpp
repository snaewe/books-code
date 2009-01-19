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

// new function
void Draw(HWND hwnd, HDC hdc, PAINTSTRUCT *pps)
{
 FillRect(hdc, &pps->rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
 RECT rc;
 GetClientRect(hwnd, &rc);
 for (int i = -10; i < 10; i++) {
  TextOut(hdc, 0, i * 15 + rc.bottom / 2, TEXT("Blah blah"), 9);
 }
}

void PaintContent(HWND hwnd, PAINTSTRUCT *pps)
{
 if (GetSystemMetrics(SM_REMOTESESSION)) {
  Draw(hwnd, pps->hdc, pps);
 } else if (!IsRectEmpty(&pps->rcPaint)) {
  HDC hdc = CreateCompatibleDC(pps->hdc);
  if (hdc) {
   int x = pps->rcPaint.left;
   int y = pps->rcPaint.top;
   int cx = pps->rcPaint.right - pps->rcPaint.left;
   int cy = pps->rcPaint.bottom - pps->rcPaint.top;
   HBITMAP hbm = CreateCompatibleBitmap(pps->hdc, cx, cy);
   if (hbm) {
    HBITMAP hbmPrev = SelectBitmap(hdc, hbm);
    SetWindowOrgEx(hdc, x, y, NULL);

    Draw(hwnd, hdc, pps);

    BitBlt(pps->hdc, x, y, cx, cy, hdc, x, y, SRCCOPY);

    SelectObject(hdc, hbmPrev);
    DeleteObject(hbm);
   }
   DeleteDC(hdc);
  }
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
    case WM_ERASEBKGND: return 1;
    }

    return DefWindowProc(hwnd, uiMsg, wParam, lParam);
}

BOOL
InitApp(void)
{
    WNDCLASS wc;

    wc.style = CS_VREDRAW | CS_HREDRAW;
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
