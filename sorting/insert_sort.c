#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일 : 2020.11.17
프로그램 기능 : Insertion sort algorithm을 이용하여 실습지에 주어진 데이터를 오름차순으로 정렬하는 프로그램
*/
#include <stdio.h>

//함수선언
void insertionSort(int list[], int n);

void main()
{
	//데이터 초기화
	int list[15] = { 1,300,200,104,101,91,88,60,15,31,12,26,82,51,6 };

	//데이터 출력
	int i;
	printf("정렬할 데이터 : ");
	for (i = 0; i < 15; i++)
		printf("%d ", list[i]);
	printf("\n\n");

	//insertion sort algorithm을 이용해 오름차순 정렬
	insertionSort(list, 15);

	//정렬된 데이터 출력
	printf("Insertion Sort : ");
	for (i = 0; i < 15; i++)
		printf("%d ", list[i]);
	printf("\n");
}//main


//Insertion sort algorithm을 이용하여 데이터를 오름차순으로 정렬하는 함수
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