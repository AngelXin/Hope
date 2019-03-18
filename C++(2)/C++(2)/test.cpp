#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>
using namespace std;

//����
//
//void Swap1(int a, int b)//��ֵ����
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Swap2(int* a, int* b)//����ַ���� 
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


//����

void TestRef1()//���ø���
{
	int a = 10;
	int& ra = a;
	ra = 20;

	printf("%d\n", a);
	printf("%d\n", ra);
}

void TestRef2()//��������
{
	int a = 10;//1��һ�����������ж������
	int b = 9;
	int& ra = a;
	int& rra = b;
	rra = 0;
	ra = 8;

	//int& b;//2�������ڶ����Ǳ����ʼ��

	//int& ra = b;//3������һ������һ��ʵ�壬�Ͳ�������������ʵ��

	printf("%d\n", a);
	printf("%d\n", ra);
	printf("%d\n", rra);
	printf("%d\n",b);
}

void TestRef3()//������
{
	/*const int a = 10;
	const int& ra = a;*/

	const double d = 9.9;
	const double& rd = d;

	printf("%f\n", d);
	printf("%f\n", rd);
}


//void TestRef4()//ʹ�ó���
//{
//	int a = 10;
//	int b = 9;
//	int& ra = a;
//	int& rb = b;
//	//1��������
//	Swap(ra, rb);
//	
//	//2��������ֵ
//	TestRefReturn(a);
//}

void Swap(int& ra, int& rb)//������
{
	int temp = ra;
	ra = rb;
	rb = temp;

	printf("a=%d\n", ra);
	printf("b=%d\n", rb);
}

int& TestRefReturn(int& c)//������ֵ
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

//ʵ������
////int c;
//int& Add(int a, int b)//��������������������ķ���ֵ���򷵻�ֵ������һ��Ҫ�Ⱥ��������ڳ�
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
//	//�ڶ����ϣ�������ʵ�干��һ��ռ�,û�ж����Ŀռ�
//	printf("%p\n", &a); //012FF92C
//	printf("%p\n", &ra); //012FF92C
//  return 0;
//}


//int main()//�����ڵײ�ʵ��ʱ�����ɿռ�ģ���Ϊ�����ǰ���ָ��ķ�ʽ��ʵ�ֵ�
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


//��������

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


//auto�ؼ���

//int main()
//{
//	int a = 10;
//	auto ra = a;
//	auto rb = 'a';
//
//	cout << typeid(ra).name() << endl;
//	cout << typeid(rb).name() << endl;
//}


//���ڷ�Χ��forѭ��

int main()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
		e *= 2;

	for (auto e : array)
		cout << e << endl;

	return 0;
}