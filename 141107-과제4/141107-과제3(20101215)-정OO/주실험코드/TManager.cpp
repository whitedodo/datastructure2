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

	// ��������
	if ( jvar->GetUserType( ) == MANUAL ){

		if ( wizard.TManagerWizard( jvar ) == TRUE )
			Status = TRUE;

	} // end of if

	// �ڵ�ȭ ����
	if ( jvar->GetUserType( ) == AUTO )
		Status = TRUE;

	// ���� ��
	if ( Status == TRUE )
	{
		// �����
		JApp<int> japp;
		LinkedList<int>* plinkedlist;
		pArr = new int[ jvar->GetUserSize( ) + 1 ];
		int datatype = japp.GetDataType( jvar->GetSortType( ) );

		// ����
		pArr = japp.Create( jvar->GetValueType( ), jvar->GetUserSize( ) );
		plinkedlist = japp.ListCreate( pArr, jvar->GetUserSize( ) );
		Node<int>* ptr = plinkedlist->GetFirstNode( );

		// ��� ����(���� ����)
		japp.PrintCreate( ptr, pArr, TYPE_PRINT_OFF, jvar );
		 
		// ����
		japp.SortOfRun( jvar, pArr, plinkedlist->GetFirstNode() );

		// ��� ����(���� ��)
		japp.PrintCreate( ptr, pArr, TYPE_PRINT_ON, jvar );

		// ���������� ��
		if (jvar->GetUserType() == MANUAL)
		{
			// ���
			jvar->SetPrintMemo( japp.PrintTotalCreate( jvar ) );
			japp.PrintView( jvar->GetPrintMemo( ) );

			// ������ ����
			jvar->SetQuestion( wizard.ChooseOfQuestion( ) );

			// ����
			if ( jvar->GetQuestion( ) == WIZARD_SAVE )
				japp.ExtractFile( jvar );
			
		} // end of if

		// �ڵ������� ��
		if ( jvar->GetUserType( ) == AUTO )
			japp.CreateAutomatric( jvar );

		// �Ұ�
		delete pArr;
		delete plinkedlist;

		pArr = NULL;
		plinkedlist = NULL;
	} // end of if
}

void TaskManager::MenuOfDouble(double* pArr, JUserVar* jvar){

	Wizard wizard;
	int Status = FALSE;

	// ��������
	if ( jvar->GetUserType( ) == MANUAL ){

		if ( wizard.TManagerWizard( jvar ) == TRUE )
			Status = TRUE;
		
	} // end of if

	// �ڵ�ȭ ����
	if ( jvar->GetUserType( ) == AUTO )
		Status = TRUE;


	// ���� ��
	if (Status == TRUE)
	{
		JApp<double> japp;
		LinkedList<double>* plinkedlist;

		jvar->SetDataType ( japp.GetDataType( jvar->GetSortType( ) ) );

		// ����
		pArr = japp.Create( jvar->GetValueType( ), jvar->GetUserSize( ) );
		plinkedlist = japp.ListCreate( pArr, jvar->GetUserSize( ) );
		Node<double>* ptr = plinkedlist->GetFirstNode( );

		// ��� ����(���� ����)
		japp.PrintCreate( ptr, pArr, TYPE_PRINT_OFF, jvar );

		// ����
		japp.SortOfRun( jvar, pArr, plinkedlist->GetFirstNode( ) );

		// ��� ����(���� ��)
		japp.PrintCreate( ptr, pArr, TYPE_PRINT_ON, jvar );
		

		// ���������� ��
		if ( jvar->GetUserType( ) == MANUAL )
		{
			// ���
			jvar->SetPrintMemo( japp.PrintTotalCreate( jvar ) );
			japp.PrintView( jvar->GetPrintMemo( ) ) ;

			// ������ ����
			jvar->SetQuestion ( wizard.ChooseOfQuestion( ) );

			// ����
			if ( jvar->GetQuestion( ) == WIZARD_SAVE )
				japp.ExtractFile( jvar );

		} // end of if

		// �ڵ������� ��
		if ( jvar->GetUserType( ) == AUTO )
			japp.CreateAutomatric( jvar );

		// �Ұ�
		delete pArr;
		delete plinkedlist;

		pArr = NULL;
		plinkedlist = NULL;

	}
}

void TaskManager::MenuOfPolygon(int* pArr, JUserVar* jvar){

	Wizard wizard;
	int Status = FALSE;

	// ��������
	if ( jvar->GetUserType( ) == MANUAL ){

		// Wizard
		if ( wizard.TManagerWizard( jvar ) == TRUE )
			Status = TRUE;

	} // end of if

	// �ڵ�ȭ ����
	if ( jvar->GetUserType( ) == AUTO )
		Status = TRUE;

	// ���� ��
	if ( Status == TRUE )
	{
		JApp<double> japp;
		JTime* startTime = NULL, *endTime = NULL;
		JPolygonList<double>* jpolylist;
		LinkedList<double>* plinkedlist;
		double* oriArr, *chgArr;

		// ������(Polygon)
		jvar->SetCriticType(POLY_TYPE_WEIGHT);

		// �м� ���� ��ġ
		japp.SetWhereAnalysis( ANALYSIS_OUTER );

		// ����
		pArr = japp.IndexCreate( jvar->GetUserSize() );
		jpolylist = japp.PolyCreateList( jvar->GetValueType(),  jvar->GetUserSize( ) );

		oriArr = japp.PolyCreateView( jpolylist, POLY_TYPE_WEIGHT, jvar->GetUserSize( ) );
		chgArr = japp.PolyCreateView( jpolylist, POLY_TYPE_WEIGHT, jvar->GetUserSize( ) );

		plinkedlist = japp.ListCreate( oriArr, jvar->GetUserSize( ) );

		Node<double>* ptr = plinkedlist->GetFirstNode();

		// ��� ����(���� ����)
		japp.PrintCreate( jpolylist, pArr, TYPE_PRINT_OFF, jvar );

		// �м� ���� - OUTER�� ��
		if ( japp.GetWhereAnalysis() == ANALYSIS_OUTER )
			startTime = GetTimer();

		// ����
		japp.SortOfRun( jvar , chgArr, plinkedlist->GetFirstNode( ) );

		japp.IndexToMerge( pArr, oriArr, chgArr, jvar->GetUserSize( ) );

		// �м� ����
		if ( japp.GetWhereAnalysis( ) == ANALYSIS_OUTER )
		{
			endTime = GetTimer( );
			japp.CreateAnalysis( startTime, endTime , jvar );
		}

		// ��� ����(���� ����)
		japp.PrintCreate( jpolylist, pArr, TYPE_PRINT_ON, jvar );

		// ���������� ��
		if ( jvar->GetUserType() == MANUAL )
		{
			// ���
			jvar->SetPrintMemo( japp.PrintTotalCreate( jvar ) );
			japp.PrintView( jvar->GetPrintMemo( ) );

			// ������ ����
			jvar->SetQuestion( wizard.ChooseOfQuestion() );

			// ����
			if ( jvar->GetQuestion() == WIZARD_SAVE )
				japp.ExtractFile( jvar );

		}

		// �ڵ������� ��
		if ( jvar->GetUserType( ) == AUTO )
			japp.CreateAutomatric( jvar );

		// �Ұ�
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

	// ���� ���� ����
	if ( japp.IsFileLoading( ) == FALSE )
	{
		std::cout << "�̸� ���� ������ �������� �ʽ��ϴ�." << std::endl;
		Cmd(CMD_DELAY, 3);
		return;
	}

	// ��������
	if ( jvar->GetUserType( ) == MANUAL ){
		 
		if (wizard.TManagerWizard(jvar) == TRUE)
			Status = TRUE;

	} // end of if

	// �ڵ�ȭ ����
	if (jvar->GetUserType() == AUTO)
		Status = TRUE;


	// ���� ��
	if (Status == TRUE)
	{
		LinkedList<std::string>* plinkedlist = NULL;

		jvar->SetDataType( japp.GetDataType ( jvar->GetSortType( ) ) );
		pArr = NULL;

		// ����
		pArr = japp.Create( jvar->GetValueType() , jvar->GetUserSize( ) );
		plinkedlist = japp.ListCreate( pArr, jvar->GetUserSize() );

		Node<std::string>* ptr = NULL;
		ptr = plinkedlist->GetFirstNode( );

		// ��� ����(���� ����)
		japp.PrintCreate( ptr, pArr, TYPE_PRINT_OFF, jvar );

		// ����
		japp.SortOfRun( jvar , pArr, ptr);
		ptr = plinkedlist->GetFirstNode( );

		// ��� ����(���� ����)
		japp.PrintCreate( ptr, pArr , TYPE_PRINT_ON, jvar );

		// ���������� ��
		if ( jvar->GetUserType( ) == MANUAL )
		{
			// ���
			std::string printdata = japp.PrintTotalCreate( jvar );
			japp.PrintView( printdata );
			jvar->SetPrintMemo( printdata );

			// ������ ����
			jvar->SetQuestion( wizard.ChooseOfQuestion( ) );

			// ����
			if ( jvar->GetQuestion( ) == WIZARD_SAVE )
				japp.ExtractFile( jvar );

		}

		// �ڵ������� ��
		if ( jvar->GetUserType() == AUTO )
			japp.CreateAutomatric(jvar);

		// �Ұ�
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

	// ���� �Է�
	jvar->SetUserType(AUTO);

	// �޴� ����
	for (int Choose = MENU_SIZE_MIN; Choose <= MENU_SIZE_MAX; Choose++)
	{
		// Value Type
		for (int ValueIDX = WIZARD_VALUETYPE_MIN; ValueIDX <= WIZARD_VALUETYPE_MAX; ValueIDX++){

			jvar->SetValueType( ValueIDX );

			// ���� ǥ��
			for (int SampleIDX = SAMPLE_SIZE_MIN; SampleIDX < SAMPLE_SIZE_MAX; SampleIDX++){

				jvar->SetUserSize( SizeArr[SampleIDX] );

				// ���� ����
				for (int SortIDX = WIZARD_SORT_MIN + 1; SortIDX <= WIZARD_SORT_MAX; SortIDX++){

					jvar->SetSortType( SortIDX );

					cout << count++;
					cout << "�� / ";

					// Menu of Switch
					switch (Choose)
					{
						case MENU_INTEGER:
							jvar->appendPrintMemo("^Integer��^\n");
							cout << "Integer��:";
							MenuOfInteger( intArr, jvar );
							break;

						case MENU_DOUBLE:
							jvar->appendPrintMemo("^Double��^\n");
							cout << "Double��:";

							MenuOfDouble( dblArr, jvar );
							break;

						case MENU_POLYGON:
							jvar->appendPrintMemo("^Polygon Double��^\n");
							cout << "Polygon Double��:";
							MenuOfPolygon(intArr, jvar);
							break;

						case MENU_STRING:
							jvar->appendPrintMemo("^String��^\n");
							cout << "String��:";
							MenuOfString(stringArr, jvar);
							break;

						default:
							break;

					} // end of switch

					cout << "ũ��:" << jvar->GetUserSize();
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

	// ����ð�
	endTime = GetTimer( );
	jvar->appendPrintMemo(FinishTimer(startTime, endTime));

	// ���� ���
	cout << jvar->GetPrintMemo( );

	// ���
	int result = FileMemoExtract( "auto_analysis.txt" , jvar->GetPrintMemo ( ) );

	// ��� �޽���
	cout << result;

	// �ʱ�ȭ
	jvar->erase();

}