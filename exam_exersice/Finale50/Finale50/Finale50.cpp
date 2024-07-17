using namespace std;
#include <iostream>
class Animal {
	int id;
	int weight;
	int age;
	static int n;
	static int count;
public:
	Animal() {
		id = ++n;
		set(2, 1);
		count++;
	}
	Animal(int weight, int age) {
		id = ++n;
		set(weight, age);
		count++;
	}
	virtual ~Animal() {
		cout << "id:" << id << " weigth:" << weight << " age:" << age << endl;
		count--;
	}
	void set(int weight, int age) {
		setWeight(weight);
		setAge(age);
	}
	void setWeight(int w) { weight = (w <= 1) ? 2 : w; }
	void setAge(int a) { age = (a < 1 || a>40) ? 1 : a; }
	int getID() { return id; }
	int getWeight() { return weight; }
	int getAge() { return age; }
	virtual void show() {
		cout << "Animal ID " << id << endl;
		cout << "Age " << age << " Weight " << weight << endl;
	}
	virtual int get() { return weight; }
	static void countA() { cout << count << endl; }
};
int Animal::n;
int Animal::count;


class Donkey :virtual public Animal {
	int color;	//1.soft brown 2.hard brown 3.gray 4.etc.
public:
	Donkey() :Animal(100, 1) {
		setColor(1);
	}
	Donkey(int weight, int age, int color) :Animal(weight, age) {
		setColor(color);
	}
	~Donkey() { cout << "color:" << color << endl; }
	void setColor(int c) { color = (c < 1 || c>4) ? 4 : c; }
	int getColor() { return color; }
	string getColor_s() {
		switch (color) {
		case 1:return"soft brown";	break;
		case 2:return"hard brown";	break;
		case 3:return"gray";	break;
		default:return"etc.";
		}
	}
	void show() {
		Animal::show();
		cout << getColor_s() << endl;
	}
	void operator()(int weight, int age, int color) {
		Animal::set(weight, age);
		setColor(color);
	}
	int get() { return color; }
};


class Zebra :virtual public Animal {
	bool social;
public:
	Zebra() :Animal(250, 2) { setSocial(1); }
	Zebra(int weight, int age, bool social) :Animal(weight, age) { setSocial(social); }
	~Zebra() {
		cout << "social:" << social << endl;
	}
	void setSocial(bool s) { social = s; }
	bool getSocial() { return social; }
	string getSocial_s() {
		if (social)
			return"like social";
		else
			return"not like social";
	}
	void show() {
		Animal::show();
		cout << getSocial_s() << endl;
	}
	Zebra operator+(Zebra& a) {
		Zebra z;
		if (social && a.getSocial())
			z.setSocial(0);
		else
			z.setSocial(1);
		setAge(1);
		setWeight((getWeight() + a.getWeight()) / 2);
	}
	int get() { return social; }
};


class Zonkey :public Donkey, public Zebra {
	int zooID;
public:
	Zonkey() :Animal(200, 2) {
		setColor(2);
		setSocial(0);
		setZooID(224);
	}
	Zonkey(int weight, int age, int color, bool social, int zooID) :Animal(weight, age) {
		setColor(color);
		setSocial(social);
		setZooID(zooID);
	}
	~Zonkey() {
		cout << "zooID:" << zooID << endl;
	}
	void setZooID(int id) { zooID = id; }
	int getZooID() { return zooID; }
	void show() {
		Donkey::show();
		cout << getSocial_s() << endl;
		cout << "Zoo ID " << zooID << endl;
	}
	int operator[](int index) {
		switch (index) {
		case 1:return getID();		break;
		case 2:return getWeight();	break;
		case 3:return getAge();		break;
		case 4:return getColor();	break;
		default: return zooID;
		}
	}
	void set(int weight, int age, int color, bool social, int zooID) {
		Animal::set(weight, age);
		setColor(color);
		setSocial(social);
		setZooID(zooID);
	}
	void set(int color, bool social, int zooID) {
		setColor(color);
		setSocial(social);
		setZooID(zooID);
	}
	Zonkey& operator++() {
		setWeight(getWeight() + 1);
	}
	Zonkey& operator++(int) {
		setWeight(getWeight() + 1);
		return *this;
	}
	Zonkey& operator!() {
		setSocial(!getSocial());
		return *this;
	}
	int get() { return zooID; }
};
ostream& operator<<(ostream& os, Zonkey& z) {
	z.show();
	return os;
}

int main()
{
	Animal** a = new Animal * [3];
	a[0] = new Donkey;
	a[1] = new Zebra;
	a[2] = new Zonkey;
	a[0]->set(150, 1);
	a[1]->set(200, 1);
	a[2]->set(250, 2);
	for (int i = 0; i < 3; i++)
	{
		a[i]->show();
		cout << "---" << endl;
	}
	Donkey b(220, 5, 3);
	Zonkey c(230, 3, 3, 0, 336);
	if (c.getColor() != a[0]->get())
		cout << "ha ha" << endl;
	!c;
	//cout << c << endl;
	Animal::countA();
	int w = 0;
	for (int i = 0; i < 3; i++)
		w += a[i]->get();
	w += b.getWeight();
	w += c.getWeight();
	cout << "Total weight = " << w << endl;
	int n = 0;
	if (a[2]->get() == 3)
		n++;
	if (c.getColor() == 3)
		n++;
	cout << "gray Donkey = " << n << endl;
	for (int i = 0; i < 3; i++)
		delete a[i];
	delete[] a;
	cout << "---" << endl;
}