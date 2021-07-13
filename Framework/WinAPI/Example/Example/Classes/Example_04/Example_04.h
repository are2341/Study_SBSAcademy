#pragma once

#include "../Global/Define/KGDefine.h"
#include "../Global/Utility/Base/CWndApp.h"

//! Example 4
class Example_04 : public CWndApp {
public:

	//! 색상
	enum class EColor {
		NONE = -1,
		RED,
		GREEN,
		BLUE,
		MAX_VAL
	};

	//! 도형
	enum class EShape {
		NONE = -1,
		LINE,
		RECTANGLE,
		ELLIPSE,
		MAX_VAL
	};

	//! 도형 정보
	struct STShapeInfo {
		EColor m_eColor;
		EShape m_eShape;

		POINT m_stStartPos;
		POINT m_stEndPos;
	};

public:			// public 함수

	//! 상태를 갱신한다
	virtual void Update(void) override;

	//! 물체를 그린다
	virtual void DoRender(void) override;

public:			// 생성자, 소멸자

	//! 생성자
	Example_04(HINSTANCE a_hInst, int a_nShowOpts, const SIZE &a_rstWndSize);

	//! 소멸자
	~Example_04(void);

protected:			// protected 함수

	//! 초기화
	virtual void Init(void) override;

private:			// private 변수

	EColor m_eColor = EColor::RED;
	EShape m_eShape = EShape::LINE;

	std::vector<STShapeInfo> m_oShapeInfoList;

	std::unordered_map<EColor, HPEN> m_oPenList;
	std::unordered_map<EColor, HBRUSH> m_oBrushList;
};
