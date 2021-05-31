#include "CWndApp.h"
#include "../../Function/GFunc.h"
#include "../Manager/CTimeManager.h"
#include "../Manager/CInputManager.h"

//#define GET_MSG_ENABLE
#define PEEK_MSG_ENABLE

// 전역 변수
CWndApp *CWndApp::m_pInst = nullptr;

/*
윈도우 프로시저란?
:
- 각 윈도우가 발생 시킨 윈도우 메세지를 처리하기 위한 전용 함수를 의미한다. WinAPI 를 통해
프로그램을 제작 한다는 것은 윈도우가 발생 시킨 메세지를 처리함으로써 프로그램의 제작 목적을
달성하는 것이기 때문에 WinAPI 를 사용 할 경우 반드시 해당 함수를 선언 및 구현해야한다.

또한, 해당 함수는 직접 호출 할 필요 없으며 DispatchMessage 함수를 사용하면 자동으로 호출된다.
(즉, DispatchMessage 함수에 의해서 전파 된 메세지를 처리 할 수 있도록 내부적으로 윈도우를
생성하면서 등록 한 윈도우 프로시저 함수를 호출해준다.)

그리고 윈도우 프로시저는 반환 값을 통해서 현재 발생 한 메세지가 정상적으로 처리되었는지
유/무를 알려줘야한다. (즉, 윈도우 프로시저의 반환 값이 0 이라면 이는 발생한 메세지가 정상적으로
처리되었다는 것을 의미한다.)
*/
//! 윈도우 프로시저
static LRESULT CALLBACK WndProc(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams) {
	static CWndApp *pWndApp = nullptr;

	/*
	CreateWindow 함수에 의해서 특정 윈도우를 생성했을 경우 WinAPI 는 내부적으로 WM_CREATE
	윈도우 메세지를 발생시킨다. (즉, 윈도우 프로시저에서 해당 이벤트가 발생했다는 것은 특정
	윈도우가 생성 되었다는 것을 의미하기 때문에 각 윈도우에 맞는 초기화 구문을 작성하는 것이
	가능하다.)

	이때, LPARAM 매개 변수에는 CreateWindow 함수 호출 시 입력으로 주어진 값들을 저장하고
	있는 CREATESTRUCT 구조체의 주소가 전달되기 때문에 해당 매개 변수를 사용하면 생성 된
	윈도우에 맞게 초기화 구문을 작성하는 것이 가능하다.
	*/
	switch(a_nMsg) {
		case WM_CREATE: {
			auto pstCreateStruct = (CREATESTRUCT *)a_lParams;
			pWndApp = static_cast<CWndApp *>(pstCreateStruct->lpCreateParams);
		} break;
	}

	// 윈도우 어플리케이션이 존재 할 경우
	if(pWndApp != nullptr) {
		return pWndApp->HandleWndMsg(a_hWnd, a_nMsg, a_wParams, a_lParams);
	}

	/*
	DefWindowProc 함수는 발생한 윈도우 메세지에 대한 기본적인 처리를 하는 역할을 수행한다.
	(즉, 발생한 모든 메세지를 다 처리 할 필요 없이 프로그램에 목적에 맞는 메세지만 처리하고
	나머지 메세지는 DefWindowProc 함수가 처리함으로써 불필요한 메세지를 처리하는 구문을
	작성 할 필요없다.)
	*/
	return DefWindowProc(a_hWnd, a_nMsg, a_wParams, a_lParams);
}

CWndApp::CWndApp(HINSTANCE a_hInst, int a_nShowOpts, const SIZE & a_rstWndSize) 
:
m_hInst(a_hInst),
m_nShowOpts(a_nShowOpts),
m_stWndSize(a_rstWndSize) 
{
	assert(m_pInst == nullptr);

	m_pInst = this;
	ZeroMemory(&m_stWndCls, sizeof(m_stWndCls));

	/*
	AllocConsole 함수는 콘솔 창을 생성하는 역할을 수행한다. (즉, 기본적으로 어플리케이션
	프로그램은 콘솔 창을 자동으로 생성해주지 않기 때문에 필요 시 해당 함수를 사용해서 별도로
	콘솔 창을 생성해줘야한다.)

	freopen 함수는 파일 스트림을 다시 연결하는 역할을 수행한다. (즉, 어플리케이션 프로그램은
	표준 입/출력 스트림을 자동으로 연결해주지 않기 때문에 필요 시 해당 함수를 사용해서 별도로
	표준 입/출력 스트림을 연결해줘야한다.)
	*/
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
	m_hWnd = this->CreateWnd(&m_stWndCls);

	GET_TIME_MANAGER()->Init();
	GET_INPUT_MANAGER()->Init();
}

void CWndApp::Update(float a_fDeltaTime) {
	GET_TIME_MANAGER()->Update(a_fDeltaTime);
	GET_INPUT_MANAGER()->Update(a_fDeltaTime);
}

void CWndApp::Render(HDC a_hDC) {
	this->PreRender(a_hDC);
	this->DoRender(a_hDC);
	this->PostRender(a_hDC);

	TCHAR szStr[MAX_PATH] = _T("");
	_stprintf(szStr, _T("Delta Time: %f sec\nRunning Time: %f sec"), GET_DELTA_TIME(), GET_RUNNING_TIME());

	POINT stPos = {
		10, 10
	};

	GFunc::DrawStr(a_hDC, szStr, stPos, DT_TOP | DT_LEFT);
}

int CWndApp::Run(void) {
	this->Init();

	/*
	ShowWindow 함수는 특정 윈도우를 화면 상에 출력하는 역할을 수행한다. (즉, 윈도우를
	생성했다 하더라도 해당 함수를 통해서 윈도우를 출력하지 않았을 경우 해당 윈도우는 백그라운드
	상에서만 존재한다는 것을 알 수 있다.)

	UpdateWindow 함수는 특정 윈도우가 발생시킨 메세지를 메세지 큐에서 제거하는 역할을 수행한다.
	(즉, 해당 함수를 사용하면 특정 윈도우가 발생시킨 모든 메세지를 처리하도록 윈도우 프로시저가
	호출된다는 것을 알 수 있다.)
	*/
	ShowWindow(m_hWnd, m_nShowOpts);
	UpdateWindow(m_hWnd);

	return this->RunMsgLoop();
}

LRESULT CWndApp::HandleWndMsg(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams) {
	switch(a_nMsg) {
		case WM_SIZE: return this->HandleSizeMsg(a_wParams, a_lParams);
		case WM_PAINT: return this->HandlePaintMsg(a_wParams, a_lParams);
		case WM_DESTROY: return this->HandleDestroyMsg(a_wParams, a_lParams);
	}

	return DefWindowProc(a_hWnd, a_nMsg, a_wParams, a_lParams);
}

int CWndApp::RunMsgLoop(void) {
	MSG stMsg;
	ZeroMemory(&stMsg, sizeof(stMsg));

#if defined GET_MSG_ENABLE
	/*
	GetMessage 함수는 메세지 큐에 존재하는 윈도우 메세지를 가져오는 역할을 수행한다. 단, 윈도우
	메세지가 존재하지 않을 경우 해당 함수는 새로운 윈도우 메세지가 들어올때까지 대기한다.
	(즉, GetMessage 함수는 블럭킹 함수이기 때문에 실시간 프로그램을 제작 할 때는 사용하는
	것을 자제해야한다.)

	TranslateMessage 함수는 WM_CHAR 메세지를 발생시키는 역할을 수행한다. (즉, WM_CHAR 메세지를
	처리하지 않을 경우 해당 함수는 사용하지 않아도 된다.)

	DispatchMessage 함수는 발생한 윈도우 메시지를 전파시키는 역할을 수행한다. (즉, 해당 함수를
	통해 윈도우 메세지를 전파시키면 내부적으로 발생한 윈도우 메세지를 처리 할 수 있도록 윈도우 
	프로시저가 호출된다.)

	일반적으로 윈도우즈 운영체제 상에서 구동되는 프로그램을 제작한다는 것은 윈도우 메세지를 
	처리해서 프로그램을 제작한다는 것을 의미하기 때문에 윈도우 메세지를 처리하기 위한 메세지 
	루프를 반드시 구현해줘야한다.
	*/
	while(GetMessage(&stMsg, NULL, 0, 0)) {
		TranslateMessage(&stMsg);
		DispatchMessage(&stMsg);
	}
#elif defined PEEK_MSG_ENABLE
	/*
	PeekMessage 함수 또한 GetMessage 함수와 같이 메세지 큐에 존재하는 윈도우 메세지를 가져오는
	역할을 수행한다. 단, 메세지 큐가 비어있을 경우 새로운 윈도우 메세지를 대기하는 GetMessage 함수와
	달리 PeekMessage 는 메세지 큐가 비어있더라도 새로운 메세지를 대기하지 않고 함수 호출이 완료된다.
	(즉, PeekMessage 는 넌블럭킹 함수이기 때문에 실시간 프로그램을 제작 할 때 사용하는 것이
	가능하다.)
	*/
	while(stMsg.message != WM_QUIT) {
		// 윈도우 메세지가 존재 할 경우
		if(PeekMessage(&stMsg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&stMsg);
			DispatchMessage(&stMsg);
		}

		HDC hDC = GetDC(m_hWnd);
		HDC hMemDC = CreateCompatibleDC(hDC);
		HBITMAP hPrevMemBitmap = (HBITMAP)SelectObject(hMemDC, m_hBitmap);

		RECT stWndRect = {
			0, 0, m_stWndSize.cx, m_stWndSize.cy
		};

		FillRect(hMemDC, &stWndRect, m_stWndCls.hbrBackground);

		__try {
			this->Update(GET_DELTA_TIME());
			this->LateUpdate(GET_DELTA_TIME());

			this->Render(hMemDC);
			StretchBlt(hDC, 0, 0, m_stWndSize.cx, m_stWndSize.cy, hMemDC, 0, 0, m_stWndSize.cx, m_stWndSize.cy, SRCCOPY);
		} __finally {
			SelectObject(hMemDC, hPrevMemBitmap);

			SAFE_DEL_DC(hMemDC);
			SAFE_RELEASE_DC(m_hWnd, hDC);
		}
	}
#endif			// #if defined MSG_LOOP_TYPE_GET

	return stMsg.wParam;
}

LRESULT CWndApp::HandleSizeMsg(WPARAM a_wParams, LPARAM a_lParams) {
	m_stWndSize.cx = LOWORD(a_lParams);
	m_stWndSize.cy = HIWORD(a_lParams);

	/*
	GetDC 함수는 특정 윈도우 디바이스 컨텍스트를 가져오는 역할을 수행한다. 디바이스 컨텍스트는
	특정 윈도우에 속한 자원이기 때문에 해당 자원 사용을 완료했다면 반드시 ReleaseDC 함수를
	통해서 디바이스 컨텍스트를 반납해야한다.

	GetStockObject 함수가 아닌 별도의 방법으로 생성한 GDI 객체는 반드시 DeleteObject 함수를
	통해서 제거해줘야한다. (즉, 아래의 경우 비트맵은 CreateCompatibleBitmap 함수에 의해서 생성
	되었기 때문에 해당 비트맵이 더이상 필요 없을 경우 반드시 제거를 해줘야한다.)
	*/
	auto hDC = GetDC(m_hWnd);
	SAFE_DEL_GDI_OBJ(m_hBitmap);

	__try {
		/*
		CreateCompatibleBitmap 함수는 주어진 비트맵과 호환되는 사본 비트맵을 생성하는 역할을
		수행한다. (즉, 모든 디바이스 컨텍스트는 내부적으로 비트맵 GDI 객체를 지니고 있으며 해당
		비트맵에 특정 이미지를 그림으로써 윈도우 상에 해당 결과가 출력되는 것을 알 수 있다.)
		*/
		m_hBitmap = CreateCompatibleBitmap(hDC, m_stWndSize.cx, m_stWndSize.cy);
	} __finally {
		SAFE_RELEASE_DC(m_hWnd, hDC);
	}

	return 0;
}

LRESULT CWndApp::HandlePaintMsg(WPARAM a_wParams, LPARAM a_lParams) {
	return 0;
}

LRESULT CWndApp::HandleDestroyMsg(WPARAM a_wParams, LPARAM a_lParams) {
	/*
	PostQuitMessage 함수는 WM_QUIT 메세지를 발생시키는 역할을 수행한다. (즉, 해당 메세지를
	통해서 WM_QUIT 메세지가 전파되면 GetMessage 함수의 결과 값으로 FALSE 가 반환 되어 메세지
	루프를 종료하는 것이 가능하다.)
	*/
	PostQuitMessage(0);

	return 0;
}

HWND CWndApp::CreateWnd(WNDCLASS * a_pstOutWndCls) {
	/*
	WNDCLASS 구조체는 사용자 정의 윈도우의 속성을 지정하는 역할을 수행한다. (즉, 윈도우즈 
	운영체제에 의해 미리 만들어져서 제공되는 윈도우가 아니라 별도의 윈도우를 생성하기 위해서는 
	반드시 해당 윈도우의 속성을 지정 후 RegisterClass 함수를 사용해서 해당 속성을 윈도우즈 
	운영체제에 등록해줘야한다.)

	GetStockObject 함수는 윈도우즈 운영체제가 제공하는 GDI 객체를 가져오는 역할을 수행한다.
	*/
	WNDCLASS stWndCls = {
		CS_VREDRAW | CS_HREDRAW,							// 윈도우 클래스 스타일
		WndProc,											// 윈도우 프로시저
		0,													// 확장을 위한 예약 변수 1
		0,													// 확장을 위한 예약 변수 2
		m_hInst,											// 인스턴스 핸들
		LoadIcon(NULL, IDI_APPLICATION),					// 아이콘
		LoadCursor(NULL, IDC_ARROW),						// 커서
		(HBRUSH)GetStockObject(COLOR_WINDOW + 1),			// 배경 색
		NULL,												// 메뉴 이름 (식별자)
		_T("Example")										// 윈도우 클래스 이름 (식별자)
	};

	RegisterClass(&stWndCls);
	CopyMemory(a_pstOutWndCls, &stWndCls, sizeof(stWndCls));

	RECT stWndRect = {
		0, 0, m_stWndSize.cx, m_stWndSize.cy
	};

	/*
	AdjustWindowRect 함수는 주어진 윈도우 스타일을 기반으로 클라이언트 영역을 포함한 윈도우
	영역을 계산하는 역할을 수행한다. (즉, CreateWindow 함수에서 지정하는 윈도우의 크기는
	클라이언트 영역을 포함한 윈도우 전체의 크기이기 때문에 특정 클라이언트 영역을 지닌 윈도우를
	생성하기 위해서는 반드시 해당 함수를 사용해서 윈도우의 전체 크기를 계산해야한다.)
	*/
	AdjustWindowRect(&stWndRect, WS_OVERLAPPEDWINDOW, FALSE);

	/*
	CreateWindow 함수는 윈도우를 생성하는 역할을 수행한다. (즉, 해당 함수를 사용하면 윈도우즈
	운영체제가 미리 제공하는 윈도우 뿐만 아니라 사용자가 정의한 윈도우를 생성하는 것이 가능하다.)
	*/
	return CreateWindow(stWndCls.lpszClassName,			// 윈도우 클래스 이름 (식별자)
		stWndCls.lpszClassName,							// 윈도우 이름 (식별자)
		WS_OVERLAPPEDWINDOW,							// 윈도우 스타일
		CW_USEDEFAULT,									// 윈도우 X 위치
		CW_USEDEFAULT,									// 윈도우 Y 위치
		stWndRect.right - stWndRect.left,				// 윈도우 너비
		stWndRect.bottom - stWndRect.top,				// 윈도우 높이
		GetDesktopWindow(),								// 부모 윈도우 핸들
		NULL,											// 메뉴 핸들
		stWndCls.hInstance,								// 인스턴스 핸들
		this);											// 윈도우 생성 매개 변수
}
