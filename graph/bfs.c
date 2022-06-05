#define _CRT_SECURE_NO_WARNINGS
/* 
�ۼ��� : ���쿬
�ۼ���(������) : 2020.10.30
���α׷� ��� : ������ �־��� adjacency list�� ǥ���� undirected graph�� BFS��
			   traversal�� ����� ����ϴ� ���α׷�.
*/
#include <stdio.h>

typedef struct node* queuePointer;
typedef struct node {
	char vertex;
	queuePointer link;
}node;
//adjacency list�� �ִ� ��� �� : 7��
//��带 �湮�ߴ��� Ȯ���ϱ� ���� �迭
short int visited[7];
//�׷����� ǥ��
queuePointer graph[7];
int front, rear;
//char�� queue
char queue[7];

//�Լ�����
void creat(queuePointer* root, char val);
void bfs(int v);
void addq(char item);
char deleteq();
int queueFull();
int queueEmpty();

void main()
{
	//adjacency list�� �������� �׷��� ����
	creat(&graph[0], 'A');
	creat(&graph[0], 'B');
	creat(&graph[0], 'C');
	creat(&graph[1], 'B');
	creat(&graph[1], 'A');
	creat(&graph[1], 'D');
	creat(&graph[1], 'E');
	creat(&graph[2], 'C');
	creat(&graph[2], 'A');
	creat(&graph[2], 'E');
	creat(&graph[3], 'D');
	creat(&graph[3], 'B');
	creat(&graph[3], 'G');
	creat(&graph[4], 'E');
	creat(&graph[4], 'B');
	creat(&graph[4], 'C');
	creat(&graph[4], 'G');
	creat(&graph[5], 'F');
	creat(&graph[5], 'G');
	creat(&graph[6], 'G');
	creat(&graph[6], 'D');
	creat(&graph[6], 'E');
	creat(&graph[6], 'F');

	//BTS������� ��ȸ
	printf("Breadth First Search�� ��� : ");
	bfs('A');
	printf("\n");
}//main


//BFS������� �׷����� ��ȸ�Ͽ� �� ��带 ����ϴ� �Լ�
void bfs(int v)
{
	queuePointer w;
	front = rear = -1;

	//���ĺ� ������� �׷����� ��尡 �߰��Ǿ������Ƿ�,
	//���ĺ��� ���� �˸��� �ε�����ȣ�� �ο��ϱ� ���� ����ġ��
	int n;
	switch (v)
	{
	case 65:
		n = 0;
		break;
	case 66:
		n = 1;
		break;
	case 67:
		n = 2;
		break;
	case 68:
		n = 3;
		break;
	case 69:
		n = 4;
		break;
	case 70:
		n = 5;
		break;
	case 71:
		n = 6;
		break;
	}

	//�湮�� ���� 1�� ����
	visited[n] = 1;
	//ť�� �湮�� ����� ��(���ĺ�)�߰�
	addq(v);
	//ť�� �������� �ݺ�
	while (!queueEmpty()) {
		//�湮�� adjacency list�� ��带 ť���� �����ϰ� ������ ����� ��� ������ ���
		v = deleteq();
		switch (v)
		{
		case 65:
			n = 0;
			break;
		case 66:
			n = 1;
			break;
		case 67:
			n = 2;
			break;
		case 68:
			n = 3;
			break;
		case 69:
			n = 4;
			break;
		case 70:
			n = 5;
			break;
		case 71:
			n = 6;
			break;
		}
		w = graph[n];
		//������ ���� adjacent�� ������ ��� ���
		for (w; w; w = w->link)
			if (!visited[w->vertex]) {
				printf("%c ", w->vertex);
				addq(w->vertex);
				visited[w->vertex] = 1;
			}
	}
}//bfs

//ť�� ���� ���� �߰��ϴ� �Լ�(ť�� ���Ҵ� char���̴�)
void addq(char item)
{
	if (rear == 6)
		queueFull();
	queue[++rear] = item;
}//addq

//ť�� �� ó������ �����ϰ� �� ���� ��ȯ�ϴ� �Լ�
char deleteq()
{
	if (front == rear)
		return queueEmpty();
	return queue[++front];
}//deleteq

//ť�� ��á���� Ȯ���ϴ� �Լ�
//��á���� 1 �ƴϸ� 0 ��ȯ
int queueFull()
{
	if ((front - rear == 1) || (rear - front == 6))
		return 1;
	else
		return 0;
}//queueFull

//ť�� ������� Ȯ���ϴ� �Լ�
//������� 1 �ƴϸ� 0 ��ȯ
int queueEmpty()
{
	if (front == rear) {
		return 1;
	}
	return 0;
}//queueEmpty

//�׷����� ����� �Լ�
//adjacency list������ �׷����� �����.
void creat(queuePointer* root, char val)
{
	//graph[i]�� null�϶�(����)
	if (!(*root))
	{
		(*root) = (queuePointer)malloc(sizeof(node));
		(*root)->vertex = val;
		(*root)->link = NULL;
	}
	//graph[i]�� ���� ������(�߰�)
	else
	{
		queuePointer ptr;
		ptr = (queuePointer)malloc(sizeof(node));
		ptr->vertex = val; ptr->link = NULL;

		queuePointer temp;
		for (temp = *root; temp->link;)
			temp = temp->link;
		temp->link = ptr;
	}
}//creat