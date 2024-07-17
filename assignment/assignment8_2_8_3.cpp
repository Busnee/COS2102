#include <iostream>
using namespace std;
class Rectangle {
private:
    //static int num;
    int width;
    int lenght;
public:
    Rectangle() {
        set(0, 0);
        //num++;
    }
    Rectangle(int x) {
        set(x, 0);
        //num++;
    }
    Rectangle(int x, int y) {
        set(x, y);
        //num++;
    }
    ~Rectangle() {
        //num--;
        //cout << num << endl;
    }
    void set(int x, int y) {
        width = x;
        lenght = y;
    }
    int getWidht() {
        return width;
    }
    int getLenght() {
        return lenght;
    }
    int findArea() {
        return width * lenght;
    }
    int findCircum() {
        return 2 * width + 2 * lenght;
    }
    void show(void);
    /*static int count() {
        return num;
    }*/
    //--------------8.2---------------
    Rectangle operator++() {
        width++;
        return *this;
    }
    Rectangle operator++(int) {
        lenght++;
        return *this;
    }
    friend Rectangle operator--(Rectangle& r) {
        r.width--;
        if (r.width < 1)
            r.width = 1;
        return r;
    }
    friend Rectangle operator--(Rectangle& r, int) {
        r.lenght--;
        if (r.lenght < 1)
            r.lenght = 1;
        return r;
    }
    //-----------------8.3-----------------
    bool operator<(Rectangle r) {
        return findArea() < r.findArea();
    }
    bool operator<=(Rectangle r) {
        return findArea() <= r.findArea();
    }
    bool operator>(Rectangle r) {
        return findArea()>r.findArea();
    }
    bool operator>=(Rectangle r) {
        return findArea() >= r.findArea();
    }
    bool operator!=(Rectangle r) {
        return findArea() != r.findArea();
    }
    int &operator[](int c) {
        switch (c) {
        case 1:return width;  break;
        case 2:return lenght; break;
        }
    }
    int operator()() {
        return findArea();
    }
    int &operator()(char c){
        switch (c) {
        case 'w':return width;  break;
        case 'l':return lenght; break;
        default:cout << "no case"<<endl;
        }
    }
};
void Rectangle::show() {
    cout << "width = " << width << endl;
    cout << "lenght = " << lenght << endl;
}
//int Rectangle::num;
int main()
{
    Rectangle a(2, 2), d;
    a.show();
    d.show();
    d=a++;
    d.show();
    d=++a;
    d.show();
    d=a--;
    d.show();
    d=--a;
    d.show();
    Rectangle b(4, 5);
    if (a < b)
        cout <<"A " << a.findArea() << endl;
    else
        cout <<"B "<< b.findArea() << endl;
    if (a <= b)
        cout << "A " << a.findArea() << endl;
    else
        cout << "B " << b.findArea() << endl;
    if (a > b)
        cout << "A " << a.findArea() << endl;
    else
        cout << "B " << b.findArea() << endl;
    if (a >= b)
        cout << "A " << a.findArea() << endl;
    else
        cout << "B " << b.findArea() << endl;
    if (a != b)
        cout << "A!=B" << endl;
    else
        cout << "A==B" << endl;
    a[1] = 1;
    a[2] = 2;
    cout << "Width = " << a[1] << endl;
    cout << "Lenght = " << a[2] << endl;
    Rectangle c;
    c('w') = a('w') + b('w');
    c('l') = abs(a('l') - b('l'));
    cout << "C Widht = " << c.getWidht() << endl;
    cout << "C Lenght = " << c.getLenght() << endl;
    cout << "C area = " << c();
}