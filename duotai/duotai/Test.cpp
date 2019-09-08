#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>
#include <String>
using namespace std;

#if 0
class Person{
public:
	//�麯����������ĳ�Ա������ǰ����ϡ�virtual���Ĺؼ���
	virtual void BuyTicket(){ cout << "��Ʊȫ��" << endl; }
};

int main()
{
	Person p;
	p.BuyTicket();
	return 0;
}
#endif


#if 0
//�麯������д
class Person{
public:
	virtual void BuyTicket(){ cout << "��Ʊȫ��" << endl; }
};

class Student :public Person{
public:
	virtual void BuyTicket(){ cout << "��Ʊ���" << endl; }
};

void Fun(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person ps;
	Student st;

	Fun(ps);
	Fun(st);

	return 0;
}
#endif

#if 0
//�麯����д������1��Э��
class A{};

class B :public A{};

class Person{
public:
	virtual A* f(){ 
		cout << "A" << endl;
		return new A;}
};

class Student : public Person{
public:
	virtual B* f(){ 
		cout <<"B"<< endl;
		return new B; }
};

int main()
{
	Person p;
	Student s;

	p.f();
	s.f();

	return 0;
}
#endif


#if 0
//�麯����д������2��������������д
class Person{
public:
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};

class Student :public Person
{
public:
	virtual ~Student()
	{
		cout << "~Student" << endl;
	}
};

int main()
{
	Person* p1 = new Person;
	Student* s1 = new Student;

	delete p1;
	delete s1;
	return 0;
}
#endif


#if 0
//�����ࣺ�麯������д��=0��Ϊ���麯�����������麯������Ϊ������
class Car{
public:
	virtual void Driver() = 0;//���麯�����޷�ʵ������
};

class Benz :public Car{
	virtual void Driver(){
		cout << "Benz-���" << endl;
	}
};

int main()
{
	Car* pBenz = new Benz;
	pBenz->Driver();
	return 0;
}
#endif


//�����������麯��ǿ�������д--override/final

#if 0
class Car
{
	//1��final���λ�����麯�����ܱ���������д
public:
	virtual void Drive() final{}
};

class Benz :public Car
{
public:
	virtual void Drive() { cout << "Benz-���" << endl; }
};
#endif


#if 0
class Car
{
public:
	virtual void Drive() {}
};

class Benz :public Car
{
	//2��override:�����������麯��ǿ�������д����������û�������д�򱨴�
public:
	virtual void Drive() override { cout << "Benz-���" << endl; }
};
#endif


#if 0
//�麯����
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}

	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};

class Drive :public Base
{
public:
	virtual void Func1()
	{
		cout << "Drive::Func1()" << endl;
	}

	virtual void Func4()
	{
		cout << "Drive::Func4()" << endl;
	}
private:
	int _d = 2;
};
//����д�����麯��ָ�룬�����д�������ָ��
int main()
{
	Base b; 
	Drive d;
	return 0;
}
#endif


class Person{
public:
	virtual void Buyticket(){ cout << "��ȫ��Ʊ" << endl; }
};

class Student :public Person{
public:
	virtual void Buyticket(){ cout << "����Ʊ" << endl; }
};

void Func(Person& p)
{
	p.Buyticket();
}

int main()
{
	Person Marry;
	Func(Marry);

	Student Bob;
	Func(Bob);

	return 0;
}