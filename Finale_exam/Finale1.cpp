#include <iostream>
using namespace std;
class C;
class E {
	int e;
protected:
	int n1() { return e * e; }
public:
	E() { e = 1; }
	E(int i) { e = i; }
	int n2(int i) { e += i; return e; }
	E n3(int i) { e = i; return *this; }
	int n4() { return n2(e); }
};

class A {
	E e;
protected:
	A f1(int x) { e.n2(x); return*this; }
public:
	int f2(int a) {
		return e.n3(a).n2(++a);
	}
	A f3(E e) {
		return f1(e.n2(this->e.n4()));
	}
	E f4() { return e; }
};

class B :public A {
		int b;
	protected:
		A g1(E e) { return e.f1(b); }
		int g2() { return b * b; }
	public:
		B() { b = 1; }
		E g3(A a) { return a.f3(f4()); }
		int g4() { return f2(b) + f4().n2(b); }
		E g5(E e) { return f3(e).f4(); }
		B g6(int i) { b = i + f4().n4(); return *this; }
		friend void bestFriend(B& b, E e);
};

class C {
	B b;
protected:
	int c;
	int h1(int i) { c = b.g4() + i; return c; }
public:
	C() { c = 0; }
	C h2(int i) { c += h1(i) * f1(i).f2(i); return *this; }
	int h3(int i) { c = b.g6(i).g5(b.f4()).f2(i); return c; }
	B h4(B b) { this->b = b; }
	B h5(int i) { b.g6(i).f2(i); return b; }
	C h6(E e) { c = e.n4() + 1; return *this; }
	int h7(A a) { return a.f4().n2(c); }
	A h8(int i) { return b.f1(b.f2(c)); }
};

void bestFriend(B& b, E e) {
	b.b = b.g2() + e.n4();
	int k = b.f1(2).f2(1);
	cout << b.e.n4() << endl;
}
int main()
{
	E e(3);
	cout << e.n2(2) << endl;
	cout << e.n4() + e.n1() << endl;
	A a;
	cout << a.f4().n4() << endl;
	B b;
	cout << b.g5(e).n2(a.f2(1)) << endl;
	E e2 = b.f3(e).f4().n3(0);
	cout << a.f3(e2).f2(e.n4()) << endl;
	C c;
	cout << c.h4(b).f3(e) << endl;
	cout << c.h7(b.f3(e)) << endl;
	cout << c.h6(e).h5(a.f2(2)).g4() << endl;
	cout << c.h5(3).h4(b).g4() << endl;
	cout << c.g6(2).g5(e).n2(1) << endl;
	a = b.f3(e2);
}
