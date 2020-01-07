/*
     �ݿ��������б�
     ����: ����(Binary Tree) ���� - 1��(���ᱸ�� ����)
     �а�: Business & CSE
     �й�: 20101215
     �̸�: ������
*/

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>
#include <string>


// 1. ���� ����
const int ROOT = 0; // Ÿ��:��Ʈ
const int NODE = 1; // Ÿ��:���

// 2. ���� ����(DECISION�� �̿� - Tree �ڷ� ���࿡ ���)
const int LEFT = 0;  // ���� 
const int RIGHT = 1; // ������
const int ALL = 2;   // ��� ��
const int NONE = 3;  // �ʱ�

// 3. Visit ����

template <class T>
class VisitNode{
public:
	int type;
	int height;
	T data;
	VisitNode<T>* link;
};

template <class T>
class Visit{
public:
	void InsertNode(VisitNode<T>* pNode);
	VisitNode<T>* CreateNode(int Type, T Element, int height);
	VisitNode<T>* GetTopNode();
	VisitNode<T>* GetHeadNode();
	void SetHeight(int height);
	int GetHeight();

	Visit();
	~Visit();

private:
	VisitNode<T>* HeadNode;
	VisitNode<T>* TopNode;
	int MaxHeight;
};

// 4. Tree ����

template <class T>
class TreeNode{
public:
	TreeNode<T>* LeftChild;
	T Data;
	TreeNode<T>* RightChild;
};

template <class T>
class BinaryTree{
public:
	BinaryTree();
	~BinaryTree();
	void DestoryTree(TreeNode<T>* pNode);
	void DestoryNode(TreeNode<T>* pNode);


	TreeNode<T>* CreateNode(T Element);
	void Insert(int Type, TreeNode<T>* CenterNode, TreeNode<T>* pNode);
	TreeNode<T>* GetRootNode();
	void SetRootNode(TreeNode<T>* pNode);

	void Preorder(TreeNode<T>* pNode);
	void Inorder(TreeNode<T>* pNode);
	void Postorder(TreeNode<T>* pNode);
	void Levelorder(TreeNode<T>* pNode);
	void PrintLevelorder(TreeNode<T>* pNode, int level);
	int GetHeight();

private:
	TreeNode<T>* rootNode;

};

#include "visitor_detail.h"
#include "binarytree_detail.h"

#endif