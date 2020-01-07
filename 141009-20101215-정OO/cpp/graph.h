/*
	����:���α׷���(1~3)
	�ݿ��������б�(Kumoh National Institute of Technology)
	�а�: �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
	�й�: 20101215
	�̸�: ������
*/

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <string.h>

using namespace std;

const int INITIALIZE = -9999;
const int NUM_ZERO = 0;
const int NUM_FIRST = 1;
const int CONTINUE = 1;
const int INITIALIZE_RECUR_DFS = 3;

const int CHOOSE_ADJLIST = 1;
const int CHOOSE_ADJMATRIX = 2;
const int CHOOSE_TOPOLOGIC = 3;
const int GRAPH_COMPONENT = 2;

const int CHOOSE_ENT_CHANGE = 1;
const int CHOOSE_ENT_INCREASE = 2;

class Node{
public:
	int vertex;
	Node* next;
	
	int count;
};

class List{
public:
	List();
	~List();
	void Insert(int vertex);
	void Remove(int vertex);
	int NotNull();
	int NextNotNull();
private:
	Node* first;
};

class Graph{
public:
	Graph();
	~Graph();
	void Init_Visited(int V);

	void BFS(int** AdjMatrix, int V, int Option);
	void DFS(int** AdjMatrix, int V, int Option);
	void BFS(Node* AdjList[], int V, int Option);
	void DFS(Node* AdjList[], int V, int Option, queue* queueApp = NULL);
	
	void Destory_Graph(Node* AdjList[], int V);

	void Topologic_Sort(Node* AdjList[], int V);

	Node** GetAdjList(int V, int E, std::string D);
	int** GetAdjMatrix(const int V, int E, std::string D);

	void Print_Visited(int Number);
	void Print(Node* AdjList[], int V, int OPTION);
	void Print(int* AdjMatrix[], int V, int OPTION);

private:
	void SetCount_Indegree(Node* AdjList[], int V);
	// DFS - AdjMatrix ����(����� �������� �ǵ������� ����)
	void DFS_Recur(int** AdjMatrix, int V, int i, std::string D);
	void Print_Component(int& check, int entnum = 0, int type = FALSE);
	void Print_Component();

	void SetCount(int n){ Count = n; };
	int GetCount(){ return Count; };
	void SetSW(int choose){ SW = choose; };
	int GetSW(){ return SW; };
	void SetEnt(int ent){ Ent = ent; };
	int GetEnt(){ return Ent; };
	void Input_AdjList(Node* AdjList[], int V, int E, std::string D);
	void Input_AdjMatrix(int** AdjMatrix, int V, int E, std::string D);
	void Print_AdjList(Node* AdjList[], int V);
	void Print_AdjMatrix(int** AdjMatrix, int V);

protected:
	int* Visited;
	int SW;
	int Count;
	int Ent;
};


#endif