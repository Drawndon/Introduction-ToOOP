#include <iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double distance(Point other)
	{
		double x_diff = this->get_x() - other.get_x();
		double y_diff = this->get_y() - other.get_y();
		return sqrt(x_diff * x_diff + y_diff * y_diff);
	}
};

double distance(Point *pA, Point *pB)
{
	double x_diff = pA->get_x() - pB->get_x();
	double y_diff = pA->get_y() - pB->get_y();
	return sqrt(x_diff * x_diff + y_diff * y_diff);
}

//#define STRUCT_POINT
void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT

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
#endif // STRUCT_POINT

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(5);
	B.set_y(7);
	Point* pA = &A;
	Point* pB = &B;
	
	Point C;
	double x, y;
	cout << "Введите координаты точки, до которой надо вычислить расстояние: "; cin >> x; cin >> y;
	C.set_x(x); C.set_y(y);
	cout << "Расстояние между точками A и B: " << distance(pA, pB) << endl;
	cout << "Расстояние между точками B и A: " << distance(pB, pA) << endl;
	cout << "Расстояние между точками A и B: " << A.distance(B) << endl;
	cout << "Расстояние между точками A и C: " << A.distance(C) << endl;
	cout << "Расстояние между точками B и C: " << B.distance(C) << endl;
	cout << "Расстояние между точками B и A: " << B.distance(A) << endl;
	main();

}