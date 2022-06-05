#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일(수정일) : 2020.09.29
프로그램 기능 : 4주차실습과제1번 문제에 주어진 binary tree를 inorder traversal,
			   preorder traversal, postorder traversal을 실행하여 각각의 결과를
			   출력하는 프로그램. linked list를 사용해 구현한다.
*/
#include <stdio.h>

//tree를 구성하는 노드구조체
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}node;

//함수선언
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

void main()
{
	//트리의 노드에 넣을 값을 저장한 data배열
	int data[13] = { 8, 4, 9, 2, 5, 10, 13, 1, 3, 6, 7, 11, 12 }; 
	//tree를 표현할 배열
	node root[14];

	//tree노드에 각각의 값을 할당
	//노드의 leftChild와 rightChild는 NULL로 설정한다.
	for (int i = 1; i < 14; i++)
	{
		root[i].data = data[i - 1];
		root[i].leftChild = NULL;
		root[i].rightChild = NULL;
	}

	//각각의 노드의 leftChild, rightChild가 가리키는 곳을 할당
	for (int i = 1; i < 14; i++)
	{
		if (i % 2 == 0)
			root[i / 2].leftChild = &root[i];
		else
			root[i / 2].rightChild = &root[i];
	}

	//inorder traversal의 방법으로 tree의 노드값을 출력
	printf("Inorder traversal의 결과 : ");
	inorder(&root[1]);
	printf("\n");

	//preorder traversal의 방법으로 tree의 노드값을 출력
	printf("Preorder traversal의 결과 : ");
	preorder(&root[1]);
	printf("\n");

	//postorder traversal의 방법으로 tree의 노드값을 출력
	printf("Postorder traversal의 결과 : ");
	postorder(&root[1]);
	printf("\n");
}//main

//inorder traversal의 방법으로 tree노드의 값을 출력하는 함수
void inorder(treePointer ptr)
{
	if (ptr) {
		inorder(ptr->leftChild);
		printf("%d ", ptr->data);
		inorder(ptr->rightChild);
	}
	return;
}//inorder

//preorder traversal의 방법으로 tree노드의 값을 출력하는 함수
void preorder(treePointer ptr)
{
	if (ptr) {
		printf("%d ", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
	return;
}//preorder

//postorder traversal의 방법으로 tree노드의 값을 출력하는 함수
void postorder(treePointer ptr)
{
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%d ", ptr->data);
	}
	return;
}//postorder
