#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ���(������) : 2020.10.03
���α׷� ��� : 5�����ǽ� 2�������� �־��� binary tree�� threaded binary tree�� �����Ͽ�
			   inorder traversal�� ������ ����� ����ϴ� ���α׷�. linked list�� ����ϸ�
			   Inorder successor�� ã�� insucc()�Լ��� threaded binary tree���� inorder traversal��
			   �ϴ� �Լ� tiorder()�� �����Ͽ� ó���Ѵ�.
*/
#include <stdio.h>
#include <stdlib.h>

//threaded binary tree�� �����ϴ� ��屸��ü
typedef struct node* threadedPointer;
typedef struct node {
	int data;
	threadedPointer leftChild;
	threadedPointer rightChild;
	short int leftThread;
	short int rightThread;
}node;


//�Լ�����
threadedPointer insucc(threadedPointer tree);
void tinorder(threadedPointer tree);

void main()
{
	//Ʈ���� ��忡 ���� ���� ������ data�迭
	int data[13] = { 8,4,9,2,5,10,13,21,3,6,17,25,15 };
	//Ʈ���� ����� ���� leftThread, rightThread�� �������� ������ �迭��
	short int Lthread[13] = { 0,0,0,0,0,0,1,1,1,1,1,1,1 };
	short int Rthread[13] = { 0,0,0,0,0,0,1,1,1,1,1,1,1 };
	//tree�� ǥ���� �迭
	node tree[14];

	//tree��忡 ������ ���� �Ҵ�
	//����� leftChild�� rightChild�� NULL�� ����
	for (int i = 1; i < 14; i++)
	{
		tree[i].data = data[i - 1];
		tree[i].leftChild = NULL;
		tree[i].rightChild = NULL;
		tree[i].leftThread = Lthread[i - 1];
		tree[i].rightThread = Rthread[i - 1];
	}
	//������ ����� leftChild,rightChild�� ����Ű�� ���� �Ҵ�
	for (int i = 1; i < 14; i++)
	{
		if (i % 2 == 0)
			tree[i / 2].leftChild = &tree[i];
		else
			tree[i / 2].rightChild = &tree[i];
	}

	//root����� ����
	tree[0].leftChild = &tree[1];
	tree[0].rightChild = NULL;
	tree[0].leftThread = 0;
	tree[0].rightThread = 0;

	//rightThread�� true�� ��忡 rightChild�� Thread�� ��.
	tree[8].rightChild = &tree[4];
	tree[9].rightChild = &tree[2];
	tree[10].rightChild = &tree[5];
	tree[11].rightChild = &tree[1];
	tree[12].rightChild = &tree[6];
	tree[13].rightChild = &tree[3];

	//inorder traversal�� ����� ���
	printf("Inorder traversal of a threaded binary tree : ");
	tinorder(&tree[0]);

}//main

//threaded binary tree���� inorder successor�� ã�� �Լ�
threadedPointer insucc(threadedPointer tree)
{
	threadedPointer temp;
	temp = tree->rightChild;
	//temp�� NULL�� �ƴϰ�, Ʈ���� rightThread�� 0�� �ƴϸ� ����
	if (temp!=NULL && !tree->rightThread)
	{
		//���ʳ�������
		while (!temp->leftThread)
			temp = temp->leftChild;
	}

	return temp;
}//insucc

//threaded binary tree�� inorder������� Ž���� ����ϴ� �Լ�
void tinorder(threadedPointer tree)
{
	threadedPointer temp = tree;
	//���� ������ �̵�
	while (temp->leftChild)
		temp = temp->leftChild;
	for (;;)
	{
		printf("%d ", temp->data);
		//temp�� successor�� ã�Ƽ� temp�� ����
		temp = insucc(temp);
		//temp�� NULL�̸� ��������
		if (temp == NULL)
		{
			printf("\n");
			break;
		}
	}
}//tinorder
