#define _CRT_SECURE_NO_WARNINGS
/*
작성자 : 조우연
작성일 : 2020.12.04
프로그램 기능 : 실습지에 주어진 단어들을 hash table에 저장하고, 단어를 탐색하여 hash table에서의
			   hash table과 탐색한 단어의 해당위치를 출력하는 프로그램
			   * 같은 단어가 있는 경우 hash table에 중복 저장하지 않는다.
			   * 다만 단어들을 배열의 형태로 저장하였으므로, 탐색한 단어의 해당위치를 출력하는 과정에서는 
			     중복된 단어도 배열의 요소이므로, 중복된 단어도 탐색한 위치를 출력해준다.
				 ex) 단어 배열에 "apple","apple" <- 이런 형식으로 중복된 두개가 입력되어 있다면, hash table에는 apple을 하나만 저장하지만,
				     단어를 탐색할때는 apple이 두번 탐색되므로, 
					 탐색 apple: 위치 = 10
					 탐색 apple: 위치 = 10 <- 이렇게 중복되어 탐색될 수 있다.(한 단어를 여러번 탐색하는 경우와 같음)
*/
#include <stdio.h>
#include <string.h>
#define M 26

//hash table
char* HT[M];

//함수선언
unsigned int stringToInt(char* key);
void LinearProbing(char* data);
int h(int x);
void PrintHashTable();
void PrintSearch(char* data);

void main()
{
	//단어 데이터
	char *data[] = { "apple","berry","grape","raisn","banana","watermelon","grapefruit","orange","kiwi","pear","peach" };
	
	//data들을 hash table에 저장
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) 
		LinearProbing(data[i]);
	
	//hash table 출력
	PrintHashTable(data);

	//단어들을 모두 탐색하여 탐색한 정보(위치)에 대해 출력
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
		PrintSearch(data[i]);
}//main

//주어진 단어를 정수로 변환하는 함수
//문자열의 각 char의 아스키코드 합으로 변환한다.
unsigned int stringToInt(char* key)
{
	int number = 0;
	int i;

	//문자열의 각 char의 아스키코드 합구하기
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

//HashTable에 데이터를 저장하는 함수
//overflow 처리기법으로 linear probing을 사용한다.
void LinearProbing(char* data)
{
	//hash table에 들어갈 위치 찾기
	int idx = h(stringToInt(data));
	int found = 0;
	while (HT[idx] != NULL && !found) {
		if (HT[idx] == data)
			found = 1;
		else
			idx = (idx + 1) % M; //linear probing을 이용한 overflow 처리
	}
	if (found)
		printf("Duplicate items are not allowed.\n");
	else
		HT[idx] = data;
}//LinearProbing

//hash table에 저장된 데이터를 탐색하는 함수
//주어진 데이터가 저장되어 있는 hash table의 인덱스를 찾아 반환한다.
int search(char* data)
{
	//hash table에 원래 들어갔을 위치 찾기
	int idx = h(stringToInt(data));
	int found = 0;

	//overflow를 처리하여서 다른 위치에 단어가 들어가 있을 경우
	//현재위치를 기준으로 Linear probing방법을 이용해 인덱스를 찾는다.
	while (HT[idx] != NULL && !found) {
		if (HT[idx] == data)
			found = 1;
		else
			idx = (idx + 1) % M;
	}

	//탐색한 위치 반환
	return idx;
}//search

//hash table을 출력하는 함수
void PrintHashTable()
{
	printf("\n=======================================\n");

	//hash table 출력
	for (int i = 0; i < M; i++)
	{	
		//bucket에 값이 들어있는 경우
		if (HT[i] != NULL)
			printf(" [%d]\t%s\n", i, HT[i]);
		//bucket에 값이 들어있지 않는 경우
		else
			printf(" [%d]\n", i);
	}
	printf("=======================================\n\n");
}//PrintHashTable

//탐색한 데이터에 대한 정보를 출력하는 함수
void PrintSearch(char* data)
{
	printf("탐색 %s: 위치 = %d\n", data, search(data));
}//PrintSearch