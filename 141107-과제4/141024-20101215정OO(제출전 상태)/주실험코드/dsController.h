/*
Subject - JLand(Sort) Project / j_ds_controller.h
Director - Wonyeong. Jeong / Kumoh National Institute of Technology / Business & Computer Science
Created Date - 2014. 10. 8
Description - data Structure / Controller 영역
[Version]
*/

#ifndef _J_DS_CONTROLLER_H_
#define _J_DS_CONTROLLER_H_

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
void Stack<T>::Push(T data){

	Node<T>* ptrNode = new Node<T>();
	ptrNode->data = data;
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

	T data = NULL;

	if (Top != NULL)
	{
		Node<T>* ptrNode = NULL;
		ptrNode = Top;
		data = Top->data;

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

	return data;
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

	// 안전한 삭제
	front = NULL;
	rear = NULL;

}

template <typename T>
void Queue<T>::Push(T data){

	Node<T>* NewNode = new Node<T>();

	NewNode->data = data;
	NewNode->prev = NewNode;
	NewNode->next = NULL;

	// 초기 빈값
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
			NewNode->prev = rear;
			front->prev = NewNode;
			rear->next = NewNode;
			rear = rear->next;

		} // end of if

	} // end of if

	Count++;

}

template <typename T>
T Queue<T>::Pop(){

	Node<T>* ptr = NULL;
	T data = NULL;

	if (front != NULL)
	{
		data = front->data;

		ptr = front;

		front = front->next;

		if (front != NULL){ // Front가 NULL이 아닐 때
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
		// 비어있음을 알리는 것 넣어도 됨.
	} // end of if

	return data;
}

// End of Queue

/// Linked List
template <typename T>
LinkedList<T>::LinkedList(){
	First = NULL;
	TopNode = NULL;
	Count = 0;
}

template <>
LinkedList<std::string>::~LinkedList(){

	while (First != NULL)
	{
		Node<std::string>* ptr = First;
		First = First->next;
		delete ptr;
		ptr = NULL;
	}

	delete[] First;
	First = NULL;
	TopNode = NULL;
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
	First = NULL;
	TopNode = NULL;
}

template <typename T>
void LinkedList<T>::Insert(T data){

	Node<T>* NewNode = NULL;
	NewNode = new Node<T>();

	NewNode->data = data;
	NewNode->next = NULL;

	if (First == NULL)
	{
		First = NewNode;
		TopNode = First;
	}
	else
	{
		TopNode->next = NewNode;
		NewNode->prev = TopNode;
		TopNode = TopNode->next;

	} // end of if

	Count++;
}

// End of Linked List

#endif