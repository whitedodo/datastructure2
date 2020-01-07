/*
�ݿ��������б�
����: ����(Binary Tree) ����5 - 2��(����)
�а�: Business & CSE
�й�: 20101215
�̸�: ������
*/

#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

// Common ����
template <class T>
class TreeNode;

// 1. Generic Stack(�Ϲ���)

template <class T>
class Node{
public:
	T Data;
	Node<T>* prev;
	Node<T>* next;
};

template <class T>
class Stack{
public:
	Stack();
	~Stack();
	void push(T t);
	T pop(void);
	T get_stack_top(void);
	int GetCount();
	int is_stack_empty(void);

private:
	int Count;
	Node<T>* Top;
};

// 2. Stack Pointer with TreeNode
template <class T>
class pNode{
public:
	T* Data;
	pNode* prev;
	pNode* next;
};

template <class T>
class pStack{
public:
	pStack();
	~pStack();
	void push(T* _pNode);
	int IsEmpty();
	int GetCount();
	T* pop();
	T* GetTop();

private:
	int Count;
	pNode<T>* Top;
};

// 3.

class stringNode{
public:
	int Height;
	std::string Data;
	stringNode* prev;
	stringNode* next;
};

class stringStack{
public:
	stringStack();
	~stringStack();
	void push(std::string _Data, int _Height);
	std::string pop();
	int GetCount();
	std::string at(int height);
private:
	int Count;
	stringNode* Top;
};

#include "stack_inl.h"

#endif
