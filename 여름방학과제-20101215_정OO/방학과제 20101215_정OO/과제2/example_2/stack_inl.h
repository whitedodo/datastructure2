/*
금오공과대학교
과제: 방학(Binary Tree) 과제5 - 2번(계산식)
학과: Business & CSE
학번: 20101215
이름: 정원영
*/

#ifndef _STACK_INL_H_
#define _STACK_INL_H_

#include <iostream>
#include "stack.h"

using namespace std;

template <class T>
Stack<T>::Stack(){
	Count = 0;
	Top = new Node<T>();
}

template <class T>
Stack<T>::~Stack(){

	Node<T>* prevNode;
	while (Top != NULL)
	{
		prevNode = Top;
		Top = Top->prev;
		delete prevNode;
	}
}

template <class T>
void Stack<T>::push(T Data){

	if (Top->Data == NULL)
	{
		Top->Data = Data;
	}
	else
	{
		Node<T>* createNode = new Node<T>();
		createNode->Data = Data;
		createNode->prev = Top;
		createNode->next = NULL;

		Top->next = createNode;
		Top = Top->next;
	}

	Count++;

}

template <class T>
T Stack<T>::pop(){

	T Data = NULL;

	if (Top->prev == NULL)
	{
		Top->prev = NULL;
		Top->next = NULL;
		Data = Top->Data;
		Top->Data = NULL;
	}
	else{

		Node<T>* prevNode = Top->prev;
		Data = Top->Data;
		delete Top;

		Top = prevNode;
	}
	Count--;

	return Data;
}

template <class T>
T Stack<T>::get_stack_top(void)
{
	return (Top->Data == NULL) ? -1 : Top->Data;
}

template <class T>
int Stack<T>::is_stack_empty(void)
{
	return (Top->Data == NULL);
}

template <class T>
int Stack<T>::GetCount(){
	return Count;
}


// 2. Stack Pointer with TreeNode

template <class T>
pStack<T>::pStack(){

	Count = 0;
	Top = new pNode<T>();
	Top->Data = NULL;
	Top->prev = NULL;
	Top->next = NULL;
}

template <class T>
pStack<T>::~pStack(){

	pNode<T>* curNode;

	while (Top != NULL)
	{
		curNode = Top;
		Top = Top->prev;
		delete curNode;
	} // End of while

}

template <class T>
void pStack<T>::push(T* _pNode){

	pNode<T>* newNode = new pNode<T>();
	newNode->Data = _pNode;
	newNode->prev = NULL;
	newNode->next = NULL;

	// 신규 추가
	if (Top->Data != NULL)
	{
		newNode->prev = Top;
		Top->next = newNode;
		Top = Top->next;
	}
	else
	{
		Top = newNode;
	} // End of if

	Count++;

}

template <class T>
T* pStack<T>::pop(){

	T* pDataNode;
	pNode<T>* pNode;

	// 데이터가 없을 때
	if (Top->Data == NULL)
		return 0;

	if (Top->prev != NULL)
	{
		pDataNode = Top->Data;
		pNode = Top;
		Top = Top->prev;
		delete pNode;
	}
	else
	{
		pDataNode = Top->Data;
		Top->Data = NULL;
		Top->next = NULL;
	} // End of if

	Count--;

	return pDataNode;
}

template <class T>
T* pStack<T>::GetTop(){
	return Top->Data;
}

template <class T>
int pStack<T>::IsEmpty(){

	if (Top->Data != NULL)
		return 0;
	else
		return 1;
}

template <class T>
int pStack<T>::GetCount(){
	return Count;
}

// 3.

stringStack::stringStack(){
	Top = new stringNode();
	Top->Height = NULL;
	Top->Data = "NULL";
	Top->prev = NULL;
	Top->next = NULL;
	Count = 0;
}

stringStack::~stringStack(){

	stringNode* curNode;

	while (Top != NULL)
	{
		curNode = Top;
		Top = Top->prev;
		delete curNode;
	} // End of while
}

void stringStack::push(std::string _Data, int _Height){
	stringNode* newNode = new stringNode();
	newNode->Data = _Data;
	newNode->Height = _Height;
	newNode->prev = NULL;
	newNode->next = NULL;

	// 신규 추가
	if (Top->Data != "NULL")
	{
		newNode->prev = Top;
		Top->next = newNode;
		Top = Top->next;
	}
	else
	{
		Top->Data = _Data;
		Top->Height = _Height;
	} // End of if

	Count++;
}

std::string stringStack::pop(){
	std::string pData;
	stringNode* pNode;

	// 데이터가 없을 때
	if (Top->Data == "NULL")
		return 0;

	if (Top->prev != NULL)
	{
		pData = Top->Data;
		pNode = Top;
		Top = Top->prev;
		delete pNode;
	}
	else
	{
		pData = Top->Data;
		Top->Data = "NULL";
		Top->next = NULL;
	} // End of if

	Count--;

	return pData;
}

int stringStack::GetCount(){
	return Count;
}

std::string stringStack::at(int height){

	std::string pData = "NULL";

	stringNode* pNode = Top;
	while (1)
	{
		// 루프 탈출
		if (pNode == NULL)
			break;

		if (pNode->Height == height){
			pData = pNode->Data;
			break;
		}

		pNode = pNode->prev;
	}

	return pData;
}

#endif

