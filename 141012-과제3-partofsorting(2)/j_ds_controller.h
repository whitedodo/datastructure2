/*
	Subject - JLand(Sort) Project / j_ds_controller.h
	Director - ........ Jeong / OOOOOOOOOOOOOOO�� / Business & Computer Science
	Created Date - 2014. 10. 8
	Description - Data Structure / Controller ����
	[Version]
*/

#ifndef _J_DS_CONTROLLER_H_
#define _J_DS_CONTROLLER_H_

/// Stack
template <typename T>
Stack<T>::Stack(){
	Top = J_NULL;
	Count = 0;
}

template <typename T>
Stack<T>::~Stack(){

	Node<T>* ptrNode = J_NULL;
	while (Top != J_NULL)
	{
		ptrNode = Top;
		delete[] ptrNode;
		ptrNode = J_NULL;
	} // end of while

	delete[] Top;
	Top = J_NULL;

}

template <typename T>
void Stack<T>::Push(T Data){

	Node<T>* ptrNode = new Node<T>();
	ptrNode->Data = Data;
	ptrNode->prev = J_NULL;
	ptrNode->next = J_NULL;

	if (Top == J_NULL)
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

	T Data = J_NULL;

	if (Top != J_NULL)
	{
		Node<T>* ptrNode = J_NULL;
		ptrNode = Top;
		Data = Top->Data;

		Top = Top->prev;

		if (Top != J_NULL)
			Top->next = J_NULL;

		delete[] ptrNode;
		ptrNode = J_NULL;

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
	front = J_NULL;
	rear = J_NULL;
	Count = 0;
}

template <typename T>
Queue<T>::~Queue(){

	Node<T>* ptr = J_NULL;

	while (front != J_NULL)
	{
		ptr = front;
		front = front->next;

		delete[] ptr;
		ptr = J_NULL;
	} // end of while

	delete[] front;
	delete[] rear;

	// ������ ����
	front = J_NULL;
	rear = J_NULL;

}

template <typename T>
void Queue<T>::Push(T Data){

	Node<T>* NewNode = new Node<T>();

	NewNode->Data = Data;
	NewNode->prev = NewNode;
	NewNode->next = J_NULL;

	// �ʱ� ��
	if (front == J_NULL)
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

	Node<T>* ptr = J_NULL;
	T Data = J_NULL;

	if (front != J_NULL)
	{
		Data = front->Data;

		ptr = front;

		front = front->next;

		if (front != J_NULL){ // Front�� J_NULL�� �ƴ� ��
			front->prev = rear;
			rear->prev = front;
		}
		else
			front = rear = J_NULL;

		delete[] ptr;
		ptr = J_NULL;

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
	First = J_NULL;
	TopNode = J_NULL;
	Count = 0;
	SortType = Type;
}

template <typename T>
LinkedList<T>::~LinkedList(){

	while (First != J_NULL)
	{
		Node<T>* ptr = First;
		First = First->next;
		delete[] ptr;
		ptr = J_NULL;
	}

	delete[] First;
	delete[] TopNode;
	First = J_NULL;
	TopNode = J_NULL;
}

template <typename T>
void LinkedList<T>::Insert(T Data){

	Node<T>* NewNode = J_NULL;
	NewNode = new Node<T>();

	NewNode->Data = Data;
	NewNode->next = J_NULL;

	if (First == J_NULL)
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
		Node<T>* curNode = J_NULL;
		Node<T>* prevNode = J_NULL;
		Node<T>* nextNode = J_NULL;

		switch (SortType)
		{
			case SORT: // ���� ��Ģ�� ��� ����
				curNode = First;
				prevNode = curNode;

				while (curNode != J_NULL)
				{
					if (curNode->Data >= NewNode->Data)
					{
						if (curNode->next != J_NULL)
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
			
				// �����Ͱ� �������� ������
				if (curNode == NULL)
					prevNode->next = NewNode;

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

#endif