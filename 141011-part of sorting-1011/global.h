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

// Global ��ɾ�
const int CMD_CLEAR = 100;
const int CMD_DELAY = 101;

// Global - �޴�
const int EXIT = 0;
const int MENU_INTEGER = 1;
const int MENU_DOUBLE = 2;
const int MENU_DOUBLE_POLYGON = 3;
const int MENU_STRING = 4;

// Global - �� / ����
const int TRUE = 1;
const int FALSE = 0;

// Global - ����(PROJECT)
const int GLOBAL_PJT_SYSMAIN = 400;	 // PJT - SYSMAIN
const int GLOBAL_PJT_JPROGRAM = 401; // PJT - JPROGRAM
const int GLOBAL_PJT_POLYGON = 402;  // PJT - POLYGON

// Global - �ɼ�(���ΰ�������)
const int GLOBAL_OPTION_TITLE = 500;			// OPTION : TITLE
const int GLOBAL_OPTION_WAIT = 600;				// OPTION : WAIT()
const int GLOBAL_OPTION_MENU_NOT_FOUND = 700;   // OPTION : ������ �޴�

// ��ɾ� �Լ�
int Cmd(int cmdSvc, int argv = NULL){

	int Result = TRUE;

	// �÷��� Ȯ��
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