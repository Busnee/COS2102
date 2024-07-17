#include <iostream>
using namespace std;
class Furniture {
	double price;
public:
	void setPrice(double p) {
		price = (p < 0) ? 0 : p;
		if (p < 0)
			price = 0;
		else
			price = p;
	}
	Furniture() {
		setPrice(99);
	}
	double getPrice() { return price; }
	~Furniture() {
		cout << "price = " << price << endl;
	}
	Furniture(double price) {
		setPrice(price);
	}
};
class Table :public Furniture {
	int type;
public:
	void setType(int type) {
		this->type = type;
	}
	void showType() {
		switch (type) {
		case 1:cout << "com"; break;
		case 2:cout << "tv" ;	break;
		case 3:cout << "kak";	break;
		default:cout << "other";
		}
	}
	Table() :Furniture(9999) { setType(3); }
	int getType() { return type; }
	~Table() { showType(); cout << endl; }
	void set(int type, double price) {
		setType(type);
		setPrice(price);
	}
};
class Chair :public Furniture {
	int type;
public:
	void setType(int type) {
		this->type = type;
	}
	void showType() {
		switch (type) {
		case 1:cout << "com";		break;
		case 2:cout << "nuam";		break;
		case 3:cout << "child";		break;
		default:cout << "other";
		}
	}
	Chair() :Furniture(999) { setType(2); }
	int getType() { return type; }
	~Chair() { showType(); cout << endl; }
	void set(int type, double price) {
		setType(type);
		setPrice(price);
	}
};
class Room {
	double width, height;
public:
	void setRoom(double w, double h) {
		width = (w < 1) ? 1 : w;
		height = (h < 1) ? 1 : h;
	}
	Room() { setRoom(5, 5); }
	double getW() { return width; }
	double getH() { return height; }
	~Room() {
		cout << "Width = " << width;
		cout << " Height =" << height << endl;
	}
	Room(double w, double h) {
		setRoom(w, h);
	}
};
class LivingRoom :public Room {
	int t, c;
	Table* table;
	Chair* chair;
	static int num;
	void setTable(int nT){
		t=nT;
		if(t==0)
			table=0;
		else
			table=new Table[t];
	}
	void setChair(int nC){
		c=nC;
		if(c==0)
			chair=0;
		else
			chair=new Chair[c];
	}
public:
	void set(int t, int c) {
		setTable(t);
		setChair(c);
	}
	/*void set(int nT, int nC) {
		t = nT;
		c = nC;
		table = new Table[t];
		chair = new Chair[c];
	}*/
	LivingRoom() {
		set(1, 1);
		table[0].setType(3);
		chair[0].setType(2);
		num++;
	}
	LivingRoom(double w, double h, int nT, int nC) :Room(w, h) {
		set(nT, nC);
		num++;
	}
	int getNTable() { return t; }
	int getNChair() { return c; }
	int getTableType(int i) { return table[i].getType(); }
	int getChairType(int i) { return table[i].getType(); }
	double getTablePrice(int i) { return table[i].getPrice(); }
	double getChaerPrice(int i) { return table[i].getPrice(); }
	~LivingRoom() {
		delete []table;
		delete []chair;
		cout << "Table = " << t;
		cout << " Chair = " << c << endl;
		num--;
	}
	void show() {
		cout << "Living Room size" << endl;
		cout << "Width = " << getW() << "  Height : " << getH() << endl;
		cout << "Table" << endl;
		for (int i = 0; i < t; i++) {
			table[i].showType();
			cout << "/t" << table[i].getPrice() << " bath" << endl;
		}
		cout << "Total Table = " << t << endl;
		cout << "Chair" << endl;
		for (int i = 0; i < c; i++) {
			chair[i].showType();
			cout << "/t" << chair[i].getPrice() << " bath" << endl;
		}
		cout << "Total Chair : " << c << endl;
	}
	void reset(int nT, int nC) {
		delete []table;
		delete []chair;
		set(nT, nC);
	}
	void setT(int i, int type, double price) {
		table[i].setType(type);
		table[i].setPrice(price);
	}
	void setC(int i, int type, double price) {
		chair[i].setType(type);
		chair[i].setPrice(price);
	}
	static void count();
	double getPrice();
};
int LivingRoom::num;
int main()
{
	LivingRoom a(5, 8, 3, 3), b(6, 9, 2, 4);
	a.setT(0, 2, 1200);
	a.setT(1, 3, 3000);
	a.setT(2, 1, 4000);
	a.setC(0, 2, 2500);
	a.setC(1, 2, 2500);
	a.setC(2, 1, 1000);
	b.setT(0, 2, 3000);
	b.setT(1, 3, 5000);
	b.setC(0, 2, 1500);
	b.setC(1, 2, 2000);
	b.setC(2, 2, 2800);
	b.setC(3, 3, 2000);
	if (a.getPrice() > b.getPrice())
		cout << "total A Price = " << a.getPrice() << endl;
	else
		cout << "total B Price = " << b.getPrice() << endl;
	int n = 0;									//
	for (int i = 0; i < b.getNChair(); i++) {	//ได้ผลลัพท์ไม่ตรงตามต้องการ
		if (b.getChairType(i) == 2)				//
			n++;								//
	}											//
	cout << "n = " << n << endl;				//
	double areaA, areaB;
	areaA = a.getW() * a.getH();
	areaB = b.getW() * b.getH();
	if (areaA > areaB) {
		cout << "A area = " << areaA << endl;
		cout << "Table type = ";
		for (int i = 0; i < a.getNTable(); i++)
			cout << a.getTableType(i) << " ";
		cout << endl;
	}
	else {
		cout << "B area = " << areaB << endl;
		cout << "Table type = ";
		for (int i = 0; i < b.getNTable(); i++) 
			cout << b.getTableType(i) << " ";
		cout << endl;
	}
}
double LivingRoom::getPrice() {
	double total = 0;
	for (int i = 0; i < t; i++)
		total += table[i].getPrice();
	for (int i = 0; i < c; i++)
		total += chair[i].getPrice();
	return total;
}
void LivingRoom::count() {
	cout << num << endl;
}