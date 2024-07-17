#include <iostream>
using namespace std;
class Rectangle {
private:
    static int num;
    int width;
    int lenght;
public:
    Rectangle() {
        set(0, 0);
        num++;
    }
    Rectangle(int x) {
        set(x, 0);
        num++;
    }
    Rectangle(int x, int y) {
        set(x, y);
        num++;
    }
    Rectangle(int x, int y, string n) {
        set(x, y);
        num++;
    }
    ~Rectangle() {
        num--;
        cout << num << endl;
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
    cout << "width = " << width << endl;
    cout << "lenght = " << lenght << endl;
}
class MyRect {
private:
    int row, col;
    Rectangle ** a;
    void del() {            
        if (a != 0) {
            for (int i = 0; i < row; i++)
                delete[] a[i];  //delete col
            delete[] a;         //delete row
        }
    }
    void newArray() {
        a = new Rectangle * [row];          //Array of pointer
        for (int i = 0; i < row; i++)
            a[i] = new Rectangle[col];
    }
public:
    MyRect() {
        a = 0;
        row = col = 0;
    }
    MyRect(int r, int c) {
        row = r;
        col = c;
        newArray();
    }
    ~MyRect() {
        del();
        cout << "Bye Bye" << endl;
    }
    void setRect() {                        //เซตทุกObj
        int w, l;
        for (int i = 0; i < row; i++) 
            for (int j = 0; j < col; j++) {
                cout << "Input width[" << i << "][" << j << "] ";
                cin >> w;
                cout << "Input length[" << i << "][" << j << "] ";
                cin >> l;
                a[i][j].set(w, l);
                cout << endl;
            }
    }
    void set(int r,int c,int w,int l) {     //เซตObjเดียว
        a[r][c].set(w, l);
    }
    Rectangle getRect(int r, int c) {
        return a[r][c];
    }
    void reset(int r,int c) {
        del();
        row = r;
        col = c;
        newArray();
    }
    void show() {
        cout<<"   show"<<endl;
        for(int i=0;i<row;i++)
            for (int j = 0; j < col; j++) {
                cout << "Rectangle[" << i << "][" << j << "]" << endl;
                a[i][j].show();
                cout << endl;
            }
    }
    void show(int r, int c) {
        cout << "   show" << endl;
        cout << "Rectangle[" << r << "][" << c << "]" << endl;
        a[r][c].show();
        cout << endl;
    }
};
int Rectangle::num;
int main()
{
    MyRect a;
    a.reset(1, 3);
    cout << Rectangle::count() << endl;
    a.set(0, 2, 4, 5);
    a.show();
    MyRect b(2, 2);
    cout << Rectangle::count() << endl;
    b.setRect();
    b.show();
    b.set(0,0,8,9);
    b.set(1, 2, 10, 10);
    b.show(0,0);
    b.show(1, 2);
    Rectangle x = b.getRect(0,0);
    cout << "Rectangle x" << endl;
    x.show();   cout << endl;
    b.getRect(1, 2).show();
}