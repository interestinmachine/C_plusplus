#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <cassert>
using namespace std;

typedef int SLDataType;

typedef struct SeqList
{
	//声明了一个指向顺序表的指针，姑且称它为“顺序表指针”
	SLDataType* a;
	//记录当前顺序表内元素个数
	int size;
	//记录当前顺序表的最大容量
	int capacity;
}SeqList;

// 初始化顺序表
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;//刚开始时顺序表为空，顺序表指针为NULL
	ps->size = 0;//起始时元素个数为0
	ps->capacity = 0;//容量为0
}

// 销毁顺序表
void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	//释放顺序表指针指向的空间
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

// 遍历顺序表
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//检查顺序表容量是否已满，若已满，则增容
void SeqCheckCapacity(SeqList* ps)
{
	// 代表满了，需要增容
	if (ps->size == ps->capacity)
	{
		//判断顺序表容量是否为0，若为0，则先开辟用于存放4个元素的空间大小
		//，若不为0，则扩容为原来容量的两倍
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* newA = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (newA == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		ps->a = newA;
		ps->capacity = newcapacity;
	}
}

// 头插
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqCheckCapacity(ps); // 检查容量

	// 在插入数据前，将原本的数据后移，留位置
	for (int i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}

// 尾插
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

// 指定下标位置插入
void SeqListInsert(SeqList* ps, SLDataType x, int pos)
{
	assert(ps);
	// 检查下标的合法性
	assert(pos >= 0 && pos <= ps->size);
	// 检查容量
	SeqCheckCapacity(ps);

	for (int i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}

// 删除一个数据（头删）
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	assert(ps->size > 0);

	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

// 删除一个数据（尾删）
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}

//指定下标位置删除
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(ps->size > 0);
	assert(pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

// 头删改进，使用上面写的函数 SeqListErase
void SeqListPopFrontAdvance(SeqList* ps)
{
	SeqListErase(ps, 0);
}

// 尾删改进，使用上面写的函数 SeqListErase
void SeqListPopBackAdvance(SeqList* ps)
{
	SeqListErase(ps, ps->size - 1);
}

//查找元素，若有，返回下标，否则返回-1
int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)//遍历顺序表进行查找
	{
		if (ps->a[i] == x)
			return i;//找到该数据，返回下标
	}
	return -1;//未找到，返回-1
}

//修改指定下标位置元素
void SeqListModify(SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);//检查输入下标的合法性
	ps->a[pos] = x;//修改数据
}
