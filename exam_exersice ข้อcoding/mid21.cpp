#include <iostream>
using namespace std;
class Dessert {
	int price;
	static int num;
public:
	void setPrice(int p) { price = (p < 10) ? 10 : p; }
	Dessert() { setPrice(90); num++; }
	Dessert(int price) { setPrice(price); num++; }
	int getPrice() { return price; }
	void show() { cout << "Price = " << price << endl; }
	~Dessert() { cout << "Price:" << price << endl; }
	static void count() { cout << num << endl; }
};
class Cake :public Dessert {
	int flavor;
	int type;
	bool topping;
public:
	void set(int f, int t, bool topp) {
		flavor = f;
		type = t;
		topping = topp;
	}
	Cake() :Dessert(120) { set(1, 1, true); }
	Cake(int price, int flavor, int type, bool topping) :Dessert(price) { set(flavor, type, topping); }
	~Cake() {
		cout << "Flavor:";		showFlavor();
		cout << " Type:";		showType();
		cout << " Topping:";	showTopping();	cout << endl;
	}
	int getFlavor() { return flavor; }
	int getType() { return type; }
	bool getTopping() { return topping; }
	void show(){
		Dessert::show();
		cout << "Flavor = "; showFlavor(); cout << endl;
		cout << "Type = ";	showType();	cout << endl;
		cout << "Topping = ";	showTopping();	cout << endl;
	}
	void showFlavor() {
		switch (flavor) {
		case 1:cout << "vanilla";	break;
		case 2:cout << "coffee";	break;
		case 3:cout << "t";			break;	//ใบเตย
		default:cout << "none";
		}
	}
	void showType() {
		switch (type)
		{
		default:cout << "none";		break;
		case 1:cout << "butter";	break;
		case 2:cout << "foam";		break;
		case 3:cout << "mouse";
		}
	}
	void showTopping() {
		if (topping == true)
			cout << "have topping";
		else
			cout << "haven't topping";
	}
	Cake add(Cake a, Cake b) {
		setPrice((a.getPrice() + b.getPrice()) / 2);
		set(b.getFlavor(), a.getType(), true);
	}
	void setFlavor(int f) { flavor = f; }
	void setType(int t) { type = t; }
	void setTopping(bool topp) { topping = topp; }
};
class IceCream :public Dessert {
	int flavor;
	bool topping;
public:
	void setFlavor(int f) { flavor = f; }
	void setTopping(bool topp) { topping = topp; }
	void set(int f, bool topp) { setFlavor(f); setTopping(topp); }
	IceCream() :Dessert(30) { set(3, false); }
	IceCream(int price, int flavor, bool topping) :Dessert(price) { set(flavor, topping); }
	int getFlavor() { return flavor; }
	bool getTopping() { return topping; }
	void showFlavor() {
		switch (flavor) {
		case 1:cout << "vanilla";	break;
		case 2:cout << "chocolate";	break;
		case 3:cout << "coconut";	break;
		default:cout << "none";
		}
	}
	void showTopping() {
		if (topping == true)
			cout << "have topping";
		else
			cout << "haven't topping";
	}
	void show() {
		Dessert::show();
		cout << "Flavor = ";	showFlavor();	cout << endl;
		cout << "Topping = ";	showTopping();	cout << endl;
	}
	~IceCream() {
		cout << "Flavor:";		showFlavor();
		cout << " Topping:";	showTopping();	cout << endl;
	}
	void toppings() { topping = !topping; }
};
int Dessert::num;
int main() {
	Cake a(100, 1, 1, true);
	Cake b(180, 2, 3, false);
	IceCream c(20, 3, true);
	if (a.getFlavor() != c.getFlavor())
		c.setFlavor(a.getFlavor());
	a.setTopping(true);
	b.setTopping(true);
	c.setTopping(true);
	//a.show();
	//b.show();
	//c.show();
	//cout << "----" << endl;
	cout << "Price a+b = " << a.getPrice() + b.getPrice() << endl;
	cout << "Type a+b = " << a.getType() + b.getType() << endl;
	cout << "Total Price = " << a.getPrice() + b.getPrice() + c.getPrice() << endl;
	cout << "----" << endl;
}