#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ��� : 2020.11.26
���α׷� ��� : Heap sort algorithm�� �̿��Ͽ� �־��� �����Ϳ� ���� ������������ �����ϴ� ���α׷�
*/
#include <Stdio.h>

//�Լ�����
void adjust(int list[], int root, int n);
void heapsort(int list[], int n);

void main()
{
	int a[] = { 1,300,200,104,101,91,88,60,15,31,12,26,82,51,6 };

	//������ ������ ���
	printf("������ ������ : ");
	for (int i = 0; i < 15; i++)
		printf("%d ", a[i]);
	printf("\n\n");

	//������ ������ merge sort ����
	heapsort(a, 14);

	//���ĵ� ������ ���
	printf("Heap Sort : ");
	for (int i = 0; i < 15; i++)
		printf("%d ", a[i]);
	printf("\n");
}//main

//max heap�� ����� �Լ�
void adjust(int list[], int root, int n)
{
	int child, rootkey;
	int temp;
	temp = list[root];
	rootkey = list[root];
	child = 2 * root;
	while (child <= n) {
		if (child < n && list[child] < list[child + 1])
			child++;
		if (rootkey > list[child])
			break;
		else {
			list[child / 2] = list[child];
			child *= 2;
		}
	}
	list[child / 2] = temp;
}//adjust

//�־��� �����͸� heapsort�� ���� ������������ �����ϴ� �Լ�
void heapsort(int list[], int n)
{
	int i, j;
	int temp;

	for (i = n / 2; i > 0; i--)
		adjust(list, i, n);
	for (i = n - 1; i > 0; i--)
	{
		temp = list[1];
		list[1] = list[i + 1];
		list[i + 1] = temp;
		adjust(list, 1, i);
	}
}//heapsort