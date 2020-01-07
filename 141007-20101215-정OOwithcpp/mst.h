/*
	����:���α׷���(1~3)
	�ݿ��������б�(Kumoh National Institute of Technology)
	�а�: �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
	�й�: 20101215
	�̸�: ������
*/

#ifndef _MST_H_
#define _MST_H_

#include <iostream>
#include "global.h"

const int ONLY_FIND = 0;
const int UNION = 1;
const int EDGE_COMPONENT = 3;

class edge{
public:
	int v1, v2;
	int weight;
};

class Heap{
public:
	Heap(int count);  // count�� E�� ����
	~Heap();
	void Push(edge* element);
	edge* Pop();

	int GetCapacity(){ return capacity; }

private:
	int size;
	int capacity;
	edge** HeapMemory;
};

/* 
   ���α׷���(2) : �ڷᱸ�� ���ÿ� ���� ���
   Min Heap(�迭��)�� ����߽��ϴ�.
   �޸𸮸� ���� �� �ᵵ ������ ������?(����� �������� �ٸ� ���� ����)������
   �� ������ ����Ͽ����ϴ�. ��, ���� Performance�� ���̰� ���ٰ� �Ǵ��߽��ϴ�.
   ���� Performance���� ���ᱸ���� ������ O(logn)�� �ӵ��� �� �� �ִٰ� �ǴܵǾ��� �����Դϴ�.
   ������, ���� ����ߴ� �� GIS(���������ý���)�� ���� �뷮�� ��ǥ���� ó���ϴ� ����� �����ϸ�, 
   ���� ������ ó������ ��, �޸� ���� Sigma(1+n^2)���� �ҿ�ȴٴ� ���� �����غ���,
   ������� �������� ���� ����Ʈ�� �̿��� ����� �޸� �ҿ並 ���������� ������ �����غ� �� �־����ϴ�.
   ����ġ�� 0 < x < n^2 �� �������� x�� ���̿� �ش�� ������ ���ϴ�.
*/

class MST{
public:
	MST();
	~MST();

	edge** CreateMatrix();
	void DestoryMatrix(edge* T_Matrix[]);

	int IsEmptyMatrix(edge* T_Matrix[]);
    void kruskal(Heap* pHeap, const int V, const int E);
	void Insert(edge* T_Matrix[], int& V, int& E, std::string D);

	Heap* GetHeap(edge* T_Matrix[], const int E);

private:
	void Init_Kruskal(int Capacity);   // MST�� ���� �⺻ ���� ��� �ʱ�ȭ
	void Destory_Kruskal(); // MST�� ���� ���� �迭 ��� ����

	void input_edge(edge** T_Matrix, int E, edge* ptrEdge);
	void SetUnion(int v1, int v2);
	int GetFind(int v);
	edge* CreateNode(int x, int y, int weight);
	void PrintOut(edge* ptrEdge);

protected:
	int *parent;
	int *num;
};


#endif