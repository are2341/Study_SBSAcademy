#include "Example_03.h"
#include "../Global/Function/GFunc.h"
#include "../Global/Utility/Manager/CInputManager.h"

Example_03::Example_03(HINSTANCE a_hInst, int a_nShowOpts, const SIZE & a_rstWndSize)
: CWndApp(a_hInst, a_nShowOpts, a_rstWndSize) 
{
	// Do Nothing
}

Example_03::~Example_03(void) {
	for(auto &rstValType : m_oPenList) {
		SAFE_DEL_GDI_OBJ(rstValType.second);
	}
}

void Example_03::Init(void) {
	CWndApp::Init();

	/*
	CreatePen 함수는 펜 GDI 객체를 생성하는 역할을 수행한다. (즉, 해당 함수를 사용해서 생성 된
	GDI 객체를 사용하면 다양한 형태 및 색상을 지니는 선을 그리는 것이 가능하다.)
	*/
	HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	HPEN hBluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

	m_oPenList.insert(decltype(m_oPenList)::value_type(EColor::RED, hRedPen));
	m_oPenList.insert(decltype(m_oPenList)::value_type(EColor::GREEN, hGreenPen));
	m_oPenList.insert(decltype(m_oPenList)::value_type(EColor::BLUE, hBluePen));
}

void Example_03::Update(float a_fDeltaTime) {
	CWndApp::Update(a_fDeltaTime);

	// 빨간색 펜 키를 눌렀을 경우
	if(IS_KEY_PRESS(DIK_R)) {
		m_eColor = EColor::RED;
	}
	// 녹색 펙 키를 눌렀을 경우
	else if(IS_KEY_PRESS(DIK_G)) {
		m_eColor = EColor::GREEN;
	}
	// 파란색 펜 키를 눌렀을 경우
	else if(IS_KEY_PRESS(DIK_B)) {
		m_eColor = EColor::BLUE;
	}

	// 마우스 버튼을 눌렀을 경우
	if(IS_MOUSE_BTN_DOWN(EMouseBtn::LEFT)) {
		// 마우스 버튼 누름을 시작했을 경우
		if(IS_MOUSE_BTN_PRESS(EMouseBtn::LEFT)) {
			STLineInfo stLineInfo = {
				m_eColor,

				GET_MOUSE_POS(),
				GET_MOUSE_POS()
			};

			m_oLineInfoList.push_back(stLineInfo);
		}

		m_oLineInfoList.back().m_eColor = m_eColor;
		m_oLineInfoList.back().m_stEndPos = GET_MOUSE_POS();
	}
}

void Example_03::DoRender(HDC a_hDC) {
	CWndApp::DoRender(a_hDC);

	/*
	SelectObject 함수는 디바이스 컨텍스트에 GDI 객체를 설정하는 역할을 수행한다. (즉, 해당
	함수를 사용해서 여러 GDI 객체를 설정하면 다양한 효과를 지니는 그림을 그리는 것이 가능하다.)

	또한, 해당 함수는 디바이스 컨텍스트에 이전에 설정되어있던 GDI 객체를 반환한다. 이는,
	디바이스 컨텍스트가 특정 윈도우에 그림을 그리기 위해서 사용되는 공유 자원이기 때문에 해당
	디바이스 컨텍스트에 설정 된 여러 GDI 객체를 변경하는 과정에서 이전에 설정되어있는 설정을
	유지하기 위해서이다.
	*/
	for(auto &rstLineInfo : m_oLineInfoList) {
		HPEN hPen = m_oPenList[rstLineInfo.m_eColor];
		HPEN hPrevPen = (HPEN)SelectObject(a_hDC, hPen);

		__try {
			GFunc::DrawLine(a_hDC, rstLineInfo.m_stStartPos, rstLineInfo.m_stEndPos);
		} __finally {
			SelectObject(a_hDC, hPrevPen);
		}
	}
}