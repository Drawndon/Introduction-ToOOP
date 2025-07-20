#include "Fraction.h"

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENTO_DECREMENTO_CHECK
//#define COMPARISON_OPERATORS
//#define STREAMS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER
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

	double b = (double)A; //
	cout << b << endl;

#endif // CONVERSIONS_FROM_CLASS_TO_OTHER

#ifdef HAVE_A_NICE_DAY
	Fraction A = Fraction(3.333); //Conversion from 'double' to 'Fraction'
	cout << A << endl;
#endif // HAVE_A_NICE_DAY

}

