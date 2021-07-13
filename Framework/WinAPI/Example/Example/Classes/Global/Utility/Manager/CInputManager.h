#pragma once

#include "../../Define/KGDefine.h"
#include "../Interface/IUpdateable.h"

//! 입력 관리자
class CInputManager : public IUpdateable {
public:			// IUpdateable

	//! 상태를 갱신한다
	virtual void Update(void) override;

public:			// public 함수

	//! 싱글턴
	DECLARE_SINGLETON(CInputManager);

	//! 초기화
	virtual void Init(void);

	//! 키 입력 여부를 검사한다
	bool IsKeyDown(BYTE a_nKeyCode) const;

	//! 키 입력 시작 여부를 검사한다
	bool IsKeyPress(BYTE a_nKeyCode) const;

	//! 키 입력 종료 여부를 검사한다
	bool IsKeyRelease(BYTE a_nKeyCode) const;

	//! 마우스 버튼 입력 여부를 검사한다
	bool IsMouseBtnDown(EMouseBtn a_eMouseBtn) const;

	//! 마우스 버튼 입력 시작 여부를 검사한다
	bool IsMouseBtnPress(EMouseBtn a_eMouseBtn) const;

	//! 마우스 버튼 입력 종료 여부를 검사한다
	bool IsMouseBtnRelease(EMouseBtn a_eMouseBtn) const;

	//! 마우스 휠을 반환한다
	int GetMouseWheel(void) const;

	//! 마우스 위치를 반환한다
	POINT GetMousePos(void) const;

private:			// private 함수

	//! 다이렉트 입력을 생성한다
	IDirectInput8 * CreateDInput(void);

	//! 키보드 디바이스를 생성한다
	IDirectInputDevice8 * CreateKeyboardDevice(void);

	//! 마우스 디바이스를 생성한다
	IDirectInputDevice8 * CreateMouseDevice(void);

private:			// private 변수

	BYTE m_anKeyStates[UCHAR_MAX + 1];
	BYTE m_anPrevKeyStates[UCHAR_MAX + 1];

	DIMOUSESTATE m_stMouseState;
	DIMOUSESTATE m_stPrevMouseState;

	IDirectInput8 *m_pDInput = nullptr;
	IDirectInputDevice8 *m_pKeyboardDevice = nullptr;
	IDirectInputDevice8 *m_pMouseDevice = nullptr;
};
