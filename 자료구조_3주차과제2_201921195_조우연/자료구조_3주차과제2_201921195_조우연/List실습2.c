#define _CRT_SECURE_NO_WARNINGS
/*
작성자 :  조우연
작성일(수정일) :  2020.09.27
프로그램 기능 : 임의의 다항식 2개를 키보드로 입력받고 원형리스트를 이용해 저장하고,
			   두 다항식의 차를 연산해 결과를 출력하는 프로그램. 단 다항식의 지수와
			   계수는 모두 정수이다.
*/
#include <stdio.h>
#include <stdlib.h>

//다항식의 계수와 지수정보를 저장하는 구조체
typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
}polyNode;

//함수선언
void attach(float coefficient, int exponent, polyPointer* ptr);
polyPointer diff(polyPointer a, polyPointer b);
int COMPARE(int exp1, int exp2);
polyPointer getInt(char pol[], polyPointer head, int Coef[], int Expon[]);
void print_poly(polyPointer head);
polyPointer addNode(polyPointer head, int coef, int expon);

void main()
{
	//CoefA:다항식A의계수저장, CoefB:다항식B의계수저장, ExponA:다항식A의지수저장, ExponB:다항식B의지수저장
	int CoefA[50], ExponA[50], CoefB[50], ExponB[50];

	//다항식A,B,C such that A-B=C
	polyPointer A=NULL, B=NULL, C=NULL;
	A = (polyPointer)malloc(sizeof(polyNode));
	B = (polyPointer)malloc(sizeof(polyNode));
	C = (polyPointer)malloc(sizeof(polyNode));
	A->coef = 0;
	A->expon = -1;
	A->link = NULL;
	B->coef = 0;
	B->expon = -1;
	B->link = NULL;
	C->coef = 0;
	C->expon = -1;
	C->link = NULL;

	//pol1,pol2 : 각각 다항식A,B를 문자열 형태로 입력받기위함
	char pol1[50], pol2[50];
	printf("다항식 1 입력 : ");
	scanf("%s", pol1);
	printf("다항식 2 입력 : ");
	scanf("%s", pol2);

	int i, count = 1;

	//입력받은 다항식의 계수와 지수를 정수로 바꾸어 CoefA,ExponA에 저장
	getInt(pol1, A, CoefA, ExponA);
	//다항식의 항의 개수세기
	for (i = 0; CoefA[i] != 9999; i++)
		count++;
	//다항식의 계수와 지수에 대한 노드를 원형리스트에 추가시킴
	for (i = 0; i < count; i++)
	{
		A = addNode(A, CoefA[i], ExponA[i]);
	}

	//입력받은 다항식의 계수와 지수를 정수로 바꾸어 CoefB,ExponB에 저장
	getInt(pol2, B, CoefB, ExponB);
	count = 1;
	//다항식의 항의 개수세기
	for (i = 0; CoefB[i] != 9999; i++)
		count++;
	//다항식의 계수와 지수에 대한 노드를 원형리스트에 추가시킴
	for (i = 0; i < count; i++)
	{
		B = addNode(B, CoefB[i], ExponB[i]);
	}

	//두 다항식의 차를 계산
	C = diff(A, B);

	//두 다항식의 차를 계산한 결과 출력
	print_poly(C);
}//main

//문자열로 입력받은 다항식의 계수와 지수를 정수로 변환해 계수에 대한 배열, 
//지수에 대한 배열로 저장하는 함수
polyPointer getInt(char pol[], polyPointer head, int Coef[], int Expon[])
{
	char coef[10], expon[10];
	int i, j, n = 0, k = 0;

	//pol[i]가 NULL일때까지 반복
	for (i = 0; pol[i-1] != 0; i++)
	{
		//pol에 입력된 계수에 대한 문자열을 coef에 저장(아직은 문자열임)
		coef[k++] = pol[i];
		//pol에서 "^"이 나오면 지수에 대한 문자열을 저장할 차례임
		if (pol[i + 1] == '^')
		{
			i++;
			i++;
			k = 0;
			//플러스나 마이너스가 나오기 전까지는 지수에 대한 정보임
			for (j = i; (pol[j] != '+') && (pol[j] != '-'); j++)
			{
				//만약 다항식이 끝났다면 break
				if (pol[j] == NULL)
					break;
				//pol에 입력된 지수에 대한 문자열을 expon에 저장(아직은 문자열)
				expon[k++] = pol[j];
			}
			//다항식이 끝났다면 break
			if (pol[j] == NULL)
				break;
			//지수 뒤에 마이너스가 나온다면 마이너스도 계수에 저장해야하므로 i=j-1로 설정한다
			if (pol[j] == '-')
				i = j - 1;
			//지수 뒤에 플러스가 나오면 숫자만 계수로 저장해도 되므로 i=j로 설정
			else
				i = j;

			//다항식에서 분리해낸 계수와 지수의 문자열을 정수로 변환해 각각 Coef와 Expon에 차례로 저장
			Coef[n] = atoi(coef);
			Expon[n] = atoi(expon);
			n++;
			//다항식의 계수와 지수는 항 한개씩 분리해 정수로 변환할 것이므로, 
			//다항식의 계수와 지수를 정수로 변환 후에는 계수와 지수를 문자열로 저장하는
			//coef,expon를 다시 비워줌(NULL로 초기화)
			for (k = 0; k < 10; k++)
			{
				coef[k] = NULL;
				expon[k] = NULL;
			}
			k = 0;
		}
	}

	//마지막 항의 계수, 지수를 정수로 변환 후 저장
	Coef[n] = atoi(coef);
	Expon[n] = atoi(expon);
	n++;
	//Coef,Expon에 계수와 지수가 저장된 배열의 길이를 알기위해 임의로 지정해준 것임
	Coef[n] = 9999;
	Expon[n] = 9999;
}//getInt


//원형리스트 끝에 노드를 추가하는 함수
polyPointer addNode(polyPointer head, int coef, int expon)
{
	//새로 생성할 노드 p
	polyPointer p;
	p = (polyPointer)malloc(sizeof(polyNode));
	p->coef = coef;
	p->expon = expon;
	
	//원형리스트이므로 리스트의 끝은 헤드를 가리킨다.
	p->link = head;

	polyPointer temp;
	temp = head; //temp에 head복사

	//head가 가리키는 것이 없다면(노드가 head만 존재할때), head가 p를 가리키게 함
	if (temp->link == NULL)
	{
		temp->link = p;
	}
	//head외에 head와 연결된 다른 노드들이 있을 때
	else
		//리스트의 끝에 있는 노드를 찾아서 temp에 저장(리스트의 끝에있는 노드의 link는 head를 가리킴)
		while (temp->link != head)
			temp = temp->link;
	//temp(리스트의 끝에있는 노드)의 link가 새로 생성한 노드를 가리키게함
	temp->link = p;
	return head;

}//addNode 

//끝에 노드를 붙이는 함수
void attach(float coefficient, int exponent, polyPointer* ptr)
{
	polyPointer temp = NULL;
	temp = (polyPointer)malloc(sizeof(polyNode));

	temp->coef = coefficient;
	temp->expon = exponent;
	(*ptr)->link = temp;
	*ptr = temp;
}//attach

//두 정수(지수)를 비교하는 함수
int COMPARE(int exp1, int exp2)
{
	//exp1이 크면 1반환
	if (exp1 > exp2)
		return 1;
	//exp2가 크면 -1반환
	else if (exp1 < exp2)
		return -1;
	//지수가 같으면 0반환
	else
		return 0;
}//COMPARE


//두 다항식의 차를 계산하는 함수
polyPointer diff(polyPointer a, polyPointer b)
{
	//강의노트와 거의 동일함
	polyPointer startA, c, lastC;
	int dif, done = 0;
	startA = a;

	a = a->link;
	b = b->link;
	c = (polyPointer)malloc(sizeof(polyNode));
	c->expon = -1;
	lastC = c;

	do {
		switch (COMPARE(a->expon, b->expon)) { 
		case -1 :
			//차를 구하는 것이므로 -(b->coef)와 b->expon의 attach한 것을 lastC에 갱신한다
			attach(-(b->coef), b->expon, &lastC);
			b = b->link;
			break;
		case 0 :
			if (startA == a)
				done = 1;
			else {
				//dif는 a->coef와 b->coef의 차
				dif = a->coef - b->coef;
				attach(dif, a->expon, &lastC);
				a = a->link;
				b = b->link;
			}
			break;
		case 1 :
			attach(a->coef, a->expon, &lastC);
			a = a->link;
		}
	} while (!done);
	lastC->link = c;
	return c;
}//diff

//다항식을 출력하는 함수
void print_poly(polyPointer head)
{
	printf("\n");
	//다항식의 끝까지 반복
	for (polyPointer p = head->link; p->link != head; p = p->link)
	{
		//expon와 coef의 끝의 위치를 파악하기 위해 마지막 값으로 9999를 입력해주었으므로,
		////p->expon가 9999인 경우는 생략하고 나머지 항에 대한 값만 출력한다.
		if (p->expon == 9999)
			continue;
		printf("%d^", p->coef);
		printf("%d", p->expon);
		//다항식의 끝에는 +를 출력하지 않기위함
		if (p->link->link != head)
			printf(" + ");
	}
}//print_poly