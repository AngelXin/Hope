#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>
using namespace std;

//交换
//
//void Swap1(int a, int b)//传值调用
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Swap2(int* a, int* b)//传地址调用 
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//int main()
//{
//	int m = 10;
//	int n = 20;
//	Swap1(m, n);
//	printf("m=%d, n=%d\n", m, n);
//	Swap2(&m, &n);
//	printf("m=%d, n=%d\n", m, n);
//
//	return 0;
//}


//引用

void TestRef1()//引用概念
{
	int a = 10;
	int& ra = a;
	ra = 20;

	printf("%d\n", a);
	printf("%d\n", ra);
}

void TestRef2()//引用特性
{
	int a = 10;//1、一个变量可以有多个引用
	int b = 9;
	int& ra = a;
	int& rra = b;
	rra = 0;
	ra = 8;

	//int& b;//2、引用在定义是必须初始化

	//int& ra = b;//3、引用一旦引用一个实体，就不能再引用其他实体

	printf("%d\n", a);
	printf("%d\n", ra);
	printf("%d\n", rra);
	printf("%d\n",b);
}

void TestRef3()//常引用
{
	/*const int a = 10;
	const int& ra = a;*/

	const double d = 9.9;
	const double& rd = d;

	printf("%f\n", d);
	printf("%f\n", rd);
}


//void TestRef4()//使用场景
//{
//	int a = 10;
//	int b = 9;
//	int& ra = a;
//	int& rb = b;
//	//1、做参数
//	Swap(ra, rb);
//	
//	//2、做返回值
//	TestRefReturn(a);
//}

void Swap(int& ra, int& rb)//做参数
{
	int temp = ra;
	ra = rb;
	rb = temp;

	printf("a=%d\n", ra);
	printf("b=%d\n", rb);
}

int& TestRefReturn(int& c)//做返回值
{
	c = c + 10;
	printf("%d\n", c);
	return c;
}

//int main()
//{
//	int a = 10;
//	int b = 9;
//	/*TestRef1();
//	TestRef2();
//	TestRef3();
//	TestRef4();*/
//	Swap(a, b);
//	printf("a=%d, b=%d\n", a, b);
//	TestRefReturn(a);
//	return 0;
//}

//实例引用
////int c;
//int& Add(int a, int b)//如果以引用类型做函数的返回值，则返回值的周期一定要比函数的周期长
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(3, 4);
//	//cout << "Add(3,4):" << ret << endl;
//	Add(4, 5);
//	//cout << "Add(3,4):" << Add(3,4) << endl;
//	//cout << "Add(4,5):" << Add(4, 5) << endl;
//	cout << "Add(3,4):" << ret << endl;
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int& ra = a;
//
//	//在定义上，引用与实体共用一块空间,没有独立的空间
//	printf("%p\n", &a); //012FF92C
//	printf("%p\n", &ra); //012FF92C
//  return 0;
//}


//int main()//引用在底层实现时，是由空间的，因为引用是按照指针的方式来实现的
//{
//	int a = 0;
//
//	int& ra = a;
//	ra = 20;
//
//	int* pa = &a;
//	*pa = 20;
//
//	return 0;
//}


//内联函数

int Add(int left, int right)
{
	return left + right;
}

//int main()
//{
//	int ret = 0;
//	ret = Add(1, 2);
//	return 0;
//}


//auto关键字

//int main()
//{
//	int a = 10;
//	auto ra = a;
//	auto rb = 'a';
//
//	cout << typeid(ra).name() << endl;
//	cout << typeid(rb).name() << endl;
//}


//基于范围的for循环

int main()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
		e *= 2;

	for (auto e : array)
		cout << e << endl;

	return 0;
}