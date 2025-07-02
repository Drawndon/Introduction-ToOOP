#pragma warning(disable:4326)
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n---------------------------------------------------\n"
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

	// Constructors
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout <<  "SingleArgumentConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	// Operators
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	// Methods
	double distance(const Point& other)const
	{
		//other.x *= 100 // E0137
		//this->x *= 100 // E0137
		double x_diff = this->get_x() - other.get_x();
		double y_diff = this->get_y() - other.get_y();
		return sqrt(x_diff * x_diff + y_diff * y_diff);
	}
	void print()const
	{
		cout << this << ": x = " << x << ",\ty = " << y << endl;
	}
};

double distance(const Point &A, const Point &B)
{
	double x_diff = A.get_x() - B.get_x();
	double y_diff = A.get_y() - B.get_y();
	return sqrt(x_diff * x_diff + y_diff * y_diff);
}

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
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

#ifdef DISTANCE_CHECK

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(5);
	B.set_y(7);
	
	
	Point C;
	double x, y;
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "Введите координаты точки, до которой надо вычислить расстояние: "; cin >> x >> y;
	C.set_x(x); C.set_y(y);
	cout << "Расстояние между точками A и B: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками A и B: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками A и C: " << A.distance(C) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и C: " << B.distance(C) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A: " << B.distance(A) << endl;

#endif // DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK

	Point A; // Здесь мы просто создаем объект, и для этого неявно вызывается конструктор по умолчанию
	A.print();
	/* {

		//Point A;
		Point B;
		cout << "Point B exists" << endl;
		B.distance(A);
	}
	cout << "Point B doesn't exist" << endl;*/
	Point B = 5; // SingleArgumentConstructor - конструктор с одним параметром
	B.print();

	Point C(7, 8); //
	C.print();

	Point D = C; //Copy constructor
	D.print();

	//Assignment operator

	Point E; //Default Constructor
	E = D; //Assignment operator
	E.print();


#endif // CONSTRUCTORS_CHECK

	int a, b, c;
	a = b = c = 0;

	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	//Point(2, 3) - здесь мы явно вызываем конструктор и создаем временный безымянный объект
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
}