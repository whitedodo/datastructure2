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
#include "graph.h"

using namespace std;

int CharToInt(const char d);

List::List(){
	first = NULL;
}

List::~List(){

	Node* ptr;

	while (first != NULL)
	{
		ptr = first;
		first = first->next;
		delete[] ptr;
	}

}



void List::Insert(int vertex){
	
	Node* ptr = new Node();
	ptr->vertex = vertex;
	ptr->next = first;

	first = ptr;

}

void List::Remove(int vertex){

	Node* current = first;
	Node* previous = NULL;

	while (current)
	{
		if (current->vertex == vertex)
			break;

		previous = current;
		current = current->next;
	}

	if (current)
	{
		if (previous)
			previous->next = first->next;
		else
			first = first->next;

		delete[] current;
	}
}

int List::NotNull(){

	if (first)
		return TRUE;
	else
		return FALSE;

}

int List::NextNotNull(){

	if (first->next != NULL)
		return TRUE;
	else
		return FALSE;
}

Graph::Graph(){
	Visited = NULL;
}

Graph::~Graph(){
	delete[] Visited;
}

void Graph::Destory_Graph(Node* AdjList[], int V){

	Node* ptr = NULL;

	for (int i = 0; i < V; i++)
	{
		ptr = AdjList[i];

		if (ptr != NULL)
			delete[] ptr;
	}

	delete[] AdjList;

}

void Graph::Init_Visited(int V){

	if (Visited != NULL)
		delete[] Visited;

	Visited = new int[V];

	// Visited[] 초기화
	for (int i = 0; i < V; i++)
		Visited[i] = FALSE;
}


void Graph::Print(Node* AdjList[], int V, int OPTION){

	switch (OPTION)
	{
		case CHOOSE_ADJLIST:
			Print_AdjList(AdjList, V);
			break;

		default:
			break;
	}
}


void Graph::Print(int* AdjMatrix[], int V, int OPTION){

	switch (OPTION)
	{
	case CHOOSE_ADJMATRIX:
		Print_AdjMatrix(AdjMatrix, V);
		break;

	default:
		break;
	}
}

void Graph::Print_Visited(int Number){
	cout << Number << " ";
}

void Graph::Print_AdjMatrix(int* AdjMatrix[], int V){

	cout << "입력된 그래프의 인접행렬 표현" << endl;

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			cout << AdjMatrix[i][j] << " ";
		} // End of for

		cout << endl;

	} // End of for

	cout << endl;
}

void Graph::Print_AdjList(Node* AdjList[], int V){

	Node* ptr;

	cout << "입력된 그래프의 인접리스트 표현";

	for (int i = 0; i < V; i++)
	{
		cout << endl << i;

		ptr = AdjList[i];

		if (ptr != NULL)
		{
			while (ptr != NULL)
			{
				cout << "-> " << ptr->vertex << " ";
				ptr = ptr->next;
			} // End of while
		}
		else
			cout << "-> null" << endl;

	} // End of for

	cout << endl;

}

void Graph::DFS(int** AdjMatrix, int V, int Option){

	std::string D;
	int Cnt = 0;

	Init_Visited(V);
	SetCount(1);
	SetEnt(INITIALIZE);
	SetSW(3);

	// 타이틀 출력
	cout << "1. 인접행렬 + DFS" << endl;

	for (int i = 0; i < V; i++)
	{
		DFS_Recur(AdjMatrix, V, i, D);
	}

	cout << endl << endl;
}

void Graph::DFS_Recur(int** AdjMatrix, int V, int i, std::string D)
{
	int w;

	if (Visited[i] == FALSE)
	{
		if (GetEnt() == INITIALIZE)
		{
			cout << "연결요소" << GetCount() << " - ";
			SetEnt(0);
			SetCount(GetCount() + 1);
		}

		if (GetEnt() == SW)
		{
			cout << endl;
			cout << "연결요소" << GetCount() << " - ";
			SetSW(1);
			SetEnt(0);
			SetCount(GetCount() + 1);
		}

		Print_Visited(i);
		Visited[i] = TRUE;
	}
	else
	{
		SetEnt(GetEnt() + 1);
	}

	w = 0;

	while (w < V)
	{
		if (AdjMatrix[i][w] == TRUE)
		{
			if (Visited[w] == FALSE){
				DFS_Recur(AdjMatrix, V, w, D);
			}
		}

		w++;
	}

}

void Graph::BFS(int** AdjMatrix, int V, int Option){

	int i = 0, j = 0, Ent = 0;
	Count = 0, SW = 2;
	int check = INITIALIZE;
	queue queueApp;

	Init_Visited(V);

	cout << "2. 인접행렬 + BFS" << endl;

	while (i < V)
	{
		// 연결요소 타이틀 출럭
		switch (check)
		{
			case INITIALIZE:
				cout << "연결요소" << ++Count << " - ";
				check = FALSE;
				break;

			case TRUE:
				cout << endl;
				cout << "연결요소" << ++Count << " - ";
				Ent = 1;
				check = FALSE;

				break;

			default:
				break;
		}

		if (Visited[i] == FALSE)
		{
			queueApp.push(i);
			Visited[i] = TRUE;

			if (check == FALSE && Ent == SW)
			{
				check = TRUE;
				SW = 1;
			}

			while (!queueApp.IsEmpty())
			{
				j = queueApp.pop();
				Print_Visited(j);

				for (j = 0; j < V; j++)
				{
					if (AdjMatrix[i][j] != FALSE && Visited[j] == 0)
					{
						queueApp.push(j);
						Visited[j] = TRUE;
					}
				}

			} // end of while

		}
		else
		{
			Ent++;
		}

		i++;
	} // end of while

	cout << endl << endl;

}

void Graph::DFS(Node* AdjList[], int V, int Option, queue* queueApp){

	int i, j;
	int check = INITIALIZE;

	Node* ptr = NULL;
	stack stackApp;

	// Visited[] 초기화
	Init_Visited(V);

	SetEnt(0);
	SetCount(1);
	SetSW(2);

	// 타이틀 출력 / 인접리스트의 경우
	if (Option == CHOOSE_ADJLIST)
		cout << "3. 인접리스트 + DFS" << endl;

	i = 0;
	while (i < V)
	{
		// 연결요소 타이틀 출럭 / 인접리스트의 경우
		if (Option == CHOOSE_ADJLIST)
			switch (check)
			{
				case INITIALIZE:
					cout << "연결요소" << GetCount() << " - ";
					check = FALSE;
					SetCount(GetCount() + 1);
					break;

				case TRUE:
					cout << endl;
					cout << "연결요소" << GetCount() << " - ";
					check = FALSE;
					SetEnt(1);
					SetCount(GetCount() + 1);

				break;

				default:
					break;
			}

		// 방문 여부 판단
		if (Visited[i] == FALSE)
		{
			stackApp.push(i);
			Visited[i] = TRUE;

			if (check == FALSE && GetEnt() == GetSW())
			{
				check = TRUE;
				SetSW(1);
			}

			while (!stackApp.IsEmpty())
			{
				j = stackApp.pop();

				// 출력 / 인접리스트의 경우
				if (Option == CHOOSE_ADJLIST)
					Print_Visited(j);
				
				// Topologic 여부 판단
				if (Option == CHOOSE_TOPOLOGIC)
					queueApp->push(j);

				ptr = AdjList[i];

				while (ptr)
				{
					if (Visited[ptr->vertex] == FALSE)
					{
						stackApp.push(ptr->vertex);
						Visited[ptr->vertex] = TRUE;
					} // end of if

					ptr = ptr->next;
				} // end of while

			} // end of while
		}
		else
		{
			SetEnt(GetEnt() + 1);
		} // end of if

		i++;
	} // end of while

	// 출력 / 인접리스트의 경우
	if (Option == CHOOSE_ADJLIST)
		cout << endl << endl;

}

void Graph::BFS(Node* AdjList[], int V, int Option){

	int w = 0, j = 0;
	int check = INITIALIZE;

	Node* ptr = NULL;
	queue queueApp;

	SetCount(1);
	SetEnt(0);

	// Visited[] 초기화
	Init_Visited(V);

	cout << "4. 인접리스트 + BFS" << endl;

	while (w < V)
	{
		// 연결요소 타이틀 출럭
		if (check == INITIALIZE)
		{
			cout << "연결요소" << GetCount() << " - ";
			
			check = FALSE;
			SetCount(GetCount() + 1);
		}
		if (check == TRUE && Ent == 0 && w != V)
		{
			cout << endl;
			cout << "연결요소" << ++Count << " - ";
			
			check = FALSE;
			SetCount(GetCount() + 1);
			SetEnt(GetEnt() + 1);
		}

		// 방문 여부 판단
		if (Visited[w] == FALSE){
			
			queueApp.push(w);
			Visited[w] = TRUE;
			SetEnt(0); // 줄 문제 해결

			while (!queueApp.IsEmpty())
			{
				j = queueApp.pop();
				Print_Visited(j);

				ptr = AdjList[j];

				if (ptr == NULL)
				{
					break;
				}

				if (Visited[ptr->vertex] == FALSE)
				{
					Visited[ptr->vertex] = TRUE;
					queueApp.push(ptr->vertex);
					AdjList[j] = ptr->next;
				}
			}

		}
		else
		{
			check = TRUE;
		}

		w++;
	}

	cout << endl << endl;
}


int** Graph::GetAdjMatrix(int V, int E, std::string D){

	int** M;
	M = new int*[V];

	// INITIALIZED
	for (int i = 0; i < V; i++)
		M[i] = new int[V];

	Input_AdjMatrix(M, V, E, D);
	return M;
}

Node** Graph::GetAdjList(int V, int E, std::string D){
	
	Node** G = NULL;
	G = new Node*[V];

	Input_AdjList(G, V, E, D);

	return G;
}

void Graph::Input_AdjMatrix(int **AdjMatrix, int V, int E, std::string D){

	int x = NULL, y = NULL;
	int num, size;
	int ChkContinue = FALSE;

	stack stackApp;

	// INITIALIZE
	SetCount(0);

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
			AdjMatrix[i][j] = FALSE;
	}

	E = 0;

	// DATA 불러오기
	size = D.length();
	for (int i = 0; i < size; i++)
	{
		if (D.at(i) == '\n'){

			// Edge 등록 처리
			if (!stackApp.IsEmpty() && GetCount() == GRAPH_COMPONENT)
			{
				y = stackApp.pop();
				x = stackApp.pop();

				AdjMatrix[x][y] = TRUE;

				E++;
			}
			// Stack 비우기
			while (!stackApp.IsEmpty())
				stackApp.pop();
                
			SetCount(0);
			ChkContinue = FALSE;
			continue;

		} // end of if

		// Edge 등록 처리
		if (D.at(i) == ' '){

			if (!stackApp.IsEmpty() && GetCount() == GRAPH_COMPONENT)
			{
				y = stackApp.pop();
				x = stackApp.pop();

				AdjMatrix[x][y] = TRUE;

				SetCount(0);
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

				SetCount(GetCount() + 1);
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

void Graph::Input_AdjList(Node* AdjList[], int V, int E, std::string D){
	
	int x = NULL, y = NULL;
    int num = NULL, size = NULL;
	int ChkContinue = FALSE;

	stack stackApp;
	Node* ptr = NULL;
	
	// INITIALIZE
	SetCount(0);
	for (int i = 0; i < V; i++)
		AdjList[i] = NULL;

	E = 0;

	// DATA 불러오기
	size = D.length();
	for (int i = 0; i < size; i++)
	{
		if (D.at(i) == '\n'){

			// Edge 등록 처리
			if (!stackApp.IsEmpty() && GetCount() == GRAPH_COMPONENT)
			{
				y = stackApp.pop();
				x = stackApp.pop();

				ptr = new Node();
				ptr->vertex = y;
				ptr->next = AdjList[x];
				AdjList[x] = ptr;

				E++;
			}
			// Stack 비우기
			while (!stackApp.IsEmpty())
				stackApp.pop();

			SetCount(0);
			ChkContinue = FALSE;
			continue;

		} // end of if

		// Edge 등록 처리
		if (D.at(i) == ' '){

			if (!stackApp.IsEmpty() && GetCount() == GRAPH_COMPONENT)
			{
				y = stackApp.pop();
				x = stackApp.pop();

				ptr = new Node();
				ptr->vertex = y;
				ptr->next = AdjList[x];
				AdjList[x] = ptr;

				SetCount(0);
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

				SetCount(GetCount() + 1);
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

void Graph::SetCount_Indegree(Node* AdjList[], int V){

	int i, j;
	Node* ptr = NULL;

	for (i = 0; i < V; i++)
	{
		SetCount(0);
		for (j = 0; j < V; j++)
		{
			ptr = AdjList[j];
			while (ptr != NULL)
			{
				if (ptr->vertex == i)
					SetCount(GetCount() + 1);

				ptr = ptr->next;
			}
		} // end of for

		ptr = AdjList[i];
		if (ptr != NULL)
			AdjList[i]->count = GetCount();
	}

}

void Graph::Topologic_Sort(Node* AdjList[], int V){
	
	queue queueApp;
	DFS(AdjList, V, CHOOSE_TOPOLOGIC, &queueApp); // DFS를 이용한 위상정렬

	if (!queueApp.IsEmpty())
		cout << "가능한 하나의 위상 정렬 : ";
	else
		cout << "해당 정렬은 Cycle을 갖습니다.";

	while (!queueApp.IsEmpty())
		cout << queueApp.pop() << " ";

	cout << endl << endl;

}