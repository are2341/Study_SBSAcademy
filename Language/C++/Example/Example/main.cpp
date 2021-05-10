//
//  main.cpp
//  Example
//
//  Created by 이상동 on 2021/03/20.
//

#include "Example_01/Example_01.hpp"

/*
 C++ 언어 주제 리스트
 :
 - Example_01 (C++ 기초)
 - Example_02 (함수 오버로딩, 디폴트 매개 변수)
 - Example_03 (인라인 함수, 레퍼런스, 문자열)
 - Example_04 (클래스, 정보 은닉)
 - Example_05 (상속, 다형성)
 - Example_06 (연산자 오버로딩)
 - Example_07 (템플릿)
 - Example_08 (모던 C++)
 - Example_09 (STL)
 - Example_10 (실전 프로젝트)
 */
//! 메인 함수
int main(const int argc, const char **args) {
	/*
	 :: (멤버 지정 연산자) 를 사용하면 특정 영역 하위에 존재하는 변수 및 함수 등에 접근하는 것이 가능하다.
	 */
	E01::Example_01(argc, args);
	
	return 0;
}
