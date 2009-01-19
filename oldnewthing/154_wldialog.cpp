#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <ole2.h>
#include <commctrl.h>
#include <shlwapi.h>

HINSTANCE g_hinst;                          /* This application's HINSTANCE */
HWND g_hwndChild;                           /* Optional child window */

class WLDialogBox
{
public:
  virtual LRESULT WLDlgProc(HWND hdlg, UINT uMsg,
                            WPARAM wParam, LPARAM lParam)
  {
    return DefDlgProcEx(hdlg, uMsg, wParam, lParam, &m_fRecursing);
  }

  INT_PTR DoModal(HINSTANCE hinst, LPCTSTR pszTemplate, HWND hwndParent)
  {
    m_fRecursing = FALSE;
    return DialogBoxParam(hinst, pszTemplate, hwndParent,
                          s_DlgProc, (LPARAM)this);
  }

private:
  static INT_PTR CALLBACK s_DlgProc(HWND hdlg, UINT uMsg,
                                    WPARAM wParam, LPARAM lParam)
  {
    if (uMsg == WM_INITDIALOG) {
      SetWindowLongPtr(hdlg, DWLP_USER, lParam);
    }

    WLDialogBox *self = (WLDialogBox*)GetWindowLongPtr(hdlg, DWLP_USER);
    if (!self) {
      return FALSE;
    }

    CheckDefDlgRecursion(&self->m_fRecursing);

    return SetDlgMsgResult(hdlg, uMsg,
              self->WLDlgProc(hdlg, uMsg, wParam, lParam));
  }

private:
  BOOL m_fRecursing;
};

class SampleWLDlg : public WLDialogBox
{
  LRESULT WLDlgProc(HWND hdlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
  {
    switch (uMsg) {
    HANDLE_MSG(hdlg, WM_COMMAND, OnCommand);
    HANDLE_MSG(hdlg, WM_SETCURSOR, OnSetCursor);
    }
    return __super::WLDlgProc(hdlg, uMsg, wParam, lParam);
  };

  void OnCommand(HWND hdlg, int id, HWND hwndCtl, UINT codeNotify)
  {
    switch (id) {
    case IDCANCEL:
      MessageBox(hdlg, TEXT("Bye"), TEXT("Title"), MB_OK);
      EndDialog(hdlg, 1);
      break;
    }
  }

  BOOL OnSetCursor(HWND hdlg, HWND hwndCursor,
                   UINT codeHitTest, UINT msg)
  {
    if (codeHitTest == HTCAPTION) {
      SetCursor(LoadCursor(NULL, IDC_SIZEALL));
      return TRUE;
    }
    return FORWARD_WM_SETCURSOR(hdlg, hwndCursor,
                  codeHitTest, msg, __super::WLDlgProc);
  }
};

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hinstPrev,
                   LPSTR lpCmdLine, int nShowCmd)
{
    SampleWLDlg dlg;
    dlg.DoModal(hinst, MAKEINTRESOURCE(1), NULL);
    return 0;
}

#ifdef RC_INVOKED
1 DIALOGEX DISCARDABLE  0, 0, 200, 200
STYLE DS_SHELLFONT | WS_POPUP | WS_VISIBLE |
      WS_CAPTION | WS_SYSMENU
CAPTION "sample"
FONT 8, "MS Shell Dlg"
BEGIN
  DEFPUSHBUTTON "&Bye",IDCANCEL,7,4,50,14,WS_TABSTOP
END

#endif
