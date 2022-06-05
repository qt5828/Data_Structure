#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일 : 2020.11.12
프로그램 기능 : All Pairs Shortest Path Alogithm을 사용하여 주어진 graph의 adjacency matrix의
			   각 vertex쌍에 대한 shortest path를 찾아 행렬형태로 출력하는 프로그램
*/
#include <Stdio.h>

#define MAX_VERTICES 6
#define INF 1000
int n = MAX_VERTICES;
int cost[][MAX_VERTICES] =
{ {0,50,45,10,INF,INF },
{INF,0,10,15,INF,INF},
{INF,INF,0,INF,30,INF},
{20,INF,INF,0,15,INF},
{INF,20,35,INF,0,INF},
{INF,INF,INF,INF,3,0} };

int distance[][MAX_VERTICES] = { 0 };

//함수선언
void AllPairsShortestPath();
void print();

void main()
{
	AllPairsShortestPath();
	print();
}//main

//All Pairs Shortest Path Alogithm을 사용하여 주어진 graph의 adjacency matrix의 
//각 vertex쌍에 대한 shortest path를 찾아 distance에 저장하는 함수
void AllPairsShortestPath()
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) {
			distance[i][j] = cost[i][j];
		}
	}
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (distance[i][k] + distance[k][j] < distance[i][j])
					distance[i][j] = distance[i][k] + distance[k][j];
			}
		}
	}
}

//distance의 배열을 행렬 형태로 출력하는 함수
//즉, 모든 vertex쌍에 대한 shortest path의 길이를 matrix형태로 모두 출력하는 함수
void print()
{
	printf("===============================\n");
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (distance[i][j] == 1000)
				printf(" * ");
			else
				printf("%2d ", distance[i][j]);
		}
		printf("\n");
	}
	printf("===============================\n");
}