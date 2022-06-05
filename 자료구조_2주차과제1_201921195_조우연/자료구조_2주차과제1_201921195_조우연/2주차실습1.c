#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
�ۼ��� : ���쿬
�ۼ���(������ ������) : 2020.09.17
���α׷� ���� : �Է����� ��ȣ���� ¦�� �´��� Ȯ���ϴ� ���α׷�
			   ����ڰ� q�� �Է��Ҷ����� ��ӽ����Ѵ�.
			   ��, ��ȣ�� �ƴ� ���ڿ��� �Էµǰų�, 50�� �̻��� ���ڿ���
			   �ԷµǸ� �����޼����� ����ϰ� ���α׷��� �����Ѵ�.
*/
int top = -1;
char stack[51]; //���ÿ� �� �� �ִ� �ִ� ���ڼ� : 50

void push(char input);
char pop();
int stackEmpty();
void stackFull();
int check(char input[]);
void main()
{
	char input[51];
	
	//q�� �Էµɶ����� ���α׷��� ����
	while (1)
	{
		top = -1;
		printf("input string (q�Է½� ����)\n");
		scanf("%s", input);
		if (input[0] == 'q')
			return;
		check(input); //input���� ���� ��ȣ�� ¦�� �´��� Ȯ��
	}
}

//������ top�� ���� �����ϴ� �Լ�
void push(char input)
{
	if (top >= 50)
	{
		stackFull();
		return;
	}
	stack[++top] = input;
}

//������ top�� ���� ��ȯ�ϰ� �����ϴ� �Լ�
char pop()
{
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}

//������ ����ִ��� Ȯ���ϴ� �Լ�
int stackEmpty()
{
	if (top == -1)
		return 1;

	return 0;
}

//������ ��á���� Ȯ���ϴ� �Լ�
//������ ��á����, ���α׷��� �����Ѵ�.
void stackFull()
{
	if (top >= 50)
	{
		printf("������ ��á���ϴ�. ���α׷��� �����մϴ�.\n");
		exit();
	}
}

//�Է����� �־��� ���ڿ�(��ȣ��)�� ¦�� �̷���� Ȯ���ϴ� �Լ�
int check(char input[])
{
	int i;
	for (i = 0; input[i] != 0; i++)
	{
		if (((input[i] == '(') || (input[i] == '[')) || (input[i] == '{'))
			push(input[i]);
		else
		{
			if (input[i] == ')')
			{
				if (stack[top] == '(')
					pop();
				else
				{
					printf("The string is unbalanced.\n\n");
					return 0;
				}
			}
			else if (input[i] == ']')
			{
				if (stack[top] == '[')
					pop();
				else
				{
					printf("The string is unbalanced.\n\n");
					return 0;
				}
			}
			else if (input[i] == '}')
			{
				if (stack[top] == '{')
					pop();
				else
				{
					printf("The string is unbalanced.\n\n");
					return 0;
				}
			}
			//��ȣ�� �ƴ� ���ڿ��� �ԷµǾ�����, ���α׷� ����
			else
			{
				printf("�߸��� ���� �Է��߽��ϴ�.(��ȣ�� �Է°����մϴ�.)\n���α׷��� �����մϴ�.\n ");
				exit(2);
			}
		}
	}
	//������ ������� ������, ��ȣ�� ¦�� ���� ����
	if (!stackEmpty())
	{
		printf("The string is unbalanced.\n\n");
		return 0;
	}
	else
		printf("The string is balanced.\n\n");
}
