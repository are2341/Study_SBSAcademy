#include "GFunc.h"

void GFunc::DrawLine(HDC a_hDC, POINT a_stStartPos, POINT a_stEndPos) {
	/*
	MoveToEx 함수는 시작점을 명시하는 역할을 수행하며, LineTo 함수는 시작점으로부터
	해당 함수에 입력으로 주어진 위치까지 선을 그리는 역할을 수행한다.
	*/
	MoveToEx(a_hDC, a_stStartPos.x, a_stStartPos.y, NULL);
	LineTo(a_hDC, a_stEndPos.x, a_stEndPos.y);
}
