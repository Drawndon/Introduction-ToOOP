#include <iostream>
#include <Point.h>
#include <MyString.h>
#include <Fraction.h>

using namespace std;

#pragma comment(lib, "Class String.lib") //Можно так, а можно в 'Input'

#define ARITHMETICAL_OPERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	//Point(2, 3) - здесь мы явно вызываем конструктор и создаем временный безымянный объект
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();

	Fraction F1(1,2);
	cout << F1 << endl;

	String str1 = "Hello";
	cout << str1 << endl;
}