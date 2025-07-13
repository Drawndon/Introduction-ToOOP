#include <iostream>
using namespace std;

class String
{
	int length;
	char* str;
public:
	int get_size() const
	{
		return length;
	}
	char* get_str()const
	{
		return str;
	}
	//					Constructors
	String(int length = 100)
	{
		this->length = length;
		this->str = new char[length] {};
	}
	String(const String& other)
	{
		length = other.length;
		str = new char [length] {};
		for (int i = 0; i < length; i++) str[i] = other.str[i];
	}

	~String()
	{
		delete[] str;
		this->str = nullptr;
		this->length = 0;
	}
	//				Operators
	String& operator=(String& other)
	{
		length = other.length;
		str = new char [length] {};
		for (int i = 0; i < length; i++) str[i] = other.str[i];
		return *this;
	}

	//				Methods
	void print()const
	{
		cout << "Length: " << length << endl;
		cout << "Str: " << str << endl;
	}
};

String operator+(const String& left, const String& right)
{

}

std::istream &operator>>(std::istream& is, String& obj)
{
	const int LENGTH = 512;
	char buffer[LENGTH] = {};
	is >> buffer;
	obj = buffer;
	return is;
}

void main()
{
	setlocale(LC_ALL, "");

}