/*
	Subject - JLand(Sort) Project / j_model.h
	Director - .......... Jeong / OOOOOOOOOOOOOOO교 / Business & Computer Science
	Created Date - 2014. 10. 8
	Description - JLand / Model 영역
	[Version]
*/

#ifndef _TSORT_H_
#define _TSORT_H_

#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <math.h>
#include "global.h"

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

/* Patition */
const int PARTITION_END = 1;

// JPolygon 옵션
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

// JApp 옵션
const int JAPP_PRINT_UNSORTED = 100;
const int JAPP_PRINT_SORTED = 200;
const int JAPP_POLYGON = 300;
const int JAPP_NORMAL = 400;

// JApp - CMD 명령
const int JAPP_SORT_BINARY_INSERT = 1;
const int JAPP_SORT_R_QSORT = 2;
const int JAPP_SORT_R_M_QSORT = 3;
const int JAPP_SORT_N_M_QSORT = 4;
const int JAPP_SORT_STD_QSORT = 5;
const int JAPP_SORT_R_MERGE = 6;
const int JAPP_SORT_N_MERGE = 7;
const int JAPP_SORT_NAT_MERGE = 8;
const int JAPP_SORT_HEAP = 9;
const int JAPP_SORT_BUBBLE = 10;
const int JAPP_SORT_SELECTION = 11;

// JLand
const int JLAND_INITIALIZE = 10;
const int JLAND_SUCCESS = 100;
const int JLAND_FAILOVER = 200;

// JLand 옵션
const int TYPE_JLAND_ANALYSIS_ON = 1;
const int TYPE_JLAND_ANALYSIS_OFF = 2;

// JLand 옵션 / Polygon
const int TYPE_JLAND_POLYGON_X = 1;
const int TYPE_JLAND_POLYGON_Y = 2;
const int TYPE_JLAND_POLYGON_RESULT = 3;

// JLAND - Wizard 마법사

// Public Menu
const int WIZARD_JLAND_T_ANALYSIS = 1;
const int WIZARD_JLAND_T_RAND = 2;
const int WIZARD_JLAND_T_USERSIZE = 3;

const int WIZARD_JLAND_START = 1;
const int WIZARD_JLAND_END = 3;

// Private Menu (음수 범위)
const int WIZARD_JLAND_T_POLYGON = -100;

// Linked Menu
const int LINKED_JLAND_T_INTEGER = 1;
const int LINKED_JLAND_T_DOUBLE = 2;
const int LINKED_JLAND_T_STRING = 3;

////////////////////////////////////////////////////

/*
	1. Global - JTuple<x, y>
	---------------------------------------------------
	---------------------------------------------------
	By Rabbit.white  /  2014.10.10
	rabbit.white@daum.net
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
	By Rabbit.white  /  2014.10.6
	rabbit.white@daum.net
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
	/* Type : Normal, Sort 방식이 있음.(삽입시 Linked InsertSort를 수행함)
		배열구조로 구현하게 되면 Sort으로 교제에서 이해하는 InsertSort를 수행하게 됨.
		이러한 자료형태일 땐, 이와 같이 삽입 정렬을 수행하는게 수행속도가 최상 성능 O(nlogn)을
		띌수 있다고 봄. 삭제할 때는 O(n)시간 소요될 것으로 봄.
	*/
										
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

/*
	3. Global - Stack<T>
	---------------------------------------------------
	---------------------------------------------------
	By Rabbit.white  /  2014.10.6
	rabbit.white@daum.net
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
	By Rabbit.white  /  2014.10.7
	rabbit.white@daum.net
*/

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

/*
	5. Global - Sort
	---------------------------------------------------
	---------------------------------------------------
	By Rabbit.white  /  2014.10.4
	rabbit.white@daum.net
*/

template <typename T>
class Sort
{
public:
	Sort();
	~Sort();

	void BinaryInsertSort(T* Data, const int n);
	/* 
		참고
		n이 8개(실제 데이터 갯수 9개)일 때 부터 분할 정렬을 시작하게 됨.
		eg) 1 2 3 5 6 | 3 4 7 9 10 이런꼴로 분할 정렬됨.
		7이하일 때 유용할 것으로 보임.
	*/
	int BinarySearch(T* Data, const T x, const int n);
	
	// 링크드 삽입정렬은 LinkedList에 있음.(참고) - 구현함.

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
	By Rabbit.white  /  2014.10.10
	rabbit.white@daum.net
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
	
	int RunOfProcess(const int InputType, const int RandType = TYPE_RAND_LOW, const int n = J_NULL);
	
	JPolygonNode<T>* GetPolyList(){ return polyList; };

	int* GetSort_Index(){ return SortIndexArr; };
	int* GetCriticia_Index(){ return IndexArr; };
	T* GetCriticia_Data(JPolygonNode<T>* pData, const int AttrType, const int n);
	
	void SortIndexToMerge(int* Arr, T* OriData, T* ChgData, const int n);

	int GetCapacity(){ return Capacity; };
	int GetEndIDX(){ return Capacity - 1; };
	int IsEmpty(){ if (Capacity == 0) { return TRUE; } else{ return FALSE; } };	// JPolygon:IsEmpty() = 자료 존재 여부
	void SetSortIndex(int* Arr){ SortIndexArr = Arr; };					// JPolygon:SetSortIndex() = 정렬 인덱스

private:
	void Create(const int RandType, const int n = J_NULL);				// JPolygon:Create() = 초기 생성 폴리곤 생성(Random)
	void Destory_Vector();												// JPolygon:Destory_Vector() = 해지
	void Assign_Vector(const int n = J_NULL);								// JPolygon:Assign_Vector() = 신규 Polygon 공간 배정
	int IsRandType(int RandType);										// JPolygon:IsRandType(RandType) = 판별

protected:
	JPolygonNode<T>* polyList; // polyList[N] = NULL or Exist
	int DataType;		      // DataType = 자료형 지원 : DOUBLE, FLOAT, INT
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
	
	void Analysis_Print(double StartTime, double EndTime);

	void PolyGon_Sort(JPolygon<T>* JPolyApp, const int CriticiaType, const int Analysis);
	void PolyGon_Print(JPolygon<T>* JPolyApp, const int CriticiaType);
	
	T* General_Create(const int n, const int SetRandType);
	void General_Sort(T* Data, const int n, const int Analysis);
	void General_Print(T* Data, const int n);
	
	LinkedList<T>* Linked_Create(const int n, LinkedList<T>* pList, const int SetRandType);
	void Linked_Print(LinkedList<T>* BeforeLst, LinkedList<T>* SortedLst);
	
	void Result_Print(const T* pArr, const int n, const int Option);

private:
	void Sort_Run(const int Type, T* Data, const int startidx, const int endidx, const int Analysis);
	void Result_Print(const T* pArr, const int* idxArr, const int n, const int Option);
	void Result_Print(const JPolygonNode<T>* pArr, const int* idxArr, const int n, const int Option, const int CriticiaType);
	void Result_Print(LinkedList<T>* ptrList, int Option);
	
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
	By Rabbit.white  /  2014.10.10
	rabbit.white@daum.net
*/

class JLand{
public:
	JLand();
	~JLand();

	void Run(const int TYPE);
	void About();

private:
	int Wizard(const int typeNum);	// 분석 마법사

	void Menu_Integer(const int Analysis, const int RandType, int UserSize);
	void Menu_Double(const int Analysis, const int RandType, int UserSize);
	void Menu_Polygon_Double(const int Analysis, const int RandType, int UserSize);
	void Menu_String(const int Analysis, const int RandType, int UserSize);
	void Menu_Linked_Insert(const int Analysis, const int RandType, int UserSize);


};
//
//extern template class Node<T>;
//extern template class Queue<typename T>;
//extern template class Stack<typename T>;
//extern template class Sort<typename T>;
//extern template class Sort<std::string>;
//extern template class JTuple<typename T>;
//extern template class LinkedList<typename T>;
//extern template class JPolygonNode<typename T>;
//extern template class JPolygon<typename T>;
//extern template class JApp<typename T>;
//extern template class JLand<typename T>;


#include "j_ds_controller.h"
#include "j_sort_controller.h"
#include "j_land_controller.h"


#endif