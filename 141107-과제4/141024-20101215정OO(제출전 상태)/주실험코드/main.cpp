#include <iostream>
#include <string>
#include "common.h"
#include "TManager.h"
#include "jUserVariable.h"

using namespace std;

const int EXIT = 0;


int main(int argc, char* argv[])
{
	TaskManager tm;
	JUserVar jvar;

	double* DblOfpArr = NULL;
	int* IntOfpArr = NULL;
	std::string* StringOfpArr = NULL;

	int SELECT;

	while (1)
	{
		cout << "-----------------------------------" << endl;
		cout << "| 자료구조 과제                   |" << endl;
		cout << "-----------------------------------" << endl;
		cout << "1번 - Integer" << endl;
		cout << "2번 - Double" << endl;
		cout << "3번 - 사각형" << endl;
		cout << "4번 - String" << endl;
		cout << "5번 - 무인" << endl;
		cout << "0번 - 종료" << endl;
		cout << "-----------------------------------" << endl;
		cout << "메뉴를 선택해주세요 : " << endl;

		cin.sync();
		cin.clear();
		cin >> SELECT;

		// 종료 사항 호출
		if (SELECT == EXIT)
			break;

		switch (SELECT)
		{
			case MENU_INTEGER:	// 1번 Integer
				jvar.SetUserType(MANUAL);
				tm.MenuOfInteger(IntOfpArr, &jvar);
				break;

			case MENU_DOUBLE:	// 2번 Double형
				jvar.SetUserType(MANUAL);
				tm.MenuOfDouble(DblOfpArr, &jvar);
				break;

			case MENU_POLYGON:	// 3번 Polygon - Double
				jvar.SetUserType(MANUAL);
				tm.MenuOfPolygon(IntOfpArr, &jvar);
				break;

			case MENU_STRING:	// 4번 String
				jvar.SetUserType(MANUAL);
				tm.MenuOfString(StringOfpArr, &jvar);
				break;

			case MENU_AUTO:
				jvar.SetUserType(AUTO);
				tm.MenuOfAuto(&jvar);
				break;

			default:
				cout << "Error: 명령어 오류" << endl;
				Cmd(CMD_DELAY, 1);
				break;
		}

		Cmd(CMD_CLEAR);
	}


}
