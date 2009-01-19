void DialogDisableWindow(HWND hdlg, HWND hwndControl)
{
  if (hwndControl == GetFocus()) {
    SendMessage(hdlg, WM_NEXTDLGCTL, 0, FALSE);
  }
  EnableWindow(hwndControl, FALSE);
}
