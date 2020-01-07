/*
	과제:프로그래밍(7장 정렬 - 1인팀)
	OOOOOOOOOOOOOOOOO교
	학과: 경영(Business) & 컴퓨터소프트웨어공학과(CSE)
	학번: 20101215
	이름: 정OO
*/

#ifndef _TSORT_H_
#define _TSORT_H_

#include <iostream>

// 공통 옵션
const int TRUE = 1;
const int FALSE = 0;

// Linked List 타입
const int SORT = 99;
const int NORMAL = 100;

// Quick Sort 타입
const int TYPE_R_QUICK = 11;
const int TYPE_R_MEDIAN_QUICK = 22;
const int TYPE_N_MEDIAN_QUICK = 33;
const int TYPE_STD_QUICK = 44;

// Merge Sort 타입
const int TYPE_R_MERGE = 55;
const int TYPE_N_MERGE = 66;
const int TYPE_NAT_MERGE = 77;

const int PARTITION_END = 1;



template <typename T>
class JTuple{
public:
	void SetTuple(T x, T y){
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
	T Data;
	Node<T>* prev;
	Node<T>* next;
};

template <typename T>
class Stack{
public:
	Stack();
	~Stack();
	void Push(T Data);
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

/* Queue FIFO로 구현 */
template <typename T>
class Queue{
public:
	Queue();
	~Queue();
	void Push(T Data);
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

template <typename T>
class LinkedList{
public:
	LinkedList(int Type = NORMAL);
	~LinkedList();
	Node<T>* GetFirstNode() { return First; };
	
	int GetCount(){ return Count; };
	void Insert(T Data);
	// void Remove(T); - 구현 생략

private:
	Node<T>* First;
	Node<T>* TopNode;
	int Count;
	int SortType;
};

template <typename T>
class Sort
{
public:
	Sort();
	~Sort();

	void BinaryInsertSort(T* Data, const int n);
	int BinarySearch(T* Data, const T x, const int n);
	void LinkedInsertSort(Node<T>* FirstNode);

	void QuickSort(T* Data, const int left, const int right, const int Type = TYPE_R_QUICK);
	/*
	   TYPE_R_QUICK(Recursive Quick Sort)
	   TYPE_R_MEDIAN_QUICK(Recursive Median 3 Quick)
	   TYPE_N_MEDIAN_QUICK(Non-Recursive Median 3 Quick)
	   TYPE_STD_QUICK(std::sort)
	*/

	void MergeSort(T* Data, const int left, const int right, const int Type = TYPE_R_MERGE);
	/* 
	   TYPE_R_MERGE(Recursive Merge Sort)
	   TYPE_N_MERGE(Non-Recursive Merge Sort)
	   TYPE_NAT_MERGE(Natural Merge Sort)
	*/ 
	void HeapSort(T* Data, const int n);
	void BubbleSort(T* Data, const int n);
	void SelectionSort(T* Data, const int n);

private:
	void Swap(T* Data, int left, int right);
	/* Quick Sort */
	void QuickSort_Non(T* Data, const int left, const int right, const int TYPE = TYPE_N_MEDIAN_QUICK);
	void QuickSort_Recur(T* Data, const int left, const int right, const int Type = TYPE_R_QUICK);
	T Median_Pivot(T* Data, const int left, const int right);
	/* End of Quick Sort */

	/* Merge Sort */
	void MergeSort_Non(T* Data, const int Start, const int End);
	void MergeSort_Recur(T* Data, const int left, const int right);
	void Merge(T* Data, const int Start, const int Mid, const int End);
	void MergeSort_Natural(T* Data, const int Start, const int End);
	/* End of Merge Sort*/

	/* Heap Sort */
	void Adjust(T* Data, const int root, const int n);
	/* End of Heap Sort */

};

template <typename T>
Sort<T>::Sort()
{

}

template <typename T>
Sort<T>::~Sort()
{
}

#include "j_sort_insert.h"

#endif