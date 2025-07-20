#include "Fraction.h"


	int Fraction::get_integer()const
	{
		return integer;
	}
	int Fraction::get_numerator()const
	{
		return numerator;
	}
	int Fraction::get_denominator()const
	{
		return denominator;
	}

	void Fraction::set_integer(int integer)
	{
		this->integer = integer;
	}
	void Fraction::set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void Fraction::set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	//				Constructors:
	Fraction::Fraction() : integer(0), numerator(0), denominator(1)
	{
		cout << "DefaultConstructor:\t" << this << endl;
	}

	Fraction::Fraction(int integer) //explicit - явное
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:" << this << endl;
	}

	Fraction::Fraction(double dbl_num)
	{
		integer = dbl_num; //Получаем целую часть дроби
		dbl_num -= integer; //Убираем целую часть из десятичной дроби
		denominator = 1e+9; //Максимальное число, которое можно записать в 'int' 
		numerator = dbl_num * denominator + 0.9; //Вытаскиваем дробную часть в числитель
		reduce();
		cout << "SingleArgumentConstructor:" << this << endl;

	}

	Fraction::Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction::Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction::Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	Fraction::~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//					Operators:
	Fraction& Fraction::operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Fraction& Fraction::operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}

	Fraction& Fraction::operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}


	//			Incremento/Decremento
	Fraction& Fraction::operator++()
	{
		integer++;
		return *this;
	}

	const Fraction& Fraction::operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	Fraction& Fraction::operator--()
	{
		integer--;
		return *this;
	}


	const Fraction& Fraction::operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}

	//					Type-cast operators
	Fraction::operator int()const
	{
		//to_improper(); //evalueate as a constant
		return integer + numerator / denominator;
	}
	Fraction::operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//						Methods:
	Fraction& Fraction::to_improper()
	{
		// Перевод в неправильную дробь:
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& Fraction::to_proper()
	{
		// Перевод в правильную дробь:
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction Fraction::inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		std::swap(inverted.numerator, inverted.denominator); //swap - меняет местами две переменные
		return inverted;
	}

	Fraction& Fraction::reduce()
	{
		int more, less, rest;
		if (numerator > denominator) more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; // GCD - Greatest Common Divisor (наибольший общий делитель)
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}

	void Fraction::print()const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;*/
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	result.to_proper();
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}

//						Comparison operators
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}

bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right); // left > right || left == right;
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right); // left < right || left == right;
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	//Stream extraction operator
	if (obj.get_integer()) os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer()) os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()) os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{
	/*int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator); */
	const int LEN = 12; //размер буфера ввода
	char line[LEN] = {}; //буфер ввода
	is.getline(line, LEN);
	int digits[3] = {}; //числа, введенные с клавиатуры
	int i = 0; //количество введенных чисел
	char* context = NULL;
	const char separators[] = ".,/ ()"; //разделители
	char* p_line = strtok_s(line, separators, &context);

	while (p_line && i < 3)
	{
		digits[i++] = atoi(p_line); //ASCII-string to integer
		p_line = strtok_s(NULL, separators, &context);
	}
	i == 0 ? obj = Fraction() : i == 1 ? obj = Fraction(digits[0]) : i == 2 ? obj = Fraction(digits[0], digits[1]) : obj = Fraction(digits[0], digits[1], digits[2]);
	return is;
}
