#include <iostream>
#include <string>
#include <string.h>
using namespace std;
void line();
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
            strcpy_s(name2,20,p);
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
    cout << "num = " << Point::count << endl;
    Point p1,p2,p3;
    p1.set(2, 3, "aPoint");
    p2.setX(2);
    p2.setY(4);
    p2.setName("bPoint");
    p1.show();
    cout << "name = " << p1.getName()<<endl;
    cout << "x = " << p1.getX() << endl;
    cout << "y = " << p1.getY() << endl;
    //cout << p1.getX() + p1.getY();
    cout << "-------------------" << endl;
    p2.show();
    cout << "name = " << p2.getName() << endl;
    cout << "x = " << p2.getX() << endl;
    cout << "y = " << p2.getY() << endl;
    cout << "-------------------" << endl;
    p3.setX(2);
    p3.setY(5);
    char p[20] = "cPoint";
    p3.setName2(p);
    p3.show2();
    cout << "num = " << Point::count() << endl;
    //line();
    //-------------------3/8/2565----------------------
    Point p4;
    p4.show();
    {
        Point p5(2);
        p5.show();
    }
    Point p6(2, 6);
    p6.show();
    Point p7(2, 7, "dPoint");
    p7.show();
}
void line()
{
    cout<<"-------------------" << endl;
}