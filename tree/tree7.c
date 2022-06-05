
#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� :  ���쿬
�ۼ���(������) : 2020.10.13
���α׷� ��� : binary search tree�� ����Ͽ� ������ ��ȸ�� ������ ������ �����ϱ� ����
			   ���α׷��� �����Ѵ�. ����ڴ� �Է�, �˻�, ��������, �������, ���� �� ������
			   �� �� �ְ�, ���� ������ ���, ������ �˻�, �������� ��������, �������, ����
			   �׷� ������ ������ �����Ѵ�. ���� �̸��� �����ڴ� ����� �ȵǸ�, ��ܿ� ��������
			   �ʴ� ����� �˻��� ��������, ������Ҵ� ���ѵȴ�.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct {
	char name[11];
	char date[9];
	char add[21];
}element;
typedef struct node {
	element data;
	treePointer leftChild;
	treePointer rightChild;
}node;

treePointer search(treePointer root, char name[]);
void insert(treePointer node);
treePointer Change(treePointer root, char name[], char change[]);
void delete(treePointer* root, char name[]);
void main()
{
	int ans;
	treePointer root = NULL;
	root = (treePointer)malloc(sizeof(node));
	printf("������ ���� ���� ���α׷�\n\n");

	//��Ʈ�� ���� �Է¹��� �� �ְ� �и�����(���ǻ�..)
	while (1)
	{
		printf("�Է�(1), �˻�(2), ��������(3), �������(4), ����(5)\n");
		scanf("%d", &ans);
		if (ans == 1)
		{
			char name[11], add[21], date[9];
			printf("������ �Է��Ͻʽÿ�.\n�̸�(���� 10���̳�)\n");
			scanf("%s", name);
			printf("��û��¥(YYYYMMDD)\n");
			scanf("%s", date);
			printf("��û����(���� 20���̳�)\n");
			scanf("%s", add);
			strcpy(root->data.name, name);
			strcpy(root->data.add, add);
			strcpy(root->data.date, date);
			root->leftChild = root->rightChild = NULL;
			break;
		}
		else if (ans >= 2 && ans <=4)
		{
			printf("����� ����ֽ��ϴ�.\n");
			continue;
		}
		else if (ans == 5)
		{
			printf("�����մϴ�.\n");
			return;
		}
		else
			continue;
	}

	//ans�� 5�� �Ǿ ���α׷��� �����Ҷ����� �ݺ�
	while (1)
	{
		//�Źݺ����� �Է�,�˻�,��������,�������,���� �� �ϳ��� ���ù޴´�.
		printf("�Է�(1), �˻�(2), ��������(3), �������(4), ����(5)\n");
		scanf("%d", &ans);

		//�Է�
		if (ans == 1)
		{
			//binary search tree�� ������(����������� ���� ���)
			insert(&root);
		}

		//�˻�
		else if (ans == 2)
		{
			//�˻��� �̸��� �Է¹���
			char name[11];
			printf("�˻��� �̸��� �Է��Ͻʽÿ�.\n");
			scanf("%s", name);

			//find�� ã���� �ϴ� ����� ������ ����
			node* find;
			find = search(root, name);

			//find�� null�̸� binary search tree�ȿ� ��� ����
			if (!find) {
				printf("��ϵ��� ���� ����Դϴ�.\n");
				continue;
			}
			//�˻� ������ ���
			printf("�˻��� �Ϸ�Ǿ����ϴ�.\n");
			printf("�̸� %s\n��û��¥ %s\n��û���� %s\n", find->data.name, find->data.date, find->data.add);
		}

		//��������
		else if (ans == 3)
		{
			//������ ������ ����� �̸��� ������ ������ �Է¹���
			char name[11], change[21];
			printf("������ ������ �Է��Ͻʽÿ�.(�̸�,����)\n");
			scanf("%s %s", name, change);

			//record�� ������ ������ ����� ������ ����
			treePointer record;
			record = Change(root, name, change);

			//record�� null�� �ƴϸ�, �� ���������� �����ϸ� ���
			if (record)
				printf("�̸� %s\n��û��¥ %s\n��û���� %s\n", record->data.name, record->data.date, record->data.add);
		}

		//�������
		else if (ans == 4)
		{
			//������ ����� �̸��� �Է¹���
			char name[11];
			printf("����� �̸��� �Է��Ͻʽÿ�.\n");
			scanf("%s", name);
			//����
			delete(&root, name);
		}

		//����
		else if (ans == 5)
		{
			printf("�����մϴ�.\n");
			return; //���α׷� ����
		}
	}
}


//binary search tree���� name�� ���� ��带 ã�Ƽ� �� ��������͸� ��ȯ�ϴ� �Լ�
treePointer search(treePointer root, char name[])
{
	if (!root) return NULL;
	if (strcmp(name, root->data.name) == 0) return root;
	if (strcmp(name, root->data.name) == -1)
		return search(root->leftChild, name);
	return search(root->rightChild, name);
}//search

//binary search tree�� ��带 �߰��ϴ� �Լ�
void insert(treePointer* node)
{
	//����� data�� �� �̸�,�ּ�,��¥ ���� �Է¹޴´�
	char name[11], add[21], date[9];
	printf("������ �Է��Ͻʽÿ�.\n�̸�(���� 10���̳�)\n");
	scanf("%s", name);

	//name�� �̹� binary search tree�ȿ� �����ϸ� �����޼��� ���
	treePointer find;
	find = search(*node, name);
	if (find) {
		printf("�̹� ��ϵ� �������Դϴ�.\n");
		return;
	}

	printf("��û��¥(YYYYMMDD)\n");
	scanf("%s", date);
	printf("��û����(���� 20���̳�)\n");
	scanf("%s", add);

	treePointer ptr = (treePointer)malloc(sizeof(node));
	treePointer temp, p;

	temp = *node;
	p = NULL;
	strcpy(ptr->data.name, name);
	strcpy(ptr->data.add, add);
	strcpy(ptr->data.date, date);
	ptr->rightChild = NULL;
	ptr->leftChild = NULL;

	while (temp) {
		if (strcmp(name, temp->data.name) == 0)
			return;
		p = temp;
		if (strcmp(name, p->data.name) == -1)
			temp = p->leftChild;
		else
			temp = p->rightChild;
	}
	if (p)
	{
		if (strcmp(name, p->data.name) == -1)
			p->leftChild = ptr;
		else
			p->rightChild = ptr;
	}
	else
		*node = ptr;
}//insert

//�Ѱܹ��� name�� ������ �����ϴ� �Լ�
//�Ѱܹ��� change�� ���ڷ� �����ϸ� date�� �����ϰ�, ���ڷ� �����ϸ� add�� �����Ѵ�.
treePointer Change(treePointer root, char name[], char change[])
{
	//root�� null�̸� tree�� name�� ���� ����
	if (!root) {
		printf("��ϵ��� ���� ����Դϴ�.\n");
		return NULL;
	}
	//name�� root�� name�� ���� ��
	if (strcmp(name, root->data.name) == 0)
	{
		if (change[0] >= 48 && change[0] <= 57)
		{
			strcpy(root->data.date, change);
			printf("������ �Ϸ�Ǿ����ϴ�.\n");
			return root;
		}
		else
		{
			strcpy(root->data.add, change);
			printf("������ �Ϸ�Ǿ����ϴ�.\n");
			return root;
		}
	}
	//name�� root�� name���� ���� ��(���ڿ���)
	if (strcmp(name, root->data.name) == -1)
		return Change(root->leftChild, name, change);
	return Change(root->rightChild, name, change);
}//change


//�Ѱܹ��� name�� ���� ��带 binary search tree���� ã�� �����ϴ� �Լ�
void delete(treePointer* root, char name[])
{
	treePointer parent, child, temp;

	temp = *root;
	parent = NULL; 

	//binary search tree���� �Է¹��� name�� ã�´�
	while (temp != NULL && strcmp(temp->data.name, name) != 0)
	{
		parent = temp;
		//parent�� name�� �Է¹��� name���� ũ��(���ڿ���) 
		if (strcmp(parent->data.name, name) == 1)
			temp = parent->leftChild; //parent�� leftChild�� �̵�
		//parent�� name�� �Է¹��� name���� ������
		else
			temp = parent->rightChild; //parent�� rightChild�� �̵�
	}

	//temp�� null�̸� binary seach tree�� name�� Ʈ�� �ȿ� ����
	if (!temp)
	{
		printf("��Ͽ� �������� �ʴ� ����Դϴ�.\n");
		return;
	}

	//binary search tree�ȿ� name�� ������ ��

	//������ ��尡 leaf����϶�
	if (temp->leftChild == NULL && temp->rightChild == NULL)
	{
		// parent(�θ���)�� NULL�� �ƴ� ��, �� ������ ��尡 root�� �ƴҶ�
		if (parent) 
		{
			//parent�� leftChild�� ������ ����̸� leftChild�� NULL�� ����
			if (parent->leftChild == temp)
				parent->leftChild = NULL;
			//parent�� rightChild�� ������ ����̸� rightChild�� NULL�� ����
			else
				parent->rightChild = NULL;
		}
		//������ ��尡 root�̸� root�� NULL�� ����
		else
			*root = NULL;
	}

	//������ ����� subtree�� �ϳ��� �����Ҷ�
	else if ((temp->leftChild == NULL) || (temp->rightChild == NULL))
	{
		//������ ����� ���ʿ� subtree �ִٸ� ���� subtree�� child�� ����
		if (temp->leftChild != NULL)
			child = temp->leftChild;
		//������ ����� �����ʿ� subtree �ִٸ� ������ subtree�� child�� ����
		else
			child = temp->rightChild;

		//parent�� null�� �ƴϸ�, �� ������ ��尡 root�� �ƴϸ�
		if (parent)
		{
			//parent�� leftChild�� ������ ����̸�, parent�� leftChild�� child(subtree)�� ���δ�.
			if (parent->leftChild == temp)
				parent->leftChild = child;
			//parent�� rightChild�� ������ ����̸�, parent�� rightChild�� child(subtree)�� ���δ�.
			else
				parent->rightChild = child;
		}
		//������ ��尡 root�̸� ��Ʈ�� child�� ���δ�.
		else
			*root = child;
	}

	//������ ����� subtree�� �ΰ��϶�
	else
	{
		treePointer smallest, temp2;

		//������ ��带 smallest�� �ִ´�.
		smallest = temp;
		//������ ����� ������ subtree�� �̵��� ����
		temp2 = temp->rightChild;
		
		//������ subtree���� ���� ���� ���� ã�� ��
		//subtree�� �������� ��Ӱ��� ���� �ִ� ���� ���� ���� ��
		while (temp2->leftChild != NULL)
		{
			smallest = temp2;
			temp2 = temp2->leftChild;
		}
		//����
		if (smallest->leftChild == temp2)
			smallest->leftChild = temp2->rightChild;
		//���� ���� ��忡 ������ ��尡 ����Ǿ����� �� �����ϱ�
		else
			smallest->rightChild = temp2->rightChild;
		
		//temp�� name�� temp2�� name�� �־���
		strcpy(temp->data.name, temp2->data.name);
		temp = temp2;
	}
	printf("������ ��ҵǾ����ϴ�.\n");
}//delete