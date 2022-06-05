#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일 : 2020.10.24
프로그램 기능 : 7주차과제3번에 주어진 adjacency list로 표현된 undirected graph를 
			  depth first search 로 traversal한 결과를 출력하는 프로그램
*/

#include <stdio.h>

typedef struct node* nodePointer;
typedef struct node {
	char vertex;
	nodePointer link;
}node;

nodePointer adjLists[7];
short int visited[7] = { 0 };
nodePointer graph[7] = { NULL };

//함수선언
void creat(nodePointer* root, char val);
void dfs(int v);
void main()
{	
	//그래프생성
	creat(&graph[0], 'A');
	creat(&graph[0], 'B');
	creat(&graph[0], 'C');
	creat(&graph[1], 'B');
	creat(&graph[1], 'A');
	creat(&graph[1], 'D');
	creat(&graph[1], 'E');
	creat(&graph[2], 'C');
	creat(&graph[2], 'A');
	creat(&graph[2], 'E');
	creat(&graph[3], 'D');
	creat(&graph[3], 'B');
	creat(&graph[3], 'G');
	creat(&graph[4], 'E');
	creat(&graph[4], 'B');
	creat(&graph[4], 'C');
	creat(&graph[4], 'G');
	creat(&graph[5], 'F');
	creat(&graph[5], 'G');
	creat(&graph[6], 'G');
	creat(&graph[6], 'D');
	creat(&graph[6], 'E');
	creat(&graph[6], 'F');


	//DFS traversal
	printf("Depth First Search의 결과 : ");
	dfs('A');
	printf("\n");
}

//그래프를 만드는 함수
//adjacency list형태의 그래프로 만든다.
void creat(nodePointer* root, char val)
{
	//graph[i]가 null일때(생성)
	if (!(*root))
	{
		(*root) = (nodePointer)malloc(sizeof(node));
		(*root)->vertex = val;
		(*root)->link = NULL;
	}
	//graph[i]에 값이 있을때(추가)
	else
	{
		nodePointer ptr;
		ptr = (nodePointer)malloc(sizeof(node));
		ptr->vertex = val; ptr->link = NULL;

		nodePointer temp;
		for (temp = *root; temp->link;)
			temp = temp->link;
		temp->link = ptr;
	}
}//creat


//DFS traversal하는 함수
void dfs(int v)
{
	nodePointer w;
	visited[v] = 1;
	
	printf("%c ", v);

	//graph의 인덱스찾기
	//ex) 'A'(65)는 graph[0]에 있음
	int n;
	switch (v)
	{
		case 65:
			n = 0;
			break;
		case 66:
			n = 1;
			break;
		case 67:
			n = 2;
			break;
		case 68:
			n = 3;
			break;
		case 69:
			n = 4;
			break;
		case 70:
			n = 5;
			break;
		case 71:
			n = 6;
			break;
	}

	for (w = graph[n]; w; w = w->link)
		if (!visited[w->vertex])
			dfs(w->vertex);
}//dfs