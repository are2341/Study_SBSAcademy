#pragma once

#include "../../Define/KGDefine.h"
#include "../Interface/IUpdateable.h"

//! 시간 관리자
class CTimeManager : public IUpdateable {
public:			// IUpdateable

	//! 상태를 갱신한다
	virtual void Update(void) override;

public:			// public 함수

	//! 싱글턴
	DECLARE_SINGLETON(CTimeManager);

	//! 시간 간격을 반환한다
	DECLARE_GETTER(float, DeltaTime, m_fDeltaTime);

	//! 실행 시간을 반환한다
	DECLARE_GETTER(float, RunningTime, m_fRunningTime);

	//! 초기화
	virtual void Init(void);

private:			// private 변수

	float m_fDeltaTime = 0.0f;
	float m_fRunningTime = 0.0f;

	std::chrono::system_clock::time_point m_oPrevTime;
	std::chrono::system_clock::time_point m_oStartTime;
};
