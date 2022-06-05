#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ���(������) : 2020.10.02
���α׷� ��� : ������ ���� �Է¹޾�, �־��� tree�� node�� ���Ͽ� 
			   �Է¹��� ������ tree node�� ���� �� ������, ���� node����
			   ��� ����ϴ� ���α׷�.
*/
#include <stdio.h>

//tree�� �����ϴ� ��屸��ü
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild;
	treePointer rightChild;
}node;

//tree ��� ���� �Է¹��� ������ ���� ���� �ִ��� Ȯ���ϱ� ���� ����
int empty;

//�Լ�����
void preorder(treePointer ptr, int num);

void main()
{
	//Ʈ���� ��忡 ���� ���� ������ data�迭
	int data[13] = { 8,4,9,2,5,10,13,21,3,6,17,25,15 };
	//tree�� ǥ���� �迭
	node root[14];

	//�Է¹��� ��
	int num;
	//���α׷��� ��������� �����ϴ� ����
	char ans[2] = "y";

	//tree��忡 ������ ���� �Ҵ�
	//����� leftChild�� rightChild�� NULL�� ����
	for (int i = 1; i < 14; i++)
	{
		root[i].data = data[i - 1];
		root[i].leftChild = NULL;
		root[i].rightChild = NULL;
	}

	//������ ����� leftChild,rightChild�� ����Ű�� ���� �Ҵ�
	for (int i = 1; i < 14; i++)
	{
		if (i % 2 == 0)
			root[i / 2].leftChild = &root[i];
		else
			root[i / 2].rightChild = &root[i];
	}

	//ans�� ���� 'n'�� �Է¹��������� �ݺ�
	for (;;)
	{
		num = 0;
		printf("\n���� �Է��Ͻÿ� : ");
		scanf("%d", &num);

		//empty�� �Ź� 0���� �ʱ�ȭ
		empty = 0;
		preorder(&root[1], num);

		//�ϳ��� Ʈ������� ���� �Է¹��� ������ ������ empty�� 1�� ��
		if (empty == 0)
			printf("�Է��� %d���� ���� ���� ���� ���� �����ϴ�.\n", num);

		printf("\n��� �Ͻðڽ��ϱ�?(y/n) : ");
		scanf("%s", ans);
		//'n'�� �Է¹����� ���α׷� ����
		if (ans[0] == 'n')
			break;
		//'n'�� 'y'���� ���ڸ� �Է¹޾Ƶ� ���α׷��� ������
		else if (ans[0] != 'n' && ans[0] != 'y')
		{
			printf("�߸��� ���ڸ� �Է��߽��ϴ�. ���α׷��� �����մϴ�.\n");
			return;
		}
	}

}

//preorder traversal�� ������� Ʈ����带 Ž���ϸ�, �Է¹��� ������ ���� ��尪��
//�߰ߵǸ� �� ���� ����ϰ� empty�� 1�� �ٲٴ� �Լ��̴�.
void preorder(treePointer ptr, int num)
{
	if (ptr) {
		if (num > ptr->data) 
		{
			printf("\n%d���� ���� ��� : %d", num, ptr->data);
			empty = 1;
		}
		preorder(ptr->leftChild, num);
		preorder(ptr->rightChild, num);
	}
	return;
}//preorder
