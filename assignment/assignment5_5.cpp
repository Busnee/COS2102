#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
using namespace std;
class Circle;
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
    void show2(void);
    void setName2(char* p) {
        strcpy_s(name2, 20, p);
    }
    friend bool prove(Point p, Circle c);
};
void Point::show() {
    cout << name << "(" << x << "," << y << ")" << endl;
}
void Point::show2() {
    cout << name2 << "(" << x << "," << y << ")" << endl;
}
class Circle{
    int radain;
    Point point;
public:
    Circle() {
        radain = 0;
    }
    Circle(int r, Point p) {
        set(r, p);
    }
    ~Circle() {
        cout << "bye bye" << endl;
    }
    void set(int r, Point p) {
        radain = r;
        point = p;
    }
    int getRadain() {
        return radain;
    }
    Point getPoint() {
        return point;
    }
    void show() {
        cout << "  circle  " << endl;
        point.show();
        cout << "radai = " << radain << endl;
    }
    friend bool prove(Point p,Circle c);
};
bool prove(Point p, Circle c) {     //friend
    bool flag = true;
    float d = sqrt(pow((p.x - c.point.x), 2) + pow((p.y - c.point.y), 2));
    cout << "d = "<<d << endl;
    if (d > c.radain)       //ไม่อยู่ในวงกลม
        flag = false;
    return flag;
}
void Output(bool r) {           
    if (r == true)
        cout << "this point exist in the circle" << endl << endl;
    else
        cout << "this point not exist in the circle" << endl << endl;
}
void prove2(Point p, Circle c) {    //not friend
    p.show();
    c.show();
    float d = sqrt(pow((p.getX() - c.getPoint().getX()), 2) + pow((p.getY() - c.getPoint().getY()), 2));
    cout << "d = " << d << endl;
    if (d < c.getRadain())
        cout << p.getName() << " point exist in "<<c.getPoint().getName()<<" circle" << endl << endl;
    else
        cout << p.getName() << " point not exist in " << c.getPoint().getName() << " circle" << endl << endl;
}
int Point::num;
int main()
{
    Circle a;
    a.show();
    Point p(4, 5,"a");
    a.set(3, p);
    a.show();

    p.set(2, 3,"b");
    Circle b(4, p);
    b.show();
    cout << endl;

    Point q(1, 3,"q"), r(6, 7,"r");
    cout << "---------------------------------"<<endl;

    q.show();
    a.show();
    bool result = prove(q, a);
    Output(result);
    r.show();
    a.show();
    result = prove(r, a);
    Output(result);

    prove2(q, b);
    prove2(r, b);

    //cout << "test"<<pow(4,2) << endl;

}