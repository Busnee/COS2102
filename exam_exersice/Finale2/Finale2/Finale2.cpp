#include <iostream>
using namespace std;
class A {
	int a;
public:
	A() { set(2); cout << "A " << a << endl; }
	A(int i) { set(i); cout << "AA " << a << endl; }
	virtual ~A() { cout << "a= " << a << endl; }
	virtual void set(int i) { a = i; }
	virtual int operator()() { return a; }
	virtual int operator~() { return a = -a; }
	int operator[](int i) {
		cout << "using []" << endl;
		return (*this)() * i;
	}
};
class B :virtual public A {
	int b;
public:
	B() :A(3) { set(3); cout << "B " << b << endl; }
	B(int i) {
		set(i); cout << "BB " << b << endl;
	}
	~B() { cout << "b= " << b << endl; }
	void set(int i) { b = i; }
	int operator()() { return b; }
	int operator~() { return b *= b; }
};
class C :virtual public A {
	int c;
public:
	C() { set(1); cout << "C " << c << endl; }
	~C() { cout << "c= " << c << endl; }
	void set(int i) { c = i; }
	int operator()() { return c; }
	int operator~() { return c += c; }
};
class D :public B, public C {
	int d;
public:
	D() :A(5), B(6) {
		d = 3; cout << "D " << d << endl;
	}
	~D() { cout << "d= " << d << endl; }
	void set(int i) { d = i; }
	int operator()() { return d; }
	int operator~() { return d += 1; }
	void show(ostream& os) {
		os << A::operator()() << endl;
		os << B::operator()() << endl;
		os << C::operator()() << endl;
		os << (*this)() << endl;
	}
};
class E {
	D d;
public:
	D set(A* a) {
		d.set(~*a);
		return d;
	}
	friend ostream& operator<<(ostream& os, E& e) {
		e.d.show(os);
		return os;
	}
	D get() { return d; }
};
int main()
{
	A* a[4];
	E e;
	a[0] = new A;
	a[1] = new B(4);
	a[2] = new C;
	a[3] = new D;
	for (int i = 0; i < 4; i++) {
		a[i]->set(i);
		cout << (*a[i])() << endl;
	}
	B b;
	cout << "plus " << ~*a[2] + ~b << endl;
	cout << e;
	cout << ~e.get() << endl;
	cout << e.get()() << endl;
	e.set(a[2]).show(cout);
	for (int i = 0; i < 4; i++)
		cout << (*a[i])[i + 1] << endl;
	cout << "Good Luck" << endl;
	for (int i = 0; i < 4; i++)
		delete a[i];
}