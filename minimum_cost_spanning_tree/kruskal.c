#define _CRT_SECURE_NO_WARNINGS
/*
작성자 :  조우연
작성일 :  2020.10.31
프로그램 기능 : 9주차실습과제문제에 주어진 graph에 대해 minimum cost spanning tree
			   를 생성하는 프로그램. Kruskal's algorithm을 사용한다.
*/
#include <stdio.h>

#define MAX_SIZE 12 //총 edge의 수+1
#define HEAP_FULL(n) (n==MAX_SIZE-1)
#define HEAP_EMPTY(n) (!n)

//각 원소가 연결되기 전에는 모두 root이므로 -1로 초기화
int parent[8] = { -1,-1,-1,-1,-1,-1,-1,-1};

//edge의 정보에 대한 구조체
typedef struct edge {
	int vertex1;
	int vertex2;
	int cost;
}edge;

edge heap[MAX_SIZE];
int n = 0; //heap크기

//함수선언
int Kruskal();
void push(int ver1, int ver2, int cost);
edge pop();
void Union(int i, int j);
int Find(int i);
int check(int i, int j);

void main()
{
	printf("\nKruska's algorithm을 이용한 minimum cost spanning tree 생성 :  T = { ");
	Kruskal();
	printf("}\n\n");
}//main

//Kruskal의 algorithm방법으로 Minimum cost spanning tree를 생성하는 함수
int Kruskal()
{
	//각 edge에 대한 정보를 minheap에 저장한다. (cost를 기준으로)
	push(0, 1, 3);
	push(0, 3, 6);
	push(0, 2, 17);
	push(1, 3, 5);
	push(1, 6, 12);
	push(2, 4, 10);
	push(2, 5, 8);
	push(3, 4, 9);
	push(4, 5, 4);
	push(4, 6, 2);
	push(5, 6, 14);

	//추가할 edge의 개수를 세는 count
	int count = 0;
	edge e;
	while (count < 6)
	{
		//cost가 최소인 edge를 minheap에서 삭제하고 e에 저장
		e = pop();
		int n1, n2;
		//e의 두 점이 같은 set에 속해있는지 확인
		//즉 cycle을 이루는지 확인

		if (!check(e.vertex1, e.vertex2))
		{
			//edge를 출력
			printf("(%d,%d) ", e.vertex1, e.vertex2);
			count++;
			//두 점을 union한다.->두점이 같은 set안에 있게됨
			Union(e.vertex1, e.vertex2);
		}
	}

	//count가 6(즉 n-1)이 아니면 spanning tree가 아니다.
	if (count != 6)
		printf("no spanning tree\n");
}//Kruskal

//edge에 대한 정보(점1, 점2, 비용)을 이용해 minheap에 edge를 추가(cost를 기준으로 추가함)
void push(int ver1, int ver2, int cost)
{
	edge Edge;
	Edge.vertex1 = ver1;
	Edge.vertex2 = ver2;
	Edge.cost = cost;
	int i;
	if (HEAP_FULL(n)) {
		fprintf(stderr, "The heap is full. ");
		exit(1);
	}
	i = ++(n);
	while ((i != 1) && (Edge.cost < heap[i / 2].cost)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = Edge;
}//push

//minheap에서 cost가 최소인 노드(즉 root)를 삭제 후 그 값을 반환
edge pop()
{
	int parent, child;
	edge item, temp;
	if (HEAP_EMPTY(n)) {
		fprintf(stderr, "The heap is empty ");
		exit(2);
	}
	item = heap[1];
	temp = heap[(n)--];
	parent = 1;
	child = 2;

	while (child <= n)
	{
		if ((child < n) && heap[child].cost > heap[child + 1].cost)
			child++;
		if (temp.cost <= heap[child].cost)
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}//pop

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

//두 수 i,j가 같은 집합에 포함되어있는지를 판단하고 이에 대한 판단결과를 출력하는 함수
//같은 집합에 있으면 1, 아니면 0 반환
int check(int i, int j)
{
	//i와 j의 root가 같으면 실행
	if (Find(i) == Find(j))
		return 1;
	//i와 j의 root가 다르면 실행
	else
		return 0;
}//check