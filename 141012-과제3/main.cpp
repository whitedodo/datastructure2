/*
	JLand(Sort) Project(����:���α׷���(7�� ���� - 1����))
	OOOOOOOOOOO��
	�Ҽ� : �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
	�й� : 20101215
	�̸� : ��OO
	�̸��� : rabbit.white@daum.net

	������ : 2014. 10. 8
	���������� : 2014. 10. xx
*/

/* Multi Platform Support */
#ifdef WIN32
	#include <windows.h>
	#include <direct.h>
#else
	#include <unistd.h>
#endif

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include "global.h"
#include "j_model.h"

using namespace std;

void main()
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

}

void Print(const int PJT_Name, const int Option){

	// Subject - PJT �з�
	switch (PJT_Name)
	{
		case GLOBAL_PJT_SYSMAIN:  // SysMain
			
			switch (Option)		   // OPTION
			{
				case GLOBAL_OPTION_TITLE:
					cout << "========================================================" << endl;
					cout << "	WELCOME JProject - Data Structrue" << endl;
					cout << "	By ��OO" << endl;
					cout << "	OOOOOOOOOOOOOOOOOOOOOOO��" << endl;
					cout << "	Business & Computer Science	Engineering" << endl;
					cout << "========================================================" << endl;
					cout << "(1��) integer" << endl;
					cout << "(2��) Double" << endl;
					cout << "(3��) Double(Polygon)" << endl;
					cout << "(4��) String" << endl;
					cout << "(5��) About" << endl;
					cout << "(0��) EXIT" << endl;
					cout << "========================================================" << endl;
					cout << endl;
					cout << "�޴��� �����ϼ���: ";
					break;

				case GLOBAL_OPTION_WAIT:
					cout << "========================================================" << endl;
					cout << "��ø� ��ٷ��ּ���" << endl;
					cout << "========================================================" << endl;
					break;

				default:
					cout << "========================================================" << endl;
					cout << "�������� �ʴ� �޴�" << endl;
					cout << "========================================================" << endl;
					break;

			} // end of switch

			break;	// end of SysMain

		case GLOBAL_PJT_JPROGRAM: // JProgram

			switch (Option)
			{
				case GLOBAL_OPTION_TITLE:
					cout << "========================================================" << endl;
					cout << "Welcome To JApp - Sort Wizard" << endl;
					cout << "Sort Wizard ������� �� 3�ܰ�(String�� ����)�� �����˴ϴ�." << endl;
					cout << "========================================================" << endl;
					cout << "��ſ� �Ϸ� �ǽʽÿ�." << endl;
					cout << " & ** HAPPY BIRTH DAY ** &" << endl;
					cout << "========================================================" << endl;
					cout << "��ø� �о�ðԿ�.";
					cout << endl;
					break;

				case GLOBAL_OPTION_TITLE_ANALYSIS:
					cout << "========================================================" << endl;
					cout << "Welcome To JApp - Sort Wizard - 1 / 3" << endl;
					cout << "�м� ��� ���� �ɼ�" << endl;
					cout << "========================================================" << endl;
					cout << "(1��) �м����" << endl;
					cout << "(2��) �Ϲݸ��" << endl;
					cout << "(0��) EXIT" << endl;
					cout << "========================================================" << endl;
					cout << endl;
					cout << "�޴��� �����ϼ���: ";
					break;

				case GLOBAL_OPTION_TITLE_RAND:
					cout << "========================================================" << endl;
					cout << "Welcome To JApp - Sort Wizard - 2 / 3" << endl;
					cout << "���� ������ ���¸� �����ϼ���." << endl;
					cout << "========================================================" << endl;
					cout << "(1��) Rand_Low" << endl;
					cout << "(2��) Rand_Mid" << endl;
					cout << "(3��) Rand_High" << endl;
					cout << "(0��) EXIT" << endl;
					cout << "========================================================" << endl;
					cout << endl;
					cout << "�޴��� �����ϼ���: ";
					break;

				case GLOBAL_OPTION_TITLE_USERSIZE:
					cout << "========================================================" << endl;
					cout << "Welcome To JApp - Sort Wizard - 3 / 3" << endl;
					cout << "ũ�� ���� : ����� ũ�⸦ �Է��ϼ���." << endl;
					cout << "========================================================" << endl;
					cout << "(������Է� : ���� ���·� 1 ~ (+n) �����)" << endl;
					cout << "(-1��) ��������(���� �Ұ�)" << endl;
					cout << "(0��) EXIT" << endl;
					cout << "========================================================" << endl;
					cout << endl;
					cout << "�޴��� �����ϼ���: ";
					break;

				case GLOBAL_OPTION_TITLE_POLYGON:
					cout << "========================================================" << endl;
					cout << "Welcome To JApp - Polygon" << endl;
					cout << "Criticia ����";
					cout << "========================================================" << endl;
					cout << "(1��) X�� ����" << endl;
					cout << "(2��) Y�� ����" << endl;
					cout << "(3��) ���� ����" << endl;
					cout << "(0��) EXIT" << endl;
					cout << "========================================================" << endl;
					cout << endl;
					cout << "�޴��� �����ϼ���: ";
					break;

				case GLOBAL_OPTION_MENU_NOT_FOUND:
					cout << "========================================================" << endl;
					cout << "�������� �ʴ� �޴�" << endl;
					cout << "========================================================" << endl;
					break;

				default:
					break;

			} // end of switch

			break;  // end of JProgram

		case GLOBAL_PJT_JAPP:

			switch (Option)
			{
				case GLOBAL_OPTION_TITLE:

					cout << "========================================================" << endl;
					cout << "	Sort ����" << endl;
					cout << "������ ���� ��ȣ�� �Է��ϼ���.";
					cout << "========================================================" << endl;
					cout << "(1��) BINARY_INSERT" << endl;
					cout << "(2��) LINK_INSERT(Polygon��忡�� ������)" << endl;
					cout << "(3��) Recursive Quick Sort" << endl;
					cout << "(4��) Recursive Median of Three Quick Sort" << endl;
					cout << "(5��) Non-Recursive Median of Three Quick Sort" << endl;
					cout << "(6��) STD::SORT - Quick Sort" << endl;
					cout << "(7��) Recursive Merge Sort" << endl;
					cout << "(8��) Non-Recursive Merge Sort" << endl;
					cout << "(9��) Natural Merge Sort" << endl;
					cout << "(10��) Heap Sort" << endl;
					cout << "(11��) Bubble Sort" << endl;
					cout << "(12��) Selection Sort" << endl;
					cout << "(0��) EXIT" << endl;
					cout << "========================================================" << endl;
					cout << endl;
					cout << "�޴��� �����ϼ���: ";

					break;

				default:
					cout << "========================================================" << endl;
					cout << "�������� �ʴ� �޴�" << endl;
					cout << "========================================================" << endl;
					break;
			}

			break; // end of JApp

		case GLOBAL_PJT_POLYGON:  // Polygon

			switch (Option)		  // OPTION
			{
				case GLOBAL_OPTION_TITLE:
				
					cout << "========================================================" << endl;
					cout << "Build - 2014/10/10" << endl;
					cout << "With Rabbit.white(rabbit.white@daum.net)" << endl;
					cout << "Welcome To Polygon LAND" << endl;
					cout << "========================================================" << endl;
					break;

				case GLOBAL_OPTION_WAIT:
					cout << "========================================================" << endl;
					cout << "��ø� ��ٷ��ּ���" << endl;
					cout << "========================================================" << endl;
					break;

				case GLOBAL_OPTION_MENU_NOT_FOUND:
					cout << "========================================================" << endl;
					cout << "�������� �ʴ� �޴�" << endl;
					cout << "========================================================" << endl;
					break;

				default:
					break;

			} // end of switch

			break; // End of Polygon

			

		default:
			break;
	}

}