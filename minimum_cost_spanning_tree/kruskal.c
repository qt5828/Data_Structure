#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� :  ���쿬
�ۼ��� :  2020.10.31
���α׷� ��� : 9�����ǽ����������� �־��� graph�� ���� minimum cost spanning tree
			   �� �����ϴ� ���α׷�. Kruskal's algorithm�� ����Ѵ�.
*/
#include <stdio.h>

#define MAX_SIZE 12 //�� edge�� ��+1
#define HEAP_FULL(n) (n==MAX_SIZE-1)
#define HEAP_EMPTY(n) (!n)

//�� ���Ұ� ����Ǳ� ������ ��� root�̹Ƿ� -1�� �ʱ�ȭ
int parent[8] = { -1,-1,-1,-1,-1,-1,-1,-1};

//edge�� ������ ���� ����ü
typedef struct edge {
	int vertex1;
	int vertex2;
	int cost;
}edge;

edge heap[MAX_SIZE];
int n = 0; //heapũ��

//�Լ�����
int Kruskal();
void push(int ver1, int ver2, int cost);
edge pop();
void Union(int i, int j);
int Find(int i);
int check(int i, int j);

void main()
{
	printf("\nKruska's algorithm�� �̿��� minimum cost spanning tree ���� :  T = { ");
	Kruskal();
	printf("}\n\n");
}//main

//Kruskal�� algorithm������� Minimum cost spanning tree�� �����ϴ� �Լ�
int Kruskal()
{
	//�� edge�� ���� ������ minheap�� �����Ѵ�. (cost�� ��������)
	push(0, 1, 3);
	push(0, 3, 6);
	push(0, 2, 17);
	push(1, 3, 5);
	push(1, 6, 12);
	push(2, 4, 10);
	push(2, 5, 8);
	push(3, 4, 9);
	push(4, 5, 4);
	push(4, 6, 2);
	push(5, 6, 14);

	//�߰��� edge�� ������ ���� count
	int count = 0;
	edge e;
	while (count < 6)
	{
		//cost�� �ּ��� edge�� minheap���� �����ϰ� e�� ����
		e = pop();
		int n1, n2;
		//e�� �� ���� ���� set�� �����ִ��� Ȯ��
		//�� cycle�� �̷���� Ȯ��

		if (!check(e.vertex1, e.vertex2))
		{
			//edge�� ���
			printf("(%d,%d) ", e.vertex1, e.vertex2);
			count++;
			//�� ���� union�Ѵ�.->������ ���� set�ȿ� �ְԵ�
			Union(e.vertex1, e.vertex2);
		}
	}

	//count�� 6(�� n-1)�� �ƴϸ� spanning tree�� �ƴϴ�.
	if (count != 6)
		printf("no spanning tree\n");
}//Kruskal

//edge�� ���� ����(��1, ��2, ���)�� �̿��� minheap�� edge�� �߰�(cost�� �������� �߰���)
void push(int ver1, int ver2, int cost)
{
	edge Edge;
	Edge.vertex1 = ver1;
	Edge.vertex2 = ver2;
	Edge.cost = cost;
	int i;
	if (HEAP_FULL(n)) {
		fprintf(stderr, "The heap is full. ");
		exit(1);
	}
	i = ++(n);
	while ((i != 1) && (Edge.cost < heap[i / 2].cost)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = Edge;
}//push

//minheap���� cost�� �ּ��� ���(�� root)�� ���� �� �� ���� ��ȯ
edge pop()
{
	int parent, child;
	edge item, temp;
	if (HEAP_EMPTY(n)) {
		fprintf(stderr, "The heap is empty ");
		exit(2);
	}
	item = heap[1];
	temp = heap[(n)--];
	parent = 1;
	child = 2;

	while (child <= n)
	{
		if ((child < n) && heap[child].cost > heap[child + 1].cost)
			child++;
		if (temp.cost <= heap[child].cost)
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}//pop

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

//�� �� i,j�� ���� ���տ� ���ԵǾ��ִ����� �Ǵ��ϰ� �̿� ���� �Ǵܰ���� ����ϴ� �Լ�
//���� ���տ� ������ 1, �ƴϸ� 0 ��ȯ
int check(int i, int j)
{
	//i�� j�� root�� ������ ����
	if (Find(i) == Find(j))
		return 1;
	//i�� j�� root�� �ٸ��� ����
	else
		return 0;
}//check