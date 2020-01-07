/*
	Subject - JLand(Sort) Project / global.h
	Created Date - 2014. 10. 8
	Description - Global 영역 / 프로젝트 전체 대상 기능 (CMD, RandBox)
	[Version]
*/

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
const int MENU_ABOUT = 5;


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


// 명령어 함수
std::string JCurPwd(){

	std::string curDir;

	char StrBuffer[_MAX_PATH] = { 0, };
	char *pstrBuffer = NULL;

	// 플랫폼 확인
	switch (PLATFORM_TYPE){

		// Win32
	case PLATFORM_WIN32:
		#ifdef WIN32
			pstrBuffer = _getcwd(StrBuffer, _MAX_PATH);
		#endif
		break; // End of Win32

		// Unix
	case PLATFORM_UNIX:
	#ifdef WIN32
	#else
		pstrBuffer = getcwd(StrBuffer, _MAX_PATH);
	#endif

		break; // End of Unix
	} // End of Switch

	curDir.append(pstrBuffer);

	return curDir;

}


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

/// RandBOX - James
int RandBox(const int Type){

	int random_num = NULL;

	switch (Type)
	{
	case TYPE_RAND_LOW:
		random_num = (rand() % (RAND_LOW_END - RAND_LOW_START)) + RAND_LOW_START;
		break;

	case TYPE_RAND_MID:
		random_num = (rand() % (RAND_MID_END - RAND_MID_START)) + RAND_MID_START;
		break;

	case TYPE_RAND_HIGH:
		random_num = (rand() % (RAND_HIGH_END - RAND_HIGH_START)) + RAND_HIGH_START;
		break;

	default:
		random_num = rand();
		break;

	}

	return random_num;

}

// End of RandBOX - James

/// std::string GetToday(const int TYPE)
std::string GetToday(const int TYPE)
{
	// 오늘 날짜 가져오기
	time_t timer;
	struct tm t;
	std::string RESULT;

	timer = time(NULL);
	localtime_s(&t, &timer);

	switch (TYPE)
	{
		case YYYYMMDD:
			RESULT.append(std::to_string(t.tm_year + 1900));
			RESULT.append(std::to_string(t.tm_mon + 1));
			RESULT.append(std::to_string(t.tm_mday));
			break;

		case HHMMSEC:
			RESULT.append(std::to_string(t.tm_hour));
			RESULT.append(std::to_string(t.tm_min));
			RESULT.append(std::to_string(t.tm_sec));
			break;

		default:
			break;
	}

	return RESULT;

}
// End of GetToday

void OutFileExtract(std::string Data){

	std::ofstream fout;
	std::string filename;
	
	// 파일명
	filename.append(GetToday(YYYYMMDD));
	filename.append("_report_");
	filename.append(GetToday(HHMMSEC));
	filename.append(".txt");

	// 파일 열기
	fout.open(filename.c_str());
	fout << Data;
	fout.close();

	std::cout << filename << "으로 정상출력되었습니다." << std::endl;

}

std::vector<std::string> GetName(const int Type){

	std::vector<std::string> names;
	std::ifstream file;

	char strName[100];
	std::string fileName;

	fileName.append(JCurPwd());
#ifdef WIN32
	fileName.append("\\");
#else
	fileName.append("/");
#endif

	if (Type == TYPE_FAMILY_NAME)
		fileName.append("familyname.txt");

	if (Type == TYPE_FULL_NAME)
		fileName.append("fullname.txt");

	file.open(fileName.c_str());

	// 초기 배열
	names.resize(1);

	while (!file.eof())
	{
		file.getline(strName, 100);
		names.push_back(strName);
	}

	file.close();

	return names;
}

#endif