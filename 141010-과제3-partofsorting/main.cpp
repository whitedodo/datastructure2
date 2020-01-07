/*
	과제:프로그래밍(7장 정렬 - 1인팀)
	OOOOOOOOOOOOOOOOO교
	학과: 경영(Business) & 컴퓨터소프트웨어공학과(CSE)
	학번: 20101215
	이름: 정OO
*/

#include <iostream>
#include "j_sort.h"
#include <time.h>

using namespace std;

void main()
{
	int bbc[5] = { 5, 7, 4, 6, 3 };
	int bb[7] = { 5, 7, 4, 6, 3, 12, 19 };
	int cc[7] = {NULL, 5, 7, 4, 6, 3, 12 };
	int test[10] = { 26, 5, 77, 1, 61, 11, 59, 15, 48, 19 };
	Sort<int> a;
	LinkedList<int>* lst = new LinkedList<int>();

	lst->Insert(31);
	lst->Insert(25);
	lst->Insert(12);
	lst->Insert(40);
	lst->Insert(13);
	lst->Insert(22);
	lst->Insert(2);								// Linked List Applied Insert Sort
	
	a.BinaryInsertSort(bb, 6);						// BinaryInsert Sort

	//a.QuickSort(bb, 0, 6, TYPE_STD_QUICK);		// STD-QUICK
	//a.QuickSort(bb, 0, 6, TYPE_N_MEDIAN_QUICK);	// Non-Recur Median 3 Quick
	//a.QuickSort(bb, 0, 6, TYPE_R_MEDIAN_QUICK);	// Recur Median 3 Quick
	//a.QuickSort(bb, 0, 6, TYPE_R_QUICK);			// Recur Quick

	//a.MergeSort(bb, 0, 6, TYPE_R_MERGE);			// Recur Merge Sort
	//a.MergeSort(bb, 0, 6, TYPE_N_MERGE);			// Non-Recur Merge Sort
	//a.MergeSort(test, 0, 9, TYPE_NAT_MERGE);		// Natural Merge Sort

	//a.HeapSort(cc, 6);							// Heap Sort {eg: {NULL(이하 0), 5, 7, 4, 6, 3, 12 };}
	
	//a.BubbleSort(bb, 6);							// Bubble Sort
	//a.SelectionSort(bb, 6);						// Selection Sort

	cout << "";
}