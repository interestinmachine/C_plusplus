#include<iostream>
namespace zzy
{
	int Add(int x, int y);

	namespace acc
	{
		int b = 19;
	}
}

int Add(int x,int y)
{
	return x + y;
}

int global = 0;

//int main()
//{
//	printf("%d\n", Add(1, 2));
//	printf("%d\n", global);
//	printf("%d\n", zzy::acc::b);
//	return 0;
//}