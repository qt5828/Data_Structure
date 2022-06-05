#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일 : 2020.11.06
프로그램 기능 : Dijkstra Algorithm을 사용하여 shortest path를 찾는 프로그램.
			   출발 vertex는 A이며, 도착 vertex는 사용자에게 입력받아 실행한다.
			   A로부터 출발하여 임의의 도착 vertex까지의 최단 거리 경로와 그때의
			   최단 거리가 출력되도록 한다.
*/
#include <stdio.h>
#include <stdlib.h>

//adjaceny matrix
#define MAX_VERTICES 7
int cost[][MAX_VERTICES] =
{ {0,10,7,1000,15,1000,1000},
	{10,0,1000,5,8,1000,1000},
	{7,1000,0,1000,6,1000,1000},
	{1000,5,1000,0,12,6,1000},
	{15,8,6,12,0,1000,3},
	{1000,1000,1000,6,1000,0,1},
	{1000,1000,1000,1000,3,1,0} };
//array of best estimates of shortest path to each vertex
int distance[MAX_VERTICES];
//check to visited
short int found[MAX_VERTICES];
int n = MAX_VERTICES;
//index of an array of predecessors for each vertex
int PI[MAX_VERTICES] = { 0 };

//함수선언
void Dijkstra(char v);
int choose();
void print(char v, char m);

void main()
{
	//사용자에게 출발지역과 도착지역을 입력받음
	//A~E사이의 알파벳만 입력한다고 가정한다.
	//출발지역은 항상 A라고 가정
	char start, end;
	printf("출발지역을 입력하세요 : ");
	scanf("%c", &start);
	printf("도착지역을 입력하세요 : ");
	scanf(" %c", &end);

	//Dijkstra algorithm방법으로 최단거리경로와 최단거리를 찾아 출력
	Dijkstra(start, end);
}//main

//시작지역 v와 도착지역 m을 입력받아 Dijkstra algorithm방법으로 두 지역 사이의 
//최단거리경로와 최단거리를 찾아 출력하는 함수
//강의노트의 소스참고함
void Dijkstra(char v, char m)
{
	int i, u, w;
	for (i = 0; i < n; i++)
	{
		found[i] = 0;
		distance[i] = cost[v - 65][i]; //v는 char형이므로 정수값과 동일하게 만듦(A=0,B=1,...)
	}
	found[v - 65] = 1; distance[v - 65] = 0;

	for (i = 0; i < n - 1; i++)
	{
		u = choose();
		found[u] = 1;
		for (w = 0; w < n; w++)
			if (!found[w])
				if (distance[u] + cost[u][w] < distance[w]) {
					distance[w] = distance[u] + cost[u][w];
					//predecessor의 index값 저장
					PI[w] = u;
				}
	}
	//최단경로와 최단거리 출력
	print(v, m);

}//Dijkstra


//Dijkstra방법으로 찾은 최단경로와 최단거리를 출력하는 함수
void print(char v, char m)
{
	int i, j = 0;
	//최단경로를 저장하기 위한 array
	int ver[MAX_VERTICES];

	//도착지역의 predecessor의 인덱스부터 출발지점의 인덱스까지 차례로 찾아 ver에 저장
	for (i = m - 65; i != v - 65;)
	{
		ver[j++] = i + 65;
		i = PI[i];
	}

	//최단경로 출력
	printf("Vertex %c에서 Vertex %c으로 가는 최단 경로는 ", v, m);
	ver[j++] = i + 65;
	for (j = j - 1; j >= 0; j--)
		printf("%c ", ver[j]);
	
	//최단거리 출력
	printf("이며, 이때 최단 거리는 ");
	printf("%d입니다.\n ", distance[m - 65]);

}//print

//아직 방문하지 않은 vertex중에서 최단거리의 vertex를 찾아 위치를 반환하는 함수
int choose()
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}//choose
