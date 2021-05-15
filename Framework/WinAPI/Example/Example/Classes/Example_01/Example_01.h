#pragma once

#include "../Global/Define/KGDefine.h"
#include "../Global/Utility/Base/CWndApp.h"

/*
WinAPI 란?
:
- 윈도우즈 운영체제에서 제공하는 API (Application Programming Interface) 로써 해당 API 를 
사용하면 윈도우즈 운영체제에서 구동되는 멀티 미디어 프로그램을 제작하는 것이 가능하다.
*/
//! Example 1
class Example_01 : public CWndApp {
public:			// 생성자

	//! 생성자
	Example_01(HINSTANCE a_hInst, int a_nShowOpts, const SIZE &a_rstWndSize);
};
