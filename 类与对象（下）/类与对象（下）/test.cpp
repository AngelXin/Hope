#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include <iostream>
using namespace std;

//��ʼ����ֻ����һ�Σ�,����ֵ�����ж��

#if 0
class Date
{
public:
	Date(int year=1990, int month=9, int day=8)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1;
	return 0;
}
#endif


#if 0
class A
{
public:
	A(int a)
		:_a(a)
	{
		cout << "A()" << endl;
	}
private:
	int _a;
};

class B
{
public:
	B(int a, int ref)
		: _aobj(a)
		, _ref(ref)
		, _n(1)
	{
		cout << "B()" << endl;
	}
private:
	A _aobj; //û��Ĭ�ϵĹ��캯��
	int& _ref;//����
	const int _n;//const
};
int main()
{
	A a1;
	B b1(a1, 2);
	return 0;
}
#endif


#if 0
class Time
{
public:
	Time(int hour = 0)
		:_hour(hour)
	{
		cout << "Time()" << endl;
	}
private:
	int _hour;
};

class Date
{
public:
	Date(int day)
	{

	}
private:
	int _day;
	Time _t;
};

int main()
{
	Date d(1);
	//return 0;
}
#endif


#if 0
#include <malloc.h>
class Array
{
public:
	Array(int size)//��Ա���������е���������������ڳ�ʼ���б��еĳ�ʼ��˳��
		//���ʼ���б��е�˳���޹�
		:_size(size)
		, _array((int*)malloc(sizeof(int)*_size))
	{}

	Array()
	{
		cout << "Array()" << endl;
	}
private:
	int* _array;
	int _size;
};

int main()
{
	Array a1(1);
	Array a2;
	return 0;
}
#endif


#if 0
class Test
{
public:
	explicit Test(int a)
	{}
};

int main()
{
	Test t1(10);
	//Test t1 = 10;
	Test t2 = t1;
}
#endif


#if 0
class Date
{
public:
	Date(int year)
		:_year(year)
	{}

	explicit Date(int year)
		:_year(year)
	{}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2018);

	//��ʽת����
	//��һ�����ͱ��������������ֵ
	//ʵ�ʱ������������2019����һ�����������������������d1������и�ֵ
	d1 = 2019;
}
#endif


#if 0
//��̬����
class Date
{
public:
	Date()
	{
		++_count;
		cout << _count << endl;
	}

	//��̬��Ա���������Ե��þ�̬��Ա����
	static void play()
	{
		cout << "play:" << _count << endl;
	}

	//�Ǿ�̬��Ա���������Ե�����ľ�̬��Ա����
	/*void play2()
	{
		cout << "play2:" << _count + 1 << endl;
	}*/
private:
	static int _count;
};
int Date::_count = 90;

int main()
{
	Date d1;
	Date::play();
	//Date::play2();
}
#endif


#if 0
//C++11�ĳ�Ա��ʼ�����淨
class A
{
public:
	A(int a = 9)
		:_a(a)
	{}

	int _a;
};

class B
{
public:
	void play()
	{
		cout << "b:" << b << endl;
		cout << "a:" << c._a << endl;
		cout << "p:" << p << endl;
	}

	static void play2()
	{
		cout << "static n:" << n + 1 << endl;
	}
private:
	//�Ǿ�̬��Ա�����������ڳ�Ա����ʱ��ֱ�ӳ�ʼ��
	int b = 1;
	A c = 80;
	int* p = (int*)malloc(4);
	static int n;
};

int B::n = 29;
int main()
{
	B b1;
	b1.play();
	b1.play2();
	return 0;
}
#endif


#if 0
//��Ԫ����
class Date
{
	//��Ԫ�������������е��κεط�����
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, const Date& d);

public:
	Date(int year = 1990, int month = 8, int day = 9)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator << (ostream& _cout, const Date& d)
{
	_cout << d._year << "/" << d._month << "/" << d._day;
	return _cout;
}

istream& operator>>(istream& _cin, const Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;

	return _cin;
}

int main()
{
	Date d;
	cin >> d;
	cout << d << endl;
	return 0;
}
#endif


#if 0
//��Ԫ��
class Date;//ǰ������
class Time
{
	//��Date��ΪTime�����Ԫ�࣬����Date���оͿ���ֱ�ӷ���Time���˽�б����ĳ�Ա
	friend class Date;
	
public:
	Time(int hour, int minute, int second)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year = 1990, int month = 9, int day = 8)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	void SetTimeofDate(int hour, int minute, int second)
	{
		//ֱ�ӷ���Time���еĳ�Ա����
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d;
}
#endif


#if 0
//�ڲ���
class A
{
public:
	A(int h1 = 1)
		:h(h1)
	{}

	//�ڲ���
	class B
	{
	public:
		void foo(const A& a)
		{
			cout << k << endl;
			cout << a.h << endl;
		}
	};


private:
	static int k;
	int h;
};

int A::k = 90;

int main()
{
	A::B b;
	b.foo(A());
	return 0;
}
#endif  


