#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <ole2.h>
#include <commctrl.h>
#include <shlwapi.h>

static BOOL s_fTimedOut;
static HWND s_hwndMBOwnerEnable;

void CALLBACK
CheapMsgBoxTooLateProc(HWND hWnd, UINT uiMsg,
                      UINT_PTR idEvent, DWORD dwTime)
{
    s_fTimedOut = TRUE;
    if (s_hwndMBOwnerEnable)
     EnableWindow(s_hwndMBOwnerEnable, TRUE);
    PostQuitMessage(0); // value not important
}

// Warning! Not thread-safe! See discussion.
int CheapTimedMessageBox(HWND hwndOwner, LPCTSTR ptszText,
    LPCTSTR ptszCaption, UINT uType, DWORD dwTimeout)
{
    s_fTimedOut = FALSE;
    s_hwndMBOwnerEnable = NULL;
    if (hwndOwner && IsWindowEnabled(hwndOwner)) {
      s_hwndMBOwnerEnable = hwndOwner;
    }
    UINT idTimer = SetTimer(NULL, 0, dwTimeout,
                           CheapMsgBoxTooLateProc);
    int iResult = MessageBox(hwndOwner,
                             ptszText, ptszCaption, uType);
    if (idTimer) KillTimer(NULL, idTimer);
    if (s_fTimedOut) {              // We timed out
      MSG msg;
      // Eat the fake WM_QUIT message we generated
      PeekMessage(&msg, NULL, WM_QUIT, WM_QUIT, PM_REMOVE);
      iResult = -1;
    }
    return iResult;
}

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hinstPrev,
                   LPSTR lpCmdLine, int nShowCmd)
{
    CheapTimedMessageBox(NULL, TEXT("Message"), TEXT("Title"), MB_OK, 1000);
    return 0;
}
