#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ���(������) : 2020.10.01
���α׷� ��� : 4�����ǽ�����3�� ������ �־��� binary tree������ ������������ C:\������
			   D:\������ ��ü�뷮�� "����ǻ��"�� ��ü�뷮�� ����ϴ� ���α׷�
			   linked list�� binary traversal����� �̿��Ѵ�.
*/
#include <stdio.h>

//������ �뷮�� ������ sum
int sum;

//tree�� �����ϴ� ��屸��ü
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}node;

//�Լ�����
void inorder(treePointer ptr);

void main()
{
	//���������� ������ �뷮�� data�迭�� ������ �ʱ�ȭ
	int data[15] = { 0,0,10,2,15,40,70,100,150,0,0,10,20,50,150 };
	//tree�� ǥ���� �迭
	node root[16];

	//tree ��忡 ������ ���� �Ҵ�
	//����� leftChild�� rightChild�� NULL�� �����Ѵ�.
	for (int i = 1; i < 16; i++)
	{
		root[i].data = data[i - 1];
		root[i].leftChild = NULL;
		root[i].rightChild = NULL;
	}

	//������ ����� leftChild�� rightChild�� ����Ű�� ���� �Ҵ�
	for (int i = 2; i < 16; i++)
	{
		if (i % 2 == 0)
			root[i / 2].leftChild = &root[i];
		else
			root[i / 2].rightChild = &root[i];
	}

	//C:�� �뷮�� ���
	printf("C:�� �뷮 : ");
	sum = 0;
	//C:�κ��� subtree�� ù��° �ּڰ��� inorder�Լ��� �־ C: subtree�� �����뷮�� ���� ���Ѵ�.
	//inorder traversal�� ������� subtree�� ��尪�� �����Ͽ� �� �뷮�� ���� ����Ѵ�.
	inorder(&root[2]);
	printf("%dM�Դϴ�.\n", sum);

	//D:�κ��� subtree�� ù��° �ּڰ��� inorder�Լ��� �־ D: subtree�� �����뷮�� ���� ���Ѵ�.
	//inorder traversal�� ������� subtree�� ��尪�� �����Ͽ� �� �뷮�� ���� ����Ѵ�.
	printf("D:�� �뷮 : ");
	sum = 0;
	inorder(&root[3]);
	printf("%dM�Դϴ�.\n", sum);

	//��ütree(root)�� ù��° �ּڰ��� inorder�Լ��� �־ ��ü������ �뷮�� ���� ���Ѵ�.
	//inorder traversal�� ������� subtree�� ��尪�� �����Ͽ� �� �뷮�� ���� ����Ѵ�.
	printf("����ǻ���� ��ü�뷮 : ");
	sum = 0;
	inorder(&root[1]);
	printf("%dM�Դϴ�.\n", sum);

}//main

//inorder traversal�� ������� �־��� �ּڰ��� �������� (sub)tree�� ����� ���� ���� ���ϴ� �Լ�
void inorder(treePointer ptr)
{
	if (ptr) {
		inorder(ptr->leftChild);
		sum += ptr->data;
		inorder(ptr->rightChild);
	}
	return;
}//inorder
