
/// Quick Sort

template <>
void Sort<std::string>::QuickSort(std::string* data, const int left, const int right, int Type){

	switch (Type)
	{
	case TYPE_R_QUICK:
		QuickSort_Recur(data, left, right);
		break;

	case TYPE_R_MEDIAN_QUICK:
		QuickSort_MedianRecur(data, left, right);
		break;

	case TYPE_N_MEDIAN_QUICK:
		QuickSort_Non(data, right);
		break;

	case TYPE_STD_QUICK:
		std::sort(data, data + (right + 1));
		break;

	default:
		break;

	} // end of switch

}


template <>
void Sort<double>::QuickSort(double* data, const int left, const int right, int Type){

	switch (Type)
	{
		case TYPE_R_QUICK:
			QuickSort_Recur(data, left, right);
			break;

		case TYPE_R_MEDIAN_QUICK:
			QuickSort_MedianRecur(data, left, right);
			break;

		case TYPE_N_MEDIAN_QUICK:
			QuickSort_Non(data, right);
			break;

		case TYPE_STD_QUICK:
			std::sort(data, data + (right + 1));
			break;

		default:
			break;

	} // end of switch

}


template <typename T>
void Sort<T>::QuickSort(T* data, const int left, const int right, int Type){

	switch (Type)
	{
		case TYPE_R_QUICK:
			QuickSort_Recur(data, left, right);
			break;

		case TYPE_R_MEDIAN_QUICK:
			QuickSort_MedianRecur(data, left, right);
			break;

		case TYPE_N_MEDIAN_QUICK:
			QuickSort_Non(data, right);
			break;

		case TYPE_STD_QUICK:
			std::sort(data, data + (right + 1));
			break;

		default:
			break;

	} // end of switch

}


template <>
int Sort<std::string>::FindIndex(std::string* data, std::string pivotValue, int right){

	int pivotIndex = 0;
	int i = 0;
	while (i < right)
	{
		if (data[i].compare(pivotValue) == 0)
		{
			pivotIndex = i;
			break;
		}

		i++;
	}

	return pivotIndex;

}

template <>
int Sort<double>::FindIndex(double* data, double pivotValue, int right){

	int pivotIndex = 0;
	int i = 0;
	while (i < right)
	{
		if (CompareDoubleAbsoulte(data[i], pivotValue) == 0)
		{
			pivotIndex = i;
			break;
		}

		i++;
	}

	return pivotIndex;

}

template <typename T>
int Sort<T>::FindIndex(T* data, T pivotValue, int right){

	int pivotIndex = 0;
	int i = 0;
	while (i < right)
	{
		if (data[i] == pivotValue)
		{
			pivotIndex = i;
			break;
		}

		i++;
	}

	return pivotIndex;

}

template <>
void Sort<std::string>::manualSort(std::string* data, int left, int right){

	int size = right - left + 1;

	if (size <= 1)
		return;

	if (size == 2){

		if (data[left].compare(data[right]) == 1)
			Swap(data, left, right);
		return;

	}
	else
	{
		if (data[left].compare(data[right - 1]) == 1)
			Swap(data, left, right - 1);

		if (data[left].compare(data[right]) == 1)
			Swap(data, left, right);

		if (data[right - 1].compare(data[right]) == 1)
			Swap(data, right - 1, right);

	} // end of if
}

template <>
void Sort<double>::manualSort(double* data, int left, int right){

	int size = right - left + 1;

	if (size <= 1)
		return;
	if (size == 2){

		if (CompareDoubleAbsoulte(data[left], data[right]) == 1)
			Swap(data, left, right);
		return;
		
	}
	else
	{
		if (CompareDoubleAbsoulte(data[left], data[right - 1]) == 1)
			Swap(data, left, right - 1);

		if (CompareDoubleAbsoulte(data[left], data[right]) == 1)
			Swap(data, left, right);

		if (CompareDoubleAbsoulte(data[right - 1], data[right]) == 1)
			Swap(data, right - 1, right);

	} // end of if
}


template <typename T>
void Sort<T>::manualSort(T* data, int left, int right){

	int size = right - left + 1;

	if (size <= 1)
		return;

	if (size == 2){

		if (data[left] > data[right])
			Swap(data, left, right);

		return;
	}
	else
	{
		if (data[left] > data[right - 1])
			Swap(data, left, right - 1);

		if (data[left] > data[right])
			Swap(data, left, right);

		if (data[right - 1] > data[right])
			Swap(data, right - 1, right);

	} // end of if
}


template <>
int Sort<std::string>::partitionIt(std::string* data, int left, int right, std::string pivot){

	int leftidx = left;
	int rightidx = right - 1;

	while (1)
	{
		while (data[++leftidx].compare(pivot) == -1); // end of do while

		while (data[--rightidx].compare(pivot) == 1); // end of do while

		if (leftidx >= rightidx)
			break;
		else
			Swap(data, leftidx, rightidx);

	}
	Swap(data, leftidx, right - 1);
	return leftidx;

}

template <>
int Sort<double>::partitionIt(double* data, int left, int right, double pivot){

	int leftidx = left;
	int rightidx = right - 1;

	while (1)
	{
		while (CompareDoubleAbsoulte(data[++leftidx] , pivot) == -1); // end of do while

		while (CompareDoubleAbsoulte(data[--rightidx], pivot) == 1); // end of do while

		if (leftidx >= rightidx)
			break;
		else
			Swap(data, leftidx, rightidx);

	}
	Swap(data, leftidx, right - 1);
	return leftidx;

}

template <typename T>
int Sort<T>::partitionIt(T* data, int left, int right, T pivot){

	int leftidx = left;
	int rightidx = right - 1;

	while (1)
	{
		while (data[++leftidx] < pivot); // end of do while

		while (data[--rightidx] > pivot); // end of do while

		if (leftidx >= rightidx)
			break;
		else
			Swap(data, leftidx, rightidx);

	}
	Swap(data, leftidx, right - 1);
	return leftidx;

}


template <>
void Sort<std::string>::QuickSort_Recur(std::string* data, const int left, const int right){

	if (left < right){

		int i = left;
		int j = right + 1;
		std::string Pivot;

		Pivot = data[left];

		do
		{
			do{
				i++;
			} while (data[i].compare(Pivot) == 0); // end of do while

			do{
				j--;
			} while (data[j].compare(Pivot) == 1); // end of do while

			if (i < j)
			{
				Swap(data, i, j);
			}// end of if

		} while (i < j); // end of do while

		Swap(data, left, j);

		QuickSort(data, left, j - 1);
		QuickSort(data, j + 1, right);
	}

}

template <>
void Sort<double>::QuickSort_Recur(double* data, const int left, const int right){

	if (left < right){

		int i = left;
		int j = right + 1;
		double Pivot;

		Pivot = data[left];

		do
		{
			do{
				i++;
			} while (CompareDoubleAbsoulte(data[i], Pivot) == 0); // end of do while

			do{
				j--;
			} while (CompareDoubleAbsoulte(data[j], Pivot) == 1); // end of do while

			if (i < j)
			{
				Swap(data, i, j);
			}// end of if

		} while (i < j); // end of do while

		Swap(data, left, j);

		QuickSort(data, left, j - 1);
		QuickSort(data, j + 1, right);
	}

}

template <typename T>
void Sort<T>::QuickSort_Recur(T* data, const int left, const int right){

	if (left < right){

		int i = left;
		int j = right + 1;
		T Pivot;

		Pivot = data[left];

		do
		{
			do{
				i++;
			} while (data[i] < Pivot); // end of do while

			do{
				j--;
			} while (data[j] > Pivot); // end of do while

			if (i < j)
			{
				Swap(data, i, j);
			}// end of if

		} while (i < j); // end of do while

		Swap(data, left, j);

		QuickSort(data, left, j - 1);
		QuickSort(data, j + 1, right);
	}
	
}


template <>
void Sort<std::string>::QuickSort_MedianRecur(std::string* data, const int left, const int right){

	int size = right - left + 1;

	if (size <= 3)
	{
		manualSort(data, left, right);
	}
	else{

		std::string pivot;

		pivot = Median_Pivot(data, left, right);

		int partition = partitionIt(data, left, right, pivot);
		//int pivotIndex = FindIndex(data, pivot, right);

		//std::cout << left << "," << right << "," << size << endl;

		QuickSort_MedianRecur(data, left, partition - 1);
		QuickSort_MedianRecur(data, partition + 1, right);

	}

}


template <>
void Sort<double>::QuickSort_MedianRecur(double* data, const int left, const int right){

	int size = right - left + 1;

	if (size <= 3)
	{
//		cout << "M" << left << "," << right << "," << size << endl;
		manualSort(data, left, right);
	}
	else{

		double pivot;

		pivot = Median_Pivot(data, left, right);

		int partition = partitionIt(data, left, right, pivot);
		//int pivotIndex = FindIndex(data, pivot, right);

		//cout << left << "," << right << "," << size << endl;

		QuickSort_MedianRecur(data, left, partition - 1);
		QuickSort_MedianRecur(data, partition + 1, right);

	}

}

template <typename T>
void Sort<T>::QuickSort_MedianRecur(T* data, const int left, const int right){

	int size = right - left + 1;

	//cout << size << endl;
	if (size <= 3)
	{
	/*	cout << "M" << left << "," << right << "," << size << endl;*/
		manualSort(data, left, right);
	}else{

		T pivot;

		pivot = Median_Pivot(data, left, right);		

		int partition = partitionIt(data, left, right, pivot);

//		cout << left << "," << right << "," << size << endl;*/

		QuickSort_MedianRecur(data, left, partition - 1);
		QuickSort_MedianRecur(data, partition + 1, right);
		
	}

}


template <>
void Sort<std::string>::QuickSort_Non(std::string* data, const int n){

	std::string v, t;
	int i, j;
	int l, r; // 스택에 저장할 구간의 정보
	Stack<int> stack;

	l = 0;
	r = n - 1;

	stack.Push(r);
	stack.Push(l);

	while (stack.Any() != FALSE) {

		l = stack.Pop();
		r = stack.Pop();

		if (r - l + 1 > 3)
		{ // 종료조건 r-l+1은 구간의 길이

			// 가운데 값 선택
			int pivot = (r + l) / 2;
			// data[l], data[pivot], data[r] 세 값 정렬 (Bubble Sort)

			if (data[l].compare(data[pivot]) == 1) {

				v = data[l];
				data[l] = data[pivot];
				data[pivot] = v;

			} // end of if

			if (data[pivot].compare(data[r]) == 1) {

				v = data[pivot];
				data[pivot] = data[r];
				data[r] = v;

			} // end of if

			if (data[l].compare(data[pivot]) == 1) {

				v = data[l];
				data[l] = data[pivot];
				data[pivot] = v;

			} // end of if

			// 중앙값을 a[r-1]과 교환

			v = data[pivot];
			data[pivot] = data[r - 1];
			data[r - 1] = v;

			i = l; // 분할구간은 l+1 ~ r-2
			j = r - 1;

			while (true) {

				while (data[++i].compare(v) == 0);

				while (data[--j].compare(v) == 1);

				if (i >= j) break;

				t = data[i];
				data[i] = data[j];
				data[j] = t;

			} // end of while

			t = data[i];
			data[i] = data[r - 1];
			data[r - 1] = t;

			stack.Push(r);
			stack.Push(i + 1);
			stack.Push(i - 1);
			stack.Push(l);

		}
		else { // 구간크기가 3보다 작다면

			// 가운데 값 선택
			int pivot = (r + l) / 2;
			// data[l], data[pivot], data[r] 세 값 정렬

			if (data[l].compare(data[pivot]) == 1) {

				v = data[l];
				data[l] = data[pivot];
				data[pivot] = v;

			} // end of if

			if (data[pivot].compare(data[r]) == 1) {

				v = data[pivot];
				data[pivot] = data[r];
				data[r] = v;

			} // end of if

			if (data[l].compare(data[pivot]) == 1) {

				v = data[l];
				data[l] = data[pivot];
				data[pivot] = v;

			} // end of if

		} // end of if

	} // end of while

}

template <>
void Sort<double>::QuickSort_Non(double* data, const int n){

	double v, t;
	int i, j;
	int l, r; // 스택에 저장할 구간의 정보
	Stack<int> stack;

	l = 0;
	r = n - 1;

	stack.Push(r);
	stack.Push(l);

	while (stack.Any() != FALSE) {

		l = stack.Pop();
		r = stack.Pop();

		if (r - l + 1 > 3)
		{ // 종료조건 r-l+1은 구간의 길이

			// 가운데 값 선택
			int pivot = (r + l) / 2;
			// data[l], data[pivot], data[r] 세 값 정렬 (Bubble Sort)

			if (CompareDoubleAbsoulte(data[l], data[pivot]) == 1) {

				v = data[l];
				data[l] = data[pivot];
				data[pivot] = v;

			} // end of if

			if (CompareDoubleAbsoulte(data[pivot], data[r]) == 1) {

				v = data[pivot];
				data[pivot] = data[r];
				data[r] = v;

			} // end of if

			if (CompareDoubleAbsoulte(data[l], data[pivot]) == 1) {

				v = data[l];
				data[l] = data[pivot];
				data[pivot] = v;

			} // end of if

			// 중앙값을 a[r-1]과 교환

			v = data[pivot];
			data[pivot] = data[r - 1];
			data[r - 1] = v;

			i = l; // 분할구간은 l+1 ~ r-2
			j = r - 1;

			while (true) {

				while (CompareDoubleAbsoulte(data[++i] , v) == 0);

				while (CompareDoubleAbsoulte(data[--j],  v) == 1);

				if (i >= j) break;

				t = data[i];
				data[i] = data[j];
				data[j] = t;

			} // end of while

			t = data[i];
			data[i] = data[r - 1];
			data[r - 1] = t;

			stack.Push(r);
			stack.Push(i + 1);
			stack.Push(i - 1);
			stack.Push(l);

		}
		else { // 구간크기가 3보다 작다면

			// 가운데 값 선택
			int pivot = (r + l) / 2;
			// data[l], data[pivot], data[r] 세 값 정렬

			if (CompareDoubleAbsoulte(data[l], data[pivot]) == 1) {
				
				v = data[l];
				data[l] = data[pivot];
				data[pivot] = v;

			} // end of if

			if (CompareDoubleAbsoulte(data[pivot], data[r]) == 1) {
				
				v = data[pivot];
				data[pivot] = data[r];
				data[r] = v;

			} // end of if

			if (CompareDoubleAbsoulte(data[l], data[pivot]) == 1) {

				v = data[l];
				data[l] = data[pivot];
				data[pivot] = v;

			} // end of if

		} // end of if
	
	} // end of while

}

template <typename T>
void Sort<T>::QuickSort_Non(T* data, const int n){
	
	T v, t;
	int i, j;
	int l, r; // 스택에 저장할 구간의 정보
	Stack<int> stack;
	
	l = 0;
	r = n - 1;
	
	stack.Push(r);
	stack.Push(l);
	
	while (stack.Any() != FALSE) {

		l = stack.Pop();
		r = stack.Pop();

		if (r - l + 1 > 3) 
		{ // 종료조건 r-l+1은 구간의 길이

			// 가운데 값 선택
			int pivot = (r + l) / 2;
			// data[l], data[pivot], data[r] 세 값 정렬 (Bubble Sort)
			
			if (data[l] > data[pivot]) {

				v = data[l];
				data[l] = data[pivot];
				data[pivot] = v;

			} // end of if
			
			if (data[pivot] > data[r]) {

				v = data[pivot]; 
				data[pivot] = data[r];
				data[r] = v;

			} // end of if
			
			if (data[l] > data[pivot]) {

				v = data[l];
				data[l] = data[pivot]; 
				data[pivot] = v;

			} // end of if
			
			// 중앙값을 a[r-1]과 교환
			
			v = data[pivot];
			data[pivot] = data[r - 1];
			data[r - 1] = v;
			
			i = l; // 분할구간은 l+1 ~ r-2
			j = r - 1;
			
			while (true) {
			
				while (data[++i] < v);
				
				while (data[--j] > v);
				
				if (i >= j) break;
				
				t = data[i];
				data[i] = data[j];
				data[j] = t;

			} // end of while

			t = data[i];
			data[i] = data[r - 1];
			data[r - 1] = t;

			stack.Push(r);
			stack.Push(i + 1);
			stack.Push(i - 1);
			stack.Push(l);

		}
		else { // 구간크기가 3보다 작다면

			// 가운데 값 선택
			int pivot = (r + l) / 2;
			// data[l], data[pivot], data[r] 세 값 정렬

			if (data[l] > data[pivot]) {

				v = data[l]; 
				data[l] = data[pivot];
				data[pivot] = v;

			} // end of if
			
			if (data[pivot] > data[r]) {

				v = data[pivot]; 
				data[pivot] = data[r];
				data[r] = v;

			} // end of if
			
			if (data[l] > data[pivot]) {

				v = data[l];
				data[l] = data[pivot]; 
				data[pivot] = v;

			} // end of if
		
		} // end of if

	} // end of while

}


template <>
std::string Sort<std::string>::Median_Pivot(std::string* data, const int left, const int right){

	int center = (left + right) / 2;

	if (data[left].compare(data[center]) == 1){
		Swap(data, left, center);
	}

	if (data[left].compare(data[right]) == 1){
		Swap(data, left, right);
	}

	if (data[center].compare(data[right]) == 1){
		Swap(data, center, right);
	}

	Swap(data, center, right - 1);

	return data[right - 1];

}

template <>
double Sort<double>::Median_Pivot(double* data, const int left, const int right){

	int center = (left + right) / 2;

	if (CompareDoubleAbsoulte(data[left], data[center]) ==  1){
		Swap(data, left, center);
	}

	if (CompareDoubleAbsoulte(data[left], data[right]) == 1){
		Swap(data, left, right);
	}

	if (CompareDoubleAbsoulte(data[center], data[right]) == 1){
		Swap(data, center, right);
	}

	Swap(data, center, right - 1);

	return data[right - 1];

}


template <typename T>
T Sort<T>::Median_Pivot(T* data, const int left, const int right){

	int center = (left + right) / 2;

	if (data[left] > data[center]){
		Swap(data, left, center);
	}

	if (data[left] > data[right]){
		Swap(data, left, right);
	}

	if (data[center] > data[right]){
		Swap(data, center, right);
	}

	Swap(data, center, right - 1);

	return data[right - 1];

}

// End of Quick Sort