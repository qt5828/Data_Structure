#define _CRT_SECURE_NO_WARNINGS
/*
작성자  :  조우연
작성일(수정일) : 2020.09.20
프로그램 기능 : 입력받은 노드의 개수만큼 각 노드의 데이터 값을 입력받고,
			   모든 노드의 값을 비교해 최댓값과 최솟값을 찾아 출력하는 프로그램.
			   단순연결리스트로 구현된다.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element; 

//<데이터,링크>쌍의 노드를 나타내는 구조체
typedef struct ListNode {
	element data; 
	struct ListNode* link; 
}ListNode;

//함수선언
ListNode* addNode(ListNode* head);
void check_node(ListNode* head);
void main()
{
	int num, i;
	printf("노드의 개수를 입력하세요 : ");
	scanf("%d", &num); //입력받을 노트의 수 입력받음

	ListNode* head = NULL;
	ListNode* p;
	head = (ListNode*)malloc(sizeof(ListNode));
	p = (ListNode*)malloc(sizeof(ListNode));
	
	printf("\n노드 1의 데이터 : ");
	scanf("%d", &head->data);
	head->link = NULL;

	//이미 1번째 노드값을 입력받았으므로 2번째~num번째 노드값을 입력받아서
	//리스트 끝에 노드를 삽입
	for (i = 0; i < num - 1; i++)
	{
		printf("\n노드 %d의 데이터 : ", i + 2);
		addNode(head);
	}
	//입력된 노드의 데이터값 중 최댓값과 최솟값 출력
	check_node(head);

}//main

//리스트 끝에 노드를 삽입하는 함수
ListNode* addNode(ListNode* head)
{
	ListNode* p;
	p = (ListNode*)malloc(sizeof(ListNode));

	//새로 생성할 노드의 데이터값을 입력받음
	scanf("%d", &p->data);
	//리스트의 끝에 삽입할 것이므로 새로 생성할 노드의 link는 NULL을 가리킴
	p->link = NULL;

	ListNode* temp;
	temp = head; //temp에 head복사

	//리스트끝에 있는 노드를 찾아 temp에 저장
	while (temp->link != NULL)
		temp = temp->link;
	//temp(리스트의 끝에있는 노드)의 link가 새로 생성한 노드를 가리키게함
	temp->link = p;

}//addNode

//리스트에 있는 각 노드들의 노드데이터값을 비교해 최대,최솟값을 찾고 출력하는 함수
void check_node(ListNode* head)
{
	//max,min을 각각 정수로 표현되는 가장 작은수, 큰수로 초기화
	int max = INT_MIN;
	int min = INT_MAX;

	//리스트의 처음부터 끝까지 노드값을 비교하는 반복문
	for (ListNode* p = head; p != NULL; p = p->link)
	{
		//max보다 노드데이터값이 더 크면 max에 노드데이터값을 저장
		if ((p->data) > max)
			max = p->data;
		//min보다 노드데이터값이 더 작으면 min에 노드데이터값을 저장
		if ((p->data) < min)
			min = p->data;
	}
	//결정된 최대,최솟값 출력
	printf("max = %d, min = %d\n", max, min);

}//check_node