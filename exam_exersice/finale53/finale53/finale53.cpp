#include <iostream>
using namespace std;
int k=0;
class Animal {	//สัตว์
	int id;
	double length;
	int age;
	static int n;
public:
	Animal() {
		n++;
		id = ++k;
		set(0.2, 1);
		//cout << n << endl;
	}
	Animal(double length, int age) {
		n++;
		id = ++k;
		set(length, age);
		//cout << n << endl;
	}
	virtual ~Animal() {
		n--;
		cout << "id:" << id << " length:" << length << " age:" << age << endl;
		//cout << n << endl;
	}
	void set(double length, int age) {
		setLength(length);
		setAge(age);
	}
	void setLength(double l){
		length = (l <= 0) ? 0.1 : l;
	}
	void setAge(int a){
		age = (a <= 0) ? 1 : a;
	}
	int getID() { return id; }
	double getLength() { return length; }
	int getAge() { return age; }
	virtual void show() {
		cout << "ID = " << id << endl;
		cout << "Length = " << length << endl;
		cout << "Age = " << age << endl;
	}
	static void count() { cout << "total animal = " << n << endl; };
};

class CommonBottlenoseDolphin :virtual public Animal {		//โลมาปากขวดธรรมดา
	bool pink;
public:
	CommonBottlenoseDolphin() :Animal(2, 2) {
		setPink(0);
	}
	CommonBottlenoseDolphin(double length, int age, bool pink) {
		length = (length > 3.1) ? 3.1 : length;		//โลมายาวไม่เกิน3.1
		Animal::set(length, age);
		setPink(pink);
	}
	~CommonBottlenoseDolphin() {
		cout << "pink:" << pink << endl;
	}
	void setPink(bool p) {
		pink = p;
	}
	bool getPink() { return pink; }
	void show() {
		cout << "Common Bottlenose Dolphin" << endl;
		Animal::show();
		cout << "Pink = ";
		if (pink == 1)
			cout << "yes";
		else
			cout << "no";
		cout << endl;
	}
	void operator()(double length, int age, bool pink) {
		Animal::set(length, age);
		setPink(pink);
	}
};

class FalseKillerWhale :virtual public Animal {		//วาฬเพชรฆาตร
	int teeth;
public:
	FalseKillerWhale() :Animal(3, 3) {
		setTeeth(8);
	}
	FalseKillerWhale(double length, int age, int teeth) {
		length = (length > 6) ? 6 : length;
		Animal::set(length, age);
		setTeeth(teeth);
	}
	~FalseKillerWhale() {
		cout << "teeth:" << teeth << endl;
	}
	void setTeeth(int t) {
		teeth = (t < 7) ? 7 : t;
		teeth = (teeth > 12) ? 12 : teeth;
	}
	int getTeeth() { return teeth; }
	void show() {
		cout << "False Killer Whale" << endl;
		Animal::show();
		cout << "Teeth = " << teeth << endl;
	}
	FalseKillerWhale& operator++() {
		if(getLength()<6)
			setLength(getLength()+1);
		return *this;
	}
};

class Wholphin :public CommonBottlenoseDolphin, public FalseKillerWhale {	//ลูกผสม
	bool wild;
public:
	Wholphin() :Animal(1.5, 1){
		CommonBottlenoseDolphin::setPink(0);
		FalseKillerWhale::setTeeth(7);
		setWild(1);
	}
	Wholphin(double length, int age, bool pink, int teeth, bool wild) :Animal(length, age) {
		setPink(pink);
		setTeeth(teeth);
		setWild(wild);
	}
	~Wholphin() {
		cout << "wild:" << wild << endl;
	}
	void setWild(bool w) {
		wild = w;
	}
	bool getWild() { return wild; }
	void show() {
		cout << "Wholphin" << endl;
		Animal::show();
		cout << "Pink = ";
		if (getPink() == 1)
			cout << "yes";
		else
			cout << "no";
		cout << endl;
		cout << "Teeth = " << getTeeth() << endl;
		cout << "Wild = ";
		if (wild == 1)
			cout << "yes";
		else
			cout << "no";
		cout << endl;
	}
	Wholphin operator+(Wholphin& w) {
		Wholphin a;
		if (getLength() < w.getLength())
			a.setLength(getLength());
		else
			a.setLength(w.getLength());
		
		if (getAge() < w.getAge())
			a.setAge(getAge());
		else
			a.setAge(w.getAge());
		
		if (getTeeth() > w.getTeeth())
			a.setTeeth(getTeeth());
		else
			a.setTeeth(w.getTeeth());

		a.setPink(1);
		a.setWild(0);
		return a;
	}
	void set(double length, int age, bool pink, int teeth, bool wild) {	//overloading void Animal::set(..)
		Animal::set(length, age);
		setPink(pink);
		setTeeth(teeth);
		setWild(wild);
	}
	Wholphin& operator!() {
		setWild(!wild);
		return *this;
	}
	void print(ostream& os) {
		show();
	}
};
ostream& operator<<(ostream& os,Wholphin w) {
	w.print(os);
	return os;
}

class Fish {
	int num;
	Animal** a;
	int idZoo;
public:
	Fish() {
		num = 0; a = 0; idZoo = 0;
	}
	Fish(int n,int idz) {
		num = (n <= 0) ? 1 : n;
		idZoo = idz;
		a = new Animal * [num];
	}
	~Fish() {
		cout << "num:" << num << " idZoo:" << idZoo << endl;
		for (int i = 0; i < num; i++)
			delete a[i];
		delete[]a;
	}
	void set(int i,Animal* ani) {
		a[i] = ani;
	}
	Animal& get(int i) {
		return *a[i];
	}
	void show() {
		if (a != 0) {
			for (int i = 0; i < num; i++) {
				cout << i + 1 << ".";
				a[i]->show();
				cout << "-----" << endl;
			}
		}
		else
			cout << "a = NULL" << endl;
	}
	Animal& operator[](int i) {
		return *a[i];
	}
};

int Animal::n;
int main()
{
	CommonBottlenoseDolphin a(8, 2, 1);
	FalseKillerWhale b(5, 3, 9);
	Wholphin c(7, 1, 1, 10, 0);
	Wholphin d(6, 2, 0, 8, 1);
	Fish fish(4, 0001);
	fish.set(0, &a);
	fish.set(1, &b);
	fish.set(2, &c);
	fish.set(3, &d);
	fish.show();
	Wholphin e(8.5, 4, 1, 9, 0);
	if (e.getAge() != fish[1].getAge())
		cout << "ha ha" << endl;
	//cout << "++++++" << endl;
	cout << c + d << endl;
	//cout << "++++++" << endl;
	Animal::count();
	double length = 0;
	length += a.getLength();
	length += b.getLength();
	length += c.getLength();
	length += d.getLength();
	length += e.getLength();
	cout << "sum length = " << length << endl;
}