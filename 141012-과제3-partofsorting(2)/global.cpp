#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <time.h>
#include "global.h"

using namespace std;

// 명령어 함수
std::string JCurPwd(){

	std::string curDir;

	char StrBuffer[MAX_PATH] = { 0, };
	char *pstrBuffer = J_NULL;

	// 플랫폼 확인
	switch (PLATFORM_TYPE){

		// Win32
		case PLATFORM_WIN32:
			#ifdef WIN32
			pstrBuffer = _getcwd(StrBuffer, MAX_PATH);
			#endif
		break; // End of Win32

		// Unix
		case PLATFORM_UNIX:
			#ifdef WIN32
			#else
				pstrBuffer = getcwd(StrBuffer, MAX_PATH);
			#endif

			break; // End of Unix
	} // End of Switch

	curDir.append(pstrBuffer);

	return curDir;

}


// 명령어 함수
int Cmd(int cmdSvc, int argv){

	int Result = TRUE;

	// 플랫폼 확인
	switch (PLATFORM_TYPE){

		// Win32
	case PLATFORM_WIN32:

		switch (cmdSvc)
		{
		case CMD_CLEAR:
			#ifdef WIN32
				system("cls");
			#endif
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
			#ifdef WIN32
			#else
				system("clear");
			#endif
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

	int random_num = J_NULL;

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
	std::string RESULT;

	timer = time(NULL);

	#ifdef WIN32
		struct tm t;
		localtime_s(&t, &timer);
		switch (TYPE)
		{
			case YYYYMMDD:
				RESULT.append(JPatch::to_string(t.tm_year + 1900));
				RESULT.append(JPatch::to_string(t.tm_mon + 1));
				RESULT.append(JPatch::to_string(t.tm_mday));
				break;

			case HHMMSEC:
				RESULT.append(JPatch::to_string(t.tm_hour));
				RESULT.append(JPatch::to_string(t.tm_min));
				RESULT.append(JPatch::to_string(t.tm_sec));
				break;

			default:
				break;
		}
	
	#else
		struct tm *t;
		t = localtime(&timer);
		switch (TYPE)
		{
			case YYYYMMDD:
				RESULT.append(JPatch::to_string(t->tm_year + 1900));
				RESULT.append(JPatch::to_string(t->tm_mon + 1));
				RESULT.append(JPatch::to_string(t->tm_mday));
				break;

			case HHMMSEC:
				RESULT.append(JPatch::to_string(t->tm_hour));
				RESULT.append(JPatch::to_string(t->tm_min));
				RESULT.append(JPatch::to_string(t->tm_sec));
				break;

			default:
				break;
		}
	#endif


	return RESULT;

}
// End of GetToday

void OutFileExtract(std::string Data){

	char strName[100];
	std::ofstream fout;
	std::string fileName;

	fileName.append(JCurPwd());

	// Path (WIN / UNIX 체계로 변경)
	#ifdef WIN32
		fileName.append("\\");
	#else
		fileName.append("/");
	#endif

	// 파일명
	fileName.append(GetToday(YYYYMMDD));
	fileName.append("_report_");
	fileName.append(GetToday(HHMMSEC));
	fileName.append(".txt");

	// 파일 열기
	fout.open(fileName.c_str());
	fout << Data;
	fout.close();

	std::cout << fileName << "으로 정상출력되었습니다." << std::endl;

}

std::vector<std::string> GetName(const int Type){

	std::vector<std::string> names;
	std::ifstream file;

	char strName[100];
	std::string fileName;

	fileName.append(JCurPwd());

	// Path (WIN / UNIX 체계로 변경)
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
