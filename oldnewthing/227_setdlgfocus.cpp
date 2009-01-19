void SetDialogFocus(HWND hdlg, HWND hwndControl)
{
 SendMessage(hdlg, WM_NEXTDLGCTL, (WPARAM)hwndControl, TRUE);
}
