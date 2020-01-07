
#ifndef _COMMON_H_
#define _COMMON_H_

#include <vector>
#include <sstream>
#include "jTime.h"

/* Multi Platform Support - 향후 계획 */
#ifdef WIN32
#include <windows.h>
#include <direct.h>
#else
#include <unistd.h>
#endif

// Platform
const int PLATFORM_WIN32 = 99;
const int PLATFORM_UNIX = 100;

#ifdef WIN32
const int PLATFORM_TYPE = PLATFORM_WIN32;
#else
const int PLATFORM_TYPE = PLATFORM_UNIX;
#endif

// Global 명령어
const int CMD_CLEAR = 100;
const int CMD_DELAY = 101;

// Global 옵션
#define TRUE 1
#define FALSE 0

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
const int HHMM = 30;
const int YYYY = 40;
const int MM = 50;
const int DD = 60;
const int HOUR = 70;
const int MIN = 80;
const int SEC = 90;
const int USEC = 100;

// 랜덤 이름
const int TYPE_FAMILY_NAME = 10;
const int TYPE_FULL_NAME = 20;

// Global 함수
int Cmd(int cmdSvc, int argv = NULL);

std::string GetToday(const int TYPE);

std::string GetTypeOfFilename(const int Type);

// 파일 존재 파악
int IsFileExist(std::string filename);

// 데이터 파일 Vector 형태로 불러오기
std::vector<std::string> GetLoadName(const int Type, const std::string filename);

// 파일 이름 생성 영역
std::string CreateFileName(std::string subject); // 파일명 생성 Lib

// 파일 추출 서비스 영역
int FileMemoExtract(std::string fileName, std::string Data); // 파일 추출 Lib

// 랜덤 숫자 만들기
int RandBox(const int Type);

// 더블형 비교(IEEE 754 규격)
int CompareDoubleAbsoulte(double x, double y, double absTolerance = (1.0e-8), int ulpsTolerance = 4);

// String To Int
int StringToint(std::string d);

// 타이머 배포
JTime* GetTimer();
std::string FinishTimer(JTime* startTime, JTime* endTime);

// G++의 구버전 호환(std::to_string(const T& n)) 개선
namespace JPatch
{
	template < typename T > std::string to_string(const T& n)
	{
		std::ostringstream stm;

		// Double precision 문제 해결
		try{
			stm << n;
		}
		catch (int e){
			
			stm.precision(::std::numeric_limits<double>::digits10);
			stm.unsetf(::std::ios::dec);
			stm.setf(::std::ios::scientific);
			stm << n;

		}

		return stm.str();
	}
}

#endif