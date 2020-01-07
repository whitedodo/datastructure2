/*
	Subject - JLand(Sort) Project / j_land_controller.h
	Created Date - 2014. 10. 8
	Description - JLand / JPolygon Controller
	[Version]
*/

#include "j_model.h"

template <typename T>
JApp<T>::JApp(){

}

template <typename T>
JApp<T>::~JApp(){
	
}

/// Specialize (std::string)General_Create
template <>
std::string* JApp<std::string>::General_Create(const int n, const int SetRandType)
{
	std::string RandomName;
	std::vector<std::string> FamilyNames = GetName(TYPE_FAMILY_NAME);
	std::vector<std::string> FullNames = GetName(TYPE_FULL_NAME);

	// 초기화
	srand((unsigned int)time(NULL)); // Seed 값 사용
	// 선언
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
	// 초기화
	srand((unsigned int)time(NULL)); // Seed 값 사용
	// 선언
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
	// 초기화
	srand((unsigned int)time(NULL)); // Seed 값 사용
	// 선언
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

	// 초기화
	srand((unsigned int)time(NULL)); // Seed 값 사용
	// 선언
	T* Arr = new T[n + 1];

	for (int i = 0; i < n; i++){
		Arr[i] = RandBox(SetRandType);
	}

	return Arr;
}

template <typename T>
void JApp<T>::General_Sort(T* Data, const int n, const int Analysis){
	
	// 정렬 작업
	Sort_Run(JAPP_NORMAL, Data, 0, n - 1, Analysis);

}


template <>
void JApp<std::string>::General_Print(std::string* Data, const int n){

	int SELECT;

	for (int i = 0; i < n; i++)
	{
		Print_Report_Data.append("Data[");
		Print_Report_Data.append(std::to_string(i));
		Print_Report_Data.append("]");
		Print_Report_Data.append(" = ");
		Print_Report_Data.append(Data[i]);
		Print_Report_Data.append("\n");
	}

	std::cout << GetPrintMemo();

	std::cout << "출력하시려면 or 탈출하시려면? (YES = 1, NO = 0) : ";
	while (1)
	{
		std::cin >> SELECT;

		// 탈출
		if (SELECT == FALSE)
			break;

		if (SELECT == TRUE)
		{
			// 파일 추출
			OutFileExtract(GetPrintMemo());

			// 지연
			Cmd(CMD_DELAY, 2);
			break;
		}

	}

	// 데이터 초기화
	Destory_PrintMemo();

}

template <typename T>
void JApp<T>::General_Print(T* Data, const int n){

	int SELECT;

	for (int i = 0; i < n; i++)
	{
		Print_Report_Data.append("Data[");
		Print_Report_Data.append(std::to_string(i));
		Print_Report_Data.append("]");
		Print_Report_Data.append(" = ");
		Print_Report_Data.append(std::to_string(Data[i]));
		Print_Report_Data.append("\n");
	}

	std::cout << GetPrintMemo();

	std::cout << "출력하시려면 or 탈출하시려면? (YES = 1, NO = 0) : ";
	while (1)
	{
		std::cin >> SELECT;

		// 탈출
		if (SELECT == FALSE)
			break;

		if (SELECT == TRUE)
		{
			// 파일 추출
			OutFileExtract(GetPrintMemo());

			// 지연
			Cmd(CMD_DELAY, 2);
			break;
		}

	}

	// 데이터 초기화
	Destory_PrintMemo();

}

template <typename T>
void JApp<T>::PolyGon_Sort(JPolygon<T>* JPolyApp, const int CriticiaType, const int Analysis){

	Sort<int> sort;
	JPolygonNode<T>* JPolyNode = NULL;
	T* Chg_Data, *Ori_Data;
	int Capacity = JPolyApp->GetCapacity();
	int* newIndexArr = NULL;

	// 기본 데이터 값 가져오기
	Ori_Data = JPolyApp->GetCriticia_Data(JPolyApp->GetPolyList(), CriticiaType, Capacity);
	Chg_Data = JPolyApp->GetCriticia_Data(JPolyApp->GetPolyList(), CriticiaType, Capacity);
		
	// Capacity 가져오기
	Capacity = JPolyApp->GetCapacity();

	// 정렬
	Sort_Run(JAPP_POLYGON, Chg_Data, 0, JPolyApp->GetEndIDX(), Analysis);

	// JPolyNode 가져오기
	JPolyNode = JPolyApp->GetPolyList();

	// 인덱스 설정
	JPolyApp->SortIndexToMerge(JPolyApp->GetCriticia_Index(), Ori_Data, Chg_Data, JPolyApp->GetEndIDX());

	// 삭제
	delete[] Ori_Data;
	delete[] Chg_Data;
	
}

template <typename T>
void JApp<T>::Sort_Run(const int Type, T* Data, const int startidx, const int endidx, const int Analysis){

	int SELECT = NULL;
	int IsExit = FALSE;
	Sort<T> sort;

	clock_t StartTime = 0, EndTime;
	StartTime = clock();

	// 타이틀 초기화
	Print_Title_Data.clear();

	while (1)
	{
		Cmd(CMD_CLEAR); // 화면 초기화

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
		
		// 출력
		Print(GLOBAL_PJT_JAPP, GLOBAL_OPTION_TITLE);

		// 입력 받기
		std::cin.clear();
		std::cin.sync();
		std::cin >> SELECT;

		// 탈출
		if (SELECT == EXIT)
			break;

		// 메뉴
		switch (SELECT)
		{
			case JAPP_SORT_BINARY_INSERT: // 1번
				sort.BinaryInsertSort(Data, endidx);										// 정확도 보장(LOW) / MID 정확도 떨어짐
				IsExit = TRUE;
				Print_Title_Data.append("BINARY INSERT :::::\n\n");
				break;

			case JAPP_SORT_LINK_INSERT:	  // 2번

				// 일반 Sort일 때
				if (Type == JAPP_NORMAL)


					break;

			case JAPP_SORT_R_QSORT:		  // 3번
				sort.QuickSort(Data, startidx, endidx, TYPE_R_QUICK);						// 정확도 보장(LOW) / MID정확도 보장
				IsExit = TRUE;
				Print_Title_Data.append("Recursive QUICK SORT :::::\n\n");
				break;

			case JAPP_SORT_R_M_QSORT:	  // 4번
				sort.QuickSort(Data, startidx, endidx, TYPE_R_MEDIAN_QUICK);				// 정확도 보장(LOW) / MID정확도 보장
				IsExit = TRUE;
				Print_Title_Data.append("Recursive Median QUICK SORT :::::\n\n");
				break;

			case JAPP_SORT_N_M_QSORT:	  // 5번
				sort.QuickSort(Data, startidx, endidx, TYPE_N_MEDIAN_QUICK);				// 일부 보장-이론(LOW) / MID(정확도 떨어짐)
				IsExit = TRUE;
				Print_Title_Data.append("Non-Recursive Median QUICK SORT :::::\n\n");
				break;

			case JAPP_SORT_STD_QSORT:	  // 6번
				sort.QuickSort(Data, startidx, endidx, TYPE_STD_QUICK);			// 정확도 보장(LOW) / MID 정확도 보장
				IsExit = TRUE;
				Print_Title_Data.append("STD::SORT QUICK SORT :::::\n\n");
				break;

			case JAPP_SORT_R_MERGE:		  // 7번
				sort.MergeSort(Data, startidx, endidx, TYPE_R_MERGE);			// 정확도 보장(LOW)
				IsExit = TRUE;
				Print_Title_Data.append("Recursive Merge Sort :::::\n\n");
				break;

			case JAPP_SORT_N_MERGE:	      // 8번
				sort.MergeSort(Data, startidx, endidx, TYPE_N_MERGE);
				IsExit = TRUE;
				Print_Title_Data.append("Non-Recursive Merge Sort :::::\n\n");
				break;

			case JAPP_SORT_NAT_MERGE:	  // 9번
				sort.MergeSort(Data, startidx, endidx, TYPE_NAT_MERGE);
				IsExit = TRUE;
				Print_Title_Data.append("Natural Merge Sort :::::\n\n");
				break;

			case JAPP_SORT_HEAP:		  // 10번
				sort.HeapSort(Data, endidx);
				IsExit = TRUE;
				Print_Title_Data.append("Heap Sort :::::\n\n");
				break;

			case JAPP_SORT_BUBBLE:		  // 11번
				sort.BubbleSort(Data, endidx);												// 정확도 보장
				IsExit = TRUE;
				Print_Title_Data.append("Bubble Sort :::::\n\n");
				break;

			case JAPP_SORT_SELECTION:	  // 12번
				sort.SelectionSort(Data, endidx);						// 정확도 보장
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

		// 탈출조건
		if (IsExit == TRUE)
			break;

	} // end of switch

}

// PolyGon_Print(JPolygon<double>* JPolyApp)
template <typename T>
void JApp<T>::PolyGon_Print(JPolygon<T>* JPolyApp, const int CriticiaType){

	int SELECT;
	JPolygonNode<T>* JNode = JPolyApp->GetPolyList();

	// 화면 초기화
	Cmd(CMD_CLEAR);

	// 결과 출력
	Result_Print(JNode, JPolyApp->GetCriticia_Index(), JPolyApp->GetCapacity(), JAPP_PRINT_UNSORTED, CriticiaType);
	Result_Print(JNode, JPolyApp->GetSort_Index(), JPolyApp->GetCapacity(), JAPP_PRINT_SORTED, CriticiaType);
	
	// 화면 출력(Cmd상)
	cout << GetPrintMemo();

	cout << "출력하시려면 or 탈출하시려면? (YES = 1, NO = 0) : ";

	while (1)
	{
		std::cin >> SELECT;

		// 탈출
		if (SELECT == FALSE)
			break;

		if (SELECT == TRUE)
		{
			// 파일 추출
			OutFileExtract(GetPrintMemo());

			// 지연
			Cmd(CMD_DELAY, 2);
			break;
		}

	}

	// 데이터 초기화
	Destory_PrintMemo();

}
// end of PolyGon_Print

// Result_Print(const JPolygonNode<T>* pArr, const int* idxArr, const int n, const int Option, const int CriticiaType)
template <typename T>
void JApp<T>::Result_Print(const JPolygonNode<T>* pArr, const int* idxArr, const int n, const int Option, const int CriticiaType){

	JTuple<T>* ptr = NULL;

	// 정렬 Title 옵션
	switch (Option)
	{
		case JAPP_PRINT_SORTED:
			Print_Report_Data.append("정렬후 상태\n");
			break;

		case JAPP_PRINT_UNSORTED:
			Print_Report_Data.append("정렬전 상태\n");
			break;

		default:
			break;
	} // end of switch

	for (int i = 0; i < n; i++)
	{
		Print_Report_Data.append("idxArr[");
		Print_Report_Data.append(std::to_string(i));
		Print_Report_Data.append("]");
		Print_Report_Data.append(" = ");
		Print_Report_Data.append(std::to_string(idxArr[i]));
		Print_Report_Data.append(" / ");
		Print_Report_Data.append("pArr[");
		Print_Report_Data.append(std::to_string(idxArr[i]));
		Print_Report_Data.append("]");
		
		ptr = pArr[idxArr[i]].Position;

		switch (CriticiaType)
		{
			case TYPE_POLY_FIELD_X:
				Print_Report_Data.append(" = ");
				Print_Report_Data.append(std::to_string(ptr->GetX()));
				break;

			case TYPE_POLY_FIELD_Y:
				Print_Report_Data.append(" = ");
				Print_Report_Data.append(std::to_string(ptr->GetY()));
				break;

			case TYPE_POLY_FIELD_RESULT:
				Print_Report_Data.append(" = ");
				Print_Report_Data.append(std::to_string(ptr->GetX() * ptr->GetY()));
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

	// 정렬 Title 옵션
	switch (Option)
	{
		case JAPP_PRINT_SORTED:
			Print_Report_Data.append("정렬후 상태\n");
			break;

		case JAPP_PRINT_UNSORTED:
			Print_Report_Data.append("정렬전 상태\n");
			break;

		default:
			break;
	} // end of switch

	for (int i = 0; i < n; i++)
	{
		Print_Report_Data.append("idxArr[");
		Print_Report_Data.append(std::to_string(i));
		Print_Report_Data.append("]");
		Print_Report_Data.append(" = ");
		Print_Report_Data.append(std::to_string(idxArr[i]));
		Print_Report_Data.append(" / ");
		Print_Report_Data.append("pArr[");
		Print_Report_Data.append(std::to_string(idxArr[i]));
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
	
	// 정렬 Title 옵션
	switch (Option)
	{
		case JAPP_PRINT_SORTED:
			Print_Report_Data.append("정렬후 상태\n");
			break;

		case JAPP_PRINT_UNSORTED:
			Print_Report_Data.append("정렬전 상태\n");
			break;

		default:
			break;
	} // end of switch

	for (int i = 0; i < n; i++)
	{
		Print_Report_Data.append("idxArr[");
		Print_Report_Data.append(std::to_string(i));
		Print_Report_Data.append("]");
		Print_Report_Data.append(" = ");
		Print_Report_Data.append(std::to_string(idxArr[i]));
		Print_Report_Data.append(" / ");
		Print_Report_Data.append("pArr[");
		Print_Report_Data.append(std::to_string(idxArr[i]));
		Print_Report_Data.append("]");
		Print_Report_Data.append(" = ");
		Print_Report_Data.append(std::to_string(pArr[idxArr]));
		Print_Report_Data.append("\n");
	}
	
}
// end of Template of Result_Print


// Analysis_Print(const int startTime, const int endTime)
template <typename T>
void JApp<T>::Analysis_Print(double StartTime, double EndTime){

	std::ostringstream oss;
	double EstimateTime = ((EndTime - StartTime) / CLOCKS_PER_SEC);

	cout << endl;
	Print_Analysis_Data.clear();
	Print_Analysis_Data.append("측정 결과--------------------------------\n");
	Print_Analysis_Data.append("Analysis Mode\n\n");
	Print_Analysis_Data.append("StartTime :");
	Print_Analysis_Data.append(std::to_string(StartTime));
	Print_Analysis_Data.append(" / ");
	Print_Analysis_Data.append("EndTime :");
	Print_Analysis_Data.append(std::to_string(EndTime));
	Print_Analysis_Data.append(" / ");
	Print_Analysis_Data.append("Estimate Time :");
	Print_Analysis_Data.append(std::to_string(EstimateTime));
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
	int RESULT = NULL, ANALYSIS = NULL, RANDMOD = NULL, USERSIZE = NULL;

	// 출력
	Cmd(CMD_CLEAR);
	Print(GLOBAL_PJT_JPROGRAM, GLOBAL_OPTION_TITLE);
	Cmd(CMD_DELAY, 1);

	// 마법사
	while (1)
	{
		if (TYPE == MENU_STRING && WIZARD_IDX != WIZARD_JLAND_T_RAND)
			RESULT = Wizard(WIZARD_IDX);

		// 메뉴 - STRING이 아닐때
		if (TYPE != MENU_STRING)
			RESULT = Wizard(WIZARD_IDX);

		// Failover가 아닐 때
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

		// 랜덤 타입 골랐을 때
		if (TYPE == MENU_STRING && USERSIZE == TYPE_JP_RANDOM_SIZE)
			RANDMOD = Wizard(WIZARD_JLAND_T_RAND);

		WIZARD_IDX++;

		// 탈출 조건
		if (RESULT == JLAND_FAILOVER || WIZARD_IDX > WIZARD_JLAND_END)
			break;
		
	} // end of while

	// 프로세스 성공시
	if (RESULT != JLAND_FAILOVER)
	{
		switch (TYPE)
		{
			case MENU_INTEGER:		  // 1번 메뉴 
				Menu_Integer(ANALYSIS, RANDMOD, USERSIZE);
				break;

			case MENU_DOUBLE:		  // 2번 메뉴
				Menu_Double(ANALYSIS, RANDMOD, USERSIZE);
				break;

			case MENU_DOUBLE_POLYGON: // 3번 메뉴
				Menu_Polygon_Double(ANALYSIS, RANDMOD, USERSIZE);
				break;

			case MENU_STRING:		  // 4번 메뉴
				Menu_String(ANALYSIS, RANDMOD, USERSIZE);
				break;

			default:
				break;
		} // end of switch
	}

}

void JLand::About(){

	// 화면 초기화
	Cmd(CMD_CLEAR);

	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "소개" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "OOOOO(정OO)" << std::endl;
	std::cout << "OOOOOOOOOOOOOOOOOO교" << std::endl;
	std::cout << "Business & Computer Science Engineering" << std::endl;
	std::cout << "2014. 10. 12" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	// 화면 지연
	Cmd(CMD_DELAY, 2);

}

int JLand::Wizard(const int typeNum){

	int RESULT = JLAND_INITIALIZE;
	int IsExit = FALSE;

	while (1)
	{
		int SELECT;

		Cmd(CMD_CLEAR); // 화면 초기화

		// TITLE 출력
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

		// 명령 입력 받기
		std::cin.clear();
		std::cin.sync();
		std::cin >> SELECT;

		// 탈출 조건
		if (SELECT == EXIT){
			RESULT = JLAND_FAILOVER;
			break;
		}

		// 옵션 처리 - 판별 - Wizard 유형
		switch (typeNum)
		{
			case WIZARD_JLAND_T_ANALYSIS:

				// 옵션 입력 Analysis
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

				// 옵션 입력 Rand
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

			// 옵션 입력 USERSIZE
			case WIZARD_JLAND_T_USERSIZE:

				// 오류 유형
				if (SELECT < -1)
					Print(GLOBAL_PJT_JPROGRAM, GLOBAL_OPTION_MENU_NOT_FOUND);
				
				// 랜덤 유형
				if (SELECT == -1)
				{
					RESULT = TYPE_JP_RANDOM_SIZE;
					IsExit = TRUE;
				}

				// 정상 범위
				if(SELECT > 0){
					RESULT = SELECT;
					IsExit = TRUE;
				}

				break; // end of usersize

			// 옵션 입력 - Polygon
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

					// 비정상 처리
					default:
						Print(GLOBAL_PJT_JPROGRAM, GLOBAL_OPTION_MENU_NOT_FOUND);
						break;
				}

				break; // end of polygon

			default:
				break;

		} // end of switch

		// 탈출조건
		if (IsExit == TRUE)
			break;

	} // end of while

	return RESULT;

}

/// Menu_Integer()
void JLand::Menu_Integer(const int Analysis, const int RandType, int UserSize){
	
	JApp<int> JProgram;
	
	// 랜덤 수 추출
	if (UserSize == TYPE_JP_RANDOM_SIZE)
		UserSize = RandBox(RandType);

	int* Data = JProgram.General_Create(UserSize, RandType);
	// 정렬
	JProgram.General_Sort(Data, UserSize, Analysis);
	// 출력
	JProgram.General_Print(Data, UserSize);

}
// End of Menu_Integer()

/// Menu_Double()
void JLand::Menu_Double(const int Analysis, const int RandType, int UserSize){

	JApp<double> JProgram;
	int INPUTTYPE = NULL;

	// 랜덤 수 추출
	if (UserSize == TYPE_JP_RANDOM_SIZE)
		UserSize = RandBox(RandType);

	double* Data = JProgram.General_Create(UserSize, RandType);
	// 정렬
	JProgram.General_Sort(Data, UserSize, Analysis);
	// 출력
	JProgram.General_Print(Data, UserSize);

}
// End of Menu_Double()

/// Menu_Polygon_Double()
void JLand::Menu_Polygon_Double(const int Analysis, const int RandType, const int UserSize){
	
	int INPUTTYPE = NULL;
	int CRITICIA = NULL;
	JApp<double> JProgramApp;
	JPolygon<double>* JPolyApp = new JPolygon<double>(TYPE_DOUBLE);
	
	if (UserSize == TYPE_JP_RANDOM_SIZE)
		INPUTTYPE = TYPE_JP_RANDOM_SIZE;
	else
		INPUTTYPE = TYPE_JP_USER_SIZE;

	// Critica 찾기
	CRITICIA = Wizard(WIZARD_JLAND_T_POLYGON);

	// Polygon 실행
	JPolyApp->RunOfProcess(INPUTTYPE, RandType, UserSize);

	// 정렬 실행
	JProgramApp.PolyGon_Sort(JPolyApp, CRITICIA, Analysis);

	// 결과 출력
	JProgramApp.PolyGon_Print(JPolyApp, CRITICIA);

}
// End of Menu_Polygon_Double()

/// Menu_String()
void JLand::Menu_String(const int Analysis, const int RandType, int UserSize){

	JApp<std::string> JProgram;
	std::string* Data;

	// 랜덤 수 추출
	if (UserSize == TYPE_JP_RANDOM_SIZE)
		UserSize = RandBox(RandType);

	Data = JProgram.General_Create(UserSize, RandType);

	// 정렬
	JProgram.General_Sort(Data, UserSize, Analysis);
	// 출력
	JProgram.General_Print(Data, UserSize);
}
// End of Menu_String()

// End of JLAND

/// Welcome to JPolygon
// 생성 JPolygon
template <typename T>
JPolygon<T>::JPolygon(int _DataType){
	Index = 0;
	Capacity = 0;
	DataType = _DataType;
	IndexArr = NULL;
	polyList = NULL;
	SortIndexArr = NULL;

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

	// 출력
	Print(GLOBAL_PJT_POLYGON, GLOBAL_OPTION_TITLE);

	// RandType 확인
	if (IsRandType(RandType) == FALSE)
		PROCESS = POLY_FAILOVER;

	// n의 범위가 올바른지(양수가 되야함)
	if (n < 0 && PROCESS == POLY_FAILOVER)
		PROCESS = POLY_FAILOVER;

	// 입력 타입
	if (PROCESS != POLY_FAILOVER){

		switch (InputType)
		{
			case TYPE_JP_USER_SIZE:				// 사용자 사이즈
				PROCESS = POLY_SUCCESS;
				Create(RandType, n);
				break;

			case TYPE_JP_RANDOM_SIZE:			// RANDOM 사이즈
				PROCESS = POLY_SUCCESS;
				Create(RandType);
				break;

			default:						// 실패
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

	srand((unsigned int)time(NULL)); // Seed 값 사용

	int x = NULL, y = NULL;

	// 공간 재생성을 위한 초기화
	Destory_Vector();

	// 공간 배정
	Assign_Vector(n);

	for (int i = 0; i < Capacity; i++)
	{
		int Num_X = RandBox(SetRandType);
		int Num_Y = RandBox(SetRandType);
		JTuple<T>* newNode = new JTuple<T>();

		if (DataType == TYPE_FLOAT)
		{
			float Multi_X = pow((float)RandBox(TYPE_RAND_LOW), -1); // float Random
			float Result_X = Multi_X * (float)Num_X;

			float Multi_Y = pow((float)RandBox(TYPE_RAND_LOW), -1); // float Random
			float Result_Y = Multi_X * (float)Num_Y;

			newNode->SetTuple((T)Result_X, (T)Result_Y);

		}

		if (DataType == TYPE_DOUBLE)
		{
			double Multi_X = pow(RandBox(TYPE_RAND_LOW), -1);	    // Double Random
			double Result_X = Multi_X* (double)Num_X;
			double Multi_Y = pow(RandBox(TYPE_RAND_LOW), -1);
			double Result_Y = Multi_Y* (double)Num_Y;

			newNode->SetTuple((T)Result_X, (T)Result_Y);
		}

		if (DataType == TYPE_INT){
			newNode->SetTuple(Num_X, Num_Y);
		}

		// 노드 삽입
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
	JTuple<T>* ptrNode = NULL;
	int Status = TRUE;
	T Result = NULL;

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
			return NULL;

		i++;
	}

	return NewData;

}
// End of JPolygon Sort Data

/// int JPolygon<T>::IsRandType(int RandType)
template <typename T>
int JPolygon<T>::IsRandType(int RandType){

	int Result = TRUE;

	// RandType 유형
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

/// JPolygon<T>::Assign_Vector(const int n = NULL)
template <typename T>
void JPolygon<T>::Assign_Vector(const int n = NULL){

	if (n == 0){
		Capacity = RandBox(TYPE_RAND_MID);
	}
	else
		Capacity = n;

	polyList = new JPolygonNode<T>[Capacity + 1];
	IndexArr = new int[Capacity + 1];

	for (int i = 0; i < Capacity; i++)
	{
		polyList[i].Position = NULL;
		IndexArr[i] = FALSE;
	}

}
// End of JPolygon<T>::Assign_Vector(int)

/// JPolygon:Destory_Vector()
template <typename T>
void JPolygon<T>::Destory_Vector(){

	JTuple<T>* ptr = NULL;

	if (Capacity != NULL)
	{
		for (int i = 0; i < Capacity; i++)
		{
			ptr = polyList[i].Position;

			if (ptr != NULL)
			{
				delete[] ptr;
				ptr = NULL;
			}
		}

		delete[] polyList;
		delete[] IndexArr;
		delete[] SortIndexArr;

		polyList = NULL;
		IndexArr = NULL;
		SortIndexArr = NULL;

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

	T NumX = NULL;
	T NumY = NULL;

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