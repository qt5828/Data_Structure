#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ��� : 2020.11.26
���α׷� ��� : 
*/

#include <stdio.h>
#include <math.h>

digit(int a, int i, int r);
void radixSort(int a[], int link[], int d, int r, int n);

void main()
{
	int a[] = { 0,1,300,200,104,101,91,88,60,15,31,12,26,82,51,6000 };
	int link[16];

	//���� �� ������ ���
	printf("������ ������ : ");
	for (int i = 1; i < 16; i++)
		printf("%d ", a[i]);
	
	//radix sort
	radixSort(a, link, 4, 10, 15);

	//���ĵ� ������ ���
	printf("\n\n");
	printf("Radix Sort : ");
	for (int i = 0; i < 15; i++)
		printf("%d ", a[i]);
	printf("\n\n");

}//main

//radix sort algorithm�� �̿��Ͽ� �����͸� �����ϴ� �Լ�
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

	//���ĵ� ������ b�� ����
	for (current = first; current; current = link[current]) {
		b[j++] = a[current];
	}
	//a�� ���ĵ� �����ͷ� �ٲ�
	for (j = 0; j < 16; j++)
		a[j] = b[j];
}//radixSort

//������ �ڸ����� ã�� �Լ�
 digit(int a, int i, int r)
{
	 int num = a;
	 for (int j = i; j < 3; j++)
		 num /= 10;

	 num %= 10;
	 return num;
}//digit