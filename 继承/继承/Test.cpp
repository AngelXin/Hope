#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#if 0
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "Marry";
	int _age = 20;
};

class Student:public Person
{
protected:
	int _stuid;//学号
};

class Teacher :public Person
{
protected:
	int _jobid;//工号
};

int main()
{
	Student s;
	Teacher t;
	s.Print();
	t.Print();
	return 0;
}
#endif


//继承基类成员访问方式的变化
#if 0
class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name ;
private:
	int _age ;
};

class Student :public Person
{
private:
	int _stuid;//学号
};

class Teacher : protected Person
{
private:
	int _teaid;//工号
};

class Children :private Person
{
private:
	string _gender;
};


int main()
{
	Student s;
	//s._age = 10;
	s.Print();

	Teacher t;
	/*t.Print();
	t._age = 1;*/ //不可访问

	Children c;
	/*c.Print();
	c._name = "maoo";*/

	return 0;
}
#endif


#if 0
//派生类与基类间的赋值转换
class Person
{
public:
	Person()
	{
		cout << "Person:" << endl;
	}
	
protected:
	string _name;
	int _gender;
	int _age;
};

class Student :public Person
{
public:
	Student()
	{
		cout << "Student:" << endl;
	}

	int _No;//学号
};

void Test1()
{
	//1.派生类赋值给基类
	Student sobj;
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& p = sobj;

	//2.基类对象不能赋值给派生类对象
	//sobj = pobj;

	//3.基类指针可以通过强制类型转化赋值给派生类指针
	pp = &sobj;
	Student* sp1 = (Student*)pp;//通过强制类型转化
	sp1->_No = 19;

}

int main()
{
	Test1();
	return 0;
}
#endif


//继承中的作用域--同名对象
#if 0
class Person
{
public:
	double sum(double a,double b)
	{
		return a+b;
	}
protected:
	string _name;
	int _num = 11;//身份证号
};

class Student :public Person
{
public:
	void Print()
	{
		cout << "姓名：" << _name << endl;
		cout << "身份证号：" <<Person::_num << endl;
		cout << "学号：" << _num << endl;

	}

	int sum(int a)
	{
		return _num + a;
	}


protected:
	int _num = 99;//学号
};

void Test2()
{
	Student s;
	cout << s.sum(1.0) << endl;//只要函数名相同就构成隐藏,参数列表是否相同没有关系
	s.Print();
}

int main()
{
	Test2();
	return 0;
}
#endif


//继承中的作用域--同名函数
#if 0
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};

class B :public A
{
public:
	void fun(int i)
	{
		//A::fun();
		cout << "fun(int i)->" << i << endl;
	}
};

void Test3()
{
	B b;
	b.fun(10);
	//b.fun();无法编译
}
int main()
{
	Test3();
	return 0;
}
#endif


//派生类的默认成员函数
#if 0
class Person
{
public:
	//默认构造函数
	/*Person(const char* name)
	{
		_name = name;
		cout << "Person()" << endl;
	}*/

	//全缺省构造函数
	Person(const char* name="marry")
	{
		_name = name;
		cout << "Person()" << endl;
	}

	//默认拷贝构造函数
	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	//赋值重载函数
	Person& operator=(const Person& p)
	{
		cout << "Person operayor=(const Person& p)" << endl;
		if (this != &p)
		{
			_name = p._name;
		}
		return *this;
	}

	//析构函数
	~Person()
	{
		cout << "~Person()" << endl;
	}

protected:
	string _name;
};

class Student :public Person
{
public:

	//构造函数的初始化列表 
	Student(int num)
		: _num(num)
	{}

	//拷贝构造函数
	Student(const Student& s)
		:Person(s)
		, _num(s._num)
	{}

	//赋值重载函数
	Student operator=(const Student& s)
	{
		cout << "Student operator=(const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator=(s);
			_num = s._num;
		}
		return *this;
	}

	//析构函数
	~Student()
	{
		cout << "~Student()" << endl;
	}

protected:
	int _num;//学号
};

int main()
{
	Student s1(12);
	Student s2(s1);
	Person p1("Peter");
	return 0;
}
#endif

//面试题：实现一个不能被继承的类
#if 0
//方法一：C++98中的构造函数私有化，派生类中调不到基类的构造函数，则无法继承
#if 0
class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{
		cout << "NonInherit()" << endl;
	}
};

int main()
{
	NonInherit n;
	return 0;
}
#endif

//方法二：C++11中直接给了一个关键字final
class NonInherit final
{};

int mian()
{
	NonInherit n;
	return 0;
}
#endif


//继承与友元（友元无法继承）
#if 0
class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name;
};

class Student :public Person
{
public:
	int _stdnum;
};
void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._stdnum << endl;
}

int main()
{
	Person p;
	Student s;
	Display(p, s);
	return 0;
}
#endif


//继承与静态成员(静态成员只能在类外进行初始化)
class Person
{
public:
	Person()
	{
		++_count;
		cout << "Person()" << endl;
	}

protected:
	string _name;//姓名
public:
	static int _count;//统计人数
};

int Person::_count = 0;

class Student :public Person
{
protected:
	int _stdnum;//学生学号
};

class Graduate :public Student
{
protected:
	string _seminarCourse;//研究科目
};

void Test1()
{
	Student s1;
	Student s2;
	Student s3;
	Graduate g1;
	cout << Person::_count << endl;
	s1._count = 0;
	cout << Person::_count << endl;
}

int main()
{
	Test1();
	return 0;
}
