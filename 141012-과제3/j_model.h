/*
	Subject - JLand(Sort) Project / j_model.h
	Created Date - 2014. 10. 8
	Description - JLand / Model ����
	[Version]
*/

#ifndef _TSORT_H_
#define _TSORT_H_

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <time.h>
#include "global.h"

// Linked List Ÿ��
const int SORT = 99;
const int NORMAL = 100;

// Quick Sort Ÿ��
const int TYPE_R_QUICK = 11;
const int TYPE_R_MEDIAN_QUICK = 22;
const int TYPE_N_MEDIAN_QUICK = 33;
const int TYPE_STD_QUICK = 44;

// Merge Sort Ÿ��
const int TYPE_R_MERGE = 55;
const int TYPE_N_MERGE = 66;
const int TYPE_NAT_MERGE = 77;

/* Patition */
const int PARTITION_END = 1;

// JPolygon �ɼ�
const int POLY_MAX = 1000;
const int TYPE_POLY_FIELD_X = 1;
const int TYPE_POLY_FIELD_Y = 2;
const int TYPE_POLY_FIELD_RESULT = 3;

const int TYPE_DOUBLE = 99;
const int TYPE_FLOAT = 100;
const int TYPE_INT = 101;

const int TYPE_JP_USER_SIZE = 200;
const int TYPE_JP_RANDOM_SIZE = 201;

const int POLY_INITIALIZE = 300;
const int POLY_SUCCESS = 301;
const int POLY_FAILOVER = 302;

// JApp �ɼ�
const int JAPP_PRINT_UNSORTED = 100;
const int JAPP_PRINT_SORTED = 200;
const int JAPP_POLYGON = 300;
const int JAPP_NORMAL = 400;

// JApp - CMD ���
const int JAPP_SORT_BINARY_INSERT = 1;
const int JAPP_SORT_LINK_INSERT = 2;
const int JAPP_SORT_R_QSORT = 3;
const int JAPP_SORT_R_M_QSORT = 4;
const int JAPP_SORT_N_M_QSORT = 5;
const int JAPP_SORT_STD_QSORT = 6;
const int JAPP_SORT_R_MERGE = 7;
const int JAPP_SORT_N_MERGE = 8;
const int JAPP_SORT_NAT_MERGE = 9;
const int JAPP_SORT_HEAP = 10;
const int JAPP_SORT_BUBBLE = 11;
const int JAPP_SORT_SELECTION = 12;

// JLand
const int JLAND_INITIALIZE = 10;
const int JLAND_SUCCESS = 100;
const int JLAND_FAILOVER = 200;

// JLand �ɼ�
const int TYPE_JLAND_ANALYSIS_ON = 1;
const int TYPE_JLAND_ANALYSIS_OFF = 2;

// JLand �ɼ� / Polygon
const int TYPE_JLAND_POLYGON_X = 1;
const int TYPE_JLAND_POLYGON_Y = 2;
const int TYPE_JLAND_POLYGON_RESULT = 3;

// JLAND - Wizard ������

// Public Menu
const int WIZARD_JLAND_T_ANALYSIS = 1;
const int WIZARD_JLAND_T_RAND = 2;
const int WIZARD_JLAND_T_USERSIZE = 3;

const int WIZARD_JLAND_START = 1;
const int WIZARD_JLAND_END = 3;

// Private Menu (���� ����)
const int WIZARD_JLAND_T_POLYGON = -100;


int RandBox(const int Type); // global.h -> RandBox �̿�

////////////////////////////////////////////////////

/*
	1. Global - JTuple<x, y>
	---------------------------------------------------
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
	By Rabbit  /  2014.10.6
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
	By Rabbit  /  2014.10.7
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
	By Rabbit  /  2014.10.4
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
	By Rabbit  /  2014.10.10
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
	
	/*
	   InputType: TYPE_JP_USER_SIZE, TYPE_JP_RANDOM_SIZE
	   SetRandType: TYPE_RAND_LOW, TYPE_RAND_MID, TYPE_RAND_HIGH
	   DataType: TYPE_DOUBLE, TYPE_INT, TYPE_FLOAT
	*/

	JPolygon(int _DataType = TYPE_INT); // JPolygon:JPolygon
	~JPolygon();
	
	int RunOfProcess(const int InputType, const int RandType = TYPE_RAND_LOW, const int n = NULL);
	
	JPolygonNode<T>* GetPolyList(){ return polyList; };

	int* GetSort_Index(){ return SortIndexArr; };
	int* GetCriticia_Index(){ return IndexArr; };
	T* GetCriticia_Data(JPolygonNode<T>* pData, const int AttrType, const int n);
	
	void SortIndexToMerge(int* Arr, T* OriData, T* ChgData, const int n);

	int GetCapacity(){ return Capacity; };
	int GetEndIDX(){ return Capacity - 1; };
	int IsEmpty(){ (Capacity == 0) ? return TRUE; : return FALSE; };	// JPolygon:IsEmpty() = �ڷ� ���� ����
	void SetSortIndex(int* Arr){ SortIndexArr = Arr; };					// JPolygon:SetSortIndex() = ���� �ε���

private:
	void Create(const int RandType, const int n = NULL);				// JPolygon:Create() = �ʱ� ���� ������ ����(Random)
	void Destory_Vector();												// JPolygon:Destory_Vector() = ����
	void Assign_Vector(const int n = NULL);								// JPolygon:Assign_Vector() = �ű� Polygon ���� ����
	int IsRandType(int RandType);										// JPolygon:IsRandType(RandType) = �Ǻ�

protected:
	JPolygonNode<T>* polyList; // polyList[N] = NULL or Exist
	int DataType;		      // DataType = �ڷ��� ���� : DOUBLE, FLOAT, INT
	int* IndexArr;		      // IndexArr = FALSE, TRUE
	int* SortIndexArr;
	int Index;
	int Capacity;
};

template <typename T>
class JApp{
public:
	JApp();
	~JApp();
	void PolyGon_Sort(JPolygon<T>* JPolyApp, const int CriticiaType, const int Analysis);
	void PolyGon_Print(JPolygon<T>* JPolyApp, const int CriticiaType);
	T* General_Create(const int n, const int SetRandType);
	void General_Sort(T* Data, const int n, const int Analysis);
	void General_Print(T* Data, const int n);

private:
	void Sort_Run(const int Type, T* Data, const int startidx, const int endidx, const int Analysis);
	void Result_Print(const T* pArr, const int* idxArr, const int n, const int Option);
	void Result_Print(const JPolygonNode<T>* pArr, const int* idxArr, const int n, const int Option, const int CriticiaType);
	void Analysis_Print(double StartTime, double EndTime);
	std::string GetPrintMemo();
	void Destory_PrintMemo();

protected:
	std::string Print_Title_Data;
	std::string Print_Analysis_Data;
	std::string Print_Report_Data;

};

/*
	7. JLand->Program Call
	---------------------------------------------------
	---------------------------------------------------
	By Rabbit  /  2014.10.10
*/

class JLand{
public:
	JLand();
	~JLand();

	void Run(const int TYPE);
	void About();

private:
	int Wizard(const int typeNum);	// �м� ������

	void Menu_Integer(const int Analysis, const int RandType, int UserSize);
	void Menu_Double(const int Analysis, const int RandType, int UserSize);
	void Menu_Polygon_Double(const int Analysis, const int RandType, int UserSize);
	void Menu_String(const int Analysis, const int RandType, int UserSize);

};

#include "j_ds_controller.h"
#include "j_sort_controller.h"
#include "j_land_controller.h"

#endif