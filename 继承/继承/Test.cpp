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
	int _stuid;//ѧ��
};

class Teacher :public Person
{
protected:
	int _jobid;//����
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


//�̳л����Ա���ʷ�ʽ�ı仯
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
	int _stuid;//ѧ��
};

class Teacher : protected Person
{
private:
	int _teaid;//����
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
	t._age = 1;*/ //���ɷ���

	Children c;
	/*c.Print();
	c._name = "maoo";*/

	return 0;
}
#endif


#if 0
//������������ĸ�ֵת��
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

	int _No;//ѧ��
};

void Test1()
{
	//1.�����ำֵ������
	Student sobj;
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& p = sobj;

	//2.��������ܸ�ֵ�����������
	//sobj = pobj;

	//3.����ָ�����ͨ��ǿ������ת����ֵ��������ָ��
	pp = &sobj;
	Student* sp1 = (Student*)pp;//ͨ��ǿ������ת��
	sp1->_No = 19;

}

int main()
{
	Test1();
	return 0;
}
#endif


//�̳��е�������--ͬ������
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
	int _num = 11;//���֤��
};

class Student :public Person
{
public:
	void Print()
	{
		cout << "������" << _name << endl;
		cout << "���֤�ţ�" <<Person::_num << endl;
		cout << "ѧ�ţ�" << _num << endl;

	}

	int sum(int a)
	{
		return _num + a;
	}


protected:
	int _num = 99;//ѧ��
};

void Test2()
{
	Student s;
	cout << s.sum(1.0) << endl;//ֻҪ��������ͬ�͹�������,�����б��Ƿ���ͬû�й�ϵ
	s.Print();
}

int main()
{
	Test2();
	return 0;
}
#endif


//�̳��е�������--ͬ������
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
	//b.fun();�޷�����
}
int main()
{
	Test3();
	return 0;
}
#endif


//�������Ĭ�ϳ�Ա����
#if 0
class Person
{
public:
	//Ĭ�Ϲ��캯��
	/*Person(const char* name)
	{
		_name = name;
		cout << "Person()" << endl;
	}*/

	//ȫȱʡ���캯��
	Person(const char* name="marry")
	{
		_name = name;
		cout << "Person()" << endl;
	}

	//Ĭ�Ͽ������캯��
	Person(const Person& p)
		:_name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	//��ֵ���غ���
	Person& operator=(const Person& p)
	{
		cout << "Person operayor=(const Person& p)" << endl;
		if (this != &p)
		{
			_name = p._name;
		}
		return *this;
	}

	//��������
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

	//���캯���ĳ�ʼ���б� 
	Student(int num)
		: _num(num)
	{}

	//�������캯��
	Student(const Student& s)
		:Person(s)
		, _num(s._num)
	{}

	//��ֵ���غ���
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

	//��������
	~Student()
	{
		cout << "~Student()" << endl;
	}

protected:
	int _num;//ѧ��
};

int main()
{
	Student s1(12);
	Student s2(s1);
	Person p1("Peter");
	return 0;
}
#endif

//�����⣺ʵ��һ�����ܱ��̳е���
#if 0
//����һ��C++98�еĹ��캯��˽�л����������е���������Ĺ��캯�������޷��̳�
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

//��������C++11��ֱ�Ӹ���һ���ؼ���final
class NonInherit final
{};

int mian()
{
	NonInherit n;
	return 0;
}
#endif


//�̳�����Ԫ����Ԫ�޷��̳У�
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


//�̳��뾲̬��Ա(��̬��Աֻ����������г�ʼ��)
class Person
{
public:
	Person()
	{
		++_count;
		cout << "Person()" << endl;
	}

protected:
	string _name;//����
public:
	static int _count;//ͳ������
};

int Person::_count = 0;

class Student :public Person
{
protected:
	int _stdnum;//ѧ��ѧ��
};

class Graduate :public Student
{
protected:
	string _seminarCourse;//�о���Ŀ
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
