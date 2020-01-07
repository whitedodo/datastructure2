
#ifndef _COMMON_H_
#define _COMMON_H_

#include <vector>
#include <sstream>
#include "jTime.h"

/* Multi Platform Support - ���� ��ȹ */
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

// Global ��ɾ�
const int CMD_CLEAR = 100;
const int CMD_DELAY = 101;

// Global �ɼ�
#define TRUE 1
#define FALSE 0

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
const int HHMM = 30;
const int YYYY = 40;
const int MM = 50;
const int DD = 60;
const int HOUR = 70;
const int MIN = 80;
const int SEC = 90;
const int USEC = 100;

// ���� �̸�
const int TYPE_FAMILY_NAME = 10;
const int TYPE_FULL_NAME = 20;

// Global �Լ�
int Cmd(int cmdSvc, int argv = NULL);

std::string GetToday(const int TYPE);

std::string GetTypeOfFilename(const int Type);

// ���� ���� �ľ�
int IsFileExist(std::string filename);

// ������ ���� Vector ���·� �ҷ�����
std::vector<std::string> GetLoadName(const int Type, const std::string filename);

// ���� �̸� ���� ����
std::string CreateFileName(std::string subject); // ���ϸ� ���� Lib

// ���� ���� ���� ����
int FileMemoExtract(std::string fileName, std::string Data); // ���� ���� Lib

// ���� ���� �����
int RandBox(const int Type);

// ������ ��(IEEE 754 �԰�)
int CompareDoubleAbsoulte(double x, double y, double absTolerance = (1.0e-8), int ulpsTolerance = 4);

// String To Int
int StringToint(std::string d);

// Ÿ�̸� ����
JTime* GetTimer();
std::string FinishTimer(JTime* startTime, JTime* endTime);

// G++�� ������ ȣȯ(std::to_string(const T& n)) ����
namespace JPatch
{
	template < typename T > std::string to_string(const T& n)
	{
		std::ostringstream stm;

		// Double precision ���� �ذ�
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