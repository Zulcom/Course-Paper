#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;


class complex
{
private:
	float real;               // Реальная часть
	float imag;      //  Мнимая часть


public:
	complex();
	complex(float, float);
	complex(const complex&);

	complex operator *(complex);

	bool operator ==(complex);
	friend ostream& operator <<(ostream &s, complex &c);
};
//   Конструктор инициализирующий
complex::complex(float r = 0.0f, float im = 0.0f)
{
	real = r;
	imag = im;
}

//     Конструктор копирующий
complex::complex(const complex &c)
{
	this->real = c.real;
	this->imag = c.imag;
}
// Конструктор по умолчанию
complex::complex() {
	cout << "Enter Real:";
	cin >> this->real;
	cout << "Enter Imaginary:";
	cin >> this->imag;
}

complex complex::operator *(complex c)
{
	complex tmp(0.f,0.f);
	tmp.real = (real*c.real) - (imag*c.imag);
	tmp.imag = (real*c.imag) + (imag*c.real);
	return tmp;
}

bool complex::operator ==(complex c)
{
	return (real == c.real) && (imag == c.imag) ? 1 : 0;
}

ostream& operator <<(ostream &s, complex &c)
{
	s << "Real Part = " << c.real << endl
		<< "Imaginary Part = " << c.imag << endl;
	s << "z = " << c.real << setiosflags(ios::showpos)
		<< c.imag << "i" << endl << resetiosflags(ios::showpos);
	return s;
}



int main()
{
	complex a(10.0f, -2.f); 
	cout << a << endl;               
	complex b(-2);
	complex d(0);
	complex c = b;                    // Копирующий конструктор
	if(b == c)            // Вызов оператора ==
		cout << "b == c";
	else
		cout << "b != c";

	d = a*b;        // вызов оператора *
	cout << d << endl;
	system("pause.exe");
	return 0;
}