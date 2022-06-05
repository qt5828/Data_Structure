#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ��� : 2020.12.04
���α׷� ��� : �ǽ����� �־��� �ܾ���� hash table�� �����ϰ�, �ܾ Ž���Ͽ� hash table������
			   hash table�� Ž���� �ܾ��� �ش���ġ�� ����ϴ� ���α׷�
			   * ���� �ܾ �ִ� ��� hash table�� �ߺ� �������� �ʴ´�.
			   * �ٸ� �ܾ���� �迭�� ���·� �����Ͽ����Ƿ�, Ž���� �ܾ��� �ش���ġ�� ����ϴ� ���������� 
			     �ߺ��� �ܾ �迭�� ����̹Ƿ�, �ߺ��� �ܾ Ž���� ��ġ�� ������ش�.
				 ex) �ܾ� �迭�� "apple","apple" <- �̷� �������� �ߺ��� �ΰ��� �ԷµǾ� �ִٸ�, hash table���� apple�� �ϳ��� ����������,
				     �ܾ Ž���Ҷ��� apple�� �ι� Ž���ǹǷ�, 
					 Ž�� apple: ��ġ = 10
					 Ž�� apple: ��ġ = 10 <- �̷��� �ߺ��Ǿ� Ž���� �� �ִ�.(�� �ܾ ������ Ž���ϴ� ���� ����)
*/
#include <stdio.h>
#include <string.h>
#define M 26

//hash table
char* HT[M];

//�Լ�����
unsigned int stringToInt(char* key);
void LinearProbing(char* data);
int h(int x);
void PrintHashTable();
void PrintSearch(char* data);

void main()
{
	//�ܾ� ������
	char *data[] = { "apple","berry","grape","raisn","banana","watermelon","grapefruit","orange","kiwi","pear","peach" };
	
	//data���� hash table�� ����
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) 
		LinearProbing(data[i]);
	
	//hash table ���
	PrintHashTable(data);

	//�ܾ���� ��� Ž���Ͽ� Ž���� ����(��ġ)�� ���� ���
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
		PrintSearch(data[i]);
}//main

//�־��� �ܾ ������ ��ȯ�ϴ� �Լ�
//���ڿ��� �� char�� �ƽ�Ű�ڵ� ������ ��ȯ�Ѵ�.
unsigned int stringToInt(char* key)
{
	int number = 0;
	int i;

	//���ڿ��� �� char�� �ƽ�Ű�ڵ� �ձ��ϱ�
	for (i = 0; i < strlen(key); i++)
	{
		number += key[i];
	}
	return number;
}//stringToInt

//hash function
int h(int x)
{
	return x % M;
}//h

//HashTable�� �����͸� �����ϴ� �Լ�
//overflow ó��������� linear probing�� ����Ѵ�.
void LinearProbing(char* data)
{
	//hash table�� �� ��ġ ã��
	int idx = h(stringToInt(data));
	int found = 0;
	while (HT[idx] != NULL && !found) {
		if (HT[idx] == data)
			found = 1;
		else
			idx = (idx + 1) % M; //linear probing�� �̿��� overflow ó��
	}
	if (found)
		printf("Duplicate items are not allowed.\n");
	else
		HT[idx] = data;
}//LinearProbing

//hash table�� ����� �����͸� Ž���ϴ� �Լ�
//�־��� �����Ͱ� ����Ǿ� �ִ� hash table�� �ε����� ã�� ��ȯ�Ѵ�.
int search(char* data)
{
	//hash table�� ���� ���� ��ġ ã��
	int idx = h(stringToInt(data));
	int found = 0;

	//overflow�� ó���Ͽ��� �ٸ� ��ġ�� �ܾ �� ���� ���
	//������ġ�� �������� Linear probing����� �̿��� �ε����� ã�´�.
	while (HT[idx] != NULL && !found) {
		if (HT[idx] == data)
			found = 1;
		else
			idx = (idx + 1) % M;
	}

	//Ž���� ��ġ ��ȯ
	return idx;
}//search

//hash table�� ����ϴ� �Լ�
void PrintHashTable()
{
	printf("\n=======================================\n");

	//hash table ���
	for (int i = 0; i < M; i++)
	{	
		//bucket�� ���� ����ִ� ���
		if (HT[i] != NULL)
			printf(" [%d]\t%s\n", i, HT[i]);
		//bucket�� ���� ������� �ʴ� ���
		else
			printf(" [%d]\n", i);
	}
	printf("=======================================\n\n");
}//PrintHashTable

//Ž���� �����Ϳ� ���� ������ ����ϴ� �Լ�
void PrintSearch(char* data)
{
	printf("Ž�� %s: ��ġ = %d\n", data, search(data));
}//PrintSearch