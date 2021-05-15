#pragma once

#include "../../Define/KGDefine.h"

//! 복사 방지 인터페이스
class INoncopyable {
public:			// 인터페이스

	//! operator=
	void operator=(const INoncopyable &a_rOther);

	//! 복사 생성자
	INoncopyable(const INoncopyable &a_rOther);

public:			// 생성자, 소멸자

	//! 생성자
	INoncopyable(void) { }

	//! 소멸자
	virtual ~INoncopyable(void) = 0;
};

//! 소멸자
INoncopyable::~INoncopyable(void) {
	// Do Nothing
}
