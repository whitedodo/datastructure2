#include <iostream>

#include "jApp.h"
#include "common.h"
#include "wizard.h"
#include "TManager.h"

using namespace std;


TaskManager::TaskManager(){

}
TaskManager::~TaskManager(){

}

void TaskManager::MenuOfInteger(int* pArr, JUserVar* jvar){

	Wizard wizard;
	int Status = FALSE;

	// 수동조작
	if ( jvar->GetUserType( ) == MANUAL ){

		if ( wizard.TManagerWizard( jvar ) == TRUE )
			Status = TRUE;

	} // end of if

	// 자동화 여부
	if ( jvar->GetUserType( ) == AUTO )
		Status = TRUE;

	// 참일 때
	if ( Status == TRUE )
	{
		// 선언부
		JApp<int> japp;
		LinkedList<int>* plinkedlist;
		pArr = new int[ jvar->GetUserSize( ) + 1 ];
		int datatype = japp.GetDataType( jvar->GetSortType( ) );

		// 생성
		pArr = japp.Create( jvar->GetValueType( ), jvar->GetUserSize( ) );
		plinkedlist = japp.ListCreate( pArr, jvar->GetUserSize( ) );
		Node<int>* ptr = plinkedlist->GetFirstNode( );

		// 출력 생성(정렬 이전)
		japp.PrintCreate( ptr, pArr, TYPE_PRINT_OFF, jvar );
		 
		// 정렬
		japp.SortOfRun( jvar, pArr, plinkedlist->GetFirstNode() );

		// 출력 생성(정렬 후)
		japp.PrintCreate( ptr, pArr, TYPE_PRINT_ON, jvar );

		// 수동조작일 때
		if (jvar->GetUserType() == MANUAL)
		{
			// 출력
			jvar->SetPrintMemo( japp.PrintTotalCreate( jvar ) );
			japp.PrintView( jvar->GetPrintMemo( ) );

			// 마지막 질문
			jvar->SetQuestion( wizard.ChooseOfQuestion( ) );

			// 저장
			if ( jvar->GetQuestion( ) == WIZARD_SAVE )
				japp.ExtractFile( jvar );
			
		} // end of if

		// 자동조작일 때
		if ( jvar->GetUserType( ) == AUTO )
			japp.CreateAutomatric( jvar );

		// 소거
		delete pArr;
		delete plinkedlist;

		pArr = NULL;
		plinkedlist = NULL;
	} // end of if
}

void TaskManager::MenuOfDouble(double* pArr, JUserVar* jvar){

	Wizard wizard;
	int Status = FALSE;

	// 수동조작
	if ( jvar->GetUserType( ) == MANUAL ){

		if ( wizard.TManagerWizard( jvar ) == TRUE )
			Status = TRUE;
		
	} // end of if

	// 자동화 여부
	if ( jvar->GetUserType( ) == AUTO )
		Status = TRUE;


	// 참일 때
	if (Status == TRUE)
	{
		JApp<double> japp;
		LinkedList<double>* plinkedlist;

		jvar->SetDataType ( japp.GetDataType( jvar->GetSortType( ) ) );

		// 생성
		pArr = japp.Create( jvar->GetValueType( ), jvar->GetUserSize( ) );
		plinkedlist = japp.ListCreate( pArr, jvar->GetUserSize( ) );
		Node<double>* ptr = plinkedlist->GetFirstNode( );

		// 출력 생성(정렬 이전)
		japp.PrintCreate( ptr, pArr, TYPE_PRINT_OFF, jvar );

		// 정렬
		japp.SortOfRun( jvar, pArr, plinkedlist->GetFirstNode( ) );

		// 출력 생성(정렬 후)
		japp.PrintCreate( ptr, pArr, TYPE_PRINT_ON, jvar );
		

		// 수동조작일 때
		if ( jvar->GetUserType( ) == MANUAL )
		{
			// 출력
			jvar->SetPrintMemo( japp.PrintTotalCreate( jvar ) );
			japp.PrintView( jvar->GetPrintMemo( ) ) ;

			// 마지막 질문
			jvar->SetQuestion ( wizard.ChooseOfQuestion( ) );

			// 저장
			if ( jvar->GetQuestion( ) == WIZARD_SAVE )
				japp.ExtractFile( jvar );

		} // end of if

		// 자동조작일 때
		if ( jvar->GetUserType( ) == AUTO )
			japp.CreateAutomatric( jvar );

		// 소거
		delete pArr;
		delete plinkedlist;

		pArr = NULL;
		plinkedlist = NULL;

	}
}

void TaskManager::MenuOfPolygon(int* pArr, JUserVar* jvar){

	Wizard wizard;
	int Status = FALSE;

	// 수동조작
	if ( jvar->GetUserType( ) == MANUAL ){

		// Wizard
		if ( wizard.TManagerWizard( jvar ) == TRUE )
			Status = TRUE;

	} // end of if

	// 자동화 여부
	if ( jvar->GetUserType( ) == AUTO )
		Status = TRUE;

	// 참일 때
	if ( Status == TRUE )
	{
		JApp<double> japp;
		JTime* startTime = NULL, *endTime = NULL;
		JPolygonList<double>* jpolylist;
		LinkedList<double>* plinkedlist;
		double* oriArr, *chgArr;

		// 기준점(Polygon)
		jvar->SetCriticType(POLY_TYPE_WEIGHT);

		// 분석 도구 위치
		japp.SetWhereAnalysis( ANALYSIS_OUTER );

		// 생성
		pArr = japp.IndexCreate( jvar->GetUserSize() );
		jpolylist = japp.PolyCreateList( jvar->GetValueType(),  jvar->GetUserSize( ) );

		oriArr = japp.PolyCreateView( jpolylist, POLY_TYPE_WEIGHT, jvar->GetUserSize( ) );
		chgArr = japp.PolyCreateView( jpolylist, POLY_TYPE_WEIGHT, jvar->GetUserSize( ) );

		plinkedlist = japp.ListCreate( oriArr, jvar->GetUserSize( ) );

		Node<double>* ptr = plinkedlist->GetFirstNode();

		// 출력 생성(정렬 이전)
		japp.PrintCreate( jpolylist, pArr, TYPE_PRINT_OFF, jvar );

		// 분석 시작 - OUTER일 때
		if ( japp.GetWhereAnalysis() == ANALYSIS_OUTER )
			startTime = GetTimer();

		// 정렬
		japp.SortOfRun( jvar , chgArr, plinkedlist->GetFirstNode( ) );

		japp.IndexToMerge( pArr, oriArr, chgArr, jvar->GetUserSize( ) );

		// 분석 종료
		if ( japp.GetWhereAnalysis( ) == ANALYSIS_OUTER )
		{
			endTime = GetTimer( );
			japp.CreateAnalysis( startTime, endTime , jvar );
		}

		// 출력 생성(정렬 이후)
		japp.PrintCreate( jpolylist, pArr, TYPE_PRINT_ON, jvar );

		// 수동조작일 때
		if ( jvar->GetUserType() == MANUAL )
		{
			// 출력
			jvar->SetPrintMemo( japp.PrintTotalCreate( jvar ) );
			japp.PrintView( jvar->GetPrintMemo( ) );

			// 마지막 질문
			jvar->SetQuestion( wizard.ChooseOfQuestion() );

			// 저장
			if ( jvar->GetQuestion() == WIZARD_SAVE )
				japp.ExtractFile( jvar );

		}

		// 자동조작일 때
		if ( jvar->GetUserType( ) == AUTO )
			japp.CreateAutomatric( jvar );

		// 소거
		delete oriArr;
		delete chgArr;
		delete pArr;
		delete plinkedlist;
		delete[] jpolylist;

		oriArr = NULL;
		chgArr = NULL;
		pArr = NULL;
		plinkedlist = NULL;
		jpolylist = NULL;

	} // end of if
}

void TaskManager::MenuOfString(std::string* pArr, JUserVar* jvar){

	Wizard wizard;
	JApp<std::string> japp;
	int Status = FALSE;

	// 파일 존재 여부
	if ( japp.IsFileLoading( ) == FALSE )
	{
		std::cout << "이름 관련 파일이 존재하지 않습니다." << std::endl;
		Cmd(CMD_DELAY, 3);
		return;
	}

	// 수동조작
	if ( jvar->GetUserType( ) == MANUAL ){
		 
		if (wizard.TManagerWizard(jvar) == TRUE)
			Status = TRUE;

	} // end of if

	// 자동화 여부
	if (jvar->GetUserType() == AUTO)
		Status = TRUE;


	// 참일 때
	if (Status == TRUE)
	{
		LinkedList<std::string>* plinkedlist = NULL;

		jvar->SetDataType( japp.GetDataType ( jvar->GetSortType( ) ) );
		pArr = NULL;

		// 생성
		pArr = japp.Create( jvar->GetValueType() , jvar->GetUserSize( ) );
		plinkedlist = japp.ListCreate( pArr, jvar->GetUserSize() );

		Node<std::string>* ptr = NULL;
		ptr = plinkedlist->GetFirstNode( );

		// 출력 생성(정렬 이전)
		japp.PrintCreate( ptr, pArr, TYPE_PRINT_OFF, jvar );

		// 정렬
		japp.SortOfRun( jvar , pArr, ptr);
		ptr = plinkedlist->GetFirstNode( );

		// 출력 생성(정렬 이후)
		japp.PrintCreate( ptr, pArr , TYPE_PRINT_ON, jvar );

		// 수동조작일 때
		if ( jvar->GetUserType( ) == MANUAL )
		{
			// 출력
			std::string printdata = japp.PrintTotalCreate( jvar );
			japp.PrintView( printdata );
			jvar->SetPrintMemo( printdata );

			// 마지막 질문
			jvar->SetQuestion( wizard.ChooseOfQuestion( ) );

			// 저장
			if ( jvar->GetQuestion( ) == WIZARD_SAVE )
				japp.ExtractFile( jvar );

		}

		// 자동조작일 때
		if ( jvar->GetUserType() == AUTO )
			japp.CreateAutomatric(jvar);

		// 소거
		delete[] pArr;
		delete plinkedlist;

		pArr = NULL;
		plinkedlist = NULL;

	} // end of if
}

void TaskManager::MenuOfAuto(JUserVar* jvar){

	int* intArr = NULL;
	double *dblArr = NULL;
	std::string* stringArr = NULL;

	int count = 1;

	int SAMPLE_SIZE_MIN = 0;
	int SAMPLE_SIZE_MAX = 5;

	int SizeArr[5] = { 1000, 5000, 10000, 50000, 100000 };

	JTime* startTime = GetTimer();
	JTime* endTime = NULL;

	// 형식 입력
	jvar->SetUserType(AUTO);

	// 메뉴 조건
	for (int Choose = MENU_SIZE_MIN; Choose <= MENU_SIZE_MAX; Choose++)
	{
		// Value Type
		for (int ValueIDX = WIZARD_VALUETYPE_MIN; ValueIDX <= WIZARD_VALUETYPE_MAX; ValueIDX++){

			jvar->SetValueType( ValueIDX );

			// 셈플 표본
			for (int SampleIDX = SAMPLE_SIZE_MIN; SampleIDX < SAMPLE_SIZE_MAX; SampleIDX++){

				jvar->SetUserSize( SizeArr[SampleIDX] );

				// 정렬 유형
				for (int SortIDX = WIZARD_SORT_MIN + 1; SortIDX <= WIZARD_SORT_MAX; SortIDX++){

					jvar->SetSortType( SortIDX );

					cout << count++;
					cout << "번 / ";

					// Menu of Switch
					switch (Choose)
					{
						case MENU_INTEGER:
							jvar->appendPrintMemo("^Integer형^\n");
							cout << "Integer형:";
							MenuOfInteger( intArr, jvar );
							break;

						case MENU_DOUBLE:
							jvar->appendPrintMemo("^Double형^\n");
							cout << "Double형:";

							MenuOfDouble( dblArr, jvar );
							break;

						case MENU_POLYGON:
							jvar->appendPrintMemo("^Polygon Double형^\n");
							cout << "Polygon Double형:";
							MenuOfPolygon(intArr, jvar);
							break;

						case MENU_STRING:
							jvar->appendPrintMemo("^String형^\n");
							cout << "String형:";
							MenuOfString(stringArr, jvar);
							break;

						default:
							break;

					} // end of switch

					cout << "크기:" << jvar->GetUserSize();
					cout << " / ";

					// Menu of SortIDX
					switch (SortIDX)
					{
						case WIZARD_BINARY_SORT:
							cout << "BinarySort";
							break;

						case WIZARD_LINKED_SORT:
							cout << "LinkedSort";
							break;

						case WIZARD_QUICK_R:
							cout << "Quick_R";
							break;

						case WIZARD_QUICK_R_MEDIAN:
							cout << "Quick_R_Median";
							break;

						case WIZARD_QUICK_N_MEDIAN:
							cout << "Quick_N_Median";
							break;

						case WIZARD_QUICK_STDSORT:
							cout << "Quick_StdSort";
							break;

						case WIZARD_MERGE_R:
							cout << "Merge_R";
							break;

						case WIZARD_MERGE_NON:
							cout << "Merge_Non";
							break;

						case WIZARD_MERGE_NAT:
							cout << "Merge_Nat";
							break;

						case WIZARD_HEAPSORT:
							cout << "Heap_Sort";
							break;

						case WIZARD_SELECTION:
							cout << "Selection";
							break;

						case WIZARD_BUBBLE:
							cout << "Bubble";
							break;

					} // end of switch

					cout << " / ";
					cout << "Wizard:";
					
					switch (ValueIDX)
					{
						case WIZARD_INCREASE:
							cout << "Increase";
							break;

						case WIZARD_DECREASE:
							cout << "Decrease";
							break;

						case WIZARD_RANDOM:
							cout << "Random";
							break;

						default:
							break;

					} // end of switch

					cout << "\n";
					
				} // end of for

			} // end of for

		} // end of for

	} // end of for

	// 종료시간
	endTime = GetTimer( );
	jvar->appendPrintMemo(FinishTimer(startTime, endTime));

	// 정상 출력
	cout << jvar->GetPrintMemo( );

	// 출력
	int result = FileMemoExtract( "auto_analysis.txt" , jvar->GetPrintMemo ( ) );

	// 출력 메시지
	cout << result;

	// 초기화
	jvar->erase();

}