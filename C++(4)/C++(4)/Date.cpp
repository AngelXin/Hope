#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include <iostream>
using namespace std;

#if 0
//���캯��
class Date
{
public:
	//�޲ι��캯��
	Date()
	{
		cout << "Date:" << this<< endl;
	}

	//���ι��캯��
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void InitDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;//�����޲ι��캯��
	Date d2(2019, 3, 21);//���ô��ι��캯��
	//Date d3();//����������d3����������һ��Date���͵Ķ���

	d1.InitDate(2019,3, 27);
	d1.PrintDate();

	d2.InitDate(2019, 8, 12);
	d2.PrintDate();
	return 0;
}

#endif


#if 0
//�û�û�ж��幹�캯������������Զ����ɵĹ��캯����Ĭ�Ϲ��캯����һ�����޲ε�
class Date
{
public:
	//�޲ι��캯��
	/*Date()
	{
		cout << "Date:" << this << endl;
	}*/

	//ȫȱʡ���캯��
	Date(int year = 1900, int month = 8, int day = 10)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
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
	d1.PrintDate();

	Date d2(2019, 9, 9);
	d2.PrintDate();
	return 0;
}
#endif


#if 0
class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
		cout << _hour << "/" << _minute << "/" << _second << endl;
	}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
private:
	//�������ͣ��������ͣ�
	int _year;
	int _month;
	int _day;

	//�Զ�������
	Time _t;
};

int main()
{
	Date d1;
	return 0;
}
#endif


#include <malloc.h>
#include <assert.h>

#if 0
//��������

typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(sizeof(DataType)*capacity);
		assert(_pData);

		_size = 0;
		_capacity = capacity;
	}

	~SeqList()
	{
		if (_pData)
		{
			free(_pData);
			_pData = NULL;
			_size = 0;
			_capacity = 0;
		}
	}
private:
	int* _pData;
	size_t _size;
	size_t _capacity;
};

int main()
{
	SeqList s;
	return 0;
}
#endif


#if 0
class String
{
public:
	String(const char* str = " ")
	{
		cout << "String(const char* str = " ")" << endl;
		if (nullptr == str)
			str = " ";

		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		cout << "~String()" << endl;
		free(_str);
		_str = nullptr;
	}
private:
	char* _str;
};

class Person
{
private:
	String _name;
	String _gender;
	int _age;
};

int main()
{
	Person p;
	return 0;
}
#endif


#if 0
class String
{
public:
	String(const char* str = " ")
	{
		cout << "String(const char* str = " ")" << endl;
		if (nullptr == str)
			str = " ";

		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		cout << "~String()" << endl;
		free(_str);
		_str = nullptr;
	}
private:
	char* _str;
};

int main()
{
	String s1("hello");
	String s2(s1);//�������캯��
	return 0;
}
#endif


#if 0
class Date
{
public:

	//���캯��
	Date(int year = 1990, int month = 10, int day = 9)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	//�������캯������ʹ�����ô��Σ�ʹ�ô�ֵ��ʽ����������ĵݹ����
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << _year << "/" << _month << "/" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019,3,22);
	Date d2(d1);//ʹ��Ĭ�Ͽ������캯������û�д�ӡ������

	Date d3(2018, 4, 30);
	d3 = d1;
	
	return 0;
}
#endif


#if 0
class String
{
public:
	String(const char* str = "hello")
	{
		cout << "String(hello)" << endl;
		_str = (char*)malloc(sizeof(str)+1);
		strcpy(_str, str);
	}

	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};

int main()
{
	String s1("world");
	String s2(s1);//����Ĭ�ϵĿ������캯����ǳ������
	return 0;
}
#endif


//��ֵ���������

#if 0
//ȫ�ֵ�operator==
class Date
{
public:
	Date(int year = 1990, int month = 1, int day = 9)
	{
		_year = year;
		_month = month;
		_day = day;
	}
//private:
	int _year;
	int _month;
	int _day;
};

bool operator==(const Date& d1, const Date& d2)
{
	return d1._year == d2._year
		&& d1._month == d2._month
		&& d1._day == d2._day;
}

int main()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d2 == d1) << endl;
	return 0;
}
#endif


#if 0
//�����operator==
class Date
{
public:
	Date(int year = 1990, int month = 3, int day = 9)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	bool operator==(const Date& d2)
	{
		return _year == d2._year
			&& _month == d2._month
			&& _day == d2._day;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2018, 9, 21);
	Date d2(2018, 9, 22);
	cout << (d1 == d2) << endl;
	return 0;
}
#endif


#if 0
//operator=
class Date
{
public:
	Date(int year = 1990, int month = 3, int day = 9)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		cout << _year << "/" << _month << "/" << _day << endl;
		return *this;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2018, 9, 22);
	Date d2;
	//Date d2(d1);
	d1 = d2;
	return 0;
}
#endif
 

#if 0
//const��Ա����
class Date
{
public:
	Date(int year = 1990, int month = 8, int day = 9)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	/*void Display()
	{
		cout << "Display()" << endl;
		cout << _year << "-" << endl;
		cout << "-" << _month << endl;
		cout << "-" << _day << endl;
	}*/
	void Display()const
		//void Display(const Date* this)
	{
		cout << "Display()const" << endl;
		cout << _year << "-" << endl;
		cout << "-" << _month << endl;
		cout << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	d1.Display();

	const Date d2;
	d2.Display();
	return 0;
}
#endif


//����Date��

class Date
{
public:
	Date(int year = 1990, int month = 1, int day = 1)
	{
		if (month >= 1 && month <= 12)
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
			cout << "���ڷǷ�" << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		cout << _year << "/" << _month << "/" << _day << endl;
		return *this;
	}
	Date operator+(int days)
	{
		Date temp(*this);
		temp._day = temp._day + days;
		return temp;
	}

	Date operator-(int days)
	{
		Date temp(*this);
		temp._day = temp._day - days;
		return temp;
	}

	int operator-(const Date& d)//�������ڵļ������
	{
		Date Max(*this);
		Date Min(d);
		int flag = 1;
		if (*this < d)
		{
			Max = d;
			Min = *this;
			flag = -1;
		}
		int days = 0;
		while (Max > Min)
		{
			--Max;
			++days;
		}
		return days*flag;
	}

	Date& operator++()//ǰ��++
	{
		_day += 1;
		return *this;
	}

	Date operator++(int)//����++
	{
		Date temp(*this);
		_day += 1;
		return temp;
	}

	Date& operator--()//ǰ��--
	{
		_day -= 1;
		return *this;
	}

	Date operator--(int)//����--
	{
		Date temp(*this);
		_day -= 1;
		return temp;
	}

	bool operator>(const Date& d)const
	{
		if (_year > d._year)
			return true;

		else if (_year == d._year)
		{
			if (_month > d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day > d._day)
					return true;
			}
		}
		return false;

	}

	bool operator>=(const Date& d)const
	{
		return !(*this < d);
	}

	bool operator<(const Date& d)const
	{
		return !((*this > d) || (*this == d));
	}

	bool operator<=(const Date& d)const
	{
		return !(*this > d);
	}

	bool operator==(const Date& d)const
	{
		return (_year == d._year)
			&& (_month == d._month)
			&& (_day == d._day);
	}
	bool operator!=(const Date& d)const
	{
		return !((_year == d._year)
			&& (_month == d._month)
			&& (_day == d._day));
	}
	
	Date* operator&()
	{
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2(1990, 9, 8);
	cout << (d1 > d2) << endl;
	cout << (d1 < d2) << endl;
	return 0;
}