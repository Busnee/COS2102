#include <iostream>
using namespace std;
class Vehicle {
	int year;
	int price;
	static int n;
public:
	Vehicle() { set(2021, 10000); n++; }
	Vehicle(int year, int price) { set(year, price); n++; }
	virtual ~Vehicle() {
		cout << "year:" << year << " price:" << price << endl;
		n--;
	}
	void setYear(int y) { year = y; }
	void setPrice(int p) { price = (p < 0) ? 0 : p; }
	void set(int year, int price) {
		setYear(year);
		setPrice(price);
	}
	int getYear() { return year; }
	int getPrice() { return price; }
	virtual void print(ostream& os) {
		os << "Year = " << year << endl;
		os << "Price = " << price << endl;
	}
	static void count() { cout << "total vehicle = " << n << endl; }
};
ostream& operator<<(ostream& os, Vehicle& v) {
	v.print(os);
	return os;
}

class Boat : public Vehicle{
	int madefrom;	//1:ไม้  2:โลหะ   3:อื่นๆ
	int num;
public:
	Boat() :Vehicle(2019,20000) { set(1, 10); }
	Boat(int year, int price, int madefrom, int nPeople) :Vehicle(year, price) {
		set(madefrom, nPeople);
	}
	~Boat(){
		cout << "madefrom:" << madefrom << " num:" << num << endl;
	}
	void setMadefrom(int from) {
		madefrom = (from < 1 || from>3) ? 3 : from;
	}
	void setNum(int nPeople) { num = (nPeople < 1) ? 1 : nPeople; }
	void set(int madefrom, int nPeople) {
		setMadefrom(madefrom);
		setNum(nPeople);
	}
	int getMadefrom() { return madefrom; }
	int getNum() { return num; }
	void print(ostream& os) {
		Vehicle::print(os);
		os << "Madefrom = ";
		switch (madefrom) {
		case 1:cout << "wood" << endl;	break;
		case 2:cout << "mental" << endl;	break;
		case 3:cout << "other" << endl;
		}
		os << "Num = " << num << endl;
	}
	Boat& operator()(int year, int price, int madefrom, int num) {
		Vehicle::set(year, price);
		set(madefrom, num);
		return *this;
	}
};

class Room {
	int type;		//1:ห้องนอน  2:ห้องน้ำ  3:ห้องครัว
	int window;
public:
	Room() { set(1, 2); }
	Room(int type, int window) { set(type, window); }
	~Room() {
		cout << "type:" << type << " window:" << window << endl;
	}
	void setType(int t) { type = (t < 1 || t>3) ? 1 : t; }
	void setWindow(int w) { window = (w < 0) ? 0 : w; }
	void set(int type, int window) {
		setType(type);
		setWindow(window);
	}
	int getType() { return type; }
	int getWindow() { return window; }
	void print(ostream& os) {
		os << "Type = " << type << endl;
		os << "Window = " << window << endl;
	}
};
ostream& operator<<(ostream& os, Room& r) {
	r.print(os);
	return os;
}

class House {
	Room* room;
	int num;
public:
	House() { 
		set(2);
		setRoom(0, 1, 2);
		setRoom(1, 2, 1);
	}
	House(int nRoom) { set(nRoom); }
	virtual ~House() {
		cout << "num:" << num << endl;
		if(room!=0)
			delete[]room;
	}
	void set(int nRoom) {
		if (room != 0)
			delete[]room;
		num = nRoom;
		room = new Room[num];
	}
	void setRoom(int i, int type, int window) {
		room[i].set(type, window);
	}
	int getNum() { return num; }
	Room& getRoom(int i) { return room[i]; }
	virtual void print(ostream& os) {
		os << "Num = " << num << endl;
		for (int i = 0; i < num; i++)
			room[i].print(os);
	}
	void addRoom(int n) {
		if (n+num > num) {
			int k = num;
			num += n;
			Room* temp = new Room[k];
			for (int i = 0; i < k; i++)
				temp[i] = room[i];
			delete[]room;
			room = new Room[num];
			for (int i=0; i < k; i++)
				room[i] = temp[i];
			delete[] temp;
		}
	}
};
ostream& operator<<(ostream& os, House& h) {
	h.print(os);
	return os;
}

class Houseboat :public House, public Boat {
	bool ghat;
public:
	Houseboat() :Boat(2001,50000,1,15) ,House(2) {
		setRoom(0, 1, 2);
		setRoom(1, 2, 1);
		set(0);
	}
	Houseboat(int year, int price, int madefrom, int nPeople, int nRoom,bool ghat) :Boat(year, price, madefrom, nPeople),
		House(nRoom) {
		set(ghat);
	}
	~Houseboat() {
		cout << "Ghat:" << ghat << endl;	//0:ไม่มีบรรได  1:มีบรรได
	}
	void set(bool g) { ghat = g; }
	bool getGhat() { return ghat; }
	void print(ostream& os) {
		Boat::print(os);
		House::print(os);
		if (ghat)
			os << "have";
		else
			os << "haven't";
		os << " Ghat" << endl;
	}
	int operator[](int index) {
		switch (index) {
		case 1:return getYear(); break;
		case 2:return getPrice(); break;
		case 3:return getMadefrom(); break;
		case 4:return Boat::getNum();
		}
	}
	void set(int year, int price, int madefrom, int nPeople, int nRoom, bool ghat) {
		Vehicle::set(year, price);
		Boat::set(madefrom, nPeople);
		House::set(nRoom);
		set(ghat);
	}
	Houseboat& operator=(Houseboat& h) {
		Vehicle::set(h.getYear(), h.getPrice());
		Boat::set(h.getMadefrom(), h.Boat::getNum());
		House::set(h.House::getNum());
		for (int i = 0; i < House::getNum(); i++)
			getRoom(i) = h.getRoom(i);
		set(h.ghat);
		return *this;
	}
};
ostream& operator<<(ostream& os, Houseboat& hb) {
	hb.print(os);
	return os;
}


int Vehicle::n;
int main()
{
	Boat a(2000, 8000, 3, 8);
	House b(3);
	b.setRoom(0, 1, 2);
	b.setRoom(1, 2, 1);
	b.setRoom(2, 3, 3);
	Houseboat c(2002, 15000, 1, 8, 2, 1), e(1998, 25000, 2, 10, 2, 1);
	c.setRoom(0, 1, 2);
	c.setRoom(1, 3, 1);
	e.setRoom(0, 2, 1);
	e.setRoom(1, 1, 4);
	if (a.getYear() < 2021)
		cout << a;
	cout << "--1--" << endl;
	if (c.getYear() < 2021)
		cout << c;
	cout << "--2--" << endl;
	if (e.getYear() < 2021)
		cout << e;
	cout << "--3--" << endl;
	e.addRoom(2);
	e.setRoom(2, 1, 3);
	e.setRoom(3, 2, 2);
	cout << e;
	cout << "--4--" << endl;
	int nBedroom = 0;
	for (int i = 0; i < b.getNum(); i++)
		if (b.getRoom(i).getType() == 1)
			nBedroom++;
	for (int i = 0; i < c.House::getNum(); i++)
		if (c.getRoom(i).getType() == 1)
			nBedroom++;
	for (int i = 0; i < e.House::getNum(); i++)
		if (e.getRoom(i).getType() == 1)
			nBedroom++;
	cout << "total Bedroom = " << nBedroom << endl;
	Vehicle::count();
	int x = 0;
	if (a.getMadefrom() == 2)
		x++;
	if (c.getMadefrom() == 2)
		x++;
	if (e.getMadefrom() == 2)
		x++;
	cout << "total mental Boat = " << x << endl;
}