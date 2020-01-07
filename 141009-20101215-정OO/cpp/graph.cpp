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

	// Visited[] �ʱ�ȭ
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

	cout << "�Էµ� �׷����� ������� ǥ��" << endl;

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

	cout << "�Էµ� �׷����� ��������Ʈ ǥ��";

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

	// ���� ��� �ʱ�ȭ
	Init_Visited(V);
	SetCount(NUM_FIRST);
	SetEnt(INITIALIZE);
	SetSW(INITIALIZE_RECUR_DFS);

	// Ÿ��Ʋ ���
	cout << "1. ������� + DFS" << endl;

	for (int i = 0; i < V; i++)
	{
		DFS_Recur(AdjMatrix, V, i, D);
	} // end of for

	cout << endl << endl;
}

void Graph::DFS_Recur(int** AdjMatrix, int V, int i, std::string D)
{
	int w;

	if (Visited[i] == FALSE)
	{
		if (GetEnt() == INITIALIZE)
		{
			Print_Component(); // ���
			SetEnt(FALSE);
			SetCount(GetCount() + 1);		
		}

		if (GetEnt() == SW)
		{
			cout << endl;
			Print_Component(); // ���
			SetSW(TRUE);
			SetEnt(FALSE);
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

	int i = 0, j = 0;
	int check = INITIALIZE;
	queue queueApp;

	// ���� ��� �ʱ�ȭ
	SetEnt(FALSE);
	SetCount(NUM_ZERO);
	SetSW(GRAPH_COMPONENT);
	Init_Visited(V);

	cout << "2. ������� + BFS";

	while (i < V)
	{
		// ������ Ÿ��Ʋ �ⷰ
		switch (check)
		{
			case INITIALIZE:
				Print_Component(check);
				break;

			case TRUE:
				Print_Component(check, TRUE, CHOOSE_ENT_CHANGE);
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
				SetSW(1);
			} // end of if

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
					} // end of if
				} // end of for

			} // end of while

		}
		else
		{
			SetEnt(GetEnt() + 1);
		} // end of if

		i++;
	} // end of while

	cout << endl << endl;

}

void Graph::DFS(Node* AdjList[], int V, int Option, queue* queueApp){

	int i, j;
	int check = INITIALIZE;

	Node* ptr = NULL;
	stack stackApp;

	// Visited[] �ʱ�ȭ
	Init_Visited(V);

	SetEnt(FALSE);
	SetSW(GRAPH_COMPONENT);
	SetCount(NUM_ZERO);

	// Ÿ��Ʋ ��� / ��������Ʈ�� ���
	if (Option == CHOOSE_ADJLIST)
		cout << "3. ��������Ʈ + DFS";

	i = 0;
	while (i < V)
	{
		// ������ Ÿ��Ʋ �ⷰ / ��������Ʈ�� ���
		if (Option == CHOOSE_ADJLIST)

			switch (check)
			{
				case INITIALIZE:
					Print_Component(check);
					break;

				case TRUE:
					Print_Component(check, TRUE, CHOOSE_ENT_CHANGE);

				break;

				default:
					break;
			} // end of switch

		// �湮 ���� �Ǵ�
		if (Visited[i] == FALSE)
		{
			stackApp.push(i);
			Visited[i] = TRUE;

			if (check == FALSE && GetEnt() == GetSW())
			{
				check = TRUE;
				SetSW(TRUE);
			} // end of if

			while (!stackApp.IsEmpty())
			{
				j = stackApp.pop();

				// ��� / ��������Ʈ�� ���
				if (Option == CHOOSE_ADJLIST)
					Print_Visited(j);
				
				// Topologic ���� �Ǵ�
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

	// ��� / ��������Ʈ�� ���
	if (Option == CHOOSE_ADJLIST)
		cout << endl << endl;

}

void Graph::BFS(Node* AdjList[], int V, int Option){

	int w = 0, j = 0;
	int check = INITIALIZE;

	Node* ptr = NULL;
	queue queueApp;

	SetCount(NUM_ZERO);
	SetEnt(FALSE);

	// Visited[] �ʱ�ȭ
	Init_Visited(V);

	cout << "4. ��������Ʈ + BFS";

	while (w < V)
	{
		// ������ Ÿ��Ʋ �ⷰ
		if (check == INITIALIZE)
			Print_Component(check);

		if (check == TRUE && Ent == 0 && w != V)
			Print_Component(check, TRUE, CHOOSE_ENT_INCREASE);

		// �湮 ���� �Ǵ�
		if (Visited[w] == FALSE){
			
			queueApp.push(w);
			Visited[w] = TRUE;
			SetEnt(FALSE); // �� ���� �ذ�

			while (!queueApp.IsEmpty())
			{
				j = queueApp.pop();
				Print_Visited(j);

				ptr = AdjList[j];

				if (ptr == NULL)
					break;

				if (Visited[ptr->vertex] == FALSE)
				{
					Visited[ptr->vertex] = TRUE;
					queueApp.push(ptr->vertex);
					AdjList[j] = ptr->next;
				} // end of if
			}

		}
		else
		{
			check = TRUE;
		} // end of if

		w++;
	} // end of while

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
void Graph::Print_Component(){
	cout << "������" << GetCount() << " - ";
}
void Graph::Print_Component(int& check, int entnum, int type){
	
	cout << endl;

	check = FALSE;
	SetCount(GetCount() + 1);

	Print_Component();

	switch (entnum)
	{
		case TRUE:
			
			if (type == CHOOSE_ENT_INCREASE)
				SetEnt(GetEnt() + 1);
			if (type == CHOOSE_ENT_CHANGE)
				SetEnt(entnum);

			break;

		case FALSE:
			break;
	}

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
	} // end of for

	E = 0;

	// DATA �ҷ�����
	size = D.length();
	for (int i = 0; i < size; i++)
	{
		if (D.at(i) == '\n'){

			// Edge ��� ó��
			if (!stackApp.IsEmpty() && GetCount() == GRAPH_COMPONENT)
			{
				y = stackApp.pop();
				x = stackApp.pop();

				AdjMatrix[x][y] = TRUE;

				E++;
			}
			// Stack ����
			while (!stackApp.IsEmpty())
				stackApp.pop();
                
			SetCount(0);
			ChkContinue = FALSE;
			continue;

		} // end of if

		// Edge ��� ó��
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

	// DATA �ҷ�����
	size = D.length();
	for (int i = 0; i < size; i++)
	{
		if (D.at(i) == '\n'){

			// Edge ��� ó��
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
			// Stack ����
			while (!stackApp.IsEmpty())
				stackApp.pop();

			SetCount(0);
			ChkContinue = FALSE;
			continue;

		} // end of if

		// Edge ��� ó��
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
			} // end of while

		} // end of for

		ptr = AdjList[i];

		if (ptr != NULL)
			AdjList[i]->count = GetCount();

	} // end of for

}

void Graph::Topologic_Sort(Node* AdjList[], int V){
	
	queue queueApp;
	DFS(AdjList, V, CHOOSE_TOPOLOGIC, &queueApp); // DFS�� �̿��� ��������

	if (!queueApp.IsEmpty())
		cout << "������ �ϳ��� ���� ���� : ";
	else
		cout << "�ش� ������ Cycle�� �����ϴ�.";

	while (!queueApp.IsEmpty())
		cout << queueApp.pop() << " ";

	cout << endl << endl;

}