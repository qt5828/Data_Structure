#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일(수정일) : 2020.09.29
프로그램 기능 : 4주차실습과제2번 문제에 주어진 binary tree를 level order traversal을
			   실행하고, 실행결과를 출력하는 프로그램. linked list와 circular queue를 사용한다.
*/
#include <stdio.h>

//tree를 구성하는 노드구조체
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}node;

//node 타입의 queue, 최대길이 20
node queue[20];
int front = 0, rear = 0;

//함수선언
void levelOrder(treePointer ptr);
void addq(int item);
int deleteq();
int queueFull();
int queueEmpty();
void main()
{
	//트리노드에 할당할 값을 저장한 data배열
	int data[13] = { 8, 4, 9, 2, 5, 10, 13, 1, 3, 6, 7, 11, 12 };
	node root[14];

	//tree노드에 각각의 값을 할당
	//노드의 leftChild와 rightChild는 NULL로 설정한다.
	for (int i = 1; i < 14; i++)
	{
		root[i].data = data[i - 1];
		root[i].leftChild = NULL;
		root[i].rightChild = NULL;
	}

	//각각의 노드의 leftChild와 rightChild가 가리키는 곳을 할당
	for (int i = 1; i < 14; i++)
	{
		if (i % 2 == 0)
			root[i / 2].leftChild = &root[i];
		else
			root[i / 2].rightChild = &root[i];
	}

	//level order traversal의 방법으로 tree의 노드값에 접근해 각 노드의 값을 출력
	printf("Level order traversal의 결과 : ");
	levelOrder(&root[1]);

}//main

//level order traversal의 방법으로 tree의 노드값에 접근해 각 노드의 값을 출력하는 함수
//큐를 이용한다.
void levelOrder(treePointer ptr)
{
	if (!ptr)
		return;
	addq(ptr);

	for (;;) {
		ptr = deleteq();
		if (ptr) {
			printf("%d ", ptr->data);
			if (ptr->leftChild)
				addq(ptr->leftChild);
			if (ptr->rightChild)
				addq(ptr->rightChild);
		}
		else
			break;
	}
}//levelOrder

//큐의 끝에 값을 추가하는 함수
void addq(int item)
{
	rear = (rear + 1) % 20;
	if (front == rear)
		queueFull(rear);
	queue[rear].data = item;
}//addq

//큐에 가장 앞의 값을 삭제하고 그 값을 반환하는 함수
int deleteq()
{
	if (front == rear)
		return queueEmpty();
	front = (front + 1) % 20;
	return queue[front].data;
}//deleteq

//큐가 꽉찼는지 확인하는 함수
int queueFull()
{
	if ((front - rear == 1) || (rear - front == 6))
		printf("queue가 꽉 찼습니다.\n");
	else
		return 1;
}//queueFull

//큐가 비었는지 확인하는 함수
int queueEmpty()
{
	if (front == rear) {
		printf("\n");
		return 0;
	}
	return 1;
}//queueEmpty
