#define _CRT_SECURE_NO_WARNINGS
/* 
작성자 : 조우연
작성일(수정일) : 2020.10.30
프로그램 기능 : 문제에 주어진 adjacency list로 표현된 undirected graph를 BFS로
			   traversal한 결과를 출력하는 프로그램.
*/
#include <stdio.h>

typedef struct node* queuePointer;
typedef struct node {
	char vertex;
	queuePointer link;
}node;
//adjacency list의 최대 노드 수 : 7개
//노드를 방문했는지 확인하기 위한 배열
short int visited[7];
//그래프를 표현
queuePointer graph[7];
int front, rear;
//char형 queue
char queue[7];

//함수선언
void creat(queuePointer* root, char val);
void bfs(int v);
void addq(char item);
char deleteq();
int queueFull();
int queueEmpty();

void main()
{
	//adjacency list를 바탕으로 그래프 생성
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

	//BTS방법으로 순회
	printf("Breadth First Search의 결과 : ");
	bfs('A');
	printf("\n");
}//main


//BFS방법으로 그래프를 순회하여 각 노드를 출력하는 함수
void bfs(int v)
{
	queuePointer w;
	front = rear = -1;

	//알파벳 순서대로 그래프에 노드가 추가되어있으므로,
	//알파벳에 따라 알맞은 인덱스번호를 부여하기 위한 스위치문
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

	//방문한 노드는 1로 변경
	visited[n] = 1;
	//큐에 방문한 노드의 값(알파벳)추가
	addq(v);
	//큐가 빌때까지 반복
	while (!queueEmpty()) {
		//방문할 adjacency list의 노드를 큐에서 삭제하고 삭제할 노드의 모든 노드들을 출력
		v = deleteq();
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
		w = graph[n];
		//삭제한 노드와 adjacent한 노드들을 모두 출력
		for (w; w; w = w->link)
			if (!visited[w->vertex]) {
				printf("%c ", w->vertex);
				addq(w->vertex);
				visited[w->vertex] = 1;
			}
	}
}//bfs

//큐의 끝에 값을 추가하는 함수(큐의 원소는 char형이다)
void addq(char item)
{
	if (rear == 6)
		queueFull();
	queue[++rear] = item;
}//addq

//큐에 맨 처음값을 삭제하고 그 값을 반환하는 함수
char deleteq()
{
	if (front == rear)
		return queueEmpty();
	return queue[++front];
}//deleteq

//큐가 꽉찼는지 확인하는 함수
//꽉찼으면 1 아니면 0 반환
int queueFull()
{
	if ((front - rear == 1) || (rear - front == 6))
		return 1;
	else
		return 0;
}//queueFull

//큐가 비었는지 확인하는 함수
//비었으면 1 아니면 0 반환
int queueEmpty()
{
	if (front == rear) {
		return 1;
	}
	return 0;
}//queueEmpty

//그래프를 만드는 함수
//adjacency list형태의 그래프로 만든다.
void creat(queuePointer* root, char val)
{
	//graph[i]가 null일때(생성)
	if (!(*root))
	{
		(*root) = (queuePointer)malloc(sizeof(node));
		(*root)->vertex = val;
		(*root)->link = NULL;
	}
	//graph[i]에 값이 있을때(추가)
	else
	{
		queuePointer ptr;
		ptr = (queuePointer)malloc(sizeof(node));
		ptr->vertex = val; ptr->link = NULL;

		queuePointer temp;
		for (temp = *root; temp->link;)
			temp = temp->link;
		temp->link = ptr;
	}
}//creat