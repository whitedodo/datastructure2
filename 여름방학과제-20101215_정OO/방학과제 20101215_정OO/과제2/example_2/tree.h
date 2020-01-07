/*
금오공과대학교
과제: 방학(Binary Tree) 과제5 - 2번(계산식)
학과: Business & CSE
학번: 20101215
이름: 정원영
*/

#ifndef _TREE_H_
#define _TREE_H_

#include <iostream>
#include <string>

using namespace std;

const int ROOT = 1;
const int NODE = 2;

template <class T>
class Node;
template <class T>
class Stack;
template <class T>
class pNode;
template <class T>
class pStack;

class stringNode;
class stringStack;

template <class T>
class TreeNode{
public:
	TreeNode* LeftNode;
	T Data;
	TreeNode* RightNode;
};

template <class T>
class Tree{
public:
	Tree();
	~Tree();
	TreeNode<T>* Create(TreeNode<T>* left, TreeNode<T>* root, TreeNode<T>* right);
	TreeNode<T>* Create(int number);
	TreeNode<T>* Create(int number, char op);
	void DestoryTree(TreeNode<T>* pNode);
	void DestoryNode(TreeNode<T>* pNode);
	void Make(int x, int y, int result, char op);
	void PostOrder(TreeNode<T>* pTreeNode, int level = 0, stringStack* pStackNode = NULL);
	void PrintOut(TreeNode<T>* pNode);
	int SkewedHeight(int Type, TreeNode<T>* pNode);
	TreeNode<T>* GetTree();

private:
	int resultToInt(std::string D);
	std::string GetResult(int number, char op);
	pStack< TreeNode<T> >* newStack;

protected:
	void SetLine(bool check);
	void SetData(int Type, std::string Data);
	bool GetLine();
	bool printLine;
	std::string RootData;
	std::string TreeData;
};

#include "tree_detail.h"

#endif
