#include <iostream>
using namespace std;

#define delimiter "\n---------------------------------------------\n"

//////////////////////////////////////////////////////////////////////////
//////////////		Объявление класса (Class declaration) ////////////////
class String
{
	int size; //размер строки в Байтах (с учетом NULL-terminator)
	char* str; //адрес строки в динамической памяти

public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//				Constructors:
	explicit String(int size = 80);
	String(const char* str);
	//CopyConstructor, CopyAssignment DeepCopy
	//CopyMethods, Copy
	String(const String& other);

	String(String&& other);

	~String();

	//				Operators
	String& operator=(const String& other);
	String& operator=(String&& other);
	char operator[](int i)const;
	char& operator[](int i);

	//				Methods:
	void print()const;
};

//////////////		Конец объявления класса (Class declaration end) ////////////////
///////////////////////////////////////////////////////////////////////////////////

///----------------------------------------------------------------------------///
///////////////////////////////////////////////////////////////////////////////////
///					Определение класса (Class defenition)		//////////////////
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//				Constructors:
String::String(int size) :size(size), str(new char[size] {})
{
	//Конструктор по умолчанию создает пустую строку размером 80 Байтов
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1; //strlen() возвращает размер строки в символах, +1 нужен чтобы выделилась память под NULL-terminator
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++) this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//this->size = other.size;
	//this->str = other.str; shallow copy
	// /---------------------------------------------///
	//DeepCopy
	//this->str = new char[size] {};
	//for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	cout << "CopyConstructor:\t" << this << endl;
}

String::String(String&& other):size(other.size), str(other.str)
{
	//MoveConstructor - ShallowCopy;
	//this->size = other.size;
	//this->str = other.str;
	//Обнуляем принимаемый объект, для того чтобы предотвратить удаление его ресурсов деструктором
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}

String::~String()
{
	delete[] str;
	str = nullptr;
	size = 0;
	cout << "Destructor:\t\t" << this << endl;
}

//				Operators
String& String::operator=(const String& other)
{
	//0) Проверяется, не является ли тот объект этим объектом
	if (this == &other) return *this;
	//1) Удаляем старую динамическую память
	delete[] this->str;
	//2) Deep copy - Побитовое копирование
	this->size = other.size;
	//3) Выделяем новую динамическую память
	this->str = new char[size] {};
	for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}

String& String::operator=(String&& other)
{
	//0) Проверка не являются ли 'this' и 'other' одним и тем же объектом
	if (this == &other) return *this;
	//1)Удаление старой памяти
	delete[] str;
	//2) Shallow copy;
	this->size = other.size;
	this->str = other.str;
	//3) Обнуляем принимаемый объект
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t\t" << this << endl;
	return *this;
}

char String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//				Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}
String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		result[i] = left[i];
		//result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result[i + left.get_size() - 1] = right[i];
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return result;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
//////////////		Конец определения класса (Class defenition end) ////////////////
////////////////////////////////////////////////////////////////////////////////////

void Clear(char* str)
{
	delete[] str;
}

//#define CONSTRUCTORS_CHECK
//#define COPY_SEMANTIC_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1;
	str1.print();

	String str2(5);  //Conversion from 'int' to 'String'
	str2.print();

	String str3 = "Hello";
	str3.print();

	cout << str3 << endl;

	String str4 = "World";

	cout << str4 << endl;
	cout << delimiter;
	String str5;
	str5 = str3 + str4;
	cout << delimiter;
	cout << str5 << endl;
	/*char * str = new char[8] {"Hello"}*;
	cout << str << endl;
	delete [] str;
	delete [] str; 'Debug Assertion Failed'*/
	//int arr[] = { 3, 5, 8, 13, 21 };
	//delete[] arr;  
#endif // CONSTRUCTORS_CHECK

#ifdef COPY_SEMANTIC_CHECK
	String str1 = "Hello";
	cout << str1 << endl;

	String str2 = str1;
	cout << str2 << endl;

	String str3 = "World";
	str2 = str3;
	cout << str2 << endl;
#endif // COPY_SEMANTIC_CHECK

	//MoveMethods (MoveSemantic)

	String str1; //DefaultConstructor;
	str1.print();

	String str2(5); //Single-argument Constructor(int)
	str2.print();

	String str3 = "Hello";//Single-argument Constructor(const char str[])
	str3.print();

	String str4(); //В этой строке не вызывается DefaultConstructor и не создается объект;
					//здесь объявляется функция 'str4', которая ничего не принимает, 
					// и возвращает значение типа 'String'
	//str4 НЕ является объектом
	//То есть, круглые скобки не делают явный вызов конструктора по умолчанию,
	//если есть необходимость явно вызвать конструктор по умолчанию, 
	//то это можно сделать при помощи фигурных скобок

	String str5{}; //А эта строка уже явно вызывает DefaultConstructor
	str5.print();

	String str6{ 6 }; //Single-argument Constructor (int)
	str6.print();

	String str7{ "World" };
	str7.print();

	String str8 = str7;
	str8.print();

	String str9(str8);
	str9.print();

	String str10{ str9 };
	str10.print();

	//!!! Фигурные скобки для вызова конструкторов следует использовать с большой осторожностью

	String str11 = str3 + str8;
	str11.print();
}