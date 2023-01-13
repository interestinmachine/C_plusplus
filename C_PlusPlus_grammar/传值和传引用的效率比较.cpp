#define _CRT_SECURE_NO_WARNINGS 1

#include <time.h>
#include<iostream>
using namespace std;

struct A { int a[10000]; };
A a;

// ֵ���� -- �п���
A TestFunc1() { return a; }
// ���÷���
A& TestFunc2() { return a; }

// ֵ��Ϊ����
void TestFunc3(A a) {}
// ������Ϊ����
void TestFunc4(A& a) {}

// ����ֵ�������Ƚ�
void TestReturnByRefOrValue()
{
	// ��ֵ��Ϊ�����ķ���ֵ����
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();

	// ��������Ϊ�����ķ���ֵ����
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();

	// �������������������֮���ʱ��
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}

void TestRefAndValue()
{
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc3(a);
	size_t end1 = clock();
	// ��������Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc4(a);
	size_t end2 = clock();
	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

int main()
{
	TestRefAndValue();
}
