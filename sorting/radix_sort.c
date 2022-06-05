#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일 : 2020.11.26
프로그램 기능 : 
*/

#include <stdio.h>
#include <math.h>

digit(int a, int i, int r);
void radixSort(int a[], int link[], int d, int r, int n);

void main()
{
	int a[] = { 0,1,300,200,104,101,91,88,60,15,31,12,26,82,51,6000 };
	int link[16];

	//정렬 전 데이터 출력
	printf("정렬할 데이터 : ");
	for (int i = 1; i < 16; i++)
		printf("%d ", a[i]);
	
	//radix sort
	radixSort(a, link, 4, 10, 15);

	//정렬된 데이터 출력
	printf("\n\n");
	printf("Radix Sort : ");
	for (int i = 0; i < 15; i++)
		printf("%d ", a[i]);
	printf("\n\n");

}//main

//radix sort algorithm을 이용하여 데이터를 정렬하는 함수
void radixSort(int a[], int link[], int d, int r, int n)
{
	int front[10], rear[10];
	int i, bin, current, first, last;
	first = 1;
	for (i = 1; i < n; i++)
		link[i] = i + 1;
	link[n] = 0;
	for (i = d - 1; i >= 0; i--)
	{
		for (bin = 0; bin < r; bin++)
			front[bin] = 0;
		for (current = first; current; current = link[current]) {
			bin = digit(a[current], i, r);
			if (front[bin] == 0)
				front[bin] = current;
			else
				link[rear[bin]] = current;
			rear[bin] = current;
		}
		for (bin = 0; !front[bin]; bin++);
		first = front[bin]; last = rear[bin];
		for(bin++;bin<r;bin++)
			if (front[bin])
			{
				link[last] = front[bin];
				last = rear[bin];
			}
		link[last] = 0;
	}

	int b[16];
	int j = 0;

	//정렬된 데이터 b에 저장
	for (current = first; current; current = link[current]) {
		b[j++] = a[current];
	}
	//a를 정렬된 데이터로 바꿈
	for (j = 0; j < 16; j++)
		a[j] = b[j];
}//radixSort

//숫자의 자릿수를 찾는 함수
 digit(int a, int i, int r)
{
	 int num = a;
	 for (int j = i; j < 3; j++)
		 num /= 10;

	 num %= 10;
	 return num;
}//digit