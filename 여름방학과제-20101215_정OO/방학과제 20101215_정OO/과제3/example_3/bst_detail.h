/*
금오공과대학교
과제 : 방학(Binary Search Tree) 과제5 - 3번
학과 : Business & CSE
학번 : 20101215
이름 : 정원영
*/

#ifndef _BST_DETAIL_H_
#define _BST_DETAIL_H_

#include <iostream>
#include "bst.h"

using namespace std;

template <class T>
BST<T>::BST(){
	Top = NULL;
	HeadNode = NULL;
}

template <class T>
BST<T>::~BST(){
	DestoryTree(Top);
}

template <class T>
void BST<T>::DestoryTree(TreeNode<T>* pNode){

	if (pNode != NULL)
	{
		DestoryNode(pNode);
		DestoryTree(pNode->LeftNode);
		DestoryTree(pNode->RightNode);
	}
}

template <class T>
void BST<T>::DestoryNode(TreeNode<T>* pNode){
	delete pNode;
}

template <class T>
void BST<T>::SetLine(bool check){
	printLine = check;
}

template <class T>
bool BST<T>::GetLine(){
	return printLine;
}

template <class T>
TreeNode<T>* BST<T>::GetNode(){
	return HeadNode;
}

template <class T>
void BST<T>::PrintOut(TreeNode<T>* pNode){
	Stack<T>* newData = new Stack<T>();
	PostOrder(pNode, 0, newData);
	cout << endl;
}

template <class T>
void BST<T>::SetMax(int _Max){
	Max = _Max;
}

template <class T>
void BST<T>::SetData(int Type, T Data){

	switch (Type)
	{
	case ROOT:
		RootData = Data;
		break;

	case NODE:
		TreeData.append(Data);
		break;
	}

}

template <class T>
void BST<T>::PostOrder(TreeNode<T>* pNode, int level, Stack<T>* pStackNode){

	std::string Data;

	// TreeNode가 아닐 때
	if (pNode != NULL)
	{
		// 라인 바꾸기
		if (GetLine() == true)
		{
			int i = 0;
			std::string tmpData;

			while (i < level)
			{
				tmpData.append(pStackNode->at(i));
				i++;
			}

			i = 0;
			int length = tmpData.length();
			tmpData.erase();

			while (i < length)
			{
				tmpData.push_back(' ');
				i++;
			}

			cout << endl;
			cout << tmpData;

			SetLine(false);
		}

		// 루트 위치 설정
		if (level == 0)
		{
			Data.append(pNode->Data);
			SetData(ROOT, pNode->Data);
		}

		// 노드 위치 설정
		if (level != 0)
		{
			Data.append(" --- ");
			Data.append(pNode->Data);
		}

		// cout << Data; - Stack 내용

		if (pStackNode->GetCount() <= GetMax()){
			pStackNode->push(Data, level);
		}

		cout << Data;

		// Node
		if (pNode->LeftNode == NULL && pNode->LeftNode == NULL)
		{
			SetLine(true);

			if ((level + 1) != GetMax())
				cout << " --- 0 ";
		}

		PostOrder(pNode->LeftNode, level + 1, pStackNode);
		PostOrder(pNode->RightNode, level + 1, pStackNode);
	}
}


template <class T>
TreeNode<T>* BST<T>::Create(T _Data){
	TreeNode<T>* pNode = new TreeNode<T>();
	pNode->Data = _Data;
	pNode->LeftNode = NULL;
	pNode->RightNode = NULL;

	return pNode;
}

template <class T>
TreeNode<T>* BST<T>::Search(TreeNode<T>* _pNode, int level, int curlevel){

	// 최대 레벨 찾기
	if (GetMax() < (level + 1))
		SetIncreaseMax();

	if (_pNode == NULL)
		return NULL;
	if (GetMax() == curlevel)
		return _pNode;

	Search(_pNode->LeftNode, level + 1, curlevel);
	Search(_pNode->RightNode, level + 1, curlevel);
}

template <class T>
int BST<T>::GetMax(){
	return Max;
}

template <class T>
void BST<T>::SetIncreaseMax(){
	Max++;
}

template <class T>
void BST<T>::Insert(TreeNode<T>* pTop, TreeNode<T>* _pNode, int level){

	// 최대 레벨 찾기
	if (GetMax() < (level + 1))
		SetIncreaseMax();

	if (HeadNode == NULL)
	{
		HeadNode = _pNode;
		Top = HeadNode;
	}
	else{

		if (pTop->Data > _pNode->Data){

			if (pTop->LeftNode == NULL)
				pTop->LeftNode = _pNode;
			else
				Insert(pTop->LeftNode, _pNode, level + 1);

		}

		if (pTop->Data == _pNode->Data){

			if (pTop->LeftNode == NULL)
				pTop->LeftNode = _pNode;
			else
				Insert(pTop->LeftNode, _pNode, level + 1);

		}

		if (pTop->Data < _pNode->Data){

			if (pTop->RightNode == NULL)
				pTop->RightNode = _pNode;
			else
				Insert(pTop->RightNode, _pNode, level + 1);
		}
	}

}

template <class T>
TreeNode<T>* BST<T>::Remove(TreeNode<T>* _pNode, T _Data){

	TreeNode<T>* tmpNode;

	if (_pNode == NULL)
	{
		// 노드 존재하지 않음
	}
	else if (_pNode->Data > _Data)
		_pNode->LeftNode = Remove(_pNode->LeftNode, _Data);
	else if (_pNode->Data < _Data)
		_pNode->RightNode = Remove(_pNode->RightNode, _Data);
	else
	{
		if (_pNode->LeftNode != NULL && _pNode->RightNode != NULL)
		{
			tmpNode = findMinNode(_pNode->RightNode);
			_pNode->Data = tmpNode->Data;
			_pNode->RightNode = Remove(_pNode->RightNode, _Data);
		}
		else{
			tmpNode = _pNode;
			if (_pNode->LeftNode == NULL)
				_pNode = _pNode->RightNode;
			else if (_pNode->RightNode == NULL)
				_pNode = _pNode->LeftNode;

			delete tmpNode;
		}
	}

	return _pNode;
}

template <class T>
TreeNode<T>* BST<T>::findMinNode(TreeNode<T>* Tree){
	if (Tree == NULL)
		return NULL;
	if (Tree->LeftNode != NULL)
		findMinNode(Tree->LeftNode);
	else
		return Tree;
}

template <class T>
Stack<T>::Stack(){
	Top = new Node<T>();
	Top->Data = "NULL";
	Top->prev = NULL;
	Top->next = NULL;
}

template <class T>
Stack<T>::~Stack(){

	Node<T>* curNode;

	while (Top != NULL)
	{
		curNode = Top;
		Top = Top->prev;
		delete curNode;
	} // End of while
}

template <class T>
void Stack<T>::push(T _Data, int _Height){
	Node<T>* newNode = new Node<T>();
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

template <class T>
T Stack<T>::pop(){
	T pData;
	Node<T>* pNode;

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

template <class T>
int Stack<T>::GetCount(){
	return Count;
}

template <class T>
T Stack<T>::at(int height){

	T pData = "NULL";

	Node<T>* pNode = Top;
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



