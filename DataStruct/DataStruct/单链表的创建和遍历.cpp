#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

typedef int ElementType;

typedef struct ListNode
{
	ElementType Data;
	struct ListNode* Next;
}Node, * PNode;

// 创建单链表
PNode CreateList()
{
	PNode PHead, PTail;
	// 分配头节点内存
	PHead = (PNode)malloc(sizeof(Node));
	if (PHead == NULL)
	{
		printf("头节点内存空间开辟失败\n");
		exit(-1);
	}

	PTail = PHead;
	PTail->Next = NULL;

	int i = 0;
	int len = 0; // 定义链表的长度
	printf("请输入要存放的节点数:>");
	scanf("%d", &len);
	for (i = 0; i < len; i++) {
		PNode PNew = (PNode)malloc(sizeof(Node));
		if (PNew == NULL)
		{
			printf("新节点创建失败\n");
			exit(-1);
		}
		printf("请输入第%d个数:>", i + 1);
		scanf("%d", &(PNew->Data));
		PNew->Next = NULL;
		PTail->Next = PNew;
		PTail = PNew;

	}
	printf("链表创建成功\n");
	return PHead->Next;
}

// 遍历单链表
void TraverseList(PNode List)
{
	//将第一个含有数据的结点地址赋值给P
	PNode P = List;
	printf("遍历链表的值为:>");
	if (P == NULL)
	{
		printf("链表为空！\n");
	}

	while (P != NULL) {
		printf("%d ", P->Data);
		P = P->Next;
	}

	printf("\n");
}

//int main() {
//	//链表创建好后，用List接收头结点位置
//	PNode List = CreateList();
//	//将头结点传入，打印该链表
//	TraverseList(List);
//
//	return 0;
//}