#include <iostream>
using namespace std;

class Fraction; //Объявление класса
Fraction operator*(Fraction left, Fraction right); //Объявление оператора
Fraction operator/(const Fraction& left, const Fraction& right);
class Fraction // Описание класса
{
	int integer; //Целая часть
	int numerator; //Числитель
	int denominator; //Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	//				Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		set_denominator(1);
		cout << "DefaultConstructor:\t" << this << endl;
	}

	explicit Fraction(int integer) //explicit - явное
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:" << this << endl;
	}

	explicit Fraction(double dbl_num)
	{
		integer = dbl_num;
		dbl_num -= integer;
		denominator = 10e+7;
		numerator = dbl_num * denominator + 0.9;
		reduce();
	}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//					Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}

	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}


	//			Incremento/Decremento
	Fraction& operator++()
	{
		integer++;
		return *this;
	}

	const Fraction& operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	Fraction& operator--()
	{
		integer--;
		return *this;
	}


	const Fraction& operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}

	//					Type-cast operators
	explicit operator int()const
	{
		//to_improper(); //evalueate as a constant
		return integer + numerator / denominator;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//						Methods:
	Fraction& to_improper()
	{
		// Перевод в неправильную дробь:
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper()
	{
		// Перевод в правильную дробь:
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator); //swap - меняет местами две переменные
		return inverted;
	}

	Fraction& reduce()
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

	void print()const
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
};

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
	int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENTO_DECREMENTO_CHECK
//#define COMPARISON_OPERATORS
//#define STREAMS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
#define CONVERSIONS_FROM_CLASS_TO_OTHER
//#define HAVE_A_NICE_DAY
void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A; //Default constructor
	A.print();

	Fraction B = 5; //Single-Argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();
	Fraction B(3, 4, 5);
	B.print();
	Fraction C = A * B;
	C.print();

	C = A / B;
	C.print();

	A *= B;
	A.print();

	A /= B;
	A.print();

	C = A + B;
	C.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef INCREMENTO_DECREMENTO_CHECK
	Fraction A(2, 3, 4);
	Fraction B = A++;
	A.print();
	B.print();
#endif // INCREMENTO_DECREMENTO_CHECK

#ifdef COMPARISON_OPERATORS
	cout << (2 == 3) << endl;
	cout << (Fraction(1, 3) <= Fraction(5, 11)) << endl;
#endif // COMPARISON_OPERATORS

#ifdef STREAMS_CHECK
	Fraction A(2, 3, 4);
	cout << "Введите простую дробь: ";
	cin >> A;
	cout << A << endl;
#endif // STREAMS_CHECK

#ifdef TYPE_CONVERSIONS_BASICS
	int a = 2;   //No conversion
	double b = 3;//Conversion from less to more
	int c = b;	 //Conversion from more to less without data loss
	int d = 5.5; //Conversion from more to less with data loss  
#endif // TYPE_CONVERSIONS_BASICS


#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS

	Fraction A = (Fraction)5; //Single-Argument Constructor (from less to more)
	cout << A << endl;

	Fraction B;
	B = Fraction(8); //Single-Argument Constructor -> CopyAssignment(from less to more)
		   //Single-Argument Constructor создает из '8' временный безымянный объект
		   //а оператор присваивания просто записывает его в существующий объект 'B'

#endif // CONVERSIONS_FROM_OTHER_TO_CLASS

#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER
	/*
	---------------------------------------
	 operator type()
	 {
		
	 }
	---------------------------------------
	*/

	Fraction A(2, 3, 4);
	A.to_improper().print();
	int a = (int)A;
	cout << a << endl;

	double b = (double)A;
	cout << b << endl;

#endif // CONVERSIONS_FROM_CLASS_TO_OTHER

#ifdef HAVE_A_NICE_DAY
	Fraction A = Fraction(2.6);
	cout << A << endl;
#endif // HAVE_A_NICE_DAY

}

