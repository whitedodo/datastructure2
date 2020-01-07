#include <iostream>
#include "jUserVariable.h"
#include "wizard.h"
#include "common.h"

using namespace std;

int Wizard::TManagerWizard(JUserVar* jvar){

	jvar->SetValueType(ChooseOfValue());
	
	if (jvar->GetValueType() == FALSE)
		return FALSE;

	jvar->SetUserSize(ChooseOfSize());

	if (jvar->GetUserSize() == FALSE)
		return FALSE;

	jvar->SetSortType(ChooseOfSortType());

	if (jvar->GetSortType() == FALSE)
		return FALSE;

	return TRUE;
}

int Wizard::ChooseOfValue(){

	bool isexited = false;
	int SELECT;

	while (1)
	{
		Cmd(CMD_CLEAR);

		cout << "----------------------------------------" << endl;
		cout << "| � ���� �����Ͻðڽ��ϱ�?          |" << endl;
		cout << "----------------------------------------" << endl;
		cout << "1. Increase" << endl;
		cout << "2. Decrease" << endl;
		cout << "3. Random" << endl;
		cout << "0. �������� ����" << endl;
		cout << "----------------------------------------" << endl;
		cout << "�޴��� �������ּ��� :";

		cin.sync();
		cin.clear();
		cin >> SELECT;

		// Ż�� ����
		if (SELECT == WIZARD_EXIT)
			break;

		switch (SELECT)
		{
			case WIZARD_INCREASE:
				isexited = true;
				break;

			case WIZARD_DECREASE:
				isexited = true;
				break;

			case WIZARD_RANDOM:
				isexited = true;
				break;

			default:
				cout << "�߸��� ���" << endl;
				Cmd(CMD_DELAY, 3);
				break;

		} // end of switch

		// Ż�� ����(����)
		if (isexited == true)
			break;

	} // end of while

	return SELECT;

}

int Wizard::ChooseOfSize(){

	bool isexited = false;
	int SELECT;

	while (1)
	{
		Cmd(CMD_CLEAR);

		cout << "----------------------------------------" << endl;
		cout << "| �Ҵ��� ũ�⸦ ���ϼ���               |" << endl;
		cout << "----------------------------------------" << endl;
		cout << "(���� �Ұ���)" << endl;
		cout << "0. �������� ����" << endl;
		cout << "----------------------------------------" << endl;
		cout << "�޴��� �������ּ��� :";

		cin.sync();
		cin.clear();
		cin >> SELECT;

		// Ż�� ����
		if (SELECT == WIZARD_EXIT)
			break;

		if (SELECT < 0)
		{
			cout << "���� �Ұ�" << endl;
			Cmd(CMD_DELAY, 3);
		} // end of if

		if (SELECT > 0)
			isexited = true;

		// Ż�� ����(����)
		if (isexited == true)
			break;

	} // end of while

	return SELECT;

}


int Wizard::ChooseOfSortType(){


	bool isexited = false;
	int SELECT;

	while (1)
	{
		Cmd(CMD_CLEAR);

		cout << "----------------------------------------" << endl;
		cout << "| ���� ����� �����ϼ���               |" << endl;
		cout << "----------------------------------------" << endl;
		cout << "1. Binary Insert Sort(�̿���������)" << endl;
		cout << "2. Linked Insert Sort(�����������)" << endl;
		cout << "3. QuickSort(Recursive)" << endl;
		cout << "4. Median QuickSort(Recursive)" << endl;
		cout << "5. Median QuickSort(Non-Recursive)" << endl;
		cout << "6. std::Sort QuickSort" << endl;
		cout << "7. Merge - Recursive" << endl;
		cout << "8. Merge - Non-Recursive" << endl;
		cout << "9. Natural Merge" << endl;
		cout << "10. Heap sort" << endl;
		cout << "11. Selection" << endl;
		cout << "12. Bubble" << endl;
		cout << "----------------------------------------" << endl;
		cout << "�޴��� �������ּ��� :";

		cin.sync();
		cin.clear();
		cin >> SELECT;

		// Ż�� ����
		if (SELECT == WIZARD_EXIT)
			break;

		if (WIZARD_SORT_MIN <= SELECT && WIZARD_SORT_MAX >= SELECT)
			isexited = true;

		// Ż�� ����(����)
		if (isexited == true)
			break;

	} // end of while

	return SELECT;

}

int Wizard::ChooseOfQuestion(){

	int SELECT;

	while (1)
	{
		std::cout << "����(1��), �޴�(0��)?";

		std::cin.clear();
		std::cin.sync();
		std::cin >> SELECT;

		// Ż�� ����
		if (SELECT == WIZARD_EXIT)
			break;

		// ���� / �߸��� ��ɾ�
		if (SELECT == WIZARD_SAVE)
			break;
		else{

			std::cout << "�߸��� ��ɾ�" << std::endl;
			Cmd(CMD_DELAY, 3);

		} // end of if

	}

	return SELECT;

}