/*
     �ݿ��������б�
     ����: ����(Binary Tree) ���� - 1��(�迭 ����)
     �а�: Business & CSE
     �й�: 20101215
     �̸�: ������
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

// Ʈ���� ���� ������ �Է� - SetData(string Data);
template <class T>
void BinaryTree<T>::SetData(std::string Data){

	int EndIDX = Data.length(); // ���ڿ��� ���� ��ȯ
	int Count = 1;

	// ���� �ʱ�ȭ
	pArr = new T[GetMaxSize() + 1];

	for (int i = 0; i < (GetMaxSize() + 1); i++)
		pArr[i] = 0;

	// ������ �Է�
	string TmpData;

	for (int StartIDX = 0; StartIDX < EndIDX; StartIDX++)
	{
		const char chData = StrToCh(Data.substr(StartIDX, 1));

		// ���� �Ǻ�
		if (isdigit(chData))
			TmpData.push_back(chData);

		// ���� �Ǻ�
		if (chData == ' ')
		{
			if (!TmpData.empty())
			{
				pArr[atoi(TmpData.c_str())] = atoi(TmpData.c_str());
				Count++;
				TmpData.erase();

			} // End of if

		} // End of if

		// ������ ���� �Ǻ�
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

// ���� �ľǿ� - GetCount(string Data);
template <class T>
int BinaryTree<T>::GetCount(std::string Data){

	int EndIDX = Data.length(); // ���ڿ��� ���� ��ȯ
	int Count = 0;

	string TmpData;

	for (int StartIDX = 0; StartIDX < EndIDX; StartIDX++)
	{
		const char chData = StrToCh(Data.substr(StartIDX, 1));

		// ���� �Ǻ�
		if (isdigit(chData))
			TmpData.push_back(chData);

		// ���� �Ǻ�
		if (chData == ' ')
		{
			if (!TmpData.empty())
			{
				Count++;
				TmpData.erase();

			} // End of if

		} // End of if

		// ������ ���� �Ǻ�
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