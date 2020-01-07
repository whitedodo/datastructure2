/*
금오공과대학교
과제: 방학(Binary Tree) 과제5 - 2번(계산식)
학과: Business & CSE
학번: 20101215
이름: 정원영
*/

#ifndef _TREE_DETAIL_H_
#define _TREE_DETAIL_H_

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "tree.h"

using namespace std;

std::string IntToString(int number);
std::string CharToString(char op);
const char stringToChar(std::string D, int i);

template <class T>
Tree<T>::Tree(){
	newStack = new pStack< TreeNode<std::string> >();
}

template <class T>
Tree<T>::~Tree(){
	DestoryTree(newStack->pop());
}


template <class T>
void Tree<T>::DestoryTree(TreeNode<T>* pNode){

	if (pNode != NULL)
	{
		DestoryTree(pNode->LeftNode);
		DestoryTree(pNode->RightNode);
		DestoryNode(pNode);
	}
}

template <class T>
void Tree<T>::DestoryNode(TreeNode<T>* pNode){
	delete pNode;
}

template <class T>
TreeNode<T>* Tree<T>::GetTree(){
	return newStack->GetTop();
}

template <class T>
void Tree<T>::SetLine(bool check){
	printLine = check;
}

template <class T>
bool Tree<T>::GetLine(){
	return printLine;
}

template <class T>
void Tree<T>::PrintOut(TreeNode<T>* pNode){
	stringStack* newData = new stringStack();
	PostOrder(pNode, 0, newData);
	cout << endl;
}

template <class T>
void Tree<T>::SetData(int Type, std::string Data){

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
void Tree<T>::PostOrder(TreeNode<T>* pTreeNode, int level, stringStack* pStackNode){

	std::string Data;

	// TreeNode가 아닐 때
	if (pTreeNode != NULL)
	{
		// 라인 바꾸기
		if (GetLine() == true)
		{
			std::string pData;
			int i = 0;

			int iStartNum = level;
			int iEndNum = pStackNode->GetCount();

			if (GetLine() == true){

				while (iStartNum < iEndNum)
				{
					pStackNode->pop();
					iStartNum++;
				}
			}

			while (i < pStackNode->GetCount())
			{
				string pTmpData = pStackNode->at(i);
				pData.append(pTmpData);
				i++;
			}


			cout << endl;

			i = 0;
			iEndNum = pData.length();
			while (i < iEndNum)
			{
				cout << " ";
				i++;
			}

			SetLine(false);
		}

		if (level == 0)
			cout << pTreeNode->Data;
		else
			cout << " --- " << pTreeNode->Data;

		// Node
		if (pTreeNode->LeftNode == NULL && pTreeNode->LeftNode == NULL)
		{
			SetLine(true);
		}
		else
		{

			// 루트 위치 설정
			if (level == 0)
			{
				Data.append(pTreeNode->Data);
				SetData(ROOT, pTreeNode->Data);
			}

			// 노드 위치 설정
			if (level != 0)
			{
				if (pTreeNode->Data != "~")
				{
					Data.append(" --- ");
					Data.append(pTreeNode->Data);
				}
			}

			// cout << Data; - Stack 내용

			if (Data != ""){
				pStackNode->push(Data, level);
			}
		}

		PostOrder(pTreeNode->LeftNode, level + 1, pStackNode);
		PostOrder(pTreeNode->RightNode, level + 1, pStackNode);
	}

}

template <class T>
std::string Tree<T>::GetResult(int number, char op){

	std::string pData;

	if (op == '~'){
		pData.push_back(op);
	}
	else{
		pData.push_back(op);
		pData.push_back(' ');
		pData.push_back('(');
		pData.append(IntToString(number));
		pData.push_back(')');
	}

	return pData;
}


/*
void Tree::Make(int left, int right, int result, char op){
cout << "left:" << left << "/right:" << right << "/result:" << result << "/op:" << op << endl;
}

*/

template <class T>
void Tree<T>::Make(int left, int right, int result, char op){

	TreeNode<T>* resultNode, *leftNode, *rightNode;
	bool Check = false;

	// 스택이 비어있을 때
	if (newStack->IsEmpty())
	{
		if (op == '~')
		{
			leftNode = new TreeNode<T>();
			resultNode = new TreeNode<T>();

			leftNode->Data = IntToString(left);
			leftNode->LeftNode = NULL;
			leftNode->RightNode = NULL;

			resultNode->Data = GetResult(result, op);
			resultNode->LeftNode = leftNode;
			resultNode->RightNode = NULL;
		}
		else{

			leftNode = new TreeNode<T>();
			rightNode = new TreeNode<T>();
			resultNode = new TreeNode<T>();

			leftNode->LeftNode = NULL;
			leftNode->Data = IntToString(left);
			leftNode->RightNode = NULL;

			rightNode->LeftNode = NULL;
			rightNode->Data = IntToString(right);
			rightNode->RightNode = NULL;

			resultNode->LeftNode = leftNode;
			resultNode->Data = GetResult(result, op);
			resultNode->RightNode = rightNode;
		}

		newStack->push(resultNode);

	}
	else
	{

		if (newStack->GetCount() > 1){

			TreeNode<T>* pNode = newStack->GetTop();

			// '^'일 때
			if (op == '^'){

				leftNode = new TreeNode<T>();
				rightNode = new TreeNode<T>();
				resultNode = new TreeNode<T>();

				leftNode->LeftNode = NULL;
				leftNode->Data = IntToString(left);
				leftNode->RightNode = NULL;

				rightNode->LeftNode = NULL;
				rightNode->Data = IntToString(right);
				rightNode->RightNode = NULL;

				resultNode->LeftNode = leftNode;
				resultNode->Data = GetResult(result, op);
				resultNode->RightNode = rightNode;

				newStack->push(resultNode);

				Check = true;
				// Push 구현

			} // End of if
			// 1-1. '~'일 때
			if (op == '~')
			{
				leftNode = new TreeNode<T>();
				resultNode = new TreeNode<T>();

				leftNode->Data = IntToString(left);
				leftNode->LeftNode = NULL;
				leftNode->RightNode = NULL;

				resultNode->Data = GetResult(result, op);
				resultNode->LeftNode = leftNode;
				resultNode->RightNode = NULL;

				newStack->push(resultNode);

				Check = true;
				// Push 구현

			} // End of if

			// 1-2. '~'일 때
			if (pNode->Data == "~"){

				leftNode = new TreeNode<T>();
				rightNode = new TreeNode<T>();
				resultNode = new TreeNode<T>();

				leftNode = newStack->pop();

				rightNode->LeftNode = NULL;
				rightNode->Data = IntToString(right);
				rightNode->RightNode = NULL;

				resultNode->LeftNode = leftNode;
				resultNode->Data = GetResult(result, op);
				resultNode->RightNode = rightNode;

				newStack->push(resultNode);

				Check = true;
				// Push 구현

			} // End of if

			// LeftNode - RightNode
			if (Check == false){

				int LeftNumber;
				int RightNumber;

				leftNode = newStack->pop();
				rightNode = newStack->pop();

				LeftNumber = resultToInt(rightNode->Data);
				RightNumber = resultToInt(leftNode->Data);

				if (LeftNumber == left && RightNumber == right)
				{
					resultNode = new TreeNode<T>();
					resultNode->Data = GetResult(result, op);
					resultNode->LeftNode = rightNode;
					resultNode->RightNode = leftNode;

					newStack->push(resultNode);
				}
				else
				{
					newStack->push(rightNode);
					newStack->push(leftNode);

					leftNode = new TreeNode<T>();
					rightNode = new TreeNode<T>();
					resultNode = new TreeNode<T>();

					leftNode->LeftNode = NULL;
					leftNode->Data = IntToString(left);
					leftNode->RightNode = NULL;

					rightNode->LeftNode = NULL;
					rightNode->Data = IntToString(right);
					rightNode->RightNode = NULL;

					resultNode->LeftNode = leftNode;
					resultNode->Data = GetResult(result, op);
					resultNode->RightNode = rightNode;

					newStack->push(resultNode);

				} // End of if

			} // End of if
		}
		else
		{
			// 1-1. '~'일 때
			if (op == '~')
			{
				leftNode = new TreeNode<T>();
				resultNode = new TreeNode<T>();

				leftNode->Data = IntToString(left);
				leftNode->LeftNode = NULL;
				leftNode->RightNode = NULL;

				resultNode->Data = GetResult(result, op);
				resultNode->LeftNode = leftNode;
				resultNode->RightNode = NULL;

				newStack->push(resultNode);

				Check = true;
				// Push 구현

			} // End of if
			else
			{
				leftNode = new TreeNode<T>();
				rightNode = new TreeNode<T>();
				resultNode = new TreeNode<T>();

				leftNode->LeftNode = NULL;
				leftNode->Data = IntToString(left);
				leftNode->RightNode = NULL;

				rightNode->LeftNode = NULL;
				rightNode->Data = IntToString(right);
				rightNode->RightNode = NULL;

				resultNode->LeftNode = leftNode;
				resultNode->Data = GetResult(result, op);
				resultNode->RightNode = rightNode;

				newStack->push(resultNode);
			}

		}

	} // End of if
}

template <class T>
int Tree<T>::resultToInt(std::string D){

	int i = 0, j = 0;
	int length = D.length();
	int result = 0;

	char ch;
	bool Check = false;
	bool Negative = false;

	while (i < length)
	{
		ch = stringToChar(D, i);

		// ) 일 때 종료처리
		if (Check == true && ch != ')')
		{
			if (ch == '-')
			{
				Negative = true;
			}
			else
			{
				// 숫자 범위 파악
				if (ch >= '0' && ch <= '9')
				{
					result = (result * 10) + ch - '0';
				} // End of if

			} // End of if

		} // End of if

		if (ch == '('){
			Check = true;
		} // End of if

		// Negative 수 처리
		if (ch == ')'){
			Check = false;

			// 음수로 변환(Result)
			if (Negative == true)
			{
				result = result * (-1);
			} // End of if

		} // End of if

		i++;
	} // End of while

	return result;

}

std::string IntToString(int number)
{
	ostringstream convStream;
	convStream << number;
	return convStream.str();
}

std::string CharToString(char op){
	string D;
	D.push_back(op);
	return D;
}

const char stringToChar(std::string D, int i){
	string T_Data = D.substr(i, 1);
	return T_Data.at(0);
}

#endif

