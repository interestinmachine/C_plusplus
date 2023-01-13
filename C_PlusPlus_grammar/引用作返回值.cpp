#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

// 传引用返回
int& Add(int a, int b)
{
	int c = a + b;
	return c;
}

//int main()
//{
//	int& ret = Add(1, 2);
//	cout << ret << endl;
//	
//	Add(10, 20);
//	cout << ret << endl;
//
//	printf("11111111111111\n");
//	cout << ret << endl;
//
//	return 0;
//}