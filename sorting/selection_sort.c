#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ��� : 2020.11.17
���α׷� ��� : Selection sort algorithm�� �̿��Ͽ� �ǽ����� �־��� �����͸� ������������ �����ϴ� ���α׷�
*/
#include <stdio.h>

//�Լ�����
void selectionSort(int list[], int n);

void main()
{
	//������ �ʱ�ȭ
	int list[15] = { 1,300,200,104,101,91,88,60,15,31,12,26,82,51,6 };

	//������ ���
	int i;
	printf("������ ������ : ");
	for (i = 0; i < 15; i++)
		printf("%d ", list[i]);
	printf("\n\n");

	//selection sort algorithm�� �̿��� �������� ����
	selectionSort(list, 15);

	//���ĵ� ������ ���
	printf("Selection Sort : ");
	for (i = 0; i < 15; i++)
		printf("%d ", list[i]);
	printf("\n");
}//main

//Selection sort algorithm�� �̿��Ͽ� �����͸� ������������ �����ϴ� �Լ�
void selectionSort(int list[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[min])
				min = j;
		}
		temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
}//selectionSort