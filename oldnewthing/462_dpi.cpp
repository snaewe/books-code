int g_xDPI, g_yDPI;

BOOL InitializeDPI()
{
 HDC hdc = GetDC(NULL); // get screen DC
 if (!hdc) return FALSE;
 g_xDPI = GetDeviceCaps(hdc, LOGPIXELSX);
 g_yDPI = GetDeviceCaps(hdc, LOGPIXELSY);
 ReleaseDC(NULL, hdc);
}

int AdjustXDPI(int cx)
{
 return MulDiv(cx, g_xDPI, 96);
}

int AdjustYDPI(int cy)
{
 return MulDiv(cy, g_yDPI, 96);
}
