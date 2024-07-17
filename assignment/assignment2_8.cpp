#include <iostream>
using namespace std;
class Rational {
private:
	float numerator,Denominator;
public:
	Rational() {
		set(0, 1);
	}
	Rational(float numerator,float denominator) {
		set(numerator, denominator);
	}
	Rational(float numerator) {
		set(numerator, 1);
	}
	~Rational() {
		cout << "bye bye" << endl;
	}

	float divide() {
		return numerator / Denominator;
	}

	void set(float a,float b) {
		numerator = a;
		Denominator = b;
	}
	void setNumerator(float a) {
		numerator = a;
	}
	void setDenominator(float b) {
		Denominator = b;
	}
	float getNumerator() {
		return numerator;
	}
	float getDenomitor() {
		return Denominator;
	}
	void show() {
		cout << "Numerator = " << numerator << endl;
		cout << "Denominator = " << Denominator << endl;
	}

};
int main()
{
	Rational a, b(3.0), c(4.0, 2.0);
	cout << "a = " << a.divide() << endl; a.show();
	cout << "b = " << b.divide() << endl; b.show(); 
	cout << "c = " << c.divide() << endl; c.show();
	b.setDenominator(2.0);
	cout << "b = " << b.divide() << endl; b.show();
}