#include <iostream>
using namespace std;

template <typename T> T get_gcd(T a, T b)
{
	while (b)
	{
		T rest = a % b;
		a = b;
		b = rest;
	}
	return a;
}

template <typename T> T get_lcm(T a, T b)
{
	return (a * b) / get_gcd(a, b);
}
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);

class Fraction
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

	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:" << this << endl;
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
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}

	Fraction& operator++()
	{
		this->integer++;
		return *this;
	}
	
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	
	Fraction& operator--()
	{
		this->integer--;
		return *this;
	}
	
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
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

	Fraction& shorten_fraction()
	{
		numerator /= get_gcd(numerator, denominator);
		denominator /= get_gcd(numerator, denominator);
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
	).to_proper();
}

Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	).to_proper();
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
	if (left.get_denominator() == right.get_denominator())
		return Fraction(left.get_integer() + right.get_integer(),
						left.get_numerator() + right.get_numerator(),
						left.get_denominator()).to_proper().shorten_fraction();

	int lcm = get_lcm(left.get_denominator(), right.get_denominator());

	return Fraction(left.get_integer() + right.get_integer(),
					left.get_numerator() * (lcm / left.get_denominator()) +
					right.get_numerator() * (lcm / right.get_denominator()),
					lcm).to_proper().shorten_fraction();
}

Fraction operator-(const Fraction& left, const Fraction& right)
{
	if (left.get_denominator() == right.get_denominator())
		return Fraction(left.get_integer() - right.get_integer(),
						left.get_numerator() - right.get_numerator(),
						left.get_denominator());

	int lcm = get_lcm(left.get_denominator(), right.get_denominator());

	return Fraction(left.get_integer() - right.get_integer(),
					left.get_numerator() * (lcm / left.get_denominator()) -
					right.get_numerator() * (lcm / right.get_denominator()),
					lcm).to_proper().shorten_fraction();
}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() ==
		left.get_denominator() * right.get_numerator();
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
		left.get_denominator() * right.get_numerator();
}

bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		left.get_denominator() * right.get_numerator();
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}


//#define CONSTRUCTORS_CHECK
//#define ARITHMETIC_CHECK
#define COMPOUND_ASSIGNMENT_CHECK
//#define COMPARISON_CHECK
//#define INCREMENT_DECREMENT_CHECK
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

#ifdef ARITHMETIC_CHECK
	Fraction A(1, 2, 3);
	A.print();
	Fraction B(2, 3, 4);
	B.print();
	Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print();

	Fraction E = A + B;
	E.print();

	Fraction F = A - B;
	F.print();
#endif // ARITHMETIC_CHECK

#ifdef COMPOUND_ASSIGNMENT_CHECK
	Fraction A(2, 3, 4);
	Fraction B(2, 3, 4);
	
	cout << "A = ";
	A.print();
	cout << "B = ";
	B.print();
	A += B;
	cout << "A += B: ";
	A.print();
	A *= B;
	cout << "A *= B: ";
	A.print();

#endif // COMPOUND_ASSIGNMENT_CHECK

#ifdef COMPARISON_CHECK
	Fraction A(2, 3, 4);
	Fraction B(2, 3, 4);
	A.print();
	B.print();
	cout << "A > B: " << (A > B ? "True" : "False") << endl;
	cout << "A < B: " << (A < B ? "True" : "False") << endl;
	cout << "A == B: " << (A == B ? "True" : "False") << endl;
	cout << "A <= B: " << (A <= B ? "True" : "False") << endl;
	cout << "A >= B: " << (A >= B ? "True" : "False") << endl;

#endif // COMPARISON_CHECK

#ifdef INCREMENT_DECREMENT_CHECK
	Fraction A(2, 3, 4);
	Fraction B(2, 3, 4);
	A.print();
	B.print();
	A++;
	A.print();
	B++;
	B.print();
	--A;
	A.print();

#endif // INCREMENT_DECREMENT_CHECK
}