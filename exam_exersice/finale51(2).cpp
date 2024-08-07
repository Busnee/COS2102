#include <iostream>
using namespace std;
class Dessert {
	int id;
	int price;
	int kcal;
	static int n;
	static int j;
	void setID() { j++; id = j; }
public:
	Dessert() {
		setID();
		set(10, 180);
	}
	Dessert(int price, int kcal) {
		setID();
		set(price, kcal);
	}
	virtual ~Dessert() {
		cout << "id:" << id << " price:" << price << " kcal:" << kcal << endl;
	}
	static void count() { cout << n << endl; }
	void setPrice(int p) { price = (p < 1) ? 1 : p; }
	void setKcal(int k) { kcal = (k < 1) ? 1 : k; }
	void set(int price, int kcal) {
		setPrice(price);
		setKcal(kcal);
	}
	int getID() { return id; }
	int getPrice() { return price; }
	int getKcal() { return kcal; }
	virtual void show(){
		cout << "ID" << id << " " << price << " bath " << kcal << " kcal" << endl;
	}
	virtual int f(int) = 0;
};
int Dessert::n;
int Dessert::j;


class Topping {
	int topping;		//1.icing 2.chocolate 3.green tea 4.candyfloss 5.marshmallow
	int amount;
public:
	Topping() { set(1, 1); }
	Topping(int topping, int amount) { set(topping, amount); }
	~Topping() { cout << "topping:" << topping << " amount:" << amount << endl; }
	void setTopping(int t) {
		topping = (t < 1 || t>5) ? 1 : t;
	}
	void setAmount(int a) {
		amount = (a < 1) ? 1 : a;
	}
	void set(int topping, int amount) {
		setTopping(topping);
		setAmount(amount);
	}
	int getTopping() { return topping; }
	int getAmount() { return amount; }
	string getTopping_s() {
		switch (topping) {
		case 1:"icing";			break;
		case 2:"chocolate";		break;
		case 3:"green tea";		break;
		case 4:"candyfloss";	break;
		case 5:"marshmallow";
		}
	}
	void show() {
		cout << getTopping_s() << " " << amount << " unit" << endl;
	}
};


class Donut :virtual public Dessert {
	int type;		//0.none 1.yeast donut 2.cake donut
	Topping* t;
	int num;
	void setArray(int n) {
		num = n;
		t = new Topping[num];
	}
public:
	Donut() :Dessert(20, 200) {
		setType(1);
		setArray(1);
		t[0].set(1, 2);
	}
	Donut(int price, int kcal,int type,int nTopping) :Dessert(price, kcal) {
		setType(type);
		setArray(nTopping);
	}
	~Donut() {
		cout << "type:" << type << " total topping:" << num << endl;
		delete[]t;
	}
	void setType(int t) { type = (t < 1 || t>2) ? 1 : t; }
	void setType() { type = 0; }
	int getType() { return type; }
	int getNTopping() { return num; }
	string getType_s() {
		switch (type) {
		case 1:return "yeast donut";	break;
		case 2:return "cake donut";		break;
		default:return "none";
		}
	}
	void show() {
		cout << "Type " << getType_s() << endl;
		cout << "-Topping-" << endl;
		for (int i = 0; i < num; i++)
			t[i].show();
		cout << "total topping = " << num << endl;
	}
};


class Waffle :virtual public Dessert {
	int shape;		//1.square 2.circle 3.kitty 4.heart 5.bear face
public:
	
};


class Wonut :public Donut, public Waffle {
	bool glutenFree;	//1.Gluten free 2.Gluten
public:

};


int main()
{

}