/*
금오공과대학교
과제 : 방학(Binary Search Tree) 과제5 - 3번
학과 : Business & CSE
학번 : 20101215
이름 : 정원영
*/

#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <string>

const int INITIAL = 1;

const int ROOT = 1;
const int NODE = 2;

template <class T>
class Node{
public:
	int Height;
	T Data;
	Node<T>* prev;
	Node<T>* next;
};

template <class T>
class Stack{
public:
	Stack();
	~Stack();
	void push(T _Data, int _Height);
	T pop();
	int GetCount();
	T at(int height);
private:
	int Count;
	Node<T>* Top;
};

template <class T>
class TreeNode{
public:
	TreeNode<T>* LeftNode;
	T Data;
	TreeNode<T>* RightNode;
};

template <class T>
class BST{
public:
	BST();
	~BST();
	TreeNode<T>* Search(TreeNode<T>* _pNode, int level, int curlevel);
	void Insert(TreeNode<T>* pTop, TreeNode<T>* _pNode, int level = 1);
	TreeNode<T>* Remove(TreeNode<T>* _pNode, T _Data);
	TreeNode<T>* Create(T _Data);
	TreeNode<T>* GetNode();
	int GetMax();
	void SetMax(int _Max);
	void SetIncreaseMax();
	TreeNode<T>* findMinNode(TreeNode<T>* Tree);
	void PrintOut(TreeNode<T>* pNode);
	void PostOrder(TreeNode<T>* pNode, int level, Stack<T>* pStackNode);
	void DestoryTree(TreeNode<T>* pNode);
	void DestoryNode(TreeNode<T>* pNode);

private:
	TreeNode<T>* Top;
	TreeNode<T>* HeadNode;
	int Max;
protected:
	void SetLine(bool check);
	void SetData(int Type, T Data);
	bool GetLine();
	bool printLine;
	std::string RootData;
	std::string TreeData;
};

#include "bst_detail.h"

#endif