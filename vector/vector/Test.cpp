#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#if 0
//vector的定义
int main()
{
	vector<int> v1;//无参构造
	vector<int> v2(4, 200);//构造并初始化4个200
	vector<int> v3(v2.begin(), v2.end());//区间构造，使用迭代器
	vector<int> v4(v3);//拷贝构造
	return 0;
}
#endif

#if 0
//iterator--迭代器的使用
void PrintVector(const vector<int>& v)
{
	//用const迭代器打印
	vector<int>::const_iterator it = v.cbegin();//定义迭代器
	cout << "const_iterator:" << endl;
	while (it != v.cend())
	{
		cout <<  *it << "  ";
		++it;
	}
	cout << endl;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	PrintVector(v);
	cout << endl;

	//用迭代器进行遍历打印
	vector<int>::iterator it = v.begin();
	cout << "iterator:" << endl;
	while (it != v.end())
	{
		cout <<*it << "  ";
		++it;
	}
	cout << endl;
	cout << endl;

	//用迭代器修改
	it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		it++;
	}

	//用反向迭代器遍历进行打印
	vector<int>::reverse_iterator rit = v.rbegin();
	cout << "reverse_iterator:" << endl;
	while (rit != v.rend())
	{
		cout << *rit << "  ";
		rit++;
	}
	cout << endl;

	return 0;
}
#endif

#if 0
//vector::capacity()
int main()
{
	size_t sz;
	vector<int> foo;
	sz = foo.capacity();
	cout << "foo grow" << endl;

	for (int i = 0; i < 100; i++)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			cout << "capacity change:" << sz << endl;
		}
	}
	return 0;
}
#endif

#if 0
//vector::reserve
int main()
{
	//一次一次的阔容
	size_t sz;
	vector<int> foo;
	sz = foo.capacity();
	cout << "foo grow" << endl;

	for (int i = 0; i < 100; i++)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			cout << "capacity change:" << sz << endl;
		}
	}
	cout << endl;


	vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);//提前预留空间
	cout << "bar grow!" << endl;

	for (int i = 0; i < 100; i++)
	{
		bar.push_back(i);
		if (sz != bar.capacity())
		{
			sz = bar.capacity();
			cout << "capacity change:" << sz << endl;
		}
	}
	return 0;
}
#endif

#if 0
//vector::resize
int main()
{
	vector<int> myvector;
	for (int i = 1; i < 10; i++)
	{
		myvector.push_back(i);
	}
	myvector.resize(5);
	myvector.resize(7,80);
	myvector.resize(12);

	cout << "myvector contains:" << endl;
	for (int i = 0; i < myvector.size(); i++)
	{
		cout << " " << myvector[i] << endl;
	}
	return 0;
}
#endif


//vector的增删改查

#if 0
//pop_back  push_back
int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	vector<int>::iterator it = v.begin();

	while (it != v.end())
	{
		cout << *it << "  ";
		it++;
	}
	cout << endl;

	v.pop_back();
	v.pop_back();
	v.push_back(8);

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << "  ";
		it++;
	}
	cout << endl;
	return 0;
}
#endif


//find  insert  erase
#if 0
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	//使用find查找2所在的位置的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 2);

	v.insert(pos, 29);//在pos位置之前插入29

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << "  ";
		it++;
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 3);
	v.erase(pos);//删除pos位置的数据

	it = v.begin();
	while (it != v.end())
	{
		cout << *it << "  ";
		it++;
	}
	cout << endl;

	return 0;
}
#endif

#if 0
//operator[]+index 和 C++11中的vector的新式for+auto的便遍历

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	//用operator[]
	v[0] = 9;
	cout << v[0] << endl;

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << "  ";
	}
	cout << endl;

	vector<int> sv;
	sv.swap(v);//交换swap

	cout << "sv data" << endl;
	for (size_t i = 0; i < sv.size(); i++)
	{
		cout << sv[i] << "  ";
	}
	cout << endl;

	cout << "v data" << endl;
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << "  ";
	}
	cout << endl;


	//用C++11支持的新式遍历
	for (auto x : sv)
	{
		cout << x << "  ";
	}
	cout << endl;

	return 0;
}
#endif

#if 0
//迭代器失效：底层空间改变 / 元素被删
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	//使用find查找2所在的位置的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 2);

	//删除pos位置的数据，导致pos的迭代器失效
	v.erase(pos);
	cout << *pos << endl;

	//insert可能会导致增容，增容后底层空间改变，
	//pos还是指向原来的空间，但是扩容后原来的空间早已被释放
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 29);//在pos位置之前插入29
	cout << *pos << endl;
	
	return 0;
}
#endif

#if 0
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	//迭代器失效——元素被删
	/*vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			v.erase(it);
		}
		++it;
	}*/

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
		{
			cout << *it << "  ";
			++it;
		}
	}
	cout << endl;
	return 0;
}
#endif

//vector的模拟实现
namespace vec
{
	template <class T>
	class vector
	{
	public:
		typedef T* Iterator;
		typedef const T* ConstIterator;

		Iterator Begin()  { return _start; }
		Iterator End()    { return _finish; }

		ConstIterator CBegin() const { return _start; }
		ConstIterator CEnd() const { return _finish; }

		size_t Size() { return _finish - _start; }
		size_t Capacity() { return _endOfStorage - _start; }

		//无参构造
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{ }

		//构造并初始化n个value
		vector(int n, const T& value = T())
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(n);
			while (n--)
			{
				PushBack(value);
			}
		}

		//重新声明迭代器，迭代器的区间[first,last]可以是任意容器的迭代器区间
		//区间构造
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			Reserve(last - first);
			while (first != last)
			{
				PushBack(*first);
				++first;
			}
		}

		//拷贝构造
		vector(vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			Reserve(v.Capacity());

			Iterator it = Begin();
			ConstIterator vit = v.CBegin();
			while (vit != v.CEnd())
			{
				*it++ = *vit++;
			}
			_finish = _start + v.Size();
			_endOfStorage = _start + v.Capacity();
		}

		//赋值运算符重载
		vector<T>& operator=(vector<T> v)
		{
			Swap(v);
			return *this;
		}

		//析构函数
		~vector()
		{
			delete[]_start;
			_start = _finish = _endOfStorage = nullptr;
		}

		//预留空间
		void Reserve(size_t n)
		{
			if (n > Capacity())
			{
				size_t size = Size();
				T* tmp = new T[n];

				if (_start)
				{
					for (size_t i = 0; i < size; i++)
						tmp[i] = _start[i];
				}

				_start = tmp;
				_finish = _start + size;
				_endOfStorage = _start + n;
			}
		}

		void Resize(size_t n, const T& value = T())
		{
			//1.如果n小于当前的size,则数据个数缩小到n
			if (n <= Size())
			{
				_finish = _start + n;
				return;
			}

			//2.空间不够，则需扩容
			if (n > Capacity())
			{
				Reserve(n);
			}

			//3.将size扩大到n
			Iterator it = _finish;
			Iterator _finish = _start + n;//新的有效元素个数
			while (it != _finish)
			{
				*it = value;
				it++;
			}
		}

		//交换
		void Swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}

		//尾插
		void PushBack(const T& x)
		{
			Insert(End(), x);
		}

		//尾删
		void PopBack()
		{
			Erase(--End());
		}

		//在pos位置前插入
		Iterator Insert(Iterator pos, const T& x)
		{
			assert(pos <= End());

			//空间不够，先扩容
			if (_finish == _endOfStorage)
			{
				size_t size = Size();
				size_t newcapacity = Capacity() == 0 ? 1: Capacity() * 2;

				Reserve(newcapacity);
				pos = _start + size;
			}
			Iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		//erase
		Iterator Erase(Iterator pos)
		{
			Iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}

			--_finish;

			return pos;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}

		void printvector(const vector<int>& v)
		{
			vector<int>::ConstIterator it = v.CBegin();
			while (it != v.CEnd())
			{
				cout << *it << "  ";
				++it;
			}
			cout << endl;
		}

	private:
		Iterator _start;//指向数据块的开始
		Iterator _finish;  //指向有效数据的结束
		Iterator _endOfStorage;//指向存储容量的尾
	};
}


void Tets1()
{
	//构造
	vec::vector<int> v1;
    vec::vector<int> v2(4, 19);

	int a[] = { 1, 2, 3, 4, 5 };
	vec::vector<int> v3(a, a + sizeof(a) / sizeof(int));

	vec::vector<int> v4(v2);
	for (vec::vector<int>::Iterator it = v4.Begin(); it != v4.End(); ++it)
		cout << *it << "  ";
	cout << endl;
	

	cout << "v1:" << endl;
	v1.PushBack(19);
	v1.PushBack(20);
	v1.PushBack(21);
	v1.PushBack(22);
	v1.PushBack(23);
	v1.PushBack(24);
	v1.PushBack(25);
	v1.printvector(v1);

	vec::vector<int>::Iterator pos = find(v1.Begin(), v1.End(), 20);
	v1.Insert(pos, 9);
	v1.printvector(v1);

}




int main()
{
	Tets1();
	return 0;
}
