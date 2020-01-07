#ifndef _WIZARD_H_
#define _WIZARD_H_

// 자료형 구분
const int WIZARD_INCREASE = 1;
const int WIZARD_DECREASE = 2;
const int WIZARD_RANDOM = 3;
const int WIZARD_VALUETYPE_MIN = 1;
const int WIZARD_VALUETYPE_MAX = 3;


// 메뉴(정렬 조건)
const int WIZARD_EXIT = 0;

const int WIZARD_BINARY_SORT = 1;
const int WIZARD_LINKED_SORT = 2;
const int WIZARD_QUICK_R = 3;
const int WIZARD_QUICK_R_MEDIAN = 4;
const int WIZARD_QUICK_N_MEDIAN = 5;
const int WIZARD_QUICK_STDSORT = 6;
const int WIZARD_MERGE_R = 7;
const int WIZARD_MERGE_NON = 8;
const int WIZARD_MERGE_NAT = 9;
const int WIZARD_HEAPSORT = 10;
const int WIZARD_SELECTION = 11;
const int WIZARD_BUBBLE = 12;

const int WIZARD_SORT_MIN = 0;
const int WIZARD_SORT_MAX = 12;

const int WIZARD_SAVE = 1;

class JUserVar;

class Wizard{
	
public:
	int TManagerWizard(JUserVar* jvar);
	int ChooseOfQuestion();

private:
	int ChooseOfValue();
	int ChooseOfSize();
	int ChooseOfSortType();
};


#endif