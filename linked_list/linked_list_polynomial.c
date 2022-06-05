#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� :  ���쿬
�ۼ���(������) :  2020.09.27
���α׷� ��� : ������ ���׽� 2���� Ű����� �Է¹ް� ��������Ʈ�� �̿��� �����ϰ�,
			   �� ���׽��� ���� ������ ����� ����ϴ� ���α׷�. �� ���׽��� ������
			   ����� ��� �����̴�.
*/
#include <stdio.h>
#include <stdlib.h>

//���׽��� ����� ���������� �����ϴ� ����ü
typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
}polyNode;

//�Լ�����
void attach(float coefficient, int exponent, polyPointer* ptr);
polyPointer diff(polyPointer a, polyPointer b);
int COMPARE(int exp1, int exp2);
polyPointer getInt(char pol[], polyPointer head, int Coef[], int Expon[]);
void print_poly(polyPointer head);
polyPointer addNode(polyPointer head, int coef, int expon);

void main()
{
	//CoefA:���׽�A�ǰ������, CoefB:���׽�B�ǰ������, ExponA:���׽�A����������, ExponB:���׽�B����������
	int CoefA[50], ExponA[50], CoefB[50], ExponB[50];

	//���׽�A,B,C such that A-B=C
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

	//pol1,pol2 : ���� ���׽�A,B�� ���ڿ� ���·� �Է¹ޱ�����
	char pol1[50], pol2[50];
	printf("���׽� 1 �Է� : ");
	scanf("%s", pol1);
	printf("���׽� 2 �Է� : ");
	scanf("%s", pol2);

	int i, count = 1;

	//�Է¹��� ���׽��� ����� ������ ������ �ٲپ� CoefA,ExponA�� ����
	getInt(pol1, A, CoefA, ExponA);
	//���׽��� ���� ��������
	for (i = 0; CoefA[i] != 9999; i++)
		count++;
	//���׽��� ����� ������ ���� ��带 ��������Ʈ�� �߰���Ŵ
	for (i = 0; i < count; i++)
	{
		A = addNode(A, CoefA[i], ExponA[i]);
	}

	//�Է¹��� ���׽��� ����� ������ ������ �ٲپ� CoefB,ExponB�� ����
	getInt(pol2, B, CoefB, ExponB);
	count = 1;
	//���׽��� ���� ��������
	for (i = 0; CoefB[i] != 9999; i++)
		count++;
	//���׽��� ����� ������ ���� ��带 ��������Ʈ�� �߰���Ŵ
	for (i = 0; i < count; i++)
	{
		B = addNode(B, CoefB[i], ExponB[i]);
	}

	//�� ���׽��� ���� ���
	C = diff(A, B);

	//�� ���׽��� ���� ����� ��� ���
	print_poly(C);
}//main

//���ڿ��� �Է¹��� ���׽��� ����� ������ ������ ��ȯ�� ����� ���� �迭, 
//������ ���� �迭�� �����ϴ� �Լ�
polyPointer getInt(char pol[], polyPointer head, int Coef[], int Expon[])
{
	char coef[10], expon[10];
	int i, j, n = 0, k = 0;

	//pol[i]�� NULL�϶����� �ݺ�
	for (i = 0; pol[i-1] != 0; i++)
	{
		//pol�� �Էµ� ����� ���� ���ڿ��� coef�� ����(������ ���ڿ���)
		coef[k++] = pol[i];
		//pol���� "^"�� ������ ������ ���� ���ڿ��� ������ ������
		if (pol[i + 1] == '^')
		{
			i++;
			i++;
			k = 0;
			//�÷����� ���̳ʽ��� ������ �������� ������ ���� ������
			for (j = i; (pol[j] != '+') && (pol[j] != '-'); j++)
			{
				//���� ���׽��� �����ٸ� break
				if (pol[j] == NULL)
					break;
				//pol�� �Էµ� ������ ���� ���ڿ��� expon�� ����(������ ���ڿ�)
				expon[k++] = pol[j];
			}
			//���׽��� �����ٸ� break
			if (pol[j] == NULL)
				break;
			//���� �ڿ� ���̳ʽ��� ���´ٸ� ���̳ʽ��� ����� �����ؾ��ϹǷ� i=j-1�� �����Ѵ�
			if (pol[j] == '-')
				i = j - 1;
			//���� �ڿ� �÷����� ������ ���ڸ� ����� �����ص� �ǹǷ� i=j�� ����
			else
				i = j;

			//���׽Ŀ��� �и��س� ����� ������ ���ڿ��� ������ ��ȯ�� ���� Coef�� Expon�� ���ʷ� ����
			Coef[n] = atoi(coef);
			Expon[n] = atoi(expon);
			n++;
			//���׽��� ����� ������ �� �Ѱ��� �и��� ������ ��ȯ�� ���̹Ƿ�, 
			//���׽��� ����� ������ ������ ��ȯ �Ŀ��� ����� ������ ���ڿ��� �����ϴ�
			//coef,expon�� �ٽ� �����(NULL�� �ʱ�ȭ)
			for (k = 0; k < 10; k++)
			{
				coef[k] = NULL;
				expon[k] = NULL;
			}
			k = 0;
		}
	}

	//������ ���� ���, ������ ������ ��ȯ �� ����
	Coef[n] = atoi(coef);
	Expon[n] = atoi(expon);
	n++;
	//Coef,Expon�� ����� ������ ����� �迭�� ���̸� �˱����� ���Ƿ� �������� ����
	Coef[n] = 9999;
	Expon[n] = 9999;
}//getInt


//��������Ʈ ���� ��带 �߰��ϴ� �Լ�
polyPointer addNode(polyPointer head, int coef, int expon)
{
	//���� ������ ��� p
	polyPointer p;
	p = (polyPointer)malloc(sizeof(polyNode));
	p->coef = coef;
	p->expon = expon;
	
	//��������Ʈ�̹Ƿ� ����Ʈ�� ���� ��带 ����Ų��.
	p->link = head;

	polyPointer temp;
	temp = head; //temp�� head����

	//head�� ����Ű�� ���� ���ٸ�(��尡 head�� �����Ҷ�), head�� p�� ����Ű�� ��
	if (temp->link == NULL)
	{
		temp->link = p;
	}
	//head�ܿ� head�� ����� �ٸ� ������ ���� ��
	else
		//����Ʈ�� ���� �ִ� ��带 ã�Ƽ� temp�� ����(����Ʈ�� �����ִ� ����� link�� head�� ����Ŵ)
		while (temp->link != head)
			temp = temp->link;
	//temp(����Ʈ�� �����ִ� ���)�� link�� ���� ������ ��带 ����Ű����
	temp->link = p;
	return head;

}//addNode 

//���� ��带 ���̴� �Լ�
void attach(float coefficient, int exponent, polyPointer* ptr)
{
	polyPointer temp = NULL;
	temp = (polyPointer)malloc(sizeof(polyNode));

	temp->coef = coefficient;
	temp->expon = exponent;
	(*ptr)->link = temp;
	*ptr = temp;
}//attach

//�� ����(����)�� ���ϴ� �Լ�
int COMPARE(int exp1, int exp2)
{
	//exp1�� ũ�� 1��ȯ
	if (exp1 > exp2)
		return 1;
	//exp2�� ũ�� -1��ȯ
	else if (exp1 < exp2)
		return -1;
	//������ ������ 0��ȯ
	else
		return 0;
}//COMPARE


//�� ���׽��� ���� ����ϴ� �Լ�
polyPointer diff(polyPointer a, polyPointer b)
{
	//���ǳ�Ʈ�� ���� ������
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
			//���� ���ϴ� ���̹Ƿ� -(b->coef)�� b->expon�� attach�� ���� lastC�� �����Ѵ�
			attach(-(b->coef), b->expon, &lastC);
			b = b->link;
			break;
		case 0 :
			if (startA == a)
				done = 1;
			else {
				//dif�� a->coef�� b->coef�� ��
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

//���׽��� ����ϴ� �Լ�
void print_poly(polyPointer head)
{
	printf("\n");
	//���׽��� ������ �ݺ�
	for (polyPointer p = head->link; p->link != head; p = p->link)
	{
		//expon�� coef�� ���� ��ġ�� �ľ��ϱ� ���� ������ ������ 9999�� �Է����־����Ƿ�,
		////p->expon�� 9999�� ���� �����ϰ� ������ �׿� ���� ���� ����Ѵ�.
		if (p->expon == 9999)
			continue;
		printf("%d^", p->coef);
		printf("%d", p->expon);
		//���׽��� ������ +�� ������� �ʱ�����
		if (p->link->link != head)
			printf(" + ");
	}
}//print_poly