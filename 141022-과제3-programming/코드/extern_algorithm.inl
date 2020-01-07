
/// [Generalize] - Template
template <typename T>
Sort<T>::Sort()
{
}

template <typename T>
Sort<T>::~Sort()
{
}


/// Swap
template <>
void Sort<std::string>::Swap(std::string* data, int left, int right){

	std::string Temp = data[left];
	data[left] = data[right];
	data[right] = Temp;

}
// End of Swap

/// Swap
template <>
void Sort<double>::Swap(double* data, int left, int right){

	double Temp = data[left];
	data[left] = data[right];
	data[right] = Temp;

}

template <typename T>
void Sort<T>::Swap(T* data, int left, int right){

	T Temp = data[left];
	data[left] = data[right];
	data[right] = Temp;

}

// End of Swap

/// Binary Insert Sort
template <typename T>
void Sort<T>::BinaryInsertSort(T* data, const int n){

	int index = 0;
	T element;

	for (int i = 1; i < n; i++)
	{
		index = BinarySearch(data, data[i], i);

		if (index < i){

			element = data[i];
			memmove(data + index + 1, data + index, sizeof(int)* (i - index));
			data[index] = element;

		} // end of if

	} // end of for

}
// End of Binary Insert Sort

/// Binary Search
template <typename T>
int Sort<T>::BinarySearch(T* data, const T x, const int n){

	int left = 0;
	int right = n;
	int middle = n / 2;

	//	for (int i = 0; i < n; i++)
	//	cout << data[i] << " ";

	while (left < right)
	{
		middle = left + ((right - left) / 2);

		if (x > data[middle])
		{
			left = middle + 1;
		} // end of if  

		else if (x == data[middle])
		{
			return middle;
		}

		else
			right = middle;

		middle = left + ((right - left) / 2);

	} // end of while

	return middle;
}
// End of Binary Search

/// LinkedInsertSort
template <typename T>
void Sort<T>::LinkedInsertSort(Node<T>* ptrNode){

	Node<T>* first = ptrNode;
	first = first->next;

	Node<T>* second = NULL;
	Node<T>* prevNode = NULL;

	T key;

	while (first != NULL)
	{
		key = first->data;
		second = first->prev;

		while (second != NULL)
		{
			prevNode = second;

			if (second->data > key)
			{
				second->next->data = second->data;
			}
			else
				break;

			second = second->prev;

		} // end of while

		if (prevNode != NULL && prevNode != second)
			prevNode->data = key;
		else
			second->next->data = key;

		first = first->next;

	} // end of while
}
// End of Linked Insert Sort

/// Quick Sort
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

	}
}

template <typename T>
int Sort<T>::partitionIt(T* data, int left, int right, T pivot){

	int leftPtr = left;
	int rightPtr = right - 1;

	while (1)
	{
		while (data[++leftPtr] < pivot); // end of do while

		while (data[--rightPtr] > pivot); // end of do while

		if (leftPtr >= rightPtr)
			break;
		else
			Swap(data, leftPtr, rightPtr);

	}
	Swap(data, leftPtr, right - 1);
	return leftPtr;

}

template <typename T>
void Sort<T>::QuickSort_Recur(T* data, const int left, const int right){

	if (left < right){

		int i = left;
		int j = right + 1;
		T Pivot = NULL;

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

template <typename T>
void Sort<T>::QuickSort_MedianRecur(T* data, const int left, const int right){

	int size = right - left + 1;

	if (size <= 3)
	{
		cout << "M" << left << "," << right << "," << size << endl;
		manualSort(data, left, right);
	}
	else{

		T pivot = NULL;

		pivot = Median_Pivot(data, left, right);

		int partition = partitionIt(data, left, right, pivot);
		int pivotIndex = FindIndex(data, pivot, right);

		cout << left << "," << right << "," << size << endl;

		QuickSort_MedianRecur(data, left, pivotIndex - 1);
		QuickSort_MedianRecur(data, pivotIndex + 1, right);

	}

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

			}

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
	}

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

/// MergeSort Framework
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

/// Heap Sort
template <typename T>
void Sort<T>::HeapSort(T* data, const int n)
{
	int i = n / 2;
	while (i >= 1)
	{
		Adjust(data, i, n);
		i--;
	} // end of while

	i = n - 1;
	while (i >= 1)
	{
		Swap(data, 1, i + 1);
		Adjust(data, 1, i);

		i--;
	} // end of while

}
// End of Heap Sort

/// Adjust
template <typename T>
void Sort<T>::Adjust(T* data, const int root, const int n)
{
	int i;
	T element = data[root];

	i = 2 * root;

	while (i <= n)
	{
		if (i < n && data[i] < data[i + 1])
			i++;

		if (data[i] <= element)
			break;

		data[i / 2] = data[i];

		i = i * 2;

	} // end of while

	data[i / 2] = element;

}
// end of Adjust

/// Bubble Sort
template <typename T>
void Sort<T>::BubbleSort(T* data, const int n){

	int i, j;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - 1)
		{
			if (data[j] > data[j + 1])
				Swap(data, j, j + 1);

			j++;
		} // end of while

		i++;
	} // end of while

}
// End of Bubble Sort

/// Selection Sort
template <typename T>
void Sort<T>::SelectionSort(T* data, const int n){

	int i, j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (data[i] > data[j])
				Swap(data, i, j);

			j++;
		} // end of while

		i++;
	} // end of while

}
// End of Selection Sort
