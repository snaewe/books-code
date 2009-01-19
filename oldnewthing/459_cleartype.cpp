#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <ole2.h>
#include <commctrl.h>
#include <shlwapi.h>

HINSTANCE g_hinst;                          /* This application's HINSTANCE */
HWND g_hwndChild;                           /* Optional child window */

HFONT g_hfAntialias;
HFONT g_hfClearType;

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
 g_hfAntialias = CreateFont(-20, 0, 0, 0, FW_NORMAL, 0, 0, 0,
    DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
    ANTIALIASED_QUALITY, DEFAULT_PITCH, TEXT("Tahoma"));
 g_hfClearType = CreateFont(-20, 0, 0, 0, FW_NORMAL, 0, 0, 0,
    DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
    CLEARTYPE_QUALITY, DEFAULT_PITCH, TEXT("Tahoma"));
 return g_hfAntialias && g_hfClearType;
}

void
OnDestroy(HWND hwnd)
{
 if (g_hfAntialias) DeleteObject(g_hfAntialias);
 if (g_hfClearType) DeleteObject(g_hfClearType);
 PostQuitMessage(0);
}

void MultiPaint(HDC hdc, int x, int y, int n)
{
 LPCTSTR psz = TEXT("The quick brown fox jumps over the lazy dog.");
 int cch = lstrlen(psz);
 for (int i = 0; i < n; i++) {
   TextOut(hdc, x, y, psz, cch);
 }
}

void
PaintContent(HWND hwnd, PAINTSTRUCT *pps)
{
 int iModePrev = SetBkMode(pps->hdc, TRANSPARENT);
 HFONT hfPrev = SelectFont(pps->hdc, g_hfAntialias);
 MultiPaint(pps->hdc, 10,  0, 1);
 MultiPaint(pps->hdc, 10, 20, 2);
 MultiPaint(pps->hdc, 10, 40, 3);
 SelectFont(pps->hdc, g_hfClearType);
 MultiPaint(pps->hdc, 10, 80, 1);
 MultiPaint(pps->hdc, 10,100, 2);
 MultiPaint(pps->hdc, 10,120, 3);
 SelectFont(pps->hdc, hfPrev);
 SetBkMode(pps->hdc, iModePrev);
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

