#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#if 0
//String�����ĳ�������
void TestString1()
{
	string s1;//����յ�string�����s1
	string s2("hello world");//��C��ʽ�ַ���������string�����s2
	string s3(10, 't');//��10���ַ���t��������string�����s3
	string s4(s3);//��������s4
	string s5(s2, 5);//��s2��ǰ5���ַ�������string�����s5

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
//String�����ĳ�����������
void TestString2()
{
	string s("hello,world!");
	cout << s.size() << endl;
	cout << s.length() << endl;//12
	cout << s.capacity() << endl;//15
	cout << s.empty() << endl;
	cout << s << endl;
	cout << " "<< endl;

	//���s����ַ���
	s.clear();
	cout << s.size() << endl;
	cout << s.length() << endl;//0
	cout << s.capacity() << endl;//15
	cout << s << endl;
	cout << " " << endl;

	//��S�е���Ч�ַ���������18����������ַ��á�t�������
	s.resize(18, 't');
	cout << s.size() << endl;
	cout << s.length() << endl;//18
	cout << s.capacity() << endl;//31(�ɱ�������)
	cout << s << endl;
	cout << " " << endl;

	//��S�е���Ч�ַ���������19����������ַ���0�����
	s.resize(19);
	cout << s.size() << endl;
	cout << s.length() << endl;//18
	cout << s.capacity() << endl;//31(�ɱ�������)
	cout << s << endl;
	cout << " " << endl;

	//��s�е���Ч�ַ��ĸ�����С��6��
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

	//reserve():Ϊ�ַ���Ԥ���ռ�
	//����
	s.reserve(100);
	cout << s.size() << endl;//9
	cout << s.capacity() << endl;//111
	cout << " " << endl;

	//��С(����ı�������С)
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
//string�����ķ��ʲ���
void TestString4()
{
	string s1("i like it");
	const string s2("I like it");
	cout << s1 << "   " << s2 << endl;
	cout << s1[0] << "   " << s2[0] << endl;
	cout << " " << endl;

	s1[0] = 'I';//�޸�s1�ĵ�һλ
	cout << s1 << endl;
	cout << " " << endl;

	//s2[0] = 'o';//const���Ͳ����޸�

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
//string�������޸Ĳ���
void TestString5()
{
	string s1("hello,world");
	string s2("  me");
	s1.push_back('!');//׷���ַ�
	s1.append("i like");//׷���ַ���
	cout << s1 << endl;

	s1 += 'y';
	cout << s1 << endl;
	s1 += "ou";

	cout << s1 << endl;
	cout << s1.c_str() << endl;//����C��ʽ�ַ���

	s1 += s2;
	cout << s1 << endl;
}

void TestString6()
{
	//��ȡfile1�ĺ�׺
	string file1("string.cpp");
	size_t pos = file1.rfind('.');
	string s2(file1.substr(pos, file1.size() - pos));
	cout << s2 << endl;
	cout << " " << endl;

	//ȡ��str�е�����(www.cplusplus.com)
	string str("http://www.cplusplus.com/reference/string/string/rfind/");
	cout << str << endl;
	size_t start = str.find("://")+3;
	size_t finish = str.find('/', start);
	string address = str.substr(start, finish - start);
	cout << address << endl;

	//ɾ��str��ǰ׺
	pos = str.find("://");
	str.erase(0, pos + 3);
	cout << str << endl;
}

void TestPushBack()
{
	//�۲�capacityÿ��ϵͳ�Զ����ݵĴ�С���̶ȣ�
	
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
	//����reserve��߲������ݵ�Ч�ʣ��������ݴ����Ŀ���

	string s;
	s.reserve(100);//Ԥ��100���ֽڵĿռ�
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
//���ַ����е�һ��ֻ����һ�ε��ַ�(������)
int firstUniqChar(string s)
{
	//ͳ��ÿ���ַ����ֵĴ���
	int count[256] = { 0 };
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		count[s[i]] += 1;
	}

	//�����ַ������ǰ�����ҳ�ֻ����һ�ε��ַ�
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
//��ת�ַ���(������)
string ReverseString(string s)
{
	//�п�
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
//�ַ��������һ�����ʵĳ��ȣ������⣩
int main()
{
	string line;
	while (getline(cin, line))
	{
		size_t pos = line.rfind(" ");
		//cout << line.size()-pos-1 << endl;//��һ
		//cout << line.substr(pos + 1, line.size() - pos).size() << endl;//����
		cout << line.substr(pos + 1).size() << endl;//����
	}

	return 0;
}
#endif


//��֤���Ĵ�
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
		//�п�
		if (s.empty())
			return true;

		int begin = 0;
		int end = s.size() - 1;
		char* p = (char*)s.c_str();
		while (begin < end)
		{
			//��ǰ��������Ч�ַ������ֺ��ַ���
			while (begin != end)
			{
				if (IsNumberLetters(s[begin]))
					break;

				else
					++ begin;
			}

			//�Ӻ���ǰ����Ч�ַ������ֺ��ַ���
			while (begin != end)
			{
				if (IsNumberLetters(s[end]))
					break;

				else
					--end;
			}

			//��֤�Ƿ����
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


//string���ģ��ʵ��
//���졢�������졢��ֵ��������ء���������

#if 0
//ǳ����
#include <assert.h>
class String
{
public:
	String(const char* str = " ")
	{
		//����
		if (nullptr == str)
		{
			assert(false);
			return;
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);//ǳ����
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
//���1(��ͳд��)
#include <assert.h>
class String
{
public:
	//���캯��
	String(const char* str = " ")
	{
		//����string�����ʱ��������ݿ�ָ��nullptr����Ϊ����Ƿ����˴�������
		if (nullptr == str)
		{
			assert(false);
			return;
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
		cout << "���죺"<<_str << endl;
	}

	String(const String& s)//���
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
		cout << "����:" << _str << endl;

	}

	//��ֵ���������
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[]_str;
			_str = pStr;
		}
		cout << "��ֵ���أ�" << _str << endl;
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
//�ִ����Stringд���������
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
		cout << "���죺" << _str << endl;
	}

	String(const String& s)
		:_str(nullptr)
	{
		String strTmp(s._str);
		swap(_str, strTmp._str);
		cout << "����:" << _str << endl;
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
		cout << "��ֵ���أ�" << _str << endl;
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


//string��ģ��ʵ��
#include <assert.h>
namespace strings
{
	class String
	{
	public:
		typedef char* Iterator;
	public:
		//���캯��
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
			cout << "���죺" << _str << endl;
		}

		//��������
		String(const String& s)
			:_str(new char[s._capacity + 1])//���ٿռ�
			, _size(s._size)
			, _capacity(s._capacity)
		{
			strcpy(_str, s._str);//��������
			cout << "����:" << _str << endl;
		}

		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		//��ֵ���������1(���δ���ΪString�ࣩ
		//��һ��
		/*String& operator=(const String& s)
		{
		if (this != &s)
		{
		delete[]_str;//�ͷžɵ��ڴ�ռ�
		char* pStr = new char[s._capacity + 1];//�����µ��ڴ�ռ�
		strcpy(pStr,s._str);

		_str = pStr;
		_size = s._size;
		_capacity = s._capacity;
		}
		cout << "��ֵ���أ�" << _str << endl;
		return *this;
		}*/

		//������(����һ����ʱ������ʹ���˿������캯��)
		/*String& operator=(const String& s)
		{
		if (this != &s)
		{
		String tmp(s);//����һ����ʱ����
		swap(_str, tmp._str);//ʹ��swap��������
		_size = tmp._size;
		_capacity = tmp._capacity;
		}
		return *this;
		}*/

		//������
		String& operator=(String& s)
		{
			if (this != &s)
			{
				//��������Ĳ����Ǵ�ֵ���൱���������ʱ����
				Swap(s);
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}

		//��ֵ���������2(���δ���Ϊ�ַ���)
		String& operator=(const char* str)
		{
			delete[]_str;//ɾ���ɵ��ڴ�ռ�
			size_t size_str = strlen(str);//����ַ����Ĵ�С
			//���ٿռ�
			_capacity = size_str + 1;
			_str = new char[_capacity];
			//����
			strcpy(_str, str);
			_size = _capacity - 1;

			return *this;
		}


		//��������
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

		//����(��������һ���ռ��С�㹻�Ŀռ䣬����ԭ���ĺ�������Ҫ�Ŀռ��С)
		void expand(size_t n)
		{
			char* tmp = new char[n];

			//����ԭ���ռ������
			strcpy(tmp, _str);
			delete[]_str;
			_str = tmp;
			_capacity = n;
		}


		//β��һ���ַ�
		void PushBack(char c)
		{
			if (_size == _capacity)
				_Reserved_(_capacity * 2);//����

			_str[_size++] = c;//����++
			_str[_size] = '\0';
		}

		//β��һ���ַ���
		void PushBack(const char* str)
		{
			size_t str_size = strlen(str);

			//�������������������(����'\0')
			if (_size + str_size + 1 >= _capacity)
			{
				//����
				_capacity += str_size;
				expand(_capacity);

				//����
				while (*str != '\0')
				{
					_str[_size++] = *str++;
				}
				_str[_size] = '\0';
			}
		}

		//����n���ַ�c
		void Append(size_t n, char c)
		{
			for (size_t i = 0; i < n; i++)
			{
				PushBack(c);
			}
		}

		//��ָ��λ�ò���һ���ַ�
		void Insert(size_t pos, char c)
		{
			if (_size < pos)
			{
				cout << "��ַ����" << endl;
				return;
			}

			else
			{
				//posλ�����������Բ��ȥ
				if (_size + 1 >= _capacity)
				{
					expand(_capacity * 2);//����
				}
				_str[_size+1] = '\0';

				//��pos���λ��ȫ������ƶ�һλ
				for (size_t i = _size; i > pos; --i)
				{
					_str[i] = _str[i - 1];
				}
				_str[pos] = c;
				_size++;
			}
		}

		//��ָ��λ�ò���һ���ַ���
		void Insert(size_t pos, const char* str)
		{
			if (_size < pos)
			{
				cout << "��ַ����" << endl;
				return;
			}

			size_t str_size = strlen(str);
			if (str_size == 0)
			{
				cout << "strΪ���ַ���" << endl;
				return;
			}

			if (_size + str_size + 1 >= _capacity)
			{
				_capacity = _size + str_size + 1;
				expand(_capacity);//����
			}

			int last_index = _size + str_size;
			_str[last_index--] = '\0';//��'\0'

			//��pos����ַ����������str_size��λ��
			for (int i = _size - 1; i > (int)pos; --i)
			{
				_str[last_index--] = _str[i];
			}

			//�����ַ�
			while (*str != '\0')
			{
				_str[pos++] = *str++;
			}

			_size += str_size;
		}

		//βɾһ���ַ�
		void PopBack()
		{
			if (_size == 0)
			{
				cout << "�ַ���Ϊ��" << endl;
				return;
			}
			_size--;
			_str[_size] = '\0';
		}

		//��ָ��λ��pos֮��ɾ��һ������Ϊn���ַ���
		void Erase(size_t pos, size_t n)
		{
			if (pos >= _size)
			{
				cout << "pos��λ�ò��Ϸ�" << endl;
				return;
			}

			if (pos + n < _size)
			{
				//pos֮����ַ���������n
				size_t index_erase = pos + n;
				while (index_erase != _size)
				{
					_str[pos++] = _str[index_erase++];
				}
			}

			//pos֮����ַ�����С��n
			_str[pos] = '\0';
			_size = pos;
		}

		//�����ַ�
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
		//+=���������
		String& operator+=(char c)
		{
			PushBack(c);
			return *this;
		}

		//[]���������
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


		///////<  >  <=  >=  !=  ==������
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
		//��һ
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

		//����
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
		//capability ����

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

		//����Ч�ַ��ĸ����ĳ�newsize,������Ŀռ���c�����
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

		//Ԥ���ռ�
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
