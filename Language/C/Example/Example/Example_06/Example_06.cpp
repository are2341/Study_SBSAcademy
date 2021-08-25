//
//  Example_06.cpp
//  Example
//
//  Created by 이상동 on 2021/07/16.
//

#include "Example_06.hpp"

#define E06_ARR
#define E06_STR
#define E06_PRACTICE

#if defined E06_ARR
#define ARR_1D
#define ARR_2D
#elif defined E06_PRACTICE
#define P06_A
#define P06_B
#define P06_C
#endif			// #if defined E06_ARR

//! Example 6
void Example_06(const int argc, const char **args) {
#if defined E06_ARR
#if defined ARR_1D
	/*
	 배열의 각 데이터 (변수) 를 배열의 요소라고 하며, 특정 배열 요소에 접근하기 위해서는 [] (인덱스 연산자) 와
	 인덱스 번호를 명시해주면 된다. 인덱스 번호는 "0 ~ 배열 길이 - 1" 의 범위를 지니고 있으며, 해당 범위를 벗어난
	 인덱스 번호를 명시했을 경우 프로그램이 오작동하거나 종료되는 문제가 발생하기 때문에 주의가 필요하다.
	 */
	int anValsA[5];
	anValsA[0] = 1;
	anValsA[1] = 2;
	anValsA[2] = 3;
	anValsA[3] = 4;
	anValsA[4] = 5;
	
	/*
	 배열 또한 일반적인 변수와 마찬가지로 선언과 동시에 값을 할당 할 수 있는 초기화를 지원하며, 초기화값은
	 {} (중괄호 연산자) 를 통해 명시하는 것이 가능하다. 초기화 값은 명시 된 순서대로 0 인덱스 요소부터 차례대로
	 배열 요소에 할당된다.
	 */
	int anValsB[5] = {
		1, 2, 3, 4, 5
	};
	
	/*
	 배열 길이보다 초가화 값을 적게 명시했을 경우 명시 된 순서대로 각 배열 요소에 값이 할당되며, 명시되지 않은
	 배열 요소는 자동으로 0 이 할당된다. (즉, 해당 규칙을 사용하면 특정 배열을 선언과 동시에 손쉽게 각 배열 요소를
	 0 으로 초기화하는 것이 가능하다. (Ex. anVals[5] = { 0 })
	 */
	int anValsC[5] = {
		1, 2, 3
	};
	
	/*
	 C/C++ 언어는 배열 길이를 생략해서 배열을 선언하는 것이 가능하다. 단, 배열 길이를 생략했을 경우 반드시 초기화 값을
	 명시해줘야한다. 이는, C/C++ 컴파일러가 명시 된 초기화 값을 개수를 기반으로 해당 배열의 길이를 자동으로 계산하기
	 때문이다.
	 */
	int anValsD[] = {
		1, 2, 3
	};
	
	/*
	 sizeof 키워드를 사용하면 배열의 길이를 계산하는 것이 가능하다. 해당 연산자는 주어진 변수 또는 자료형의 크기를
	 반환하는 역할을 수행하며, 배열을 명시했을 경우 배열의 크기를 반환한다.
	 
	 배열의 크기는 "배열 요소 크기 * 배열 길이" 이다. (즉, 배열 크기를 배열 요소 크기로 나눠줌으로써 배열 길이를
	 계산하는 것이 가능하다.)
	 */
	const int nSizeB = sizeof(anValsB) / sizeof(anValsB[0]);
	const int nSizeC = sizeof(anValsC) / sizeof(anValsC[0]);
	const int nSizeD = sizeof(anValsD) / sizeof(anValsD[0]);
	
	printf("=====> 배열 A 요소 <=====\n");
	printf("%d, %d, %d, %d, %d\n", anValsA[0], anValsA[1], anValsA[2], anValsA[3], anValsA[4]);
	
	printf("\n\n=====> 배열 B 요소 <=====\n");
	
	/*
	 반복문을 활용하면 배열을 좀 더 쉽게 제어하는 것이 가능하다. (즉, 배열 요소를 기반으로 특정 반복적인 연산이 필요
	 할 경우 반복문을 통해서 각 배열 요소를 제어하기 위한 구문의 중복을 최소화하는 것이 가능하다.)
	 */
	for(int i = 0; i < nSizeB; ++i) {
		printf("%d, ", anValsB[i]);
	}
	
	printf("\n\n=====> 배열 C 요소 <=====\n");
	
	for(int i = 0; i < nSizeC; ++i) {
		printf("%d, ", anValsC[i]);
	}
	
	printf("\n\n=====> 배열 D 요소 <=====\n");
	
	for(int i = 0; i < nSizeD; ++i) {
		printf("%d, ", anValsD[i]);
	}
	
	printf("\n");
#elif defined ARR_2D
	int anMatrixA[2][2];
	anMatrixA[0][0] = 1;
	anMatrixA[0][1] = 2;
	anMatrixA[1][0] = 3;
	anMatrixA[1][1] = 4;
	
	int anMatrixB[2][2] = {
		{ 1, 2 },
		{ 3, 4 }
	};
	
	int anMatrixC[2][2] = {
		{ 1 },
		{ 3 }
	};
	
	int anMatrixD[2][2] = {
		1, 3
	};
	
	int anMatrixE[][2] = {
		1, 2, 3
	};
	
	const int nNumRowsA = sizeof(anMatrixA) / sizeof(anMatrixA[0]);
	const int nNumColsA = sizeof(anMatrixA[0]) / sizeof(anMatrixA[0][0]);
	
	const int nNumRowsB = sizeof(anMatrixB) / sizeof(anMatrixB[0]);
	const int nNumColsB = sizeof(anMatrixB[0]) / sizeof(anMatrixB[0][0]);
	
	const int nNumRowsC = sizeof(anMatrixC) / sizeof(anMatrixC[0]);
	const int nNumColsC = sizeof(anMatrixC[0]) / sizeof(anMatrixC[0][0]);
	
	const int nNumRowsD = sizeof(anMatrixD) / sizeof(anMatrixD[0]);
	const int nNumColsD = sizeof(anMatrixD[0]) / sizeof(anMatrixD[0][0]);
	
	const int nNumRowsE = sizeof(anMatrixE) / sizeof(anMatrixE[0]);
	const int nNumColsE = sizeof(anMatrixE[0]) / sizeof(anMatrixE[0][0]);
	
	printf("=====> 행렬 A 요소 <=====\n");
	
	for(int i = 0; i < nNumRowsA; ++i) {
		for(int j = 0; j < nNumColsA; ++j) {
			printf("%d, ", anMatrixA[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\n=====> 행렬 B 요소 <=====\n");
	
	for(int i = 0; i < nNumRowsB; ++i) {
		for(int j = 0; j < nNumColsB; ++j) {
			printf("%d, ", anMatrixB[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\n=====> 행렬 C 요소 <=====\n");
	
	for(int i = 0; i < nNumRowsC; ++i) {
		for(int j = 0; j < nNumColsC; ++j) {
			printf("%d, ", anMatrixC[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\n=====> 행렬 D 요소 <=====\n");
	
	for(int i = 0; i < nNumRowsD; ++i) {
		for(int j = 0; j < nNumColsD; ++j) {
			printf("%d, ", anMatrixD[i][j]);
		}
		
		printf("\n");
	}
	
	printf("\n=====> 행렬 E 요소 <=====\n");
	
	for(int i = 0; i < nNumRowsE; ++i) {
		for(int j = 0; j < nNumColsE; ++j) {
			printf("%d, ", anMatrixE[i][j]);
		}
		
		printf("\n");
	}
#endif			// #if defined ARR_1D
#elif defined E06_STR
	char szStrA[] = "ABC";
	char szStrB[] = "DEF";
	
	printf("=====> 문자열 <=====\n");
	printf("Str A : %s\n", szStrA);
	printf("Str B : %s\n", szStrB);
#elif defined E06_PRACTICE
#if defined P06_A
	
#elif defined P06_B
	
#elif defined P06_C
	
#endif			// #if defined P06_A
#endif			// #if defined E06_ARR
}
