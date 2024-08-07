#include <iostream>
using namespace std;
class Animal {
	int id;
	double length;
	int age;
	static int c;
	static int n;
	void setID() { n++; id = n; }
public:
	Animal() {
		setID();
		setLength(0.2);
		setAge(1);
		c++;
	}
	Animal(double length, int age) {
		setID();
		setLength(length);
		setAge(age);
		c++;
	}
	virtual ~Animal() {
		cout << "id:" << id << " length:" << length << " age:" << age << endl;
		c--;
	}
	static void count() { cout << c << endl; }
	void setLength(double l) { length = (l < 1) ? 1 : l; }
	void setAge(int a) { age = (a < 1) ? 1 : a; }
	int getID() { return id; }
	double getLength() { return length; }
	int getAge() { return age; }
	virtual void show() {
		cout << "ID = " << id << endl;
		cout << "Length = " << length << endl;
		cout << "Age = " << age << endl;
	}
	virtual int f(int) = 0;
};
int Animal::c;
int Animal::n;

class CommonBottlenoseDolphin : virtual public Animal {
	bool pink;
public:
	CommonBottlenoseDolphin() :Animal(2, 2) { setPink(0); }
	CommonBottlenoseDolphin(double length, int age, bool pink){
		setLength(length);
		setAge(age);
		setPink(pink);
	}
	~CommonBottlenoseDolphin() {
		cout << "pink:" << pink << endl;
	}
	void setLength(double l) { 
		l = (l > 3.1) ? 3.1 : l;
		Animal::setLength(l);
	}
	void setPink(bool p) { pink = p; }
	bool getPink() { return pink; }
	string gPink() { return (pink) ? "Pink" : "Not pink"; }
	void show() {
		Animal::show();
		cout << gPink() << endl;
	}
	int f(int i) {
		return pink;
	}
	void operator()(double length, int age, bool pink) {
		setLength(length);
		setAge(age);
		setPink(pink);
	}
};

class FalaseKillerWhale :virtual public Animal {
	int teeth;
public:
	FalaseKillerWhale() :Animal(3, 3) { setTeeth(8); }
	FalaseKillerWhale(double length,int age,int teeth){ 
		setLength(length);
		setAge(age);
		setTeeth(teeth); 
	}
	~FalaseKillerWhale() {
		cout << "teeth:" << teeth << endl;
	}
	void setLength(double l){
		l = (l > 6) ? 6 : l;
		Animal::setLength(l);
	}
	void setTeeth(int t) { teeth = (t < 7 || t>12) ? 7 : t; }
	int getTeeth() { return teeth; }
	void show() {
		Animal::show();
		cout << "Teeth = " << teeth << endl;
	}
	int f(int i) {
		return teeth;
	}
	FalaseKillerWhale& operator++() {
		setLength(getLength() + 1);
		return *this;
	}
};

class Wholpinn :public CommonBottlenoseDolphin, public FalaseKillerWhale {
	bool wild;
public:
	Wholpinn() :Animal(1.5, 1), CommonBottlenoseDolphin(1.5,1,0), FalaseKillerWhale(1.5,1,7) {
		set(1);
	}
	Wholpinn(double length, int age, bool pink, int teeth, bool wild) :Animal(length, age),
		CommonBottlenoseDolphin(length, age, pink), FalaseKillerWhale(length, age, teeth) {
		Animal::setLength(length);
		set(wild);
	}
	~Wholpinn(){
		cout << "wild:" << wild << endl;
	}
	void set(bool w) { wild = w; }
	void set(double length, int age, bool pink, int teeth, bool wild) {
		Animal::setLength(length);
		setAge(age);
		setPink(pink);
		setTeeth(teeth);
		set(wild);
	}
	bool getWild() { return wild; }
	string gWile() { return (wild) ? "Wild" : "Not wild"; }
	void show() {
		CommonBottlenoseDolphin::show();
		cout << "Teeth = " << getTeeth() << endl;
		cout << gWile() << endl;
	}
	int f(int c) {
		switch (c) {
		case 1:return getPink(); break;
		case 2:return getTeeth(); break;
		default: return getWild();
		}
	}
	Wholpinn(Wholpinn& w){
		set(w.getLength(),w.getAge(), w.getPink(), w.getTeeth(), w.getWild());
	}
	Wholpinn operator+(Wholpinn w) {
		Wholpinn n;
		if (getLength() < w.getLength())
			n.Animal::setLength(getLength());
		else
			n.Animal::setLength(w.getLength());
		
		if (getAge() < w.getAge())
			n.setAge(getAge());
		else
			n.setAge(w.getAge());

		if (getTeeth() > w.getTeeth())
			n.setTeeth(getTeeth());
		else
			n.setTeeth(w.getTeeth());

		n.setPink(1);
		n.set(0);
		return n;
	}
	void operator!() { wild = !wild; }
};
ostream& operator<<(ostream& os, Wholpinn& w) {
	w.show();
	return os;
}

class Fish {
	int num;
	Animal** a;
	int idZoo;
	void setArray(int n) {
		num = n;
		a = new Animal * [num];
	}
public:
	Fish() {
		num = 0;
		a = 0;
		idZoo = 0;
	}
	Fish(int n,int idz) {
		setArray(n);
		setIDZ(idz);
	}
	~Fish() {
		cout << "Zoo ID" << idZoo << " total fish:" << num << endl;			
	}
	void setIDZ(int z) { idZoo = z; }
	void setFish(int index, Animal& f) { a[index] = &f; }
	int getNum() { return num; }
	int getIDZ() { return idZoo; }
	Animal* getFish(int index) { return a[index]; }
	void show() {
		for (int i = 0; i < num; i++)
			a[i]->show();
	}
	Animal* operator[](int index) { return a[index]; }
};

int main()
{
	CommonBottlenoseDolphin a(2,1,1);
	FalaseKillerWhale b(5,2,8);
	Wholpinn c(6,1,1,9,0);
	Wholpinn d(7,2,0,10,0);
	Fish fish(4,123);
	fish.setFish(0,a);
	fish.setFish(1,b);
	fish.setFish(2,c);
	fish.setFish(3,d);
	fish.show();
	cout << "---" << endl;
	Wholpinn e(5, 3, 0, 8, 1);
	if (e.getAge() != fish[1]->getAge())
		cout << "ha ha" << endl;
	cout << "---" << endl;
	(c + d).show();
	cout << "---" << endl;
	Animal::count();
	cout << "---" << endl;
	double l = 0;
	for (int i = 0; i < 4; i++)
		l += fish[i]->getLength();
	l += e.getLength();
	cout << "total length = " << l << endl;
	cout << "---" << endl;
}