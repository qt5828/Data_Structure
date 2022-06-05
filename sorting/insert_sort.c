#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ��� : 2020.11.17
���α׷� ��� : Insertion sort algorithm�� �̿��Ͽ� �ǽ����� �־��� �����͸� ������������ �����ϴ� ���α׷�
*/
#include <stdio.h>

//�Լ�����
void insertionSort(int list[], int n);

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

	//insertion sort algorithm�� �̿��� �������� ����
	insertionSort(list, 15);

	//���ĵ� ������ ���
	printf("Insertion Sort : ");
	for (i = 0; i < 15; i++)
		printf("%d ", list[i]);
	printf("\n");
}//main


//Insertion sort algorithm�� �̿��Ͽ� �����͸� ������������ �����ϴ� �Լ�
void insertionSort(int list[], int n)
{
	int i, j, next;
	for (i = 1; i < n; i++) {
		next = list[i];
		for (j = i - 1; j >= 0 && next < list[j]; j--)
			list[j + 1] = list[j];
		list[j + 1] = next;
	}
}//insertion