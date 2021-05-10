#pragma once

#include "../../Define/KGDefine.h"

//! 렌더링 인터페이스
class IRenderable {
public:			// public 인터페이스

	//! 물체를 그린다
	virtual void Render(void) = 0;

protected:			// protected 인터페이스

	//! 물체를 그리기 전
	virtual void PreRender(void) { }

	//! 물체를 그린다
	virtual void DoRender(void) { }

	//! 물체를 그린 후
	virtual void PostRender(void) { }
};
