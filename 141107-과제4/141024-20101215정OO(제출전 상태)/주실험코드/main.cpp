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
		cout << "| �ڷᱸ�� ����                   |" << endl;
		cout << "-----------------------------------" << endl;
		cout << "1�� - Integer" << endl;
		cout << "2�� - Double" << endl;
		cout << "3�� - �簢��" << endl;
		cout << "4�� - String" << endl;
		cout << "5�� - ����" << endl;
		cout << "0�� - ����" << endl;
		cout << "-----------------------------------" << endl;
		cout << "�޴��� �������ּ��� : " << endl;

		cin.sync();
		cin.clear();
		cin >> SELECT;

		// ���� ���� ȣ��
		if (SELECT == EXIT)
			break;

		switch (SELECT)
		{
			case MENU_INTEGER:	// 1�� Integer
				jvar.SetUserType(MANUAL);
				tm.MenuOfInteger(IntOfpArr, &jvar);
				break;

			case MENU_DOUBLE:	// 2�� Double��
				jvar.SetUserType(MANUAL);
				tm.MenuOfDouble(DblOfpArr, &jvar);
				break;

			case MENU_POLYGON:	// 3�� Polygon - Double
				jvar.SetUserType(MANUAL);
				tm.MenuOfPolygon(IntOfpArr, &jvar);
				break;

			case MENU_STRING:	// 4�� String
				jvar.SetUserType(MANUAL);
				tm.MenuOfString(StringOfpArr, &jvar);
				break;

			case MENU_AUTO:
				jvar.SetUserType(AUTO);
				tm.MenuOfAuto(&jvar);
				break;

			default:
				cout << "Error: ��ɾ� ����" << endl;
				Cmd(CMD_DELAY, 1);
				break;
		}

		Cmd(CMD_CLEAR);
	}


}
