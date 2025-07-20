#include <iostream>
#include <Point.h>
//#include <String.h>
#include <Fraction.h>

using namespace std;

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

}