#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일(수정일) : 2020.10.11
프로그램 기능 : 1부터 15까지의 15개 값을 각각 개별 노드로 하여, 6주차과제 3번문제에 주어진
			   대로 union을 실행하고, union연산이 끝난 후의 현재 모든 노드를 출력하고,
			   이후 임의의 두 노드를 입력받아 이들이 같은 집합에 포함되어 있는지 아닌지를 출력하는
			   프로그램. Union-Find를 이용하여 구현한다.
*/
#include <stdio.h>

//0번째 인덱스 사용안할것임(편의를 위해서)
int parent[16] = { 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };

//함수선언
void SimpleUnion(int i, int j);
int SimpleFind(int i);
void check(int i, int j);
void main()
{
	//6주차과제 3번문제에 주어진대로 union 실행
	SimpleUnion(1, 2);
	SimpleUnion(1, 3);
	SimpleUnion(1, 4);
	SimpleUnion(3, 5);
	SimpleUnion(5, 6);
	SimpleUnion(7, 8);
	SimpleUnion(9, 10);
	SimpleUnion(10, 11);
	SimpleUnion(12, 14);
	
	//union실행 후 현재 모든 노드의 root를 출력
	printf("[현재 각 노드의 root를 출력]\n\n");
	int i;
	for (i = 1; i < 16; i++)
		printf("노드 %d의 root는 %d\n", i, SimpleFind(i));

	printf("\n\n");


	//임의의 두 노드를 입력받아 같은 집합에 포함되어 있는 노드인지 확인하고 출력
	printf("[두 노드가 같은 집합에 속하였는지 서로 다른 집합에 속하였는지 여부를 출력]\n\n");
	char ans[2] = "Y";
	//사용자가 'N'를 입력할때까지 반복해서 실행한다.
	while (ans[0] == 'Y')
	{
		int n1, n2;
		printf("두 개 노드 입력(형식: 노드1 노드2) : ");
		scanf("%d %d", &n1, &n2);
		check(n1, n2);
		printf("더 입력하려면 Y, 그만하려면 N을 입력하세요 : ");
		scanf("%s", ans);
		printf("\n");
	}
	printf("프로그램을 종료합니다.\n");

}//main

//i의 root를 j로 만드는 함수
void SimpleUnion(int i, int j)
{
	//i가 root가 아닐 때, i의 root였던 parent의 root도 j로 만듦
	if (parent[i] > 0)
		parent[parent[i]] = j;

	//i의 root를 j로 만듦
	parent[i] = j;
}//SimpleUnion


//i의 root를 찾는 함수
int SimpleFind(int i)
{
	for (; parent[i] >= 0; i = parent[i]);
	return i;
}//SimpleFind


//두 수 i,j가 같은 집합에 포함되어있는지를 판단하고 이에 대한 판단결과를 출력하는 함수
void check(int i, int j)
{
	//i와 j의 root가 같으면 실행
	if (SimpleFind(i) == SimpleFind(j))
		printf("\n노드 %d과 노드 %d는 같은 집합에 속한 노드들입니다.\n\n", i, j);
	//i와 j의 root가 다르면 실행
	else
		printf("\n노드 %d과 노드 %d는 서로 다른 집합의 노드들입니다.\n\n", i, j);
}//check
