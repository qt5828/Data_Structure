#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ���(������) : 2020.09.29
���α׷� ��� : 4�����ǽ�����2�� ������ �־��� binary tree�� level order traversal��
			   �����ϰ�, �������� ����ϴ� ���α׷�. linked list�� circular queue�� ����Ѵ�.
*/
#include <stdio.h>

//tree�� �����ϴ� ��屸��ü
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}node;

//node Ÿ���� queue, �ִ���� 20
node queue[20];
int front = 0, rear = 0;

//�Լ�����
void levelOrder(treePointer ptr);
void addq(int item);
int deleteq();
int queueFull();
int queueEmpty();
void main()
{
	//Ʈ����忡 �Ҵ��� ���� ������ data�迭
	int data[13] = { 8, 4, 9, 2, 5, 10, 13, 1, 3, 6, 7, 11, 12 };
	node root[14];

	//tree��忡 ������ ���� �Ҵ�
	//����� leftChild�� rightChild�� NULL�� �����Ѵ�.
	for (int i = 1; i < 14; i++)
	{
		root[i].data = data[i - 1];
		root[i].leftChild = NULL;
		root[i].rightChild = NULL;
	}

	//������ ����� leftChild�� rightChild�� ����Ű�� ���� �Ҵ�
	for (int i = 1; i < 14; i++)
	{
		if (i % 2 == 0)
			root[i / 2].leftChild = &root[i];
		else
			root[i / 2].rightChild = &root[i];
	}

	//level order traversal�� ������� tree�� ��尪�� ������ �� ����� ���� ���
	printf("Level order traversal�� ��� : ");
	levelOrder(&root[1]);

}//main

//level order traversal�� ������� tree�� ��尪�� ������ �� ����� ���� ����ϴ� �Լ�
//ť�� �̿��Ѵ�.
void levelOrder(treePointer ptr)
{
	if (!ptr)
		return;
	addq(ptr);

	for (;;) {
		ptr = deleteq();
		if (ptr) {
			printf("%d ", ptr->data);
			if (ptr->leftChild)
				addq(ptr->leftChild);
			if (ptr->rightChild)
				addq(ptr->rightChild);
		}
		else
			break;
	}
}//levelOrder

//ť�� ���� ���� �߰��ϴ� �Լ�
void addq(int item)
{
	rear = (rear + 1) % 20;
	if (front == rear)
		queueFull(rear);
	queue[rear].data = item;
}//addq

//ť�� ���� ���� ���� �����ϰ� �� ���� ��ȯ�ϴ� �Լ�
int deleteq()
{
	if (front == rear)
		return queueEmpty();
	front = (front + 1) % 20;
	return queue[front].data;
}//deleteq

//ť�� ��á���� Ȯ���ϴ� �Լ�
int queueFull()
{
	if ((front - rear == 1) || (rear - front == 6))
		printf("queue�� �� á���ϴ�.\n");
	else
		return 1;
}//queueFull

//ť�� ������� Ȯ���ϴ� �Լ�
int queueEmpty()
{
	if (front == rear) {
		printf("\n");
		return 0;
	}
	return 1;
}//queueEmpty
