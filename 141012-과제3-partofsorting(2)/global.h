/*
	Subject - JLand(Sort) Project / global.h
	Director - ........... Jeong / OOOOOOOOOOOOOOO�� / Business & Computer Science
	Created Date - 2014. 10. 8
	Description - Global ���� / ������Ʈ ��ü ��� ��� (CMD, RandBox)
	[Version]
*/

#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <time.h>

// Platform
const int PLATFORM_WIN32 = 99;
const int PLATFORM_UNIX = 100;

/* Multi Platform Support */
#ifdef WIN32
#include <windows.h>
#include <direct.h>
#else
#include <unistd.h>
#endif

/* Multi Platform Support */
#ifdef WIN32
	const int PLATFORM_TYPE = PLATFORM_WIN32;
#else
	const int PLATFORM_TYPE = PLATFORM_UNIX;
#endif

/* Multi PATH */
#ifndef MAX_PATH
	#define MAX_PATH 260
#endif

/* TRUE */
#ifndef TRUE
	#define TRUE 1
#endif

/* FALSE */
#ifndef FALSE
	#define FALSE 0
#endif

/* NULL */
#ifndef J_NULL
	#define J_NULL 0
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
const int MENU_LINKED_INSERT = 5;
const int MENU_ABOUT = 6;

// Global - ����(PROJECT)
const int GLOBAL_PJT_SYSMAIN = 400;						// PJT - SYSMAIN
const int GLOBAL_PJT_JPROGRAM = 401;					// PJT - JPROGRAM
const int GLOBAL_PJT_JAPP = 402;						// PJT - JAPP
const int GLOBAL_PJT_JSORT = 403;		    			// PJT - JSORT
const int GLOBAL_PJT_POLYGON = 403;						// PJT - POLYGON

// Global - �ɼ�(���ΰ�������)
const int GLOBAL_OPTION_TITLE = 500;					// OPTION : TITLE
const int GLOBAL_OPTION_TITLE_ANALYSIS = 501;			// OPTION : TITLE - Analysis
const int GLOBAL_OPTION_TITLE_RAND = 502;				// OPTION : TITLE - Rand
const int GLOBAL_OPTION_TITLE_USERSIZE = 503;			// OPTION : TITLE - USERSIZE
const int GLOBAL_OPTION_TITLE_POLYGON = 504;			// OPTION : TITLE - Polygon
const int GLOBAL_OPTION_TITLE_LINKED = 505;				// OPTION : TITLE - ��ũ�� �ڷ��� Ÿ��
const int GLOBAL_OPTION_WAIT = 600;						// OPTION : WAIT()
const int GLOBAL_OPTION_MENU_NOT_FOUND = 700;			// OPTION : ������ �޴�

// Global - RandBox �ɼ�
const int TYPE_RAND_LOW = 1;
const int TYPE_RAND_MID = 2;
const int TYPE_RAND_HIGH = 3;

const int RAND_LOW_START = 5;
const int RAND_LOW_END = 25;

const int RAND_MID_START = 100;
const int RAND_MID_END = 1000;

const int RAND_HIGH_START = 2000;
const int RAND_HIGH_END = 5000;

// ��¥ - �ɼ�
const int YYYYMMDD = 10;
const int HHMMSEC = 20;

// ���� �̸�
const int TYPE_FAMILY_NAME = 10;
const int TYPE_FULL_NAME = 20;

// Global Function
void Print(const int PJT_Name, const int Option);	// Print �Լ� - �����Լ�
std::string JCurPwd();
int Cmd(int cmdSvc, int argv = J_NULL);
std::string GetToday(const int TYPE);
std::vector<std::string> GetName(const int Type);
void OutFileExtract(std::string Data);
int RandBox(const int Type);

// G++�� ������ ȣȯ(std::to_string(const T& n)) ����
namespace JPatch
{
	template < typename T > std::string to_string(const T& n)
	{
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
}

#endif