#define _CRT_SECURE_NO_WARNINGS
/*
�ۼ��� : ���쿬
�ۼ���(������) : 2020.10.11
���α׷� ��� : 1���� 15������ 15�� ���� ���� ���� ���� �Ͽ�, 6�������� 3�������� �־���
			   ��� union�� �����ϰ�, union������ ���� ���� ���� ��� ��带 ����ϰ�,
			   ���� ������ �� ��带 �Է¹޾� �̵��� ���� ���տ� ���ԵǾ� �ִ��� �ƴ����� ����ϴ�
			   ���α׷�. Union-Find�� �̿��Ͽ� �����Ѵ�.
*/
#include <stdio.h>

//0��° �ε��� �����Ұ���(���Ǹ� ���ؼ�)
int parent[16] = { 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };

//�Լ�����
void SimpleUnion(int i, int j);
int SimpleFind(int i);
void check(int i, int j);
void main()
{
	//6�������� 3�������� �־������ union ����
	SimpleUnion(1, 2);
	SimpleUnion(1, 3);
	SimpleUnion(1, 4);
	SimpleUnion(3, 5);
	SimpleUnion(5, 6);
	SimpleUnion(7, 8);
	SimpleUnion(9, 10);
	SimpleUnion(10, 11);
	SimpleUnion(12, 14);
	
	//union���� �� ���� ��� ����� root�� ���
	printf("[���� �� ����� root�� ���]\n\n");
	int i;
	for (i = 1; i < 16; i++)
		printf("��� %d�� root�� %d\n", i, SimpleFind(i));

	printf("\n\n");


	//������ �� ��带 �Է¹޾� ���� ���տ� ���ԵǾ� �ִ� ������� Ȯ���ϰ� ���
	printf("[�� ��尡 ���� ���տ� ���Ͽ����� ���� �ٸ� ���տ� ���Ͽ����� ���θ� ���]\n\n");
	char ans[2] = "Y";
	//����ڰ� 'N'�� �Է��Ҷ����� �ݺ��ؼ� �����Ѵ�.
	while (ans[0] == 'Y')
	{
		int n1, n2;
		printf("�� �� ��� �Է�(����: ���1 ���2) : ");
		scanf("%d %d", &n1, &n2);
		check(n1, n2);
		printf("�� �Է��Ϸ��� Y, �׸��Ϸ��� N�� �Է��ϼ��� : ");
		scanf("%s", ans);
		printf("\n");
	}
	printf("���α׷��� �����մϴ�.\n");

}//main

//i�� root�� j�� ����� �Լ�
void SimpleUnion(int i, int j)
{
	//i�� root�� �ƴ� ��, i�� root���� parent�� root�� j�� ����
	if (parent[i] > 0)
		parent[parent[i]] = j;

	//i�� root�� j�� ����
	parent[i] = j;
}//SimpleUnion


//i�� root�� ã�� �Լ�
int SimpleFind(int i)
{
	for (; parent[i] >= 0; i = parent[i]);
	return i;
}//SimpleFind


//�� �� i,j�� ���� ���տ� ���ԵǾ��ִ����� �Ǵ��ϰ� �̿� ���� �Ǵܰ���� ����ϴ� �Լ�
void check(int i, int j)
{
	//i�� j�� root�� ������ ����
	if (SimpleFind(i) == SimpleFind(j))
		printf("\n��� %d�� ��� %d�� ���� ���տ� ���� �����Դϴ�.\n\n", i, j);
	//i�� j�� root�� �ٸ��� ����
	else
		printf("\n��� %d�� ��� %d�� ���� �ٸ� ������ �����Դϴ�.\n\n", i, j);
}//check
