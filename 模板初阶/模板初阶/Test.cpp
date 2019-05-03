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
//����ģ���ʵ����

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

	Add(a1, (int)b2);//1.��ʽʵ�������ñ���������ʵ������ģ�������ʵ������
	cout << "Add(a1, (int)b2):" << Add(a1, (int)b2) << endl;

	Add<int>(a2, b1);//��ʽʵ�������ں������ĺ���<>���ƶ�ģ�������ʵ������
	cout << "Add<int>(a2, b1):" << Add<int>(a2, b1) << endl;

	return 0;
}
#endif

#if 0
//ģ�������ƥ��ԭ��
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
	Add(1, 3);//���ģ�����ƥ�䣬���ú���ģ��ʵ����
	int a = 1.2, b = 9;
	cout << "Add((int)a, b):" << Add((int)a, b) << endl;//��ʽʵ����
	cout << a << " " << b << endl;
	cout << "Add<int>(a,b):" << Add<int>(a,b) << endl;//��ʽʵ����
}

int main()
{
	Test1();
	return 0;
}
#endif


#if 0
//���ڷ�ģ�庯����ͬ�����������������������ͬ����������Ҳ����ͬ��
//ϵͳ�����ȵ��÷�ģ�庯�����������ģ����Բ���һ�����и���ƥ��ĺ�������ô��ѡ��ģ��

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
	
	cout << "Add(1.2,3):" << Add(1.2,3) << endl;//��ʽʵ����
	cout << "Add<int>(1.2,3):" << Add<int>(1.2, 3) << endl;//��ʽʵ����
	return 0;
}
#endif


//��ģ��
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

	~Vector();//�����ⶨ��

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