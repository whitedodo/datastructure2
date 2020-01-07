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
		cout << "| 어떤 값을 선택하시겠습니까?          |" << endl;
		cout << "----------------------------------------" << endl;
		cout << "1. Increase" << endl;
		cout << "2. Decrease" << endl;
		cout << "3. Random" << endl;
		cout << "0. 메인으로 가기" << endl;
		cout << "----------------------------------------" << endl;
		cout << "메뉴를 선택해주세요 :";

		cin.sync();
		cin.clear();
		cin >> SELECT;

		// 탈출 조건
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
				cout << "잘못된 명령" << endl;
				Cmd(CMD_DELAY, 3);
				break;

		} // end of switch

		// 탈출 조건(정상)
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
		cout << "| 할당할 크기를 정하세요               |" << endl;
		cout << "----------------------------------------" << endl;
		cout << "(음수 불가능)" << endl;
		cout << "0. 메인으로 가기" << endl;
		cout << "----------------------------------------" << endl;
		cout << "메뉴를 선택해주세요 :";

		cin.sync();
		cin.clear();
		cin >> SELECT;

		// 탈출 조건
		if (SELECT == WIZARD_EXIT)
			break;

		if (SELECT < 0)
		{
			cout << "음수 불가" << endl;
			Cmd(CMD_DELAY, 3);
		} // end of if

		if (SELECT > 0)
			isexited = true;

		// 탈출 조건(정상)
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
		cout << "| 정렬 기능을 선택하세요               |" << endl;
		cout << "----------------------------------------" << endl;
		cout << "1. Binary Insert Sort(이원삽입정렬)" << endl;
		cout << "2. Linked Insert Sort(연결삽입정렬)" << endl;
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
		cout << "메뉴를 선택해주세요 :";

		cin.sync();
		cin.clear();
		cin >> SELECT;

		// 탈출 조건
		if (SELECT == WIZARD_EXIT)
			break;

		if (WIZARD_SORT_MIN <= SELECT && WIZARD_SORT_MAX >= SELECT)
			isexited = true;

		// 탈출 조건(정상)
		if (isexited == true)
			break;

	} // end of while

	return SELECT;

}

int Wizard::ChooseOfQuestion(){

	int SELECT;

	while (1)
	{
		std::cout << "저장(1번), 메뉴(0번)?";

		std::cin.clear();
		std::cin.sync();
		std::cin >> SELECT;

		// 탈출 조건
		if (SELECT == WIZARD_EXIT)
			break;

		// 저장 / 잘못된 명령어
		if (SELECT == WIZARD_SAVE)
			break;
		else{

			std::cout << "잘못된 명령어" << std::endl;
			Cmd(CMD_DELAY, 3);

		} // end of if

	}

	return SELECT;

}