#include <iostream>
using namespace std;
int r = 0;
class Dessert {
	int id;
	int price;
	int kcal;
public:
	Dessert() { 
		id = ++r;
		set(10, 180);
	}
	Dessert(int price, int kcal) {
		id = ++r;
		set(price, kcal);
	}
	virtual ~Dessert() {
		cout << "id:" << id << " price:" << price << " kcal:" << kcal << endl;
	}
	void setPrice(int p) { price = (p <= 0) ? 1 : p; }
	void setKcal(int cal) { kcal = (cal <= 0) ? 1 : cal; }
	void set(int price, int kcal) {
		setPrice(price);
		setKcal(kcal);
	}
	int getID() { return id; }
	int getPrice() { return price; }
	int getKcal() { return kcal; }
	virtual void show() {
		cout << "ID " << id << " Price " << price << " bath " << kcal << " kcal" << endl;
	}
	virtual string f() = 0;
};
ostream& operator<<(ostream& os, Dessert& d) {
	d.show();
	return os;
}


class Topping {
	int topping;	//1.icing 2.choclate 3.green tea 4.condyflos 5.Marshmallow
	int amount;
public:
	Topping() { set(1, 1); }
	Topping(int topping, int amount) { set(topping, amount); }
	~Topping() {
		cout << "topping:" << topping << "amount:" << amount << endl;
	}
	void setTopping(int t) { topping = (t < 1 || t>5) ? 1 : t; }
	void setAmount(int a) { amount = (a <= 0) ? 1 : a; }
	void set(int topping, int amount) {
		setTopping(topping);
		setAmount(amount);
	}
	int getTopping() { return topping; }
	string getTopping_s() {
		switch (topping) {
		case 1:return"icing";	break;
		case 2:return"choclate";	break;
		case 3:return"green tea";	break;
		case 4:return"condyflos";	break;
		case 5:return"Marshmallow";
		}
	}
	int getAmount() { return amount; }
	void show() {
		cout << getTopping_s() << " " << amount << " unit" << endl;
	}
};


class Donut :virtual public Dessert {
	int type;	//0.none 1.donut yeast 2.donut cake
	Topping* t;
	int num;
	static int n;
public:
	Donut() :Dessert(20, 200) {
		num = 1;
		t = new Topping[num];
		t[0].set(1, 2);
		setType(2);
		n++;
	}
	Donut(int price, int kcal, int type, int nTopping) {
		setType(type);
		num = nTopping;
		t = new Topping[num];
		n++;
	}
	~Donut() {
		cout << "type:" << type << " nTopping:" << num << endl;
		delete[]t;
		n--;
	}
	void setType(int t) { type = (t < 1 || t>2) ? 0 : t; }
	void setNum(int n) {
		delete[]t;
		num = n;
		t = new Topping[num];
	}
	void setT(int i, int topping, int amount) {
		t[i].set(topping, amount);
	}
	int getType() { return type; }
	string getType_s() {
		switch (type) {
		case 1:return"yeast";	break;
		case 2:return"cake";	break;
		default:return "none type";
		}
	}
	int getNTopping() { return num; }
	Topping& getTopping(int i) { return t[i]; }
	void show() {
		cout << f() << getType_s() << endl;
		Dessert::show();
		showTopping();
	}
	void showTopping() {
		cout << "topping ";
		for (int i = 0; i < num; i++)
			cout << i + 1 << "." << t[i].getTopping_s() << " ";
		cout << endl;
	}
	static void count() { cout <<"total donut = "<< n << endl; }
	string f() {
		return "this is Donut ";
	}
	void operator()(int price, int kcal, int type) {
		Dessert::set(price, kcal);
		setType(type);
	}
};
int Donut::n;


class Waffle :virtual public Dessert {
	int shape;		//1.สี่เหลี่ยม 2.วงกลม 3.kitty 4.heart 5.bear face
public:
	Waffle() :Dessert(30, 250) { setShape(1); }
	Waffle(int price, int kcal, int shape) :Dessert(price, kcal) { setShape(shape); }
	~Waffle() {
		cout << "shape:" << shape << endl;
	}
	void setShape(int s) { shape = (s < 1 || s>5) ? 1 : s; }
	int getShape() { return shape; }
	string getShape_s() {
		switch (shape) {
		case 1:return"shape1";	break;	//สี่เหลี่ยม
		case 2:return"shape2";	break;	//วงกลม
		case 3:return"kitty shape";	break;
		case 4:return"heart shape";	break;
		case 5:return"bear face shape";	break;	
		}
	}
	void show() {
		cout << f() << getShape_s() << endl;
		Dessert::show();
	}
	string f() {
		return "this is Waffle ";
	}
	void operator++() {
		shape = (shape >= 1 || shape <= 5) ? shape++ : 1;
	}
};


class Wonut :public Donut, public Waffle {
	bool glutenFree;
public:
	Wonut() :Dessert(40, 290) {
		setType(0);
		setShape(2);
		setGluten(1);
		setNum(1);
		setT(0, 2, 3);
	}
	Wonut(int price, int kcal, int type, int nTopping, int shape, bool gluten) :Dessert(price, kcal) {
		setType(type);
		setShape(shape);
		setGluten(gluten);
		setNum(nTopping);
	}
	~Wonut() {
		cout << "glutenFree:" << glutenFree << endl;
	}
	void setGluten(bool g) { glutenFree = g; }
	bool getGluten() { return glutenFree; }
	string getGluten_s() {
		if (glutenFree)
			return "with gluten";
		else
			return "without gluten";
	}
	void show() {
		cout << f() << getType_s() << " " << getShape_s() << " " << getGluten_s() << endl;
		Dessert::show();
		showTopping();
	}
	string f() {
		return "this is Wonut ";
	}
	Wonut operator+(Wonut& w) {
		Wonut wonut;	//new wonut have new ID
		if (getShape() == w.getShape())
			wonut.setShape(getShape());
		else
			wonut.setShape(4);
		setType(0);
		wonut.setNum(getNTopping() + w.getNTopping());
		for (int i = 0; i < getNTopping(); i++)
			wonut.setT(i, getTopping(i).getTopping(), getTopping(i).getAmount());
		for (int i = 0; i < w.getNTopping(); i++)
			wonut.setT(getNTopping() + i, w.getTopping(i).getTopping(), w.getTopping(i).getAmount());
		if (getGluten() || w.getGluten())
			wonut.setGluten(1);
		else
			wonut.setGluten(0);
		return wonut;
	}
	int operator[](int index) {
		switch (index) {
		case 1:return getID();	break;
		case 2:return getPrice();	break;
		case 3:return getKcal();	break;
		case 4:return getType();	break;
		case 5:return getShape();	break;
		default:return getID();
		}
	}
	void set(int type, int shape) { setType(type); setShape(shape); }
	void set(bool gluten) { setGluten(gluten); }
	void operator!() {
		glutenFree = !glutenFree;
	}
};
ostream& operator<<(ostream& os, Wonut& w) {
	w.show();
	return os;
}


int main()
{
	Dessert** d;
	d = new Dessert * [4];
	d[0] = new Donut;
	d[1] = new Waffle;
	d[2] = new Wonut;
	d[3] = new Wonut;
	d[0]->set(10, 100);
	d[1]->set(15, 120);
	d[2]->set(20, 150);
	d[3]->set(25, 175);
	for (int i = 0; i < 4; i++)
		d[i]->show();
	cout << "-----" << endl;
	Donut b(27, 230, 2, 1);
	b.setT(0, 2, 2);
	Wonut c(45, 310, 0, 1, 5, 0);
	c.setT(0, 4, 3);
	c.setNum(3);
	for (int i = 0; i < 3; i++)
		c.setT(i, i + 1, i + 1);
	cout << "-----" << endl;
	//c+d[2]
	cout << "-----" << endl;
	Donut::count();
	cout << "-----" << endl;
	int totalPrice = 0;
	for (int i = 0; i < 4; i++)
		totalPrice += d[i]->getPrice();
	totalPrice += b.getPrice();
	totalPrice += c.getPrice();
	cout << "total price = " << totalPrice << endl;
	cout << "-----" << endl;
	int n = 0;
	/*
	for (int i = 0; i < 4; i++)
		delete d[i];
	delete []d;
	*/
}
