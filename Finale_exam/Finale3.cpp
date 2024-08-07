#include <iostream>
using namespace std;
class A {
	static int count;
	int x;
public:
	A() { x = 2; }
	A(A& a) {
		x = a.x + 1;
		count++;
		cout << "copy A " << operator!() << endl;
	}
	~A() { cout << "~A " << !*this << endl; }
	A operator()(int x) {
		this->x = x;
		return *this;
	}
	A operator()(A a) {
		x = a.x + 2;
		cout << "operator() " << x << endl;
		return *this;
	}
	int operator!() { return x; }
	static int getNumCopy() {
		return count;
	}
	friend ostream& operator<<(ostream& os, A& a) {
		os << !a;
		return os;
	}
};
int A::count;
class B {
	A* a;
	int n;
public:
	B() { n = 1; a = new A[1]; }
	B& reset(int n) {
		delete[] a;
		this->n = n;
		a = new A[n];
		return *this;
	}
	B& operator()(int i, A& a) {
		this->a[i] = a;
		return *this;
	}
	A& operator[](int i) {
		return a[i];
	}
	~B() {
		delete[] a;
	}
};
int main()
{
	A a1, a2;
	a2 = a1(4);
	cout << a1 << " " << a2 << endl;
	B b;
	b.reset(3)(0, a1)(1, a2);
	A a3(a2);
	cout << !b[2](a3) << endl;
	cout << a3 << endl;
	for (int i = 0; i < 3; i++)
		cout << !b[i] << endl;
	cout << "num copy: " << A::getNumCopy() << endl;
	cout << "The End" << endl;
}