//
//  Example_04.cpp
//  Example
//
//  Created by 이상동 on 2021/07/16.
//

#include "Example_04.hpp"

#define E04_IF_ELSE
#define E04_SWITCH_CASE
#define E04_PRACTICE

#if defined E04_PRACTICE
#define P04_A
#define P04_B
#endif			// #if defined E04_PRACTICE

//! Example 4
void Example_04(const int argc, const char **args) {
#if defined E04_IF_ELSE
	int nScore = 0;
	
	printf("점수 입력 : ");
	scanf("%d", &nScore);
	
	// F 학점 일 경우
	if(nScore < 60) {
		printf("F 학점입니다.\n");
	} else {
		// A 학점 일 경우
		if(nScore >= 90) {
			printf("A 학점입니다.\n");
		}
		// B 학점 일 경우
		else if(nScore >= 80) {
			printf("B 학점입니다.\n");
		}
		// C 학점 일 경우
		else if(nScore >= 70) {
			printf("C 학점입니다.\n");
		} else {
			printf("D 학점입니다.\n");
		}
	}
#elif defined E04_SWITCH_CASE
	
#elif defined E04_PRACTICE
#if defined P04_A
	
#elif defined P04_B
	
#endif			// #if defined P04_A
#endif			// #if defined E04_IF_ELSE
}
