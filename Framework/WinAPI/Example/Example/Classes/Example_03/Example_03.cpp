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

	HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	HPEN hBluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	HPEN hBlackPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

	m_oPenList.insert(decltype(m_oPenList)::value_type(EColor::RED, hRedPen));
	m_oPenList.insert(decltype(m_oPenList)::value_type(EColor::GREEN, hGreenPen));
	m_oPenList.insert(decltype(m_oPenList)::value_type(EColor::BLUE, hBluePen));
	m_oPenList.insert(decltype(m_oPenList)::value_type(EColor::BLACK, hBlackPen));
}

void Example_03::Update(float a_fDeltaTime) {
	CWndApp::Update(a_fDeltaTime);

	// 빨간색 펜 키를 눌렀을 경우
	if(IS_KEY_PRESS(DIK_1)) {
		m_eColor = EColor::RED;
	}
	// 녹색 펙 키를 눌렀을 경우
	else if(IS_KEY_PRESS(DIK_2)) {
		m_eColor = EColor::GREEN;
	}
	// 파란색 펜 키를 눌렀을 경우
	else if(IS_KEY_PRESS(DIK_3)) {
		m_eColor = EColor::BLUE;
	}
	// 검은색 펜 키를 눌렀을 경우
	else if(IS_KEY_PRESS(DIK_4)) {
		m_eColor = EColor::BLACK;
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

	for(auto &rstValType : m_oLineInfoList) {
		HPEN hPen = m_oPenList[rstValType.m_eColor];
		HPEN hPrevPen = (HPEN)SelectObject(a_hDC, hPen);

		__try {
			GFunc::DrawLine(a_hDC, rstValType.m_stStartPos, rstValType.m_stEndPos);
		} __finally {
			SelectObject(a_hDC, hPrevPen);
		}
	}
}