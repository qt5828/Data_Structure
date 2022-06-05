#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ��� : 2020.11.26
���α׷� ��� : Quick sort algorithm�� �̿��Ͽ� �־��� �����Ϳ� ���� ������������ �����ϴ� ���α׷�
*/
#include <Stdio.h>

//�Լ�����
void quicksort(int a[], int left, int right);
void main()
{
	int a[] = { 1,300,200,104,101,91,88,60,15,31,12,26,82,51,6 };

	//������ ������ ���
	printf("������ ������ : ");
	for (int i = 0; i < 15; i++)
		printf("%d ", a[i]);
	printf("\n\n");

	//������ ������ quicksort ����
	quicksort(a, 0, 14);

	//���ĵ� ������ ���
	printf("Quick Sort : ");
	for (int i = 0; i < 15; i++)
		printf("%d ", a[i]);
	printf("\n");
}//main


//Quick Sort algorithm�� �̿��� �־��� �����͸� ������������ �����ϴ� �Լ�
void quicksort(int a[], int left, int right)
{
	int pivot, i, j, temp;
	if (left < right)
	{
		i = left;
		j = right + 1;
		pivot = a[left];
		do {
			do i++;
			while (a[i] < pivot);
			do j--;
			while (a[j] > pivot);
			if (i < j) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		} while (i < j);
		temp = a[left];
		a[left] = a[j];
		a[j] = temp;
		quicksort(a, left, j - 1);
		quicksort(a, j + 1, right);
	}
}//quicksort