//
//  Example_03.cpp
//  Example
//
//  Created by 이상동 on 2021/07/16.
//

#include "Example_03.hpp"

//! Example 3
void Example_03(const int argc, const char **args) {
	int nValA = 0;
	int nValB = 0;
	
	printf("정수 (2 개) 입력 : ");
	scanf("%d %d", &nValA, &nValB);
	
	printf("=====> 산술 연산자 <=====\n");
	printf("%d + %d = %d\n", nValA, nValB, nValA + nValB);
	printf("%d - %d = %d\n", nValA, nValB, nValA - nValB);
	printf("%d * %d = %d\n", nValA, nValB, nValA * nValB);
	printf("%d / %d = %f\n", nValA, nValB, nValA / (float)nValB);
	printf("%d %% %d = %d\n", nValA, nValB, nValA % nValB);
	
	printf("\n=====> 관계 연산자 <=====\n");
	printf("%d < %d : %d\n", nValA, nValB, nValA < nValB);
	printf("%d > %d : %d\n", nValA, nValB, nValA > nValB);
	printf("%d <= %d : %d\n", nValA, nValB, nValA <= nValB);
	printf("%d >= %d : %d\n", nValA, nValB, nValA >= nValB);
	printf("%d == %d : %d\n", nValA, nValB, nValA == nValB);
	printf("%d != %d : %d\n", nValA, nValB, nValA != nValB);
	
	printf("\n=====> 논리 연산자 <=====\n");
	printf("%d && %d : %d\n", nValA, nValB, nValA && nValB);
	printf("%d || %d : %d\n", nValA, nValB, nValA || nValB);
	printf("!%d : %d\n", nValA, !nValA);
	printf("!%d : %d\n", nValB, !nValB);
	
	printf("\n=====> 증감 연산자 <=====\n");
	printf("++%d, --%d\n", ++nValA, --nValB);
	printf("%d++, %d--\n", nValA++, nValB--);
	
	printf("\n=====> 조건 연산자 <=====\n");
	printf("%d < %d ? : %d\n", nValA, nValB, (nValA < nValB) ? nValA : nValB);
}
