#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ��� : 2020.11.06
���α׷� ��� : Dijkstra Algorithm�� ����Ͽ� shortest path�� ã�� ���α׷�.
			   ��� vertex�� A�̸�, ���� vertex�� ����ڿ��� �Է¹޾� �����Ѵ�.
			   A�κ��� ����Ͽ� ������ ���� vertex������ �ִ� �Ÿ� ��ο� �׶���
			   �ִ� �Ÿ��� ��µǵ��� �Ѵ�.
*/
#include <stdio.h>
#include <stdlib.h>

//adjaceny matrix
#define MAX_VERTICES 7
int cost[][MAX_VERTICES] =
{ {0,10,7,1000,15,1000,1000},
	{10,0,1000,5,8,1000,1000},
	{7,1000,0,1000,6,1000,1000},
	{1000,5,1000,0,12,6,1000},
	{15,8,6,12,0,1000,3},
	{1000,1000,1000,6,1000,0,1},
	{1000,1000,1000,1000,3,1,0} };
//array of best estimates of shortest path to each vertex
int distance[MAX_VERTICES];
//check to visited
short int found[MAX_VERTICES];
int n = MAX_VERTICES;
//index of an array of predecessors for each vertex
int PI[MAX_VERTICES] = { 0 };

//�Լ�����
void Dijkstra(char v);
int choose();
void print(char v, char m);

void main()
{
	//����ڿ��� ��������� ���������� �Է¹���
	//A~E������ ���ĺ��� �Է��Ѵٰ� �����Ѵ�.
	//��������� �׻� A��� ����
	char start, end;
	printf("��������� �Է��ϼ��� : ");
	scanf("%c", &start);
	printf("���������� �Է��ϼ��� : ");
	scanf(" %c", &end);

	//Dijkstra algorithm������� �ִܰŸ���ο� �ִܰŸ��� ã�� ���
	Dijkstra(start, end);
}//main

//�������� v�� �������� m�� �Է¹޾� Dijkstra algorithm������� �� ���� ������ 
//�ִܰŸ���ο� �ִܰŸ��� ã�� ����ϴ� �Լ�
//���ǳ�Ʈ�� �ҽ�������
void Dijkstra(char v, char m)
{
	int i, u, w;
	for (i = 0; i < n; i++)
	{
		found[i] = 0;
		distance[i] = cost[v - 65][i]; //v�� char���̹Ƿ� �������� �����ϰ� ����(A=0,B=1,...)
	}
	found[v - 65] = 1; distance[v - 65] = 0;

	for (i = 0; i < n - 1; i++)
	{
		u = choose();
		found[u] = 1;
		for (w = 0; w < n; w++)
			if (!found[w])
				if (distance[u] + cost[u][w] < distance[w]) {
					distance[w] = distance[u] + cost[u][w];
					//predecessor�� index�� ����
					PI[w] = u;
				}
	}
	//�ִܰ�ο� �ִܰŸ� ���
	print(v, m);

}//Dijkstra


//Dijkstra������� ã�� �ִܰ�ο� �ִܰŸ��� ����ϴ� �Լ�
void print(char v, char m)
{
	int i, j = 0;
	//�ִܰ�θ� �����ϱ� ���� array
	int ver[MAX_VERTICES];

	//���������� predecessor�� �ε������� ��������� �ε������� ���ʷ� ã�� ver�� ����
	for (i = m - 65; i != v - 65;)
	{
		ver[j++] = i + 65;
		i = PI[i];
	}

	//�ִܰ�� ���
	printf("Vertex %c���� Vertex %c���� ���� �ִ� ��δ� ", v, m);
	ver[j++] = i + 65;
	for (j = j - 1; j >= 0; j--)
		printf("%c ", ver[j]);
	
	//�ִܰŸ� ���
	printf("�̸�, �̶� �ִ� �Ÿ��� ");
	printf("%d�Դϴ�.\n ", distance[m - 65]);

}//print

//���� �湮���� ���� vertex�߿��� �ִܰŸ��� vertex�� ã�� ��ġ�� ��ȯ�ϴ� �Լ�
int choose()
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}//choose
