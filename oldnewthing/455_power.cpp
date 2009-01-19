#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <ole2.h>
#include <commctrl.h>
#include <shlwapi.h>

HINSTANCE g_hinst;                          /* This application's HINSTANCE */
HWND g_hwndChild;                           /* Optional child window */

// If we cannot determine the power status, assume we're not on battery
BOOL IsOnBatteryPower()
{
 SYSTEM_POWER_STATUS sps;
 return GetSystemPowerStatus(&sps) && sps.ACLineStatus == 0;
}

BOOL g_fTimerRunning = FALSE;
char g_chBackground = '0';
#define IDT_BACKGROUND 1

void CALLBACK OnBackgroundTimer(HWND hwnd, UINT uMsg,
                                UINT_PTR idTimer, DWORD tm)
{
 g_chBackground++;
 if (g_chBackground == '9' + 1) g_chBackground = '0';
 InvalidateRect(hwnd, NULL, TRUE);
}

void OnPowerChange(HWND hwnd)
{
 BOOL fWantTimerRunning = !!IsOnBatteryPower();
 if (g_fTimerRunning != fWantTimerRunning) {
  g_fTimerRunning = fWantTimerRunning;
  if (fWantTimerRunning) {
   SetTimer(hwnd, IDT_BACKGROUND, 250, OnBackgroundTimer);
  } else {
   KillTimer(hwnd, IDT_BACKGROUND);
  }
 }
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
    OnPowerChange(hwnd);
    return TRUE;
}

void
OnDestroy(HWND hwnd)
{
    PostQuitMessage(0);
}

LRESULT OnPowerBroadcast(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
 switch (wParam) {
 case PBT_APMPOWERSTATUSCHANGE:
   OnPowerChange(hwnd);
   break;
 }
 return TRUE;
}

void
PaintContent(HWND hwnd, PAINTSTRUCT *pps)
{
 TextOut(pps->hdc, 0, 0, &g_chBackground, 1);
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
    case WM_POWERBROADCAST:
     return OnPowerBroadcast(hwnd, wParam, lParam);
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
