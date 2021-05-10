#include "CWndApp.h"
#include "../Manager/CTimeManager.h"
#include "../Manager/CInputManager.h"

// 전역 변수
static CWndApp *g_pInst = nullptr;

//! 윈도우 프로시저
static LRESULT CALLBACK WndProc(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParam, LPARAM a_lParam) {
	static CWndApp *pWndApp = nullptr;

	switch(a_nMsg) {
		case WM_CREATE: {
			auto pstCreateStruct = (CREATESTRUCT *)a_lParam;
			pWndApp = static_cast<CWndApp *>(pstCreateStruct->lpCreateParams);
		} break;
	}

	// 윈도우 어플리케이션이 존재 할 경우
	if(pWndApp != nullptr) {
		return pWndApp->HandleWndMsg(a_hWnd, a_nMsg, a_wParam, a_lParam);
	}

	return DefWindowProc(a_hWnd, a_nMsg, a_wParam, a_lParam);
}

CWndApp::CWndApp(HINSTANCE a_hInst, int a_nShowOpts, const SIZE & a_rstWndSize) 
:
m_hInst(a_hInst),
m_nShowOpts(a_nShowOpts),
m_stWndSize(a_rstWndSize) 
{
	g_pInst = this;
	ZeroMemory(&m_stWndCls, sizeof(m_stWndCls));

	// 콘솔 창을 생성한다
	if(AllocConsole()) {
		m_pstRStream = freopen("CONIN$", "rb", stdin);
		m_pstWStream = freopen("CONOUT$", "wb", stdout);
	}
}

CWndApp::~CWndApp(void) {
	SAFE_FCLOSE(m_pstRStream);
	SAFE_FCLOSE(m_pstWStream);

	FreeConsole();
	UnregisterClass(m_stWndCls.lpszClassName, m_hInst);
}

void CWndApp::Init(void) {
	m_hWnd = this->CreateWnd(m_stWndCls);

	GET_TIME_MANAGER()->Init();
	GET_INPUT_MANAGER()->Init();
}

void CWndApp::Update(void) {
	GET_TIME_MANAGER()->Update();
	GET_INPUT_MANAGER()->Update();
}

void CWndApp::Render(void) {
	this->PreRender();
	this->DoRender();
	this->PostRender();
}

SIZE CWndApp::GetWndSize(void) const {
	return m_stWndSize;
}

HWND CWndApp::GetWndHandle(void) const {
	return m_hWnd;
}

HINSTANCE CWndApp::GetInstHandle(void) const {
	return m_hInst;
}

CWndApp * CWndApp::GetInst(void) {
	return g_pInst;
}

int CWndApp::Run(void) {
	this->Init();

	ShowWindow(m_hWnd, m_nShowOpts);
	UpdateWindow(m_hWnd);

	return this->RunMsgLoop();
}

LRESULT CWndApp::HandleWndMsg(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParam, LPARAM a_lParam) {
	switch(a_nMsg) {
		case WM_SIZE: this->HandleSizeMsg(a_wParam, a_lParam); break;
		case WM_DESTROY: this->HandleDestroyMsg(a_wParam, a_lParam); break;
	}

	return DefWindowProc(a_hWnd, a_nMsg, a_wParam, a_lParam);
}

int CWndApp::RunMsgLoop(void) {
	MSG stMsg;
	ZeroMemory(&stMsg, sizeof(stMsg));

	while(stMsg.message != WM_QUIT) {
		// 윈도우 메세지가 존재 할 경우
		if(PeekMessage(&stMsg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&stMsg);
			DispatchMessage(&stMsg);
		}

		this->Update();
		this->LateUpdate();

		this->Render();
	}

	return stMsg.wParam;
}

void CWndApp::HandleDestroyMsg(WPARAM a_wParam, LPARAM a_lParam) {
	PostQuitMessage(0);
}

void CWndApp::HandleSizeMsg(WPARAM a_wParam, LPARAM a_lParam) {
	m_stWndSize.cx = LOWORD(a_lParam);
	m_stWndSize.cy = HIWORD(a_lParam);

	auto hDC = GetDC(m_hWnd);
	SAFE_DEL_GDI_OBJ(m_hBitmap);

	__try {
		m_hBitmap = CreateCompatibleBitmap(hDC, m_stWndSize.cx, m_stWndSize.cy);
	} __finally {
		SAFE_RELEASE_DC(m_hWnd, hDC);
	}
}

HWND CWndApp::CreateWnd(WNDCLASS & a_rstOutWndCls) {
	WNDCLASS stWndCls = {
		CS_VREDRAW | CS_HREDRAW,
		WndProc,
		0,
		0,
		m_hInst,
		LoadIcon(NULL, IDI_APPLICATION),
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)GetStockObject(COLOR_WINDOW + 1),
		NULL,
		_T("Example")
	};

	RegisterClass(&stWndCls);
	CopyMemory(&a_rstOutWndCls, &stWndCls, sizeof(stWndCls));

	RECT stWndRect = {
		0, 0, m_stWndSize.cx, m_stWndSize.cy
	};

	AdjustWindowRect(&stWndRect, WS_OVERLAPPEDWINDOW, FALSE);
	return CreateWindow(stWndCls.lpszClassName, stWndCls.lpszClassName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, stWndRect.right - stWndRect.left, stWndRect.bottom - stWndRect.top, GetDesktopWindow(), NULL, stWndCls.hInstance, this);
}
