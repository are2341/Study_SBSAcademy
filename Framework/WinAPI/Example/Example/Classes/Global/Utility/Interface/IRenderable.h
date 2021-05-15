#pragma once

#include "../../Define/KGDefine.h"

//! 렌더링 인터페이스
class IRenderable {
public:			// public 인터페이스

	//! 물체를 그린다
	virtual void Render(HDC a_hDC) = 0;

protected:			// protected 인터페이스

	//! 물체를 그리기 전
	virtual void PreRender(HDC a_hDC) { }

	//! 물체를 그린다
	virtual void DoRender(HDC a_hDC) { }

	//! 물체를 그린 후
	virtual void PostRender(HDC a_hDC) { }
};
