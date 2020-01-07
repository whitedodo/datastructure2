/*
과제:프로그래밍(1~3)
금오공과대학교(Kumoh National Institute of Technology)
학과: 경영(Business) & 컴퓨터소프트웨어공학과(CSE)
학번: 20101215
이름: 정원영
*/

#include <iostream>
#include <string>
#include "global.h"
#include "ds.h"
#include "io.h"
#include "mst.h"

using namespace std;

int CharToInt(const char d);

Heap::Heap(int count){

	size = 0;
	int HeapMax = 2;

	// 힙 크기 계산 Heap을 Edge기준으로 판단
	while (HeapMax <= count)
		HeapMax = HeapMax * 2;

	HeapMemory = new edge*[HeapMax];

	for (int i = 0; i < HeapMax; i++){
		HeapMemory[i] = NULL;
	} // end of for

	// 힙 capacity 배정
	capacity = HeapMax;
}

// 소멸 힙
Heap::~Heap(){

	int i = 0;
	while (i < capacity)
	{
		if (HeapMemory[i] != NULL){ // 힙 존재 판단

			if (HeapMemory[i]->v1 != ERROR_MEMORY)	// 정상 힙이 아닐 때
			{
				delete[] HeapMemory[i];	// 개별 힙 제거
			} // end of if

			HeapMemory[i] = NULL;	// 안전한 제거
		}
		else{
			// cout << i << "거짓:" << &HeapMemory[i] << endl;
			i++;
		} // end of if

	} // end of while

	delete[] HeapMemory;	// 소거
	HeapMemory = NULL;		// 안전한 제거

}

// 삽입 힙(Min-Heap)
void Heap::Push(edge* item){

	int i;
	i = ++size;

	edge** ptrMemory = HeapMemory;

	while (i != 1 && item->weight < ptrMemory[i / 2]->weight)
	{
		ptrMemory[i] = ptrMemory[i / 2];
		i /= 2;
	} // end of while

	ptrMemory[i] = item;
}

// Pop 힙(Min-Heap) - 단, 제거 인출한 곳에서 해야함.
edge* Heap::Pop(){

	/* 부 로드는 1로 할당
	(트리를 수학의 수열로 생각해보면
	1 + 2^1 + 2^2 + ... + 2^n 의 관계임
	따라서, Heap 할당시 이의 관계를 형성했는데,
	부모를 순수하게 1부터 시작하는 관계로 바라봄.
	*/

	int parent = 1;
	int child = 2;

	edge* CurData = NULL;
	edge* tmpNode = NULL;

	CurData = HeapMemory[parent];	// 부모 힙이 Min이라고 가정하고 인출
	tmpNode = HeapMemory[size--];   // 사이즈 감소 

	while (child <= size)
	{
		// 자식 노드간 작은 수 비교
		if ((child < size) && (HeapMemory[child]->weight) > HeapMemory[child + 1]->weight)
			child++;

		if (tmpNode->weight <= HeapMemory[child]->weight)
			break;

		HeapMemory[parent] = HeapMemory[child];		// 부모 힙과 자녀힙의 세대 교체

		parent = child;
		child *= 2; // 다음 자식 노드 비교

	} // end of while

	HeapMemory[parent] = tmpNode;

	return CurData;
}

MST::MST(){
	parent = NULL;
	num = NULL;
}

MST::~MST(){
	Destory_Kruskal();
}

int MST::IsEmptyMatrix(edge* T_Matrix[]){

	if (T_Matrix == NULL)
		return TRUE;
	else
		return FALSE;

}

edge** MST::CreateMatrix(){
	edge** T_Matrix;
	T_Matrix = new edge*[MAX_VERTEX];

	for (int i = 0; i < MAX_VERTEX; i++)
		T_Matrix[i] = NULL;

	return T_Matrix;
}

void MST::DestoryMatrix(edge* T_Matrix[]){
	delete[] T_Matrix;
}

void MST::Init_Kruskal(int capacity){

	parent = new int[capacity];
	num = new int[capacity];

	for (int i = 0; i < capacity; i++)
	{
		parent[i] = -1;
		num[i] = -1;
	} // end of for
}

void MST::Destory_Kruskal(){

	if (parent != NULL)
		delete[] parent;

	if (num != NULL)
		delete[] num;

	parent = NULL;
	num = NULL;
}

void MST::Insert(edge* T_Matrix[], int& V, int& E, std::string D){

	int x, y, weight;
	int num, size, count = 0;
	int ChkContinue = FALSE;

	stack stackApp;

	E = 0;

	// DATA 불러오기
	size = D.length();
	for (int i = 0; i < size; i++)
	{
		if (D.at(i) == '\n'){

			// Edge 등록 처리
			if (!stackApp.IsEmpty() && count == EDGE_COMPONENT)
			{
				weight = stackApp.pop();
				y = stackApp.pop();
				x = stackApp.pop();

				input_edge(T_Matrix, E, CreateNode(x, y, weight));

				E++;
			} // end of if

			// Stack 비우기
			while (!stackApp.IsEmpty())
				stackApp.pop();

			count = 0;
			ChkContinue = FALSE;
			continue;

		} // end of if

		// Edge 등록 처리
		if (D.at(i) == ' '){

			if (!stackApp.IsEmpty() && count == EDGE_COMPONENT)
			{
				weight = stackApp.pop();
				y = stackApp.pop();
				x = stackApp.pop();

				input_edge(T_Matrix, E, CreateNode(x, y, weight));

				count = 0;
				E++;
			} // end of if

			ChkContinue = FALSE;
		}
		else
		{
			if (ChkContinue == FALSE)
			{
				num = CharToInt(D.at(i));
				stackApp.push(num);
				ChkContinue = TRUE;

				count++;
			}
			else{
				num = stackApp.pop();
				num = num * 10;
				num = num + CharToInt(D.at(i));
				stackApp.push(num);
			} // end of if

		} // end of if

	} // end of for
}


edge* MST::CreateNode(int x, int y, int weight){

	edge* pNode = new edge();

	pNode->v1 = x;
	pNode->v2 = y;
	pNode->weight = weight;

	return pNode;
}

void MST::input_edge(edge* T_Matrix[], int E, edge* ptrEdge){
	T_Matrix[E] = ptrEdge;
}

Heap* MST::GetHeap(edge* T_Matrix[], const int E){

	Heap* pHeap = new Heap(E);

	for (int i = 0; i < E; i++)
		pHeap->Push(T_Matrix[i]); // edge 배열을 통한 데이터 입력(pHeap)

	return pHeap;
}

void MST::SetUnion(int v1, int v2){

	if (num[v1] < num[v2]) // 자식의 갯수로 비교
	{
		parent[v1] = v2;
		num[v1] += num[v2];
	}
	else
	{
		parent[v2] = v1;
		num[v2] += num[v1];
	} // end of if

}

int MST::GetFind(int v){

	int i, p, elem;

	p = NULL;
	elem = NULL;

	for (i = v; (p = parent[i]) >= 0; i = p);

	elem = i; // 대표원소

	for (i = v; (p = parent[i]) >= 0; i = p)
		parent[i] = elem;

	return elem;

}

void MST::kruskal(Heap* pHeap, const int V, const int E){

	edge* ptrEdge;
	queue queueApp;
	int v1Set, v2Set, edgeCount = 0, sum = 0;

	Init_Kruskal(pHeap->GetCapacity()); // 힙을 기준으로 생성

	cout << "선택된 간선 ";

	while (edgeCount < V - 1)	// 간선의 수는 V - 1
	{
		ptrEdge = pHeap->Pop();
		v1Set = GetFind(ptrEdge->v1);
		v2Set = GetFind(ptrEdge->v2);

		if (v1Set != v2Set)
		{
			PrintOut(ptrEdge);
			sum += ptrEdge->weight;
			queueApp.push(ptrEdge->weight);
			edgeCount++;
			SetUnion(v1Set, v2Set);
		} // end of if
	} // end of while

	// Connect 데이타가 존재할 때
	if (queueApp.GetCapacity() != FALSE)
	{
		cout << endl;
		cout << "최소비용 신장트리를 구할 수 있음" << endl;
		cout << "최소비용은 ";

		while (!queueApp.IsEmpty())
			cout << queueApp.pop() << "+";

		cout << "=" << sum << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "최소비용 신장트리를 구할 수 없음" << endl;
		cout << endl;
	} // end of if

	// 제거
	Destory_Kruskal();

}

void MST::PrintOut(edge* ptrEdge){

	cout << "(";
	cout << ptrEdge->v1;
	cout << " ";
	cout << ptrEdge->v2;
	cout << " ";
	cout << ptrEdge->weight;
	cout << ")";
	cout << " ";

}