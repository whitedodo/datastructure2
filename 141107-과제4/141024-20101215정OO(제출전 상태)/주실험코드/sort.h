#ifndef _SORT_H_
#define _SORT_H_

#include <iostream>
#include <string>
#include <algorithm>

#include "common.h"
#include "ds.h"

// Quick Sort 타입
const int TYPE_R_QUICK = 11;
const int TYPE_R_MEDIAN_QUICK = 22;
const int TYPE_N_MEDIAN_QUICK = 33;
const int TYPE_STD_QUICK = 44;

// Merge Sort 타입
const int TYPE_R_MERGE = 55;
const int TYPE_N_MERGE = 66;
const int TYPE_NAT_MERGE = 77;

/// Sort ADT
template <typename T>
class Sort
{
public:
	Sort();
	~Sort();

	void LinkedInsertSort(Node<T>* Data);
	void BinaryInsertSort(T* data, const int n);
	void QuickSort(T* data, const int left, const int right, const int Type = TYPE_R_QUICK);
	void MergeSort(T* data, const int left, const int right, const int Type = TYPE_R_MERGE);
	void HeapSort(T* data, const int n);
	void BubbleSort(T* data, const int n);
	void SelectionSort(T* data, const int n);

private:
	void Swap(T* data, int left, int right);

	int BinarySearch(T* data, const T x, const int n);
	/* Quick Sort */
	void QuickSort_Non(T* data, const int n);
	void QuickSort_Recur(T* data, const int left, const int right);
	void QuickSort_MedianRecur(T* data, const int left, const int right);
	
	T Median_Pivot(T* data, const int left, const int right);

	int FindIndex(T* data, T pivotValue, int right);
	void manualSort(T* data, int left, int right);
	int partitionIt(T* data, int left, int right, T Pivot);
	/* End of Quick Sort */

	/* Merge Sort */
	void MergeSort_Non(T* data, const int left, const int right, const int size);
	void MergeSort_Recur(T* data, const int left, const int right);
	void Merge(T* data, const int Start, const int Mid, const int End);
	void MergeSort_Natural(T* data, const int n);
	/* End of Merge Sort*/

	/* Heap Sort */
	void Adjust(T* data, const int root, const int n);
	/* End of Heap Sort */

protected:

};


#include "binarysort.h"
#include "bubblenselection.h"
#include "sortController.h"
#include "heap.h"
#include "quicksort.h"
#include "linkedinsertsort.h"
#include "merge.h"

#endif 