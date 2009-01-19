#include <windows.h>
#include <windowsx.h>

HINSTANCE g_hinst;

INT_PTR CALLBACK
InnerDlgProc(HWND hdlg, UINT wm, WPARAM wParam, LPARAM lParam)
{
 switch (wm) {
 case WM_INITDIALOG:
  return TRUE;
 }
 return FALSE;
}

void GetWindowRectRelative(HWND hwnd, LPRECT prc)
{
 GetWindowRect(hwnd, prc);
 MapWindowRect(NULL, GetAncestor(hwnd, GA_PARENT), prc);
}

void SlideWindow(HWND hwnd, int dx, int dy)
{
 RECT rc;
 GetWindowRectRelative(hwnd, &rc);
 SetWindowPos(hwnd, NULL, rc.left + dx, rc.top + dy, 0, 0,
              SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
}

void GrowWindow(HWND hwnd, int dx, int dy)
{
 RECT rc;
 GetWindowRectRelative(hwnd, &rc);
 int cx = rc.right - rc.left;
 int cy = rc.bottom - rc.top;
 SetWindowPos(hwnd, NULL, 0, 0, cx + dx, cy + dy,
              SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
}

void OnInitDialog(HWND hdlg)
{
 HWND hdlgInner = CreateDialog(g_hinst,
                               MAKEINTRESOURCE(2), hdlg, InnerDlgProc);
 if (hdlgInner) {
  RECT rcInner;
  GetWindowRectRelative(hdlgInner, &rcInner);
  RECT rcDst;
  GetWindowRectRelative(GetDlgItem(hdlg, 100), &rcDst);
  SetWindowPos(hdlgInner, HWND_TOP, rcDst.left, rcDst.top, 0, 0,
               SWP_NOSIZE | SWP_NOACTIVATE);

  int cxInner = rcInner.right - rcInner.left;
  int cyInner = rcInner.bottom - rcInner.top;
  int cxDst = rcDst.right - rcDst.left;
  int cyDst = rcDst.bottom - rcDst.top;
  int dx = cxInner - cxDst;
  int dy = cyInner - cyDst;
  SlideWindow(GetDlgItem(hdlg, IDOK), dx, dy);
  SlideWindow(GetDlgItem(hdlg, IDCANCEL), dx, dy);
  GrowWindow(hdlg, dx, dy);
 } else {
  EndDialog(hdlg, IDCANCEL);
 }
}

INT_PTR CALLBACK
OuterDlgProc(HWND hdlg, UINT wm, WPARAM wParam, LPARAM lParam)
{
 switch (wm) {
 case WM_INITDIALOG:
  OnInitDialog(hdlg);
  return TRUE;
 case WM_COMMAND:
  switch (GET_WM_COMMAND_ID(wParam, lParam)) {
  case IDOK:
   EndDialog(hdlg, IDOK);
   break;
  case IDCANCEL:
   EndDialog(hdlg, IDCANCEL);
   break;
  }
 }
 return FALSE;
}

int PASCAL
WinMain(HINSTANCE hinst, HINSTANCE, LPSTR, int nShowCmd)
{
 g_hinst = hinst;
 INT_PTR iRc = DialogBox(g_hinst, MAKEINTRESOURCE(1),
                         NULL, OuterDlgProc);
 return 0;
}

#ifdef RC_INVOKED

1 DIALOG 0, 0, 212, 188
STYLE DS_SHELLFONT | WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU
CAPTION "Sample"
FONT 8, "MS Shell Dlg"
BEGIN
    CONTROL         "",100,"static",SS_GRAYRECT | NOT WS_VISIBLE,0,0,212,160
    DEFPUSHBUTTON   "OK",IDOK,98,167,50,14
    PUSHBUTTON      "Cancel",IDCANCEL,155,167,50,14
END

2 DIALOG 0, 0, 148, 62
STYLE DS_SHELLFONT | DS_CONTROL | WS_CHILD | WS_VISIBLE
CAPTION "Inner"
FONT 8, "MS Shell Dlg"
BEGIN
    GROUPBOX        "&Options",-1,7,7,134,55
    AUTOCHECKBOX    "&Autosave",100,14,24,120,10
    AUTOCHECKBOX    "&Resize images to fit window",101,14,36,120,10
END

#endif
