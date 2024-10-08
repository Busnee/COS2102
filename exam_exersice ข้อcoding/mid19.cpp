#include <iostream>
using namespace std;
class Size {
	double width;
	double height;
public:
	void setW(double w) { width = w; }
	void setH(double h) { height = h; }
	void set(double width, double height) {
		setW(width);
		setH(height);
	}
	Size() { set(1, 1); }
	Size(double width, double height) {
		set(width,height);
	}
	~Size() { cout << "width:" << width << " height:" << height << endl; }
	double getW() { return width; }
	double getH() { return height; }
	void show() {
		cout << "width = " << width << endl;
		cout << "height = " << height << endl;
	}
};
class Room {
	Size size;
	int window;
	int door;
	static int num;
public:
	void setWindow(int w) { window = w; }
	void setDoor(int d) { door = d; }
	void set(double width, double height, int window, int door) {
		size.set(width, height);
		setWindow(window);
		setDoor(door);
	}
	Room() { set(2, 2, 2, 1); num++; }
	Room(double width, double height, int window, int door) {
		set(width, height, window, door);
		num++;
	}
	~Room() {
		cout << "size:" << size.getW() << "x" << size.getH();
		cout << " window:" << window << " door:" << door << endl;
		num--;
	}
	Size& getSize() { return size; }
	int getWindow() { return window; }
	int getDoor() { return door; }
	void show() {
		cout << "size" << endl;
		size.show();
		cout << "window = " << window << endl;
		cout << "door = " << door << endl;
	}
	static void count() { cout << num << endl; }
};
class Restroom :public Room {
	int type;
public:
	void set(int t) { type = t; }
	Restroom() { set(1); }
	Restroom(double width, double height, int window, int door, int type) :Room(width,height,window,door) {
		set(type);
	}
	~Restroom() { cout << "type:" << type << endl; }
	int getType() { return type; }
	string getType2() {
		switch (type) {
		case 1:return "type 1";	break;	//ชักโครก
		case 2:return "type 2";	break;	//นั่งยอง
		case 3:return "type 3";	break;	//นี่งราบ
		default:return "other type";
		}
	}
	void show() {
		Room::show();
		cout << getType2() << endl;
	}
	void switchToilet() {
		type = (type > 2) ? 1 : ++type;
	}
};
class Bedroom :public Room {
	int type;
public:
	void set(int t) { type = t; }
	Bedroom() { set(1); }
	Bedroom(double width, double height, int window, int door, int type) :Room(width, height, window, door) {
		set(type);
	}
	~Bedroom() { cout << "type:" << type << endl; }
	int getType() { return type; }
	string getType2() {
		switch (type) {
		case 1:return "sigle bed";	break;
		case 2:return "twin bed";	break;
		case 3:return "queen size bed";	break;
		case 4:return "king size bed";	break;
		default:return "other type";
		}
	}
	void show() {
		Room::show();
		cout << getType2() << endl;
	}
};
class House {
	int b, r;
	Bedroom* bedroom;
	Restroom* restroom;
	void setBedroom(int x) {
		if (bedroom != NULL)
			delete bedroom;
		b = x;
		bedroom = new Bedroom[b];
	}
	void setRestroom(int y) {
		if (restroom != NULL)
			delete restroom;
		r = y;
		restroom = new Restroom[r];
	}
public:
	void set(int b, int r) {
		setBedroom(b);
		setRestroom(r);
	}
	House() {
		b = r = 0;
		bedroom = 0;
		restroom = 0;
	}
	House(int b, int r) { set(b, r); }
	int getB() { return b; }
	int getR() { return r; }
	~House() {
		cout << "b:" << b << " r:" << r << endl;
		delete[]bedroom;
		delete[]restroom;
	}
	void show() {
		cout << "b = " << b << endl;
		for (int i = 0; i < b; i++) {
			cout << i + 1 << ".";
			bedroom[i].show();
		}
		cout << "r = " << r << endl;
		for (int i = 0; i < r; i++) {
			cout << i + 1 << ".";
			restroom[i].show();
		}
	}
	Bedroom& getBedroom(int i) { return bedroom[i]; }
	Restroom& getRestroom(int i) { return restroom[i]; }
};
int Room::num;
int main() {
	Restroom a(4, 4, 2, 1, 1);
	Bedroom b(10, 10, 4, 1, 2);
	House c(3, 2);
	for (int i = 0; i < 3; i++) {
		c.getBedroom(i).set(i + 1);
		c.getBedroom(i).Room::set(10 - i, 10 - 2 * i, 4 - i, 1);
	}
	c.getRestroom(0).set(2);
	c.getRestroom(0).Room::set(2, 2, 1, 1);
	c.getRestroom(1).set(1);
	c.getRestroom(1).Room::set(3, 4, 0, 1);
	int n = 0;
	if (a.getType() == 1)
		n++;
	for (int i = 0; i < c.getR(); i++) {
		if (c.getRestroom(i).getType() == 1)
			n++;
	}
	cout << "n = " << n << endl;
	if (c.getBedroom(1).getType() != 2)
		c.getBedroom(1).set(2);
	else
		cout << "twin bed" << endl;
	double areaB, areaC;
	areaB = b.getSize().getW() * b.getSize().getH();
	areaC = c.getBedroom(2).getSize().getW() * c.getBedroom(2).getSize().getH();
	if (areaB > areaC)
		cout << "area B = " << areaB << endl;
	else
		cout << "area C = " << areaC << endl;
	cout << "--------" << endl;
}