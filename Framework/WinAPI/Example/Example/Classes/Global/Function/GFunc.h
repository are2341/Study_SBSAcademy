#pragma once

#include "../Define/KGDefine.h"

//! 전역 함수
class GFunc {
public:			// public 함수

	//! 선을 그린다
	static void DrawLine(HDC a_hDC, POINT a_stStartPos, POINT a_stEndPos);
};
