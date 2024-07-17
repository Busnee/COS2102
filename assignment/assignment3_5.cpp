#include <iostream>
using namespace std;
class Point {
private:
    static int num;
    int x;
    int y;
    string name;
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
    void set(int x, int y, string n) {
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
};
void Point::show() {
    cout << name << "(" << x << "," << y << ")" << endl;
}
class MyPoint {
private:
    int x;
    Point *p;
    void setArray(int y) {
        x = y;
        p = new Point[x];
    }
public:
    MyPoint() {
        x = 0;
        p = 0;
    }
    MyPoint(int y) {
        setArray(y);
    }
    ~MyPoint() {
        delete[] p;
        cout << "bye bye" << endl;
    }
    void reset(int y) {      //กำหนดขนาดและจองพื้นที่ให้array
        delete[] p;
        setArray(y);
    }
    void setPoint(int i,int x,int y,string n) {   //กำหนดค่าให้กับobject in array
        p[i].set(x, y, n);
    }
    void setPoint(int i, int x, int y) {
        p[i].setX(x);
        p[i].setY(y);
    }
    Point getPoint(int i) {   //return obj in array
        return p[i];
    }
    void show() {
        for (int i = 0; i < x; i++) {
            p[i].show();
        }
    }
};
int Point::num;
int main()
{
    MyPoint mp1, mp2(2);
    //mp2.show();
    mp2.setPoint(0, 1, 2, "p1");
    //mp2.show();
    mp2.setPoint(1, 2, 3);
    mp2.show();
    cout << "mp2 x : "<<mp2.getPoint(1).getX() << endl;
}