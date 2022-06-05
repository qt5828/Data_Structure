#define _CRT_SECURE_NO_WARNINGS
/*
작성자 :  조우연
작성일(수정일) :  2020.09.26
프로그램 기능 : 사용자가 "추가","삭제","출력","역순 출력","종료"중 하나를 선택하고,
			   선택된 것에 따라 리스트에 값을 입력받거나, 삭제하거나, 리스트의 값을
			   출력하거나 역순으로 출력하는 실행을 한다. "종료"가 선택될때까지 프로그램은
			   종료되지 않는다. 리스트에 값을 입력받을 때에는, 리스트의 값이 큰 순서대로
			   정렬되도록 값을 삽입한다. 상황에따라 리스트가 비어있거나, 중복된 값에 대해서는
			   에러메세지를 출력한다.
*/

#include <stdio.h>
#include <stdlib.h>

//리스트의 <데이터,링크>쌍의 노드를 나타내는 구조체
typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

//함수선언
ListNode* addNode(ListNode* head);
ListNode* delete(ListNode* head, int del);
void print(ListNode* head);
ListNode* reverse(ListNode* head);

void main()
{
	int choice;
	ListNode* head = NULL;

	head = (ListNode*)malloc(sizeof(ListNode));

	printf("1: 추가, 2: 삭제, 3: 출력, 4: 역순 출력, 5: 종료\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		head->link = NULL;
		printf("\"입력\"");
		scanf("%d", &head->data);
		printf("성공했습니다\n");
	}
	else if (choice == 2)
	{
		printf("\"삭제\"");
		printf("list가 비어 있습니다.\n");
		head = NULL;
	}
	else if (choice == 3)
	{
		printf("\"출력\"");
		printf("list가 비어 있습니다.\n");
		head = NULL;
	}
	else if (choice == 4)
	{
		printf("\"역순 출력\"");
		printf("list가 비어 있습니다.\n");
		head = NULL;
	}
	else if (choice == 5)
		return;

	while (1)
	{
		printf("1: 추가, 2: 삭제, 3: 출력, 4: 역순 출력, 5: 종료\n");
		scanf("%d", &choice);
		//"추가"선택시
		if (choice == 1)
		{
			printf("\"입력\"  ");
			//리스트가 비어있으면 head를 새로 생성
			if (head == NULL)
			{
				head = (ListNode*)malloc(sizeof(ListNode));
				head->link = NULL;
				scanf("%d", &head->data);
				printf("성공했습니다\n");
				continue;
			}
			//리스트에 다른 값이 있으면 값을 삽입
			head = addNode(head);
		}
		//"삭제"선택시
		else if (choice == 2)
		{
			printf("\"삭제\"  ");
			//리스트가 비어있을때 에러출력
			if (head == NULL)
			{
				printf("list가 비어 있습니다\n");
				continue;
			}
			int del; //삭제할 값
			scanf("%d", &del);
			head = delete(head, del);
		}
		//"출력"선택시
		else if (choice == 3)
		{
			printf("\"출력\"  ");
			//리스트가 비어있을때 에러출력
			if (head == NULL)
			{
				printf("list가 비어 있습니다\n");
				continue;
			}
			print(head);
		}
		//"역순출력"선택시
		else if (choice == 4)
		{
			printf("\"역순 출력\"  ");
			//리스트가 비어있을때 에러출력
			if (head == NULL)
			{
				printf("list가 비어 있습니다\n");
				continue;
			}
			//리스트를 역순으로 만든 후 출력
			head = reverse(head);
			print(head);
			//역순 출력 후, 다시 역순으로 만듦(원래 리스트로 되돌림)
			head = reverse(head);
		}
		//"종료"선택시 프로그램 종료
		else if (choice == 5)
		{
			printf("\"종료\"");
			break;
		}
	}

	return;

}//main

//삽입할 값을 입력받아 리스트의 내림차순으로 값을 삽입하는 함수
ListNode* addNode(ListNode* head)
{
	ListNode* p;
	p = (ListNode*)malloc(sizeof(ListNode));

	//새로 삽입할 리스트의 값
	scanf("%d", &p->data);

	ListNode* temp;
	temp = head; //temp에 head복사

	//입력받은 값이 가장 크면 리스트의 맨 앞에 값을 삽입
	if (p->data > head->data)
	{
		p->link = head;
		head = p;
		printf("성공했습니다\n");
		return head;
	}

	//내림차순으로 입력받은 값을 삽입
	while (temp->data > p->data)
	{
		//입력받은 값이 가장 작으면 리스트의 맨뒤에 삽입
		if (temp->link == NULL)
		{
			p->link = NULL;
			temp->link = p;
			printf("성공했습니다\n");
			return head;
		}
		else {
			//입력받은 값을 넣을 위치찾기
			if ((temp->link->data) > p->data)
				temp = temp->link;
			//리스트안에 입력받은 값과 같은 값이 존재하면 중복되었다는 에러메세지 출력
			else if ((temp->link->data) == p->data)
			{
				printf("중복된 데이터입니다\n");
				return head;
			}
			//내림차순으로 입력받은 값을 삽입할 위치를 찾았을 때, break
			else
				break;
		}
	}
	//리스트의 마지막값이 입력받은 값과 같을때, 중복됨을 알리는 에러메세지 출력
	if (temp->data == p->data)
	{
		printf("중복된 데이터입니다\n");
		return head;
	}

	//입력받은 값 삽입
	p->link = temp->link;
	temp->link = p;
	printf("성공했습니다\n");
	return head;

}//addNode

//입력받은 값을 리스트에서 삭제하는 함수
ListNode* delete(ListNode* head, int del)
{
	ListNode* removed;

	//맨앞 값을 삭제할 시
	if (head->data == del)
	{
		removed = head;
		head = removed->link;
		free(removed);
		printf("성공했습니다\n");
		return head;
	}

	//삭제할 값을 리스트에서 찾는 코드
	for (ListNode* p = head; p->link != NULL; p = p->link)
	{
		//삭제할 값을 찾으면 해당 값을 삭제
		if (p->link->data == del)
		{
			removed = p->link;
			p->link = removed->link;
			free(removed);
			printf("성공했습니다\n");
			return head;
		}
	}
	//삭제할 값을 리스트에서 찾지못하면 에러메세지 출력
	printf("찾는 값이 없습니다.\n");
	return head;

}//delete


//리스트에 있는 모든 값을 출력하는 함수
void print(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d ", p->data);
	printf("\n");
}//print

//리스트의 값을 역순으로 변환하는 함수
ListNode* reverse(ListNode* head)
{
	ListNode* p, * q, * r;
	p = head;
	q = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}//reverse