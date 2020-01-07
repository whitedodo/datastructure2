
template <typename T>
JApp<T>::JApp(){
	PositionAnalysis = ANALYSIS_INNER;
}

template <typename T>
JApp<T>::~JApp(){

}

template <typename T>
int JApp<T>::GetWhereAnalysis(){
	return PositionAnalysis;
}

template <typename T>
void JApp<T>::SetWhereAnalysis(int sw){
	PositionAnalysis = sw;
}

template <typename T>
std::string JApp<T>::PrintAnalysis(){
	return print_analysis_estimate;
}

template <typename T>
void JApp<T>::CreateAutomatric(JUserVar* jvar){

	std::string print_Subject;

	jvar->appendPrintMemo( "--------------------------------------\n" );

	switch (jvar->GetValueType())
	{
		case WIZARD_INCREASE:
			print_Subject.append( "!������!" );
			break;

		case WIZARD_DECREASE:
			print_Subject.append( "!������!" );
			break;

		case WIZARD_RANDOM:
			print_Subject.append( "!������!" );
			break;

	} // end of switch

	print_Subject.append( "ũ��:@" );
	print_Subject.append( JPatch::to_string( jvar->GetUserSize( ) ) );
	print_Subject.append( "@" );
	print_Subject.append( "\n" );
	print_Subject.append( "--------------------------------------\n" );

	jvar->appendPrintMemo( print_Subject );
	jvar->appendPrintMemo( "#" );
	jvar->appendPrintMemo( jvar->GetPrintSortTitle() );			// ���� ����
	jvar->appendPrintMemo( "#" );
	jvar->appendPrintMemo( "\n" );
	jvar->appendPrintMemo( jvar->GetPrintAnalysisStart() );
	jvar->appendPrintMemo( "\n" );
	jvar->appendPrintMemo( jvar->GetPrintAnalysisEnd() );
	jvar->appendPrintMemo( "\n" );
	jvar->appendPrintMemo( jvar->GetPrintAnalysisEstimate() );	// �м� ���
	jvar->appendPrintMemo( "\n\n" );

}

template <>
LinkedList<std::string>* JApp<std::string>::ListCreate(int valuetype, const int size){

	LinkedList<std::string>* list = new LinkedList<std::string>();
	float x, num, result;

	for (int i = 0; i < size; i++)
	{

		switch (valuetype)
		{
		case WIZARD_INCREASE:
			list->Insert( JPatch::to_string( ( i ) ) );
			break;

		case WIZARD_DECREASE:
			list->Insert( JPatch::to_string( size - i ) );
			break;

		case WIZARD_RANDOM:

			num = pow((float)RandBox(TYPE_RAND_MID), -1);
			x = pow((float)RandBox(TYPE_RAND_MID), -1); // float Random
			result = x * (float)num;

			list->Insert( JPatch::to_string( result ) );

			break;

		} // end of switch


	} // end of for

	return list;

}

template <typename T>
LinkedList<T>* JApp<T>::ListCreate(int valuetype, const int size){

	LinkedList<T>* list = new LinkedList<T>();
	float x, num, result;

	for (int i = 0; i < size; i++)
	{

		switch (valuetype)
		{
			case WIZARD_INCREASE:
				list->Insert(i);
				break;

			case WIZARD_DECREASE:
				list->Insert(size - i);
				break;

			case WIZARD_RANDOM:

				num = pow ( (float) RandBox(TYPE_RAND_MID), -1 );
				x = pow ( (float) RandBox(TYPE_RAND_MID), -1 ); // float Random
				result = x * (float) num ;

				list->Insert( ( T ) result );

				break;

		} // end of switch


	} // end of for

	return list;

}


template <>
std::string* JApp<std::string>::Create(int valuetype, const int size){

	int familyidx = 0, nameidx = 0;
	int cnt = 0;

	// ���� �̸� ���
	std::string RandomName;

	// ���� ���� ����
	std::string familyname = GetTypeOfFilename(TYPE_FAMILY_NAME);
	std::vector<std::string> familynameVec = GetLoadName(TYPE_FAMILY_NAME, familyname);
	std::string fullname = GetTypeOfFilename(TYPE_FULL_NAME);
	std::vector<std::string> fullnameVec = GetLoadName(TYPE_FULL_NAME, fullname);

	// �ʱ�ȭ
	srand((unsigned int)time(NULL)); // Seed �� ���

	// ����
	std::string* Arr = new std::string[size + 1];

	// Ÿ�Կ� �°� �ʱⰪ ��������
	if (WIZARD_INCREASE == valuetype)
	{
		familyidx = (int)(familynameVec.size() - 1);
		nameidx = (int)(fullnameVec.size() - 1);
	}

	for (int i = 0; i < size; i++){

		switch (valuetype)
		{
		case WIZARD_INCREASE:

			// ����(��) �̸� ���� �ʰ�
			if (familyidx >= (int)(familynameVec.size() - 1))
				familyidx = 0;

			// ��ü �̸� �ʱ�ȭ
			if (nameidx >= (int)(fullnameVec.size() - 1))
			{
				nameidx = 0;
				familyidx++;
			}

			nameidx++;
			break;

		case WIZARD_DECREASE:

			// ��ü �̸� �ʱ�ȭ
			if (nameidx > 0)
				nameidx--;
			else
			{
				nameidx = (fullnameVec.size() - 1);
				familyidx--;
			}

			// ����(��) �̸� ���� �ʰ�
			if (familyidx < 0)
				familyidx = (familynameVec.size() - 1);

			break;

		case WIZARD_RANDOM:
			familyidx = (rand() % (familynameVec.size() - 1)) + 0;
			nameidx = (rand() % (fullnameVec.size() - 1)) + 0;

			break;

		} // end of switch

		RandomName.clear();
		RandomName.append(familynameVec[familyidx]);
		RandomName.append(fullnameVec[nameidx]);

		Arr[i] = RandomName;
	}

	return Arr;

}

template <>
int* JApp<int>::Create(int valuetype, const int size){

	int* arr = new int[size + 1];
	int num, result;

	for (int i = 0; i < size; i++)
	{

		switch (valuetype)
		{
		case WIZARD_INCREASE:
			arr[i] = i;
			break;

		case WIZARD_DECREASE:
			arr[i] = size - i;
			break;

		case WIZARD_RANDOM:
			num = RandBox(TYPE_RAND_MID);
			result = num;
			arr[i] = result;

			break;

		} // end of switch

	} // end of for

	return arr;

}

template <typename T>
T* JApp<T>::Create(int valuetype, const int size){

	T* arr = new T[size + 1];
	double x, num, result;

	for (int i = 0; i < size; i++)
	{

		switch (valuetype)
		{
			case WIZARD_INCREASE:
				arr[i] = i;
				break;

			case WIZARD_DECREASE:
				arr[i] = size - i;
				break;

			case WIZARD_RANDOM:
				num = RandBox (TYPE_RAND_MID);
				x = (double) pow( (float) RandBox (TYPE_RAND_MID), -1); // float Random
				result = x * num;
				arr[i] = (T) result;

				break;

		} // end of switch

	} // end of for

	return arr;

}


template <typename T>
int* JApp<T>::IndexCreate(const int size){

	int* pArr = new int[size + 1];
	
	// index �ʱ�ȭ
	for (int i = 0; i < size; i++)
		pArr[i] = i;

	return pArr;
}


template <>
LinkedList<std::string>* JApp<std::string>::ListCreate(std::string* data, const int size){

	LinkedList<std::string>* list = new LinkedList<std::string>();

	for (int i = 0; i < size; i++)
		list->Insert(data[i]);

	return list;
}

template <typename T>
LinkedList<T>* JApp<T>::ListCreate(T* data, const int size){

	LinkedList<T>* list = new LinkedList<T>();

	for (int i = 0; i < size; i++)
		list->Insert(data[i]);
	
	return list;
}

template <typename T>
void JApp<T>::SortOfRun(JUserVar* jvar, T* data, Node<T>* ndata)
{
	Sort<T> sort;
	int startnum, endnum;
	JTime* startTime = NULL, *endTime = NULL;
	std::string print_sort_title;

	// �м����
	if (GetWhereAnalysis() == ANALYSIS_INNER){
		startTime = GetTimer();
	}

	Cmd(CMD_DELAY, 0);

	// �޴�
	switch ( jvar->GetSortType() )
	{
		case WIZARD_BINARY_SORT:	// 1�� �޴�(�̿� ���� ����)
			print_sort_title = "BINARY INSERT SORT";
			endnum = jvar->GetUserSize();
			sort.BinaryInsertSort(data, endnum);
			break;

		case WIZARD_LINKED_SORT:	// 2�� �޴�(���� ���� ����)
			print_sort_title = "LINKED INSERT SORT";
			sort.LinkedInsertSort(ndata);
			break;

		case WIZARD_QUICK_R:		// 3�� Quick(Recursive)
			print_sort_title = "Quick(Recursive)";
			startnum = 0;
			endnum = jvar->GetUserSize() - 1;
			sort.QuickSort(data, startnum, endnum, TYPE_R_QUICK);
			break;

		case WIZARD_QUICK_R_MEDIAN:	// 4�� Quick(Recursive Median)
			print_sort_title = "Quick(Recursive Median)";
			startnum = 0;
			endnum = jvar->GetUserSize() - 1;
			sort.QuickSort(data, startnum, endnum, TYPE_R_MEDIAN_QUICK);
			break;

		case WIZARD_QUICK_N_MEDIAN:	// 5�� Quick(Non-Recursive Median)
			print_sort_title = "Quick(Non-Recursive Median)";
			startnum = 0;
			endnum = jvar->GetUserSize();
			sort.QuickSort(data, startnum, endnum, TYPE_N_MEDIAN_QUICK);
			break;

		case WIZARD_QUICK_STDSORT:	// 6�� Quick(Std::sort)
			print_sort_title = "Quick-Std-sort";
			startnum = 0;
			endnum = jvar->GetUserSize();
			sort.QuickSort(data, startnum, endnum, TYPE_STD_QUICK);
			break;

		case WIZARD_MERGE_R:		// 7�� Merge(Recursive)
			print_sort_title = "Merge(Recursive)";
			startnum = 0;
			endnum = jvar->GetUserSize();
			sort.MergeSort(data, startnum, endnum, TYPE_R_MERGE);
			break;

		case WIZARD_MERGE_NON:		// 8�� Merge(Non-Recursive)
			print_sort_title = "Merge(Non-Recursive)";
			startnum = 0;
			endnum = jvar->GetUserSize() - 1;
			sort.MergeSort(data, startnum, endnum, TYPE_N_MERGE);
			break;

		case WIZARD_MERGE_NAT:		// 9�� Merge(Natural)
			print_sort_title = "Merge(Natural)";
			startnum = 0;
			endnum = jvar->GetUserSize();
			sort.MergeSort(data, startnum, endnum, TYPE_NAT_MERGE);
			break;

		case WIZARD_HEAPSORT:		// 10�� Heap Sort
			print_sort_title = "Heap Sort";
			startnum = 0;
			endnum = jvar->GetUserSize() - 1;
			sort.HeapSort(data, endnum);
			break;

		case WIZARD_SELECTION:		// 11�� Selection
			print_sort_title = "Selection Sort";
			endnum = jvar->GetUserSize();
			sort.SelectionSort(data, endnum);
			break;

		case WIZARD_BUBBLE:			// 12�� Bubble
			print_sort_title = "Bubble Sort";
			endnum = jvar->GetUserSize();
			sort.BubbleSort(data, endnum);
			break;

		default:
			break;

	} // end of switch
	
	print_sort_title.append( "-" );
	print_sort_title.append( JPatch::to_string( jvar->GetUserSize() ) );

	jvar->SetPrintSortTitle( print_sort_title );

	// Inner ���� �Ǵ�
	if (GetWhereAnalysis() == ANALYSIS_INNER){
		endTime = GetTimer();
		CreateAnalysis(startTime, endTime, jvar);
	}
}

template <typename T>
int JApp<T>::GetDataType(const int sorttype){

	int result = FALSE;

	// ���� ����
	switch (sorttype)
	{
		case WIZARD_LINKED_SORT: // ���� ���� ����
			result = PRINT_LINKED;
			break;

		default:
			result = PRINT_NORMAL;
			break;

	} // end of switch

	return result;
}


template <typename T>
std::string JApp<T>::PrintTotalCreate(JUserVar* jvar){

	std::string result;
	std::string createDate;

	// ��¥ ����
	createDate = GetToday(YYYYMMDD);
	createDate.append(" ");
	createDate.append(GetToday(HHMM));

	// �˰��� ����
	result.append( "���� ����:" );
	result.append( jvar->GetPrintSortTitle( ) );
	result.append( "\n" );

	// ����
	result.append( "��� ���� / " );
	result.append( createDate );
	
	// ����
	result.append( "\n\n" );
	result.append( jvar->GetPrintOffTitle( ) );
	result.append( jvar->GetPrintOffMemo());
	result.append( "\n" );
	result.append( jvar->GetPrintOnTitle( ) );
	result.append( jvar->GetPrintOnMemo( ) );

	// �м�
	result.append( "�м� ���� / " );
	result.append( createDate );
	result.append("\n");
	result.append( jvar->GetPrintAnalysisStart( ) );
	result.append( "\n" );
	result.append( jvar->GetPrintAnalysisEnd( ) );
	result.append( "\n" );
	result.append( jvar->GetPrintAnalysisEstimate( ) );
	result.append( "\n" );


	return result;
}

template <typename T>
void JApp<T>::PrintView(std::string printdata){
	std::cout << printdata;
}

template <typename T>
void JApp<T>::ExtractFile( JUserVar* jvar ){

	std::string subject;
	std::string filename;

	//std::cout << "������ ���ϸ��� �Է��ϼ��� : ";

	//std::cin.clear();
	//std::cin.sync();
	//std::getline(std::cin, subject);
	
	subject.append( jvar->GetPrintSortTitle( ) );

	// ���ϸ� ����
	filename = CreateFileName(subject);

	// ���� ����
	if (FileMemoExtract(filename, jvar->GetPrintMemo() ) == FALSE)
		std::cout << "���⿡ �����߽��ϴ�." << std::endl;
	else
	{
		std::cout << "���⿡ �����߽��ϴ�." << std::endl;
		std::cout << "������ġ :";
		std::cout << filename << std::endl;
	}

	// �ʱ�ȭ
	jvar->erase();

	Cmd(CMD_DELAY, 1);

}