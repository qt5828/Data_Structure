#define _CRT_SECURE_NO_WARNINGS
/* 
작성자 : 조우연
작성일 : 2020.11.06
프로그램 기능 : Prim의 algorithm을 이용하여 실습지에 주어진 graph의 minimum cost spanning tree를
			   생성하는 프로그램. 0번 vertex부터 시작하는 minimum cost spanning tree를 생성한다.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 7
//adjacent matrix
int cost[][MAX_VERTICES] =
{ {1000,3,17,6,1000,1000,1000},
{3,1000,1000,5,1000,1000,12},
{17,1000,1000,1000,10,8,1000},
{6,5,1000,1000,9,1000,1000},
{1000,1000,10,9,1000,4,2},
{1000,1000,8,1000,4,1000,14},
{1000,12,1000,1000,2,14,1000} };

//edge의 정보에 대한 구조체
typedef struct edge {
	int vertex1;
	int vertex2;
	int cost;
}edge;

//함수선언
void Prim(int v);

void main()
{
	printf("Prim's algorithm을 이용한 minimum cost spanning tree 생성 : \n");
	Prim(0);
}//main

//Prim's algorithm을 이용하여 parameter로 주어진 vertex를 시작으로하는 minimum cost spanning tree를 생성하여 출력하는 함수.
void Prim(int v)
{
	int i, j, k, n = 0; //n은 방문한 vertex의 개수-1
	int count = 0; //edge수
	//방문한 vertex인지 확인하기 위한 visited, 방문시 1, 아니면 0
	int visited[MAX_VERTICES] = { 0 };
	//방문한 vertex집합
	int TV[MAX_VERTICES];

	//방문한 vertex들과 인접한 edge중에서 minimum cost를 갖는 vertex와 cost의 정보를 저장하기 위한 변수
	edge min;

	//TV의 원소는 1000으로 초기화
	//TV에 저장된 원소들의 개수를 알기 위함
	for (i = 0; i < MAX_VERTICES; i++)
		TV[i] = 1000;
	
	printf("T = { ");

	//TV의 첫번째 자리에 처음 방문한 vertex 추가
	TV[n] = v;
	//방문했으므로 1로 변경
	visited[v] = 1;

	//edge수가 vertex개수-1 될때까지 반복
	while (count < MAX_VERTICES - 1)
	{
		//min의 cost값을 가장 큰 수로 초기화
		min.cost = INT_MAX;
		//TV에 있는 vertex들과 인접한 것들의 cost min 찾기
		for (j = 0; TV[j] != 1000; j++)
		{
			for (k = 0; k < MAX_VERTICES; k++) {
				//이미 방문한 vertex라면 중복하지 않음
				if (visited[k] == 1) {
					continue;
				}
				//min.cost보다 작은 cost값을 가지고 있는 edge를 min.cost로 바꿈
				//이에 대한 vertex의 정보도 cost.vertex에 저장
				if (min.cost > cost[TV[j]][k]) {
					min.cost = cost[TV[j]][k];
					min.vertex1 = TV[j];
					min.vertex2 = k;
				}
			}
		}
		//TV에 있는 vertex들과 인접한 것들 중 가장 작은 cost를 가진 vertex를 TV에 추가하고, 그 vertex를 방문했음으로 변경
		TV[++n] = min.vertex2;
		visited[min.vertex2] = 1;

		//찾은 minimum cost edge를 출력
		printf("(%d,%d) ", min.vertex1, min.vertex2);
		count++;
	}

	printf("}\n");
	//TV의 원소 출력
	printf("TV = { ");
	for (i = 0; i < MAX_VERTICES; i++)
		printf("%d ", TV[i]);
	printf("}\n");

	//count가 6(즉 n-1)이 아니면 spanning tree가 아니다.
	if (count != MAX_VERTICES - 1)
		printf("no spanning tree\n");
}//Prim