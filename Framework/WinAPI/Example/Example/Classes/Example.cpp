#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include "Example_01/Example_01.h"
#include "Example_02/Example_02.h"
#include "Example_03/Example_03.h"
#include "Example_04/Example_04.h"
#include "Example_05/Example_05.h"

/*
윈도우즈 운영체제는 멀티 바이트 방식과 유니 코드 방식으로 문자열을 처리한다. (즉, 멀티 바이트 
방식은 문자의 종류에 따라 1 ~ 2 바이트의 가변 크기로 문자를 처리하며, 유니 코드는 2 바이트의 
크기로 문자를 처리한다.)

따라서, WinAPI 는 두 문자열 방식을 처리하기 위한 중간 형태인 TCHAR 타입을 지원하며, 해당
자료형을 사용하면 멀티 바이트, 유니 코드 방식에 종속되지 않는 구문을 작성하는 것이 가능하다.
(즉, TCHAR 를 사용하면 프로젝트 설정에 따라 멀티 바이트, 유니 코드로 자동으로 변환된다.)
*/
//! 메인 함수
int WINAPI _tWinMain(HINSTANCE a_hInst, HINSTANCE a_hPrevInst, TCHAR *a_pszCmdLine, int a_nShowOpts) {
	SIZE stWndSize = {
		480, 320
	};

	//Example_01 oApp(a_hInst, a_nShowOpts, stWndSize);
	//Example_02 oApp(a_hInst, a_nShowOpts, stWndSize);
	//Example_03 oApp(a_hInst, a_nShowOpts, stWndSize);
	//Example_04 oApp(a_hInst, a_nShowOpts, stWndSize);
	Example_05 oApp(a_hInst, a_nShowOpts, stWndSize);

	return oApp.Run();
}
