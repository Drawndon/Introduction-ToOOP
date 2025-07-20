#pragma once
#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

class Fraction // Описание класса
{
	int integer; //Целая часть
	int numerator; //Числитель
	int denominator; //Знаменатель
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;

	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//				Constructors:
	Fraction();

	explicit Fraction(int integer); //explicit - явное

	explicit Fraction(double dbl_num);

	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);

	Fraction(const Fraction& other);
	~Fraction();

	//					Operators:
	Fraction& operator=(const Fraction& other);

	Fraction& operator*=(const Fraction& other);

	Fraction& operator/=(const Fraction& other);


	//			Incremento/Decremento
	Fraction& operator++();

	const Fraction& operator++(int);

	Fraction& operator--();


	const Fraction& operator--(int);

	//					Type-cast operators
	explicit operator int()const;
	explicit operator double()const;

	//						Methods:
	Fraction& to_improper();

	Fraction& to_proper();

	Fraction inverted()const;

	Fraction& reduce();

	void print()const;
};

Fraction operator+(Fraction left, Fraction right);

Fraction operator*(Fraction left, Fraction right);

Fraction operator/(const Fraction& left, const Fraction& right);

//						Comparison operators
bool operator==(Fraction left, Fraction right);

bool operator!=(const Fraction& left, const Fraction& right);

bool operator>(Fraction left, Fraction right);

bool operator<(Fraction left, Fraction right);

bool operator>=(const Fraction& left, const Fraction& right);

bool operator<=(const Fraction& left, const Fraction& right);

std::ostream& operator<<(std::ostream& os, const Fraction& obj);

std::istream& operator>>(std::istream& is, Fraction& obj);
