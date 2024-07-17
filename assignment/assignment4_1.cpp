#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class Point {
private:
    static int num;
    int x;
    int y;
    string name;
    char name2[20];
public:
    Point() {
        num++;
        set(0, 0, "nonamePoint");
        cout << "num = " << num << endl;
    }
    Point(int a) {
        num++;
        set(a, 0, "nonamePoint");
        cout << "num = " << num << endl;
    }
    Point(int a, int b) {
        num++;
        set(a, b, "nonamePoint");
        cout << "num = " << num << endl;
    }
    Point(int a, int b, string c) {
        num++;
        set(a, b, c);
        cout << "num = " << num << endl;
    }
    ~Point() {
        num--;
        cout << num << endl;
    }
    static int count() {
        return num;
    }
    void setX(int x) {
        this->x = x;
    }
    void setY(int y) {
        this->y = y;
    }
    void setName(string n) {
        name = n;
    }
    void set(int x, int y,string n) {
        this->x = x;
        this->y = y;
        name = n;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    string getName() {
        return name;
    }
    void show(void);
    void show2(void);
    void setName2(char* p) {
        strcpy_s(name2, 20, p);
    }
    int dot(Point& p) {
        return (x * p.x) + (y * p.y);
    }
    Point midpoint(Point& a, Point& b) {
        //x = (a.x + b.x) / 2;
        //y = (a.y + b.y) / 2;
        setX((a.x + b.x) / 2);
        setY((a.y + b.y) / 2);
        //Point p(x, y);
        //return p;
        //return Point(x,y);
        return *this;
    }
};
void Point::show() {
    cout << name << "(" << x << "," << y << ")" << endl;
}
void Point::show2() {
    cout << name2 << "(" << x << "," << y << ")" << endl;
}
int Point::num;
int main()
{
    Point a(1, 2), b(4, 6);
    cout << "(" << a.getX() << "," << a.getY() << ").(" << b.getX() << "," << b.getY() << ") = ";
    cout<<a.dot(b)<<endl;

    Point c,d;
    d=c.midpoint(a, b);
    cout << "midpointC = (" << c.getX() << "," << c.getY() <<")" << endl;
    cout << "midpointD = (" << d.getX() << "," << d.getY() << ")" << endl;
}