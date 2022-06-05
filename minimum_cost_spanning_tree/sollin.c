#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ��� : 2020.11.15
���α׷� ��� : Sollin�� algorithm�� �̿��Ͽ� �ǽ����� �־��� graph�� minimum cost spanning tree��
			   �����ϰ� ����ϴ� ���α׷�
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
//������ rootã�� ���� parent
int parent[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };

//edge�� ������ ���� ����ü
typedef struct edge {
	int vertex1;
	int vertex2;
	int cost;
}edge;

//�Լ�����
void Sollin();
void Union(int i, int j);
int Find(int i);

void main()
{
	printf("Sollin's algorithm�� �̿��� minimum cost spanning tree ���� : \n");
	Sollin();
}//main



//Sollin's algorithm�� �̿��Ͽ� minimum cost spanning tree�� �����Ͽ� ����ϴ� �Լ�.
void Sollin()
{
	int i, j, k, n = 0, TF;
	int count = 0;
	int visited[MAX_VERTICES] = { 0 };
	edge T[MAX_VERTICES - 1];
	edge min;

	//edge���� ���� T�� ���ҵ��� cost�� 1000���� ����
	//������ ������ ���� ����
	for (i = 0; i < MAX_VERTICES - 1; i++)
		T[i].cost = 1000;

	//first stage
	while (i < MAX_VERTICES)
	{
		for (i = 0; i < MAX_VERTICES; i++)
		{
			TF = 1;
			min.cost = INT_MAX;
			visited[i] = 1; //�湮�� vertex�� visited 1�� ����
			for (j = 0; j < MAX_VERTICES; j++)
			{
				//�� vertex�� ���� minimum cost�� ������ edgeã��
				if (min.cost > cost[i][j])
				{
					min.cost = cost[i][j];
					min.vertex1 = i;
					min.vertex2 = j;
				}
			}

			//������ ã�� minimum cost�� ���� edge�� �ߺ��Ǵ°��� ���ܽ�Ŵ
			for (k = 0; k < 6; k++)
			{
				if (T[k].vertex1 == min.vertex2)
					if (T[k].vertex2 == min.vertex1)
						TF = 0;
			}
			//�� vertex�� ���� minimum cost�� ������ edge���� ���� T�� �����Ѵ�.
			if (TF) {
				T[n++] = min;
				count++;
			}
		}
	}

	printf("T = {");
	//first stage���� ã�� minimum cost spanning subtree�� edge���� ���
	for (j = 0; j < count; j++)
	{
		printf("(%d,%d) ", T[j].vertex1, T[j].vertex2);
		Union(T[j].vertex1, T[j].vertex2);
	}

	//second stage
	edge forest[MAX_VERTICES][MAX_VERTICES]; //forest���� ����
	edge forest2[MAX_VERTICES][MAX_VERTICES]; //forest���� �� ����ϰ� ����(�� forest�� �߰��߰� �����Ⱚ�� ����ִ� ���ҵ��� �������)
	edge MINT; //cost�� �ּڰ��� ���� edge����
	int MIN = INT_MAX;
	int a, b, c, d, e, f, g;
	a = b = c = d = e = f = g = 0;

	//forest�� forest2�� ��� ���ҵ��� cost���� 1000���� ����
	for (i = 0; i < MAX_VERTICES; i++)
	{
		for (j = 0; j < MAX_VERTICES; j++) {
			forest[i][j].cost = 1000;
			forest2[i][j].cost = 1000;
		}
	}

	//���� ���տ� �ִ� edge���� ã�� ������ ��ġ�� ����
	//ex) 0�� root�� �ϴ� vertex�� ����ִ� edge���� forest[0]�� ����,
	//ex) 1�� root�� �ϴ� vertex�� ����ִ� edge���� forest[1]�� ����
	for (i = 0; T[i].cost != 1000; i++) {
		switch (Find(T[i].vertex1))
		{
		case 0:
			forest[0][a++] = T[i];
			break;
		case 1:
			forest[1][b++] = T[i];
			break;
		case 2:
			forest[2][c++] = T[i];
			break;
		case 3:
			forest[3][d++] = T[i];
			break;
		case 4:
			forest[4][e++] = T[i];
			break;
		case 5:
			forest[5][f++] = T[i];
			break;
		case 6:
			forest[6][g++] = T[i];
			break;
		}
	}

	//forest[0]~forest[6]���� �� ����ִ� ���� ������ ���� edge�� ����ִ� ����
	//forest2[0]���� ���ʴ�� ����(forest�� forest2�� ����ϰ� ����)
	k = 0;
	for (i = 0; i < MAX_VERTICES; i++) {
		if (forest[i][0].cost != 1000) { //forest[i][0].cost�� 1000�̸� �� ���� �������
			for (j = 0; forest[i][j].cost != 1000; j++) {
				forest2[k][j] = forest[i][j];
			}
			k++;
		}
	}

	//�� forest2[i]���� minimum cost spaaning subtree�� �̷�� edge���� ��������Ƿ�,
	//�� forest�� vertex�� ������ cost�� ���� ���� ���� ���� ������ edge�� MINT�� ����
	for (i = 0; forest2[0][i].cost != 1000; i++) {
		for (j = 0; forest2[1][j].cost != 1000; j++)
			if (MIN > cost[forest2[0][i].vertex1][forest2[1][j].vertex1]) {
				MIN = cost[forest2[0][i].vertex1][forest2[1][j].vertex1];
				MINT.vertex1 = forest2[0][i].vertex1;
				MINT.vertex2 = forest2[1][j].vertex1;
				MINT.cost = MIN;
			}
	}
	//�̹� ������� subtree�� edge���� �����ϰ� ���� edge�� ���� ���� cost�� ���� edge�� ã�Ƽ� MINT�� ���������Ƿ�,
	//MINT�� ���� �� subtree�� �������ָ� minimum cost spanning tree����
	printf("(%d,%d)}\n ", MINT.vertex1, MINT.vertex2);

}//Sollin

//i�� root�� j�� ����� �Լ�
void Union(int i, int j)
{
	//i�� root�� j�� ����
	parent[i] = j;
}//Union

//i�� root�� ã�� �Լ�
int Find(int i)
{
	for (; parent[i] >= 0; i = parent[i]);
	return i;
}//Find
