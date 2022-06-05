#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� :  ���쿬
�ۼ���(������) :  2020.09.26
���α׷� ��� : ����ڰ� "�߰�","����","���","���� ���","����"�� �ϳ��� �����ϰ�,
			   ���õ� �Ϳ� ���� ����Ʈ�� ���� �Է¹ްų�, �����ϰų�, ����Ʈ�� ����
			   ����ϰų� �������� ����ϴ� ������ �Ѵ�. "����"�� ���õɶ����� ���α׷���
			   ������� �ʴ´�. ����Ʈ�� ���� �Է¹��� ������, ����Ʈ�� ���� ū �������
			   ���ĵǵ��� ���� �����Ѵ�. ��Ȳ������ ����Ʈ�� ����ְų�, �ߺ��� ���� ���ؼ���
			   �����޼����� ����Ѵ�.
*/

#include <stdio.h>
#include <stdlib.h>

//����Ʈ�� <������,��ũ>���� ��带 ��Ÿ���� ����ü
typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

//�Լ�����
ListNode* addNode(ListNode* head);
ListNode* delete(ListNode* head, int del);
void print(ListNode* head);
ListNode* reverse(ListNode* head);

void main()
{
	int choice;
	ListNode* head = NULL;

	head = (ListNode*)malloc(sizeof(ListNode));

	printf("1: �߰�, 2: ����, 3: ���, 4: ���� ���, 5: ����\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		head->link = NULL;
		printf("\"�Է�\"");
		scanf("%d", &head->data);
		printf("�����߽��ϴ�\n");
	}
	else if (choice == 2)
	{
		printf("\"����\"");
		printf("list�� ��� �ֽ��ϴ�.\n");
		head = NULL;
	}
	else if (choice == 3)
	{
		printf("\"���\"");
		printf("list�� ��� �ֽ��ϴ�.\n");
		head = NULL;
	}
	else if (choice == 4)
	{
		printf("\"���� ���\"");
		printf("list�� ��� �ֽ��ϴ�.\n");
		head = NULL;
	}
	else if (choice == 5)
		return;

	while (1)
	{
		printf("1: �߰�, 2: ����, 3: ���, 4: ���� ���, 5: ����\n");
		scanf("%d", &choice);
		//"�߰�"���ý�
		if (choice == 1)
		{
			printf("\"�Է�\"  ");
			//����Ʈ�� ��������� head�� ���� ����
			if (head == NULL)
			{
				head = (ListNode*)malloc(sizeof(ListNode));
				head->link = NULL;
				scanf("%d", &head->data);
				printf("�����߽��ϴ�\n");
				continue;
			}
			//����Ʈ�� �ٸ� ���� ������ ���� ����
			head = addNode(head);
		}
		//"����"���ý�
		else if (choice == 2)
		{
			printf("\"����\"  ");
			//����Ʈ�� ��������� �������
			if (head == NULL)
			{
				printf("list�� ��� �ֽ��ϴ�\n");
				continue;
			}
			int del; //������ ��
			scanf("%d", &del);
			head = delete(head, del);
		}
		//"���"���ý�
		else if (choice == 3)
		{
			printf("\"���\"  ");
			//����Ʈ�� ��������� �������
			if (head == NULL)
			{
				printf("list�� ��� �ֽ��ϴ�\n");
				continue;
			}
			print(head);
		}
		//"�������"���ý�
		else if (choice == 4)
		{
			printf("\"���� ���\"  ");
			//����Ʈ�� ��������� �������
			if (head == NULL)
			{
				printf("list�� ��� �ֽ��ϴ�\n");
				continue;
			}
			//����Ʈ�� �������� ���� �� ���
			head = reverse(head);
			print(head);
			//���� ��� ��, �ٽ� �������� ����(���� ����Ʈ�� �ǵ���)
			head = reverse(head);
		}
		//"����"���ý� ���α׷� ����
		else if (choice == 5)
		{
			printf("\"����\"");
			break;
		}
	}

	return;

}//main

//������ ���� �Է¹޾� ����Ʈ�� ������������ ���� �����ϴ� �Լ�
ListNode* addNode(ListNode* head)
{
	ListNode* p;
	p = (ListNode*)malloc(sizeof(ListNode));

	//���� ������ ����Ʈ�� ��
	scanf("%d", &p->data);

	ListNode* temp;
	temp = head; //temp�� head����

	//�Է¹��� ���� ���� ũ�� ����Ʈ�� �� �տ� ���� ����
	if (p->data > head->data)
	{
		p->link = head;
		head = p;
		printf("�����߽��ϴ�\n");
		return head;
	}

	//������������ �Է¹��� ���� ����
	while (temp->data > p->data)
	{
		//�Է¹��� ���� ���� ������ ����Ʈ�� �ǵڿ� ����
		if (temp->link == NULL)
		{
			p->link = NULL;
			temp->link = p;
			printf("�����߽��ϴ�\n");
			return head;
		}
		else {
			//�Է¹��� ���� ���� ��ġã��
			if ((temp->link->data) > p->data)
				temp = temp->link;
			//����Ʈ�ȿ� �Է¹��� ���� ���� ���� �����ϸ� �ߺ��Ǿ��ٴ� �����޼��� ���
			else if ((temp->link->data) == p->data)
			{
				printf("�ߺ��� �������Դϴ�\n");
				return head;
			}
			//������������ �Է¹��� ���� ������ ��ġ�� ã���� ��, break
			else
				break;
		}
	}
	//����Ʈ�� ���������� �Է¹��� ���� ������, �ߺ����� �˸��� �����޼��� ���
	if (temp->data == p->data)
	{
		printf("�ߺ��� �������Դϴ�\n");
		return head;
	}

	//�Է¹��� �� ����
	p->link = temp->link;
	temp->link = p;
	printf("�����߽��ϴ�\n");
	return head;

}//addNode

//�Է¹��� ���� ����Ʈ���� �����ϴ� �Լ�
ListNode* delete(ListNode* head, int del)
{
	ListNode* removed;

	//�Ǿ� ���� ������ ��
	if (head->data == del)
	{
		removed = head;
		head = removed->link;
		free(removed);
		printf("�����߽��ϴ�\n");
		return head;
	}

	//������ ���� ����Ʈ���� ã�� �ڵ�
	for (ListNode* p = head; p->link != NULL; p = p->link)
	{
		//������ ���� ã���� �ش� ���� ����
		if (p->link->data == del)
		{
			removed = p->link;
			p->link = removed->link;
			free(removed);
			printf("�����߽��ϴ�\n");
			return head;
		}
	}
	//������ ���� ����Ʈ���� ã�����ϸ� �����޼��� ���
	printf("ã�� ���� �����ϴ�.\n");
	return head;

}//delete


//����Ʈ�� �ִ� ��� ���� ����ϴ� �Լ�
void print(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d ", p->data);
	printf("\n");
}//print

//����Ʈ�� ���� �������� ��ȯ�ϴ� �Լ�
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