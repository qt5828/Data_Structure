#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일(수정일) : 2020.10.02
프로그램 기능 : 임의의 값을 입력받아, 주어진 tree의 node와 비교하여 
			   입력받은 값보다 tree node의 값이 더 작으면, 작은 node값을
			   모두 출력하는 프로그램.
*/
#include <stdio.h>

//tree를 구성하는 노드구조체
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild;
	treePointer rightChild;
}node;

//tree 노드 값이 입력받은 값보다 작은 값이 있는지 확인하기 위한 변수
int empty;

//함수선언
void preorder(treePointer ptr, int num);

void main()
{
	//트리의 노드에 넣을 값을 저장할 data배열
	int data[13] = { 8,4,9,2,5,10,13,21,3,6,17,25,15 };
	//tree를 표현할 배열
	node root[14];

	//입력받을 값
	int num;
	//프로그램을 계속할지를 결정하는 변수
	char ans[2] = "y";

	//tree노드에 각각의 값을 할당
	//노드의 leftChild와 rightChild는 NULL로 설정
	for (int i = 1; i < 14; i++)
	{
		root[i].data = data[i - 1];
		root[i].leftChild = NULL;
		root[i].rightChild = NULL;
	}

	//각각의 노드의 leftChild,rightChild가 가리키는 곳을 할당
	for (int i = 1; i < 14; i++)
	{
		if (i % 2 == 0)
			root[i / 2].leftChild = &root[i];
		else
			root[i / 2].rightChild = &root[i];
	}

	//ans의 값을 'n'로 입력받을때까지 반복
	for (;;)
	{
		num = 0;
		printf("\n값을 입력하시오 : ");
		scanf("%d", &num);

		//empty를 매번 0으로 초기화
		empty = 0;
		preorder(&root[1], num);

		//하나라도 트리노드의 값이 입력받은 수보다 작으면 empty는 1이 됨
		if (empty == 0)
			printf("입력한 %d보다 작은 값을 갖는 노드는 없습니다.\n", num);

		printf("\n계속 하시겠습니까?(y/n) : ");
		scanf("%s", ans);
		//'n'을 입력받으면 프로그램 종료
		if (ans[0] == 'n')
			break;
		//'n'과 'y'외의 문자를 입력받아도 프로그램을 종료함
		else if (ans[0] != 'n' && ans[0] != 'y')
		{
			printf("잘못된 문자를 입력했습니다. 프로그램을 종료합니다.\n");
			return;
		}
	}

}

//preorder traversal의 방법으로 트리노드를 탐색하며, 입력받은 수보다 작은 노드값이
//발견되면 그 값을 출력하고 empty를 1로 바꾸는 함수이다.
void preorder(treePointer ptr, int num)
{
	if (ptr) {
		if (num > ptr->data) 
		{
			printf("\n%d보다 작은 노드 : %d", num, ptr->data);
			empty = 1;
		}
		preorder(ptr->leftChild, num);
		preorder(ptr->rightChild, num);
	}
	return;
}//preorder
