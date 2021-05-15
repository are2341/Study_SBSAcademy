#include "Example_02.h"
#include "../Global/Function/GFunc.h"

Example_02::Example_02(HINSTANCE a_hInst, int a_nShowOpts, const SIZE & a_rstWndSize)
: CWndApp(a_hInst, a_nShowOpts, a_rstWndSize) 
{
	ZeroMemory(&m_stCurPos, sizeof(m_stCurPos));
	ZeroMemory(&m_stPrevPos, sizeof(m_stPrevPos));
}

LRESULT Example_02::HandleWndMsg(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams) {
	switch(a_nMsg) {
		case WM_PAINT: return this->HandlePaintMsg(a_wParams, a_lParams);
		case WM_MOUSEMOVE: return this->HandleMouseMoveMsg(a_wParams, a_lParams); 
		case WM_LBUTTONUP: case WM_LBUTTONDOWN: return this->HandleMouseBtnMsg(a_wParams, a_lParams, a_nMsg == WM_LBUTTONDOWN);
	}

	return CWndApp::HandleWndMsg(a_hWnd, a_nMsg, a_wParams, a_lParams);
}

LRESULT Example_02::HandleMouseMoveMsg(WPARAM a_wParams, LPARAM a_lParams) {
	// 마우스 버튼을 눌렀을 경우
	if(a_wParams != 0) {
		m_stCurPos.x = LOWORD(a_lParams);
		m_stCurPos.y = HIWORD(a_lParams);

		/*
		InvalidateRect 함수는 윈도우의 일부 또는 전체 영역을 무효화하는 것이 가능하다.
		(즉, 해당 함수를 사용하면 윈도우는 무효화 된 영역을 다시 그리기 위해서 WM_PAINT 메세지를
		발생시킨다.)

		단, 해당 함수를 빈번하게 사용 할 경우 윈도우의 영역이 무효화 된 순간이 화면 상에
		출력되어 깜빡이는 현상을 발생시키는 원인이 된다.
		*/
		InvalidateRect(GET_WND_HANDLE(), NULL, TRUE);
	}

	return 0;
}

LRESULT Example_02::HandleMouseBtnMsg(WPARAM a_wParams, LPARAM a_lParams, bool a_bIsBtnDown) {
	// 마우스 버튼을 눌렀을 경우
	if(a_bIsBtnDown) {
		m_stCurPos.x = m_stPrevPos.x = LOWORD(a_lParams);
		m_stCurPos.y = m_stPrevPos.y = HIWORD(a_lParams);
	} else {
		m_oPosInfoList.push_back(std::make_pair(m_stPrevPos, m_stCurPos));
	}

	return 0;
}

LRESULT Example_02::HandlePaintMsg(WPARAM a_wParams, LPARAM a_lParams) {
	/*
	WM_PAINT 메세지가 발생했을 경우에는 GetDC 함수가 아닌 BeginPaint 함수를 통해서 특정
	윈도우를 그리기 위한 디바이스 컨텍스트를 가져와야한다. 또한, 해당 함수를 통해서 가져온
	디바이스 컨텍스트는 반드시 EndPaint 함수를 통해서 해제해줘야한다.
	*/
	PAINTSTRUCT stPaintStruct;
	BeginPaint(GET_WND_HANDLE(), &stPaintStruct);

	__try {
		for(auto stPosInfo : m_oPosInfoList) {
			GFunc::DrawLine(stPaintStruct.hdc, stPosInfo.first, stPosInfo.second);
		}

		GFunc::DrawLine(stPaintStruct.hdc, m_stPrevPos, m_stCurPos);
	} __finally {
		EndPaint(GET_WND_HANDLE(), &stPaintStruct);
	}

	return 0;
}
