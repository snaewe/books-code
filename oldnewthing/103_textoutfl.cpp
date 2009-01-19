#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <ole2.h>
#include <commctrl.h>
#include <shlwapi.h>
#include <mlang.h>

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

HRESULT TextOutFL(HDC hdc, int x, int y, LPCWSTR psz, int cch)
{
  HRESULT hr;
  IMLangFontLink2 *pfl;
  if (SUCCEEDED(hr = CoCreateInstance(CLSID_CMultiLanguage,
                      NULL, CLSCTX_ALL, IID_IMLangFontLink2,
                      (void**)&pfl))) {
    HFONT hfOrig = (HFONT)GetCurrentObject(hdc, OBJ_FONT);
    POINT ptOrig;
    DWORD dwAlignOrig = GetTextAlign(hdc);
    if (!(dwAlignOrig & TA_UPDATECP)) {
      SetTextAlign(hdc, dwAlignOrig | TA_UPDATECP);
    }
    MoveToEx(hdc, x, y, &ptOrig);
    DWORD dwFontCodePages = 0;
    hr = pfl->GetFontCodePages(hdc, hfOrig, &dwFontCodePages);
    if (SUCCEEDED(hr)) {
      while (cch > 0) {
        DWORD dwActualCodePages;
        long cchActual;
        hr = pfl->GetStrCodePages(psz, cch, dwFontCodePages,
                                  &dwActualCodePages, &cchActual);
        if (FAILED(hr)) {
          break;
        }

        if (dwActualCodePages & dwFontCodePages) {
          TextOutW(hdc, 0, 0, psz, cchActual);
        } else {
          HFONT hfLinked;
          if (FAILED(hr = pfl->MapFont(hdc, dwActualCodePages, 0,
                                       &hfLinked))) {
            break;
          }
          SelectFont(hdc, hfLinked);
          TextOutW(hdc, 0, 0, psz, cchActual);
          SelectFont(hdc, hfOrig);
          pfl->ReleaseFont(hfLinked);
        }
        psz += cchActual;
        cch -= cchActual;
      }
      if (FAILED(hr)) {
        //  We started outputting characters so we must finish.
        //  Do the rest without font linking since we have
        //  no choice.
        TextOutW(hdc, 0, 0, psz, cch);
        hr = S_FALSE;
      }
    }

    pfl->Release();

    if (!(dwAlignOrig & TA_UPDATECP)) {
      SetTextAlign(hdc, dwAlignOrig);
      MoveToEx(hdc, ptOrig.x, ptOrig.y, NULL);
    }
  }

  return hr;
}

void TextOutTryFL(HDC hdc, int x, int y, LPCWSTR psz, int cch)
{
  if (FAILED(TextOutFL(hdc, x, y, psz, cch))) {
    TextOutW(hdc, x, y, psz, cch);
  }
}

void
PaintContent(HWND hwnd, PAINTSTRUCT *pps)
{
  TextOutTryFL(pps->hdc, 0, 0,
               L"ABC\x0410\x0411\x0412\x0E01\x0E02\x0E03", 9);
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
