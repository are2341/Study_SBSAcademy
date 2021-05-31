#pragma once

#include "../../Define/KGDefine.h"
#include "../Interface/IUpdateable.h"
#include "../Interface/IRenderable.h"
#include "../Interface/INoncopyable.h"

//! 윈도우 어플리케이션
class CWndApp : public IUpdateable, public IRenderable, public INoncopyable {
public:			// IUpdateable

	//! 상태를 갱신한다
	virtual void Update(float a_fDeltaTime) override;

public:			// IRenderable

	//! 물체를 그린다
	virtual void Render(HDC a_hDC) final override;

public:			// public 함수

	//! 윈도우 크기를 반환한다
	DECLARE_GETTER(SIZE, WndSize, m_stWndSize);

	//! 윈도우 핸들을 반환한다
	DECLARE_GETTER(HWND, WndHandle, m_hWnd);

	//! 인스턴스 핸들을 반환한다
	DECLARE_GETTER(HINSTANCE, InstHandle, m_hInst);

	//! 인스턴스를 반환한다
	DECLARE_STATIC_GETTER(CWndApp *, Inst, m_pInst);

	//! 어플리케이션을 실행한다
	int Run(void);

	//! 윈도우 메세지를 처리한다
	virtual LRESULT HandleWndMsg(HWND a_hWnd, UINT a_nMsg, WPARAM a_wParams, LPARAM a_lParams);

protected:			// protected 함수

	//! 초기화
	virtual void Init(void);

	//! 메세지 루프를 실행한다
	virtual int RunMsgLoop(void);

	//! 크기 메세지를 처리한다
	virtual LRESULT HandleSizeMsg(WPARAM a_wParams, LPARAM a_lParams);

	//! 그리기 메세지를 처리한다
	virtual LRESULT HandlePaintMsg(WPARAM a_wParams, LPARAM a_lParams);

	//! 제거 메세지를 처리한다
	virtual LRESULT HandleDestroyMsg(WPARAM a_wParams, LPARAM a_lParams);

	//! 윈도우를 생성한다
	virtual HWND CreateWnd(WNDCLASS *a_pstOutWndCls);

protected:			// 생성자, 소멸자

	//! 생성자
	CWndApp(HINSTANCE a_hInst, int a_nShowOpts, const SIZE &a_rstWndSize);

	//! 소멸자
	virtual ~CWndApp(void);

protected:			// protected 변수

	int m_nShowOpts = 0;
	float m_fSkipTime = 0.0f;

	SIZE m_stWndSize;
	WNDCLASS m_stWndCls;

	HDC m_hDC = nullptr;
	HWND m_hWnd = nullptr;
	HBITMAP m_hBitmap = nullptr;
	HINSTANCE m_hInst = nullptr;

	FILE *m_pstRStream = nullptr;
	FILE *m_pstWStream = nullptr;

	static CWndApp *m_pInst;
};
