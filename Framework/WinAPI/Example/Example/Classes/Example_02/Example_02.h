#pragma once

#include "../Global/Define/KGDefine.h"
#include "../Global/Utility/Base/CWndApp.h"

//! Example 2
class Example_02 : public CWndApp {
public:			// public 함수

	//! 윈도우 메세지를 처리한다
	virtual LRESULT HandleWndMsg(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams) override;

public:			// 생성자

	//! 생성자
	Example_02(HINSTANCE a_hInst, int a_nShowOpts, const SIZE &a_rstWndSize);

private:			// private 함수

	//! 마우스 이동 메세지를 처리한다
	LRESULT HandleMouseMoveMsg(WPARAM a_wParams, LPARAM a_lParams);

	//! 마우스 버튼 메세지를 처리한다
	LRESULT HandleMouseBtnMsg(WPARAM a_wParams, LPARAM a_lParams, bool a_bIsBtnDown);

	//! 그리기 메세지를 처리한다
	virtual LRESULT HandlePaintMsg(WPARAM a_wParams, LPARAM a_lParams) override;

private:			// private 변수

	POINT m_stCurPos;
	POINT m_stPrevPos;

	std::vector<std::pair<POINT, POINT>> m_oPosInfoList;
};
