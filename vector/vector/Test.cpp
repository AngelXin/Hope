#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#if 0
//vector�Ķ���
int main()
{
	vector<int> v1;//�޲ι���
	vector<int> v2(4, 200);//���첢��ʼ��4��200
	vector<int> v3(v2.begin(), v2.end());//���乹�죬ʹ�õ�����
	vector<int> v4(v3);//��������
	return 0;
}
#endif

#if 0
//iterator--��������ʹ��
void PrintVector(const vector<int>& v)
{
	//��const��������ӡ
	vector<int>::const_iterator it = v.cbegin();//���������
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

	//�õ��������б�����ӡ
	vector<int>::iterator it = v.begin();
	cout << "iterator:" << endl;
	while (it != v.end())
	{
		cout <<*it << "  ";
		++it;
	}
	cout << endl;
	cout << endl;

	//�õ������޸�
	it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		it++;
	}

	//�÷���������������д�ӡ
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
	//һ��һ�ε�����
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
	bar.reserve(100);//��ǰԤ���ռ�
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


//vector����ɾ�Ĳ�

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

	//ʹ��find����2���ڵ�λ�õ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 2);

	v.insert(pos, 29);//��posλ��֮ǰ����29

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << "  ";
		it++;
	}
	cout << endl;

	pos = find(v.begin(), v.end(), 3);
	v.erase(pos);//ɾ��posλ�õ�����

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
//operator[]+index �� C++11�е�vector����ʽfor+auto�ı����

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	//��operator[]
	v[0] = 9;
	cout << v[0] << endl;

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << "  ";
	}
	cout << endl;

	vector<int> sv;
	sv.swap(v);//����swap

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


	//��C++11֧�ֵ���ʽ����
	for (auto x : sv)
	{
		cout << x << "  ";
	}
	cout << endl;

	return 0;
}
#endif

#if 0
//������ʧЧ���ײ�ռ�ı� / Ԫ�ر�ɾ
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	//ʹ��find����2���ڵ�λ�õ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 2);

	//ɾ��posλ�õ����ݣ�����pos�ĵ�����ʧЧ
	v.erase(pos);
	cout << *pos << endl;

	//insert���ܻᵼ�����ݣ����ݺ�ײ�ռ�ı䣬
	//pos����ָ��ԭ���Ŀռ䣬�������ݺ�ԭ���Ŀռ����ѱ��ͷ�
	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 29);//��posλ��֮ǰ����29
	cout << *pos << endl;
	
	return 0;
}
#endif

#if 0
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	//������ʧЧ����Ԫ�ر�ɾ
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

//vector��ģ��ʵ��
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

		//�޲ι���
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{ }

		//���첢��ʼ��n��value
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

		//����������������������������[first,last]���������������ĵ���������
		//���乹��
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

		//��������
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

		//��ֵ���������
		vector<T>& operator=(vector<T> v)
		{
			Swap(v);
			return *this;
		}

		//��������
		~vector()
		{
			delete[]_start;
			_start = _finish = _endOfStorage = nullptr;
		}

		//Ԥ���ռ�
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
			//1.���nС�ڵ�ǰ��size,�����ݸ�����С��n
			if (n <= Size())
			{
				_finish = _start + n;
				return;
			}

			//2.�ռ䲻������������
			if (n > Capacity())
			{
				Reserve(n);
			}

			//3.��size����n
			Iterator it = _finish;
			Iterator _finish = _start + n;//�µ���ЧԪ�ظ���
			while (it != _finish)
			{
				*it = value;
				it++;
			}
		}

		//����
		void Swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}

		//β��
		void PushBack(const T& x)
		{
			Insert(End(), x);
		}

		//βɾ
		void PopBack()
		{
			Erase(--End());
		}

		//��posλ��ǰ����
		Iterator Insert(Iterator pos, const T& x)
		{
			assert(pos <= End());

			//�ռ䲻����������
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
		Iterator _start;//ָ�����ݿ�Ŀ�ʼ
		Iterator _finish;  //ָ����Ч���ݵĽ���
		Iterator _endOfStorage;//ָ��洢������β
	};
}


void Tets1()
{
	//����
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
