#include <iostream>
using namespace std;
class A {
	int a;
public:
	A() { a = -1; }
	A(int i) { a = i; }
	//~A() { cout << "~A" << endl; }
	int get() { return a; }
	virtual void p()throw(int) {
		throw a + 10;
	}
};
class B :public A {
	int b;
public:
	B() { b = -2; }
	B(int i) { b = i; }
	//~B() { cout << "~B" << endl; }
	int get() { return b; }
	void set(int i) { b = i; }
	void p()throw(int) {
		throw b + A::get();
	}
};
class MyException :public exception {
	const char* what() const throw() {
		return "exception:MyException";
	}
};
class YourException :public MyException {
	const char* what() const throw() {
		return "exception:YourException";
	}
};
void f(B);
void g1(int, char);
void g2(int,char);
int main()
{
	//-----------12.1------------
	try {
		throw 5;
	}
	catch (int e) {
		cout << "int:" << e << endl;
	}
	catch (double e) {
		cout << "double:" << e << endl;
	}
	catch (char e) {
		cout << "char:" << e << endl;
	}
	catch (string e) {
		cout << "string:" << e << endl;
	}
	catch (...) {
		cout << "othr" << endl;
	}
	//---------------------------
	try {
		throw 2.5;
	}
	catch (int e) {
		cout << "int:" << e << endl;
	}
	catch (double e) {
		cout << "double:" << e << endl;
	}
	catch (char e) {
		cout << "char:" << e << endl;
	}
	catch (string e) {
		cout << "string:" << e << endl;
	}
	catch (...) {
		cout << "othr" << endl;
	}
	//---------------------------
	try {
		throw 'a';
	}
	catch (int e) {
		cout << "int:" << e << endl;
	}
	catch (double e) {
		cout << "double:" << e << endl;
	}
	catch (char e) {
		cout << "char:" << e << endl;
	}
	catch (string e) {
		cout << "string:" << e << endl;
	}
	catch (...) {
		cout << "othr" << endl;
	}
	//---------------------------
	try {
		string s = "hello";
		throw s;
	}
	catch (int e) {
		cout << "int:" << e << endl;
	}
	catch (double e) {
		cout << "double:" << e << endl;
	}
	catch (char e) {
		cout << "char:" << e << endl;
	}
	catch (string e) {
		cout << "string:" << e << endl;
	}
	catch (...) {
		cout << "othr" << endl;
	}
	//-------------12.2--------------
	cout << "--12.2--" << endl;
	try {
		A a;
		throw a;
	}
	catch (int e) {
		cout << "int:" << e << endl;
	}
	catch (double e) {
		cout << "double:" << e << endl;
	}
	catch (char e) {
		cout << "char:" << e << endl;
	}
	catch (string e) {
		cout << "string:" << e << endl;
	}
	catch (...) {
		cout << "othr" << endl;
	}
	//------------12.3---------------
	cout << "--12.3--" << endl;
	try {
		B b;
		throw b;
	}
	catch (B& b) {
		cout << "B:" << b.get() << endl;
	}
	catch (A& a) {
		cout << "A:" << a.get() << endl;
	}
	//--------------------------------
	try {
		B b;
		throw b;
	}
	catch (A& a) {
		cout << "A:" << a.get() << endl;
	}
	catch (B& b) {
		cout << "B:" << b.get() << endl;
	}
	//----------12.4-----------
	cout << "--12.4--" << endl;
	try {
		g2(4, 'a');
		}
	catch (char c) {
		cout << "char:" << c << endl;
	}
	//cout << 143 << endl;
	//-----------12.5-----------
	cout << "--12.5--" << endl;
	try {
		B b(3);
		b.p();
	}
	catch (int i) {
		cout << "int:" << i << endl;
	}
	//-----------12.6-----------
	cout << "--12.6--" << endl;
	try {
		YourException you;
		throw you;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	try {
		MyException me;
		throw me;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

}
void f(B b) throw(A) {
	b.set(b.get() * 2);
	throw b;
}
void g1(int a,char b) throw(char) {
	throw b;
}
void g2(int a,char b) throw(char) {
	g1(a+1, b+2);
	throw b;
}