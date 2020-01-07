/* 
	����:���α׷���(1~3)
	�ݿ��������б�(Kumoh National Institute of Technology)
	�а�: �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
	�й�: 20101215
	�̸�: ������
*/

#include "ds.h"
#include "global.h"

stack::stack(){
	first = NULL;
	top = NULL;
}

stack::~stack()
{
	n* ptr;

	if (!IsEmpty())
	{
		while (first->link != NULL)
		{
			ptr = first;
			first = first->link;
			delete[] ptr;
		}
	}

	first = NULL;
	top = NULL;

}

void stack::push(int number){

	n* ptr = new n();

	ptr->d = number;
	ptr->link = NULL;

	if (IsEmpty())
	{
		ptr->link = NULL;
		first = ptr;
		top = first;
	}
	else
	{
		ptr->prev = top;
		top->link = ptr;
		top = top->link;
	}
}

int stack::pop(){

	int num = EMPTY;
	n* ptr;

	if (!IsEmpty())
	{
		num = top->d;
		ptr = top;
		top = top->prev;

		delete[] ptr;
	}
	else
	{
		// ���̻� ����� ����.
	}

	return num;
}

int stack::IsEmpty(){

	if (top == NULL)
		return TRUE;
	else
		return FALSE;
}

queue::queue(){
	front = NULL;
	rear = NULL;
	capacity = 0;
}

queue::~queue(){
	
    n* ptr;

	while (front != NULL)
	{
		ptr = front;
    	front = front->link;
		delete[] ptr;
	}

	front = NULL;
	rear = NULL;

}

void queue::push(int number){

	n* ptr = new n();

	ptr->d = number;
	ptr->link = NULL;
	ptr->prev = NULL;

	if (IsEmpty())
	{
		front = ptr;
		rear = front;
	}
	else
	{
		ptr->prev = rear;
        rear->link = ptr;
		rear = rear->link;
	}

	capacity++;
}

int queue::pop(){

	int num = EMPTY;
	n* ptr;

	if (IsEmpty())
	{
        
	}
	else
	{
		num = front->d;
		ptr = front;

		front = front->link;
		
		if (front != NULL)
			front->prev = NULL;
        
        delete[] ptr;
	}

	capacity--;

	return num;
}

int queue::IsEmpty(){
	
	if (front != NULL)
		return FALSE;
	else
		return TRUE;
}