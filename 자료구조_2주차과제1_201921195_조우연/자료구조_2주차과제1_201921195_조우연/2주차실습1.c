#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
작성자 : 조우연
작성일(마지막 수정일) : 2020.09.17
프로그램 설명 : 입력으로 괄호들의 짝이 맞는지 확인하는 프로그램
			   사용자가 q를 입력할때까지 계속실행한다.
			   단, 괄호가 아닌 문자열이 입력되거나, 50개 이상의 문자열이
			   입력되면 에러메세지를 출력하고 프로그램을 종료한다.
*/
int top = -1;
char stack[51]; //스택에 들어갈 수 있는 최대 문자수 : 50

void push(char input);
char pop();
int stackEmpty();
void stackFull();
int check(char input[]);
void main()
{
	char input[51];
	
	//q가 입력될때까지 프로그램을 실행
	while (1)
	{
		top = -1;
		printf("input string (q입력시 종료)\n");
		scanf("%s", input);
		if (input[0] == 'q')
			return;
		check(input); //input으로 들어온 괄호의 짝이 맞는지 확인
	}
}

//스택의 top에 값을 삽입하는 함수
void push(char input)
{
	if (top >= 50)
	{
		stackFull();
		return;
	}
	stack[++top] = input;
}

//스택의 top의 값을 반환하고 삭제하는 함수
char pop()
{
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}

//스택이 비어있는지 확인하는 함수
int stackEmpty()
{
	if (top == -1)
		return 1;

	return 0;
}

//스택이 꽉찼는지 확인하는 함수
//스택이 꽉찼을시, 프로그램을 종료한다.
void stackFull()
{
	if (top >= 50)
	{
		printf("스택이 꽉찼습니다. 프로그램을 종료합니다.\n");
		exit();
	}
}

//입력으로 주어진 문자열(괄호들)이 짝을 이뤘는지 확인하는 함수
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
			//괄호가 아닌 문자열이 입력되었을때, 프로그램 종료
			else
			{
				printf("잘못된 값을 입력했습니다.(괄호만 입력가능합니다.)\n프로그램을 종료합니다.\n ");
				exit(2);
			}
		}
	}
	//스택이 비어있지 않으면, 괄호의 짝이 맞지 않음
	if (!stackEmpty())
	{
		printf("The string is unbalanced.\n\n");
		return 0;
	}
	else
		printf("The string is balanced.\n\n");
}
