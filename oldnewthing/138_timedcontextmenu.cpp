void CALLBACK
MenuTooLateProc(HWND hwnd, UINT uiMsg, UINT idEvent, DWORD dwTime)
{
  SendMessage(hwnd, WM_CANCELMODE, 0, 0);
}

BOOL
TimedTrackPopupMenuEx(HMENU hMenu, UINT uFlags, int x, int y,
    HWND hwnd, LPTPMPARAMS pTpm, DWORD dwTimeout)
{
    UINT idTimer = SetTimer(NULL, IDT_TOOLATE,
                            dwTimeout, MenuTooLateProc);
    BOOL fResult = TrackPopupMenuEx(hMenu, uFlags, x, y, hwnd, pTpm);
    if (idTimer) KillTimer(NULL, idTimer);
    return fResult;
}

