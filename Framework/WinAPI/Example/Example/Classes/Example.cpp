#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include "Example_01/Example_01.h"
#include "Example_02/Example_02.h"
#include "Example_03/Example_03.h"
#include "Example_04/Example_04.h"
#include "Example_05/Example_05.h"

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
