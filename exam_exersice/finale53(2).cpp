#include <iostream>
using namespace std;
int k = 1;

class Animal {
	int id;
	double length;
	int age;
	static int n;
public:
	Animal() {
		id = k++;
		set(0.2, 1);
		n++;
	}
	Animal(double length, int age) {
		id = k++;
		set(length, age);
		n++;
	}
	virtual ~Animal() {
		cout << "id:" << id << " length:" << length << " age:" << age << endl;
		n--;
	}
	void setLength(double l) { length = (l <= 0) ? 1: l; }
	void setAge(int a) { age = (a <= 0) ? 1 : a; }
	void set(double length, int age) {
		setLength(length);
		setAge(age);
	}
	int getID() { return id; }
	double getLength() { return length; }
	int getAge() { return age; }
	virtual void show() = 0;
	static void count() { cout << n << endl; }
};
/*void showAnimal(Animal* a) {
	a->show();
}*/

class CommonBottlenoseDolphin :virtual public Animal{
	bool pink;
public:
	CommonBottlenoseDolphin() {
		setLengthDolphin(2);
		setAge(2);
		setPink(0);
	}
	CommonBottlenoseDolphin(double length, int age, bool pink) {
		setLengthDolphin(length);
		setAge(age);
		setPink(pink);
	}
	~CommonBottlenoseDolphin() {
		cout << "pink:" << pink << endl;	//0=not pink  1=pink
	}
	void setLengthDolphin(double length) {
		length = (length > 3.1) ? 3.1 : length;
		setLength(length);
	}
	void setPink(bool p) { pink = p; }
	bool getPink() { return pink; }
	void show() {
		cout << "ID = " << getID() << endl;
		cout << "Length = " << getLength() << endl;
		cout << "Age = " << getAge() << endl;
		if (pink)
			cout << "pink" << endl;
		else
			cout << "not pink" << endl;
	}
	void operator()(double length, int age, bool pink) {
		setLengthDolphin(length);
		setAge(age);
		setPink(pink);
	}
	CommonBottlenoseDolphin get() { return *this; }
};

class FalseKillerWhale :virtual public Animal {
	int teeth;
public:
	FalseKillerWhale() { 
		setLengthWhale(3);
		setAge(3);
		setTeeth(8); 
	}
	FalseKillerWhale(double length, int age, int teeth) { 
		setLengthWhale(length);
		setAge(age);
		setTeeth(teeth); 
	}
	~FalseKillerWhale() {
		cout << "teeth:" << teeth << endl;
	}
	void setLengthWhale(double length) {
		length = (length > 6) ? 6 : length;
		setLength(length);
	}
	void setTeeth(int t) {
		teeth = (t < 7) ? 7 : t;
		teeth = (t > 12) ? 12 : t;
	}
	int getTeeth() { return teeth; }
	void show() {
		cout << "ID = " << getID() << endl;
		cout << "Length = " << getLength() << endl;
		cout << "Age = " << getAge() << endl;
		cout << "Teeth = " << teeth << endl;
	}
	FalseKillerWhale& operator++() {		//pre
		setLengthWhale(getLength() + 1);
		return *this;
	}
	FalseKillerWhale& operator++(int) {		//post
		setLengthWhale(getLength() + 1);
		return *this;
	}
	FalseKillerWhale get() { return *this; }
};

class Wholphin :public CommonBottlenoseDolphin, public FalseKillerWhale {
	bool wild;
public:
	Wholphin() :Animal(1.5, 1) {
		setTeeth(7);
		setPink(0);
		set(1);
	}
	Wholphin(double length, int age, bool pink, int teeth, bool wild) :Animal(length, age) {
		setTeeth(teeth);
		setPink(pink);
		set(wild);
	}
	~Wholphin() {
		cout << "wild:" << wild << endl;
	}
	void set(bool w) { wild = w; }
	bool getWild() { return wild; }
	void show() {
		CommonBottlenoseDolphin::show();
		cout << "Teeth = " << getTeeth() << endl;
	}
	Wholphin& operator+(Wholphin& wp) {
		Wholphin wholphin;
		//----length------
		if (getLength() < wp.getLength())
			wholphin.setLength(getLength());
		else
			wholphin.setLength(wp.getLength());
		//----age-----
		if (getAge() < wp.getAge())
			wholphin.setAge(getAge());
		else
			wholphin.setAge(wp.getAge());
		//----teeth----
		if (getTeeth() > wp.getTeeth())
			wholphin.setTeeth(getTeeth());
		else
			wholphin.setTeeth(wp.getTeeth());
		//---pink&wild---
		wholphin.setPink(1);
		wholphin.set(0);
		return wholphin;
	}
	void set(double length, int age, bool pink, int teeth, bool wild) {
		Animal::set(length, age);
		setPink(pink);
		setTeeth(teeth);
		set(wild);
	}
	Wholphin& operator!() {
		wild = !wild;
		return *this;
	}
	void print(ostream& os) {
		show();
	}
	Wholphin get() { return *this; }
};
ostream& operator<<(ostream& os, Wholphin& wp) {
	wp.print(os);
	return os;
}

class Fish {	//ค้างคาหลายจุด
	int num;
	Animal** a;
	int idZoo;
	void set(int n, int idZoo) {
		setIDzoo(idZoo);
		num = n;
		a = new Animal* [num];
	}
public:
	Fish() { num = 0; a = 0; idZoo = 0; }
	Fish(int n, int idZoo) { set(n, idZoo); }
	~Fish() {
		cout << "num:" << num << " idZoo:" << idZoo << endl;
		delete[]a;
	}
	void setFish(int i, Animal* animal) {
		a[i] = animal;
	}
	void setIDzoo(int izoo) { idZoo = izoo; }
	int getNum() { return num; }
	int getIDZoo() { return idZoo; }
	void show() {
		cout << "ID zoo " << idZoo << endl;
		for (int i = 0; i < num; i++){
			cout << i + 1 << ". ";
			a[i]->show();
		}
		cout << "Total fish = " << num << endl;
	}
	Animal& operator[](int index) { return *a[index]; }
};

int Animal::n;
int main()
{
	CommonBottlenoseDolphin a(3.5,2,0);
	FalseKillerWhale b(4,1,9);
	Wholphin c(6,3,1,12,1), d(5,2,0,8,0);
	Fish fish(4, 1);
	fish.setFish(0, &a);
	fish.setFish(1, &b);
	fish.setFish(2, &c);
	fish.setFish(3, &d);
	fish.show();
	cout << "------" << endl;
	Wholphin e(4.5, 1, 1, 8, 0);
	if (e.getAge() != fish[1].getAge())
		cout << "ha ha" << endl;
	cout << "------" << endl;
	Wholphin z;
	z = c + d;
	z.show();
	cout << "------" << endl;
	Animal::count();
	cout << "------" << endl;
	double totalLength = 0;
	totalLength += a.getLength();
	totalLength += b.getLength();
	totalLength += c.getLength();
	totalLength += d.getLength();
	totalLength += e.getLength();
	totalLength += z.getLength();
	cout << "Total length = " << totalLength << endl;
	cout << "------" << endl;
}