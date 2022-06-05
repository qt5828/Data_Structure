#define _CRT_SECURE_NO_WARNINGS
/* 
�ۼ��� : ���쿬
�ۼ��� : 2020.11.06
���α׷� ��� : Prim�� algorithm�� �̿��Ͽ� �ǽ����� �־��� graph�� minimum cost spanning tree��
			   �����ϴ� ���α׷�. 0�� vertex���� �����ϴ� minimum cost spanning tree�� �����Ѵ�.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 7
//adjacent matrix
int cost[][MAX_VERTICES] =
{ {1000,3,17,6,1000,1000,1000},
{3,1000,1000,5,1000,1000,12},
{17,1000,1000,1000,10,8,1000},
{6,5,1000,1000,9,1000,1000},
{1000,1000,10,9,1000,4,2},
{1000,1000,8,1000,4,1000,14},
{1000,12,1000,1000,2,14,1000} };

//edge�� ������ ���� ����ü
typedef struct edge {
	int vertex1;
	int vertex2;
	int cost;
}edge;

//�Լ�����
void Prim(int v);

void main()
{
	printf("Prim's algorithm�� �̿��� minimum cost spanning tree ���� : \n");
	Prim(0);
}//main

//Prim's algorithm�� �̿��Ͽ� parameter�� �־��� vertex�� ���������ϴ� minimum cost spanning tree�� �����Ͽ� ����ϴ� �Լ�.
void Prim(int v)
{
	int i, j, k, n = 0; //n�� �湮�� vertex�� ����-1
	int count = 0; //edge��
	//�湮�� vertex���� Ȯ���ϱ� ���� visited, �湮�� 1, �ƴϸ� 0
	int visited[MAX_VERTICES] = { 0 };
	//�湮�� vertex����
	int TV[MAX_VERTICES];

	//�湮�� vertex��� ������ edge�߿��� minimum cost�� ���� vertex�� cost�� ������ �����ϱ� ���� ����
	edge min;

	//TV�� ���Ҵ� 1000���� �ʱ�ȭ
	//TV�� ����� ���ҵ��� ������ �˱� ����
	for (i = 0; i < MAX_VERTICES; i++)
		TV[i] = 1000;
	
	printf("T = { ");

	//TV�� ù��° �ڸ��� ó�� �湮�� vertex �߰�
	TV[n] = v;
	//�湮�����Ƿ� 1�� ����
	visited[v] = 1;

	//edge���� vertex����-1 �ɶ����� �ݺ�
	while (count < MAX_VERTICES - 1)
	{
		//min�� cost���� ���� ū ���� �ʱ�ȭ
		min.cost = INT_MAX;
		//TV�� �ִ� vertex��� ������ �͵��� cost min ã��
		for (j = 0; TV[j] != 1000; j++)
		{
			for (k = 0; k < MAX_VERTICES; k++) {
				//�̹� �湮�� vertex��� �ߺ����� ����
				if (visited[k] == 1) {
					continue;
				}
				//min.cost���� ���� cost���� ������ �ִ� edge�� min.cost�� �ٲ�
				//�̿� ���� vertex�� ������ cost.vertex�� ����
				if (min.cost > cost[TV[j]][k]) {
					min.cost = cost[TV[j]][k];
					min.vertex1 = TV[j];
					min.vertex2 = k;
				}
			}
		}
		//TV�� �ִ� vertex��� ������ �͵� �� ���� ���� cost�� ���� vertex�� TV�� �߰��ϰ�, �� vertex�� �湮�������� ����
		TV[++n] = min.vertex2;
		visited[min.vertex2] = 1;

		//ã�� minimum cost edge�� ���
		printf("(%d,%d) ", min.vertex1, min.vertex2);
		count++;
	}

	printf("}\n");
	//TV�� ���� ���
	printf("TV = { ");
	for (i = 0; i < MAX_VERTICES; i++)
		printf("%d ", TV[i]);
	printf("}\n");

	//count�� 6(�� n-1)�� �ƴϸ� spanning tree�� �ƴϴ�.
	if (count != MAX_VERTICES - 1)
		printf("no spanning tree\n");
}//Prim