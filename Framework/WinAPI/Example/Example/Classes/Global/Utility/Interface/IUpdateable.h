#pragma once

#include"../../Define/KGDefine.h"

//! 갱신 인터페이스
class IUpdateable {
public:			// public 인터페이스

	//! 상태를 갱신한다
	virtual void Update(float a_fDeltaTime) = 0;

	//! 상태를 갱신한다
	virtual void LateUpdate(float a_fDeltaTime) { }
};
