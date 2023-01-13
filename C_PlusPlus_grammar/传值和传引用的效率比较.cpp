#define _CRT_SECURE_NO_WARNINGS 1

#include <time.h>
#include<iostream>
using namespace std;

struct A { int a[10000]; };
A a;

// 值返回 -- 有拷贝
A TestFunc1() { return a; }
// 引用返回
A& TestFunc2() { return a; }

// 值作为参数
void TestFunc3(A a) {}
// 引用作为参数
void TestFunc4(A& a) {}

// 返回值类型作比较
void TestReturnByRefOrValue()
{
	// 以值作为函数的返回值类型
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc1();
	size_t end1 = clock();

	// 以引用作为函数的返回值类型
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; ++i)
		TestFunc2();
	size_t end2 = clock();

	// 计算两个函数运算完成之后的时间
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;
}

void TestRefAndValue()
{
	A a;
	// 以值作为函数参数
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc3(a);
	size_t end1 = clock();
	// 以引用作为函数参数
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFunc4(a);
	size_t end2 = clock();
	// 分别计算两个函数运行结束后的时间
	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
}

int main()
{
	TestRefAndValue();
}
