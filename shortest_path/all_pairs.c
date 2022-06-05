#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ��� : 2020.11.12
���α׷� ��� : All Pairs Shortest Path Alogithm�� ����Ͽ� �־��� graph�� adjacency matrix��
			   �� vertex�ֿ� ���� shortest path�� ã�� ������·� ����ϴ� ���α׷�
*/
#include <Stdio.h>

#define MAX_VERTICES 6
#define INF 1000
int n = MAX_VERTICES;
int cost[][MAX_VERTICES] =
{ {0,50,45,10,INF,INF },
{INF,0,10,15,INF,INF},
{INF,INF,0,INF,30,INF},
{20,INF,INF,0,15,INF},
{INF,20,35,INF,0,INF},
{INF,INF,INF,INF,3,0} };

int distance[][MAX_VERTICES] = { 0 };

//�Լ�����
void AllPairsShortestPath();
void print();

void main()
{
	AllPairsShortestPath();
	print();
}//main

//All Pairs Shortest Path Alogithm�� ����Ͽ� �־��� graph�� adjacency matrix�� 
//�� vertex�ֿ� ���� shortest path�� ã�� distance�� �����ϴ� �Լ�
void AllPairsShortestPath()
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) {
			distance[i][j] = cost[i][j];
		}
	}
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (distance[i][k] + distance[k][j] < distance[i][j])
					distance[i][j] = distance[i][k] + distance[k][j];
			}
		}
	}
}

//distance�� �迭�� ��� ���·� ����ϴ� �Լ�
//��, ��� vertex�ֿ� ���� shortest path�� ���̸� matrix���·� ��� ����ϴ� �Լ�
void print()
{
	printf("===============================\n");
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (distance[i][j] == 1000)
				printf(" * ");
			else
				printf("%2d ", distance[i][j]);
		}
		printf("\n");
	}
	printf("===============================\n");
}