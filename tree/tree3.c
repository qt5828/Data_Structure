#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일(수정일) : 2020.10.01
프로그램 기능 : 4주차실습과제3번 문제에 주어진 binary tree형태의 폴더구조에서 C:\폴더와
			   D:\폴더의 전체용량과 "내컴퓨터"의 전체용량을 계산하는 프로그램
			   linked list와 binary traversal방법을 이용한다.
*/
#include <stdio.h>

//폴더의 용량을 저장할 sum
int sum;

//tree를 구성하는 노드구조체
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}node;

//함수선언
void inorder(treePointer ptr);

void main()
{
	//폴더구조의 각각의 용량을 data배열의 값으로 초기화
	int data[15] = { 0,0,10,2,15,40,70,100,150,0,0,10,20,50,150 };
	//tree를 표현할 배열
	node root[16];

	//tree 노드에 각각의 값을 할당
	//노드의 leftChild와 rightChild는 NULL로 설정한다.
	for (int i = 1; i < 16; i++)
	{
		root[i].data = data[i - 1];
		root[i].leftChild = NULL;
		root[i].rightChild = NULL;
	}

	//각각의 노드의 leftChild와 rightChild가 가리키는 곳을 할당
	for (int i = 2; i < 16; i++)
	{
		if (i % 2 == 0)
			root[i / 2].leftChild = &root[i];
		else
			root[i / 2].rightChild = &root[i];
	}

	//C:의 용량을 계산
	printf("C:의 용량 : ");
	sum = 0;
	//C:부분의 subtree의 첫번째 주솟값을 inorder함수에 주어서 C: subtree의 폴더용량의 합을 구한다.
	//inorder traversal의 방법으로 subtree의 노드값에 접근하여 각 용량의 합을 계산한다.
	inorder(&root[2]);
	printf("%dM입니다.\n", sum);

	//D:부분의 subtree의 첫번째 주솟값을 inorder함수에 주어서 D: subtree의 폴더용량의 합을 구한다.
	//inorder traversal의 방법으로 subtree의 노드값에 접근하여 각 용량의 합을 계산한다.
	printf("D:의 용량 : ");
	sum = 0;
	inorder(&root[3]);
	printf("%dM입니다.\n", sum);

	//전체tree(root)의 첫번째 주솟값을 inorder함수에 주어서 전체폴더의 용량의 합을 구한다.
	//inorder traversal의 방법으로 subtree의 노드값에 접근하여 각 용량의 합을 계산한다.
	printf("내컴퓨터의 전체용량 : ");
	sum = 0;
	inorder(&root[1]);
	printf("%dM입니다.\n", sum);

}//main

//inorder traversal의 방법으로 주어진 주솟값을 기준으로 (sub)tree의 노드의 값의 합을 구하는 함수
void inorder(treePointer ptr)
{
	if (ptr) {
		inorder(ptr->leftChild);
		sum += ptr->data;
		inorder(ptr->rightChild);
	}
	return;
}//inorder
