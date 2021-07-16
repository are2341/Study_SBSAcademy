//
//  Example_06.cpp
//  Example
//
//  Created by 이상동 on 2021/07/16.
//

#include "Example_06.hpp"

//#define E06_ARR
#define E06_STR
#define E06_PRACTICE

#if defined E06_ARR
//#define ARR_SINGLE
#define ARR_MATRIX
#elif defined E06_PRACTICE
#define P06_A
#define P06_B
#define P06_C
#endif			// #if defined E06_ARR

//! Example 6
void Example_06(const int argc, const char **args) {
#if defined E06_ARR
#if defined ARR_SINGLE
	int anValsA[5];
	anValsA[0] = 1;
	anValsA[1] = 2;
	anValsA[2] = 3;
	anValsA[3] = 4;
	anValsA[4] = 5;
	
	int anValsB[5] = {
		1, 2, 3, 4, 5
	};
	
	int anValsC[5] = {
		1, 2, 3
	};
	
	int anValsD[] = {
		1, 2, 3
	};
	
	const int nSizeA = sizeof(anValsA) / sizeof(anValsA[0]);
	const int nSizeB = sizeof(anValsB) / sizeof(anValsB[0]);
	const int nSizeC = sizeof(anValsC) / sizeof(anValsC[0]);
	const int nSizeD = sizeof(anValsD) / sizeof(anValsD[0]);
	
	printf("=====> 배열 A 요소 <=====\n");
	
	for(int i = 0; i < nSizeA; ++i) {
		printf("%d, ", anValsA[i]);
	}
	
	printf("\n\n=====> 배열 B 요소 <=====\n");
	
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
#elif defined ARR_MATRIX
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
#endif			// #if defined ARR_SINGLE
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
