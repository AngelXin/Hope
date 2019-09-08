#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>
#include <String>
using namespace std;

#if 0
class Person{
public:
	//虚函数就是在类的成员函数的前面加上“virtual”的关键字
	virtual void BuyTicket(){ cout << "买票全价" << endl; }
};

int main()
{
	Person p;
	p.BuyTicket();
	return 0;
}
#endif


#if 0
//虚函数的重写
class Person{
public:
	virtual void BuyTicket(){ cout << "买票全价" << endl; }
};

class Student :public Person{
public:
	virtual void BuyTicket(){ cout << "买票半价" << endl; }
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
//虚函数重写的例外1：协变
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
//虚函数重写的例外2：析构函数的重写
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
//抽象类：虚函数后面写上=0，为纯虚函数；包含纯虚函数的类为抽象类
class Car{
public:
	virtual void Driver() = 0;//纯虚函数（无法实例化）
};

class Benz :public Car{
	virtual void Driver(){
		cout << "Benz-舒服" << endl;
	}
};

int main()
{
	Car* pBenz = new Benz;
	pBenz->Driver();
	return 0;
}
#endif


//修饰派生类虚函数强制完成重写--override/final

#if 0
class Car
{
	//1、final修饰基类的虚函数不能被派生类重写
public:
	virtual void Drive() final{}
};

class Benz :public Car
{
public:
	virtual void Drive() { cout << "Benz-舒服" << endl; }
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
	//2、override:修饰派生类虚函数强制完成重写，如派生类没有完成重写则报错
public:
	virtual void Drive() override { cout << "Benz-舒服" << endl; }
};
#endif


#if 0
//虚函数表
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
//虚表中存的是虚函数指针，对象中存的是虚表指针
int main()
{
	Base b; 
	Drive d;
	return 0;
}
#endif


class Person{
public:
	virtual void Buyticket(){ cout << "买全价票" << endl; }
};

class Student :public Person{
public:
	virtual void Buyticket(){ cout << "买半价票" << endl; }
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