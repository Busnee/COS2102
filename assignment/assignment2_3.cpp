#include <iostream>
using namespace std;
class Rectangle {
private :
    static int num;
    int width;
    int lenght;
    string name;
    //int area;
    //int circum;
public :
    Rectangle() {
        set(0, 0,"noname");
        //area = 0;
        //circum = 0;
        num++;
    }
    Rectangle(int x) {
        set(x, 0, "noname");
        //findArae();
        //findCircum();
        num++;
    }
    Rectangle(int x, int y) {
        set(x, y, "noname");
        //findArae();
        //findCircum();
        num++;
    }
    Rectangle(int x, int y, string n) {
        set(x, y, n);
        //findArae();
        //findCircum();
        num++;
    }
    ~Rectangle() {
        num--;
        cout << num << endl;
    }
    void set(int x, int y, string n) {
        width = x;
        lenght = y;
        name = n;
    }
    int getWidht() {
        return width;
    }
    int getLenght() {
        return lenght;
    }
    /*int getArea() {
        return area;
    }
    int getCircum() {
        return circum;
    }*/
    string getName() {
        return name;
    }
    int findArae() {
        return width * lenght;
    }
    int findCircum() {
        return 2 * width + 2 * lenght;
    }
    void show(void);
    static int count() {
        return num;
    }
};
void Rectangle::show() {
    cout << name << endl;
    cout << "width = " << width << endl;
    cout << "lenght = " << lenght << endl;
    //cout << "area = " << area << endl;
    //cout << "circum = " << circum << endl;
}
int Rectangle::num;
int main()
{
    cout << "num = " << Rectangle::count() << endl;
    Rectangle a;
    cout << "num = " << Rectangle::count() << endl;
    Rectangle b(2), c(2, 3), d(2, 4, "dee");
    cout << "num = " << Rectangle::count() << endl;
    cout << endl;
    a.show();
    cout << "area = " << a.findArae() << endl;
    cout << "circum = " << a.findCircum() << endl;
    cout << endl;
    b.show();
    cout << "area = " << b.findArae() << endl;
    cout << "circum = " << b.findCircum() << endl;
    cout << endl;
    c.show();
    cout << "area = " << c.findArae() << endl;
    cout << "circum = " << c.findCircum() << endl;
    cout << endl;
    cout << d.getName()<<endl;
    cout << "Area = " << d.getWidht() << " x " << d.getLenght()<<" = "<<d.findArae() << endl;
    cout << "Circum = (2 x " << d.getWidht() << ") + " << "(2 x " << d.getLenght() << ") = " << d.findCircum() << endl;
    cout << endl;
}