/*
	과제:프로그래밍(1~3)
	금오공과대학교(Kumoh National Institute of Technology)
	학과: 경영(Business) & 컴퓨터소프트웨어공학과(CSE)
	학번: 20101215
	이름: 정원영
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
	Heap(int count);  // count는 E의 갯수
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
   프로그래밍(2) : 자료구조 선택에 관한 고민
   Min Heap(배열형)을 사용했습니다.
   메모리를 조금 더 써도 구현의 용이함?(사실은 현실적인 다른 과업 문제)때문에
   이 구조를 사용하였습니다. 단, 실행 Performance는 차이가 없다고 판단했습니다.
   실행 Performance에선 연결구조와 동일한 O(logn)의 속도를 낼 수 있다고 판단되었기 때문입니다.
   하지만, 가장 우려했던 건 GIS(지리정보시스템)과 같은 대량의 좌표값을 처리하는 경우라고 가정하면, 
   이의 구조로 처리했을 때, 메모리 낭비가 Sigma(1+n^2)으로 소요된다는 점을 생각해보면,
   장기적인 관점에선 연결 리스트를 이용한 방식이 메모리 소요를 절감해주지 않을까 생각해볼 수 있었습니다.
   절감치는 0 < x < n^2 의 범위에서 x값 사이에 해당될 것으로 봅니다.
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
	void Init_Kruskal(int Capacity);   // MST를 위한 기본 추적 요소 초기화
	void Destory_Kruskal(); // MST를 위한 동적 배열 요소 제거

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