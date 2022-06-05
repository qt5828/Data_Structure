#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일 : 2020.11.14
프로그램 기능 : 실습지에 주어진 그래프의 shortest path의 길이를
			   Bellman-Ford algorithm을 사용하여 구하고, 출력하는 프로그램
			   출발 vertex는 항상 0이며, 도착 vertex는 사용자에게 입력받아서 
			   shortest path의 길이를 구한다.
*/
#include <stdio.h>
#define MAX_VERTICES 6
#define INF 1000
//adjacency matrix
int length[][MAX_VERTICES] =
{ {0,10,INF,20,INF,INF},
	{INF,0,60,INF,INF,INF},
	{INF,INF,0,INF,-30,20},
	{INF,20,INF,0,30,INF},
	{INF,INF,INF,INF,0,10},
	{INF,INF,INF,INF,INF,0} };
int dist[MAX_VERTICES] = { 0 };
int n = MAX_VERTICES;

//함수선언
void BellmanFord(int v);

void main()
{
	int arr;
	printf("도착 vertex를 입력하세요 : ");
	scanf("%d", &arr);

	BellmanFord(arr);
	
}//main


//Bellman-Ford algorithm을 사용하여 주어진 adjacency matrix의 shortest path의 찾아 출력하는 함수
void BellmanFord(int v)
{
	int u, i, k;
	for (i = 0; i < n; i++)
		dist[i] = length[0][i];

	for (i = 1; i < n; i++) {
		for (u = 1; u != 0 && u < n; u++) {
			if (dist[u] > dist[i] + length[i][u])
				dist[u] = dist[i] + length[i][u];
		}
	}

	for (i = 0; i < n; i++) {
		for (u = 0; u != 0 && u < n; u++) {
			if (dist[u] > dist[i] + length[i][u]) {
				printf("There are negative cycle.\n");
				exit(1);
			}
		}
	}

	//shortest path출력
	printf("\nVertex 0번에서 Vertex %d번까지 shortest path의 길이는 %d입니다.\n", v, dist[v]);
}//BellmanFord