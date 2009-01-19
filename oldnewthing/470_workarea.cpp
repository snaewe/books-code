void GetWorkAreaFromWindow(HWND hwnd, OUT RECT *prc)
{
 MONITORINFO mi = { sizeof(mi) };
 HMONITOR hmon = MonitorFromWindow(hwnd,
                                   MONITOR_DEFAULTTONEAREST);
 if (hmon && GetMonitorInfo(hmon, &mi)) {
  *prc = mi.rcWork;
 } else {
  // Cant get monitor from window  use the primary monitor
  SystemParametersInfo(SPI_GETWORKAREA, 0, prc, 0);
 }
}

