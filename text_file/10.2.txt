#include <iostream>
using namespace std;
const double pi = 3.14;
class Shape {
public:
	virtual double area() = 0;
	virtual void print(ostream& os) = 0;
	virtual void input(istream& is) = 0;
	virtual ~Shape() {
		cout << "bye Shape" << endl;
	}
};
class TwoDimenional :public Shape {
public:
	~TwoDimenional() {
		cout << "bye Two" << endl;
	}
};
class Rectangle :public TwoDimenional {
	double width, length;
public:
	Rectangle() {
		set(0, 0);
	}
	Rectangle(double width, double length){
		set(width, length);
	}
	double area() {
		return width * length;
	}
	~Rectangle() {
		cout << "bye Rec" << endl;
	}
	void set(double w, double h) {
		width = w;
		length = h;
	}
	double getWidth() { return width; }
	double getLength() { return length; }
	void print(ostream& os) {
		os <<"---Rectangle---" << endl;
		os << "width=" << width;
		os << " length=" << length;
		os << " arae=" << area();
		os << endl;
	}
	void input(istream& is) {
		cout << "Enter width : ";	is >> width;
		cout << "Enter length : ";	is >> length;
	}
};
class Triangle:public TwoDimenional {
	double base, hight;
public:
	Triangle() {
		set(0, 0);
	}
	Triangle(double base, double hight){
		set(base, hight);
	}
	double area() {
		return 1.0 / 2.0 *base * hight;
	}
	~Triangle() {
		cout << "bye Tri" << endl;
	}
	void set(double b,double h) {
		base = b;
		hight = h;
	}
	void print(ostream& os) {
		os << "---Triangle---" << endl;
		os << "base=" << base;
		os << " hight=" << hight;
		os << " arae=" << area();
		os << endl;
	}
	void input(istream& is) {
		cout << "Enter base : ";	is >> base;
		cout << "Enter hight : ";	is >> hight;
	}
};
class Circle :public TwoDimenional {
	double radious;
public:
	Circle() {
		set(0);
	}
	Circle(double radious) { set(radious); }
	double area() {
		return pi * radious * radious;
	}
	~Circle() {
		cout << "bye Circle" << endl;
	}
	void set(double r) {
		radious = r;
	}
	void print(ostream& os) {
		os << "---Circle---" << endl;
		os << "radious=" << radious;
		os << " arae=" << area();
		os << endl;
	}
	void input(istream& is) {
		cout << "Enter radious : ";	is >> radious;
	}
};
class ThreeDimensional :public Shape {
public:
	~ThreeDimensional() {
		cout << "bye three" << endl;
	}
	virtual double volume() = 0;
};
class Cylinder :public ThreeDimensional {
	double radious, hight;
public:
	Cylinder() {
		set(0, 0);
	}
	Cylinder(double radious, double hight) {
		set(radious, hight);
	}
	~Cylinder() {
		cout << "bye cylinder" << endl;
	}
	void set(double r, double h) {
		radious = r;
		hight = h;
	}
	double area() {
		double a;
		a = pi * radious * radious;
		a += baseArea();
		return a;
	}
	double baseArea() {
		return 2 * pi * radious * hight;
	}
	double volume() {
		return baseArea() * hight;
	}
	void print(ostream& os) {
		os << "radious=" << radious;
		os << " hight=" << hight;
		os << " area=" << area();
		os << " volume=" << volume();
		os << endl;
	}
	void input(istream& is) {
		cout << "Enter radious : ";	is >> radious;
		cout << "Enter hight : ";	is >> hight;
	}
};
class Sphere :public ThreeDimensional {
	double radious;
public:
	Sphere() {
		set(0);
	}
	Sphere(double radious) {
		set(radious);
	}
	~Sphere() {
		cout << "bye sphere";
	}
	void set(double r) {
		radious = r;
	}
	double area() {
		return 4 * pi * radious * radious;
	}
	double volume() {
		return 4.0 / 3.0 * pi * radious * radious * radious;
	}
	void print(ostream& os) {
		os << "radious=" << radious;
		os << " arae=" << area();
		os << " volume=" << volume();
		os << endl;
	}
	void input(istream& is) {
		cout << "Enter radious : ";	is >> radious;
	}
};

double findArea(Shape *s) {
	return s->area();
}
double findVolume(ThreeDimensional *t) {
	return t->volume();
}
ostream& operator<<(ostream& os,Shape *s) {
	s->print(os);
	return os;
}
istream& operator>>(istream& is, Shape *s) {
	s->input(is);
	return is;
}
ostream& operator<<(ostream& os, Shape& s) {
	s.print(os);
	return os;
}
istream& operator>>(istream& is, Shape& s) {
	s.input(is);
	return is;
}
int main()
{
	//-----rectagle---------
	Shape* a;
	a = new Rectangle(3,4);
	cout << a;
	delete a;
	Shape* b;
	b = new Rectangle;
	//cin >> b;
	cout << "a" << findArea(b) << endl;
	delete b;
	//-------triangle--------
	a = new Triangle(3,4);
	cout << a;
	b = new Triangle;
	//cin >> b;
	cout << b;
	cout << "a" << findArea(b) << endl;
	delete a;
	delete b;
	//---------circle--------
	a = new Circle(3);
	cout << a;
	b = new Circle;
	//cin >> b;
	cout << b;
	cout << "a" << findArea(b) << endl;
	delete a;
	delete b;
	//----------cylinder-------
	ThreeDimensional *c;
	ThreeDimensional* d;
	d = new Cylinder(3, 4);
	cout << d;
	c = new Cylinder;
	//cin >> c;
	cout << c;
	cout << "a" << findArea(c) << endl;
	cout << "v" << findVolume(c) << endl;
	delete d;
	delete c;
	//--------sphere----------
	d = new Sphere(3);
	cout << d;
	c = new Sphere;
	//cin >> c;
	cout << c;
	cout << "a" << findArea(c) << endl;
	cout << "v" << findVolume(c) << endl;

	Shape* p[3];
	p[0] = new Rectangle(2,2);
	p[1] = new Triangle(2,2);
	p[2] = new Circle(2);
	ThreeDimensional* q[2];
	q[0] = new Cylinder(2,2);
	q[1] = new Sphere(2);
	cout << "--Two--" << endl;
	for (int i = 0; i < 3; i++) {
		cout << p[i]->area() << endl;
	}
	cout << "--Three--" << endl;
	for (int i = 0; i < 2; i++) {
		cout << q[i]->area() << ", ";
		cout << q[i]->volume() << endl;
	}
}