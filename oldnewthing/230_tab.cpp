#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <ole2.h>
#include <commctrl.h>
#include <shlwapi.h>

HINSTANCE g_hinst;                          /* This application's HINSTANCE */
HWND g_hwndChild;                           /* Optional child window */

HWND g_hwndLastFocus;

void OnSetFocus(HWND hwnd, HWND hwndOldFocus)
{
    if (g_hwndLastFocus) {
        SetFocus(g_hwndLastFocus);
    }
}

void OnActivate(HWND hwnd, UINT state,
                HWND hwndActDeact, BOOL fMinimized)
{
    if (state == WA_INACTIVE) {
        g_hwndLastFocus = GetFocus();
    }
}

// Just display a messagebox so you can see something
void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch (id) {
    case 100:
        MessageBox(hwnd, TEXT("Button 1 pushed"),
                   TEXT("Title"), MB_OK);
        break;
    case 101:
        MessageBox(hwnd, TEXT("Button 2 pushed"),
                   TEXT("Title"), MB_OK);
        break;
    case IDCANCEL:
        MessageBox(hwnd, TEXT("Cancel pushed"),
                   TEXT("Title"), MB_OK);
        break;
    }
}

BOOL
OnCreate(HWND hwnd, LPCREATESTRUCT lpcs)
{
    HWND hwndChild =
        CreateWindow(
        TEXT("button"),                 /* Class Name */
        TEXT("Button &1"),              /* Title */
        WS_CHILD | WS_VISIBLE | WS_TABSTOP |
        BS_DEFPUSHBUTTON | BS_TEXT,     /* Style */
        0, 0, 100, 100,                 /* Position and size */
        hwnd,                           /* Parent */
        (HMENU)100,                     /* Child ID */
        g_hinst,                        /* Instance */
        0);                             /* No special parameters */
    if (!hwndChild) return FALSE;
    g_hwndLastFocus = hwndChild;

    hwndChild =
        CreateWindow(
        TEXT("button"),                 /* Class Name */
        TEXT("Button &2"),              /* Title */
        WS_CHILD | WS_VISIBLE | WS_TABSTOP |
        BS_PUSHBUTTON | BS_TEXT,        /* Style */
        100, 0, 100, 100,               /* Position and size */
        hwnd,                           /* Parent */
        (HMENU)101,                     /* Child ID */
        g_hinst,                        /* Instance */
        0);                             /* No special parameters */
    if (!hwndChild) return FALSE;

    hwndChild =
        CreateWindow(
        TEXT("button"),                 /* Class Name */
        TEXT("Cancel"),                 /* Title */
        WS_CHILD | WS_VISIBLE | WS_TABSTOP |
        BS_PUSHBUTTON | BS_TEXT,        /* Style */
        200, 0, 100, 100,               /* Position and size */
        hwnd,                           /* Parent */
        (HMENU)IDCANCEL,                /* Child ID */
        g_hinst,                        /* Instance */
        0);                             /* No special parameters */
    if (!hwndChild) return FALSE;

    return TRUE;
}

void
OnSize(HWND hwnd, UINT state, int cx, int cy)
{
    if (g_hwndChild) {
        MoveWindow(g_hwndChild, 0, 0, cx, cy, TRUE);
    }
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
    HANDLE_MSG(hwnd, WM_COMMAND, OnCommand);
    HANDLE_MSG(hwnd, WM_ACTIVATE, OnActivate);
    HANDLE_MSG(hwnd, WM_SETFOCUS, OnSetFocus);

    // Add blank case statements for these to ensure we don't use them
    // by mistake.
    case DM_GETDEFID: break;
    case DM_SETDEFID: break;
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
            if (IsDialogMessage(hwnd, &msg)) {
                /* Already handled by dialog manager */
            } else {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        CoUninitialize();
    }

    return 0;
}

