#ifndef _GLOBAL_H_
#define _GLOBAL_H_


#include <time.h>

// Platform
const int PLATFORM_WIN32 = 99;
const int PLATFORM_UNIX = 100;

/* Multi Platform Support */
#ifdef WIN32
	const int PLATFORM_TYPE = PLATFORM_WIN32;
#else
	const int PLATFORM_TYPE = PLATFORM_UNIX;
#endif

// Global 명령어
const int CMD_CLEAR = 100;
const int CMD_DELAY = 101;

// Global - 메뉴
const int EXIT = 0;
const int MENU_INTEGER = 1;
const int MENU_DOUBLE = 2;
const int MENU_DOUBLE_POLYGON = 3;
const int MENU_STRING = 4;

// Global - 참 / 거짓
const int TRUE = 1;
const int FALSE = 0;

// Global - 주제(PROJECT)
const int GLOBAL_PJT_SYSMAIN = 400;	 // PJT - SYSMAIN
const int GLOBAL_PJT_JPROGRAM = 401; // PJT - JPROGRAM
const int GLOBAL_PJT_POLYGON = 402;  // PJT - POLYGON

// Global - 옵션(세부공통주제)
const int GLOBAL_OPTION_TITLE = 500;			// OPTION : TITLE
const int GLOBAL_OPTION_WAIT = 600;				// OPTION : WAIT()
const int GLOBAL_OPTION_MENU_NOT_FOUND = 700;   // OPTION : 미지원 메뉴

// 명령어 함수
int Cmd(int cmdSvc, int argv = NULL){

	int Result = TRUE;

	// 플랫폼 확인
	switch (PLATFORM_TYPE){

		// Win32
	case PLATFORM_WIN32:

		switch (cmdSvc)
		{
			case CMD_CLEAR:
				system("cls");
				break;

			case CMD_DELAY:
				clock_t t1, t2;
				t1 = clock();
				while (1)
				{
					t2 = clock();
					if ((t2 - t1) > (argv * CLOCKS_PER_SEC))
						break;
				}

				break;

			default:
				Result = FALSE;
				break;
		} // End of Switch

		break; // End of Win32

		// Unix
	case PLATFORM_UNIX:

		switch (cmdSvc)
		{
			case CMD_CLEAR:
				system("clear");
				break;

			case CMD_DELAY:
				#ifdef WIN32
				#else
					sleep(argv);
				#endif

				break;

			default:
				Result = FALSE;
				break;
		}

		break; // End of Unix
	} // End of Switch

	return Result;

}

#endif