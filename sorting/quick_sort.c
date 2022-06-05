#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일 : 2020.11.26
프로그램 기능 : Quick sort algorithm을 이용하여 주어진 데이터에 대해 오름차순으로 정렬하는 프로그램
*/
#include <Stdio.h>

//함수선언
void quicksort(int a[], int left, int right);
void main()
{
	int a[] = { 1,300,200,104,101,91,88,60,15,31,12,26,82,51,6 };

	//정렬할 데이터 출력
	printf("정렬할 데이터 : ");
	for (int i = 0; i < 15; i++)
		printf("%d ", a[i]);
	printf("\n\n");

	//정렬할 데이터 quicksort 진행
	quicksort(a, 0, 14);

	//정렬된 데이터 출력
	printf("Quick Sort : ");
	for (int i = 0; i < 15; i++)
		printf("%d ", a[i]);
	printf("\n");
}//main


//Quick Sort algorithm을 이용해 주어진 데이터를 오름차순으로 정렬하는 함수
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