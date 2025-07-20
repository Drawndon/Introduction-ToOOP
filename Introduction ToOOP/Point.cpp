#include "Point.h"

	double Point::get_x()const
	{
		return x;
	}
	double Point::get_y()const
	{
		return y;
	}
	void Point::set_x(double x)
	{
		this->x = x;
	}
	void Point::set_y(double y)
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
	Point::Point(double x, double y): x(x), y(y)
	{
		cout << "Constructor:\t\t" << this << endl;
	}
	Point::Point(const Point& other) : Point(other.x, other.y)
	{
		cout << "CopyConstructor:\t" << this << endl;
	}
	Point::~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	// Operators
	Point& Point::operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Point& Point::operator++() //Prefix increment
	{
		x++;
		y++;
		return *this;
	}

	Point Point::operator++(int) //Postfix (Suffix) increment
	{
		Point old = *this; //сохраняем старое значение объекта
		x++;
		y++;
		return old;
	}



	// Methods
	double Point::distance(const Point& other)const
	{
		//other.x *= 100 // E0137
		//this->x *= 100 // E0137
		double x_diff = this->get_x() - other.get_x();
		double y_diff = this->get_y() - other.get_y();
		return sqrt(x_diff * x_diff + y_diff * y_diff);
	}
	void Point::print()const
	{
		cout << this << ": x = " << x << ",\ty = " << y << endl;
	}

double distance(const Point& A, const Point& B)
{
	double x_diff = A.get_x() - B.get_x();
	double y_diff = A.get_y() - B.get_y();
	return sqrt(x_diff * x_diff + y_diff * y_diff);
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

bool operator==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y()) return true;
	else
		return false;*/
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}

bool operator!=(const Point& left, const Point& right)
{
	return !(left == right);
}
