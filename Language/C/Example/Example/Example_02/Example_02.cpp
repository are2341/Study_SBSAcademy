//
//  Example_02.cpp
//  Example
//
//  Created by 이상동 on 2021/03/20.
//

#include "Example_02.hpp"

#define E02_VAR
#define E02_DATA_IO

//! Example 2
void Example_02(const int argc, const char **args) {
#if defined E02_VAR
	short nShortVal = 0;
	int nIntVal = 0;
	long nLongVal = 0;
	long long nLongLongVal = 0;
	
	printf("=====> 정수형 <=====\n");
	printf("Short (%ld) : %d\n", sizeof(nShortVal), nShortVal);
	printf("Int (%ld) : %d\n", sizeof(nIntVal), nIntVal);
	printf("Long (%ld) : %ld\n", sizeof(nLongVal), nLongVal);
	printf("Long Long (%ld) : %lld\n", sizeof(nLongLongVal), nLongLongVal);
	
	float fFltVal = 0.0f;
	double dblDblVal = 0.0;
	long double ldblLongDblVal = 0.0;
	
	printf("\n=====> 실수형 <=====\n");
	printf("Float (%ld) : %f\n", sizeof(fFltVal), fFltVal);
	printf("Double (%ld) : %lf\n", sizeof(dblDblVal), dblDblVal);
	printf("Long Double (%ld) : %Lf\n", sizeof(ldblLongDblVal), ldblLongDblVal);
	
	char chCharValA = 'A';
	char chCharValB = 'B';
	char chCharValC = 'C';
	
	printf("\n=====> 문자형 <=====\n");
	printf("Char (%ld) : %c, %c, %c\n", sizeof(char), chCharValA, chCharValB, chCharValC);
#elif defined E02_DATA_IO
	int nIntValA = 0;
	int nIntValB = 0;
	
	float fFltValA = 0.0f;
	float fFltValB = 0.0f;
	
	printf("정수 (2 개) 입력 : ");
	scanf("%d %d", &nIntValA, &nIntValB);
	
	printf("실수 (2 개) 입력 : ");
	scanf("%f %f", &fFltValA, &fFltValB);
	
	printf("=====> 정수형 <=====\n");
	printf("%d + %d = %d\n", nIntValA, nIntValB, nIntValA + nIntValB);
	
	printf("\n=====> 실수형 <=====\n");
	printf("%f + %f = %f\n", fFltValA, fFltValB, fFltValA + fFltValB);
#endif			// #if defined E02_VAR
}
