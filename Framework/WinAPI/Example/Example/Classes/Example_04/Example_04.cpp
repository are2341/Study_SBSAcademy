#include "Example_04.h"
#include "../Global/Function/GFunc.h"
#include "../Global/Utility/Manager/CInputManager.h"

Example_04::Example_04(HINSTANCE a_hInst, int a_nShowOpts, const SIZE & a_rstWndSize)
: CWndApp(a_hInst, a_nShowOpts, a_rstWndSize) 
{
	// Do Nothing
}

Example_04::~Example_04(void) {
	for(auto &rstValType : m_oPenList) {
		SAFE_DEL_GDI_OBJ(rstValType.second);
	}

	for(auto &rstValType : m_oBrushList) {
		SAFE_DEL_GDI_OBJ(rstValType.second);
	}
}

void Example_04::Init(void) {
	CWndApp::Init();

	HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	HPEN hGreenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	HPEN hBluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));

	HBRUSH hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));

	m_oPenList.insert(decltype(m_oPenList)::value_type(EColor::RED, hRedPen));
	m_oPenList.insert(decltype(m_oPenList)::value_type(EColor::GREEN, hGreenPen));
	m_oPenList.insert(decltype(m_oPenList)::value_type(EColor::BLUE, hBluePen));

	m_oBrushList.insert(decltype(m_oBrushList)::value_type(EColor::RED, hRedBrush));
	m_oBrushList.insert(decltype(m_oBrushList)::value_type(EColor::GREEN, hGreenBrush));
	m_oBrushList.insert(decltype(m_oBrushList)::value_type(EColor::BLUE, hBlueBrush));
}

void Example_04::Update(void) {
	CWndApp::Update();

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

	// 선 키를 눌렀을 경우
	if(IS_KEY_PRESS(DIK_1)) {
		m_eShape = EShape::LINE;
	}
	// 사각형 키를 눌렀을 경우
	else if(IS_KEY_PRESS(DIK_2)) {
		m_eShape = EShape::RECTANGLE;
	}
	// 타원 키를 눌렀을 경우
	else if(IS_KEY_PRESS(DIK_3)) {
		m_eShape = EShape::ELLIPSE;
	}

	// 마우스 버튼을 눌렀을 경우
	if(IS_MOUSE_BTN_DOWN(EMouseBtn::LEFT)) {
		// 마우스 버튼 누름을 시작했을 경우
		if(IS_MOUSE_BTN_PRESS(EMouseBtn::LEFT)) {
			STShapeInfo stShapeInfo = {
				m_eColor,
				m_eShape,

				GET_MOUSE_POS(),
				GET_MOUSE_POS()
			};

			m_oShapeInfoList.push_back(stShapeInfo);
		}

		m_oShapeInfoList.back().m_eColor = m_eColor;
		m_oShapeInfoList.back().m_eShape = m_eShape;
		m_oShapeInfoList.back().m_stEndPos = GET_MOUSE_POS();
	}
}

void Example_04::DoRender(void) {
	CWndApp::DoRender();

	for(auto &rstShapeInfo : m_oShapeInfoList) {
		HPEN hPen = m_oPenList[rstShapeInfo.m_eColor];
		HPEN hPrevPen = (HPEN)SelectObject(GET_MEM_DC(), hPen);

		HBRUSH hBrush = m_oBrushList[rstShapeInfo.m_eColor];
		HBRUSH hPrevBrush = (HBRUSH)SelectObject(GET_MEM_DC(), hBrush);

		__try {
			switch(rstShapeInfo.m_eShape) {
				case EShape::LINE: GFunc::DrawLine(GET_MEM_DC(), rstShapeInfo.m_stStartPos, rstShapeInfo.m_stEndPos); break;
				case EShape::RECTANGLE: GFunc::DrawRectangle(GET_MEM_DC(), rstShapeInfo.m_stStartPos, rstShapeInfo.m_stEndPos); break;
				case EShape::ELLIPSE: GFunc::DrawEllipse(GET_MEM_DC(), rstShapeInfo.m_stStartPos, rstShapeInfo.m_stEndPos); break;
			}
			
		} __finally {
			SelectObject(GET_MEM_DC(), hPrevPen);
			SelectObject(GET_MEM_DC(), hPrevBrush);
		}
	}
}
