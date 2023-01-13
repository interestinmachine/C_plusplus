#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <cassert>
using namespace std;

typedef int SLDataType;

typedef struct SeqList
{
	//������һ��ָ��˳����ָ�룬���ҳ���Ϊ��˳���ָ�롱
	SLDataType* a;
	//��¼��ǰ˳�����Ԫ�ظ���
	int size;
	//��¼��ǰ˳�����������
	int capacity;
}SeqList;

// ��ʼ��˳���
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;//�տ�ʼʱ˳���Ϊ�գ�˳���ָ��ΪNULL
	ps->size = 0;//��ʼʱԪ�ظ���Ϊ0
	ps->capacity = 0;//����Ϊ0
}

// ����˳���
void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	//�ͷ�˳���ָ��ָ��Ŀռ�
	free(ps->a);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

// ����˳���
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//���˳��������Ƿ���������������������
void SeqCheckCapacity(SeqList* ps)
{
	// �������ˣ���Ҫ����
	if (ps->size == ps->capacity)
	{
		//�ж�˳��������Ƿ�Ϊ0����Ϊ0�����ȿ������ڴ��4��Ԫ�صĿռ��С
		//������Ϊ0��������Ϊԭ������������
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

// ͷ��
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqCheckCapacity(ps); // �������

	// �ڲ�������ǰ����ԭ�������ݺ��ƣ���λ��
	for (int i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}

// β��
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

// ָ���±�λ�ò���
void SeqListInsert(SeqList* ps, SLDataType x, int pos)
{
	assert(ps);
	// ����±�ĺϷ���
	assert(pos >= 0 && pos <= ps->size);
	// �������
	SeqCheckCapacity(ps);

	for (int i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}

// ɾ��һ�����ݣ�ͷɾ��
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

// ɾ��һ�����ݣ�βɾ��
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}

//ָ���±�λ��ɾ��
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

// ͷɾ�Ľ���ʹ������д�ĺ��� SeqListErase
void SeqListPopFrontAdvance(SeqList* ps)
{
	SeqListErase(ps, 0);
}

// βɾ�Ľ���ʹ������д�ĺ��� SeqListErase
void SeqListPopBackAdvance(SeqList* ps)
{
	SeqListErase(ps, ps->size - 1);
}

//����Ԫ�أ����У������±꣬���򷵻�-1
int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)//����˳�����в���
	{
		if (ps->a[i] == x)
			return i;//�ҵ������ݣ������±�
	}
	return -1;//δ�ҵ�������-1
}

//�޸�ָ���±�λ��Ԫ��
void SeqListModify(SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);//��������±�ĺϷ���
	ps->a[pos] = x;//�޸�����
}
