#define _CRT_SECURE_NO_WARNINGS
/*
작성자 :  조우연
작성일(수정일) : 2020.10.06
프로그램 기능 : 하루에 반드시 해야할 일과 소요시간의 목록을 우선순위큐로 정리하는 프로그램.
			   우선순위 큐는 MAX heap의 삽입,삭제로 구성되며, 출력할때는 소요시간이 가장
			   긴 일을 먼저 출력한다. 문제에 프로그램 종료조건을 명시하지 않았으므로, 사용자가
			   출력을 선택하면 할일목록을 출력하고 종료하게끔 설정하였다. 또한 힙이 비어있는데
			   삭제를 선택하거나, 힙이 꽉차있는데 삽입을 선택하면 에러메세지를 출력하고 프로그램을
			   종료한다.
*/

#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 11
#define HEAP_FULL(n) (n==MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)
typedef struct {
	int key;
	char work[15];
}element;
element heap[MAX_ELEMENTS];
int n = 0;

//함수선언
void push(element item, int* n);
void delete(int* n);
element pop(int* n);
void main()
{
	//사용자가 삽입,삭제,출력 중 어떤것을 고르는지를 저장할 변수
	char ans[2];
	//사용자가 입력할 할일의 목록을 저장하는 배열
	element save[10];
	int i = 0;

	//문제에 프로그램 종료를 따로 정의하지 않았으므로, 출력을 하면 프로그램이 종료되게 설정함.
	printf("출력을 선택하면 출력하고 프로그램을 종료합니다.");
	while (1)
	{
		printf("\n삽입(i), 삭제(d), 출력(p) : ");
		scanf("%s", ans);
		
		//삽입을 선택
		if (ans[0] == 'i')
		{
			//힙이 꽉차있으면 에러메세지 출력 후, 프로그램 종료
			if (HEAP_FULL(n)) {
				fprintf(stderr, "The heap is full. ");
				exit(1);
			}
			//사용자에게 할일과 소요시간을 입력받는다
			printf("해야할 일 : ");
			scanf("%s", &save[i].work);
			printf("소요시간(단위:분) : ");
			scanf("%d", &save[i].key);

			//입력받은 할일과 소요시간을 MAX힙에 삽입
			push(save[i], &n);
			i++;
		}

		//삭제를 선택
		else if (ans[0] == 'd')
		{
			//삭제(사용자에게 입력받은 값을 삭제-> 입력은 delete함수안에서 받음)
			delete(&n);
		}

		//출력을 선택
		else if (ans[0] == 'p')
		{
			//힙의 크기만큼 출력하기 위함
			int size = n;
			for (i = 1; i <=size ; i++) {
				//맥스힙의 루트(힙의 1번인덱스, 즉 최댓값)부터 삭제되며 힙이 비어질때까지 삭제된 값을 차례로 출력
				//즉 힙의 가장 큰 값부터 차례로 출력됨
				element res = pop(&n); 
				printf("%s-%d분\n", res.work, res.key);
			}
			//출력 후 프로그램 종료
			return;
		}

		//잘못된 값을 입력받았을 때
		else {
			printf("잘못된 값을 입력하였습니다.\n");
		}
	}
}//main


//맥스힙에 새로운 힙을 삽입하는 함수.
//새로운 힙이 삽입된 힙은 맥스힙의 형태를 따른다.
void push(element item, int* n) {
	int i;
	i = ++(*n);
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}//push


//맥스힙에서 사용자가 입력한 값을 찾아 삭제하는 함수
//삭제가 실행된 힙도 맥스힙형태를 따른다.
void delete(int* n) {

	//힙이 비어있으면 에러메세지 출력 후 프로그램 종료
	if (HEAP_EMPTY(*n)) {
		fprintf(stderr, "The heap is empty");
		exit(1);
	}

	//사용자에게 삭제할 할일을 입력받는다.
	char del[10];
	printf("삭제할 일 : ");
	scanf("%s", del);

	int parent, child;
	element item, temp;

	//삭제할 값의 인덱스를 찾아 parent에 저장한다.
	int check = 1;
	for (int i = 1; i <= *n; i++) {
		if (!(check = strcmp(heap[i].work, del)))
		{
			parent = i;
				child = 2 * i;
				break;
		}
	}

	//만약 삭제할 값이 힙에 존재하지 않는다면, 에러메세지 출력 후, 이전단계로 돌아감
	if (check != 0) {
		printf("존재하지 않는 할 일 입니다.\n");
		return;
	}
	item = heap[parent];
	temp = heap[(*n)--];

	while (child <= *n) {
		if ((child < *n) && (heap[child].key < heap[child + 1].key))
			child++;
		if (temp.key >= heap[child].key)
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	for (int i = 0; del[i] != NULL; i++)
		printf("%c", del[i]);
	printf("가 삭제됨\n");
}//delete

//맥스힙의 루트(가장 큰 값)을 삭제하고 그 값을 반환하는 함수
element pop(int* n)
{
	int parent, child;
	element item, temp;
	if (HEAP_EMPTY(*n)) {
		fprintf(stderr, "The heap is empty");
		exit(1);
	}
	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	while (child <= *n)
	{
		if ((child < *n) && (heap[child].key < heap[child + 1].key))
			child++;
		if (temp.key >= heap[child].key)
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}//pop