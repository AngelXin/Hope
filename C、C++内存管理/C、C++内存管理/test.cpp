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

	printf("malloc的分配值：");
	for (int i = 0; i < 5; i++)
	{
		printf("%d  ", *p1++);
	}

	printf("\n");
	printf("calloc的分配值：");
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

	printf("malloc的首地址：%x\n",p1);
	printf("realloc的首地址：%x\n", p2);
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
	//动态申请一个int类型的空间
	int* ptr4 = new int;

	//动态申请一个int类型的空间并初始化为10
	int* ptr5 = new int(10);

	//动态申请10个int类型的空间
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
//mew和delete的自定义操作
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
	//申请单个Test1类型的空间
	Test1* p1 = (Test1*)malloc(sizeof(int));
	printf("%d", *p1);
	free(p1);

	//申请10个Test1类型的空间
	Test1* p2 = (Test1*)malloc(sizeof(int)* 10);
	free(p2);
}

void Test3()
{
	//申请单个Test1类型的空间
	Test1* p3 = new Test1;
	printf("%d", *p3);
	free(p3);

	//申请10个Test1类型的空间
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
//operator new和operator delete

//利用带头节点的双向循环链表来证明
struct ListNode
{
	ListNode* _next;//结点后继
	ListNode* _prev;//结点前驱
	int _data;//结点的data值

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
		while (cur != _head)//有两个或两个以上的结点
		{
			ListNode* next = cur->_next;
			delete cur;
			cur = next;
		}
		delete _head;
		_head = nullptr;
	}
private:
	ListNode* _head;//头结点
};

int main()
{
	List l;
	return 0;
}
#endif

#if 0
//定位new表达式
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
//设计一个类，该类只能在堆上创建对象

//方法一：将构造函数私有化

//1.将该类的构造函数私有化，拷贝构造函数声明成为：私有化。
//防止别人调用调用拷贝在栈上生成对象
//2.提供一个静态的成员函数，在该静态函数中完成堆对象的创建

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
	//1.只声明，不实现。因为实现可能会很麻烦，而本身不需要
	//2.声明成私有
	HeapOnly(const HeapOnly&);

	//C++11
	//HeapOnly(const HeapOnly&) = delete;
};
#endif

#if 0
//设计一个类，该类只能在栈上创建对象
//方法：屏蔽new的功能
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

//单例模式：一个类只能创建一个对象

#if 0
//1.饿汉模式：不管将来用不用，程序启动时就创建一个唯一的实例对象

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		return &m_instance;
	}
private:
	//构造函数私有
	Singleton()
	{}

	//C++98 防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	//C++11
	/*Singleton(Singleton const&)=delete;
	Singleton& operator=(Singleton const&) = delete;*/

	static Singleton m_instance;
};

Singleton Singleton::m_instance;//在程序入口之前完成单例对象的初始化
#endif


#if 0
//2.懒汉模式

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		//注意这里一定要用Double-Check的方式加锁，才能保证效率和线程安全
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

	//实现一个内嵌垃圾回收
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
	//构造函数私有
	Singleton()
	{}

	//防拷贝
	Singleton(Singleton const&);
	Singleton& operator=(Singleton const&);

	static Singleton* m_pInstance;//单例对象指针
	static mutex m_mtx;//互斥锁
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


