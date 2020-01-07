#include <iostream>

#define MAX_VERTICES 8
#define FALSE 0
#define TRUE 1

typedef struct node *node_point;
typedef struct node
{
	int vertex;
	node_point link;
};

node_point graph[MAX_VERTICES];
short int visited[MAX_VERTICES];
node_point createnode(int data);

void dfs(int vertex);

void setup(int size){



}

void main()
{
	graph[0] = createnode(0);
	graph[0]->link = createnode(1);
	graph[1] = createnode(0);
	graph[1]->link = createnode(2);
	graph[1]->link->link = createnode(3);
	graph[2] = createnode(1);
	graph[2]->link = createnode(3);
	graph[3] = createnode(0);

	printf("정점의 운행 순서 : ");
	
	dfs(0);
	printf("끝\n");
}
/* 노드 생성을 위한 함수 */
node_point createnode(int data)
{
	node_point ptr;
	ptr = (node_point)malloc(sizeof(struct node));
	ptr->vertex = data;
	ptr->link = NULL;
	return ptr;
}
void dfs(int v)
{
	/*그래프의 정점 V에서 시작하는 깊이 우선 탐색 */
	node_point w;

	visited[v] = TRUE;

	printf("V%d -> ", v);

	for (w = graph[v]; w; w = w->link)
	if (!visited[w->vertex])
		dfs(w->vertex);
}