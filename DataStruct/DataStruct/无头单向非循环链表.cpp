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

// 打印单链表
void SListPrint(SListNode* plist)
{
	//assert(plist);
	SListNode* cur = plist;// 接收头指针
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->Next;
	}
	printf("NULL\n");
	printf("=======================\n");
}

// 找到对应值的节点
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

//创建一个新结点，返回新结点地址
SListNode* BuySLTNode(SLDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		printf("新节点创建失败\n");
		exit(-1);
	}
	newNode->Next = NULL;
	newNode->data = x;

	return newNode;
}

// 单链表头插
void SListPushFront(SListNode** pplist, SLDataType x)
{
	//申请一个新结点
	SListNode* newNode = BuySLTNode(x);
	//让新结点的指针域指向地址为pos的结点的下一个结点
	newNode->Next = *pplist;
	*pplist = newNode;
}

// 单链表尾插
void SListPushBack(SListNode** pplist, SLDataType x)
{
	SListNode* newNode = BuySLTNode(x);
	// 判断是否为空表
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

//在给定位置之后插入
void SListInsertAfter(SListNode** pos, SLDataType x)
{
	assert(*pos); // 确保传入地址不为空
	SListNode* newnode = BuySLTNode(x);
	newnode->Next = (*pos)->Next;
	(*pos)->Next = newnode;
}

//在给定位置之前插入
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

// 头删
void SListPopFront(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		printf("链表已为空链表");
		return;
	}
	else
	{
		//记录第一个结点的位置
		SListNode* tmp = *pplist;
		//让头指针指向第二个结点
		*pplist = (*pplist)->Next;
		//让头指针指向第二个结点
		free(tmp);
		//及时置空
		tmp = NULL;
	}
}

// 尾删
void SListPopBack(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		printf("链表已为空");
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

//删除给定位置之后的值
void SListErasetAfter(SListNode* pos)
{
	//确保传入地址不为空
	assert(pos);
	if (pos->Next == NULL)
	{
		printf("该节点之后的位置为空");
		return;
	}
	SListNode* tmp = pos->Next;
	pos->Next = tmp->Next;
	free(tmp);
	tmp = NULL;
}

//删除给定位置的值
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
	// 头插
	SListPushFront(&phead, 2);
	SListPrint(phead);

	// 尾插
	SListPushBack(&phead, 3);
	SListPrint(phead);

	//// 尾删
	//SListPopBack(&phead);
	//SListPopBack(&phead);
	//SListPopBack(&phead);
	//SListPrint(phead);

	//// 头删
	//SListPopFront(&phead);
	//SListPrint(phead);

	//SListInsertAfter(&phead, 4);
	//SListPrint(phead);

	//SListNode* pos = SListFind(phead, 1);
	//SListInsertBefore(&phead, pos, 10);
	//SListPrint(phead);

}