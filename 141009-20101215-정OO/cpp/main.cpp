/*
����:���α׷���(1~3)
�ݿ��������б�(Kumoh National Institute of Technology)
�а�: �濵(Business) & ��ǻ�ͼ���Ʈ������а�(CSE)
�й�: 20101215
�̸�: ������
*/

#include <iostream>
#include "ds.h"
#include "io.h"
#include "mst.h"
#include "graph.h"

using namespace std;

// ���ڿ� to Int������ ��ȯ
int CharToInt(const char d){
	return (int)d - 48;
}

// �Ұ�
void Destory(Graph* GraphApp, MST* MstApp, Heap* H);

void main()
{
	// ������� / ��������Ʈ(�׷���) ����
	int **M = NULL;
	int V, E;
	V = E = NULL;
	Node** G = NULL;

	// MST ���� ����
	edge** MST_Matrix = NULL;

	// ���� ����
	IO IOApp;
	std::string FileData;

	while (1)
	{
		Graph* GraphApp = new Graph();
		MST* MstApp = new MST();
		Heap* H = NULL;

		char key;

		cout << "���α׷��� �����ϼ��� ([S]earch / [M]inimum cost spanning tree / [T]opological Sort / [Q]uit) :";
		cin >> key;

		// ����
		if (key == CMD_QUIT){
			Destory(GraphApp, MstApp, H); // �Ҵ� ����
			break;
		}

		// �޴�
		switch (key)
		{
			case CMD_SEARCH:

				FileData = IOApp.GetUserFile(V, E, CMD_SEARCH);  // ���� �б�

				G = GraphApp->GetAdjList(V, E, FileData);		 // �׷��� ����
				M = GraphApp->GetAdjMatrix(V, E, FileData);		 // ������� ����

				GraphApp->Print(M, V, CHOOSE_ADJMATRIX);			 // ������� ���
				GraphApp->Print(G, V, CHOOSE_ADJLIST);			 // ��������Ʈ ���
				GraphApp->DFS(M, V, CHOOSE_ADJMATRIX);			 // DFS - �������
				GraphApp->BFS(M, V, CHOOSE_ADJMATRIX);			 // BFS - �������
				GraphApp->DFS(G, V, CHOOSE_ADJLIST);				 // DFS - ����Ʈ
				GraphApp->BFS(G, V, CHOOSE_ADJLIST);				 // BFS - ����Ʈ

				GraphApp->Destory_Graph(G, V);					 // Destory - �׷��� ����

				break;

			case CMD_MINIMUM:

				FileData = IOApp.GetUserFile(V, E, CMD_MINIMUM); // ���� �б�

				MST_Matrix = MstApp->CreateMatrix();				 // MST ��� �ʱ�ȭ
				MstApp->Insert(MST_Matrix, V, E, FileData);		 // MST_Matrix = ������ �Է�
				H = MstApp->GetHeap(MST_Matrix, E);				 // Heap ������ ��������
				MstApp->kruskal(H, V, E);						 // Kruskal ����
				MstApp->DestoryMatrix(MST_Matrix);				 // �Ҹ�

				break;

			case CMD_TOPOLOGICAL:

				FileData = IOApp.GetUserFile(V, E, CMD_TOPOLOGICAL); // ���� �б�

				G = GraphApp->GetAdjList(V, E, FileData);			 // �׷��� ����
				GraphApp->Topologic_Sort(G, V);						 // Topologic Sort ����

				GraphApp->Destory_Graph(G, V);					     // Destory - �׷��� ����

				break;

			default:
				cout << "�߸��� ��ɾ�" << endl;
				continue;
				break;

		} // end of switch

		Destory(GraphApp, MstApp, H); // �Ҵ� ����

	}
}

void Destory(Graph* GraphApp, MST* MstApp, Heap* H){

	// �Ұ�
	delete GraphApp;				// �׷��� ����
	delete MstApp;					// MST ����

	if (H != NULL)
		delete H;					// Heap ����

	// ������ �Ұ�
	GraphApp = NULL;
	MstApp = NULL;
	H = NULL;

}