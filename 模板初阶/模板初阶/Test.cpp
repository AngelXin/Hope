#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>
using namespace std;

#if 0
template<class T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}
int main()
{
	int a = 10 ;
	int b = 9;

	Swap(a, b);
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	return 0;
}
#endif


#if 0
//函数模板的实例化

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

int main()
{
	int a1 = 19, a2 = 90;
	double b1 = 19.6, b2 = 3.4;

	cout << "Add(a1, a2):" << Add(a1, a2) << endl;
	cout << "Add(b1, b2):" << Add(b1, b2) << endl;

	Add(a1, (int)b2);//1.隐式实例化：让编译器根据实参推理模板参数的实际类型
	cout << "Add(a1, (int)b2):" << Add(a1, (int)b2) << endl;

	Add<int>(a2, b1);//显式实例化：在函数名的后面<>中制定模板参数的实际类型
	cout << "Add<int>(a2, b1):" << Add<int>(a2, b1) << endl;

	return 0;
}
#endif

#if 0
//模板参数的匹配原则
int Add(int a, int b)
{
	return a + b;
}

template<class T>
T Add(const T& a,const T& b)
{
	return a + b;
}

void Test1()
{
	Add(1, 3);//与非模板参数匹配，不用函数模板实例化
	int a = 1.2, b = 9;
	cout << "Add((int)a, b):" << Add((int)a, b) << endl;//隐式实例化
	cout << a << " " << b << endl;
	cout << "Add<int>(a,b):" << Add<int>(a,b) << endl;//显式实例化
}

int main()
{
	Test1();
	return 0;
}
#endif


#if 0
//对于非模板函数与同名函数，如果其他条件都相同，参数类型也都相同，
//系统会优先调用非模板函数；但是如果模板可以产生一个具有更好匹配的函数，那么将选择模板

int Add(int left, int right)
{
	return left + right;
}

template<class T1,class T2>
T1 Add(const T1& a,const T2& b)
{
	return a + b;
}

int main()
{
	Add(1, 2);
	
	cout << "Add(1.2,3):" << Add(1.2,3) << endl;//隐式实例化
	cout << "Add<int>(1.2,3):" << Add<int>(1.2, 3) << endl;//显式实例化
	return 0;
}
#endif


//类模板
#include <assert.h>
template<class T>
class Vector
{
public:
	Vector(size_t capacity = 10)
		:_pData(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}

	~Vector();//在类外定义

	void PushBack(const T& data)
	{
		_pData[_size++] = data;
	}

	void PopBack()
	{
		--_size;
	}

	size_t Size()
	{
		return _size;
	}

	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return _pData[pos];
	}

private:
	T* _pData;
	size_t _size;
	size_t _capacity;
};

template<class T>
Vector<T>::~Vector()
{
	if (_pData)
	{
		delete[]_pData;
	}
}

int main()
{
	Vector<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);

	Vector<double>s2;
	s2.PushBack(1.1);
	s2.PushBack(2.2);
	s2.PushBack(3.3);

	for (size_t i = 0; i < s1.Size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < s2.Size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;

	return 0;
}