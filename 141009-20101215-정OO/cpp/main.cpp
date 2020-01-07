/*
과제:프로그래밍(1~3)
금오공과대학교(Kumoh National Institute of Technology)
학과: 경영(Business) & 컴퓨터소프트웨어공학과(CSE)
학번: 20101215
이름: 정원영
*/

#include <iostream>
#include "ds.h"
#include "io.h"
#include "mst.h"
#include "graph.h"

using namespace std;

// 문자열 to Int형으로 전환
int CharToInt(const char d){
	return (int)d - 48;
}

// 소거
void Destory(Graph* GraphApp, MST* MstApp, Heap* H);

void main()
{
	// 인접행렬 / 인접리스트(그래프) 선언
	int **M = NULL;
	int V, E;
	V = E = NULL;
	Node** G = NULL;

	// MST 관련 선언
	edge** MST_Matrix = NULL;

	// 파일 선언
	IO IOApp;
	std::string FileData;

	while (1)
	{
		Graph* GraphApp = new Graph();
		MST* MstApp = new MST();
		Heap* H = NULL;

		char key;

		cout << "프로그램을 선택하세요 ([S]earch / [M]inimum cost spanning tree / [T]opological Sort / [Q]uit) :";
		cin >> key;

		// 종료
		if (key == CMD_QUIT){
			Destory(GraphApp, MstApp, H); // 할당 제거
			break;
		}

		// 메뉴
		switch (key)
		{
			case CMD_SEARCH:

				FileData = IOApp.GetUserFile(V, E, CMD_SEARCH);  // 파일 읽기

				G = GraphApp->GetAdjList(V, E, FileData);		 // 그래프 생성
				M = GraphApp->GetAdjMatrix(V, E, FileData);		 // 인접행렬 생성

				GraphApp->Print(M, V, CHOOSE_ADJMATRIX);			 // 인접행렬 출력
				GraphApp->Print(G, V, CHOOSE_ADJLIST);			 // 인접리스트 출력
				GraphApp->DFS(M, V, CHOOSE_ADJMATRIX);			 // DFS - 인접행렬
				GraphApp->BFS(M, V, CHOOSE_ADJMATRIX);			 // BFS - 인접행렬
				GraphApp->DFS(G, V, CHOOSE_ADJLIST);				 // DFS - 리스트
				GraphApp->BFS(G, V, CHOOSE_ADJLIST);				 // BFS - 리스트

				GraphApp->Destory_Graph(G, V);					 // Destory - 그래프 제거

				break;

			case CMD_MINIMUM:

				FileData = IOApp.GetUserFile(V, E, CMD_MINIMUM); // 파일 읽기

				MST_Matrix = MstApp->CreateMatrix();				 // MST 행렬 초기화
				MstApp->Insert(MST_Matrix, V, E, FileData);		 // MST_Matrix = 데이터 입력
				H = MstApp->GetHeap(MST_Matrix, E);				 // Heap 데이터 가져오기
				MstApp->kruskal(H, V, E);						 // Kruskal 실행
				MstApp->DestoryMatrix(MST_Matrix);				 // 소멸

				break;

			case CMD_TOPOLOGICAL:

				FileData = IOApp.GetUserFile(V, E, CMD_TOPOLOGICAL); // 파일 읽기

				G = GraphApp->GetAdjList(V, E, FileData);			 // 그래프 생성
				GraphApp->Topologic_Sort(G, V);						 // Topologic Sort 실행

				GraphApp->Destory_Graph(G, V);					     // Destory - 그래프 제거

				break;

			default:
				cout << "잘못된 명령어" << endl;
				continue;
				break;

		} // end of switch

		Destory(GraphApp, MstApp, H); // 할당 제거

	}
}

void Destory(Graph* GraphApp, MST* MstApp, Heap* H){

	// 소거
	delete GraphApp;				// 그래프 제거
	delete MstApp;					// MST 제거

	if (H != NULL)
		delete H;					// Heap 제거

	// 안전한 소거
	GraphApp = NULL;
	MstApp = NULL;
	H = NULL;

}