#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ��� : 2020.11.17
���α׷� ��� : Bubble sort algorithm�� �̿��Ͽ� �ǽ����� �־��� �����͸� ������������ �����ϴ� ���α׷�
*/
#include <stdio.h>

//�Լ�����
void bubbleSort(int list[], int n);

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

	//bubble sort algorithm�� �̿��� �������� ����
	bubbleSort(list, 15);

	//���ĵ� ������ ���
	printf("Bubble Sort : ");
	for (i = 0; i < 15; i++)
		printf("%d ", list[i]);
	printf("\n");
}//main

//Bubble sort algorithm�� �̿��Ͽ� �����͸� ������������ �����ϴ� �Լ�
void bubbleSort(int list[], int n)
{
	int temp, i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (list[j + 1] < list[j]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}//bubbleSort