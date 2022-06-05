#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일 : 2020.11.15
프로그램 기능 : Sollin의 algorithm을 이용하여 실습지에 주어진 graph의 minimum cost spanning tree를
			   생성하고 출력하는 프로그램
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
//집합의 root찾기 위한 parent
int parent[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };

//edge의 정보에 대한 구조체
typedef struct edge {
	int vertex1;
	int vertex2;
	int cost;
}edge;

//함수선언
void Sollin();
void Union(int i, int j);
int Find(int i);

void main()
{
	printf("Sollin's algorithm을 이용한 minimum cost spanning tree 생성 : \n");
	Sollin();
}//main



//Sollin's algorithm을 이용하여 minimum cost spanning tree를 생성하여 출력하는 함수.
void Sollin()
{
	int i, j, k, n = 0, TF;
	int count = 0;
	int visited[MAX_VERTICES] = { 0 };
	edge T[MAX_VERTICES - 1];
	edge min;

	//edge들의 집합 T의 원소들의 cost를 1000으로 설정
	//원소의 개수를 세기 위함
	for (i = 0; i < MAX_VERTICES - 1; i++)
		T[i].cost = 1000;

	//first stage
	while (i < MAX_VERTICES)
	{
		for (i = 0; i < MAX_VERTICES; i++)
		{
			TF = 1;
			min.cost = INT_MAX;
			visited[i] = 1; //방문한 vertex는 visited 1로 변경
			for (j = 0; j < MAX_VERTICES; j++)
			{
				//각 vertex에 대한 minimum cost를 가지는 edge찾기
				if (min.cost > cost[i][j])
				{
					min.cost = cost[i][j];
					min.vertex1 = i;
					min.vertex2 = j;
				}
			}

			//위에서 찾은 minimum cost를 가진 edge중 중복되는것은 제외시킴
			for (k = 0; k < 6; k++)
			{
				if (T[k].vertex1 == min.vertex2)
					if (T[k].vertex2 == min.vertex1)
						TF = 0;
			}
			//각 vertex에 대한 minimum cost를 가지는 edge들을 집합 T에 저장한다.
			if (TF) {
				T[n++] = min;
				count++;
			}
		}
	}

	printf("T = {");
	//first stage에서 찾은 minimum cost spanning subtree의 edge들을 출력
	for (j = 0; j < count; j++)
	{
		printf("(%d,%d) ", T[j].vertex1, T[j].vertex2);
		Union(T[j].vertex1, T[j].vertex2);
	}

	//second stage
	edge forest[MAX_VERTICES][MAX_VERTICES]; //forest들을 저장
	edge forest2[MAX_VERTICES][MAX_VERTICES]; //forest들을 더 깔끔하게 저장(위 forest는 중간중간 쓰레기값이 들어있는 원소들이 들어있음)
	edge MINT; //cost의 최솟값을 가진 edge저장
	int MIN = INT_MAX;
	int a, b, c, d, e, f, g;
	a = b = c = d = e = f = g = 0;

	//forest와 forest2의 모든 원소들의 cost들을 1000으로 설정
	for (i = 0; i < MAX_VERTICES; i++)
	{
		for (j = 0; j < MAX_VERTICES; j++) {
			forest[i][j].cost = 1000;
			forest2[i][j].cost = 1000;
		}
	}

	//같은 집합에 있는 edge들을 찾아 각각의 위치에 저장
	//ex) 0을 root로 하는 vertex가 들어있는 edge들은 forest[0]에 저장,
	//ex) 1을 root로 하는 vertex가 들어있는 edge들은 forest[1]에 저장
	for (i = 0; T[i].cost != 1000; i++) {
		switch (Find(T[i].vertex1))
		{
		case 0:
			forest[0][a++] = T[i];
			break;
		case 1:
			forest[1][b++] = T[i];
			break;
		case 2:
			forest[2][c++] = T[i];
			break;
		case 3:
			forest[3][d++] = T[i];
			break;
		case 4:
			forest[4][e++] = T[i];
			break;
		case 5:
			forest[5][f++] = T[i];
			break;
		case 6:
			forest[6][g++] = T[i];
			break;
		}
	}

	//forest[0]~forest[6]까지 중 비어있는 곳을 버리고 실제 edge가 들어있는 곳만
	//forest2[0]부터 차례대로 저장(forest를 forest2에 깔끔하게 정리)
	k = 0;
	for (i = 0; i < MAX_VERTICES; i++) {
		if (forest[i][0].cost != 1000) { //forest[i][0].cost가 1000이면 그 곳은 비어있음
			for (j = 0; forest[i][j].cost != 1000; j++) {
				forest2[k][j] = forest[i][j];
			}
			k++;
		}
	}

	//각 forest2[i]에는 minimum cost spaaning subtree를 이루는 edge들이 들어있으므로,
	//각 forest의 vertex들 사이의 cost를 비교해 가장 작은 값을 가지는 edge를 MINT에 저장
	for (i = 0; forest2[0][i].cost != 1000; i++) {
		for (j = 0; forest2[1][j].cost != 1000; j++)
			if (MIN > cost[forest2[0][i].vertex1][forest2[1][j].vertex1]) {
				MIN = cost[forest2[0][i].vertex1][forest2[1][j].vertex1];
				MINT.vertex1 = forest2[0][i].vertex1;
				MINT.vertex2 = forest2[1][j].vertex1;
				MINT.cost = MIN;
			}
	}
	//이미 만들어진 subtree의 edge들을 제외하고 남은 edge중 가장 작은 cost를 가진 edge를 찾아서 MINT에 저장했으므로,
	//MINT를 통해 두 subtree를 연결해주면 minimum cost spanning tree생성
	printf("(%d,%d)}\n ", MINT.vertex1, MINT.vertex2);

}//Sollin

//i의 root를 j로 만드는 함수
void Union(int i, int j)
{
	//i의 root를 j로 만듦
	parent[i] = j;
}//Union

//i의 root를 찾는 함수
int Find(int i)
{
	for (; parent[i] >= 0; i = parent[i]);
	return i;
}//Find
