#include <iostream>
using namespace std;
template<class T>
T maximum(T a,T b,T c) {
	T max;
	max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	return max;
}
template<class P>
class maxInAray {
	P* a;
	int n;
public:
	maxInAray() {
		a = 0;
		n = 0;
	}
	maxInAray(int i) {
		n = i;
		a = new P[n];
	}
	void set(int i,P p) {
		if (i < n)
			a[i] = p;
		else
			cout << i<<"is more then size" << endl;
	}
	P findMax() {
		if (n != 0) {
			P max = a[0];
			for (int i = 1; i < n; i++) {
				if (a[i] > max)
					max = a[i];
			}
			return max;
		}
	}
	P findMin() {
		if (n != 0) {
			P min = a[0];
			for (int i = 1; i < n; i++) {
				if (a[i] < min)
					min = a[i];
			}
			return min;
		}
	}
};
class A {
	string name;
	int score;
public:
	A() {
		name = "noname";
		score = 0;
	}
	A(string name,int score) {
		this->name = name;
		this->score = score;
	}
	bool operator>(A& a) {
		return score > a.score;
	}
	bool operator<(A& a) {
		return score < a.score;
	}
	A& operator=(A& a) {
		name = a.name;
		score = a.score;
		return *this;
	}
	void print(ostream& os) {
		os << score << " of " << name << endl;
	}
};
ostream& operator<<(ostream& os, A& a) {
	a.print(os);
	return os;
}
int main() {
	int a[3]{ 1,2,3 };
	cout << "int " << maximum(a[0], a[1], a[2]) << endl;

	double b[3]{ 2.3,4.5,1.6 };
	cout << "double " << maximum(b[0], b[1], b[2]) << endl;

	A c1("busnee", 80), c2("chananda", 42), c3("dee", 56);
	cout << "class A ";
	A m = maximum(c1, c2, c3);
	cout << m << endl;

	cout << "------aray---------" << endl;
	maxInAray<int> b1(3);
	b1.set(0, 1);
	b1.set(1, 25);
	b1.set(2, 18);
	cout <<"max int "<< b1.findMax() << endl;
	cout << "min int " << b1.findMin() << endl;

	maxInAray<double> b2(3);
	b2.set(0, 80.5);
	b2.set(1, 42.4);
	b2.set(2, 71.2);
	cout <<"max double "<< b2.findMax() << endl;
	cout << "min double " << b2.findMin() << endl;

	maxInAray<A> b3(3);
	b3.set(0, c1);
	b3.set(1, c2);
	b3.set(2, c3);
	A maxA = b3.findMax();
	cout << "max class " << maxA;
	A minA = b3.findMin();
	cout << "min class " << minA;
}