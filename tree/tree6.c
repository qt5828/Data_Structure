#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� :  ���쿬
�ۼ���(������) : 2020.10.06
���α׷� ��� : �Ϸ翡 �ݵ�� �ؾ��� �ϰ� �ҿ�ð��� ����� �켱����ť�� �����ϴ� ���α׷�.
			   �켱���� ť�� MAX heap�� ����,������ �����Ǹ�, ����Ҷ��� �ҿ�ð��� ����
			   �� ���� ���� ����Ѵ�. ������ ���α׷� ���������� ������� �ʾ����Ƿ�, ����ڰ�
			   ����� �����ϸ� ���ϸ���� ����ϰ� �����ϰԲ� �����Ͽ���. ���� ���� ����ִµ�
			   ������ �����ϰų�, ���� �����ִµ� ������ �����ϸ� �����޼����� ����ϰ� ���α׷���
			   �����Ѵ�.
*/

#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 11
#define HEAP_FULL(n) (n==MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)
typedef struct {
	int key;
	char work[15];
}element;
element heap[MAX_ELEMENTS];
int n = 0;

//�Լ�����
void push(element item, int* n);
void delete(int* n);
element pop(int* n);
void main()
{
	//����ڰ� ����,����,��� �� ����� �������� ������ ����
	char ans[2];
	//����ڰ� �Է��� ������ ����� �����ϴ� �迭
	element save[10];
	int i = 0;

	//������ ���α׷� ���Ḧ ���� �������� �ʾ����Ƿ�, ����� �ϸ� ���α׷��� ����ǰ� ������.
	printf("����� �����ϸ� ����ϰ� ���α׷��� �����մϴ�.");
	while (1)
	{
		printf("\n����(i), ����(d), ���(p) : ");
		scanf("%s", ans);
		
		//������ ����
		if (ans[0] == 'i')
		{
			//���� ���������� �����޼��� ��� ��, ���α׷� ����
			if (HEAP_FULL(n)) {
				fprintf(stderr, "The heap is full. ");
				exit(1);
			}
			//����ڿ��� ���ϰ� �ҿ�ð��� �Է¹޴´�
			printf("�ؾ��� �� : ");
			scanf("%s", &save[i].work);
			printf("�ҿ�ð�(����:��) : ");
			scanf("%d", &save[i].key);

			//�Է¹��� ���ϰ� �ҿ�ð��� MAX���� ����
			push(save[i], &n);
			i++;
		}

		//������ ����
		else if (ans[0] == 'd')
		{
			//����(����ڿ��� �Է¹��� ���� ����-> �Է��� delete�Լ��ȿ��� ����)
			delete(&n);
		}

		//����� ����
		else if (ans[0] == 'p')
		{
			//���� ũ�⸸ŭ ����ϱ� ����
			int size = n;
			for (i = 1; i <=size ; i++) {
				//�ƽ����� ��Ʈ(���� 1���ε���, �� �ִ�)���� �����Ǹ� ���� ����������� ������ ���� ���ʷ� ���
				//�� ���� ���� ū ������ ���ʷ� ��µ�
				element res = pop(&n); 
				printf("%s-%d��\n", res.work, res.key);
			}
			//��� �� ���α׷� ����
			return;
		}

		//�߸��� ���� �Է¹޾��� ��
		else {
			printf("�߸��� ���� �Է��Ͽ����ϴ�.\n");
		}
	}
}//main


//�ƽ����� ���ο� ���� �����ϴ� �Լ�.
//���ο� ���� ���Ե� ���� �ƽ����� ���¸� ������.
void push(element item, int* n) {
	int i;
	i = ++(*n);
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}//push


//�ƽ������� ����ڰ� �Է��� ���� ã�� �����ϴ� �Լ�
//������ ����� ���� �ƽ������¸� ������.
void delete(int* n) {

	//���� ��������� �����޼��� ��� �� ���α׷� ����
	if (HEAP_EMPTY(*n)) {
		fprintf(stderr, "The heap is empty");
		exit(1);
	}

	//����ڿ��� ������ ������ �Է¹޴´�.
	char del[10];
	printf("������ �� : ");
	scanf("%s", del);

	int parent, child;
	element item, temp;

	//������ ���� �ε����� ã�� parent�� �����Ѵ�.
	int check = 1;
	for (int i = 1; i <= *n; i++) {
		if (!(check = strcmp(heap[i].work, del)))
		{
			parent = i;
				child = 2 * i;
				break;
		}
	}

	//���� ������ ���� ���� �������� �ʴ´ٸ�, �����޼��� ��� ��, �����ܰ�� ���ư�
	if (check != 0) {
		printf("�������� �ʴ� �� �� �Դϴ�.\n");
		return;
	}
	item = heap[parent];
	temp = heap[(*n)--];

	while (child <= *n) {
		if ((child < *n) && (heap[child].key < heap[child + 1].key))
			child++;
		if (temp.key >= heap[child].key)
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	for (int i = 0; del[i] != NULL; i++)
		printf("%c", del[i]);
	printf("�� ������\n");
}//delete

//�ƽ����� ��Ʈ(���� ū ��)�� �����ϰ� �� ���� ��ȯ�ϴ� �Լ�
element pop(int* n)
{
	int parent, child;
	element item, temp;
	if (HEAP_EMPTY(*n)) {
		fprintf(stderr, "The heap is empty");
		exit(1);
	}
	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	while (child <= *n)
	{
		if ((child < *n) && (heap[child].key < heap[child + 1].key))
			child++;
		if (temp.key >= heap[child].key)
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}//pop