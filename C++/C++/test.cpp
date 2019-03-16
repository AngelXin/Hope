#include <stdio.h>

#include <iostream>
using namespace std;

namespace N1
{
	int a = 0;
	int b = 10;
	int p;
	int Add(int left, int right)
	{
		return left + right;
	}

	namespace N2
	{
		int c = 5;
		int d = 7;
		double m;
		int Sub(int left, int right)
		{
			return left - right;
		}
	}
}

namespace N3
{
	int h = 19;
	int t = 89;
	int Mul(int left, int right)
	{
		return left*right;
	}
}

int Ful(int left, int right)
{
	return left + right;
}

double Ful(int left, double right)
{
	return left + right;
}

int main()//函数的重载
{
	cout << Ful(1, 6) << endl;
	cout << Ful(0, 9.5) << endl;
	return 0;
}

#if 0
using N1::a;

int Add1(int a=10, int b=1)//全缺省函数
{
	return a + b;
}

int Ful(int a, int b = 1)//半缺省函数
{
	return a*b;
}

void Print(int a=9, int b = 79, double c = 9.8)//全缺省函数
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

int main()//缺省函数
{
	cout << Add1() << endl;
	cout << Ful(a) << endl;
	Print();
	return 0;
}

#endif


#if 0

int a = 9;
using N1::b;
using N1::N2::Sub;
using namespace N3;

int main()//c++输入&&输出
{
	int w;
	double e;
	int o;

	cout << "hello world!!" << endl;
	cout << b << endl;

	cin >> w;
	cin >> e;
	cin >> N1::p;
	cin >> N1::N2::m;

	cout << w << " " << e << " " << N1::p << " " << N1::N2::m << endl;

}

int main()//命名空间及其元素的使用
{
	int a = 8;
	printf("%d\n", a);//8
	printf("%d\n", ::a);//9
	printf("%d\n", N1::a);//0
	printf("%d\n", N1::N2::c);//5 ——(命名空间里嵌套命名空间)
	printf("%d\n", N1::Add(9,3));//12

	printf("%d\n", b);//10
	printf("%d\n", Sub(7, 6));//1

	printf("%d\n", h);//19
	printf("%d\n", t);//89
	printf("%d\n", Mul(4 , 6));//24

	return 0;
}
#endif





