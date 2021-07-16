//
//  Example_05.cpp
//  Example
//
//  Created by 이상동 on 2021/07/16.
//

#include "Example_05.hpp"

//#define E05_WHILE
//#define E05_FOR
//#define E05_DO_WHILE
#define E05_PRACTICE

#if defined E05_PRACTICE
//#define P05_A
//#define P05_B
#define P05_C
#endif			// #if defined E05_PRACTICE

//! Example 5
void Example_05(const int argc, const char **args) {
#if defined E05_WHILE
	int i = 0;
	int nRepeatTimes = 0;
	
	printf("반복 횟수 입력 : ");
	scanf("%d", &nRepeatTimes);
	
	while(i < nRepeatTimes) {
		printf("Hello, World!\n");
		i += 1;
	}
#elif defined E05_FOR
	
#elif defined E05_DO_WHILE
	
#elif defined E05_PRACTICE
#if defined P05_A
	int nVal = 1;
	int nSumVal = 0;
	
	while(nVal > 0) {
		printf("정수 입력 : ");
		scanf("%d", &nVal);
		
		// 양수 일 경우
		if(nVal >= 0) {
			nSumVal += nVal;
		}
	}
	
	printf("\n합계 : %d\n", nSumVal);
#elif defined P05_B
	int nVal = 0;
	
	printf("정수 입력 : ");
	scanf("%d", &nVal);
	
	printf("=====> %d 단 <=====\n", nVal);
	
	for(int i = 1; i < 10; ++i) {
		printf("%d * %d = %d\n", nVal, i, nVal * i);
	}
#elif defined P05_C
	for(int i = 2; i < 10; ++i) {
		printf("=====> %d 단 <=====\n", i);
		
		for(int j = 1; j < 10; ++j) {
			printf("%d * %d = %d\n", i, j, i * j);
		}
		
		printf("\n");
	}
#endif			// #if defined P05_A
#endif			// #if defined E05_WHILE
}
