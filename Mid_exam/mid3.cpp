#include <iostream>
using namespace std;
class Corn {
	string type;
public:
	Corn() { setType("A"); }
	Corn(string type) { setType(type); }
	~Corn() { cout << "type:" << type << endl; }
	void setType(string t) { type = t; }
	string getType() { return type; }
	void show() {
		cout << "Type = " << type << endl;
	}
};

class CornStorage {
	int num;
	Corn* storage;
public:
	CornStorage() { num = 0; storage = 0; }
	CornStorage(int num) { setNum(num); }
	~CornStorage() { 
		cout << "num:" << num << endl;
		if(num!=0)
			delete[]storage; 
	}
	void setNum(int n) { 
		if (num != 0)
			delete []storage;
		num = (n < 0) ? 0 : n;
		storage = new Corn[num];
	}
	void setStorage(int i, string type) {
		storage[i].setType(type);
	}
	int getNum() { return num; }
	Corn getStorage(int i) { return storage[i]; }
	void show() {
		cout << "Num = " << num << endl;
		storage->show();
	}
};

class Somtum {
	double price;
	int chilliNum;
public:
	Somtum() { set(35, 3); }
	Somtum(double price, int chilli) { set(price, chilli); }
	~Somtum() {
		cout << "price:" << price;
		cout << " chilli:" << chilliNum << endl;
	}
	void set(double price, int chilli) {
		setPrice(price);
		setChilli(chilli);
	}
	void setPrice(double p) { price = (p <= 0) ? 1 : p; }
	void setChilli(int n) { chilliNum = (n < 0) ? 0 : n; }
	double getPrice() { return price; }
	int getChilli() { return chilliNum; }
	void show() {
		cout << "Price = " << price << endl;
		cout << "Chilli = " << chilliNum << endl;
	}
};

class SomtumCorn :public Somtum{
	Corn corn;
	bool saltedEgg;
	static int n;
public:
	SomtumCorn() :Somtum(40, 4) { 
		corn.setType("B");
		setEgg(true);
	}
	SomtumCorn(double price, int chilli, Corn corn, bool egg) :Somtum(price,chilli) {
		this->corn = corn;
		setEgg(egg);
	}
	~SomtumCorn() { cout << "saltedEgg:" << saltedEgg << endl; }	//0=ไม่ใส่ไข่เค็ม 1=ใส่ไข่เค็ม
	void setEgg(bool egg) { saltedEgg = egg; }
	Corn getCorn() { return corn; }
	bool getEgg() { return saltedEgg; }
	void show() {
		Somtum::show();
		corn.show();
		if (saltedEgg)
			cout << "put ";
		else
			cout << "not put ";
		cout << "Salted Egg" << endl;
	}
	static void count() { cout << n; }
};

class SomtumThai :public Somtum{
	bool peanut;
public:
	SomtumThai() { setPeanut(true); }
	SomtumThai(double price, int chilli, bool peanut) { setPeanut(peanut); }
	~SomtumThai() { cout << "peanut:" << peanut << endl; }	//0=ไม่ใส่ถั่ว 1=ใส่ถั่ว
	void setPeanut(bool peanut) { this->peanut = peanut; }
	bool getPeanut() { return peanut; }
	void show() {
		Somtum::show();
		if (peanut)
			cout << "put ";
		else
			cout << "not put ";
		cout << "Peanut" << endl;
	}
	bool moreChilli(SomtumThai t) {
		return getChilli() > t.getChilli();
	}
};

int SomtumCorn::n;
int main()
{
	CornStorage cornStorage(2);
	cornStorage.setStorage(0, "C");
	cornStorage.setStorage(1, "D");
	SomtumThai tumThai1(45, 7, 1), tumThai2(50, 12, 0);
	SomtumCorn tumCorn1(40, 5, cornStorage.getStorage(0),1);
	SomtumCorn tumCorn2(45, 7, cornStorage.getStorage(1), 0);
	tumThai1.show();
	tumThai2.show();
	tumCorn1.show();
	tumCorn2.show();
	if (tumThai1.moreChilli(tumThai2))
		cout << "Chilli of tumThai1 more than tumThai2" << endl;
	else
		cout << "Chilli of tumThai2 more than tumThai1" << endl;
	double total = 0;
	total += tumThai1.getPrice();
	total += tumThai2.getPrice();
	total += tumCorn1.getPrice();
	total += tumCorn2.getPrice();
	cout << "total Price = " << total << endl;
}