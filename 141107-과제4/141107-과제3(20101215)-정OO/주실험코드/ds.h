#ifndef _DS_H_
#define _DS_H_

template <typename T>
class JVector{
public:
	void SetVector(T x, T y){
		_x = x; _y = y;
	};

	T GetX(){ return this->_x; };
	T GetY(){ return this->_y; };

private:
	T _x;
	T _y;
};


template <typename T>
class Node{
public:
	T data;
	Node<T>* prev;
	Node<T>* next;
};

/* 연결리스트 자료구조 */
template <typename T>
class LinkedList{
public:
	LinkedList();
	~LinkedList();
	Node<T>* GetFirstNode() { return First; };
	int GetCount(){ return Count; };
	void Insert(T data);

private:
	Node<T>* First;
	Node<T>* TopNode;
	int Count;
	int SortType;
};

/* Stack 자료구조 */
template <typename T>
class Stack{
public:
	Stack();
	~Stack();
	void Push(T data);
	T Pop();
	int GetCount(){ return Count; };
	int Any(){
		if (Top == NULL) return FALSE; else return TRUE;
	}
	Node<T>* GetTop(){ return Top; };

private:
	Node<T>* Top;
	int Count;
};

/*
4. Global - Queue<T>
---------------------------------------------------
---------------------------------------------------
By James  /  2014.10.7
jungwy@cakeon.com
*/

/* Queue FIFO로 구현 */
template <typename T>
class Queue{
public:
	Queue();
	~Queue();
	void Push(T data);
	T Pop();
	int Any(){
		if (front == NULL) return FALSE; else return TRUE;
	}
	int GetCount(){ return Count; };
	Node<T>* GetRear(){ return rear; };
	Node<T>* GetFront(){ return front; };

private:
	Node<T>* front;
	Node<T>* rear;
	int Count;
};

#include "dsController.h"

#endif