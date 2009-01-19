#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <ole2.h>
#include <commctrl.h>
#include <shlwapi.h>
#include <oleacc.h>

HINSTANCE g_hinst;                          /* This application's HINSTANCE */
HWND g_hwndChild;                           /* Optional child window */

class BaseAccessible : public IAccessible
{
public:
 // *** IUnknown ***
 STDMETHODIMP QueryInterface(REFIID riid, void **ppv)
 {
  IUnknown *punk = NULL;
  if (riid == IID_IUnknown)  {
   punk = static_cast<IUnknown*>(this);
  } else if (riid == IID_IDispatch)  {
   punk = static_cast<IDispatch*>(this);
  } else if (riid == IID_IAccessible)  {
   punk = static_cast<IAccessible*>(this);
  }
  *ppv = punk;
  if (punk) {
   punk->AddRef();
   return S_OK;
  } else {
   return E_NOINTERFACE;
  }
 }
 STDMETHODIMP_(ULONG) AddRef() { return InterlockedIncrement(&m_cRef); }
 STDMETHODIMP_(ULONG) Release()
 {
   ULONG cRef = InterlockedDecrement(&m_cRef);
   if (cRef == 0) delete this;
   return cRef;
 }

 // *** IDispatch ***
 STDMETHODIMP GetTypeInfoCount(UINT *pctinfo)
 {
  return m_paccStd->GetTypeInfoCount(pctinfo);
 }
 STDMETHODIMP GetTypeInfo(UINT iTInfo, LCID lcid,
                          ITypeInfo **ppTInfo)
 {
  return m_paccStd->GetTypeInfo(iTInfo, lcid, ppTInfo);
 }
 STDMETHODIMP GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames,
                        UINT cNames, LCID lcid, DISPID *rgDispId)
 {
  return m_paccStd->GetIDsOfNames(riid, rgszNames, cNames,
                                  lcid, rgDispId);
 }
 STDMETHODIMP Invoke(DISPID dispIdMember, REFIID riid, LCID lcid,
                     WORD wFlags, DISPPARAMS *pDispParams,
                     VARIANT *pVarResult, EXCEPINFO *pExcepInfo,
                     UINT *puArgErr)
 {
  return m_paccStd->Invoke(dispIdMember, riid, lcid,
          wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr);
 }

// *** IAccessible ***
 STDMETHODIMP get_accParent(IDispatch **ppdispParent)
 {
  return m_paccStd->get_accParent(ppdispParent);
 }
 STDMETHODIMP get_accChildCount(long *pcountChildren)
 {
  return m_paccStd->get_accChildCount(pcountChildren);
 }
 STDMETHODIMP get_accChild(VARIANT varChild,
                           IDispatch **ppdispChild)
 {
  return m_paccStd->get_accChild(varChild, ppdispChild);
 }
 STDMETHODIMP get_accName(VARIANT varChild, BSTR *pbsName)
 {
  return m_paccStd->get_accName(varChild, pbsName);
 }
 STDMETHODIMP get_accValue(VARIANT varChild, BSTR *pbsValue)
 {
  return m_paccStd->get_accValue(varChild, pbsValue);
 }
 STDMETHODIMP get_accDescription(VARIANT varChild, BSTR *pbsDesc)
 {
  return m_paccStd->get_accDescription(varChild, pbsDesc);
 }
 STDMETHODIMP get_accRole(VARIANT varChild, VARIANT *pvarRole)
 {
  return m_paccStd->get_accRole(varChild, pvarRole);
 }
 STDMETHODIMP get_accState(VARIANT varChild, VARIANT *pvarState)
 {
  return m_paccStd->get_accState(varChild, pvarState);
 }
 STDMETHODIMP get_accHelp(VARIANT varChild, BSTR *pbsHelp)
 {
  return m_paccStd->get_accHelp(varChild, pbsHelp);
 }
 STDMETHODIMP get_accHelpTopic(BSTR *pbsHelpFile,
                               VARIANT varChild, long *pidTopic)
 {
  return m_paccStd->get_accHelpTopic(pbsHelpFile, varChild,
                                                       pidTopic);
 }
 STDMETHODIMP get_accKeyboardShortcut(VARIANT varChild,
                                                    BSTR *pbsKey)
 {
  return m_paccStd->get_accKeyboardShortcut(varChild, pbsKey);
 }
 STDMETHODIMP get_accFocus(VARIANT *pvarChild)
 {
  return m_paccStd->get_accFocus(pvarChild);
 }
 STDMETHODIMP get_accSelection(VARIANT *pvarChildren)
 {
  return m_paccStd->get_accSelection(pvarChildren);
 }
 STDMETHODIMP get_accDefaultAction(VARIANT varChild,
                                              BSTR *pbsDefAction)
 {
  return m_paccStd->get_accDefaultAction(varChild, pbsDefAction);
 }
 STDMETHODIMP accSelect(long flagsSelect, VARIANT varChild)
 {
    return m_paccStd->accSelect(flagsSelect, varChild);
 }
 STDMETHODIMP accLocation(long *pxLeft, long *pyTop,
                          long *pcxWidth, long *pcyHeight,
                          VARIANT varChild)
 {
  return m_paccStd->accLocation(pxLeft, pyTop, pcxWidth,
                                pcyHeight, varChild);
 }
 STDMETHODIMP accNavigate(long navDir, VARIANT varStart,
                                            VARIANT *pvarEndUpAt)
 {
  return m_paccStd->accNavigate(navDir, varStart, pvarEndUpAt);
 }
 STDMETHODIMP accHitTest(long xLeft, long yTop,
                                              VARIANT *pvarChild)
 {
  return m_paccStd->accHitTest(xLeft, yTop, pvarChild);
 }
 STDMETHODIMP accDoDefaultAction(VARIANT varChild)
 {
  return m_paccStd->accDoDefaultAction(varChild);
 }
 STDMETHODIMP put_accName(VARIANT varChild, BSTR bsName)
 {
  return m_paccStd->put_accName(varChild, bsName);
 }
 STDMETHODIMP put_accValue(VARIANT varChild, BSTR bsValue)
 {
  return m_paccStd->put_accValue(varChild, bsValue);
 }

protected:
 BaseAccessible(IAccessible *paccStd)
  : m_cRef(1), m_paccStd(paccStd)
 {
  m_paccStd->AddRef();
 }
 ~BaseAccessible() { m_paccStd->Release(); }

private:
 LONG m_cRef;
protected:
 IAccessible *m_paccStd;
};

class ScratchAccessible : public BaseAccessible
{
public:
 static HRESULT Create(HWND hwnd, LONG idObject,
                       REFIID riid, void **ppv)
 {
  *ppv = NULL;
  IAccessible *paccStd;
  HRESULT hr = CreateStdAccessibleObject(hwnd, idObject,
                             IID_IAccessible, (void **)&paccStd);
  if (SUCCEEDED(hr)) {
   // note: uses non-throwing "new"
   ScratchAccessible *psa = new ScratchAccessible(paccStd);
   if (psa) {
    hr = psa->QueryInterface(riid, ppv);
    psa->Release();
   } else {
    hr = E_OUTOFMEMORY;
   }
   paccStd->Release();
  }
  return hr;
 }

 // Selective overriding of IAccessible
 STDMETHODIMP get_accName(VARIANT varChild, BSTR *pbsName)
 {
  if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF) {
   *pbsName = SysAllocString(L"Current time");
   return *pbsName ? S_OK : E_OUTOFMEMORY;
  }
  return m_paccStd->get_accName(varChild, pbsName);
 }
 STDMETHODIMP get_accValue(VARIANT varChild, BSTR *pbsValue)
 {
  if (varChild.vt == VT_I4 && varChild.lVal == CHILDID_SELF) {
   WCHAR szTime[100];
   if (GetTimeFormatW(LOCALE_USER_DEFAULT, 0, NULL, NULL,
                      szTime, 100)) {
    *pbsValue = SysAllocString(szTime);
    return *pbsValue ? S_OK : E_OUTOFMEMORY;
   }
  }
  return m_paccStd->get_accValue(varChild, pbsValue);
 }
private:
 ScratchAccessible(IAccessible *paccStd)
  : BaseAccessible(paccStd) { }
};


void
OnSize(HWND hwnd, UINT state, int cx, int cy)
{
    if (g_hwndChild) {
        MoveWindow(g_hwndChild, 0, 0, cx, cy, TRUE);
    }
}

BOOL
OnCreate(HWND hwnd, LPCREATESTRUCT lpcs)
{
    return TRUE;
}

void
OnDestroy(HWND hwnd)
{
    PostQuitMessage(0);
}

void
PaintContent(HWND hwnd, PAINTSTRUCT *pps)
{
    TCHAR szTime[100];
    if (GetTimeFormat(LOCALE_USER_DEFAULT, 0, NULL, NULL,
                      szTime, 100)) {
        TextOut(pps->hdc, 0, 0, szTime, lstrlen(szTime));
    }
}

void CALLBACK
InvalidateAndKillTimer(HWND hwnd, UINT uMsg,
                       UINT_PTR idTimer, DWORD dwTime)
{
    KillTimer(hwnd, idTimer);
    InvalidateRect(hwnd, NULL, TRUE);
    NotifyWinEvent(EVENT_OBJECT_VALUECHANGE, hwnd,
                   OBJID_CLIENT, CHILDID_SELF);
}

void
OnPaint(HWND hwnd)
{
    PAINTSTRUCT ps;
    BeginPaint(hwnd, &ps);
    PaintContent(hwnd, &ps);
    EndPaint(hwnd, &ps);
}

void
OnPrintClient(HWND hwnd, HDC hdc)
{
    PAINTSTRUCT ps;
    ps.hdc = hdc;
    GetClientRect(hwnd, &ps.rcPaint);
    ps.fErase = FALSE;
    PaintContent(hwnd, &ps);
}

LRESULT OnGetObject(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
 if (lParam == OBJID_CLIENT) {
  IAccessible *pacc;
  HRESULT hr = ScratchAccessible::Create(hwnd,
                   (LONG)lParam, IID_IAccessible, (void**)&pacc);
  if (FAILED(hr)) return hr;
  LRESULT lr = LresultFromObject(IID_IAccessible, wParam, pacc);
  pacc->Release();
  return lr;
 }
 return DefWindowProc(hwnd, WM_GETOBJECT, wParam, lParam);
}

LRESULT CALLBACK
WndProc(HWND hwnd, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uiMsg) {
    HANDLE_MSG(hwnd, WM_CREATE, OnCreate);
    HANDLE_MSG(hwnd, WM_SIZE, OnSize);
    HANDLE_MSG(hwnd, WM_DESTROY, OnDestroy);
    HANDLE_MSG(hwnd, WM_PAINT, OnPaint);
    case WM_PRINTCLIENT: OnPrintClient(hwnd, (HDC)wParam); return 0;
    case WM_GETOBJECT: return OnGetObject(hwnd, wParam, lParam);
    }

    return DefWindowProc(hwnd, uiMsg, wParam, lParam);
}

BOOL
InitApp(void)
{
    WNDCLASS wc;

    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = g_hinst;
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = TEXT("Scratch");

    if (!RegisterClass(&wc)) return FALSE;

    InitCommonControls();               /* In case we use a common control */

    return TRUE;
}

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hinstPrev,
                   LPSTR lpCmdLine, int nShowCmd)
{
    MSG msg;
    HWND hwnd;

    g_hinst = hinst;

    if (!InitApp()) return 0;

    if (SUCCEEDED(CoInitialize(NULL))) {/* In case we use COM */

        hwnd = CreateWindow(
            TEXT("Scratch"),                /* Class Name */
            TEXT("Scratch"),                /* Title */
            WS_OVERLAPPEDWINDOW,            /* Style */
            CW_USEDEFAULT, CW_USEDEFAULT,   /* Position */
            CW_USEDEFAULT, CW_USEDEFAULT,   /* Size */
            NULL,                           /* Parent */
            NULL,                           /* No menu */
            hinst,                          /* Instance */
            0);                             /* No special parameters */

        ShowWindow(hwnd, nShowCmd);

        while (GetMessage(&msg, NULL, 0, 0)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        CoUninitialize();
    }

    return 0;
}
