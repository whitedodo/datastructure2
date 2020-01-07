/*
	Subject - JLand(Sort) Project / j_ds_controller.h
	Created Date - 2014. 10. 8
	Description - Data Structure / Controller ����
	[Version]
*/

#include "j_model.h"

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