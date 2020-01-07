/*
	����:���α׷���(7�� ���� - 1����)
	�ݿ��������б�(Kumoh National Institute of Technology)
	�а�: �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
	�й�: 20101215
	�̸�: ������
*/

#ifndef _TSORT_H_
#define _TSORT_H_

#include <iostream>

/*
	***************************************************
	Model ����
	---------------------------------------------------
	By James / jungwy@cakeon.com
*/

////////////////////////////////////////////////////

// Linked List Ÿ��
const int SORT = 99;
const int NORMAL = 100;

////////////////////////////////////////////////////

// Quick Sort Ÿ��
const int TYPE_R_QUICK = 11;
const int TYPE_R_MEDIAN_QUICK = 22;
const int TYPE_N_MEDIAN_QUICK = 33;
const int TYPE_STD_QUICK = 44;

// Merge Sort Ÿ��
const int TYPE_R_MERGE = 55;
const int TYPE_N_MERGE = 66;
const int TYPE_NAT_MERGE = 77;

/* ���� */
const int PARTITION_END = 1;

////////////////////////////////////////////////////

// PolyLand �ɼ�
const int POLY_MAX = 1000;
const int TYPE_POLY_FIELD_X = 1;
const int TYPE_POLY_FIELD_Y = 2;
const int TYPE_POLY_FIELD_RESULT = 3;

const int TYPE_DOUBLE = 99;
const int TYPE_FLOAT = 100;
const int TYPE_INT = 101;

const int TYPE_USER_SIZE = 200;
const int TYPE_RANDOM_SIZE = 201;

const int POLY_INITIALIZE = 300;
const int POLY_SUCCESS = 301;
const int POLY_FAILOVER = 302;

////////////////////////////////////////////////////

// Rand_Number �ɼ�
const int TYPE_RAND_LOW = 100;
const int TYPE_RAND_MID = 200;
const int TYPE_RAND_HIGH = 300;

const int RAND_LOW_START = 5;
const int RAND_LOW_END = 25;

const int RAND_MID_START = 100;
const int RAND_MID_END = 1000;

const int RAND_HIGH_START = 2000;
const int RAND_HIGH_END = 5000;

int RandBox(const int Type);

////////////////////////////////////////////////////

/*
	1. Global - JTuple<x, y>
	---------------------------------------------------
	---------------------------------------------------
	By James  /  2014.10.10
	jungwy@cakeon.com
*/


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

/*
	2. LinkedList(Sort, Normal)
	---------------------------------------------------
	---------------------------------------------------
	By James  /  2014.10.6
	jungwy@cakeon.com
*/

template <typename T>
class Node{
public:
	T Data;
	Node<T>* prev;
	Node<T>* next;
};

template <typename T>
class LinkedList{
public:
	LinkedList(int Type = NORMAL);	
	/* Type : Normal, Sort ����� ����.(���Խ� Linked InsertSort�� ������)
		�迭������ �����ϰ� �Ǹ� Sort���� �������� �����ϴ� InsertSort�� �����ϰ� ��.
		�̷��� �ڷ������� ��, �̿� ���� ���� ������ �����ϴ°� ����ӵ��� �ֻ� ���� O(nlogn)��
		��� �ִٰ� ��. ������ ���� O(n)�ð� �ҿ�� ������ ��.
	*/
										
	~LinkedList();
	Node<T>* GetFirstNode() { return First; };

	int GetCount(){ return Count; };
	void Insert(T Data);
	// void Remove(T); - ���� ����

private:
	Node<T>* First;
	Node<T>* TopNode;
	int Count;
	int SortType;
};

/*
	3. Global - Stack<T>
	---------------------------------------------------
	---------------------------------------------------
	By James  /  2014.10.6
	jungwy@cakeon.com
*/

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

/*
	4. Global - Queue<T>
	---------------------------------------------------
	---------------------------------------------------
	By James  /  2014.10.7
	jungwy@cakeon.com
*/

/* Queue FIFO�� ���� */
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

/*
	5. Global - Sort
	---------------------------------------------------
	---------------------------------------------------
	By James  /  2014.10.4
	jungwy@cakeon.com
*/

template <typename T>
class Sort
{
public:
	Sort();
	~Sort();

	void BinaryInsertSort(T* Data, const int n);
	/* 
		����
		n�� 8��(���� ������ ���� 9��)�� �� ���� ���� ������ �����ϰ� ��.
		eg) 1 2 3 5 6 | 3 4 7 9 10 �̷��÷� ���� ���ĵ�.
		7������ �� ������ ������ ����.
	*/
	int BinarySearch(T* Data, const T x, const int n);
	
	// ��ũ�� ���������� LinkedList�� ����.(����) - ������.

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

protected:
};

/*
	6. Polygon
	---------------------------------------------------
	---------------------------------------------------
	By James  /  2014.10.10
	jungwy@cakeon.com
*/

template <typename T>
class JPolygonNode{
public:
	JTuple<T>* Position;
	int index;
};

template <typename T>
class JPolygon{
public:
	JPolygon(int _datatype = TYPE_INT); // _datatype = TYPE_DOUBLE, TYPE_INT, TYPE_FLOAT
	~JPolygon();
	int RunOfProcess(const int InputType = TYPE_RANDOM_SIZE, const int RandType = TYPE_RAND_LOW, const int n = NULL);
	int IsEmpty(){ (Capacity == 0) ? return TRUE; : return FALSE; };	// �ڷ� ���翩�� �Ǵ�
	/* Type						  | SetRandType
	TYPE_USER_SIZE				  |	TYPE_RAND_LOW
	TYPE_RANDOM_SIZE			  |	TYPE_RAND_MID
								  |	TYPE_RAND_HIGH
	*/

	JPolygonNode<T>* GetPolyList(){ return polyList; };
	int* GetSortData(JPolygonNode<T>* pData, const int AttrType, const int n);
	int* GetIndexArr(){ return IndexArr; };								
	// ���� ���� �ּҷ� ������Ʈ������ �ڵ� ���Ǹ� �̷��� �ϸ� �ȵ�.
	// ��, ������ ���� ������Ʈ�̹Ƿ� �������·� ����

	int GetCapacity(){ return Capacity; };
	int GetEndIDX(){ return Capacity - 1; };
	int* GetArrangeData(int* Arr, int* OriData, int* ChgData, const int n);

private:
	void Create(const int RandType, const int n = NULL);				/*  SetRandType (Tip)
																				-TYPE_RAND_LOW
																				-TYPE_RAND_MID
																				-TYPE_RAND_HIGH
																		*/
	void Initialize_Vector();											// ���� �ʱ�ȭ
	void Assign_Vector(const int n = NULL);								// �Ҵ�
	int IsRandType(int RandType);										// RandType �Ǻ�

protected:
	JPolygonNode<T>* polyList; // polyList[N] = NULL or Exist
	int DataType;		      // DataType = �ڷ��� ���� : DOUBLE, FLOAT, INT
	int* IndexArr;		      // IndexArr = FALSE, TRUE
	int Index;
	int Capacity;
};

/*
	7. JLand->Program Call
	---------------------------------------------------
	---------------------------------------------------
	By James  /  2014.10.10
	jungwy@cakeon.com
*/

class JLand{
public:
	JLand();
	~JLand();

	void Run(const int TYPE);

private:
	void Menu_Integer();
	void Menu_Double();
	void Menu_Polygon_Double();
	void Menu_String();

};

#include "j_sort_insert.h"

#endif