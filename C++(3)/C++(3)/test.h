class  Student
{
public:
	void SetStudentInfo(const char* name, const char* gender, int age);
	void PrintStudentInfo();

private:
	char _name[20];
	char _gender[3]; 
	int _age;
};

struct data
{
	int a;
	double b;
	short c;
};