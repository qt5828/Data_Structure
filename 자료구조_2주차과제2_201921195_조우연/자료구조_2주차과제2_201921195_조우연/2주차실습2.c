#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ���(������) : 2020.09.18
���α׷� ��� : �������� ������ȯ�ڸ� �����ϴ� ���α׷�
				'��������','��������','��������'
				����ڰ� �� �� ���� �� �ϳ��� �����ϸ�, '��������'�� ���ý� ����ڰ�
				���ϸ� ����� ����� ���ְ�, '��������'�� ���ý� ����� �� ���ᰡ ��������
				ȯ���� �̸��� ����ϰ�, '��������'�� ���ý� ���α׷��� �����ϴ� ���α׷��̴�.
				�� ������� ���� 6������ ���ѵȴ�.
*/
#include <stdio.h>

//ȯ���� �̸������� �����ϴ� ����ü
typedef struct {
	char name[10]; //�̸��ִ���� 9
} patient;

//����ڸ���� ������ queue, circular queue���·� ����� ����
patient queue[7];

int front = 0; rear = 0;

void addq(patient item);
patient deleteq();
int queueFull();
int queueEmpty();
void main()
{
	int answer;
	printf("\n�Է´��\n");
	printf("1. ���� ����\n2. ���� ����\n3. ���� ����\n");
	scanf("%d", &answer);

	//����ڰ� '��������'(3)�� �����Ҷ����� ����
	while (answer != 3) {
		//�������� ����
		if (answer == 1)
		{
			//����ڸ���� ������ �ʾ��� �� ����
			if (queueFull() == 1) {
				int ans1;
				printf("\n1. ����� ���\n2. ���\n");
				scanf("%d", &ans1);
				//����ڰ� ����� ����� ���Ҷ� ����
				if (ans1 == 1)
				{
					patient person;
					printf("�̸� �Է� : ");
					scanf("%s", person.name);
					addq(person);
				}
			}
		}
		//�������� ����
		else if (answer == 2)
		{
			//������� ȯ�ڰ� �ִٸ� ����
			if(queueEmpty())
				printf("ȯ�� : %s\n\n", deleteq().name);
		}
		//'��������','��������','��������'�� �ƴ� �ٸ� ���� �Է����� ���� ����ó��
		else
		{
			printf("�߸��� ���� �Է��Ͽ����ϴ�. 1,2,3�߿� �Է��ϼ���.\n");
		}
		printf("\n�Է´��\n");
		printf("1. ���� ����\n2. ���� ����\n3. ���� ����\n");
		scanf("%d", &answer);
	}
	printf("\n���񽺸� �����մϴ�.\n");
}

//ť�� ��(����ڸ��)�� �����ϴ� �Լ�
void addq(patient item)
{
	rear = (rear + 1) % 7;
	queue[rear] = item;
}

//ť�� �Էµ� ������� ���� ��ȯ�ϰ� �����ϴ� �Լ�
patient deleteq()
{
	if (front == rear)
		queueEmpty();
	front = (front + 1) % 7;
	return queue[front];
}

//ť�� ����������, ����ڸ���� ��á���� �˸��� ������ ����ϴ� �Լ�
int queueFull()
{
	if ((front - rear == 1) || (rear - front == 6))
		printf("Service is not availanle\n");
	else
		return 1;
}

//ť�� ������� ��, ����ڰ� ������ �˸��� ������ ����ϴ� �Լ�
int queueEmpty()
{
	if (front == rear) {
		printf("There is no patient waiting\n");
		return 0;
	}
	return 1;
}


