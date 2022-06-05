#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일 : 2020.11.26
프로그램 기능 : Merge sort algorithm을 이용하여 주어진 데이터에 대해 오름차순으로 정렬하는 프로그램
*/
#include <Stdio.h>

//함수선언
void merge(int initList[], int mergedList[], int i, int m, int n);
void mergePass(int initList[], int resultList[], int n, int s);
void mergeSort(int a[], int n);

void main()
{
	int a[] = { 1,300,200,104,101,91,88,60,15,31,12,26,82,51,6 };

	//정렬할 데이터 출력
	printf("정렬할 데이터 : ");
	for (int i = 0; i < 15; i++)
		printf("%d ", a[i]);
	printf("\n\n");

	//정렬할 데이터 merge sort 진행
	mergeSort(a, 14);

	//정렬된 데이터 출력
	printf("Merge Sort : ");
	for (int i = 0; i < 15; i++)
		printf("%d ", a[i]);
	printf("\n");
}//main

//정렬된 두 list를 합병하는 함수
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

//merge의 단계를 수행하는 함수
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

//sub group의 크기를 두배씩 늘려가면서 merge pass를 반복적으로 실행하는 함수
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