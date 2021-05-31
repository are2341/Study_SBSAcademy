#pragma once

#include "../Global/Define/KGDefine.h"
#include "../Global/Utility/Base/CWndApp.h"

//! Example 3
class Example_03 : public CWndApp {
public:

	//! 색상
	enum class EColor {
		NONE = -1,
		RED,
		GREEN,
		BLUE,
		MAX_VAL
	};

	//! 라인 정보
	struct STLineInfo {
		EColor m_eColor;

		POINT m_stStartPos;
		POINT m_stEndPos;
	};

public:			// public 함수

	//! 상태를 갱신한다
	virtual void Update(float a_fDeltaTime) override;

	//! 물체를 그린다
	virtual void DoRender(HDC a_hDC) override;

public:			// 생성자, 소멸자

	//! 생성자
	Example_03(HINSTANCE a_hInst, int a_nShowOpts, const SIZE &a_rstWndSize);

	//! 소멸자
	virtual ~Example_03(void);

protected:			// protected 함수

	//! 초기화
	virtual void Init(void) override;

private:			// private 변수

	EColor m_eColor = EColor::RED;

	std::vector<STLineInfo> m_oLineInfoList;
	std::unordered_map<EColor, HPEN> m_oPenList;
};
