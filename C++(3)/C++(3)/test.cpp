#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

#include <iostream>
using namespace std;

//1�������Ͷ���ȫ������������
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
//	s.SetStudentInfo("Angel", "Ů", 20);
//	s.PrintStudentInfo();
//	return 0;
//}

//1��������ͷ�ļ��������cpp�ļ���

//��������Ҫֵָ��SetStudentInfo���������Student��������
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
//	s.SetStudentInfo("Angel", "Ů", 19);
//	s.PrintStudentInfo();
//	return 0;
//}

//int main()
//{
//    printf("%d\n",offsetof(data, c));//������ṹ���ڴ��ƫ����
//	return 0;
//}


