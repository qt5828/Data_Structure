#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ���  :  ���쿬
�ۼ���(������) : 2020.09.20
���α׷� ��� : �Է¹��� ����� ������ŭ �� ����� ������ ���� �Է¹ް�,
			   ��� ����� ���� ���� �ִ񰪰� �ּڰ��� ã�� ����ϴ� ���α׷�.
			   �ܼ����Ḯ��Ʈ�� �����ȴ�.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element; 

//<������,��ũ>���� ��带 ��Ÿ���� ����ü
typedef struct ListNode {
	element data; 
	struct ListNode* link; 
}ListNode;

//�Լ�����
ListNode* addNode(ListNode* head);
void check_node(ListNode* head);
void main()
{
	int num, i;
	printf("����� ������ �Է��ϼ��� : ");
	scanf("%d", &num); //�Է¹��� ��Ʈ�� �� �Է¹���

	ListNode* head = NULL;
	ListNode* p;
	head = (ListNode*)malloc(sizeof(ListNode));
	p = (ListNode*)malloc(sizeof(ListNode));
	
	printf("\n��� 1�� ������ : ");
	scanf("%d", &head->data);
	head->link = NULL;

	//�̹� 1��° ��尪�� �Է¹޾����Ƿ� 2��°~num��° ��尪�� �Է¹޾Ƽ�
	//����Ʈ ���� ��带 ����
	for (i = 0; i < num - 1; i++)
	{
		printf("\n��� %d�� ������ : ", i + 2);
		addNode(head);
	}
	//�Էµ� ����� �����Ͱ� �� �ִ񰪰� �ּڰ� ���
	check_node(head);

}//main

//����Ʈ ���� ��带 �����ϴ� �Լ�
ListNode* addNode(ListNode* head)
{
	ListNode* p;
	p = (ListNode*)malloc(sizeof(ListNode));

	//���� ������ ����� �����Ͱ��� �Է¹���
	scanf("%d", &p->data);
	//����Ʈ�� ���� ������ ���̹Ƿ� ���� ������ ����� link�� NULL�� ����Ŵ
	p->link = NULL;

	ListNode* temp;
	temp = head; //temp�� head����

	//����Ʈ���� �ִ� ��带 ã�� temp�� ����
	while (temp->link != NULL)
		temp = temp->link;
	//temp(����Ʈ�� �����ִ� ���)�� link�� ���� ������ ��带 ����Ű����
	temp->link = p;

}//addNode

//����Ʈ�� �ִ� �� ������ ��嵥���Ͱ��� ���� �ִ�,�ּڰ��� ã�� ����ϴ� �Լ�
void check_node(ListNode* head)
{
	//max,min�� ���� ������ ǥ���Ǵ� ���� ������, ū���� �ʱ�ȭ
	int max = INT_MIN;
	int min = INT_MAX;

	//����Ʈ�� ó������ ������ ��尪�� ���ϴ� �ݺ���
	for (ListNode* p = head; p != NULL; p = p->link)
	{
		//max���� ��嵥���Ͱ��� �� ũ�� max�� ��嵥���Ͱ��� ����
		if ((p->data) > max)
			max = p->data;
		//min���� ��嵥���Ͱ��� �� ������ min�� ��嵥���Ͱ��� ����
		if ((p->data) < min)
			min = p->data;
	}
	//������ �ִ�,�ּڰ� ���
	printf("max = %d, min = %d\n", max, min);

}//check_node