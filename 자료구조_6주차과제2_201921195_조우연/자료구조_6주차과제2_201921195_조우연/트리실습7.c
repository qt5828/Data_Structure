
#define _CRT_SECURE_NO_WARNINGS
/*
작성자 :  조우연
작성일(수정일) : 2020.10.13
프로그램 기능 : binary search tree를 사용하여 마라톤 대회의 참가자 정보를 관리하기 위한
			   프로그램을 구현한다. 사용자는 입력, 검색, 정보변경, 참가취소, 종료 의 선택을
			   할 수 있고, 각각 참가자 등록, 참가자 검색, 참가자의 정보수정, 참가취소, 프로
			   그램 종료의 수행을 실행한다. 같은 이름의 참가자는 등록이 안되며, 명단에 존재하지
			   않는 사람의 검색과 정보수정, 참가취소는 제한된다.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct {
	char name[11];
	char date[9];
	char add[21];
}element;
typedef struct node {
	element data;
	treePointer leftChild;
	treePointer rightChild;
}node;

treePointer search(treePointer root, char name[]);
void insert(treePointer node);
treePointer Change(treePointer root, char name[], char change[]);
void delete(treePointer* root, char name[]);
void main()
{
	int ans;
	treePointer root = NULL;
	root = (treePointer)malloc(sizeof(node));
	printf("참가자 정보 관리 프로그램\n\n");

	//루트는 따로 입력받을 수 있게 분리해줌(편의상..)
	while (1)
	{
		printf("입력(1), 검색(2), 정보변경(3), 참가취소(4), 종료(5)\n");
		scanf("%d", &ans);
		if (ans == 1)
		{
			char name[11], add[21], date[9];
			printf("정보를 입력하십시오.\n이름(영문 10자이내)\n");
			scanf("%s", name);
			printf("신청날짜(YYYYMMDD)\n");
			scanf("%s", date);
			printf("신청지역(영문 20자이내)\n");
			scanf("%s", add);
			strcpy(root->data.name, name);
			strcpy(root->data.add, add);
			strcpy(root->data.date, date);
			root->leftChild = root->rightChild = NULL;
			break;
		}
		else if (ans >= 2 && ans <=4)
		{
			printf("명단이 비어있습니다.\n");
			continue;
		}
		else if (ans == 5)
		{
			printf("종료합니다.\n");
			return;
		}
		else
			continue;
	}

	//ans가 5가 되어서 프로그램이 종료할때까지 반복
	while (1)
	{
		//매반복마다 입력,검색,정보변경,참가취소,종료 중 하나를 선택받는다.
		printf("입력(1), 검색(2), 정보변경(3), 참가취소(4), 종료(5)\n");
		scanf("%d", &ans);

		//입력
		if (ans == 1)
		{
			//binary search tree에 노드삽입(등록자정보에 대한 노드)
			insert(&root);
		}

		//검색
		else if (ans == 2)
		{
			//검색할 이름을 입력받음
			char name[11];
			printf("검색할 이름을 입력하십시오.\n");
			scanf("%s", name);

			//find에 찾고자 하는 사람의 정보를 저장
			node* find;
			find = search(root, name);

			//find가 null이면 binary search tree안에 명단 없음
			if (!find) {
				printf("등록되지 않은 명단입니다.\n");
				continue;
			}
			//검색 성공시 출력
			printf("검색이 완료되었습니다.\n");
			printf("이름 %s\n신청날짜 %s\n신청지역 %s\n", find->data.name, find->data.date, find->data.add);
		}

		//정보변경
		else if (ans == 3)
		{
			//정보를 변경할 사람의 이름과 변경할 내용을 입력받음
			char name[11], change[21];
			printf("변경할 정보를 입력하십시오.(이름,정보)\n");
			scanf("%s %s", name, change);

			//record에 정보를 수정한 사람의 정보를 저장
			treePointer record;
			record = Change(root, name, change);

			//record가 null이 아니면, 즉 정보변경을 성공하면 출력
			if (record)
				printf("이름 %s\n신청날짜 %s\n신청지역 %s\n", record->data.name, record->data.date, record->data.add);
		}

		//참가취소
		else if (ans == 4)
		{
			//참가를 취소할 이름을 입력받음
			char name[11];
			printf("취소할 이름을 입력하십시오.\n");
			scanf("%s", name);
			//삭제
			delete(&root, name);
		}

		//종료
		else if (ans == 5)
		{
			printf("종료합니다.\n");
			return; //프로그램 종료
		}
	}
}


//binary search tree에서 name을 가진 노드를 찾아서 그 노드포인터를 반환하는 함수
treePointer search(treePointer root, char name[])
{
	if (!root) return NULL;
	if (strcmp(name, root->data.name) == 0) return root;
	if (strcmp(name, root->data.name) == -1)
		return search(root->leftChild, name);
	return search(root->rightChild, name);
}//search

//binary search tree에 노드를 추가하는 함수
void insert(treePointer* node)
{
	//노드의 data에 들어갈 이름,주소,날짜 정보 입력받는다
	char name[11], add[21], date[9];
	printf("정보를 입력하십시오.\n이름(영문 10자이내)\n");
	scanf("%s", name);

	//name이 이미 binary search tree안에 존재하면 에러메세지 출력
	treePointer find;
	find = search(*node, name);
	if (find) {
		printf("이미 등록된 참가자입니다.\n");
		return;
	}

	printf("신청날짜(YYYYMMDD)\n");
	scanf("%s", date);
	printf("신청지역(영문 20자이내)\n");
	scanf("%s", add);

	treePointer ptr = (treePointer)malloc(sizeof(node));
	treePointer temp, p;

	temp = *node;
	p = NULL;
	strcpy(ptr->data.name, name);
	strcpy(ptr->data.add, add);
	strcpy(ptr->data.date, date);
	ptr->rightChild = NULL;
	ptr->leftChild = NULL;

	while (temp) {
		if (strcmp(name, temp->data.name) == 0)
			return;
		p = temp;
		if (strcmp(name, p->data.name) == -1)
			temp = p->leftChild;
		else
			temp = p->rightChild;
	}
	if (p)
	{
		if (strcmp(name, p->data.name) == -1)
			p->leftChild = ptr;
		else
			p->rightChild = ptr;
	}
	else
		*node = ptr;
}//insert

//넘겨받은 name의 정보를 수정하는 함수
//넘겨받은 change가 숫자로 시작하면 date를 수정하고, 문자로 시작하면 add를 수정한다.
treePointer Change(treePointer root, char name[], char change[])
{
	//root가 null이면 tree에 name이 존재 안함
	if (!root) {
		printf("등록되지 않은 명단입니다.\n");
		return NULL;
	}
	//name과 root의 name이 같을 때
	if (strcmp(name, root->data.name) == 0)
	{
		if (change[0] >= 48 && change[0] <= 57)
		{
			strcpy(root->data.date, change);
			printf("변경이 완료되었습니다.\n");
			return root;
		}
		else
		{
			strcpy(root->data.add, change);
			printf("변경이 완료되었습니다.\n");
			return root;
		}
	}
	//name이 root의 name보다 작을 때(문자열비교)
	if (strcmp(name, root->data.name) == -1)
		return Change(root->leftChild, name, change);
	return Change(root->rightChild, name, change);
}//change


//넘겨받은 name을 가진 노드를 binary search tree에서 찾아 삭제하는 함수
void delete(treePointer* root, char name[])
{
	treePointer parent, child, temp;

	temp = *root;
	parent = NULL; 

	//binary search tree에서 입력받은 name을 찾는다
	while (temp != NULL && strcmp(temp->data.name, name) != 0)
	{
		parent = temp;
		//parent의 name이 입력받은 name보다 크면(문자열비교) 
		if (strcmp(parent->data.name, name) == 1)
			temp = parent->leftChild; //parent의 leftChild로 이동
		//parent의 name이 입력받은 name보다 작으면
		else
			temp = parent->rightChild; //parent의 rightChild로 이동
	}

	//temp가 null이면 binary seach tree에 name이 트리 안에 없음
	if (!temp)
	{
		printf("목록에 존재하지 않는 명단입니다.\n");
		return;
	}

	//binary search tree안에 name이 존재할 때

	//삭제할 노드가 leaf노드일때
	if (temp->leftChild == NULL && temp->rightChild == NULL)
	{
		// parent(부모노드)가 NULL이 아닐 때, 즉 삭제할 노드가 root가 아닐때
		if (parent) 
		{
			//parent의 leftChild가 삭제할 노드이면 leftChild를 NULL로 만듦
			if (parent->leftChild == temp)
				parent->leftChild = NULL;
			//parent의 rightChild가 삭제할 노드이면 rightChild를 NULL로 만듦
			else
				parent->rightChild = NULL;
		}
		//삭제할 노드가 root이면 root를 NULL로 만듦
		else
			*root = NULL;
	}

	//삭제할 노드의 subtree가 하나만 존재할때
	else if ((temp->leftChild == NULL) || (temp->rightChild == NULL))
	{
		//삭제할 노드의 왼쪽에 subtree 있다면 왼쪽 subtree를 child에 저장
		if (temp->leftChild != NULL)
			child = temp->leftChild;
		//삭제할 노드의 오른쪽에 subtree 있다면 오른쪽 subtree를 child에 저장
		else
			child = temp->rightChild;

		//parent가 null이 아니면, 즉 삭제할 노드가 root가 아니면
		if (parent)
		{
			//parent의 leftChild가 삭제할 노드이면, parent의 leftChild에 child(subtree)를 붙인다.
			if (parent->leftChild == temp)
				parent->leftChild = child;
			//parent의 rightChild가 삭제할 노드이면, parent의 rightChild에 child(subtree)를 붙인다.
			else
				parent->rightChild = child;
		}
		//삭제할 노드가 root이면 루트에 child를 붙인다.
		else
			*root = child;
	}

	//삭제할 노드의 subtree가 두개일때
	else
	{
		treePointer smallest, temp2;

		//삭제할 노드를 smallest에 넣는다.
		smallest = temp;
		//삭제할 노드의 오른쪽 subtree로 이동할 것임
		temp2 = temp->rightChild;
		
		//오른쪽 subtree에서 가장 작은 값을 찾을 것
		//subtree의 왼쪽으로 계속가서 끝에 있는 것이 가장 작은 값
		while (temp2->leftChild != NULL)
		{
			smallest = temp2;
			temp2 = temp2->leftChild;
		}
		//연결
		if (smallest->leftChild == temp2)
			smallest->leftChild = temp2->rightChild;
		//왼쪽 끝의 노드에 오른쪽 노드가 연결되어있을 때 연결하기
		else
			smallest->rightChild = temp2->rightChild;
		
		//temp의 name에 temp2의 name을 넣어줌
		strcpy(temp->data.name, temp2->data.name);
		temp = temp2;
	}
	printf("참가가 취소되었습니다.\n");
}//delete