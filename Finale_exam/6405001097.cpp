#include <iostream>
using namespace std;
class Cooking {
	double time;
public:
	Cooking() { setTime(0); }
	Cooking(int time) { setTime(time); }
	void setTime(int t) { time = t; }
	double getTime() { return time; }
	virtual void show() = 0;
};
ostream& operator<<(ostream& os, Cooking& c) {
	c.show();
	return os;
}


class Grill :public Cooking {
	int stove;	//1.เตาอั้งโล่  2.เตาฮิบาชิ  3.เตาปิ้งย่างไฟฟ้า
public:
	Grill() :Cooking(5) { setStove(3); }
	Grill(double time,int stove) :Cooking(time) { setStove(stove); }
	void setStove(int s) { stove = s; }
	int getStove() { return stove; }
	void show() {
		cout << "Cooking by Stove type" << stove << ",Time " << getTime() << endl;
	}
};


class Fry :public Cooking {
	bool oilFree;	//true:ไม่ใช้น้ำมัน false:ใช้น้ำมัน
public:
	Fry() :Cooking(3) { setOil(0); }
	Fry(double time, bool oilFree) :Cooking(time) { setOil(oilFree); }
	void setOil(bool o) { oilFree = o; }
	bool getOil() { return oilFree; }
	string getOil_s() {
		if (oilFree)
			return "use oil";
		else
			return "not use oil";
	}
	void show() {
		cout << "Cooking by Fry " << getOil_s() << ",Time " << getTime() << endl;
	}
};


class Meat {
	bool organic;	//true:ปลอดสาร false:ไม่ปลอดสาร
public:
	Meat() { setOrganic(0); }
	Meat(bool organic) { setOrganic(organic); }
	void setOrganic(bool o) { organic = o; }
	bool getOrganic() { return organic; }
	string getOrganic_s() {
		if (organic)
			return "organic";
		else
			return "not organic";
	}
	virtual void show() = 0;
};
ostream& operator<<(ostream& os, Meat& m) {
	m.show();
	return os;
}


class Pork :public Meat {
	int part;		//1.สันใน  2.ซี่โครอ่อน  3.สามชั้น
public:
	Pork() :Meat(1) { setPart(1); }
	Pork(bool organic,int part) :Meat(organic) { setPart(part); }
	void setPart(int p) { part = p; }
	int getPart() { return part; }
	void show() {
		cout << getOrganic_s() << " Pork part" << part << endl;
	}
};


class Chicken :public Meat {
	int type;	//1.ไก่บ้าน  2.ไก่เนื้อ
public:
	Chicken() :Meat(0) { setType(2); }
	Chicken(bool oganic,int type) :Meat(oganic) { setType(type); }
	void setType(int t) { type = t; }
	int getType() { return type; }
	void show() {
		cout << getOrganic_s() << " Chicken type" << type << endl;
	}
};


class Food {
	double price;
	string dishName;
	Cooking* cooking;
	Meat** meat;
	int num;
	static int n;
	void setArrayMeat(int nMeat) {
		num = nMeat;
		meat = new Meat * [num];
	}
public:
	Food() {
		set(20);
		set("rice");
		cooking = 0;
		meat = 0;
		num = 0;
		n++;
	}
	Food(string name,double price, int nMeat,Cooking* cooking) {
		set(price);
		set(name);
		set(cooking);
		setArrayMeat(nMeat);
		n++;
	}
	~Food() { 
		if (meat != 0) {
			/*for (int i = 0; i < num; i++)
				delete meat[i];*/
			delete[] meat;
		}
		n--;
	}
	void set(Cooking* c) { cooking = c; }
	void set(double p) { price = p; }
	void set(string name) { dishName = name; }
	Cooking* getCooking() { return cooking; }
	double getPrice() { return price; }
	string getName() { return dishName; }
	Meat* getMeat(int i) { return meat[i]; }
	int getN() { return num; }
	void show() {
		cout << "\t" << dishName << endl;
		if (meat != 0){
			cout << "use Meat " << num << " type" << endl;
			for (int i = 0; i < num; i++) {
				cout << i + 1 << ".";
				meat[i]->show();
			}
		}
		if(cooking!=0)
			cooking->show();
		cout << "Price " << price << endl;
	}
	void setMeat(int i, Meat* m) {
		meat[i] = m;
	}
	void setNum(int nMeat) {
		if (meat != 0) {
			/*for (int i = 0; i < num; i++)
				delete meat[i];*/
			delete[]meat;
		}
		num = nMeat;
		setArrayMeat(num);
	}
	Food(Food& f) {
		set(f.price);
		set(f.dishName);
		set(f.cooking);
		setArrayMeat(f.num);
		for (int i = 0; i < num; i++)
			meat[i] = f.meat[i];
		n++;
	}
	static void count() { cout << "Total food now : " << n << endl; }
};
int Food::n;
ostream& operator<<(ostream& os, Food& f) {
	f.show();
	return os;
}


class Order {
	Food* food;
	int num;
	bool member;
	void setArray(int n) {
		num = n;
		food = new Food[num];
	}
public:
	Order() {
		food = 0;
		num = 0;
		setMember(0);
	}
	Order(int n, bool member) {
		setArray(n);
		setMember(member);
	}
	~Order() {
		delete[]food;
	}
	void setMember(bool m) { member = m; }
	int getN() { return num; }
	Food getFood(int i) { return food[i]; }
	bool getMember() { return member; }
	string getMember_s() {
		if (member)
			return "you are member";
		else
			return "you are not member";
	}
	void show() {
		for (int i = 0; i < num; i++){
			cout << i + 1 << endl;
			food[i].show();
		}
		cout << endl;
		cout << "Total food " << num << endl;
		cout << getMember_s() << endl;
	}
	void setFood(int i, Food& f) {
		food[i] = f;
	}
	void setNum(int n) {
		if (food != 0) {
			delete []food;
		}
		num = n;
		setArray(num);
	}
	double operator!() {
		double price = 0;
		for (int i = 0; i < num; i++)
			price += food[i].getPrice();
		return price;
	}
	Order(Order& o) {
		setMember(o.member);
		setArray(o.num);
		for (int i = 0; i < num; i++)
			food[i] = o.food[i];
	}
	bool operator()() { return member; }
	int getOrganic() {
		int m = 0;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < food[i].getN(); j++) {
				if (food[i].getMeat(j)->getOrganic())
					m++;
			}
		}
		return m;
	}
};
ostream& operator<<(ostream& os, Order& o) {
	o.show();
	return os;
}

int main()
{
	Cooking* c[4];
	c[0] = new Grill(30, 1);
	c[1] = new Grill(25, 2);
	c[2] = new Fry(10, 1);
	c[3] = new Fry(20, 0);
	for (int i = 0; i < 4; i++)
		c[i]->show();
	cout << "---" << endl;
	Meat* m[6];
	m[0] = new Chicken(1, 2);
	m[1] = new Chicken(0, 2);
	m[2] = new Chicken(1, 1);
	m[3] = new Pork(1, 1);
	m[4] = new Pork(1, 2);
	m[5] = new Pork(1, 3);
	for (int i = 0; i < 6; i++)
		m[i]->show();
	cout << "---" << endl;
	Food muTod("Garlic Fried Pork", 120, 1, c[3]);
	muTod.setMeat(0, m[3]);
	cout << muTod;
	cout << "---" << endl;
	muTod.setNum(2);
	muTod.setMeat(0, m[3]);
	muTod.setMeat(1, m[4]);
	muTod.set(c[2]);
	cout << muTod;
	cout << "---" << endl;
	Food kaiYang("Kay Yang", 100, 3, c[0]);
	for (int i = 0; i < 3; i++)
		kaiYang.setMeat(i, m[i]);
	cout << kaiYang << endl;
	cout << "---" << endl;
	Food samChanTod("Sam Chan Tod", 130, 1, c[2]);
	samChanTod.setMeat(0, m[5]);
	cout << samChanTod << endl;
	cout << "---" << endl;
	Food rice;
	cout << rice;
	cout << "---" << endl;
	Food::count();
	cout << "---" << endl;
	Order order1(2, 0);
	order1.setFood(0, rice);
	order1.setFood(1, muTod);
	cout <<"+++order1+++"<<endl<< order1;
	cout << "---" << endl;
	Order order2(4, 1);
	order2.setFood(0, rice);
	order2.setFood(1, rice);
	order2.setFood(2, kaiYang);
	order2.setFood(3, samChanTod);
	cout <<"+++order2+++"<<endl<< order2;
	cout << "---" << endl;
	cout << !order1 << endl;
	cout << !order2 << endl;
	cout << "---" << endl;
	Order order3(order1);
	order3.setMember(!(order3.getMember()));
	cout << "+++order3+++" << endl<< order3;
	cout << "---" << endl;
	cout << "organic:" << order2.getOrganic() << endl;
	cout << "---" << endl;
	for (int i = 0; i < order3.getN(); i++)
		cout << order3.getFood(i).getName() << ",";
	cout << endl;
	cout << "--finish--" << endl;
	//delete[] c;
	//delete[] m;
	for(int i=0; i<4; i++)
		delete c[i];
	delete[] c;
	for(int i=0; i<6; i++)
		delete m[i];
	delete[] m;
}
