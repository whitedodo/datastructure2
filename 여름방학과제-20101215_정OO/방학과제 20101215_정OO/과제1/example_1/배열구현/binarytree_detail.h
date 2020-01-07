/*
     금오공과대학교
     과제: 방학(Binary Tree) 과제 - 1번(배열 구현)
     학과: Business & CSE
     학번: 20101215
     이름: 정원영
*/

#ifndef _BINARYTREE_DETAIL_H_
#define _BINARYTREE_DETAIL_H_

#include "binarytree.h"

const char StrToCh(std::string Data);

template <class T>
void BinaryTree<T>::Preorder(int index){
	if (pArr[index] == 0 || index > GetMaxSize())
		return;

	cout << pArr[index] << " ";
	Preorder(2 * index);
	Preorder(2 * index + 1);
}

template <class T>
void BinaryTree<T>::Inorder(int index){
	if (pArr[index] == 0 || index > GetMaxSize())
		return;

	Inorder(index * 2);
	cout << pArr[index] << " ";
	Inorder(index * 2 + 1);
}

template <class T>
void BinaryTree<T>::Postorder(int index){

	if (pArr[index] == 0 || index > GetMaxSize())
		return;

	Postorder(index * 2);
	Postorder(index * 2 + 1);
	cout << pArr[index] << " ";

}

template <class T>
void BinaryTree<T>::Levelorder(int index){

	if (pArr[index] == 0 || index > GetMaxSize())
		return;

	cout << pArr[index] << " ";
	Levelorder(index + 1);

}

// 트리에 실제 데이터 입력 - SetData(string Data);
template <class T>
void BinaryTree<T>::SetData(std::string Data){

	int EndIDX = Data.length(); // 문자열의 길이 반환
	int Count = 1;

	// 공간 초기화
	pArr = new T[GetMaxSize() + 1];

	for (int i = 0; i < (GetMaxSize() + 1); i++)
		pArr[i] = 0;

	// 데이터 입력
	string TmpData;

	for (int StartIDX = 0; StartIDX < EndIDX; StartIDX++)
	{
		const char chData = StrToCh(Data.substr(StartIDX, 1));

		// 숫자 판별
		if (isdigit(chData))
			TmpData.push_back(chData);

		// 공백 판별
		if (chData == ' ')
		{
			if (!TmpData.empty())
			{
				pArr[atoi(TmpData.c_str())] = atoi(TmpData.c_str());
				Count++;
				TmpData.erase();

			} // End of if

		} // End of if

		// 마지막 문자 판별
		if ((StartIDX + 1) == EndIDX)
		{
			if (isdigit(chData))
				TmpData.push_back(chData);

			if (!TmpData.empty())
			{

				pArr[atoi(TmpData.c_str())] = atoi(TmpData.c_str());
				Count++;
				TmpData.erase();
			}
		} // End of if

	} // End of while
}

// 갯수 파악용 - GetCount(string Data);
template <class T>
int BinaryTree<T>::GetCount(std::string Data){

	int EndIDX = Data.length(); // 문자열의 길이 반환
	int Count = 0;

	string TmpData;

	for (int StartIDX = 0; StartIDX < EndIDX; StartIDX++)
	{
		const char chData = StrToCh(Data.substr(StartIDX, 1));

		// 숫자 판별
		if (isdigit(chData))
			TmpData.push_back(chData);

		// 공백 판별
		if (chData == ' ')
		{
			if (!TmpData.empty())
			{
				Count++;
				TmpData.erase();

			} // End of if

		} // End of if

		// 마지막 문자 판별
		if ((StartIDX + 1) == EndIDX)
		{
			if (isdigit(chData))
				TmpData.push_back(chData);

			if (!TmpData.empty())
			{
				Count++;
				TmpData.erase();
			}
		} // End of if

	} // End of while

	return Count;
}

template <class T>
void BinaryTree<T>::SetMaxSize(int n){
	MAX_SIZE = n;
}

template <class T>
int BinaryTree<T>::GetMaxSize(){
	return MAX_SIZE;
}

template <class T>
void BinaryTree<T>::DestoryTree(){
	delete pArr;
}

#endif