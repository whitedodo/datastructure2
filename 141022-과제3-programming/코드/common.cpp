#include <iostream>
#include <string>
#include <fstream>
#include <sys/timeb.h>
#include <time.h>
#include "common.h"

using namespace std;

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

// 명령어 함수
std::string JCurPwd(){

	std::string curDir;

	char StrBuffer[MAX_PATH] = { 0, };
	char *pstrBuffer = NULL;

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

JTime* GetTimer()
{
	JTime* pTime = new JTime();

	 pTime->year = StringToint(GetToday(YYYY));
	 pTime->month = StringToint(GetToday(MM));
	 pTime->day = StringToint(GetToday(DD));
	 pTime->hour = StringToint(GetToday(HOUR));
	 pTime->miniute = StringToint(GetToday(MIN));
	 pTime->sec = StringToint(GetToday(SEC));
	 pTime->usec = StringToint(GetToday(USEC));

	 return pTime;
}

/// std::string GetToday(const int TYPE)
std::string GetToday(const int TYPE)
{
	// 오늘 날짜 가져오기
	struct _timeb timebuffer;
	std::string RESULT;
	time_t timer = time(NULL);

	_ftime64_s(&timebuffer);

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

		case HHMM:
			if (t.tm_hour > 12)
				RESULT.append("pm ");
			else
				RESULT.append("am ");

			RESULT.append(JPatch::to_string(t.tm_hour));
			RESULT.append(" ");
			RESULT.append(JPatch::to_string(t.tm_min));
			break;

		case YYYY:
			RESULT.append(JPatch::to_string(t.tm_year + 1900));
			break;
			
		case MM:
			RESULT.append(JPatch::to_string(t.tm_mon + 1));
			break;

		case DD:
			RESULT.append(JPatch::to_string(t.tm_mday));
			break;

		case HOUR:
			RESULT.append(JPatch::to_string(t.tm_hour));
			break;

		case MIN:
			RESULT.append(JPatch::to_string(t.tm_min));
			break;

		case SEC:
			RESULT.append(JPatch::to_string(t.tm_sec));
			break;

		case USEC:
			RESULT.append(JPatch::to_string(timebuffer.millitm));
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

		case HHMM:
			if (t.tm_hour > 12)
				RESULT.append("pm ");
			else
				RESULT.append("am ");

			RESULT.append(JPatch::to_string(t->tm_hour));
			RESULT.append(" ");
			RESULT.append(JPatch::to_string(t->tm_min));


		case YYYY:
			RESULT.append(JPatch::to_string(t->tm_year + 1900));
			break;

		case MM:
			RESULT.append(JPatch::to_string(t->tm_mon + 1));
			break;

		case DD:
			RESULT.append(JPatch::to_string(t->tm_mday));
			break;

		case HOUR:
			RESULT.append(JPatch::to_string(t->tm_hour));
			break;

		case MIN:
			RESULT.append(JPatch::to_string(t->tm_min));
			break;

		case SEC:
			RESULT.append(JPatch::to_string(t->tm_sec));
			break;

		case USEC:
			RESULT.append(JPatch::to_string(timebuffer.millitm));
			break;

		default:
			break;
	}
#endif


	return RESULT;

}
// End of GetToday


std::string FinishTimer(JTime* startTime, JTime* endTime){

	std::string timerMemo;
	JTime* estTime = new JTime();

	// 경과 시간
	estTime->year = endTime->year - startTime->year;
	estTime->month = endTime->month - startTime->month;
	estTime->day = endTime->day - startTime->day;

	estTime->hour = abs(endTime->hour - startTime->hour);
	estTime->miniute = abs(endTime->miniute - startTime->miniute);
	estTime->sec = abs(endTime->sec - startTime->sec);
	estTime->usec = abs(endTime->usec - startTime->usec);
	
	// 각 유형 별 수집 결과 정리
	timerMemo.append("실험시작시간:");
	timerMemo.append(JPatch::to_string(startTime->year));
	timerMemo.append(JPatch::to_string(startTime->month));
	timerMemo.append(JPatch::to_string(startTime->day));
	timerMemo.append(" ");
	timerMemo.append(JPatch::to_string(startTime->hour));
	timerMemo.append(":");
	timerMemo.append(JPatch::to_string(startTime->miniute));
	timerMemo.append(":");
	timerMemo.append(JPatch::to_string(startTime->sec));
	timerMemo.append(".");
	timerMemo.append(JPatch::to_string(startTime->usec));

	timerMemo.append("실험종료시간:");
	timerMemo.append(JPatch::to_string(endTime->year));
	timerMemo.append(JPatch::to_string(endTime->month));
	timerMemo.append(JPatch::to_string(endTime->day));
	timerMemo.append(" ");
	timerMemo.append(JPatch::to_string(endTime->hour));
	timerMemo.append(":");
	timerMemo.append(JPatch::to_string(endTime->miniute));
	timerMemo.append(":");
	timerMemo.append(JPatch::to_string(endTime->sec));
	timerMemo.append(".");
	timerMemo.append(JPatch::to_string(endTime->usec));

	// 한달 이내만 측정됨.
	timerMemo.append("경과시간:");
	int sum = estTime->hour + (estTime->day * 24 * 3600) + estTime->sec;

	timerMemo.append(JPatch::to_string(sum));
	timerMemo.append(".");
	timerMemo.append(JPatch::to_string(estTime->usec));

	return timerMemo;
}

/// CreateFileName (Subject를 지정할 수 있음)
std::string CreateFileName(std::string subject){

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
	fileName.append("_");
	fileName.append(subject);
	fileName.append("_");
	fileName.append(GetToday(HHMMSEC));
	fileName.append(".txt");

	return fileName;
}
// end of filename

int FileMemoExtract(std::string fileName, std::string Data){

	std::ofstream fout;

	// 파일 열기
	fout.open(fileName.c_str());
	
	if (fout.fail())
	{
		fout.close();
		return 0;
	}
	else
	{
		fout << Data;
		fout.close();
		return TRUE;
	}
}


int IsFileExist(std::string filename){


	std::ifstream file;
	file.open(filename.c_str());

	if (file.fail())
	{
		file.close();
		return false;
	}
	else{
		file.close();
		return true;
	}
}

std::string GetTypeOfFilename(const int Type)
{
	std::string fileName;

	// JCurPwd는 현재 디렉토리 생성
	fileName.append(JCurPwd());

	// Path (WIN / UNIX 체계로 변경)
	#ifdef WIN32
		fileName.append("\\");
	#else
		fileName.append("/");
	#endif

	// 유형에 따라 파일 불러오기(유형 2가지)
	if (Type == TYPE_FAMILY_NAME)
		fileName.append("familyname.txt");

	if (Type == TYPE_FULL_NAME)
		fileName.append("fullname.txt");

	return fileName;
}

std::vector<std::string> GetLoadName(const int Type, const std::string Getfilename){

	std::vector<std::string> names;
	std::ifstream file;
	char strName[100];

	// 파일 불러오기
	file.open(GetTypeOfFilename(Type).c_str());

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

// Double 비교
int CompareDoubleAbsoulte(double x, double y, double absTolerance, int ulpsTolerance)
{
	double diff = x - y;
	if (fabs(diff) <= absTolerance)
		return 0;

	__int64 nx = *((__int64*)&x);
	__int64 ny = *((__int64*)&y);

	if ((nx & 0x8000000000000000) != (ny & 0x8000000000000000))
		return (diff > 0) ? 1 : -1;

	__int64 ulpsDiff = nx - ny;
	if ((ulpsDiff >= 0 ? ulpsDiff : -ulpsDiff) <= ulpsTolerance)
		return 0;

	return (diff > 0) ? 1 : -1;

}

int StringToint(std::string d)
{
	return atoi(d.c_str());
}