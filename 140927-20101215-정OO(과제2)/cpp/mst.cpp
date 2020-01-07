/*
����:���α׷���(1~3)
�ݿ��������б�(Kumoh National Institute of Technology)
�а�: �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
�й�: 20101215
�̸�: ������
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

	// �� ũ�� ��� Heap�� Edge�������� �Ǵ�
	while (HeapMax <= count)
		HeapMax = HeapMax * 2;

	HeapMemory = new edge*[HeapMax];

	for (int i = 0; i < HeapMax; i++){
		HeapMemory[i] = NULL;
	}

	// �� capacity ����
	capacity = HeapMax;
}

// �Ҹ� ��
Heap::~Heap(){

	int i = 0;
	while (i < capacity)
	{
		if (HeapMemory[i] != NULL){

			if (HeapMemory[i]->v1 != ERROR_MEMORY)
			{
				delete[] HeapMemory[i];
			}

			HeapMemory[i] = NULL;
		}
		else
			// cout << i << "����:" << &HeapMemory[i] << endl;

		i++;
	}

	delete[] HeapMemory;
	HeapMemory = NULL;

}

// ���� ��(Min-Heap)
void Heap::Push(edge* item){

	int i;
	i = ++size;

	edge** ptrMemory = HeapMemory;

	while (i != 1 && item->weight < ptrMemory[i / 2]->weight)
	{
		ptrMemory[i] = ptrMemory[i / 2];
		i /= 2;
	}

	ptrMemory[i] = item;
}

// Pop ��(Min-Heap) - ��, ���� ������ ������ �ؾ���.
edge* Heap::Pop(){

	/* �� �ε�� 1�� �Ҵ�
	(Ʈ���� ������ ������ �����غ���
	1 + 2^1 + 2^2 + ... + 2^n �� ������
	����, Heap �Ҵ�� ���� ���踦 �����ߴµ�,
	�θ� �����ϰ� 1���� �����ϴ� ����� �ٶ�.
	*/

	int parent = 1;
	int child = 2;

	edge* CurData = NULL;
	edge* tmpNode = NULL;

	CurData = HeapMemory[parent];	// �θ� ���� Min�̶�� �����ϰ� ����
	tmpNode = HeapMemory[size--];   // ������ ���� 

	while (child <= size)
	{
		// �ڽ� ��尣 ���� �� ��
		if ((child < size) && (HeapMemory[child]->weight) > HeapMemory[child + 1]->weight)
			child++;

		if (tmpNode->weight <= HeapMemory[child]->weight)
			break;

		HeapMemory[parent] = HeapMemory[child];		// �θ� ���� �ڳ����� ���� ��ü

		parent = child;
		child *= 2; // ���� �ڽ� ��� ��
	}

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
	}
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

	// DATA �ҷ�����
	size = D.length();
	for (int i = 0; i < size; i++)
	{
		if (D.at(i) == '\n'){

			// Edge ��� ó��
			if (!stackApp.IsEmpty() && count == EDGE_COMPONENT)
			{
				weight = stackApp.pop();
				y = stackApp.pop();
				x = stackApp.pop();

				input_edge(T_Matrix, E, CreateNode(x, y, weight));

				E++;
			}
			// Stack ����
			while (!stackApp.IsEmpty())
				stackApp.pop();

			count = 0;
			ChkContinue = FALSE;
			continue;

		} // end of if

		// Edge ��� ó��
		if (D.at(i) == ' '){

			if (!stackApp.IsEmpty() && count == EDGE_COMPONENT)
			{
				weight = stackApp.pop();
				y = stackApp.pop();
				x = stackApp.pop();

				input_edge(T_Matrix, E, CreateNode(x, y, weight));

				count = 0;
				E++;
			}

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
		pHeap->Push(T_Matrix[i]); // edge �迭�� ���� ������ �Է�(pHeap)

	return pHeap;
}

void MST::SetUnion(int v1, int v2){

	if (num[v1] < num[v2]) // �ڽ��� ������ ��
	{
		parent[v1] = v2;
		num[v1] += num[v2];
	}
	else
	{
		parent[v2] = v1;
		num[v2] += num[v1];
	}

}

int MST::GetFind(int v){

	int i, p, elem;

	p = NULL;
	elem = NULL;

	for (i = v; (p = parent[i]) >= 0; i = p);

	elem = i; // ��ǥ����

	for (i = v; (p = parent[i]) >= 0; i = p)
		parent[i] = elem;

	return elem;

}

void MST::kruskal(Heap* pHeap, const int V, const int E){

	edge* ptrEdge;
	queue queueApp;
	int v1Set, v2Set, edgeCount = 0, sum = 0;

	Init_Kruskal(pHeap->GetCapacity()); // ���� �������� ����

	cout << "���õ� ���� ";

	while (edgeCount < V - 1)	// ������ ���� V - 1
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
		}
	}

	// Connect ����Ÿ�� ������ ��
	if (queueApp.GetCapacity() != FALSE)
	{
		cout << endl;
		cout << "�ּҺ�� ����Ʈ���� ���� �� ����" << endl;
		cout << "�ּҺ���� ";

		while (!queueApp.IsEmpty())
			cout << queueApp.pop() << "+";

		cout << "=" << sum << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "�ּҺ�� ����Ʈ���� ���� �� ����" << endl;
		cout << endl;
	} // end of if

	// ����
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