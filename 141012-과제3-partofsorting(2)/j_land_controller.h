/*
	Subject - JLand(Sort) Project / j_land_controller.h
	Director - ....... Jeong / OOOOOOOOOOOOOOOOO�� / Business & Computer Science
	Created Date - 2014. 10. 8
	Description - JLand / JPolygon Controller
	[Version]
*/

#ifndef _J_LAND_CONTROLLER_H_
#define _J_LAND_CONTROLLER_H_

#include "j_model.h"

template <typename T>
JApp<T>::JApp(){

}

template <typename T>
JApp<T>::~JApp(){
	
}

// Specialize Float Linked_Create ����
template <>
LinkedList<std::string>* JApp<std::string>::Linked_Create(const int n, LinkedList<std::string>* pList, const int SetRandType){

	std::string RandomName;
	std::vector<std::string> FamilyNames = GetName(TYPE_FAMILY_NAME);
	std::vector<std::string> FullNames = GetName(TYPE_FULL_NAME);

	// �ʱ�ȭ
	srand((unsigned int)time(J_NULL)); // Seed �� ���

	for (int i = 0; i < n; i++){

		int FamilyNum = (rand() % (FamilyNames.size() - 1)) + 0;
		int FullNum = (rand() % (FullNames.size() - 1)) + 0;

		RandomName.clear();
		RandomName.append(FamilyNames[FamilyNum]);
		RandomName.append(FullNames[FullNum]);

		pList->Insert(RandomName);
	}

	return pList;
}
// End of float Linked_Create

// Specialize Float Linked_Create ����
template <>
LinkedList<float>* JApp<float>::Linked_Create(const int n, LinkedList<float>* pList, const int SetRandType){

	// �ʱ�ȭ
	srand((unsigned int)time(J_NULL)); // Seed �� ���

	for (int i = 0; i < n; i++){

		float Num = pow((float)RandBox(TYPE_RAND_LOW), -1); // float Random
		float Result = RandBox(SetRandType) * (float)Num;
		pList->Insert(Result);
	}

	return pList;
}
// End of float Linked_Create

/// Specialize Double Linked_Create ����
template <>
LinkedList<double>* JApp<double>::Linked_Create(const int n, LinkedList<double>* pList, const int SetRandType){

	// �ʱ�ȭ
	srand((unsigned int)time(J_NULL)); // Seed �� ���

	for (int i = 0; i < n; i++){

		double Num = pow((double)RandBox(TYPE_RAND_LOW), -1); // float Random
		double Result = RandBox(SetRandType) * (double)Num;
		pList->Insert(Result);
	}

	return pList;
}

/// Linked_Create ����
template <typename T>
LinkedList<T>* JApp<T>::Linked_Create(const int n, LinkedList<T>* pList, const int SetRandType){

	// �ʱ�ȭ
	srand((unsigned int)time(J_NULL)); // Seed �� ���

	for (int i = 0; i < n; i++)
		pList->Insert(RandBox(SetRandType));

	return pList;
}
// End of Linked_Create

template <typename T>
void JApp<T>::Result_Print(LinkedList<T>* ptrList, int Option){

	Node<T>* ptr = ptrList->GetFirstNode();

	switch (Option)
	{
		case JAPP_PRINT_SORTED:
			Print_Report_Data.append("������ ����\n");
			break;

		case JAPP_PRINT_UNSORTED:
			Print_Report_Data.append("������ ����\n");
			break;

		default:
			break;
	}

	while (!ptr == J_NULL)
	{
		Print_Report_Data.append("ptr[");
		Print_Report_Data.append(JPatch::to_string(&ptr));
		Print_Report_Data.append("]");
		Print_Report_Data.append(" = ");
		Print_Report_Data.append(JPatch::to_string(ptr->Data));
		Print_Report_Data.append("\n");

		ptr = ptr->next;
	}

}


/// Specialize (std::string)General_Create
template <>
std::string* JApp<std::string>::General_Create(const int n, const int SetRandType)
{
	std::string RandomName;
	std::vector<std::string> FamilyNames = GetName(TYPE_FAMILY_NAME);
	std::vector<std::string> FullNames = GetName(TYPE_FULL_NAME);

	// �ʱ�ȭ
	srand((unsigned int)time(J_NULL)); // Seed �� ���
	// ����
	std::string* Arr = new std::string[n + 1];

	for (int i = 0; i < n; i++){

		int FamilyNum = (rand() % (FamilyNames.size() - 1)) + 0;
		int FullNum = (rand() % (FullNames.size() - 1)) + 0;

		RandomName.clear();
		RandomName.append(FamilyNames[FamilyNum]);
		RandomName.append(FullNames[FullNum]);
		
		Arr[i] = RandomName;

	}

	return Arr;
}
// End of Specialize (float)General_Create


/// Specialize (float)General_Create
template <>
float* JApp<float>::General_Create(const int n, const int SetRandType)
{
	// �ʱ�ȭ
	srand((unsigned int)time(J_NULL)); // Seed �� ���
	// ����
	float* Arr = new float[n + 1];

	for (int i = 0; i < n; i++){

		float Num = pow((float)RandBox(TYPE_RAND_LOW), -1); // float Random
		float Result = RandBox(SetRandType) * (float)Num;
		Arr[i] = Result;
	}

	return Arr;
}
// End of Specialize (float)General_Create

/// Specialize (double)General_Create
template <>
double* JApp<double>::General_Create(const int n, const int SetRandType)
{
	// �ʱ�ȭ
	srand((unsigned int)time(J_NULL)); // Seed �� ���
	// ����
	double* Arr = new double[n + 1];

	for (int i = 0; i < n; i++){
		
		double Num = pow((double)RandBox(TYPE_RAND_LOW), -1); // float Random
		double Result = RandBox(SetRandType) * (double)Num;
		Arr[i] = Result;
	}

	return Arr;
}
// End of Specialize (double)General_Create

template <typename T>
T* JApp<T>::General_Create(const int n, const int SetRandType){

	// �ʱ�ȭ
	srand((unsigned int)time(J_NULL)); // Seed �� ���
	// ����
	T* Arr = new T[n + 1];

	for (int i = 0; i < n; i++){
		Arr[i] = RandBox(SetRandType);
	}

	return Arr;
}

template <typename T>
void JApp<T>::General_Sort(T* Data, const int n, const int Analysis){
	
	// ���� �۾�
	Sort_Run(JAPP_NORMAL, Data, 0, n - 1, Analysis);

}


template <>
void JApp<std::string>::General_Print(std::string* Data, const int n){

	int SELECT;

	std::cout << GetPrintMemo();

	std::cout << "����Ͻ÷��� or Ż���Ͻ÷���? (YES = 1, NO = 0) : ";
	while (1)
	{
		std::cin >> SELECT;

		// Ż��
		if (SELECT == FALSE)
			break;

		if (SELECT == TRUE)
		{
			// ���� ����
			OutFileExtract(GetPrintMemo());

			// ����
			Cmd(CMD_DELAY, 2);
			break;
		}

	}

	// ������ �ʱ�ȭ
	Destory_PrintMemo();

}

template <typename T>
void JApp<T>::General_Print(T* Data, const int n){

	int SELECT;

	std::cout << GetPrintMemo();

	std::cout << "����Ͻ÷��� or Ż���Ͻ÷���? (YES = 1, NO = 0) : ";
	while (1)
	{
		std::cin >> SELECT;

		// Ż��
		if (SELECT == FALSE)
			break;

		if (SELECT == TRUE)
		{
			// ���� ����
			OutFileExtract(GetPrintMemo());

			// ����
			Cmd(CMD_DELAY, 2);
			break;
		}

	}

	// ������ �ʱ�ȭ
	Destory_PrintMemo();

}

template <typename T>
void JApp<T>::PolyGon_Sort(JPolygon<T>* JPolyApp, const int CriticiaType, const int Analysis){

	Sort<int> sort;
	JPolygonNode<T>* JPolyNode = J_NULL;
	T* Chg_Data, *Ori_Data;
	int Capacity = JPolyApp->GetCapacity();
	int* newIndexArr = J_NULL;

	// �⺻ ������ �� ��������
	Ori_Data = JPolyApp->GetCriticia_Data(JPolyApp->GetPolyList(), CriticiaType, Capacity);
	Chg_Data = JPolyApp->GetCriticia_Data(JPolyApp->GetPolyList(), CriticiaType, Capacity);
		
	// Capacity ��������
	Capacity = JPolyApp->GetCapacity();

	// ����
	Sort_Run(JAPP_POLYGON, Chg_Data, 0, JPolyApp->GetEndIDX(), Analysis);

	// JPolyNode ��������
	JPolyNode = JPolyApp->GetPolyList();

	// �ε��� ����
	JPolyApp->SortIndexToMerge(JPolyApp->GetCriticia_Index(), Ori_Data, Chg_Data, JPolyApp->GetEndIDX());

	// ����
	delete[] Ori_Data;
	delete[] Chg_Data;
	
}

template <typename T>
void JApp<T>::Sort_Run(const int Type, T* Data, const int startidx, const int endidx, const int Analysis){

	int SELECT = J_NULL;
	int IsExit = FALSE;
	Sort<T> sort;

	clock_t StartTime = 0, EndTime;
	StartTime = clock();

	// Ÿ��Ʋ �ʱ�ȭ
	Print_Title_Data.clear();

	while (1)
	{
		Cmd(CMD_CLEAR); // ȭ�� �ʱ�ȭ

		switch (Type)
		{
			case JAPP_POLYGON:
				std::cout << "========================================================" << std::endl;
				std::cout << "POLYGON:: Sorting";
				std::cout << "========================================================" << std::endl;
				break;

			case JAPP_NORMAL:
				std::cout << "========================================================" << std::endl;
				std::cout << "NORMAL:: Sorting";
				std::cout << "========================================================" << std::endl;

				break;

			default:
				break;
		}
		
		// ���
		Print(GLOBAL_PJT_JAPP, GLOBAL_OPTION_TITLE);

		// �Է� �ޱ�
		std::cin.clear();
		std::cin.sync();
		std::cin >> SELECT;

		// Ż��
		if (SELECT == EXIT)
			break;

		// �޴�
		switch (SELECT)
		{
			case JAPP_SORT_BINARY_INSERT: // 1��
				sort.BinaryInsertSort(Data, endidx);										// ��Ȯ�� ����(LOW) / MID ��Ȯ�� ������
				IsExit = TRUE;
				Print_Title_Data.append("BINARY INSERT :::::\n\n");
				break;

			case JAPP_SORT_R_QSORT:		  // 3��
				sort.QuickSort(Data, startidx, endidx, TYPE_R_QUICK);						// ��Ȯ�� ����(LOW) / MID��Ȯ�� ����
				IsExit = TRUE;
				Print_Title_Data.append("Recursive QUICK SORT :::::\n\n");
				break;

			case JAPP_SORT_R_M_QSORT:	  // 4��
				sort.QuickSort(Data, startidx, endidx, TYPE_R_MEDIAN_QUICK);				// ��Ȯ�� ����(LOW) / MID��Ȯ�� ����
				IsExit = TRUE;
				Print_Title_Data.append("Recursive Median QUICK SORT :::::\n\n");
				break;

			case JAPP_SORT_N_M_QSORT:	  // 5��
				sort.QuickSort(Data, startidx, endidx, TYPE_N_MEDIAN_QUICK);				// �Ϻ� ����-�̷�(LOW) / MID(��Ȯ�� ������)
				IsExit = TRUE;
				Print_Title_Data.append("Non-Recursive Median QUICK SORT :::::\n\n");
				break;

			case JAPP_SORT_STD_QSORT:	  // 6��
				sort.QuickSort(Data, startidx, endidx, TYPE_STD_QUICK);			// ��Ȯ�� ����(LOW) / MID ��Ȯ�� ����
				IsExit = TRUE;
				Print_Title_Data.append("STD::SORT QUICK SORT :::::\n\n");
				break;

			case JAPP_SORT_R_MERGE:		  // 7��
				sort.MergeSort(Data, startidx, endidx, TYPE_R_MERGE);			// ��Ȯ�� ����(LOW)
				IsExit = TRUE;
				Print_Title_Data.append("Recursive Merge Sort :::::\n\n");
				break;

			case JAPP_SORT_N_MERGE:	      // 8��
				sort.MergeSort(Data, startidx, endidx, TYPE_N_MERGE);
				IsExit = TRUE;
				Print_Title_Data.append("Non-Recursive Merge Sort :::::\n\n");
				break;

			case JAPP_SORT_NAT_MERGE:	  // 9��
				sort.MergeSort(Data, startidx, endidx, TYPE_NAT_MERGE);
				IsExit = TRUE;
				Print_Title_Data.append("Natural Merge Sort :::::\n\n");
				break;

			case JAPP_SORT_HEAP:		  // 10��
				sort.HeapSort(Data, endidx);
				IsExit = TRUE;
				Print_Title_Data.append("Heap Sort :::::\n\n");
				break;

			case JAPP_SORT_BUBBLE:		  // 11��
				sort.BubbleSort(Data, endidx);												// ��Ȯ�� ����
				IsExit = TRUE;
				Print_Title_Data.append("Bubble Sort :::::\n\n");
				break;

			case JAPP_SORT_SELECTION:	  // 12��
				sort.SelectionSort(Data, endidx);						// ��Ȯ�� ����
				IsExit = TRUE;
				Print_Title_Data.append("Selection Sort :::::\n\n");
				break;

			default:
				Print(GLOBAL_PJT_JAPP, GLOBAL_OPTION_MENU_NOT_FOUND);
				break;

		} // end of switch

		// Analysis - End Print
		if (Analysis == TRUE){
			EndTime = clock();
			Analysis_Print((double)StartTime, (double)EndTime);
		}

		// Ż������
		if (IsExit == TRUE)
			break;

	} // end of switch

}

// PolyGon_Print(JPolygon<double>* JPolyApp)
template <typename T>
void JApp<T>::PolyGon_Print(JPolygon<T>* JPolyApp, const int CriticiaType){

	int SELECT;
	JPolygonNode<T>* JNode = JPolyApp->GetPolyList();

	// ȭ�� �ʱ�ȭ
	Cmd(CMD_CLEAR);

	// ��� ���
	Result_Print(JNode, JPolyApp->GetCriticia_Index(), JPolyApp->GetCapacity(), JAPP_PRINT_UNSORTED, CriticiaType);
	Result_Print(JNode, JPolyApp->GetSort_Index(), JPolyApp->GetCapacity(), JAPP_PRINT_SORTED, CriticiaType);
	
	// ȭ�� ���(Cmd��)
	std::cout << GetPrintMemo();

	std::cout << "����Ͻ÷��� or Ż���Ͻ÷���? (YES = 1, NO = 0) : ";

	while (1)
	{
		std::cin >> SELECT;

		// Ż��
		if (SELECT == FALSE)
			break;

		if (SELECT == TRUE)
		{
			// ���� ����
			OutFileExtract(GetPrintMemo());

			// ����
			Cmd(CMD_DELAY, 2);
			break;
		}

	}

	// ������ �ʱ�ȭ
	Destory_PrintMemo();
}
// end of PolyGon_Print


// PolyGon_Print(JPolygon<double>* JPolyApp)
template <typename T>
void JApp<T>::Linked_Print(LinkedList<T>* BeforeLst, LinkedList<T>* SortedLst){

	int SELECT;
	// ȭ�� �ʱ�ȭ
	Cmd(CMD_CLEAR);

	// ��� ���
	Result_Print(BeforeLst, JAPP_PRINT_UNSORTED);
	Result_Print(SortedLst, JAPP_PRINT_SORTED);

	// ȭ�� ���(Cmd��)
	std::cout << GetPrintMemo();

	std::cout << "����Ͻ÷��� or Ż���Ͻ÷���? (YES = 1, NO = 0) : ";

	while (1)
	{
		std::cin >> SELECT;

		// Ż��
		if (SELECT == FALSE)
			break;

		if (SELECT == TRUE)
		{
			// ���� ����
			OutFileExtract(GetPrintMemo());

			// ����
			Cmd(CMD_DELAY, 2);
			break;
		}

	}

	// ������ �ʱ�ȭ
	Destory_PrintMemo();
}

template <typename T>
void JApp<T>::Result_Print(const T* pArr, const int n, const int Option){

	// ���� Title �ɼ�
	switch (Option)
	{
	case JAPP_PRINT_SORTED:
		Print_Report_Data.append("������ ����\n");
		break;

	case JAPP_PRINT_UNSORTED:
		Print_Report_Data.append("������ ����\n");
		break;

	default:
		break;
	} // end of switch

	for (int i = 0; i < n; i++)
	{
		Print_Report_Data.append("pArr[");
		Print_Report_Data.append(JPatch::to_string(i));
		Print_Report_Data.append("]");
		Print_Report_Data.append(" = ");
		Print_Report_Data.append(JPatch::to_string(pArr[i]));

		Print_Report_Data.append("\n");
	} // end of for
}

// Result_Print(const JPolygonNode<T>* pArr, const int* idxArr, const int n, const int Option, const int CriticiaType)
template <typename T>
void JApp<T>::Result_Print(const JPolygonNode<T>* pArr, const int* idxArr, const int n, const int Option, const int CriticiaType){

	JTuple<T>* ptr = J_NULL;

	// ���� Title �ɼ�
	switch (Option)
	{
		case JAPP_PRINT_SORTED:
			Print_Report_Data.append("������ ����\n");
			break;

		case JAPP_PRINT_UNSORTED:
			Print_Report_Data.append("������ ����\n");
			break;

		default:
			break;
	} // end of switch

	for (int i = 0; i < n; i++)
	{
		Print_Report_Data.append("idxArr[");
		Print_Report_Data.append(JPatch::to_string(i));
		Print_Report_Data.append("]");
		Print_Report_Data.append(" = ");
		Print_Report_Data.append(JPatch::to_string(idxArr[i]));
		Print_Report_Data.append(" / ");
		Print_Report_Data.append("pArr[");
		Print_Report_Data.append(JPatch::to_string(idxArr[i]));
		Print_Report_Data.append("]");
		
		ptr = pArr[idxArr[i]].Position;

		switch (CriticiaType)
		{
			case TYPE_POLY_FIELD_X:
				Print_Report_Data.append(" = ");
				Print_Report_Data.append(JPatch::to_string(ptr->GetX()));
				break;

			case TYPE_POLY_FIELD_Y:
				Print_Report_Data.append(" = ");
				Print_Report_Data.append(JPatch::to_string(ptr->GetY()));
				break;

			case TYPE_POLY_FIELD_RESULT:
				Print_Report_Data.append(" = ");
				Print_Report_Data.append(JPatch::to_string(ptr->GetX() * ptr->GetY()));
				break;

			default:
				break;

		} // end of switch
		
		Print_Report_Data.append("\n");
	} // end of for
	
}
// end of Result_Print

// Specialize Result_Print(const std::string* pArr, const int* idxArr, const int n, const int Option)
template <>
void JApp<std::string>::Result_Print(const std::string* pArr, const int* idxArr, const int n, const int Option){

	// ���� Title �ɼ�
	switch (Option)
	{
		case JAPP_PRINT_SORTED:
			Print_Report_Data.append("������ ����\n");
			break;

		case JAPP_PRINT_UNSORTED:
			Print_Report_Data.append("������ ����\n");
			break;

		default:
			break;
	} // end of switch

	for (int i = 0; i < n; i++)
	{
		Print_Report_Data.append("idxArr[");
		Print_Report_Data.append(JPatch::to_string(i));
		Print_Report_Data.append("]");
		Print_Report_Data.append(" = ");
		Print_Report_Data.append(JPatch::to_string(idxArr[i]));
		Print_Report_Data.append(" / ");
		Print_Report_Data.append("pArr[");
		Print_Report_Data.append(JPatch::to_string(idxArr[i]));
		Print_Report_Data.append("]");
		Print_Report_Data.append(" = ");
		Print_Report_Data.append(pArr[idxArr[i]]);
		Print_Report_Data.append("\n");
	} // end of for

}
// End of Specialize Result_Print

// Template of Result_Print(const T* pArr, const int* idxArr, const int n, const int Option)
template <typename T>
void JApp<T>::Result_Print(const T* pArr, const int* idxArr, const int n, const int Option){
	
	// ���� Title �ɼ�
	switch (Option)
	{
		case JAPP_PRINT_SORTED:
			Print_Report_Data.append("������ ����\n");
			break;

		case JAPP_PRINT_UNSORTED:
			Print_Report_Data.append("������ ����\n");
			break;

		default:
			break;
	} // end of switch

	for (int i = 0; i < n; i++)
	{
		Print_Report_Data.append("idxArr[");
		Print_Report_Data.append(JPatch::to_string(i));
		Print_Report_Data.append("]");
		Print_Report_Data.append(" = ");
		Print_Report_Data.append(JPatch::to_string(idxArr[i]));
		Print_Report_Data.append(" / ");
		Print_Report_Data.append("pArr[");
		Print_Report_Data.append(JPatch::to_string(idxArr[i]));
		Print_Report_Data.append("]");
		Print_Report_Data.append(" = ");
		Print_Report_Data.append(JPatch::to_string(pArr[idxArr]));
		Print_Report_Data.append("\n");
	}
	
}
// end of Template of Result_Print


// Analysis_Print(const int startTime, const int endTime)
template <typename T>
void JApp<T>::Analysis_Print(double StartTime, double EndTime){

	double EstimateTime = ((EndTime - StartTime) / CLOCKS_PER_SEC);

	std::cout << std::endl;
	Print_Analysis_Data.clear();
	Print_Analysis_Data.append("���� ���--------------------------------\n");
	Print_Analysis_Data.append("Analysis Mode\n\n");
	Print_Analysis_Data.append("StartTime :");
	Print_Analysis_Data.append(JPatch::to_string(StartTime));
	Print_Analysis_Data.append(" / ");
	Print_Analysis_Data.append("EndTime :");
	Print_Analysis_Data.append(JPatch::to_string(EndTime));
	Print_Analysis_Data.append(" / ");
	Print_Analysis_Data.append("Estimate Time :");
	Print_Analysis_Data.append(JPatch::to_string(EstimateTime));
	Print_Analysis_Data.append("\n\n");
	
}
// end of Analysis_Print

template <typename T>
std::string JApp<T>::GetPrintMemo(){

	std::string Memo;

	Memo.append(Print_Title_Data);
	Memo.append(Print_Analysis_Data);
	Memo.append(Print_Report_Data);
	
	return Memo;
}

/// Destory_Analysis_Memo()
template <typename T>
void JApp<T>::Destory_PrintMemo(){
	
	Print_Title_Data.clear();
	Print_Analysis_Data.clear();
	Print_Report_Data.clear();
}
//

/// Welcome To JLAND
JLand::JLand(){

}

JLand::~JLand(){

}

void JLand::Run(const int TYPE){
	
	int WIZARD_IDX = WIZARD_JLAND_START;
	int RESULT = J_NULL, ANALYSIS = J_NULL, RANDMOD = J_NULL, USERSIZE = J_NULL;

	// ���
	Cmd(CMD_CLEAR);
	Print(GLOBAL_PJT_JPROGRAM, GLOBAL_OPTION_TITLE);
	Cmd(CMD_DELAY, 1);

	// ������
	while (1)
	{
		if (TYPE == MENU_STRING && WIZARD_IDX != WIZARD_JLAND_T_RAND)
			RESULT = Wizard(WIZARD_IDX);

		// �޴� - STRING�� �ƴҶ�
		if (TYPE != MENU_STRING)
			RESULT = Wizard(WIZARD_IDX);

		// Failover�� �ƴ� ��
		if (RESULT != JLAND_FAILOVER){

			switch (WIZARD_IDX)
			{
				case WIZARD_JLAND_T_ANALYSIS:
					ANALYSIS = RESULT;
					break;

				case WIZARD_JLAND_T_RAND:
					RANDMOD = RESULT;
					break;

				case WIZARD_JLAND_T_USERSIZE:
					USERSIZE = RESULT;
					break;

				default:
					break;

			} // end of switch
		
		} // end of if

		// ���� Ÿ�� ����� ��
		if (TYPE == MENU_STRING && USERSIZE == TYPE_JP_RANDOM_SIZE)
			RANDMOD = Wizard(WIZARD_JLAND_T_RAND);

		WIZARD_IDX++;

		// Ż�� ����
		if (RESULT == JLAND_FAILOVER || WIZARD_IDX > WIZARD_JLAND_END)
			break;
		
	} // end of while

	// ���μ��� ������
	if (RESULT != JLAND_FAILOVER)
	{
		switch (TYPE)
		{
			case MENU_INTEGER:		  // 1�� �޴� 
				Menu_Integer(ANALYSIS, RANDMOD, USERSIZE);
				break;

			case MENU_DOUBLE:		  // 2�� �޴�
				Menu_Double(ANALYSIS, RANDMOD, USERSIZE);
				break;

			case MENU_DOUBLE_POLYGON: // 3�� �޴�
				Menu_Polygon_Double(ANALYSIS, RANDMOD, USERSIZE);
				break;

			case MENU_STRING:		  // 4�� �޴�
				Menu_String(ANALYSIS, RANDMOD, USERSIZE);
				break;

			case MENU_LINKED_INSERT:  // 5�� �޴�
				Menu_Linked_Insert(ANALYSIS, RANDMOD, USERSIZE);
				break;

			default:
				break;
		} // end of switch
	}

}

void JLand::About(){

	// ȭ�� �ʱ�ȭ
	Cmd(CMD_CLEAR);

	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "�Ұ�" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Rabbit.white(��OO)" << std::endl;
	std::cout << "OOOOOOOOOOOOOOOOOOO��" << std::endl;
	std::cout << "Business & Computer Science Engineering" << std::endl;
	std::cout << "2014. 10. 11() !! / 2014. 11. 09" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	// ȭ�� ����
	Cmd(CMD_DELAY, 2);

}

int JLand::Wizard(const int typeNum){

	int RESULT = JLAND_INITIALIZE;
	int IsExit = FALSE;

	while (1)
	{
		int SELECT;

		Cmd(CMD_CLEAR); // ȭ�� �ʱ�ȭ

		// TITLE ���
		switch (typeNum)
		{
			case WIZARD_JLAND_T_ANALYSIS:
				Print(GLOBAL_PJT_JPROGRAM, GLOBAL_OPTION_TITLE_ANALYSIS);
				break;

			case WIZARD_JLAND_T_RAND:
				Print(GLOBAL_PJT_JPROGRAM, GLOBAL_OPTION_TITLE_RAND);
				break;

			case WIZARD_JLAND_T_USERSIZE:
				Print(GLOBAL_PJT_JPROGRAM, GLOBAL_OPTION_TITLE_USERSIZE);
				break;

			case WIZARD_JLAND_T_POLYGON:
				Print(GLOBAL_PJT_JPROGRAM, GLOBAL_OPTION_TITLE_POLYGON);
				break;

			default:
				break;
		}

		// ��� �Է� �ޱ�
		std::cin.clear();
		std::cin.sync();
		std::cin >> SELECT;

		// Ż�� ����
		if (SELECT == EXIT){
			RESULT = JLAND_FAILOVER;
			break;
		}

		// �ɼ� ó�� - �Ǻ� - Wizard ����
		switch (typeNum)
		{
			case WIZARD_JLAND_T_ANALYSIS:

				// �ɼ� �Է� Analysis
				switch (SELECT)
				{
					case TYPE_JLAND_ANALYSIS_ON:
						RESULT = TRUE;
						IsExit = TRUE;
						break;

					case TYPE_JLAND_ANALYSIS_OFF:
						RESULT = FALSE;
						IsExit = TRUE;
						break;

					default:
						Print(GLOBAL_PJT_JPROGRAM, GLOBAL_OPTION_MENU_NOT_FOUND);
						break;
				} // end of switch

				break; // end of analysis

			case WIZARD_JLAND_T_RAND:

				// �ɼ� �Է� Rand
				switch (SELECT)
				{
					case TYPE_RAND_LOW:
						RESULT = TYPE_RAND_LOW;
						IsExit = TRUE;
						break;

					case TYPE_RAND_MID:
						RESULT = TYPE_RAND_MID;
						IsExit = TRUE;
						break;

					case TYPE_RAND_HIGH:
						RESULT = TYPE_RAND_HIGH;
						IsExit = TRUE;
						break;

				default:
					Print(GLOBAL_PJT_JPROGRAM, GLOBAL_OPTION_MENU_NOT_FOUND);
					break;
				} // end of switch

				break; // end of rand

			// �ɼ� �Է� USERSIZE
			case WIZARD_JLAND_T_USERSIZE:

				// ���� ����
				if (SELECT < -1)
					Print(GLOBAL_PJT_JPROGRAM, GLOBAL_OPTION_MENU_NOT_FOUND);
				
				// ���� ����
				if (SELECT == -1)
				{
					RESULT = TYPE_JP_RANDOM_SIZE;
					IsExit = TRUE;
				}

				// ���� ����
				if(SELECT > 0){
					RESULT = SELECT;
					IsExit = TRUE;
				}

				break; // end of usersize

			// �ɼ� �Է� - Polygon
			case WIZARD_JLAND_T_POLYGON:

				switch (SELECT)
				{
					case TYPE_JLAND_POLYGON_X:
						RESULT = TYPE_POLY_FIELD_X;
						IsExit = TRUE;
						break;

					case TYPE_JLAND_POLYGON_Y:
						RESULT = TYPE_POLY_FIELD_Y;
						IsExit = TRUE;
						break;

					case TYPE_JLAND_POLYGON_RESULT:
						RESULT = TYPE_POLY_FIELD_RESULT;
						IsExit = TRUE;
						break;

					// ������ ó��
					default:
						Print(GLOBAL_PJT_JPROGRAM, GLOBAL_OPTION_MENU_NOT_FOUND);
						break;
				}

				break; // end of polygon

			default:
				break;

		} // end of switch

		// Ż������
		if (IsExit == TRUE)
			break;

	} // end of while

	return RESULT;

}

/// Menu_Integer()
void JLand::Menu_Integer(const int Analysis, const int RandType, int UserSize){
	
	JApp<int> JProgram;
	
	// ���� �� ����
	if (UserSize == TYPE_JP_RANDOM_SIZE)
		UserSize = RandBox(RandType);

	int* Data = JProgram.General_Create(UserSize, RandType);

	// ������ ���
	JProgram.Result_Print(Data, UserSize, JAPP_PRINT_UNSORTED);

	// ����
	JProgram.General_Sort(Data, UserSize, Analysis);

	// ������ ���
	JProgram.Result_Print(Data, UserSize, JAPP_PRINT_SORTED);

	// ���
	JProgram.General_Print(Data, UserSize);

}
// End of Menu_Integer()

/// Menu_Double()
void JLand::Menu_Double(const int Analysis, const int RandType, int UserSize){

	JApp<double> JProgram;
	int INPUTTYPE = J_NULL;

	// ���� �� ����
	if (UserSize == TYPE_JP_RANDOM_SIZE)
		UserSize = RandBox(RandType);

	double* Data = JProgram.General_Create(UserSize, RandType);

	// ������ ���
	JProgram.Result_Print(Data, UserSize, JAPP_PRINT_UNSORTED);

	// ����
	JProgram.General_Sort(Data, UserSize, Analysis);

	// ������ ���
	JProgram.Result_Print(Data, UserSize, JAPP_PRINT_SORTED);

	// ���
	JProgram.General_Print(Data, UserSize);

}
// End of Menu_Double()

/// Menu_Polygon_Double()
void JLand::Menu_Polygon_Double(const int Analysis, const int RandType, const int UserSize){
	
	int INPUTTYPE = J_NULL;
	int CRITICIA = J_NULL;
	JApp<double> JProgramApp;
	JPolygon<double>* JPolyApp = new JPolygon<double>(TYPE_DOUBLE);
	
	if (UserSize == TYPE_JP_RANDOM_SIZE)
		INPUTTYPE = TYPE_JP_RANDOM_SIZE;
	else
		INPUTTYPE = TYPE_JP_USER_SIZE;

	// Critica ã��
	CRITICIA = Wizard(WIZARD_JLAND_T_POLYGON);

	// Polygon ����
	JPolyApp->RunOfProcess(INPUTTYPE, RandType, UserSize);

	// ���� ����
	JProgramApp.PolyGon_Sort(JPolyApp, CRITICIA, Analysis);

	// ��� ���
	JProgramApp.PolyGon_Print(JPolyApp, CRITICIA);

}
// End of Menu_Polygon_Double()

/// Menu_String()
void JLand::Menu_String(const int Analysis, const int RandType, int UserSize){

	JApp<std::string> JProgram;
	std::string* Data;

	// ���� �� ����
	if (UserSize == TYPE_JP_RANDOM_SIZE)
		UserSize = RandBox(RandType);

	Data = JProgram.General_Create(UserSize, RandType);
	
	// ������ ���
	JProgram.Result_Print(Data, UserSize, JAPP_PRINT_UNSORTED);

	// ����
	JProgram.General_Sort(Data, UserSize, Analysis);

	// ������ ���
	JProgram.Result_Print(Data, UserSize, JAPP_PRINT_SORTED);
}
// End of Menu_String()

void JLand::Menu_Linked_Insert(const int Analysis, const int RandType, int UserSize){

	int SELECT;
	int IsExit = FALSE;

	clock_t StartTime = clock(), EndTime = 0;

	while (1)
	{
		Cmd(CMD_CLEAR);
		// Ÿ��Ʋ ���
		Print(GLOBAL_PJT_JPROGRAM, GLOBAL_OPTION_TITLE_LINKED);

		std::cin.clear();
		std::cin.sync();

		std::cin >> SELECT;

		if (SELECT == LINKED_JLAND_T_INTEGER)
		{
			JApp<int> Program;
			LinkedList<int>* Normal_List;
			LinkedList<int>* Sorted_List;

			// Ÿ��Ʋ ���

			// ���� �� ����
			if (UserSize == TYPE_JP_RANDOM_SIZE)
				UserSize = RandBox(RandType);

			Normal_List = new LinkedList<int>(NORMAL);
			Sorted_List = new LinkedList<int>(SORT);

			// ���� (Case �ΰ�
			Normal_List = Program.Linked_Create(UserSize, Normal_List, RandType);
			Sorted_List = Program.Linked_Create(UserSize, Sorted_List, RandType);

			// ��
			EndTime = clock();
			Program.Analysis_Print((double)StartTime, (double)EndTime);

			// ���
			Program.Linked_Print(Normal_List, Sorted_List);

			IsExit = TRUE;

		}

		if (SELECT == LINKED_JLAND_T_DOUBLE)
		{
			JApp<double> Program;
			LinkedList<double>* Normal_List;
			LinkedList<double>* Sorted_List;

			// Ÿ��Ʋ ���

			// ���� �� ����
			if (UserSize == TYPE_JP_RANDOM_SIZE)
				UserSize = RandBox(RandType);

			Normal_List = new LinkedList<double>(NORMAL);
			Sorted_List = new LinkedList<double>(SORT);

			// ���� (Case �ΰ�
			Normal_List = Program.Linked_Create(UserSize, Normal_List, RandType);
			Sorted_List = Program.Linked_Create(UserSize, Sorted_List, RandType);

			// ��
			EndTime = clock();
			Program.Analysis_Print((double)StartTime, (double)EndTime);

			// ���
			Program.Linked_Print(Normal_List, Sorted_List);

			IsExit = TRUE;
		}


		if (SELECT == LINKED_JLAND_T_STRING)
		{
			JApp<std::string> Program;
			LinkedList<std::string>* Normal_List;
			LinkedList<std::string>* Sorted_List;

			// Ÿ��Ʋ ���

			// ���� �� ����
			if (UserSize == TYPE_JP_RANDOM_SIZE)
				UserSize = RandBox(RandType);

			Normal_List = new LinkedList<std::string>(NORMAL);
			Sorted_List = new LinkedList<std::string>(SORT);

			// ���� (Case �ΰ�
			Normal_List = Program.Linked_Create(UserSize, Normal_List, RandType);
			Sorted_List = Program.Linked_Create(UserSize, Sorted_List, RandType);

			// ��
			EndTime = clock();
			Program.Analysis_Print((double)StartTime, (double)EndTime);

			// ���
			Program.Linked_Print(Normal_List, Sorted_List);

			IsExit = TRUE;
		}

		if (IsExit == TRUE)
			break;

	}
	

}


// End of JLAND

/// Welcome to JPolygon
// ���� JPolygon
template <typename T>
JPolygon<T>::JPolygon(int _DataType){
	Index = 0;
	Capacity = 0;
	DataType = _DataType;
	IndexArr = J_NULL;
	polyList = J_NULL;
	SortIndexArr = J_NULL;

}
// End of JPolygon

// JPolygon()
template <typename T>
JPolygon<T>::~JPolygon(){
	Destory_Vector();
}

// End of ~JPolygon()


// JPolygon Process
template <typename T>
int JPolygon<T>::RunOfProcess(const int InputType, const int RandType, const int n){

	int PROCESS = POLY_INITIALIZE;

	// ���
	Print(GLOBAL_PJT_POLYGON, GLOBAL_OPTION_TITLE);

	// RandType Ȯ��
	if (IsRandType(RandType) == FALSE)
		PROCESS = POLY_FAILOVER;

	// n�� ������ �ùٸ���(����� �Ǿ���)
	if (n < 0 && PROCESS == POLY_FAILOVER)
		PROCESS = POLY_FAILOVER;

	// �Է� Ÿ��
	if (PROCESS != POLY_FAILOVER){

		switch (InputType)
		{
			case TYPE_JP_USER_SIZE:				// ����� ������
				PROCESS = POLY_SUCCESS;
				Create(RandType, n);
				break;

			case TYPE_JP_RANDOM_SIZE:			// RANDOM ������
				PROCESS = POLY_SUCCESS;
				Create(RandType);
				break;

			default:						// ����
				PROCESS = POLY_FAILOVER;
				break;

		} // end of switch

	} // end of if
	
	return PROCESS;

}
// End of Polygon Process


/// void JPolygon<T>::Create(const int SetRandType, const int n)
template <typename T>
void JPolygon<T>::Create(const int SetRandType, const int n){

	srand((unsigned int)time(J_NULL)); // Seed �� ���

	int x = J_NULL, y = J_NULL;

	// ���� ������� ���� �ʱ�ȭ
	Destory_Vector();

	// ���� ����
	Assign_Vector(n);

	for (int i = 0; i < Capacity; i++)
	{
		int Num_X = RandBox(SetRandType);
		int Num_Y = RandBox(SetRandType);
		JTuple<T>* newNode = new JTuple<T>();

		if (DataType == TYPE_FLOAT)
		{
			float Multi_X = pow((double)RandBox(TYPE_RAND_LOW), -1); // float Random
			float Result_X = Multi_X * (float)Num_X;

			float Multi_Y = pow((double)RandBox(TYPE_RAND_LOW), -1); // float Random
			float Result_Y = Multi_X * (float)Num_Y;

			newNode->SetTuple((T)Result_X, (T)Result_Y);

		}

		if (DataType == TYPE_DOUBLE)
		{
			double Multi_X = pow((double)RandBox(TYPE_RAND_LOW), -1);	    // Double Random
			double Result_X = Multi_X* (double)Num_X;
			double Multi_Y = pow((double)RandBox(TYPE_RAND_LOW), -1);
			double Result_Y = Multi_Y* (double)Num_Y;

			newNode->SetTuple((T)Result_X, (T)Result_Y);
		}

		if (DataType == TYPE_INT){
			newNode->SetTuple(Num_X, Num_Y);
		}

		// ��� ����
		polyList[Index].Position = newNode;
		polyList[Index].index = Index;
		IndexArr[Index] = Index;
		Index++;
	}

}
// End of void JPolygon<T>::Create(const int, const int)

/// JPolygon Sort Data
template <typename T>
T* JPolygon<T>::GetCriticia_Data(JPolygonNode<T>* pData, const int AttrType, const int n){

	T* NewData = new T[n + 1];
	JTuple<T>* ptrNode = J_NULL;
	int Status = TRUE;
	T Result = J_NULL;

	int i = 0;
	while (i < n)
	{
		ptrNode = pData[i].Position;

		switch (AttrType)
		{
		case TYPE_POLY_FIELD_X:
			NewData[i] = ptrNode->GetX();
			break;

		case TYPE_POLY_FIELD_Y:
			NewData[i] = ptrNode->GetY();
			break;

		case TYPE_POLY_FIELD_RESULT:
			Result = ptrNode->GetX() * ptrNode->GetY();
			NewData[i] = Result;
			break;

		default:
			Status = FALSE;
			break;
		}

		if (Status == FALSE)
			return J_NULL;

		i++;
	}

	return NewData;

}
// End of JPolygon Sort Data

/// int JPolygon<T>::IsRandType(int RandType)
template <typename T>
int JPolygon<T>::IsRandType(int RandType){

	int Result = TRUE;

	// RandType ����
	switch (RandType)
	{
		case TYPE_RAND_LOW:
			break;

		case TYPE_RAND_MID:
			break;

		case TYPE_RAND_HIGH:
			break;
			
		default:
			Result = FALSE;
			break;
	}

	return Result;

}
// End of JPolygon<T>::IsRandType(int)

/// JPolygon<T>::Assign_Vector(const int n = J_NULL)
template <typename T>
void JPolygon<T>::Assign_Vector(const int n){

	if (n == 0){
		Capacity = RandBox(TYPE_RAND_MID);
	}
	else
		Capacity = n;

	polyList = new JPolygonNode<T>[Capacity + 1];
	IndexArr = new int[Capacity + 1];

	for (int i = 0; i < Capacity; i++)
	{
		polyList[i].Position = J_NULL;
		IndexArr[i] = FALSE;
	}

}
// End of JPolygon<T>::Assign_Vector(int)

/// JPolygon:Destory_Vector()
template <typename T>
void JPolygon<T>::Destory_Vector(){

	JTuple<T>* ptr = J_NULL;

	if (Capacity != J_NULL)
	{
		for (int i = 0; i < Capacity; i++)
		{
			ptr = polyList[i].Position;

			if (ptr != J_NULL)
			{
				delete[] ptr;
				ptr = J_NULL;
			}
		}

		delete[] polyList;
		delete[] IndexArr;
		delete[] SortIndexArr;

		polyList = J_NULL;
		IndexArr = J_NULL;
		SortIndexArr = J_NULL;

		Capacity = 0;
		Index = 0;
	}

}
// End of JPolygon:Destory_Vector()

/// GetMerge_Index(int* Arr, T* OriData, T* ChgData, const int n)
template <typename T>
void JPolygon<T>::SortIndexToMerge(int* Arr, T* OriData, T* ChgData, const int n){

	int i, j;
	int index = 0;
	int* SortArr = new int[n + 1];

	T NumX = J_NULL;
	T NumY = J_NULL;

	i = 0;
	while (i <= n)
	{
		NumX = ChgData[i];

		j = 0;
		while (j <= n)
		{
			NumY = OriData[j];

			if (NumX == NumY){
				SortArr[index++] = j;
				break;
			}
			j++;
		}
		i++;
	}

	SetSortIndex(SortArr);

}
// End of GetMerge_Index(int*, T*, T*, int)

#endif