/*
	����:���α׷���(1~3)
	�ݿ��������б�(Kumoh National Institute of Technology)
	�а�: �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
	�й�: 20101215
	�̸�: ������
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