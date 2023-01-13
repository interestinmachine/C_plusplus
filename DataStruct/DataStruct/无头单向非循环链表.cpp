#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <cassert>
using namespace std;

typedef int SLDataType;

typedef struct SListNode
{
	SLDataType data;
	struct SListNode* Next;
}SListNode;

// ��ӡ������
void SListPrint(SListNode* plist)
{
	//assert(plist);
	SListNode* cur = plist;// ����ͷָ��
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->Next;
	}
	printf("NULL\n");
	printf("=======================\n");
}

// �ҵ���Ӧֵ�Ľڵ�
SListNode* SListFind(SListNode* phead, SLDataType x)
{
	SListNode* cur = phead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->Next;
		}
	}

	return NULL;
}

//����һ���½�㣬�����½���ַ
SListNode* BuySLTNode(SLDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("�½ڵ㴴��ʧ��\n");
		exit(-1);
	}
	newNode->Next = NULL;
	newNode->data = x;

	return newNode;
}

// ������ͷ��
void SListPushFront(SListNode** pplist, SLDataType x)
{
	//����һ���½��
	SListNode* newNode = BuySLTNode(x);
	//���½���ָ����ָ���ַΪpos�Ľ�����һ�����
	newNode->Next = *pplist;
	*pplist = newNode;
}

// ������β��
void SListPushBack(SListNode** pplist, SLDataType x)
{
	SListNode* newNode = BuySLTNode(x);
	// �ж��Ƿ�Ϊ�ձ�
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->Next != NULL)
		{
			tail = tail->Next;
		}

		tail->Next = newNode;
	}
}

//�ڸ���λ��֮�����
void SListInsertAfter(SListNode** pos, SLDataType x)
{
	assert(*pos); // ȷ�������ַ��Ϊ��
	SListNode* newnode = BuySLTNode(x);
	newnode->Next = (*pos)->Next;
	(*pos)->Next = newnode;
}

//�ڸ���λ��֮ǰ����
void SListInsertBefore(SListNode** pplist, SListNode* pos, SLDataType x)
{
	assert(pos);
	SListNode* newnode = BuySLTNode(x);
	if (pos == *pplist)
	{
		newnode->Next = *pplist;
		*pplist = newnode;
	}
	else
	{
		SListNode* prev = *pplist;
		while (prev->Next != pos)
		{
			prev = prev->Next;
		}
		newnode->Next = pos;
		prev->Next = newnode;
	}
}

// ͷɾ
void SListPopFront(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		printf("������Ϊ������");
		return;
	}
	else
	{
		//��¼��һ������λ��
		SListNode* tmp = *pplist;
		//��ͷָ��ָ��ڶ������
		*pplist = (*pplist)->Next;
		//��ͷָ��ָ��ڶ������
		free(tmp);
		//��ʱ�ÿ�
		tmp = NULL;
	}
}

// βɾ
void SListPopBack(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		printf("������Ϊ��");
		return;
	}

	SListNode* tail = *pphead;
	if (tail->Next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		while (tail->Next->Next != NULL)
		{
			tail = tail->Next;
		}

		SListNode* tmp = tail->Next;
		tail->Next = NULL;
		free(tmp);
		tmp = NULL;
	}
}

//ɾ������λ��֮���ֵ
void SListErasetAfter(SListNode* pos)
{
	//ȷ�������ַ��Ϊ��
	assert(pos);
	if (pos->Next == NULL)
	{
		printf("�ýڵ�֮���λ��Ϊ��");
		return;
	}
	SListNode* tmp = pos->Next;
	pos->Next = tmp->Next;
	free(tmp);
	tmp = NULL;
}

//ɾ������λ�õ�ֵ
void SListErasetCur(SListNode** pplist, SListNode* pos)
{
	assert(pos);
	if (pos == *pplist)
	{
		*pplist = pos->Next;
		free(pos);
		pos = NULL;
	}
	else
	{
		SListNode* prev = *pplist;
		while (prev->Next != pos)
		{
			prev = prev->Next;
		}
		prev->Next = pos->Next;
		free(pos);
		pos = NULL;
	}

}

int main()
{
	SListNode* phead = BuySLTNode(1);
	// ͷ��
	SListPushFront(&phead, 2);
	SListPrint(phead);

	// β��
	SListPushBack(&phead, 3);
	SListPrint(phead);

	//// βɾ
	//SListPopBack(&phead);
	//SListPopBack(&phead);
	//SListPopBack(&phead);
	//SListPrint(phead);

	//// ͷɾ
	//SListPopFront(&phead);
	//SListPrint(phead);

	//SListInsertAfter(&phead, 4);
	//SListPrint(phead);

	//SListNode* pos = SListFind(phead, 1);
	//SListInsertBefore(&phead, pos, 10);
	//SListPrint(phead);

}