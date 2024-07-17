#include <iostream>
using namespace std;

class Vehicle {
	int year;
	int price;
	static int n;
public:
	static void count() { cout << n << endl; }
	Vehicle() {
		set(2021, 10000);
		n++;
	}
	Vehicle(int year, int price) {
		set(year, price);
		n++;
	}
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
		os << "Year = " << year;
		os << " Price = " << price << " bath" << endl;
	}
};
ostream& operator<<(ostream& os, Vehicle& v) {
	v.print(os);
	return os;
}
int Vehicle::n;
class Boat :public Vehicle {
	int madefrom;	//1.wood,2.mental,3.etc.
	int num;		//n people
public:
	Boat() :Vehicle(2019, 20000) {
		set(1, 10);
	}
	Boat(int year, int price, int madefrom, int nPeople) :Vehicle(year, price) {
		set(madefrom, nPeople);
	}
	~Boat() {
		cout << "made from:" << getMadefrom_s() << "nPeople:" << num << endl;
	}
	void setMadefrom(int mf) { madefrom = (mf < 1 || mf>3) ? 3 : mf; }
	void setnumPeople(int n) { num = (n < 1) ? 1 : n; }
	void set(int madefrom, int nPeople) {
		setMadefrom(madefrom);
		setnumPeople(nPeople);
	}
	int getMadefrom() { return madefrom; }
	int getnumPeople() { return num; }
	string getMadefrom_s() {
		switch (madefrom) {
		case 1:return "wood";	break;
		case 2:return "mental";	break;
		case 3:return "etc.";
		}
	}
	void print(ostream& os) {
		Vehicle::print(os);
		os << "Made from " << getMadefrom_s();
		os << " contain " << num << " people" << endl;
	}
	Boat operator()(int year,int price,int madefrom,int nPeople){
		Vehicle::set(year, price);
		set(madefrom, nPeople);
	}
};

class Room {
	int type;		//1.bedroom,2.bathroom,3.kitchen
	int window;
public:
	Room() { set(1, 2); }
	Room(int type, int window) {
		set(type, window);
	}
	~Room() {
		cout << "type:" << getType_s() << " window:" << window << endl;
	}
	void setType(int t) { type = (t < 1 || t>3) ? 1 : t; }
	void setWindow(int w) { window = (w < 0) ? 0 : w; }
	void set(int type, int window) {
		setType(type);
		setWindow(window);
	}
	int getType() { return type; }
	int getWindow() { return window; }
	string getType_s() {
		switch (type) {
		case 1:return "bedroom";	break;
		case 2:return "bathroom";	break;
		case 3:return "kitchen";
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
public:
	House() {
		num = 2;
		room = new Room[num];
		setRoom(0, 1, 2);
		setRoom(1, 2, 1);
	}
	House(int n) {
		num = n;
		room = new Room[num];
	}
	virtual ~House() {
		delete[]room;
		cout << "total room:" << num << endl;
	}
	void set(int n) {
		num = n;
		delete[]room;
		room = new Room[num];
	}
	void setRoom(int i, int type, int window) {
		room[i].set(type, window);
	}
	int getN() { return num; }
	Room getRoom(int i) { return room[i]; }
	virtual void print(ostream& os) {
		cout << "\troom" << endl;
		for (int i = 0; i < num; i++){
			os << i + 1 << ". ";
			room[i].print(os);
		}
		os << "Total room = " << num << endl;
	}
	void addRoom(int type, int window) {
		Room* r = new Room[num];
		for (int i = 0; i < num; i++)//coppy
			r[i] = room[i];
		delete[]room;
		num++;
		room = new Room[num];
		for (int i = 0; i < num-1; i++)//coppy
			room[i] = r[i];
		delete[]r;
		room[num - 1].set(type, window);//assign new room
	}
};
ostream& operator<<(ostream& os, House& h) {
	h.print(os);
	return os;
}

class Houseboat : public Boat, public House {
	bool ghat;
public:
	Houseboat(){
		Vehicle::set(2001, 50000);
		Boat::set(1, 15);
		House::set(2);
		setRoom(0, 1, 2);
		setRoom(1, 2, 1);
		setGhat(0);
	}
	Houseboat(int year, int price, int madefrom, int nPeople, int nRoom, bool ghat) {
		Vehicle::set(year, price);
		Boat::set(madefrom,nPeople);
		House::set(nRoom);
		setGhat(ghat);
	}
	~Houseboat() {
		cout << "ghat:";
		if (ghat == 1)
			cout << "have ";
		else
			cout << "haven't ";
		cout << endl;
	}
	void setGhat(bool g) { ghat = g; }
	bool getGhat() { return ghat; }
	void print(ostream& os) {
		Boat::print(os);
		House::print(os);
		if (ghat == 1)
			os << "have ";
		else
			os << "haven't ";
		os << "Ghat" << endl;
	}
	int operator[](int index) {
		switch (index) {
		case 1:return getYear();	break;
		case 2:return getPrice();	break;
		case 3:return getMadefrom();	break;
		case 4:return getnumPeople();	break;
		default: return -1;
		}
	}
	void set(int madefrom, int nPeople, bool glat) {
		Boat::set(madefrom, nPeople);
		setGhat(glat);
	}
	void set(int year, int price, int madefrom, int nPeople, int nRoom, bool ghat) {
		Vehicle::set(year, price);
		Boat::set(madefrom, nPeople);
		House::set(nRoom);
		setGhat(ghat);
	}
	Houseboat& operator=(Houseboat& h) {
		set(h.getYear(), h.getPrice(), h.getMadefrom(), h.getnumPeople(), h.getN(), h.getGhat());
	}
};
ostream& operator<<(ostream& os, Houseboat& h) {
	h.print(os);
	return os;
}

int main()
{
	Boat a(1998, 1500, 1, 8);
	House b(3);
	Houseboat c(2000, 70000, 1, 10, 2, 1), e(2002, 50000, 2, 12, 2, 1);
	b.setRoom(0, 3, 4);
	for (int i = 0; i < 2; i++) {
		c.setRoom(i, i+1, i+1);
		e.setRoom(i, i + 2, i +2);
	}
	cout << "----" << endl;
	if (a.getYear() < 2021)
		cout << "a." << a << endl;
	if (c.getYear() < 2021)
		cout << "c." << c << endl;
	if (e.getYear() < 2021)
		cout << "e." << e << endl;
	cout << "----" << endl;
	c.addRoom(1, 3);
	c.addRoom(2, 2);
	cout << "----" << endl;
	cout << e << endl;
	cout << "----" << endl;
	int troom = 0;
	troom += b.getN();
	troom += c.getN();
	troom += e.getN();
	cout << "total room = " << troom << endl;
	cout << "----" << endl;
	Vehicle::count();
	cout << "----" << endl;
	int mental = 0;
	if (a.getMadefrom() == 2)
		mental++;
	if (c.getMadefrom() == 2)
		mental++;
	if (e.getMadefrom() == 2)
		mental++;
	cout << "total mental Vehicle = " << mental << endl;
	cout << "----" << endl;
}