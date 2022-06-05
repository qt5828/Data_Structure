#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일 : 2020.11.26
프로그램 기능 : Heap sort algorithm을 이용하여 주어진 데이터에 대해 오름차순으로 정렬하는 프로그램
*/
#include <Stdio.h>

//함수선언
void adjust(int list[], int root, int n);
void heapsort(int list[], int n);

void main()
{
	int a[] = { 1,300,200,104,101,91,88,60,15,31,12,26,82,51,6 };

	//정렬할 데이터 출력
	printf("정렬할 데이터 : ");
	for (int i = 0; i < 15; i++)
		printf("%d ", a[i]);
	printf("\n\n");

	//정렬할 데이터 merge sort 진행
	heapsort(a, 14);

	//정렬된 데이터 출력
	printf("Heap Sort : ");
	for (int i = 0; i < 15; i++)
		printf("%d ", a[i]);
	printf("\n");
}//main

//max heap을 만드는 함수
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

//주어진 데이터를 heapsort를 통해 오름차순으로 정렬하는 함수
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