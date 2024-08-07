#include <iostream>
using namespace std;
class  Stationery {
	int year;
	double price;
public:
	void setYear(int y) { year = y; }
	void setPrice(double p) { price = p; }
	void set(int year, double price) {
		setYear(year);
		setPrice(price);
	}
	Stationery() { set(2518, 5); }
	Stationery(int year, double price) { set(year, price); }
	~Stationery() {
		cout << "year:" << year << " price:" << price << endl;
	}
	int getYear() { return year; }
	double getPrice() { return price; }
	void show() {
		cout << "year=" << year << endl;
		cout << "price=" << price << endl;
	}
};
class Pencil :public Stationery {
	int type;
	int color;
	static int num;
public:
	void setType(int t) { type = t; }
	void setColor(int c) { 
		color = (type == 1 || type == 4) ? 1 : c; 
	}
	void set(int type, int color) { 
		setType(type);
		setColor(color);
	}
	Pencil() { set(1, 1); num++; }
	Pencil(int year, double price, int type, int color) :Stationery(year,price) {
		set(type, color);
	}
	~Pencil() {
		cout << "type:" << type << " color:" << color << endl;
	}
	int getType() { return type; }
	int getColor() { return color; }
	string getType2() {
		switch (type) {
		case 1:return "Black pencil";	break;
		case 2:return "Oil pencil";		break;
		case 3:return "Color pencil";	break;
		case 4:return "Press pencil";	break;
		default:return "none type of pencil";
		}
	}
	string getColor2() {
		switch (color) {
		case 1:return "black";	break;
		case 2:return "red";	break;
		case 3:return "blue";	break;
		case 4:return "green";	break;
		case 5:return "yellow";	break;
		case 6:return "purple";	break;
		default:return "none color";
		}
	}
	void show() {
		Stationery::show();
		cout << "pencil=" << getType2() << endl;
		cout << "color=" << getColor2() << endl;
	}
	static void count() { cout << num << endl; }
};
class Pen :public Stationery {
	int inkColor;
	double nibSize;
	bool waterproof;
public:
	void setInk(int c) { inkColor = c; }
	void setNib(double s) { nibSize = (s < 0.25) ? 0.25 : s; }
	void setWaterproof(bool w) { waterproof = w; }
	void set(int color, double size, bool waterproof) {
		setInk(color);
		setNib(size);
		setWaterproof(waterproof);
	}
	Pen() { set(3, 0.5, true); }
	Pen(int year, double price, int color, double size, bool waterproof) :Stationery(year, price) {
		set(color, size, waterproof);
	}
	~Pen() {
		cout << "inkColor:" << inkColor;
		cout << " nibSize:" << nibSize;
		cout << " waterproof:" << waterproof << endl;	//1=true,0=false
	}
	int getInkColor() { return inkColor; }
	double getNibSize() { return nibSize; }
	bool getWaterproof() { return waterproof; }
	string getColor(){
		switch (inkColor) {
		case 1:return "black";	break;
		case 2:return "red";	break;
		case 3:return "blue";	break;
		case 4:return "green";	break;
		default:return "none color";
		}
	}
	string getWaterproof2() {
		if (waterproof == true)
			cout << "can";
		else
			cout << "can't";
	}
	void show() {
		Stationery::show();
		cout << "ink color=" << inkColor << endl;
		cout << "nib size=" << nibSize << endl;
		cout << getWaterproof2() << endl;
	}
	void switchWaterproof() { waterproof = !waterproof; }
};
class BallpointPen :public Pen {
	int length;
	int type;
public:
	void setLength(int l) { length = l; }
	void setType(int t) { type = t; }
	void set(int length, int type) {
		setLength(length);
		setType(type);
	}
	BallpointPen() { set(1500,1); }
	BallpointPen(int year, double price, int color, double size, bool waterproof,int length,int type) :
		Pen(year, price, color, size, waterproof) {
		set(length, type);
	}
	~BallpointPen() {
		cout << "length:" << length;
		cout << "type:" << type << endl;
	}
	int getLength() { return length; }
	int getType() { return type; }
	string getType2() {
		switch (type){
		case 1:return "type 1"; break;	//แบบกด
		case 2:return "type 2"; break;	//แบบปลอก
		default:return "none type";
		}
	}
	void show() {
		Pen::show();
		cout << "length=" << length << endl;
		cout << "type=" << type << endl;
	}
};
class PencilBox {
	Pencil* p;
	int num;
public:
	PencilBox() { num = 0; p = 0; }
	PencilBox(int n) {
		num = n;
		p = new Pencil[num];
	}
	~PencilBox() {
		delete []p;
	}
	Pencil& getP(int i) { return p[i]; }
	int getNum() { return num; }
	void setP(int i, int year,double price,int type, int color) {
		p[i].Stationery::set(year, price);
		p[i].set(type, color);
	}
};
int Pencil::num;
int main() {
	Pencil a(2545, 20, 4, 1);
	BallpointPen b(2550, 15, 3, 0.5, false, 1500, 2);
	PencilBox d(4);
	for (int i = 0; i < 4; i++) {
		d.setP(i, 2554, 100 + i * 20, 3, i + 2);
	}
	cout << "a color = " << a.getColor2() << endl;
	cout << "b color = " << b.getColor() << endl;
	cout << "d color = ";
	for (int i = 0; i < 4; i++)
		cout << d.getP(i).getColor2() << " ";
	cout << endl;
	for (int i = 0; i < 4; i++)
		d.getP(i).setColor(1);
	BallpointPen h;
	h.set(2000, 2);
	h.Pen::set(2, 0.16, false);
	h.Stationery::set(2018, 20);
	if (b.getNibSize() < h.getNibSize())
		cout << "b nib size = " << b.getNibSize() << endl;
	else
		cout << "h nib size = " << h.getNibSize() << endl;
	double total = 0;
	total += a.getPrice();
	total += b.getPrice();
	for (int i = 0; i < 4; i++)
		total += d.getP(i).getPrice();
	total += h.getPrice();
	cout << "total price = " << total << endl;
	b.switchWaterproof();
	if (b.getWaterproof() == true)
		cout << "beautiful" << endl;
	else
		cout << "nice" << endl;
	cout << "-----------" << endl;
}