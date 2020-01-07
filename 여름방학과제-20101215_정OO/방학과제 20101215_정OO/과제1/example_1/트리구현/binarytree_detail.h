/*
     금오공과대학교
     과제: 방학(Binary Tree) 과제 - 1번(연결구조 구현)
     학과: Business & CSE
     학번: 20101215
     이름: 정원영
*/

#ifndef _BINARYTREE_DETAIL_H_
#define _BINARYTREE_DETAIL_H_

#include "binarytree.h"

template <class T>
BinaryTree<T>::BinaryTree(){
	rootNode = NULL;
}

template <class T>
BinaryTree<T>::~BinaryTree(){
	DestoryTree(GetRootNode());
}

template <class T>
void BinaryTree<T>::DestoryTree(TreeNode<T>* pNode){

	if (pNode != NULL)
	{
		DestoryTree(pNode->LeftChild);
		DestoryTree(pNode->RightChild);
		DestoryNode(pNode);
	}
}

template <class T>
void BinaryTree<T>::DestoryNode(TreeNode<T>* pNode){
	delete pNode;
}

template <class T>
void BinaryTree<T>::Insert(int Type, TreeNode<T>* CenterNode, TreeNode<T>* pNode){

	switch (Type)
	{
		case LEFT:
			CenterNode->LeftChild = pNode;
			break;

		case RIGHT:
			CenterNode->RightChild = pNode;
			break;
	}
}

template <class T>
TreeNode<T>* BinaryTree<T>::CreateNode(T Element){

	TreeNode<T>* newNode = new TreeNode<T>();

	newNode->Data = Element;
	newNode->LeftChild = NULL;
	newNode->RightChild = NULL;

	return newNode;
}

template <class T>
TreeNode<T>* BinaryTree<T>::GetRootNode(){
	return rootNode;
}

template <class T>
void BinaryTree<T>::SetRootNode(TreeNode<T>* pNode){

	if (rootNode == NULL)
		rootNode = pNode;

}

template <class T>
void BinaryTree<T>::Preorder(TreeNode<T>* pNode){

	if (pNode == NULL)
		return;

	cout << pNode->Data << " ";
	Preorder(pNode->LeftChild);
	Preorder(pNode->RightChild);
	
}

template <class T>
void BinaryTree<T>::Inorder(TreeNode<T>* pNode){

	if (pNode == NULL)
		return;

	Inorder(pNode->LeftChild);
	cout << pNode->Data << " ";
	Inorder(pNode->RightChild);

}

template <class T>
void BinaryTree<T>::Postorder(TreeNode<T>* pNode){

	if (pNode == NULL)
		return;

	Postorder(pNode->LeftChild);
	Postorder(pNode->RightChild);
	cout << pNode->Data << " ";

}

template <class T>
void BinaryTree<T>::Levelorder(TreeNode<T>* pNode){

	int height = GetHeight();
	int i;

	for (int i = 1; i <= height; i++)
	{
		PrintLevelorder(pNode, i);
	}
	
}

template <class T>
void BinaryTree<T>::PrintLevelorder(TreeNode<T>* pNode, int level){
	
	if (pNode == NULL)
		return;

	if (level == 1)
		cout << pNode->Data << " ";

	else if (level > 1)
	{
		PrintLevelorder(pNode->LeftChild, level - 1);
		PrintLevelorder(pNode->RightChild, level - 1);
	}
}

template <class T>
int BinaryTree<T>::GetHeight(){

	int height = 0;
	TreeNode<int> *pNode = rootNode;
	while (pNode != NULL)
	{
		height++;
		pNode = pNode->LeftChild;
	}

	return height;
}

#endif