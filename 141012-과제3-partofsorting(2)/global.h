/*
	Subject - JLand(Sort) Project / global.h
	Director - ........... Jeong / OOOOOOOOOOOOOOO교 / Business & Computer Science
	Created Date - 2014. 10. 8
	Description - Global 영역 / 프로젝트 전체 대상 기능 (CMD, RandBox)
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

// Global 명령어
const int CMD_CLEAR = 100;
const int CMD_DELAY = 101;

// Global - 메뉴
const int EXIT = 0;
const int MENU_INTEGER = 1;
const int MENU_DOUBLE = 2;
const int MENU_DOUBLE_POLYGON = 3;
const int MENU_STRING = 4;
const int MENU_LINKED_INSERT = 5;
const int MENU_ABOUT = 6;

// Global - 주제(PROJECT)
const int GLOBAL_PJT_SYSMAIN = 400;						// PJT - SYSMAIN
const int GLOBAL_PJT_JPROGRAM = 401;					// PJT - JPROGRAM
const int GLOBAL_PJT_JAPP = 402;						// PJT - JAPP
const int GLOBAL_PJT_JSORT = 403;		    			// PJT - JSORT
const int GLOBAL_PJT_POLYGON = 403;						// PJT - POLYGON

// Global - 옵션(세부공통주제)
const int GLOBAL_OPTION_TITLE = 500;					// OPTION : TITLE
const int GLOBAL_OPTION_TITLE_ANALYSIS = 501;			// OPTION : TITLE - Analysis
const int GLOBAL_OPTION_TITLE_RAND = 502;				// OPTION : TITLE - Rand
const int GLOBAL_OPTION_TITLE_USERSIZE = 503;			// OPTION : TITLE - USERSIZE
const int GLOBAL_OPTION_TITLE_POLYGON = 504;			// OPTION : TITLE - Polygon
const int GLOBAL_OPTION_TITLE_LINKED = 505;				// OPTION : TITLE - 링크드 자료형 타입
const int GLOBAL_OPTION_WAIT = 600;						// OPTION : WAIT()
const int GLOBAL_OPTION_MENU_NOT_FOUND = 700;			// OPTION : 미지원 메뉴

// Global - RandBox 옵션
const int TYPE_RAND_LOW = 1;
const int TYPE_RAND_MID = 2;
const int TYPE_RAND_HIGH = 3;

const int RAND_LOW_START = 5;
const int RAND_LOW_END = 25;

const int RAND_MID_START = 100;
const int RAND_MID_END = 1000;

const int RAND_HIGH_START = 2000;
const int RAND_HIGH_END = 5000;

// 날짜 - 옵션
const int YYYYMMDD = 10;
const int HHMMSEC = 20;

// 랜덤 이름
const int TYPE_FAMILY_NAME = 10;
const int TYPE_FULL_NAME = 20;

// Global Function
void Print(const int PJT_Name, const int Option);	// Print 함수 - 공통함수
std::string JCurPwd();
int Cmd(int cmdSvc, int argv = J_NULL);
std::string GetToday(const int TYPE);
std::vector<std::string> GetName(const int Type);
void OutFileExtract(std::string Data);
int RandBox(const int Type);

// G++의 구버전 호환(std::to_string(const T& n)) 개선
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