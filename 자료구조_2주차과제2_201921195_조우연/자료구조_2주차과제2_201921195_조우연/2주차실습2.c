#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일(수정일) : 2020.09.18
프로그램 기능 : 병원에서 진료대기환자를 관리하는 프로그램
				'병원도착','병원퇴장','서비스종료'
				사용자가 위 세 서비스 중 하나를 선택하면, '병원도착'을 선택시 사용자가
				원하면 대기자 등록을 해주고, '병원퇴장'을 선택시 대기자 중 진료가 가능해진
				환자의 이름을 출력하고, '서비스종료'를 선택시 프로그램을 종료하는 프로그램이다.
				단 대기자의 수는 6명으로 제한된다.
*/
#include <stdio.h>

//환자의 이름정보를 저장하는 구조체
typedef struct {
	char name[10]; //이름최대길이 9
} patient;

//대기자명단을 저장할 queue, circular queue형태로 사용할 것임
patient queue[7];

int front = 0; rear = 0;

void addq(patient item);
patient deleteq();
int queueFull();
int queueEmpty();
void main()
{
	int answer;
	printf("\n입력대기\n");
	printf("1. 병원 도착\n2. 병원 퇴장\n3. 서비스 종료\n");
	scanf("%d", &answer);

	//사용자가 '서비스종료'(3)를 선택할때까지 실행
	while (answer != 3) {
		//병원도착 선택
		if (answer == 1)
		{
			//대기자목록이 꽉차지 않았을 때 실행
			if (queueFull() == 1) {
				int ans1;
				printf("\n1. 대기자 등록\n2. 취소\n");
				scanf("%d", &ans1);
				//사용자가 대기자 등록을 원할때 실행
				if (ans1 == 1)
				{
					patient person;
					printf("이름 입력 : ");
					scanf("%s", person.name);
					addq(person);
				}
			}
		}
		//병원퇴장 선택
		else if (answer == 2)
		{
			//대기중인 환자가 있다면 실행
			if(queueEmpty())
				printf("환자 : %s\n\n", deleteq().name);
		}
		//'병원도착','병원퇴장','서비스종료'가 아닌 다른 수를 입력했을 때의 예외처리
		else
		{
			printf("잘못된 값을 입력하였습니다. 1,2,3중에 입력하세요.\n");
		}
		printf("\n입력대기\n");
		printf("1. 병원 도착\n2. 병원 퇴장\n3. 서비스 종료\n");
		scanf("%d", &answer);
	}
	printf("\n서비스를 종료합니다.\n");
}

//큐에 값(대기자명단)을 삽입하는 함수
void addq(patient item)
{
	rear = (rear + 1) % 7;
	queue[rear] = item;
}

//큐에 입력된 순서대로 값을 반환하고 삭제하는 함수
patient deleteq()
{
	if (front == rear)
		queueEmpty();
	front = (front + 1) % 7;
	return queue[front];
}

//큐가 꽉차있을때, 대기자명단이 꽉찼음을 알리는 문구를 출력하는 함수
int queueFull()
{
	if ((front - rear == 1) || (rear - front == 6))
		printf("Service is not availanle\n");
	else
		return 1;
}

//큐가 비어있을 때, 대기자가 없음을 알리는 문구를 출력하는 함수
int queueEmpty()
{
	if (front == rear) {
		printf("There is no patient waiting\n");
		return 0;
	}
	return 1;
}


