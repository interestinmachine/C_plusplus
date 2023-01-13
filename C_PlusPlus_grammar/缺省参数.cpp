#include<iostream>

using namespace std;

void Print(int a = 0)
{
	cout << a << endl;
}

void Print2(int a, int b, int c = 90) {
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

int x = 77;
void Print3(int a, int c = x)
{
	cout << a << endl;
	cout << c << endl;
}

//int main() {
//	Print();
//	Print(10);
//	printf("=================\n");
//	Print2(1, 2);
//	Print2(1,2,3);
//	printf("=================\n");
//	Print3(1);
//	Print3(1, 99);
//
//	return 0;
//}