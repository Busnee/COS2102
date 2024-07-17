#include <iostream>
using namespace std;
class Vehicle {
	int year;
	int price;
	static int n;
public:
	Vehicle() { set(2021, 10000); n++; }
	Vehicle(int year, int price) { set(year, price); n++; }
	virtual ~Vehicle() { cout << "year:" << year << " price:" << price << endl; n--; }
	static void count() { cout << n << endl; }
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
};
int Vehicle::n;
ostream& operator<<(ostream& os, Vehicle& v) {
	v.print(os);
	return os;
}


class Boat :public Vehicle {
	int madefrom;
	int num;
public:
	Boat() :Vehicle(2019, 20000) { set(1, 10); }
	Boat(int year, int price, int madefrom, int nPeople) :Vehicle(year, price) { set(madefrom, nPeople); }
	~Boat() { cout << "madefrom:" << madefrom << " nPeople:" << num << endl; }
	void setMadefrom(int m) { madefrom = (m < 1 || m>3) ? 3 : m; }
	void setNPeople(int n) { num = (n < 1) ? 1 : n; }
	void set(int madefrom, int nPeople) {
		setMadefrom(madefrom);
		setNPeople(nPeople);
	}
	int getMadefrom() { return madefrom; }
	int getNPeople() { return num; }
	string getMadefrom_s(){
		switch (madefrom) {
		case 1:return"wood";	break;
		case 2:return"mental";	break;
		default:return"etc.";
		}
	}
	void print(ostream& os) {
		Vehicle::print(os);
		os << "Madefrom = " << getMadefrom_s() << endl;
		os << "num people = " << num << endl;
	}
	void operator()(int madefrom, int nPeople, int price, int year) {
		Vehicle::set(year, price);
		set(madefrom, nPeople);
	}
};


class Room {
	int type;
	int window;
public:
	Room() { set(1, 2); }
	Room(int type, int window) { set(type, window); }
	~Room() { cout << "type:" << type << " window:" << window << endl; }
	void setType(int t) { type = (t < 1 || t>3) ? 1 : t; }
	void setWindow(int w) { window = (w < 0) ? 0 : w; }
	void set(int type, int window) {
		setType(type);
		setWindow(window);
	}
	int getType() { return type; }
	int getWindow() { return window; }
	string getType_s() {
		switch(type) {
		case 1:return"Bedroom"; break;
		case 2:return"Bathroom"; break;
		case 3:return"Kitchen room";
		}
	}
	void print(ostream& os) {
		os << getType_s() << " " << window << " window" << endl;
	}
};
ostream& operator<<(ostream& os, Room& r) {
	r.print(os);
	return os;
}


class House {
	Room* room;
	int num;
	void setArray(int n) {
		num = n;
		room = new Room[num];
	}
public:
	House() { 
		setArray(2);
		setRoom(0, 1, 2);
		setRoom(1, 2, 1);
	}
	House(int nRoom) { setArray(nRoom); }
	~House() {
		cout << "total room:" << num << endl;
		delete[]room;
	}
	void setRoom(int index,int type, int window) {
		room[index].set(type, window);
	}
	int getNRoom() { return num; }
	Room getRoom(int index) { return room[index]; }
	void print(ostream& os){
		os << "Total room = " << num << endl;
		for (int i = 0; i < num; i++)
			os << i + 1 << "." << room[i];
	}
	void addRoom(int type, int window) {
		Room* temp = new Room[num];
		for (int i = 0; i < num; i++)
			temp[i] = room[i];
		num++;
		resetArray(num);
		for (int i = 0; i < num-1; i++)
			room[i] = temp[i];
		setRoom(num - 1, type, window);
	}
	void resetArray(int n) {
		if (room != 0)
			delete[]room;
		setArray(n);
	}
};
ostream& operator<<(ostream& os, House& h) {
	h.print(os);
	return os;
}


class Houseboat :public Boat, public House {
	bool ghat;
public:
	Houseboat() :Boat(2001, 50000, 1, 15), House(2) {
		setRoom(0, 1, 2);
		setRoom(1, 2, 1);
		set(0);
	}
	Houseboat(int year, int price, int madefrom, int nPeople,int nRoom,bool ghat):
		Boat(year,price,madefrom,nPeople),House(nRoom) {
		set(ghat);
	}
	~Houseboat() { cout << "ghat:" << ghat << endl; }
	void set(bool g) { ghat = g; }
	void set(int year, int price, int madefrom, int nPeople, int nRoom, bool ghat) {
		Vehicle::set(year, price);
		Boat::set(madefrom, nPeople);
		resetArray(nRoom);
		set(ghat);
	}
	bool getGhat() { return ghat; }
	string getGhat_s() { return (ghat) ? "have" : "haven't"; }
	void print(ostream& os) {
		Boat::print(os);
		House::print(os);
		os << getGhat_s() << " Ghat" << endl;
	}
	int operator[](int index) {
		switch (index) {
		case 1:return getYear();	break;
		case 2:return getPrice();	break;
		case 3:return getMadefrom();	break;
		case 4:return getNPeople();	break;
		default:return -1;
		}
	}
	Houseboat& operator=(Houseboat& h){
		set(h.getYear(), h.getPrice(), h.getMadefrom(), h.getNPeople(), h.getNRoom(), h.getGhat());
		for (int i = 0; i < getNRoom(); i++)
			setRoom(i, h.getRoom(i).getType(), h.getRoom(i).getWindow());
		return *this;
	}
};
ostream& operator<<(ostream& os, Houseboat& h) {
	h.print(os);
	return os;
}

int main()
{
	Boat a(1998, 20000, 1, 10);
	House b(3);
	for (int i = 0; i < 3; i++)
		b.setRoom(i, i, i + 1);
	Houseboat c(2000, 30000, 2, 12, 2, 1), e(2002, 25000, 1, 9, 2, 1);
	for (int i = 0; i < 2; i++) {
		c.setRoom(i, i, i + 1);
		e.setRoom(i, i, i + 2);
	}
	cout << "---" << endl;
	if (a.getYear() < 2021)
		cout << a << endl;
	if (c.getYear() < 2021)
		cout << c << endl;
	if (e.getYear() < 2021)
		cout << e << endl;
	cout << "---" << endl;
	c.addRoom(1, 3);
	c.addRoom(2, 2);
	//cout << c << endl;
	cout << "---" << endl;
	cout << e << endl;
	cout << "---" << endl;
	int bedroom = 0;
	for (int i = 0; i < b.getNRoom(); i++) {
		if (b.getRoom(i).getType() == 1)
			bedroom++;
	}
	for (int i = 0; i < c.getNRoom(); i++) {
		if (c.getRoom(i).getType() == 1)
			bedroom++;
	}
	for (int i = 0; i < e.getNRoom(); i++) {
		if (e.getRoom(i).getType() == 1)
			bedroom++;
	}
	cout << "total bedroom = " << bedroom << endl;
	cout << "---" << endl;
	Vehicle::count();
	cout << "---" << endl;
	int mental = 0;
	if (a.getMadefrom() == 2)
		mental++;
	if (c.getMadefrom() == 2)
		mental++;
	if (e.getMadefrom() == 2)
		mental++;
	cout << "total mental boat = " << mental << endl;
	cout << "---" << endl;

}