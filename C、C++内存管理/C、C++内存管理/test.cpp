#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <iostream>
using namespace std;


#if 0
//malloc/calloc/realloc
void Test1()
{
	int size = 200;
	int* p1 = (int*)malloc(sizeof(int)*5);
	int* p2 = (int*)calloc(5, sizeof(int));

	printf("malloc�ķ���ֵ��");
	for (int i = 0; i < 5; i++)
	{
		printf("%d  ", *p1++);
	}

	printf("\n");
	printf("calloc�ķ���ֵ��");
	for (int j = 0; j < 5; j++)
	{
		printf("%d  ", *p2++);
	}

}

void Test2()
{
	int size = 2000;
	int* p1 = (int*)malloc(size * sizeof(int));
	int* p2 = (int*)realloc(p1,sizeof(int)*20);

	printf("malloc���׵�ַ��%x\n",p1);
	printf("realloc���׵�ַ��%x\n", p2);
}

int main()
{
	//Test1();
	Test2();
	return 0;
}
#endif


#if 0
void Test2()
{
	//��̬����һ��int���͵Ŀռ�
	int* ptr4 = new int;

	//��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
	int* ptr5 = new int(10);

	//��̬����10��int���͵Ŀռ�
	int* ptr6 = new int[3];

	delete ptr4;
	delete ptr5;
	delete[] ptr6;
}

int main()
{
	Test2();
	return 0;
}
#endif


#if 0
//mew��delete���Զ������
class Test1
{
public:
	Test1()
		:_data(0)
	{
		cout << "Test()" << endl;
	}

	~Test1()
	{
		cout << "~Test()" << endl;
	}
private:
	int _data;
};

void Test2()
{
	//���뵥��Test1���͵Ŀռ�
	Test1* p1 = (Test1*)malloc(sizeof(int));
	printf("%d", *p1);
	free(p1);

	//����10��Test1���͵Ŀռ�
	Test1* p2 = (Test1*)malloc(sizeof(int)* 10);
	free(p2);
}

void Test3()
{
	//���뵥��Test1���͵Ŀռ�
	Test1* p3 = new Test1;
	printf("%d", *p3);
	free(p3);

	//����10��Test1���͵Ŀռ�
	Test1* p4 = new Test1[10];
	free(p4);
}

int main()
{
	//Test2();
	Test3();
	return 0;
}
#endif


#if 0
//operator new��operator delete

//���ô�ͷ�ڵ��˫��ѭ��������֤��
struct ListNode
{
	ListNode* _next;//�����
	ListNode* _prev;//���ǰ��
	int _data;//����dataֵ

	void* operator new(size_t n)
	{
		void* p = nullptr;
		p = allocator<ListNode>().allocate(1);
		cout << "memory pool allocator" << endl;
		return p;
	}

	void operator delete(void* p)
	{
		allocator<ListNode>().deallocate((ListNode*)p, 1);
		cout << "memory pool deallocate" << endl;
	}
};

class List
{
public:
	List()
	{
		_head = new ListNode;
		_head->_next = _head;
		_head->_prev = _head;
	}

	~List()
	{
		ListNode* cur = _head->_next;
		while (cur != _head)//���������������ϵĽ��
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;//ͷ���
};

int main()
{
	List l;
	return 0;
}
#endif

#if 0
//��λnew���ʽ
class Test
{
public:
	Test()
		:_data(0)
	{
		cout << "Test()" << this << endl;
	}

	~Test()
	{
		cout << "~Test()" << this << endl;
	}
private:
	int _data;
};

void Test1()
{
	Test* pt = (Test*)malloc(sizeof(Test));

	new(pt)Test;
}

int main()
{
	Test1();
	return 0;
}
#endif

#if 0
int main()
{
	int array[4] = { 0 };
	new(array + 3)int(3);

	return 0;
}
#endif


#if 0
//���һ���࣬����ֻ���ڶ��ϴ�������

//����һ�������캯��˽�л�

//1.������Ĺ��캯��˽�л����������캯��������Ϊ��˽�л���
//��ֹ���˵��õ��ÿ�����ջ�����ɶ���
//2.�ṩһ����̬�ĳ�Ա�������ڸþ�̬��������ɶѶ���Ĵ���

class HeapOnly
{
public:
	static HeapOnly* CreatObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly(){}
	
	//C++98 
	//1.ֻ��������ʵ�֡���Ϊʵ�ֿ��ܻ���鷳����������Ҫ
	//2.������˽��
	HeapOnly(const HeapOnly&);

	//C++11
	//HeapOnly(const HeapOnly&) = delete;
};
#endif

#if 0
//���һ���࣬����ֻ����ջ�ϴ�������
//����������new�Ĺ���
class StackOnly
{
public:
	StackOnly()
	{}
private:
	void* operator new(size_t size);
	void operator delete(void* p);
};
#endif

//����ģʽ��һ����ֻ�ܴ���һ������

#if 0
//1.����ģʽ�����ܽ����ò��ã���������ʱ�ʹ���һ��Ψһ��ʵ������

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	//���캯��˽��
	Singleton()
	{}

	//C++98 ������
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	//C++11
	/*Singleton(Singleton const&)=delete;
	Singleton& operator=(Singleton const&) = delete;*/

	static Singleton m_instance;
};

Singleton Singleton::m_instance;//�ڳ������֮ǰ��ɵ�������ĳ�ʼ��
#endif


#if 0
//2.����ģʽ

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		//ע������һ��Ҫ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ
		if (nullptr == m_pInstance)
		{
			m_mtx.lock();
			if (nullptr == m_pInstance)
			{
				m_pInstance = new Singleton();
			}
			m_mtx.unlock();
		}
		return m_pInstance;
	}

	//ʵ��һ����Ƕ��������
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (Singleton::m_pInstance)
				delete Singleton::m_pInstance;
		}
	};

private:
	//���캯��˽��
	Singleton()
	{}

	//������
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	static Singleton* m_pInstance;//��������ָ��
	static mutex m_mtx;//������
};

Singleton* Singleton::m_pInstance = nullptr;
Singleton::CGarbo Garbo;
mutex Singleton::m_mtx;

void func(int n)
{
	cout << Singleton::GetInstance() << endl;
}

int main()
{
	thread t1(func, 10);
	thread t2(func, 10);

	t1.join();
	t2.join();

	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;
	return 0;
}

#endif


