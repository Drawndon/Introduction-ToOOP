#include <iostream>
using namespace std;

class Point
{
	double x;
	double y;
};

void main()
{
	setlocale(LC_ALL, "");
	int a; //Объявление переменной 'а' типа 'int'
	Point A; //Объявление переменной 'A' типа 'Point'
			//Создание объекта 'А' структуры 'Point'
			//Создание экземпляра 'А' структуры 'Point'
			//'A' is instance of struct 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;

	cout << pA->x << "\t" << pA->y << endl;


}