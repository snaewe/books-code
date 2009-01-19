void GetMonitorRectFromWindow(HWND hwnd, OUT RECT *prc)
{
 MONITORINFO mi = { sizeof(mi) };
 HMONITOR hmon = MonitorFromWindow(hwnd,
                                   MONITOR_DEFAULTTONEAREST);
 if (hmon && GetMonitorInfo(hmon, &mi)) {
  *prc = mi.rcMonitor;
 } else {
  // Cant get monitor from window  use the primary monitor
  prc->left = prc->top = 0;
  prc->right = GetSystemMetrics(SM_CXSCREEN);
  prc->bottom = GetSystemMetrics(SM_CYSCREEN);
 }
}

#if 0

// code fragment for computing the center of a monitor
RECT rcMonitor;
GetMonitorRectFromWindow(hwnd, &rcMonitor);
int x = rcMonitor.left + (rcMonitor.right  rcMonitor.left) / 2;
int y = rcMonitor.top + (rcMonitor.bottom  rcMonitor.top) / 2;

#endif
