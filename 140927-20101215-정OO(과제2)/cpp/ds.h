/*
	과제:프로그래밍(1~3)
	금오공과대학교(Kumoh National Institute of Technology)
	학과: 경영(Business) & 컴퓨터소프트웨어공학과(CSE)
	학번: 20101215
	이름: 정원영
*/

#ifndef _DS_H_
#define _DS_H_

#include <iostream>
#include "global.h"

class n{
public:
	int d;
	n* prev;
	n* link;
};

class stack{

public:
	stack();
	~stack();
	void push(int number);
	int GetTop(){ return top->d; };
	int GetFirst(){ return first->d; }
	int pop();
	int IsEmpty();

private:
	n* first;
	n* top;
};

class queue{
public:
	queue();
	~queue();
	void push(int number);
	int pop();
	int IsEmpty();
	int GetRear(){ return rear->d; };
	int GetCapacity(){ return capacity; };

private:
	n* front;
	n* rear;
	int capacity;
};

#endif