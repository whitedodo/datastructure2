/*
	JLand(Sort) Project(����:���α׷���(7�� ���� - 1����))
	����� : OOOOOOOOOOOOOOO��
	�Ҽ� : �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
	�й� : 20101215
	�̸� : ��OO
	�̸��� : rabbit.white@daum.net

*/


#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include "j_model.h"

using namespace std;

/*
	***************************************************
	View ����
	---------------------------------------------------
*/

int main()
{
	JLand JProgram;

	while (1)
	{
		int SELECT;
		Print(GLOBAL_PJT_SYSMAIN, GLOBAL_OPTION_TITLE); // Ÿ��Ʋ �ø���
		
		cin.clear();
		cin.sync();
		cin >> SELECT;

		if (SELECT == EXIT)
			break;

		switch (SELECT) // �޴�
		{
			case MENU_INTEGER:								// 1�� - INTEGER �޴�
				JProgram.Run(MENU_INTEGER);
				break;

			case MENU_DOUBLE:								// 2�� - DOUBLE �޴�
				JProgram.Run(MENU_DOUBLE);
				break;

			case MENU_DOUBLE_POLYGON:						// 3�� - DOUBLE_POLYGON �޴�
				JProgram.Run(MENU_DOUBLE_POLYGON);
				break;

			case MENU_STRING:								// 4�� - STRING �޴�
				JProgram.Run(MENU_STRING);
				break;

			case MENU_LINKED_INSERT:
				JProgram.Run(MENU_LINKED_INSERT);
				break;

			case MENU_ABOUT:								// 5�� - About �޴�
				JProgram.About();
				break;
				
			default:									    // ������ �޴�
				Print(GLOBAL_PJT_SYSMAIN, GLOBAL_OPTION_MENU_NOT_FOUND);
				Cmd(CMD_DELAY, 1);
				Cmd(CMD_CLEAR);
				break;
		}

		Cmd(CMD_CLEAR);										// �ʱ�ȭ
		std::cout << endl;

	}

	return 0;

}
