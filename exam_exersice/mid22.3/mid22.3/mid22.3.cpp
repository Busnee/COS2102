#include <iostream>
using namespace std;
class PencilSharpener {
	int color;
	int num;
	double price;
public:
	PencilSharpener() { set(1, 1, 20); }
	void set(int c, int n, double p) {
		color = (c < 1 || c>5) ? 0 : c;
		num = (n < 1) ? 1 : n;
		price = (p < 0) ? 0 : p;
	}
	PencilSharpener(int color, int num, double price) { set(color, num, price); }
	int getColor() { return color; }
	int getNum() { return num; }
	double getPrice() { return price; }
	void show() {
		cout << "color = ";	showColor();
		cout << " num = " << num;
		cout << " Price = " << price << endl;
	}
	void showColor() {
		switch (color) {
		case 1:cout << "blue";	break;
		case 2:cout << "white";	break;
		case 3:cout << "green";	break;
		case 4:cout << "pink";	break;
		case 5:cout << "black";	break;
		default:cout << "no color";
		}
	}
	~PencilSharpener() { show(); }
	void setColor(int c) { color = (c < 1 || c>5) ? 0 : c; }
};
class ElectricSharpener :public PencilSharpener {
	int type;
	static int n;
public:
	ElectricSharpener() :PencilSharpener(2, 1, 280) { set(2); n++; }
	void set(int type) { this->type = (type < 1 || type>3) ? 0 : type; }
	ElectricSharpener(int color, int num, double price, int type):PencilSharpener(color,num,price) {
		set(type);
		n++;
	}
	int getType() { return type; }
	void show() {
		PencilSharpener::show();
		cout << "type";	showType(); cout << endl;
	}
	void showType() {
		switch (type) {
		case 1:cout << "use plug";	break;
		case 2:cout << "use batery"; break;
		case 3:cout << "use USB";	break;
		default:cout << "no type";
		}
	}
	~ElectricSharpener() {
		showType();	cout << endl;
		n--;
	}
	static void count() { cout << n << endl; }
};
class ManualSharpener :public PencilSharpener {
	bool box;
public:
	ManualSharpener() :PencilSharpener(5, 1, 20) { setBox(false); }
	void setBox(bool b) { box = b; }
	ManualSharpener(int color, int num, double price, bool box) :PencilSharpener(color, num, price) {
		setBox(box);
	}
	bool getBox() { return box; }
	void show() {
		PencilSharpener::show();
		cout << "box = ";	showBox();	cout << endl;
	}
	void showBox() {
		if (box == true)
			cout << "have box";
		else
			cout << "haven't box";
	}
	~ManualSharpener() {
		showBox();	cout << endl;
	}

};
class PrismSharpener :public ManualSharpener {
	int hand;
public:
	PrismSharpener() :ManualSharpener(5, 1, 20, false) { setHand(1); }
	void setHand(int h) { hand = (h < 1 || h>2) ? 0 : h; }
	PrismSharpener(int color, int num, double price, bool box, int hand) :ManualSharpener(color, num, price, box) {
		setHand(hand);
	}
	int getHand() { return hand; }
	void show() {
		ManualSharpener::show();
		
	}
	void showHand() {
		switch (hand) {
		case 1:cout << "rigth hand";	break;
		case 2:cout << "left hand";		break;
		default:cout << "-";
		}
	}
	~PrismSharpener() {
		showHand();	cout << endl;
	}
	void switchBox() {
		if (getBox() == true)
			setBox(false);
		else
			setBox(true);
	}
};
class PlanetarySharpener :public ManualSharpener {
	int mount;
public:
	PlanetarySharpener() :ManualSharpener(1, 1, 180, true) { setMount(false); }
	void setMount(bool m) { mount = m; }
	PlanetarySharpener(int color, int num, double price, bool box, bool mount) :ManualSharpener(color, num, price, box) {
		setMount(mount);
	}
	bool getMount() { return mount; }
	void showMount() {
		if (mount == true)
			cout << "can";
		else
			cout << "can't";
	}
	void show() {
		ManualSharpener::show();
		showMount();	cout << endl;
	}
	~PlanetarySharpener() { showMount(); cout << endl; }
};
class Sharpener {
	PrismSharpener* p;
	int num;
public:
	Sharpener() { num = 0; p = 0; }
	Sharpener(int n) {
		num = n;
		p = new PrismSharpener[num];
	}
	~Sharpener() { delete []p; }
	void set(int i, int color, int num, double price, bool box, int hand) {
		p[i].PencilSharpener::set(color, num, price);
		p[i].setBox(box);
		p[i].setHand(hand);
	}
	PrismSharpener &get(int i) { return p[i]; }
	int getNum() { return num; }
	void setColor(int i,int color) {
		p[i].setColor(color);
	}
	void switchBox(int i) {
		p[i].switchBox();
	}
};
int ElectricSharpener::n;
int main()
{
	ElectricSharpener a(1, 1, 100, 3);
	PrismSharpener b(2, 2, 30, false, 1);
	PlanetarySharpener c(4, 1, 250, true, true);
	Sharpener d(2);
	d.set(1, 2, 1, 25, false, 1);
	d.set(2, 3, 1, 40, true, 2);
	double totalPrice = 0;
	for (int i = 0; i < d.getNum(); i++)
		totalPrice = totalPrice+d.get(i).getPrice();
	cout << "total price = " << totalPrice << endl;
	for (int i = 0; i < d.getNum(); i++)
		d.setColor(i, 4);
	for (int i = 0; i < d.getNum(); i++)
		d.switchBox(i);
	ElectricSharpener h;
	h.set(3);
	h.PencilSharpener::set(3, 2, 350);
	if (a.getNum() > h.getNum())
		cout << a.getPrice() << endl;
	else
		cout << h.getPrice() << endl;
	c.show();
	ElectricSharpener::count();
	cout << "--------------" << endl;
}