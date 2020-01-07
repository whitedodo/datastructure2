/*
     금오공과대학교
     과제: 방학(Binary Tree) 과제 - 1번(연결구조 구현)
     학과: Business & CSE
     학번: 20101215
     이름: 정원영
*/

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>
#include <string>


// 1. 형식 구분
const int ROOT = 0; // 타입:루트
const int NODE = 1; // 타입:노드

// 2. 방향 구분(DECISION에 이용 - Tree 자료 구축에 사용)
const int LEFT = 0;  // 왼쪽 
const int RIGHT = 1; // 오른쪽
const int ALL = 2;   // 모두 널
const int NONE = 3;  // 초기

// 3. Visit 설계

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

// 4. Tree 설계

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