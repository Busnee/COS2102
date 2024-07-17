#include <iostream>
using namespace std;
class A {
	int a;
protected:
	int aa;
public:
	A() { a = aa = 1; }
	A(int a) {
		this->a = a;
		aa = a;
	}
	A& setA(int i) {
		a = i;
		return *this;
	}
	A& setAA(int i) {
		aa = i;
		return *this;
	}
	int getA() { return a; }
	int getAA() { return aa; }
	A fa() { aa += aa; return *this; }
};
class B : public A {
	int b;
protected:
	int fb1() { return b * aa; }
public:
	B() :A(3) { b = 3 * a; }
	B(int i, int j) :A(j) { b = i; }
	B& setB(int i) { b = i; return *this; }
	A fb2(A a) {
		b = a.getA();
		a.setA(b);
		return a;
	}
	int fb3(B b) { b = b.getAA(); }
	int fb4() { b = aa; return b; }
};
class C :public B {
	int c;
protected:
	int fc1() { return fb1(); }
public:
	C(int i, int j) :B(i, j) { c = aa; }
	void fc2(B b) { c = b.aa; }
	C fc3() { return C(c, c); }
	int getC() { return c; }
};
int main()
{
	A a;
	B b(3, 4);
	C c(1, 2);
	cout << c.fc3().getA() << endl;
	cout << b.fb2(a).fa().getAA() << endl;
	a.setA(5).setAA(4);
	cout << c.getC() + b.fb2(a).fb4() << endl;
	cout << b.setB(a.getAA()).getA() << endl;
	cout << c.fb4() + c.fc1() << endl;
}
