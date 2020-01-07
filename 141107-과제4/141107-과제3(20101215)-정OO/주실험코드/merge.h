
/// MergeSort Framework


template <>
void Sort<std::string>::MergeSort(std::string* data, const int left, const int right, const int Type){

	switch (Type)
	{

		case TYPE_R_MERGE:
			MergeSort_Recur(data, left, right - 1);
			break;

		case TYPE_N_MERGE:
			MergeSort_Non(data, left, right, right + 1);
			break;

		case TYPE_NAT_MERGE:  // 완료
			MergeSort_Natural(data, right);
			break;

		default:
			break;

	} // end of switch

}

template <>
void Sort<double>::MergeSort(double* data, const int left, const int right, const int Type){

	switch (Type)
	{

		case TYPE_R_MERGE:
			MergeSort_Recur(data, left, right - 1);
			break;

		case TYPE_N_MERGE:
			MergeSort_Non(data, left, right, right + 1);
			break;

		case TYPE_NAT_MERGE:  // 완료
			MergeSort_Natural(data, right);
			break;

		default:
			break;

	} // end of switch

}

template <typename T>
void Sort<T>::MergeSort(T* data, const int left, const int right, const int Type){

	switch (Type)
	{

		case TYPE_R_MERGE:
			MergeSort_Recur(data, left, right - 1);
			break;

		case TYPE_N_MERGE:
			MergeSort_Non(data, left, right, right + 1);
			break;

		case TYPE_NAT_MERGE:  // 완료
			MergeSort_Natural(data, right);
			break;

		default:
			break;

	} // end of switch

}
// End of Framework Merge

/// Merge_Recur

template <>
void Sort<std::string>::MergeSort_Recur(std::string* data, const int left, const int right){

	if (right - left != 0)
	{
		int middle = (left + right) / 2;

		MergeSort_Recur(data, left, middle);
		MergeSort_Recur(data, middle + 1, right);

		Merge(data, left, middle, right);

	} // end of if

}

template <>
void Sort<double>::MergeSort_Recur(double* data, const int left, const int right){

	if (right - left != 0)
	{
		int middle = (left + right) / 2;

		MergeSort_Recur(data, left, middle);
		MergeSort_Recur(data, middle + 1, right);

		Merge(data, left, middle, right);

	} // end of if

}

template <typename T>
void Sort<T>::MergeSort_Recur(T* data, const int left, const int right){

	if (right - left != 0)
	{
		int middle = (left + right) / 2;

		MergeSort_Recur(data, left, middle);
		MergeSort_Recur(data, middle + 1, right);

		Merge(data, left, middle, right);
	
	} // end of if

}
// End of Merge_Recur

/// Merge(합병)


template <>
void Sort<std::string>::Merge(std::string* data, const int Start, const int Mid, const int End){

	int i = Start;
	int LeftIDX = Start;
	int RightIDX = Mid + 1;
	int DestIDX = 0;

	std::string* DestArr = new std::string[End - Start + 1];

	// 단일 정복 구현
	while (LeftIDX <= Mid && RightIDX <= End)
	{
		if (data[LeftIDX].compare(data[RightIDX]) == -1)
			DestArr[DestIDX] = data[LeftIDX++];
		else
			DestArr[DestIDX] = data[RightIDX++];

		DestIDX++;
	} // end of while

	while (LeftIDX <= Mid)
		DestArr[DestIDX++] = data[LeftIDX++];

	while (RightIDX <= End)
		DestArr[DestIDX++] = data[RightIDX++];

	DestIDX = 0;

	while (i <= End)
	{
		data[i] = DestArr[DestIDX++];
		i++;
	} // end of while

	delete[] DestArr;

}

template <>
void Sort<double>::Merge(double* data, const int Start, const int Mid, const int End){

	int i = Start;
	int LeftIDX = Start;
	int RightIDX = Mid + 1;
	int DestIDX = 0;

	double* DestArr = new double[End - Start + 1];

	// 단일 정복 구현
	while (LeftIDX <= Mid && RightIDX <= End)
	{
		if (CompareDoubleAbsoulte(data[LeftIDX], data[RightIDX]) == -1)
			DestArr[DestIDX] = data[LeftIDX++];
		else
			DestArr[DestIDX] = data[RightIDX++];

		DestIDX++;
	} // end of while

	while (LeftIDX <= Mid)
		DestArr[DestIDX++] = data[LeftIDX++];

	while (RightIDX <= End)
		DestArr[DestIDX++] = data[RightIDX++];

	DestIDX = 0;

	while (i <= End)
	{
		data[i] = DestArr[DestIDX++];
		i++;
	} // end of while

	delete DestArr;

}

template <typename T>
void Sort<T>::Merge(T* data, const int Start, const int Mid, const int End){

	int i = Start;
	int LeftIDX = Start;
	int RightIDX = Mid + 1;
	int DestIDX = 0;

	T* DestArr = new T[End - Start + 1];

	// 단일 정복 구현
	while (LeftIDX <= Mid && RightIDX <= End)
	{
		if (data[LeftIDX] < data[RightIDX])
			DestArr[DestIDX] = data[LeftIDX++];
		else
			DestArr[DestIDX] = data[RightIDX++];

		DestIDX++;
	} // end of while

	while (LeftIDX <= Mid)
		DestArr[DestIDX++] = data[LeftIDX++];

	while (RightIDX <= End)
		DestArr[DestIDX++] = data[RightIDX++];

	DestIDX = 0;

	while (i <= End)
	{
		data[i] = DestArr[DestIDX++];
		i++;
	} // end of while

	delete DestArr;

}
// End of Merge(합병)

/// MergeSort_Non


template <>
void Sort<std::string>::MergeSort_Non(std::string* data, const int left, const int right, const int size){

	int i, j, k;

	int step = 8; // Merge의 기준을 초기 step 8로 잡음
	int nextStep, middle;

	std::string* buffer = new std::string[right + 1]; // 임시공간
	std::string temp;

	int uleft = left;
	int uright = right;

	// step 이하 삽입정렬 
	for (k = 0; k < size - 1; k += step)
	{
		uright = k + step - 1;
		if (uright  > size - 1)
			uright = size - 1;

		for (j = k + 1; j <= uright; j++)
		{
			temp = data[j];
			for (i = j - 1; i >= k && data[i].compare(temp) == 1; i--);
			i++;
			memmove(&data[i + 1], &data[i], sizeof(std::string)*(j - i));
			data[i] = temp;
		}
	}

	for (; step<size; step = nextStep)
	{
		nextStep = step << 1;

		for (uleft = 0; uleft <size; uleft += nextStep)
		{
			uright = uleft + nextStep - 1;

			if (uleft + step > size)
				break;

			if (uright > size - 1)
				uright = size - 1;

			middle = step + uleft - 1;

			// 크기 비교 후 Buffer에 자료 저장(Merge to Buffer)
			for (i = uleft, j = middle + 1, k = uleft; i <= middle && j <= uright;)
			{
				buffer[k++] = (data[i].compare(data[j]) == -1 ? data[i++] : data[j++]);
			} // end of for

			// 자료 잔량 처리
			while (i <= middle)
				buffer[k++] = data[i++];

			while (j <= right)
				buffer[k++] = data[j++];

			// 데이터 합병
			memcpy(&data[uleft], &buffer[uleft], (uright - uleft + 1)*sizeof(double));
		}

	} // end of for

}

template <>
void Sort<double>::MergeSort_Non(double* data, const int left, const int right, const int size){

	int i, j, k;

	int step = 8; // Merge의 기준을 초기 step 8로 잡음
	int nextStep, middle;

	double* buffer = new double[right + 1]; // 임시공간
	double temp;

	int uleft = left;
	int uright = right;

	// step 이하 삽입정렬 
	for (k = 0; k < size - 1; k += step)
	{
		uright = k + step - 1;
		if (uright  > size - 1)
			uright = size - 1;

		for (j = k + 1; j <= uright; j++)
		{
			temp = data[j];
			for (i = j - 1; i >= k &&  CompareDoubleAbsoulte(data[i], temp) == 1; i--);
			i++;
			memmove(&data[i + 1], &data[i], sizeof(double)*(j - i));
			data[i] = temp;
		}
	}

	for (; step<size; step = nextStep)
	{
		nextStep = step << 1;

		for (uleft = 0; uleft <size; uleft += nextStep)
		{
			uright = uleft + nextStep - 1;

			if (uleft + step > size)
				break;

			if (uright > size - 1)
				uright = size - 1;

			middle = step + uleft - 1;

			// 크기 비교 후 Buffer에 자료 저장(Merge to Buffer)
			for (i = uleft, j = middle + 1, k = uleft; i <= middle && j <= uright;)
			{
				buffer[k++] = (CompareDoubleAbsoulte(data[i], data[j]) == -1 ? data[i++] : data[j++]);
			} // end of for

			// 자료 잔량 처리
			while (i <= middle)
				buffer[k++] = data[i++];

			while (j <= right)
				buffer[k++] = data[j++];

			// 데이터 합병
			memcpy(&data[uleft], &buffer[uleft], (uright - uleft + 1)*sizeof(double));
		}

	} // end of for

}

template <typename T>
void Sort<T>::MergeSort_Non(T* data, const int left, const int right, const int size){
	
	int i, j, k;
	
	int step = 8; // Merge의 기준을 초기 step 8로 잡음
	int nextStep, middle;
	
	T* buffer = new T[right + 1]; // 임시공간
	T temp;

	int uleft = left;
	int uright = right;

	// step 이하 삽입정렬 
	for (k = 0; k < size - 1; k += step)
	{
		uright = k + step - 1;
		if (uright  > size - 1)
			uright = size - 1;

		for (j = k + 1; j <= uright; j++)
		{
			temp = data[j];
			for (i = j - 1; i >= k&&data[i]>temp; i--);
			i++;
			memmove(&data[i + 1], &data[i], sizeof(T)*(j - i));
			data[i] = temp;
		}
	}

	for (; step<size; step = nextStep)
	{
		nextStep = step << 1;

		for (uleft = 0; uleft <size; uleft += nextStep)
		{
			uright = uleft + nextStep - 1;

			if (uleft + step > size)
				break;

			if (uright > size - 1)
				uright = size - 1;

			middle = step + uleft - 1;

			// 크기 비교 후 Buffer에 자료 저장(Merge to Buffer)
			for (i = uleft, j = middle + 1, k = uleft; i <= middle && j <= uright;)
			{
				buffer[k++] = (data[i] < data[j] ? data[i++] : data[j++]);
			} // end of for

			// 자료 잔량 처리
			while (i <= middle)
				buffer[k++] = data[i++];

			while (j <= right)
				buffer[k++] = data[j++];

			// 데이터 합병
			memcpy(&data[uleft], &buffer[uleft], (uright - uleft + 1)*sizeof(T));
		}

	} // end of for

} 
// End of MergeSort_Non

/// MergeSort_Natural

template <>
void Sort<std::string>::MergeSort_Natural(std::string* data, const int n){

	int left = 0;
	int right = n - 1;

	bool issorted = false;

	int mid = 0;
	int uright = right;

	do {
		issorted = true;
		left = 0;

		while (left < right) {

			mid = left;

			while (mid < right &&  data[mid].compare(data[mid + 1]) <= 0)
				mid++;
			// end of while

			uright = mid + 1;

			while (uright == right - 1 || uright < right && data[uright].compare(data[uright + 1]) <= 0)
				uright++;
			// end of while

			if (uright <= right) {
				Merge(data, left, mid, uright);
				issorted = false;
			} // end of if

			left = uright + 1;
		}

	} while (!issorted); // 정렬 여부 판별
}

template <>
void Sort<double>::MergeSort_Natural(double* data, const int n){

	int left = 0;
	int right = n - 1;

	bool issorted = false;

	int mid = 0;
	int uright = right;

	do {
		issorted = true;
		left = 0;

		while (left < right) {

			mid = left;

			while (mid < right &&  CompareDoubleAbsoulte(data[mid], data[mid + 1]) <= 0)
				mid++;
			// end of while

			uright = mid + 1;

			while (uright == right - 1 || uright < right && CompareDoubleAbsoulte(data[uright], data[uright + 1]) <= 0)
				uright++;
			// end of while

			if (uright <= right) {
				Merge(data, left, mid, uright);
				issorted = false;
			} // end of if

			left = uright + 1;
		}

	} while (!issorted); // 정렬 여부 판별
}

template <typename T>
void Sort<T>::MergeSort_Natural(T* data, const int n){

	int left = 0;
	int right = n - 1;

	bool issorted = false;

	int mid = 0;
	int uright = right;

	do {
		issorted = true;
		left = 0;

		while (left < right) {
			
			mid = left;
			
			while (mid < right &&  data[mid] <= data[mid + 1])
				mid++;
			 // end of while
			
			uright = mid + 1;

			while (uright == right - 1 || uright < right && data[uright] <= data[uright + 1])
				uright++;
			// end of while

			if (uright <= right) {
				Merge(data, left, mid, uright);
				issorted = false;
			} // end of if

			left = uright + 1;
		}

	} while (!issorted); // 정렬 여부 판별
}
// End of Merge