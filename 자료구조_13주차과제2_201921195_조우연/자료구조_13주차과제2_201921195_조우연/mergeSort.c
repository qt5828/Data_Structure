#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ��� : 2020.11.26
���α׷� ��� : Merge sort algorithm�� �̿��Ͽ� �־��� �����Ϳ� ���� ������������ �����ϴ� ���α׷�
*/
#include <Stdio.h>

//�Լ�����
void merge(int initList[], int mergedList[], int i, int m, int n);
void mergePass(int initList[], int resultList[], int n, int s);
void mergeSort(int a[], int n);

void main()
{
	int a[] = { 1,300,200,104,101,91,88,60,15,31,12,26,82,51,6 };

	//������ ������ ���
	printf("������ ������ : ");
	for (int i = 0; i < 15; i++)
		printf("%d ", a[i]);
	printf("\n\n");

	//������ ������ merge sort ����
	mergeSort(a, 14);

	//���ĵ� ������ ���
	printf("Merge Sort : ");
	for (int i = 0; i < 15; i++)
		printf("%d ", a[i]);
	printf("\n");
}//main

//���ĵ� �� list�� �պ��ϴ� �Լ�
void merge(int initList[], int mergedList[], int i, int m, int n)
{
	int j, k, t;
	j = m + 1; k = i;
	while (i <= m && j <= n) {
		if (initList[i] <= initList[j])
			mergedList[k++] = initList[i++];
		else
			mergedList[k++] = initList[j++];
	}
	if (i > m)
		for (t = j; t <= n; t++)
			mergedList[t] = initList[t];
	else
		for (t = i; t <= m; t++)
			mergedList[k + t - i] = initList[t];
}//merge

//merge�� �ܰ踦 �����ϴ� �Լ�
void mergePass(int initList[], int resultList[], int n, int s)
{
	int i, j;
	for (i = 1; i <= n - 2 * s + 1; i += 2 * s)
		merge(initList, resultList, i, i + s - 1, i + 2 * s - 1);

	if ((i + s - 1) < n)
		merge(initList, resultList, i, i + s - 1, n);
	else
		for (j = i; j <= n; j++)
			resultList[j] = initList[j];
}//mergePass

//sub group�� ũ�⸦ �ι辿 �÷����鼭 merge pass�� �ݺ������� �����ϴ� �Լ�
void mergeSort(int a[], int n)
{
	int s = 1;
	int extra[100];
	while (s < n) {
		mergePass(a, extra, n, s);
		s *= 2;
		mergePass(extra, a, n, s);
		s *= 2;
	}
}//mergeSort