#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

typedef int ElementType;

typedef struct ListNode
{
	ElementType Data;
	struct ListNode* Next;
}Node, * PNode;

// ����������
PNode CreateList()
{
	PNode PHead, PTail;
	// ����ͷ�ڵ��ڴ�
	PHead = (PNode)malloc(sizeof(Node));
	if (PHead == NULL)
	{
		printf("ͷ�ڵ��ڴ�ռ俪��ʧ��\n");
		exit(-1);
	}

	PTail = PHead;
	PTail->Next = NULL;

	int i = 0;
	int len = 0; // ��������ĳ���
	printf("������Ҫ��ŵĽڵ���:>");
	scanf("%d", &len);
	for (i = 0; i < len; i++) {
		PNode PNew = (PNode)malloc(sizeof(Node));
		if (PNew == NULL)
		{
			printf("�½ڵ㴴��ʧ��\n");
			exit(-1);
		}
		printf("�������%d����:>", i + 1);
		scanf("%d", &(PNew->Data));
		PNew->Next = NULL;
		PTail->Next = PNew;
		PTail = PNew;

	}
	printf("�������ɹ�\n");
	return PHead->Next;
}

// ����������
void TraverseList(PNode List)
{
	//����һ���������ݵĽ���ַ��ֵ��P
	PNode P = List;
	printf("���������ֵΪ:>");
	if (P == NULL)
	{
		printf("����Ϊ�գ�\n");
	}

	while (P != NULL) {
		printf("%d ", P->Data);
		P = P->Next;
	}

	printf("\n");
}

//int main() {
//	//�������ú���List����ͷ���λ��
//	PNode List = CreateList();
//	//��ͷ��㴫�룬��ӡ������
//	TraverseList(List);
//
//	return 0;
//}