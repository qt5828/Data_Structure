#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ��� : 2020.11.14
���α׷� ��� : �ǽ����� �־��� �׷����� shortest path�� ���̸�
			   Bellman-Ford algorithm�� ����Ͽ� ���ϰ�, ����ϴ� ���α׷�
			   ��� vertex�� �׻� 0�̸�, ���� vertex�� ����ڿ��� �Է¹޾Ƽ� 
			   shortest path�� ���̸� ���Ѵ�.
*/
#include <stdio.h>
#define MAX_VERTICES 6
#define INF 1000
//adjacency matrix
int length[][MAX_VERTICES] =
{ {0,10,INF,20,INF,INF},
	{INF,0,60,INF,INF,INF},
	{INF,INF,0,INF,-30,20},
	{INF,20,INF,0,30,INF},
	{INF,INF,INF,INF,0,10},
	{INF,INF,INF,INF,INF,0} };
int dist[MAX_VERTICES] = { 0 };
int n = MAX_VERTICES;

//�Լ�����
void BellmanFord(int v);

void main()
{
	int arr;
	printf("���� vertex�� �Է��ϼ��� : ");
	scanf("%d", &arr);

	BellmanFord(arr);
	
}//main


//Bellman-Ford algorithm�� ����Ͽ� �־��� adjacency matrix�� shortest path�� ã�� ����ϴ� �Լ�
void BellmanFord(int v)
{
	int u, i, k;
	for (i = 0; i < n; i++)
		dist[i] = length[0][i];

	for (i = 1; i < n; i++) {
		for (u = 1; u != 0 && u < n; u++) {
			if (dist[u] > dist[i] + length[i][u])
				dist[u] = dist[i] + length[i][u];
		}
	}

	for (i = 0; i < n; i++) {
		for (u = 0; u != 0 && u < n; u++) {
			if (dist[u] > dist[i] + length[i][u]) {
				printf("There are negative cycle.\n");
				exit(1);
			}
		}
	}

	//shortest path���
	printf("\nVertex 0������ Vertex %d������ shortest path�� ���̴� %d�Դϴ�.\n", v, dist[v]);
}//BellmanFord