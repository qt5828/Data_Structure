#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ���(������) : 2020.09.29
���α׷� ��� : 4�����ǽ�����1�� ������ �־��� binary tree�� inorder traversal,
			   preorder traversal, postorder traversal�� �����Ͽ� ������ �����
			   ����ϴ� ���α׷�. linked list�� ����� �����Ѵ�.
*/
#include <stdio.h>

//tree�� �����ϴ� ��屸��ü
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}node;

//�Լ�����
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

void main()
{
	//Ʈ���� ��忡 ���� ���� ������ data�迭
	int data[13] = { 8, 4, 9, 2, 5, 10, 13, 1, 3, 6, 7, 11, 12 }; 
	//tree�� ǥ���� �迭
	node root[14];

	//tree��忡 ������ ���� �Ҵ�
	//����� leftChild�� rightChild�� NULL�� �����Ѵ�.
	for (int i = 1; i < 14; i++)
	{
		root[i].data = data[i - 1];
		root[i].leftChild = NULL;
		root[i].rightChild = NULL;
	}

	//������ ����� leftChild, rightChild�� ����Ű�� ���� �Ҵ�
	for (int i = 1; i < 14; i++)
	{
		if (i % 2 == 0)
			root[i / 2].leftChild = &root[i];
		else
			root[i / 2].rightChild = &root[i];
	}

	//inorder traversal�� ������� tree�� ��尪�� ���
	printf("Inorder traversal�� ��� : ");
	inorder(&root[1]);
	printf("\n");

	//preorder traversal�� ������� tree�� ��尪�� ���
	printf("Preorder traversal�� ��� : ");
	preorder(&root[1]);
	printf("\n");

	//postorder traversal�� ������� tree�� ��尪�� ���
	printf("Postorder traversal�� ��� : ");
	postorder(&root[1]);
	printf("\n");
}//main

//inorder traversal�� ������� tree����� ���� ����ϴ� �Լ�
void inorder(treePointer ptr)
{
	if (ptr) {
		inorder(ptr->leftChild);
		printf("%d ", ptr->data);
		inorder(ptr->rightChild);
	}
	return;
}//inorder

//preorder traversal�� ������� tree����� ���� ����ϴ� �Լ�
void preorder(treePointer ptr)
{
	if (ptr) {
		printf("%d ", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
	return;
}//preorder

//postorder traversal�� ������� tree����� ���� ����ϴ� �Լ�
void postorder(treePointer ptr)
{
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%d ", ptr->data);
	}
	return;
}//postorder
