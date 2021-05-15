//
//  main.cpp
//  Example
//
//  Created by 이상동 on 2021/03/20.
//

#include "Example_01/Example_01.hpp"
#include "Example_02/Example_02.hpp"

/*
 C 언어 주제 리스트
 :
 - Example_01 (C 기초)
 - Example_02 (변수/상수, 데이터 입/출력)
 - Example_03 (연산자)
 - Example_04 (조건문)
 - Example_05 (반복문)
 - Example_06 (배열, 문자열)
 - Example_07 (함수, 지역/전역 공간)
 - Example_08 (포인터)
 - Example_09 (사용자 정의 자료형)
 - Example_10 (파일 시스템)
 - Example_11 (실전 프로젝트)
 
 메인 함수란?
 :
 - C 언어로 작성 된 프로그램에 가장 먼저 호출되는 함수를 의미하며, 진입 함수라고도 한다. (즉, 메인 함수는 프로그램이
 실행 될 때 운영체제에 의해 자동으로 호출되기 때문에 해당 함수를 반드시 구현해주어야한다.) 또한, 메인 함수가 종료 될 경우
 이는 곧 프로그램의 종료를 의미한다.
 
 C 언어로 작성 된 프로그램은 일반적으로 여러 개의 소스 파일 (.c) 로 작성이 되며, 이러한 파일에 존재하는 함수 중 가장
 먼저 호출되어 실행되는 것이 메인 함수이다. (즉, 메인 함수는 프로그램이 시작이다.)
 
 C 언어 메인 함수의 유형
 :
 - 입력 O, 출력 O		<= int main(const int, const char **);
 - 입력 O, 출력 X		<= void main(const int, const char **);
 - 입력 X, 출력 O		<= int main(void);
 - 입력 X, 출력 X		<= void main(void);
 
 C 언어 파일 유형
 :
 - 헤더 파일		<= 각 소스 파일 간에 정보를 알리기 위한 용도
 - 소스 파일		<= 실제 컴퓨터가 실행 할 명령어를 작성하기 위한 용도
 */
//! 메인 함수
int main(const int argc, const char **args) {
	srand((unsigned int)time(NULL));
	
	Example_01(argc, args);
	Example_02(argc, args);
	
	return 0;
}
