/*
	Subject - JLand(Sort) Project / j_sort_controller.h
	Created Date - 2014. 10. 8
	Description - JSort Controller 영역
	[Version]
*/

#include "j_model.h"

/// [Specialize] - String
// Binary Insert Sort
template <>
void Sort<std::string>::BinaryInsertSort(std::string* Data, const int n){

	int num = 0;
	std::string tmp = 0;

	for (int i = 1; i <= n; i++)
	{
		num = BinarySearch(Data, Data[i], i);

		if (num != -1){
			tmp = Data[i];

			for (int j = i; j >= num; j--)
			{
				Data[j] = Data[j - 1];
			}

			Data[num] = tmp;
		}
	} // end of for

}

template <>
int Sort<std::string>::BinarySearch(std::string* Data, const std::string x, const int n){

	int left = 0;
	int right = n;
	int index = -1;
	int middle = 0;

	while (left <= right)
	{
		middle = (left + right) / 2;

		if (x == Data[middle])
			break;

		if (x.compare(Data[middle]) < 0)
		{
			index = middle;
			right = middle - 1;
			continue;
		} // end of if  

		if (x.compare(Data[middle]) > 0)
		{
			left = middle + 1;
			continue;
		} // end of if

	} // end of while

	return middle;

}

// End of Binary Sort

/// Quick Sort
template <>
void Sort<std::string>::QuickSort(std::string* Data, const int left, const int right, int Type){

	switch (Type)
	{
	case TYPE_R_QUICK:
		QuickSort_Recur(Data, left, right, TYPE_R_QUICK);
		break;

	case TYPE_R_MEDIAN_QUICK:
		QuickSort_Recur(Data, left, right, TYPE_R_MEDIAN_QUICK);
		break;

	case TYPE_N_MEDIAN_QUICK:
		QuickSort_Non(Data, left, right, TYPE_N_MEDIAN_QUICK);
		break;

	case TYPE_STD_QUICK:
		std::sort(Data, Data + (right + 1));
		break;

	default:
		break;

	} // end of switch

}

template <>
void Sort<std::string>::QuickSort_Recur(std::string* Data, const int left, const int right, const int Type){

	if (left < right){

		int i = left;
		int j = right + 1;
		std::string Pivot;

		switch (Type)
		{
		case TYPE_R_QUICK:
			Pivot = Data[left].c_str();
			break;

		case TYPE_R_MEDIAN_QUICK:
			Pivot = Median_Pivot(Data, left, right);
			break;

		default:
			Pivot = Data[left];
			break;

		} // end of switch


		do
		{
			do{
				i++;
			} while (Data[i].compare(Pivot) < 0); // end of do while

			do{
				j--;
			} while (Data[j].compare(Pivot) > 0); // end of do while

			if (i < j)
			{
				Swap(Data, i, j);
			}// end of if

		} while (i < j); // end of do while

		Swap(Data, left, j);

		QuickSort(Data, left, j - 1);
		QuickSort(Data, j + 1, right);

	}

}

template <>
void Sort<std::string>::QuickSort_Non(std::string* Data, const int left, const int right, const int TYPE){

	Stack<JTuple<int>*> stack;
	JTuple<int>* varPair = NULL;
	int i, j;
	std::string pivot;

	// 스택에 초기에 Tuple을 담음
	// JTuple(James + Tuple = (x, y))
	// Version : 0.1
	// James(jungwy@cakeon.com)

	varPair = new JTuple<int>();
	varPair->SetTuple(left, right);
	stack.Push(varPair);

	while (1)
	{
		// Stack의 데이터 존재에 따라 동작(Recursive를 스택으로 잡음)
		if (stack.Any() != FALSE){

			varPair = stack.Pop();
			i = varPair->GetX();
			j = varPair->GetY();

			//pivot = Median_Pivot(Data, i, j); // MedianThree 이용(Recursive형에도 동일 적용)
			pivot = Data[i];

			j = j - 1; // right의 right - 1를 의미함.

			while (i < j)
			{
				//for (int k = 0; k <= right; k++) - 태스트 자료
				//	cout << Data[k] << " ";
				//cout << endl;

				if (Data[i].compare(Data[j]) > 0)
					Swap(Data, i, j);

				if (i != j)
				{
					i++; j--;
				}
				else
					break;

			}

			/*
			cout << "GetX:" << varPair->GetX() << " / GetY:" << varPair->GetY() << endl;
			*/

			Swap(Data, i, varPair->GetY());

			/*
			for (int k = 0; k <= right; k++)  // 구현 동작 측정용
			cout << Data[k] << " ";
			cout << endl;*/

			if (i != 0 && j != 0 && i != j){

				// i != 0때는 partition 상황에서 나올 수 있는 상황 고려
				// j != 0때도 마찬가지로 partition 상황 고려
				// i != j는 right(partition시 나올 수 있는 상황)

				varPair = new JTuple<int>();
				varPair->SetTuple(j + 1, right);
				stack.Push(varPair);

				varPair = new JTuple<int>();
				varPair->SetTuple(left, i - 1);
				stack.Push(varPair);
			} // end of if

		}
		else
		{
			break;
		}// end of if
	}

}

template <>
std::string Sort<std::string>::Median_Pivot(std::string* Data, const int left, const int right){

	int center = (left + right) / 2;

	if (Data[left].compare(Data[right]) > 0){
		Swap(Data, left, right);
	}

	if (Data[left].compare(Data[center]) > 0){
		Swap(Data, left, center);
	}

	if (Data[center].compare(Data[right]) > 0){
		Swap(Data, center, right);
	}

	Swap(Data, center, right);

	return Data[right];

}

// End of Quick Sort

/// Welcome to MergeSort
template <>
void Sort<std::string>::MergeSort(std::string* Data, const int left, const int right, const int Type){

	switch (Type)
	{
	case TYPE_R_MERGE:
		MergeSort_Recur(Data, left, right);
		break;

	case TYPE_N_MERGE:
		MergeSort_Non(Data, left, right);
		break;

	case TYPE_NAT_MERGE:
		MergeSort_Natural(Data, left, right);
		break;

	default:
		break;

	} // end of switch

}

template <>
void Sort<std::string>::MergeSort_Recur(std::string* Data, const int left, const int right){

	if (right - left != 0)
	{
		int middle = (left + right) / 2;

		MergeSort_Recur(Data, left, middle);
		MergeSort_Recur(Data, middle + 1, right);

		Merge(Data, left, middle, right);
	} // end of if
}



template <>
void Sort<std::string>::Merge(std::string* Data, const int Start, const int Mid, const int End){

	int i = Start;
	int LeftIDX = Start;
	int RightIDX = Mid + 1;
	int DestIDX = 0;

	std::string* DestArr = new std::string[End - Start + 1];

	// 단일 정복 구현
	while (LeftIDX <= Mid && RightIDX <= End)
	{
		if (Data[LeftIDX] < Data[RightIDX])
			DestArr[DestIDX] = Data[LeftIDX++];
		else
			DestArr[DestIDX] = Data[RightIDX++];

		DestIDX++;
	} // end of while

	while (LeftIDX <= Mid)
		DestArr[DestIDX++] = Data[LeftIDX++];

	while (RightIDX <= End)
		DestArr[DestIDX++] = Data[RightIDX++];

	DestIDX = 0;

	while (i <= End)
	{
		Data[i] = DestArr[DestIDX++];
		i++;
	} // end of while

	delete DestArr;

}


template <>
void Sort<std::string>::MergeSort_Non(std::string* Data, const int Start, const int End){

	JTuple<int>* varPair;
	Stack<JTuple<int>* > stack;
	int i;
	int Left = Start;
	int Mid = 0;
	int Right = End;

	// Partition 영역
	while (Left < Right)
	{
		// 초기 구축
		if (Left == Start && Right == End){
			varPair = new JTuple<int>();
			varPair->SetTuple(Left, Right);
			stack.Push(varPair);
		} // end of if

		// 왼쪽 구축
		while (Right - Left != PARTITION_END)
		{
			// Mid 영역
			Mid = (Left + Right) / 2;
			Right = Mid;

			varPair = new JTuple<int>();
			varPair->SetTuple(Left, Right);
			stack.Push(varPair);
		} // end of while

		// 오른쪽 구축
		Mid = (Start + End) / 2;
		Left = Mid + 1;
		Right = End;

		while (Left < Right)
		{
			if (Left != Right)
			{
				varPair = new JTuple<int>();
				varPair->SetTuple(Left, Right);
				stack.Push(varPair);
			} // end of if

			Mid = (Left + Right) / 2;
			Right = Mid;

		} // end of while

	} // end of while

	// 정복
	while (stack.Any() != FALSE)
	{
		varPair = stack.Pop();

		Left = varPair->GetX();
		Mid = (varPair->GetX() + varPair->GetY()) / 2;
		Right = Mid + 1;

		int DestIDX = 0;
		std::string* DestArr = new std::string[varPair->GetY() - varPair->GetX() + 1];

		// Data[Left]와 Data[Right] 비교하며 순서대로 데이터 입력
		while (Left <= varPair->GetX() && Right <= varPair->GetY())
		{
			if (Data[Left] < Data[Right])
				DestArr[DestIDX] = Data[Left++];
			else
				DestArr[DestIDX] = Data[Right++];

			DestIDX++;
		} // end of while

		// 잔량 데이터 입력
		// (Left)
		while (Left <= varPair->GetX())
			DestArr[DestIDX++] = Data[Left++];

		// 잔량 데이터 입력
		// (Right)
		while (Right <= varPair->GetY())
			DestArr[DestIDX++] = Data[Right++];


		// 데이터 교체
		i = varPair->GetX();
		DestIDX = 0;

		while (i <= varPair->GetY())
		{
			Data[i] = DestArr[DestIDX++];
			i++;
		} // end of while

		delete DestArr;

	} // end of while

}

template <>
void Sort<std::string>::MergeSort_Natural(std::string* Data, const int Start, const int End){

	int status = TRUE;
	int partLeft = 1;
	int partRight = partLeft + 1;
	int partStart = 0;
	int i;
	int partIDX = 1;

	JTuple<int>* varPair = NULL;
	Queue<JTuple<int>* > queue;

	// Part 1
	// 탐색할 공간 Partition

	while (status)
	{
		i = 0;
		// 범위 비교 전략 수립
		while (i < partIDX)
		{
			// 범위 초과
			if (partRight > End)
			{
				// 마지막 단계 분할
				varPair = queue.GetRear()->Data;
				partLeft = varPair->GetX();
				varPair = new JTuple<int>();
				varPair->SetTuple(partLeft, End);
				queue.Push(varPair);

				// 최종 분할 과정
				varPair = new JTuple<int>();
				varPair->SetTuple(Start, End);
				queue.Push(varPair);
				status = FALSE;

				break;
			}
			else
			{
				varPair = new JTuple<int>();
				varPair->SetTuple(partLeft, partRight);
				queue.Push(varPair); // 분할 삽입
			} // end of if

			// i는 Grouping의 갯수
			if ((i + 1) == partIDX)
			{
				varPair = new JTuple<int>();
				varPair->SetTuple(partStart, partRight);
				queue.Push(varPair);

				/* Mid의 범위가 1보다 클 때
				V(0, partRight)로 부분 정복 */

				if (partIDX > 1)
				{
					varPair = new JTuple<int>();
					varPair->SetTuple(Start, partRight);
					queue.Push(varPair);
				} // end of if

			} // end of if

			partLeft = partLeft + 2;
			partRight = partLeft + 1;

			i++;

		} // end of if

		partStart = partLeft;
		partIDX++;

	} // end of while

	// Part 2
	// 정복

	int Left = 0;
	int Right = 0;
	int Mid = 0;
	int Range = 0;
	int partMid = partLeft;

	varPair = NULL; // Tuple 가독성 목적으로 재배치

	while (queue.Any() != FALSE)
	{
		varPair = queue.Pop();
		Left = varPair->GetX();
		Mid = (varPair->GetX() + varPair->GetY()) / 2;
		Range = varPair->GetY() - varPair->GetX();

		if (Range == 2 && Left != 0 && Right != varPair->GetY())
			Mid = Mid - 1;
		if ((Range + 1) % 2 == 1 && Range >= 2 && Left == 0)
			Mid = Mid - 1;

		// 마지막일 때
		if (varPair->GetX() == Start && varPair->GetY() == End)
			Mid = partMid - 1; // 파트의 마지막 분할 영역을 기점으로

		Right = Mid + 1;

		int DestIDX = 0;

		std::string* DestArr = new std::string[Range + 1];

		while (Left <= Mid && Right <= varPair->GetY())
		{
			if (Data[Left] < Data[Right])
				DestArr[DestIDX] = Data[Left++];
			else
				DestArr[DestIDX] = Data[Right++];

			DestIDX++;
		} // end of while

		while (Left <= Mid)
			DestArr[DestIDX++] = Data[Left++];

		while (Right <= varPair->GetY())
			DestArr[DestIDX++] = Data[Right++];

		//for (int j = 0; j < DestIDX; j++)
		//	cout << DestArr[j] << " ";

		//cout << endl;


		// Merge 수행
		i = varPair->GetX();
		DestIDX = 0;

		while (i <= varPair->GetY())
		{
			Data[i] = DestArr[DestIDX++];
			i++;
		} // end of while

		//for (int j = 0; j <= End; j++)
		//	cout << Data[j] << " ";

		//cout << endl;

		delete DestArr;
		DestArr = NULL;

	}

}
// End of Merge

/// Heap Sort
template <>
void Sort<std::string>::HeapSort(std::string* Data, const int n)
{
	int i = n / 2;
	while (i >= 1)
	{
		Adjust(Data, i, n);
		i--;
	} // end of while

	i = n - 1;
	while (i >= 1)
	{
		Swap(Data, 1, i + 1);
		Adjust(Data, 1, i);

		i--;
	} // end of while

}

template <>
void Sort<std::string>::Adjust(std::string* Data, const int root, const int n)
{
	int i;
	std::string Element = Data[root];

	i = 2 * root;
	while (i <= n)
	{
		if (i < n && Data[i].compare(Data[i + 1]) > 0)
			i++;

		if (Data[i].compare(Element) <= 0)
			break;

		Data[i / 2] = Data[i];

		i = i * 2;
	} // end of while

	Data[i / 2] = Element;

}

// End of Heap Sort

/// Bubble Sort
template <>
void Sort<std::string>::BubbleSort(std::string* Data, const int n){

	int i, j;
	i = 0;
	while (i <= n)
	{
		j = 0;
		while (j <= n - 1)
		{
			if (Data[j].compare(Data[j + 1]) > 0)
				Swap(Data, j, j + 1);

			j++;
		} // end of while

		i++;
	} // end of while

}

// End of Bubble Sort

/// Selection Sort
template <>
void Sort<std::string>::SelectionSort(std::string* Data, const int n){

	int i, j;

	i = 0;
	while (i <= n)
	{
		j = i + 1;
		while (j <= n)
		{
			if (Data[i].compare(Data[j]) > 0)
				Swap(Data, i, j);

			j++;
		} // end of while

		i++;
	} // end of while

}
// End of Selection Sort

/// Swap
template <>
void Sort<std::string>::Swap(std::string* Data, int left, int right){

	std::string Temp = Data[left];
	Data[left] = Data[right];
	Data[right] = Temp;

}

// End of Swap

/// [Generalize] - Template
template <typename T>
Sort<T>::Sort()
{
}

template <typename T>
Sort<T>::~Sort()
{
}

/// Binary Insert Sort
template <typename T>
void Sort<T>::BinaryInsertSort(T* Data, const int n){

	int num = 0;
	T tmp = 0;

	for (int i = 1; i <= n; i++)
	{
		num = BinarySearch(Data, Data[i], i);

		if (num != -1){
			tmp = Data[i];

			for (int j = i; j >= num; j--)
			{
				Data[j] = Data[j - 1];
			}

			Data[num] = tmp;
		}
	} // end of for

}

template <typename T>
int Sort<T>::BinarySearch(T* Data, const T x, const int n){

	int left = 0;
	int right = n;
	int index = -1;
	int middle = 0;

	while (left <= right)
	{
		middle = (left + right) / 2;

		if (x == Data[middle])
			break;

		if (x < Data[middle])
		{
			index = middle;
			right = middle - 1;
			continue;
		} // end of if  

		if (x > Data[middle])
		{
			left = middle + 1;
			continue;
		} // end of if

	} // end of while

	return middle;

}

// End of Binary Sort

/// Quick Sort
template <typename T>
void Sort<T>::QuickSort(T* Data, const int left, const int right, int Type = TYPE_R_QUICK){

	switch (Type)
	{
	case TYPE_R_QUICK:
		QuickSort_Recur(Data, left, right, TYPE_R_QUICK);
		break;

	case TYPE_R_MEDIAN_QUICK:
		QuickSort_Recur(Data, left, right, TYPE_R_MEDIAN_QUICK);
		break;

	case TYPE_N_MEDIAN_QUICK:
		QuickSort_Non(Data, left, right, TYPE_N_MEDIAN_QUICK);
		break;

	case TYPE_STD_QUICK:
		std::sort(Data, Data + (right + 1));
		break;

	default:
		break;

	} // end of switch

}

template <typename T>
void Sort<T>::QuickSort_Recur(T* Data, const int left, const int right, const int Type = TYPE_R_QUICK){

	if (left < right){

		int i = left;
		int j = right + 1;
		T Pivot = NULL;

		switch (Type)
		{
		case TYPE_R_QUICK:
			Pivot = Data[left];
			break;

		case TYPE_R_MEDIAN_QUICK:
			Pivot = Median_Pivot(Data, left, right);
			break;

		default:
			Pivot = Data[left];
			break;

		} // end of switch


		do
		{
			do{
				i++;
			} while (Data[i] < Pivot); // end of do while

			do{
				j--;
			} while (Data[j] > Pivot); // end of do while

			if (i < j)
			{
				Swap(Data, i, j);
			}// end of if

		} while (i <= j); // end of do while

		Swap(Data, left, j);

		QuickSort(Data, left, j - 1);
		QuickSort(Data, j + 1, right);

	}

}

template <typename T>
void Sort<T>::QuickSort_Non(T* Data, const int left, const int right, const int TYPE = TYPE_N_MEDIAN_QUICK){

	Stack<JTuple<int>*> stack;
	JTuple<int>* varPair = NULL;
	int i, j;
	T pivot;

	// 스택에 초기에 Tuple을 담음
	// JTuple(James + Tuple = (x, y))
	// Version : 0.1

	varPair = new JTuple<int>();
	varPair->SetTuple(left, right);
	stack.Push(varPair);

	while (1)
	{
		// Stack의 데이터 존재에 따라 동작(Recursive를 스택으로 잡음)
		if (stack.Any() != FALSE){

			varPair = stack.Pop();
			i = varPair->GetX();
			j = varPair->GetY();

			//pivot = Median_Pivot(Data, i, j); // MedianThree 이용(Recursive형에도 동일 적용)
			pivot = Data[i];

			j = j - 1; // right의 right - 1를 의미함.

			while (i < j)
			{
				//for (int k = 0; k <= right; k++) - 태스트 자료
				//	cout << Data[k] << " ";
				//cout << endl;

				if (Data[i] > Data[j])
					Swap(Data, i, j);

				if (i != j)
				{
					i++; j--;
				}
				else
					break;

			}

			/*
			cout << "GetX:" << varPair->GetX() << " / GetY:" << varPair->GetY() << endl;
			*/

			Swap(Data, i, varPair->GetY());

			/*
			for (int k = 0; k <= right; k++)  // 구현 동작 측정용
			cout << Data[k] << " ";
			cout << endl;*/

			if (i != 0 && j != 0 && i != j){

				// i != 0때는 partition 상황에서 나올 수 있는 상황 고려
				// j != 0때도 마찬가지로 partition 상황 고려
				// i != j는 right(partition시 나올 수 있는 상황)

				varPair = new JTuple<int>();
				varPair->SetTuple(j + 1, right);
				stack.Push(varPair);

				varPair = new JTuple<int>();
				varPair->SetTuple(left, i - 1);
				stack.Push(varPair);
			} // end of if

		}
		else
		{
			break;
		}// end of if
	}

}

template <typename T>
T Sort<T>::Median_Pivot(T* Data, const int left, const int right){

	int center = (left + right) / 2;

	if (Data[left] > Data[right]){
		Swap(Data, left, right);
	}

	if (Data[left] > Data[center]){
		Swap(Data, left, center);
	}

	if (Data[center] > Data[right]){
		Swap(Data, center, right);
	}

	Swap(Data, center, right);

	return Data[right];

}

// End of Quick Sort

/// Welcome to MergeSort
template <typename T>
void Sort<T>::MergeSort(T* Data, const int left, const int right, const int Type){

	switch (Type)
	{
	case TYPE_R_MERGE:
		MergeSort_Recur(Data, left, right);
		break;

	case TYPE_N_MERGE:
		MergeSort_Non(Data, left, right);
		break;

	case TYPE_NAT_MERGE:
		MergeSort_Natural(Data, left, right);
		break;

	default:
		break;

	} // end of switch

}

template <typename T>
void Sort<T>::MergeSort_Recur(T* Data, const int left, const int right){

	if (right - left != 0)
	{
		int middle = (left + right) / 2;

		MergeSort_Recur(Data, left, middle);
		MergeSort_Recur(Data, middle + 1, right);

		Merge(Data, left, middle, right);
	} // end of if
}



template <typename T>
void Sort<T>::Merge(T* Data, const int Start, const int Mid, const int End){

	int i = Start;
	int LeftIDX = Start;
	int RightIDX = Mid + 1;
	int DestIDX = 0;

	T* DestArr = new T[End - Start + 1];

	// 단일 정복 구현
	while (LeftIDX <= Mid && RightIDX <= End)
	{
		if (Data[LeftIDX] < Data[RightIDX])
			DestArr[DestIDX] = Data[LeftIDX++];
		else
			DestArr[DestIDX] = Data[RightIDX++];

		DestIDX++;
	} // end of while

	while (LeftIDX <= Mid)
		DestArr[DestIDX++] = Data[LeftIDX++];

	while (RightIDX <= End)
		DestArr[DestIDX++] = Data[RightIDX++];

	DestIDX = 0;

	while (i <= End)
	{
		Data[i] = DestArr[DestIDX++];
		i++;
	} // end of while

	delete DestArr;

}


template <typename T>
void Sort<T>::MergeSort_Non(T* Data, const int Start, const int End){

	JTuple<int>* varPair;
	Stack<JTuple<int>* > stack;
	int i;
	int Left = Start;
	int Mid = 0;
	int Right = End;

	// Partition 영역
	while (Left < Right)
	{
		// 초기 구축
		if (Left == Start && Right == End){
			varPair = new JTuple<int>();
			varPair->SetTuple(Left, Right);
			stack.Push(varPair);
		} // end of if

		// 왼쪽 구축
		while (Right - Left != PARTITION_END)
		{
			// Mid 영역
			Mid = (Left + Right) / 2;
			Right = Mid;

			varPair = new JTuple<int>();
			varPair->SetTuple(Left, Right);
			stack.Push(varPair);
		} // end of while

		// 오른쪽 구축
		Mid = (Start + End) / 2;
		Left = Mid + 1;
		Right = End;

		while (Left < Right)
		{
			if (Left != Right)
			{
				varPair = new JTuple<int>();
				varPair->SetTuple(Left, Right);
				stack.Push(varPair);
			} // end of if

			Mid = (Left + Right) / 2;
			Right = Mid;

		} // end of while

	} // end of while

	// 정복
	while (stack.Any() != FALSE)
	{
		varPair = stack.Pop();

		Left = varPair->GetX();
		Mid = (varPair->GetX() + varPair->GetY()) / 2;
		Right = Mid + 1;

		int DestIDX = 0;
		T* DestArr = new T[varPair->GetY() - varPair->GetX() + 1];

		// Data[Left]와 Data[Right] 비교하며 순서대로 데이터 입력
		while (Left <= varPair->GetX() && Right <= varPair->GetY())
		{
			if (Data[Left] < Data[Right])
				DestArr[DestIDX] = Data[Left++];
			else
				DestArr[DestIDX] = Data[Right++];

			DestIDX++;
		} // end of while

		// 잔량 데이터 입력
		// (Left)
		while (Left <= varPair->GetX())
			DestArr[DestIDX++] = Data[Left++];

		// 잔량 데이터 입력
		// (Right)
		while (Right <= varPair->GetY())
			DestArr[DestIDX++] = Data[Right++];


		// 데이터 교체
		i = varPair->GetX();
		DestIDX = 0;

		while (i <= varPair->GetY())
		{
			Data[i] = DestArr[DestIDX++];
			i++;
		} // end of while

		delete DestArr;

	} // end of while

}

template <typename T>
void Sort<T>::MergeSort_Natural(T* Data, const int Start, const int End){

	int status = TRUE;
	int partLeft = 1;
	int partRight = partLeft + 1;
	int partStart = 0;
	int i;
	int partIDX = 1;

	JTuple<int>* varPair = NULL;
	Queue<JTuple<int>* > queue;

	// Part 1
	// 탐색할 공간 Partition

	while (status)
	{
		i = 0;
		// 범위 비교 전략 수립
		while (i < partIDX)
		{
			// 범위 초과
			if (partRight > End)
			{
				// 마지막 단계 분할
				varPair = queue.GetRear()->Data;
				partLeft = varPair->GetX();
				varPair = new JTuple<int>();
				varPair->SetTuple(partLeft, End);
				queue.Push(varPair);

				// 최종 분할 과정
				varPair = new JTuple<int>();
				varPair->SetTuple(Start, End);
				queue.Push(varPair);
				status = FALSE;

				break;
			}
			else
			{
				varPair = new JTuple<int>();
				varPair->SetTuple(partLeft, partRight);
				queue.Push(varPair); // 분할 삽입
			} // end of if

			// i는 Grouping의 갯수
			if ((i + 1) == partIDX)
			{
				varPair = new JTuple<int>();
				varPair->SetTuple(partStart, partRight);
				queue.Push(varPair);

				/* Mid의 범위가 1보다 클 때
				V(0, partRight)로 부분 정복 */

				if (partIDX > 1)
				{
					varPair = new JTuple<int>();
					varPair->SetTuple(Start, partRight);
					queue.Push(varPair);
				} // end of if

			} // end of if

			partLeft = partLeft + 2;
			partRight = partLeft + 1;

			i++;

		} // end of if

		partStart = partLeft;
		partIDX++;

	} // end of while

	// Part 2
	// 정복

	int Left = 0;
	int Right = 0;
	int Mid = 0;
	int Range = 0;
	int partMid = partLeft;

	varPair = NULL; // Tuple 가독성 목적으로 재배치

	while (queue.Any() != FALSE)
	{
		varPair = queue.Pop();
		Left = varPair->GetX();
		Mid = (varPair->GetX() + varPair->GetY()) / 2;
		Range = varPair->GetY() - varPair->GetX();

		if (Range == 2 && Left != 0 && Right != varPair->GetY())
			Mid = Mid - 1;
		if ((Range + 1) % 2 == 1 && Range >= 2 && Left == 0)
			Mid = Mid - 1;

		// 마지막일 때
		if (varPair->GetX() == Start && varPair->GetY() == End)
			Mid = partMid - 1; // 파트의 마지막 분할 영역을 기점으로

		Right = Mid + 1;

		int DestIDX = 0;

		T* DestArr = new T[Range + 1];

		while (Left <= Mid && Right <= varPair->GetY())
		{
			if (Data[Left] < Data[Right])
				DestArr[DestIDX] = Data[Left++];
			else
				DestArr[DestIDX] = Data[Right++];

			DestIDX++;
		} // end of while

		while (Left <= Mid)
			DestArr[DestIDX++] = Data[Left++];

		while (Right <= varPair->GetY())
			DestArr[DestIDX++] = Data[Right++];

		//for (int j = 0; j < DestIDX; j++)
		//	cout << DestArr[j] << " ";

		//cout << endl;


		// Merge 수행
		i = varPair->GetX();
		DestIDX = 0;

		while (i <= varPair->GetY())
		{
			Data[i] = DestArr[DestIDX++];
			i++;
		} // end of while

		//for (int j = 0; j <= End; j++)
		//	cout << Data[j] << " ";

		//cout << endl;

		delete DestArr;
		DestArr = NULL;

	}

}
// End of Merge

/// Heap Sort
template <typename T>
void Sort<T>::HeapSort(T* Data, const int n)
{
	int i = n / 2;
	while (i >= 1)
	{
		Adjust(Data, i, n);
		i--;
	} // end of while

	i = n - 1;
	while (i >= 1)
	{
		Swap(Data, 1, i + 1);
		Adjust(Data, 1, i);

		i--;
	} // end of while

}

template <typename T>
void Sort<T>::Adjust(T* Data, const int root, const int n)
{
	int i;
	T Element = Data[root];

	i = 2 * root;
	while (i <= n)
	{
		if (i < n && Data[i] < Data[i + 1])
			i++;

		if (Data[i] <= Element)
			break;

		Data[i / 2] = Data[i];

		i = i * 2;
	} // end of while

	Data[i / 2] = Element;

}

// End of Heap Sort

/// Bubble Sort
template <typename T>
void Sort<T>::BubbleSort(T* Data, const int n){

	int i, j;
	i = 0;
	while (i <= n)
	{
		j = 0;
		while (j <= n - 1)
		{
			if (Data[j] > Data[j + 1])
				Swap(Data, j, j + 1);

			j++;
		} // end of while

		i++;
	} // end of while

}

// End of Bubble Sort

/// Selection Sort
template <typename T>
void Sort<T>::SelectionSort(T* Data, const int n){

	int i, j;

	i = 0;
	while (i <= n)
	{
		j = i + 1;
		while (j <= n)
		{
			if (Data[i] > Data[j])
				Swap(Data, i, j);

			j++;
		} // end of while

		i++;
	} // end of while

}
// End of Selection Sort

/// Swap
template <typename T>
void Sort<T>::Swap(T* Data, int left, int right){

	T Temp = Data[left];
	Data[left] = Data[right];
	Data[right] = Temp;

}

// End of Swap