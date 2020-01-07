/*
	����:���α׷���(7�� ���� - 1����)
	OOOOOOOOOOOOOOOOO��
	�а�: �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
	�й�: 20101215
	�̸�: ��OO
*/

#include "j_sort.h"
#include <algorithm>


/// Stack
template <typename T>
Stack<T>::Stack(){
	Top = NULL;
	Count = 0;
}

template <typename T>
Stack<T>::~Stack(){

	Node<T>* ptrNode = NULL;
	while (Top != NULL)
	{
		ptrNode = Top;
		delete[] ptrNode;
		ptrNode = NULL;
	} // end of while

	delete[] Top;
	Top = NULL;

}

template <typename T>
void Stack<T>::Push(T Data){

	Node<T>* ptrNode = new Node<T>();
	ptrNode->Data = Data;
	ptrNode->prev = NULL;
	ptrNode->next = NULL;

	if (Top == NULL)
	{
		Top = ptrNode;
	}
	else
	{
		ptrNode->prev = Top;
		Top->next = ptrNode;
		Top = Top->next;
	} // end of if

	Count++;
}

template <typename T>
T Stack<T>::Pop(){

	T Data = NULL;

	if (Top != NULL)
	{
		Node<T>* ptrNode = NULL;
		ptrNode = Top;
		Data = Top->Data;
		
		Top = Top->prev;
		
		if (Top != NULL)
			Top->next = NULL;

		delete[] ptrNode;
		ptrNode = NULL;

		Count--;
	}
	else
	{
		// Empty();
	} // end of if

	return Data;	
}

// End of Stack

/// Queue
template <typename T>
Queue<T>::Queue(){
	front = NULL;
	rear = NULL;
	Count = 0;
}

template <typename T>
Queue<T>::~Queue(){

	Node<T>* ptr = NULL;

	while (front != NULL)
	{
		ptr = front;
		front = front->next;

		delete[] ptr;
		ptr = NULL;
	} // end of while

	delete[] front;
	delete[] rear;

	// ������ ����
	front = NULL;
	rear = NULL;

}

template <typename T>
void Queue<T>::Push(T Data){

	Node<T>* NewNode = new Node<T>();

	NewNode->Data = Data;
	NewNode->prev = NewNode;
	NewNode->next = NULL;

	// �ʱ� ��
	if (front == NULL)
	{
		front = NewNode;
		rear = front;
	}
	else
	{
		if (front == rear){
			
			front->prev = NewNode;
			NewNode->prev = front;
			front->next = NewNode;
			
			rear = NewNode;
		}
		else{	
			NewNode->prev = front;
			front->prev = NewNode;
			rear->next = NewNode;
			rear = NewNode;

		} // end of if

	} // end of if

	Count++;

}

template <typename T>
T Queue<T>::Pop(){

	Node<T>* ptr = NULL;
	T Data = NULL;

	if (front != NULL)
	{
		Data = front->Data;
		
		ptr = front;
		
		front = front->next;

		if (front != NULL){ // Front�� NULL�� �ƴ� ��
			front->prev = rear;
			rear->prev = front;
		}
		else
			front = rear = NULL;

		delete[] ptr;
		ptr = NULL;

		Count--;
	}
	else{
		// ��������� �˸��� �� �־ ��.
	} // end of if

	return Data;
}

// End of Queue

/// Linked List
template <typename T>
LinkedList<T>::LinkedList(int Type){
	First = NULL;
	TopNode = NULL;
	Count = 0;
	SortType = Type;
}

template <typename T>
LinkedList<T>::~LinkedList(){

	while (First != NULL)
	{
		Node<T>* ptr = First;
		First = First->next;
		delete[] ptr;
		ptr = NULL;
	}

	delete[] First;
	delete[] TopNode;
	First = NULL;
	TopNode = NULL;
}

template <typename T>
void LinkedList<T>::Insert(T Data){

	Node<T>* NewNode = NULL;
	NewNode = new Node<T>();

	NewNode->Data = Data;
	NewNode->next = NULL;

	if (First == NULL)
	{

		First = NewNode;
		switch (SortType)
		{
			case SORT:	
				break;

			default:
				TopNode = First;
				break;
		}
	}
	else
	{	
		Node<T>* curNode = NULL;
		Node<T>* prevNode = NULL;
		Node<T>* nextNode = NULL;

		switch (SortType)
		{
			case SORT: // ���� ��Ģ�� ��� ����
				curNode = First;
				prevNode = curNode;

				while (curNode != NULL)
				{
					if (curNode->Data > NewNode->Data)
					{
						if (curNode->next != NULL)
						{
							if (curNode == First)
							{
								NewNode->next = prevNode;
								First = NewNode;
							}
							else{
								prevNode->next = NewNode;
								NewNode->next = curNode;
								curNode = NewNode;
							} // end of if

						}
						else{

							if (curNode == First)
							{
								NewNode->next = prevNode;
								First = NewNode;
							}
							else{
								NewNode->next = curNode;
								curNode = NewNode;
							} // end of if

						} // end of if

						break;
					} // end of if

					prevNode = curNode;
					curNode = curNode->next;
				} // end of while


				break;

			default: // �Ϲ� ������ ����

				TopNode->next = NewNode;
				NewNode->prev = TopNode;
				TopNode = TopNode->next;

				break;
		} // end of switch

	} // end of if

	Count++;
}

// End of Linked List

/// Binary Insert Sort
template <typename T>
void Sort<T>::BinaryInsertSort(T* Data, const int n){

	T num = 0;
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
		middle = (left + right) / 2 ;

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
			std::sort(Data, Data + right);
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
			}
			while (Data[i] < Pivot); // end of do while

			do{
				j--;
			}
			while (Data[j] > Pivot); // end of do while

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
	int pivot;

	// ���ÿ� �ʱ⿡ Tuple�� ����
	// JTuple(James + Tuple = (x, y))
	// Version : 0.1
	// James(jungwy@cakeon.com)

	varPair = new JTuple<int>();
	varPair->SetTuple(left, right);
	stack.Push(varPair);

	while (1)
	{
		// Stack�� ������ ���翡 ���� ����(Recursive�� �������� ����)
		if (stack.Any() != FALSE){

			varPair = stack.Pop();
			i = varPair->GetX();
			j = varPair->GetY();

			pivot = Median_Pivot(Data, i, j); // MedianThree �̿�(Recursive������ ���� ����)

			j = j - 1; // right�� right - 1�� �ǹ���.

			while (i < j)
			{
				for (int k = 0; k <= right; k++)
					cout << Data[k] << " ";
				cout << endl;

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
			for (int k = 0; k <= right; k++)  // ���� ���� ������
				cout << Data[k] << " ";
			cout << endl;*/

			if (i != 0 && j != 0 && i != j){ 
				
				// i != 0���� partition ��Ȳ���� ���� �� �ִ� ��Ȳ ���
				// j != 0���� ���������� partition ��Ȳ ���
				// i != j�� right(partition�� ���� �� �ִ� ��Ȳ)

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

	if (Data[left] > Data[right])
		Swap(Data, left, right);

	if (Data[left] > Data[center])
		Swap(Data, left, center);

	if (Data[center] > Data[right])
		Swap(Data, center, right);

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
void Sort<T>::MergeSort_Non(T* Data, const int Start, const int End){

	JTuple<int>* varPair;
	Stack<JTuple<int>* > stack;
	int i;
	int Left = Start;
	int Mid = 0;
	int Right = End;

	// Partition ����
	while (Left < Right)
	{
		// �ʱ� ����
		if (Left == Start && Right == End){
			varPair = new JTuple<int>();
			varPair->SetTuple(Left, Right);
			stack.Push(varPair);
		} // end of if

		// ���� ����
		while (Right - Left != PARTITION_END)
		{
			// Mid ����
			Mid = (Left + Right) / 2;
			Right = Mid;

			varPair = new JTuple<int>();
			varPair->SetTuple(Left, Right);
			stack.Push(varPair);
		} // end of while

		// ������ ����
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

	// ����
	while (stack.Any() != FALSE)
	{
		varPair = stack.Pop();
		
		Left = varPair->GetX();
		Mid = (varPair->GetX() + varPair->GetY()) / 2;
		Right = Mid + 1;

		int DestIDX = 0;
		T* DestArr = new T[varPair->GetY() - varPair->GetX() + 1];

		// Data[Left]�� Data[Right] ���ϸ� ������� ������ �Է�
		while (Left <= varPair->GetX() && Right <= varPair->GetY())
		{
			if (Data[Left] < Data[Right])
				DestArr[DestIDX] = Data[Left++];
			else
				DestArr[DestIDX] = Data[Right++];

			DestIDX++;
		} // end of while

		// �ܷ� ������ �Է�
		// (Left)
		while (Left <= varPair->GetX())
			DestArr[DestIDX++] = Data[Left++];

		// �ܷ� ������ �Է�
		// (Right)
		while (Right <= varPair->GetY())
			DestArr[DestIDX++] = Data[Right++];


		// ������ ��ü
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

	// ���� ���� ����
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
	// Ž���� ���� Partition

	while (status)
	{
		i = 0;
		// ���� �� ���� ����
		while (i < partIDX)
		{
			// ���� �ʰ�
			if (partRight > End)
			{
				// ������ �ܰ� ����
				varPair = queue.GetRear()->Data;
				partLeft = varPair->GetX();
				varPair = new JTuple<int>();
				varPair->SetTuple(partLeft, End);
				queue.Push(varPair);

				// ���� ���� ����
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
				queue.Push(varPair); // ���� ����
			} // end of if

			// i�� Grouping�� ����
			if ((i + 1) == partIDX)
			{
				varPair = new JTuple<int>();
				varPair->SetTuple(partStart, partRight);
				queue.Push(varPair);

				/* Mid�� ������ 1���� Ŭ ��
				   V(0, partRight)�� �κ� ���� */

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
	// ����

	int Left = 0;
	int Right = 0;
	int Mid = 0;
	int Range = 0;
	int partMid = partLeft;

	varPair = NULL; // Tuple ������ �������� ���ġ

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

		// �������� ��
		if (varPair->GetX() == Start && varPair->GetY() == End)
			Mid = partMid - 1; // ��Ʈ�� ������ ���� ������ ��������

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

		for (int j = 0; j < DestIDX; j++)
			cout << DestArr[j] << " ";

		cout << endl;


		// Merge ����
		i = varPair->GetX();
		DestIDX = 0;

		while (i <= varPair->GetY())
		{
			Data[i] = DestArr[DestIDX++];
			i++;
		} // end of while

		for (int j = 0; j <= End; j++)
			cout << Data[j] << " ";

		cout << endl;

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
	while (i < n)
	{
		j = 0;
		while (j < n - 1)
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
	while (i < n)
	{
		j = i + 1;
		while (j < n)
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

	int Temp = Data[left];
	Data[left] = Data[right];
	Data[right] = Temp;

}
// End of Swap