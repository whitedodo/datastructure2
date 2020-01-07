/*
     �ݿ��������б�
     ����: ����(Binary Tree) ���� - 1��(�迭 ����)
     �а�: Business & CSE
     �й�: 20101215
     �̸�: ������
*/

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>
#include <string>

template <class T>
class BinaryTree{
public:
	void Preorder(int index);
	void Inorder(int index);
	void Postorder(int index);
	void Levelorder(int index);

	void SetData(std::string Data);

	int GetCount(std::string Data);

	int GetMaxSize();
	void SetMaxSize(int n);

	void DestoryTree();

private:
	int MAX_SIZE;
	T *pArr;
};

#include "binarytree_detail.h"

#endif