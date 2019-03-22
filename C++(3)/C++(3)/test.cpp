#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#include <iostream>
using namespace std;

//1、声明和定义全部放在类体中
//class Student
//{
//public:
//	void SetStudentInfo(const char* name, const char* gender, int age)
//	{
//		strcpy(_name, name);
//		strcpy(_gender, gender);
//		_age = age;
//	}
//
//	void PrintStudentInfo()
//	{
//		cout << _name << " " << _gender << " " << _age << endl;
//	}
//private:
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//
//int main()
//{
//	Student s;
//	s.SetStudentInfo("Angel", "女", 20);
//	s.PrintStudentInfo();
//	return 0;
//}

//1、声明在头文件里，定义在cpp文件里

//在这里需要值指定SetStudentInfo这个函数是Student这个类域的
void Student::SetStudentInfo(const char* name, const char* gender, int age)
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}

void Student::PrintStudentInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}

//int main()
//{
//	Student s;
//	s.SetStudentInfo("Angel", "女", 19);
//	s.PrintStudentInfo();
//	return 0;
//}

//int main()
//{
//    printf("%d\n",offsetof(data, c));//用来求结构体内存的偏移量
//	return 0;
//}


