BOOL DrawSolidRect1(HDC hdc, LPCRECT prc, COLORREF clr)
{
 BOOL fDrawn = FALSE;
 HPEN hpenPrev =  SelectPen(hdc, GetStockPen(NULL_PEN));
 HBRUSH hbrSolid = CreateSolidBrush(clr);
 if (hbrSolid) {
  HBRUSH hbrPrev = SelectBrush(hdc, hbrSolid);
  fDrawn = Rectangle(hdc, prc->left, prc->top,
                     prc->right + 1, prc->bottom + 1);
  SelectBrush(hdc, hbrPrev);
  DeleteObject(hbrSolid);
 }
 SelectPen(hdc, hpenPrev);
 return fDrawn;
}

BOOL DrawSolidRect2(HDC hdc, LPCRECT prc, COLORREF clr)
{
 BOOL fDrawn = FALSE;
 HBRUSH hbrSolid = CreateSolidBrush(clr);
 if (hbrSolid) {
  fDrawn = FillRect(hdc, prc, hbrSolid);
  DeleteObject(hbrSolid);
 }
 return fDrawn;
}

BOOL DrawSolidRect3(HDC hdc, LPCRECT prc, COLORREF clr)
{
 BOOL fDrawn = FALSE;
 COLORREF clrPrev = SetDCBrushColor(hdc, clr);
 if (clrPrev != CLR_INVALID) {
  fDrawn = FillRect(hdc, prc, GetStockBrush(DC_BRUSH));
  SetDCBrushColor(hdc, clrPrev);
 }
 return fDrawn;
}

BOOL DrawSolidRect4(HDC hdc, LPCRECT prc, COLORREF clr)
{
 BOOL fDrawn = FALSE;
 COLORREF clrPrev = SetBkColor(hdc, clr);
 if (clrPrev != CLR_INVALID) {
  fDrawn = ExtTextOut(hdc, 0, 0, ETO_OPAQUE, prc, NULL, 0, NULL);
  SetBkColor(hdc, clrPrev);
 }
 return fDrawn;
}

