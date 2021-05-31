#include "GFunc.h"

void GFunc::DrawStr(HDC a_hDC, TCHAR * a_pszStr, POINT a_stPos, UINT a_nFmt) {
	RECT stStrRect = {
		a_stPos.x, a_stPos.y
	};

	/*
	DrawText 함수는 문자열을 윈도우 상에 그리는 역할을 수행한다. 해당 함수를 사용해서 문자열을
	올바른 위치에 출력하기 위해서는 출력 될 문자열의 영역을 계산 할 필요가 있으며, 해당 영역을
	계산하기 위해서는 DT_CALCRECT 속성을 지정하면 된다. (즉, 해당 속성을 지정하면 실제 문자열이
	윈도우 상에 그려지는 것이 아니라 해당 영역에 대한 계산을 수행한다.)
	*/
	DrawText(a_hDC, a_pszStr, -1, &stStrRect, a_nFmt | DT_CALCRECT);
	DrawText(a_hDC, a_pszStr, -1, &stStrRect, a_nFmt);
}

void GFunc::DrawLine(HDC a_hDC, POINT a_stStartPos, POINT a_stEndPos) {
	/*
	MoveToEx 함수는 시작점을 명시하는 역할을 수행하며, LineTo 함수는 시작점으로부터
	해당 함수에 입력으로 주어진 위치까지 선을 그리는 역할을 수행한다.
	*/
	MoveToEx(a_hDC, a_stStartPos.x, a_stStartPos.y, NULL);
	LineTo(a_hDC, a_stEndPos.x, a_stEndPos.y);
}

void GFunc::DrawRectangle(HDC a_hDC, POINT a_stStartPos, POINT a_stEndPos) {
	HPEN hPen = (HPEN)GetStockObject(BLACK_PEN);
	HPEN hPrevPen = (HPEN)SelectObject(a_hDC, hPen);

	__try {
		Rectangle(a_hDC, a_stStartPos.x, a_stStartPos.y, a_stEndPos.x, a_stEndPos.y);
	} __finally {
		SelectObject(a_hDC, hPrevPen);
	}
}

void GFunc::DrawEllipse(HDC a_hDC, POINT a_stStartPos, POINT a_stEndPos) {
	HPEN hPen = (HPEN)GetStockObject(BLACK_PEN);
	HPEN hPrevPen = (HPEN)SelectObject(a_hDC, hPen);

	__try {
		Ellipse(a_hDC, a_stStartPos.x, a_stStartPos.y, a_stEndPos.x, a_stEndPos.y);
	} __finally {
		SelectObject(a_hDC, hPrevPen);
	}
}
