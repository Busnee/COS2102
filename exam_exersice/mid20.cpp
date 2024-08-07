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
	Size(double width, double height) { set(width, height); }
	double getW() { return width; }
	double getH() { return height; }
	~Size() { cout << "width:" << width << " height:" << height << endl; }
};
class Bed {
	double size;
	int type;
public:
	void setSize(double s) { size = s; }
	void setType(int t) { type = t; }
	void set(double size, int type) { 
		setSize(size); setType(type); 
	}
	Bed() { set(1, 1); }
	Bed(double size, int type) { set(size, type); }
	double getSize() { return size; }
	string getType2() {
		switch (type) {
		case 1:return "cloth";	break;
		case 2:return "genuine leather";	break;
		case 3:return "syntnetic leather";	break;
		default:return "other";	break;
		}
	}
	int getType() { return type; }
	~Bed() {
		cout << "type:" << type;
		cout << " size:" << size << endl;
	}
};
class Cupboard {
	int type;
	int door;
public:
	void setType(int t) { type = t; }
	void setDoor(int d) { door = d; }
	void set(int type, int door) {
		setType(type);
		setDoor(door);
	}
	Cupboard() { set(1, 2); }
	Cupboard(int type, int door) { set(type, door); }
	int getType() { return type; }
	int getDoor() { return door; }
	string getType2() {
		switch (type) {
		case 1:return "Clothes cupboard";	break;
		case 2:return "Build-in clothes cupboard";	break;
		case 3:return "Blanket cupboard";	break;
		default:return "other";
		}
	}
	~Cupboard() { cout << "type:" << type << " door:" << door << endl; }
};
class Room {
	Size size;
	int c;
	Cupboard* cupboard;
	void setRoom(int i, double width, double height) {
		c = i;
		size.set(width, height);
	}
public:
	Room() {
		setRoom(2, 2, 2);
		cupboard = new Cupboard[c];
	}
	Room(int i, double width, double height) {
		setRoom(i, width, height);
		cupboard = new Cupboard[c];
	}
	Size& getSize() { return size; }
	int getC() { return c; }
	Cupboard& getCupboard(int i) { return cupboard[i]; }
	int& getCupboardDoor(int i){}
	void show() {
		cout << "size = " << size.getW() << "x" << size.getH() << endl;
		cout << "c = " << c << endl;
		for (int i = 0; i < c; i++)
			cout << cupboard[i].getType2() << " " << cupboard[i].getDoor() << " door" << endl;
	}
};
class Bedroom :public Room {
	int b;
	Bed* bed;
	static int num;
	void set(int i) { b = i; }
public:
	Bedroom() :Room(1, 2, 2) {
		set(1);
		bed = new Bed[b];
		num++;
	}
	Bedroom(int c, int b, double width, double height) :Room(c, width, height) {
		set(b);
		bed = new Bed[b];
		num++;
	}
	~Bedroom() {
		cout << "b:" << b << endl;
		delete[]bed;
		num--;
	}
	int getB() { return b; }
	Bed& getBed(int i) { return bed[i]; }
	void show() {
		Room::show();
		cout << "b = " << b << endl;
		for (int i = 0; i < b; i++)
			cout << bed[i].getType2() << " " << bed[i].getSize() << " foot" << endl;
	}
	static void count() { cout << num << endl; }
};
int Bedroom::num;
int main() {
	//cout << 1 << endl;
	Bed a(5, 2);
	//cout << 2 << endl;
	Cupboard b(1, 2);
	//cout << 3 << endl;
	Bedroom myBedRoom(2, 2, 5, 7);
	//cout << 4 << endl;
	for(int i=0;i<2;i++)
		myBedRoom.getBed(i).set(3.5, 1);
	//cout << 5 << endl;
	myBedRoom.getCupboard(0).set(1, 3);
	//cout << 6 << endl;
	myBedRoom.getCupboard(1).set( 3, 1);
	//cout << 7 << endl;
	myBedRoom.show();
	//cout << 8 << endl;
	int n = 0;
	//cout << 9 << endl;
	if (b.getDoor() == 2)
		n++;
	//cout << 10 << endl;
	for (int i = 0; i < myBedRoom.getC(); i++) {
		if (myBedRoom.getCupboard(i).getDoor() == 2)
			n++;
	}
	//cout << 11 << endl;
	//cout << "n="<<n << endl;
	//cout << 12 << endl;
	cout << "------------" << endl;
}