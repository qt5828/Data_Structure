#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일(수정일) : 2020.10.03
프로그램 기능 : 5주차실습 2번문제에 주어진 binary tree를 threaded binary tree로 구현하여
			   inorder traversal을 실행한 결과를 출력하는 프로그램. linked list를 사용하며
			   Inorder successor를 찾는 insucc()함수와 threaded binary tree에서 inorder traversal을
			   하는 함수 tiorder()를 구현하여 처리한다.
*/
#include <stdio.h>
#include <stdlib.h>

//threaded binary tree를 구성하는 노드구조체
typedef struct node* threadedPointer;
typedef struct node {
	int data;
	threadedPointer leftChild;
	threadedPointer rightChild;
	short int leftThread;
	short int rightThread;
}node;


//함수선언
threadedPointer insucc(threadedPointer tree);
void tinorder(threadedPointer tree);

void main()
{
	//트리의 노드에 넣을 값을 저장할 data배열
	int data[13] = { 8,4,9,2,5,10,13,21,3,6,17,25,15 };
	//트리의 노드의 각각 leftThread, rightThread에 넣을값을 저장한 배열들
	short int Lthread[13] = { 0,0,0,0,0,0,1,1,1,1,1,1,1 };
	short int Rthread[13] = { 0,0,0,0,0,0,1,1,1,1,1,1,1 };
	//tree를 표현할 배열
	node tree[14];

	//tree노드에 각각의 값을 할당
	//노드의 leftChild와 rightChild는 NULL로 설정
	for (int i = 1; i < 14; i++)
	{
		tree[i].data = data[i - 1];
		tree[i].leftChild = NULL;
		tree[i].rightChild = NULL;
		tree[i].leftThread = Lthread[i - 1];
		tree[i].rightThread = Rthread[i - 1];
	}
	//각각의 노드의 leftChild,rightChild가 가리키는 곳을 할당
	for (int i = 1; i < 14; i++)
	{
		if (i % 2 == 0)
			tree[i / 2].leftChild = &tree[i];
		else
			tree[i / 2].rightChild = &tree[i];
	}

	//root노드의 정의
	tree[0].leftChild = &tree[1];
	tree[0].rightChild = NULL;
	tree[0].leftThread = 0;
	tree[0].rightThread = 0;

	//rightThread가 true인 노드에 rightChild를 Thread로 줌.
	tree[8].rightChild = &tree[4];
	tree[9].rightChild = &tree[2];
	tree[10].rightChild = &tree[5];
	tree[11].rightChild = &tree[1];
	tree[12].rightChild = &tree[6];
	tree[13].rightChild = &tree[3];

	//inorder traversal한 결과를 출력
	printf("Inorder traversal of a threaded binary tree : ");
	tinorder(&tree[0]);

}//main

//threaded binary tree에서 inorder successor를 찾는 함수
threadedPointer insucc(threadedPointer tree)
{
	threadedPointer temp;
	temp = tree->rightChild;
	//temp가 NULL이 아니고, 트리의 rightThread가 0이 아니면 실행
	if (temp!=NULL && !tree->rightThread)
	{
		//왼쪽끝까지감
		while (!temp->leftThread)
			temp = temp->leftChild;
	}

	return temp;
}//insucc

//threaded binary tree를 inorder방법으로 탐색해 출력하는 함수
void tinorder(threadedPointer tree)
{
	threadedPointer temp = tree;
	//왼쪽 끝으로 이동
	while (temp->leftChild)
		temp = temp->leftChild;
	for (;;)
	{
		printf("%d ", temp->data);
		//temp의 successor를 찾아서 temp에 저장
		temp = insucc(temp);
		//temp가 NULL이면 실행종료
		if (temp == NULL)
		{
			printf("\n");
			break;
		}
	}
}//tinorder
