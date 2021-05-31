#pragma once

#include "../Define/KGDefine.h"

//! 전역 함수
class GFunc {
public:			// public 함수

	//! 문자열을 그린다
	static void DrawStr(HDC a_hDC, TCHAR *a_pszStr, POINT a_stPos, UINT a_nFmt);

	//! 선을 그린다
	static void DrawLine(HDC a_hDC, POINT a_stStartPos, POINT a_stEndPos);

	//! 사각형을 그린다
	static void DrawRectangle(HDC a_hDC, POINT a_stStartPos, POINT a_stEndPos);

	//! 타원을 그린다
	static void DrawEllipse(HDC a_hDC, POINT a_stStartPos, POINT a_stEndPos);
};
