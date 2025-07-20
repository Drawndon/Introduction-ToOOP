#pragma once
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
	double get_x()const;
	double get_y()const;
	void set_x(double x);
	void set_y(double y);

	//					Constructors

	Point(double x = 0, double y = 0);
	Point(const Point& other);
	~Point();
	//					Operators
	Point& operator=(const Point& other);

	Point& operator++(); //Prefix increment

	Point operator++(int); //Postfix (Suffix) increment

	//					Methods
	double distance(const Point& other)const;
	void print()const;
};

double distance(const Point& A, const Point& B);

Point operator+(const Point& left, const Point& right);

bool operator==(const Point& left, const Point& right);

bool operator!=(const Point& left, const Point& right);
