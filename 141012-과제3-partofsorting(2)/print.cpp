#include <iostream>
#include "global.h"

using namespace std;

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
			cout << "	By Rabbit.white(��OO)" << endl;
			cout << "	OOOOOOOOOOOOOOOOOOOOO��" << endl;
			cout << "	Business & Computer Science	Engineering" << endl;
			cout << "	[���� �޴�] / 2014. 11. 09" << endl;
			cout << "========================================================" << endl;
			cout << "(1��) integer" << endl;
			cout << "(2��) Double" << endl;
			cout << "(3��) Double(Polygon)" << endl;
			cout << "(4��) String" << endl;
			cout << "(5��) Linked Structure(���ᱸ��)" << endl;
			cout << "(6��) About" << endl;
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
			cout << "Sort Wizard ������� �� 3�ܰ�� �����˴ϴ�." << endl;
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

		case GLOBAL_OPTION_TITLE_LINKED:
			cout << "========================================================" << endl;
			cout << "Welcome To Linked List - Insert Sort" << endl;
			cout << "�ڷ��� ����";
			cout << "========================================================" << endl;
			cout << "(1��) INTEGER" << endl;
			cout << "(2��) DOUBLE" << endl;
			cout << "(3��) STRING" << endl;
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
			cout << "(2��) Recursive Quick Sort" << endl;
			cout << "(3��) Recursive Median of Three Quick Sort" << endl;
			cout << "(4��) Non-Recursive Median of Three Quick Sort" << endl;
			cout << "(5��) STD::SORT - Quick Sort" << endl;
			cout << "(6��) Recursive Merge Sort" << endl;
			cout << "(7��) Non-Recursive Merge Sort" << endl;
			cout << "(8��) Natural Merge Sort" << endl;
			cout << "(9��) Heap Sort" << endl;
			cout << "(10��) Bubble Sort" << endl;
			cout << "(11��) Selection Sort" << endl;
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
			cout << "Build - 2014/11/9" << endl;
			cout << "With Rabbit.white(rabbit.white@daum.net)" << endl;
			cout << "Welcome To Polygon LAND" << endl;
			cout << "OOOOOOOOOOOOOOOOOO��" << endl;
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