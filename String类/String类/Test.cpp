#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#if 0
//String类对象的常见构造
void TestString1()
{
	string s1;//构造空的string类对象s1
	string s2("hello world");//用C格式字符串来构造string类对象s2
	string s3(10, 't');//用10个字符‘t’来构造string类对象s3
	string s4(s3);//拷贝构造s4
	string s5(s2, 5);//用s2的前5个字符来构造string类对象s5

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
}
int main()
{
	TestString1();
	return 0;
}
#endif

#if 0
//String类对象的常见容量操作
void TestString2()
{
	string s("hello,world!");
	cout << s.size() << endl;
	cout << s.length() << endl;//12
	cout << s.capacity() << endl;//15
	cout << s.empty() << endl;
	cout << s << endl;
	cout << " "<< endl;

	//清空s里的字符串
	s.clear();
	cout << s.size() << endl;
	cout << s.length() << endl;//0
	cout << s.capacity() << endl;//15
	cout << s << endl;
	cout << " " << endl;

	//将S中的有效字符个数增大到18个，多出的字符用‘t’来填充
	s.resize(18, 't');
	cout << s.size() << endl;
	cout << s.length() << endl;//18
	cout << s.capacity() << endl;//31(成倍的扩容)
	cout << s << endl;
	cout << " " << endl;

	//将S中的有效字符个数增大到19个，多出的字符用0来填充
	s.resize(19);
	cout << s.size() << endl;
	cout << s.length() << endl;//18
	cout << s.capacity() << endl;//31(成倍的扩容)
	cout << s << endl;
	cout << " " << endl;

	//将s中的有效字符的个数缩小到6个
	s.resize(5);
	cout << s.size() << endl;
	cout << s.length() << endl;//5
	cout << s.capacity() << endl;//31
	cout << s << endl;
	cout << " " << endl;
}

void TestString3()
{
	string s("I like it");
	cout << s.size() << endl;//9
	cout << s.capacity() << endl;//15
	cout << " " << endl;

	//reserve():为字符串预留空间
	//增大
	s.reserve(100);
	cout << s.size() << endl;//9
	cout << s.capacity() << endl;//111
	cout << " " << endl;

	//减小(不会改变容量大小)
	s.reserve(10);
	cout << s.size() << endl;//9
	cout << s.capacity() << endl;//15
	cout << " " << endl;
}
int main()
{
	//TestString2();
	TestString3();
	return 0;
}
#endif

#if 0
//string类对象的访问操作
void TestString4()
{
	string s1("i like it");
	const string s2("I like it");
	cout << s1 << "   " << s2 << endl;
	cout << s1[0] << "   " << s2[0] << endl;
	cout << " " << endl;

	s1[0] = 'I';//修改s1的第一位
	cout << s1 << endl;
	cout << " " << endl;

	//s2[0] = 'o';//const类型不能修改

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << endl;
	}
}
int main()
{
	TestString4();
	return 0;
}
#endif

# if 0
//string类对象的修改操作
void TestString5()
{
	string s1("hello,world");
	string s2("  me");
	s1.push_back('!');//追加字符
	s1.append("i like");//追加字符串
	cout << s1 << endl;

	s1 += 'y';
	cout << s1 << endl;
	s1 += "ou";

	cout << s1 << endl;
	cout << s1.c_str() << endl;//返回C格式字符串

	s1 += s2;
	cout << s1 << endl;
}

void TestString6()
{
	//获取file1的后缀
	string file1("string.cpp");
	size_t pos = file1.rfind('.');
	string s2(file1.substr(pos, file1.size() - pos));
	cout << s2 << endl;
	cout << " " << endl;

	//取出str中的域名(www.cplusplus.com)
	string str("http://www.cplusplus.com/reference/string/string/rfind/");
	cout << str << endl;
	size_t start = str.find("://")+3;
	size_t finish = str.find('/', start);
	string address = str.substr(start, finish - start);
	cout << address << endl;

	//删除str的前缀
	pos = str.find("://");
	str.erase(0, pos + 3);
	cout << str << endl;
}

void TestPushBack()
{
	//观察capacity每次系统自动扩容的大小（程度）
	
	string s;
	size_t sz = s.capacity();
	cout << "making a grow:\n";
	for (int i = 0; i < 100; i++)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}

void TestPushBack_P()
{
	//利用reserve提高插入数据的效率，避免增容带来的开销

	string s;
	s.reserve(100);//预留100个字节的空间
	size_t sz = s.capacity();

	cout << "making a grow:\n";
	for (int i = 0; i < 100; i++)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}

int main()
{
	//TestString5();
	//TestString6();
	//TestPushBack();
	TestPushBack_P();
	return 0;
}
#endif

#if 0
//找字符串中第一次只出现一次的字符(面试题)
int firstUniqChar(string s)
{
	//统计每个字符出现的次数
	int count[256] = { 0 };
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		count[s[i]] += 1;
	}

	//按照字符次序从前往后找出只出现一次的字符
	for (int i = 0; i < size; i++)
	{
		if (1 == count[s[i]])
			return i;
	}
	return -1;
}
int main()
{
	string s1("leavlecond");
	int a = firstUniqChar(s1);
	cout << a << endl;
	cout << s1[a] << endl;
	return 0;
}
#endif

#if 0
//翻转字符串(面试题)
string ReverseString(string s)
{
	//判空
	if (s.empty())
		return s;

	size_t start = 0;
	size_t end = s.size() - 1;

	while (start < end)
	{
		swap(s[start], s[end]);
		++start;
		--end;
	}
	return s;
}

int main()
{
	string s("hello angele");
	cout << ReverseString(s) << endl;
	return 0;
}
#endif


#if 0
//字符串里最后一个单词的长度（面试题）
int main()
{
	string line;
	while (getline(cin, line))
	{
		size_t pos = line.rfind(" ");
		//cout << line.size()-pos-1 << endl;//法一
		//cout << line.substr(pos + 1, line.size() - pos).size() << endl;//法二
		cout << line.substr(pos + 1).size() << endl;//法三
	}

	return 0;
}
#endif


//验证回文串
#if 0
bool IsNumberLetters(char c)
{
	if (c >= '0' && c <= '9' ||
		c >= 'A' && c <= 'Z' ||
		c >= 'a' && c <= 'z')
	{
		return true;
	}

	return false;
}
bool isPalindrome(string s)
	{
		//判空
		if (s.empty())
			return true;

		int begin = 0;
		int end = s.size() - 1;
		char* p = (char*)s.c_str();
		while (begin < end)
		{
			//从前往后找有效字符（数字和字符）
			while (begin != end)
			{
				if (IsNumberLetters(s[begin]))
					break;

				else
					++ begin;
			}

			//从后往前找有效字符（数字和字符）
			while (begin != end)
			{
				if (IsNumberLetters(s[end]))
					break;

				else
					--end;
			}

			//验证是否相等
			if (begin < end)
			{
				if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
					return false;

				++begin;
				--end;
			}
		}
		return  true;
	}


int main()
{
	string s("hello ollef");
	isPalindrome(s);
	return 0;
}
#endif


//string类的模拟实现
//构造、拷贝构造、赋值运算符重载、析构函数

#if 0
//浅拷贝
#include <assert.h>
class String
{
public:
	String(const char* str = " ")
	{
		//断言
		if (nullptr == str)
		{
			assert(false);
			return;
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);//浅拷贝
	}

	~String()
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

int main()
{
	String s1("hello,world");
	String s2(s1);
	return 0;
}
#endif

#if 0
//深拷贝1(传统写法)
#include <assert.h>
class String
{
public:
	//构造函数
	String(const char* str = " ")
	{
		//构造string类对象时，如果传递空指针nullptr，认为程序非法，此处断言下
		if (nullptr == str)
		{
			assert(false);
			return;
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		cout << "构造："<<_str << endl;
	}

	String(const String& s)//深拷贝
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
		cout << "拷贝:" << _str << endl;

	}

	//赋值运算符重载
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[]_str;
			_str = pStr;
		}
		cout << "赋值重载：" << _str << endl;
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
		}
		cout << "~String()" << endl;
	}


private:
	char* _str;
};

int main()
{
	String s1("hello world!!");
	String s2(s1);
	String s3;
	s3 = s1;

	return 0;
}
#endif


#if 0
//现代版的String写法（深拷贝）
#include <assert.h>
class String
{
public:
	String(const char* str = " ")
	{
		if (nullptr == str)
		{
			assert(false);
			return;
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str,str);
		cout << "构造：" << _str << endl;
	}

	String(const String& s)
		:_str(nullptr)
	{
		String strTmp(s._str);
		swap(_str, strTmp._str);
		cout << "拷贝:" << _str << endl;
	}

	/*String& operator=(const String& s)
	{
		swap(_str, s._str);
		return *this;
	}*/

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			String strTmp(s);
			swap(_str, strTmp._str);
		}
		cout << "赋值重载：" << _str << endl;
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[]_str;
			_str = nullptr;
		}
		cout << "~String()" << endl;
	}

private:
	char* _str;
};

int main()
{
	String s1("hello world!!");
	String s2(s1);
	String s3;
	s3 = s1;

	return 0;
}
#endif


//string的模拟实现
#include <assert.h>
namespace strings
{
	class String
	{
	public:
		typedef char* Iterator;
	public:
		//构造函数
		strings::String(const char* str = " ")
		{
			if (nullptr == str)
			{
				assert(false);
				return;
			}

			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
			cout << "构造：" << _str << endl;
		}

		//拷贝函数
		String(const String& s)
			:_str(new char[s._capacity + 1])//开辟空间
			, _size(s._size)
			, _capacity(s._capacity)
		{
			strcpy(_str, s._str);//拷贝内容
			cout << "拷贝:" << _str << endl;
		}

		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		//赋值运算符重载1(传参传的为String类）
		//法一：
		/*String& operator=(const String& s)
		{
		if (this != &s)
		{
		delete[]_str;//释放旧的内存空间
		char* pStr = new char[s._capacity + 1];//申请新的内存空间
		strcpy(pStr,s._str);

		_str = pStr;
		_size = s._size;
		_capacity = s._capacity;
		}
		cout << "赋值重载：" << _str << endl;
		return *this;
		}*/

		//法二：(创建一个临时变量，使用了拷贝构造函数)
		/*String& operator=(const String& s)
		{
		if (this != &s)
		{
		String tmp(s);//创建一个临时变量
		swap(_str, tmp._str);//使用swap函数交换
		_size = tmp._size;
		_capacity = tmp._capacity;
		}
		return *this;
		}*/

		//法三：
		String& operator=(String& s)
		{
			if (this != &s)
			{
				//传入进来的参数是传值，相当于上面的临时变量
				Swap(s);
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}

		//赋值运算符重载2(传参传的为字符串)
		String& operator=(const char* str)
		{
			delete[]_str;//删除旧的内存空间
			size_t size_str = strlen(str);//算出字符串的大小
			//开辟空间
			_capacity = size_str + 1;
			_str = new char[_capacity];
			//复制
			strcpy(_str, str);
			_size = _capacity - 1;

			return *this;
		}


		//析构函数
		~String()
		{
			if (_str)
			{
				delete[]_str;
				_str = nullptr;
				_size = 0;
				_capacity = 0;
			}
		}

///////////////////////////////////////////////////////////////////////////////////////

		//扩容(重新申请一个空间大小足够的空间，包括原来的和现在需要的空间大小)
		void expand(size_t n)
		{
			char* tmp = new char[n];

			//复制原来空间的内容
			strcpy(tmp, _str);
			delete[]_str;
			_str = tmp;
			_capacity = n;
		}


		//尾插一个字符
		void PushBack(char c)
		{
			if (_size == _capacity)
				_Reserved_(_capacity * 2);//扩容

			_str[_size++] = c;//后置++
			_str[_size] = '\0';
		}

		//尾插一个字符串
		void PushBack(const char* str)
		{
			size_t str_size = strlen(str);

			//如果容量不够，则扩容(包含'\0')
			if (_size + str_size + 1 >= _capacity)
			{
				//扩容
				_capacity += str_size;
				expand(_capacity);

				//拷贝
				while (*str != '\0')
				{
					_str[_size++] = *str++;
				}
				_str[_size] = '\0';
			}
		}

		//插入n个字符c
		void Append(size_t n, char c)
		{
			for (size_t i = 0; i < n; i++)
			{
				PushBack(c);
			}
		}

		//在指定位置插入一个字符
		void Insert(size_t pos, char c)
		{
			if (_size < pos)
			{
				cout << "地址错误" << endl;
				return;
			}

			else
			{
				//pos位置正常，可以插进去
				if (_size + 1 >= _capacity)
				{
					expand(_capacity * 2);//扩容
				}
				_str[_size+1] = '\0';

				//将pos后的位置全部向后移动一位
				for (size_t i = _size; i > pos; --i)
				{
					_str[i] = _str[i - 1];
				}
				_str[pos] = c;
				_size++;
			}
		}

		//在指定位置插入一个字符串
		void Insert(size_t pos, const char* str)
		{
			if (_size < pos)
			{
				cout << "地址错误" << endl;
				return;
			}

			size_t str_size = strlen(str);
			if (str_size == 0)
			{
				cout << "str为空字符串" << endl;
				return;
			}

			if (_size + str_size + 1 >= _capacity)
			{
				_capacity = _size + str_size + 1;
				expand(_capacity);//扩容
			}

			int last_index = _size + str_size;
			_str[last_index--] = '\0';//加'\0'

			//将pos后的字符串都向后移str_size个位置
			for (int i = _size - 1; i > (int)pos; --i)
			{
				_str[last_index--] = _str[i];
			}

			//插入字符
			while (*str != '\0')
			{
				_str[pos++] = *str++;
			}

			_size += str_size;
		}

		//尾删一个字符
		void PopBack()
		{
			if (_size == 0)
			{
				cout << "字符串为空" << endl;
				return;
			}
			_size--;
			_str[_size] = '\0';
		}

		//在指定位置pos之后删除一个长度为n的字符串
		void Erase(size_t pos, size_t n)
		{
			if (pos >= _size)
			{
				cout << "pos的位置不合法" << endl;
				return;
			}

			if (pos + n < _size)
			{
				//pos之后的字符个数大于n
				size_t index_erase = pos + n;
				while (index_erase != _size)
				{
					_str[pos++] = _str[index_erase++];
				}
			}

			//pos之后的字符个数小于n
			_str[pos] = '\0';
			_size = pos;
		}

		//查找字符
		size_t Find(char c)
		{
			for (size_t i = 0; i < _size; i++)
			{
				if (_str[i] == c)
					return i;
			}
			return -1;
		}

		/////////////////////////////////////////////////////////////////////////
		//+=运算符重载
		String& operator+=(char c)
		{
			PushBack(c);
			return *this;
		}

		//[]运算符重载
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}


		///////<  >  <=  >=  !=  ==的重载
		bool operator>(const String& s)
		{
			size_t i = 0;
			while (_str[i] == s._str[i] && i < _size)
			{
				i++;
			}

			if (i == _size)
			{
				return  false;
			}
		}
		//法一
		/*bool operator==(const String& s)
		{
			for (int i = 0; i<_size; i++)
			{
				if (_str[i] != s._str[i])
				{
					return false;
				}
			}
			return true;
		}*/

		//法二
		bool operator==(const String& s)
		{
			size_t i = 0;
			while (_str[i] == s._str[i] && i < _size)
			{
				i++;
			}

			if (i == _size && s._str[i] == '\0')
			{
				return true;
			}
			else
				return false;
		}


		bool operator>=(const String& s)
		{
			if (*this > s || *this == s)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		

		bool operator != (const String& s)
		{
			if (*this == s)
			{
				return false;
			}
			else
				return true;
		}

		bool operator<=(const String& s)
		{
			if (!(*this > s))
			{
				return true;
			}
			return false;
		}

//////////////////////////////////////////////////////////////////////////
		//capability 容量

		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		bool empty()const
		{
			return 0 == _size;
		}

		//将有效字符的个数改成newsize,多出来的空间用c来替代
		void resize(size_t newsize, char c = char())
		{
			if (newsize > _size)
			{
				if (newsize > _capacity)
				{
					expand(newsize);
				}

				memset(_str + _size, c, newsize - _size);
			}
			else
			{
				_size = newsize;
				_str[newsize] = '\0';
			}
		}

		//预留空间
		void reserve(size_t newcapacity)
		{
			if (newcapacity > _capacity)
			{
				expand(newcapacity);
			}
		}

		void print()
		{
			printf("%s\n", _str);
		}

   /*private:
	   friend ostream& operator<<(ostream& _cout, const strings::String& s);*/

   private:
	   char* _str;
	   size_t _size;
	   size_t _capacity;
	};
}
//ostream& strings::operator<<(ostream& _cout, const strings::String& s)
//{
//	cout << s._str;
//	return _cout;
//}


void TestString1()
{
	strings::String s1("hello world!!");
	strings::String s2(s1);
	strings::String s4("me");
	strings::String s3;
	s3 = s1;
}

void TestString2()
{
	strings::String s1("hello");
	s1.Append(1, '!');
	s1.Insert(2, 'i');
	s1.print();
}

int main()
{
	//TestString1();
	TestString2();
	return 0;
}
