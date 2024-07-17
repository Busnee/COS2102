#include <iostream>
using namespace std;

class Topping {         //Abstract class
    string detail;//
    double price;//
public:
    Topping() {//
        detail = "no detail";
        price = 0;
    }
    Topping(string detail, double price) {//
        this->detail = detail;
        this->price = (price < 1) ? 1 : price;
    }
    Topping(string detail) {//   //convert str to obj
        this->detail = detail;
        price = 0;
    }
    virtual ~Topping(){}//add
    operator string() {     //convert obj to str
        return "topping";
    }
    string getDetail() { return detail; }//
    double getPrice() { return price; }//
    virtual void show() = 0;//
    virtual string operator ()() {
        return detail;
    }
    /*virtual operator string() {//เขียนแบบนี้ก็ได้
        return detail;
    }*/
};
class Chocolate :public Topping {
    int type;//        //1.dark  2.white  3.milk
public:
    Chocolate() :Topping("made in Swiss", 40) {//
        type = 1;
    }
    Chocolate(string detail, double price, int type) :Topping(detail, price) {//
        this->type = (type < 1 || type>3) ? 1 : type;
    }
    Chocolate(string detail) :Topping(detail, 40) {//   //convert
        type = 1;
    }
    operator string() {
        string a;
        switch (type) {
        case 1:a = "dark chocolate ";   break;
        case 2:a = "white chocolate ";  break;
        case 3:a = "milk chocolate ";
        }
        return a;
    }
    int getType() { return type; }//เพิ่มgetTypeString เหมือนที่เคยทำจะดี
    void show() {//
        switch (type) {
        case 1:cout << "dark chocolate ";   break;
        case 2:cout << "white chocolate ";  break;
        case 3:cout << "milk chocolate ";
        }
        cout << getDetail() << " Price " << getPrice() << endl;
    }
    string operator()() {//
        switch (type) {
        case 1:return "dark chocolate ";    break;
        case 2:return "white chocolate ";   break;
        case 3:return "milk chocolate ";
        }
    }    
};
class Fruit :public Topping {
    string name;
public:
    Fruit() :Topping("sweet", 30) {//
        name = "strawberry";
    }
    Fruit(string detail, double price, string name) :Topping(detail, price) {//
        this->name = name;
    }
    Fruit(string detail) :Topping(detail, 30) {//
        name = detail;
    }
    operator string() {//
        return name;
    }
    string getName() {//
        return name;
    }
    void show() {//
        cout << name << " " << getDetail() << " Price " << getPrice() << endl;
    }
    string operator()() {//
        return name;
    }
};



class Dessert {         //Abstract class
    int price;      //ไม่รวมtopping
    string flavor;
    Topping** topping;  //เก็บpointer
    int num;
public:
    Dessert() {//ตอนเกิดควรจองพทในconstructor
        setPrice(45);
        setFlavor("vanila");
        num = 1;//แก้แล้ว
        topping = new Topping * [num];//แก้แล้ว
    }
    Dessert(int price, string flavor, int n) {//commentเหมือนdefault
        setPrice(price);//แก้แล้ว
        setFlavor(flavor);//แก้แล้ว
        num = (n < 1) ? 1 : n;//แก้แล้ว
        topping = new Topping * [num];//แก้แล้ว
    }
    virtual ~Dessert() {//เรียกshow()ก็ได้
        delete[] topping;           //delete pointer(เมื่อnumไม่มีทางเป็น0แล้วtoppingไม่มีทาง=NULL)
        cout << "price:" << price << " flavor:" << flavor << " num:" << num << endl;
    }
    /*void set(int price, string flavor, int num) {
        setPrice(price);
        setFlavor(flavor);
        setNum(num);
    }*/
    void setPrice(int p) { price = (p < 1) ? 1 : p; }//
    void setFlavor(string f) { flavor = f; }//
    void setNum(int n){//
        n = (n < 1) ? 1 : n;//แก้แล้ว
        if (n == num)//add เช็คก่อนถ้าเท่ากันไม่จำเป็นต้องdeleteเพราะเป็นpointerไม่ใช้obj
            return;//ไม่ทำข้างล่างต่อ
        num = n;
        delete[] topping;           //delete pointer
        topping = new Topping * [num];
    }
    void setTopping(int i,Topping* topp) {//
        topping[i] = topp;
    }
    int getPrice() { return price; }//
    string getFlavor() { return flavor; }//
    int getNum() { return num; }//
    Topping* getTopping(int i) { return topping[i]; }//
    virtual void show() = 0;//
    virtual void operator++() {//แก้แล้ว
        price += 10;
    }
    //เพิ่มshowDessert
    void showTopping() {//
        for (int i = 0; i < num; i++) {
            cout << "Topping " << i + 1 << ". ";
            topping[i]->show();
        }

    }
};
/*Dessert& operator++(Dessert& d) {
    d.operator++();
    return d;
}*/
class IceCream :virtual public Dessert {
    int type;       //1.ไอศกรีมธรรมดา  2.เจลาโต้  3.ไอศกรีมโยเกิร์ต
    static int n;//ลืมบวก n อีกแล้วTT
public:
    static void count() { cout << n << endl; }//
    IceCream() {
        setType(1);
        n++;//add
    }
    IceCream(int price, string flavor, int num, int type) :Dessert(price, flavor, num) {
        setType(type);
        n++;//add
    }
    ~IceCream() {
        cout << "type:" << type << endl;
        n--;//add
    }
    void setType(int t) { type = (t < 1 || t>3) ? 1 : t; }//
    int getType() { return type; }//
    void show() {//
        cout << "--Ice cream--" << endl;
        cout << "Price = " << getPrice() << endl;
        cout << "Flaver = " << getFlavor() << endl;
        cout << "Type = " << type << endl;     //1.ไอศกรีมธรรมดา  2.เจลาโต้  3.ไอศกรีมโยเกิร์ต 
        showTopping();
        cout << "total topping = " << getNum() << endl;
    }
    void operator++() {//แก้แล้ว
        if (type == 1 || type == 2)
            type++;
        else
            type = 1;
    }
};
class Cake :virtual public Dessert {
    int type;       //1.butter  2.foam  3.mousse  4.sponge
public:
    Cake() { setType(1); }//
    Cake(int price, string flavor, int num, int type) :Dessert(price, flavor, num) {//
        setType(type);
    }
    ~Cake() {//
        cout << "type:" << type << endl;

    }
    void setType(int t) { type = (t < 1 || t>4) ? 1 : t; }//
    int getType() { return type; }//
    void show() {//
        cout << "--Cake--" << endl;
        cout << "Price = " << getPrice() << endl;
        cout << "Flaver = " << getFlavor() << endl;
        cout << "Type = " << type << endl;     //1.butter  2.foam  3.mousse  4.sponge
        showTopping();
        cout << "total topping = " << getNum() << endl;
    }
    void operator++() {//แก้แล้ว
        if (type == 1 || type == 2 || type == 3)
            type++;
        else
            type = 1;
    }
};
class IceCreamCake :public IceCream, public Cake {
    int layer;      //layer of cake+iceCream
public:
    IceCreamCake() :Dessert(100,"vanila",1) {//
        IceCream::setType(1);
        Cake::setType(4);
        setLayer(2);
    }
    IceCreamCake(int price, string flavor, int num, int IcecreamType, int cakeType,int layer) //
        : Dessert(price, flavor, num) {
        IceCream::setType(IcecreamType);
        Cake::setType(cakeType);
        setLayer(layer);
    }
    IceCreamCake(IceCreamCake& a) :Dessert(a.getPrice(), a.getFlavor(), a.getNum()) {   //coppy con
        for (int i = 0; i < getNum(); i++)
            setTopping(i, a.getTopping(i));
        IceCream::setType(a.IceCream::getType());
        Cake::setType(a.Cake::getType());
        setLayer(a.getLayer());
    }
    ~IceCreamCake() {//
        cout << "layer:" << layer << endl;
    }
    void setLayer(int l) { layer = (l < 1) ? 1 : l; }//เพิ่มsetLayerอีกอันก็ได้
    //void set(string flavor) { setFlavor(flavor); }
    //void set(int price) { setPrice(price); }
    int getLayer() { return layer; }//
    void show() {//
        cout << "--Ice cream cake--" << endl;
        cout << "Price = " << getPrice() << endl;
        cout << "Flaver = " << getFlavor() << endl;
        cout << "Ice cream Type = " << IceCream::getType() << endl; //1.ไอศกรีมธรรมดา  2.เจลาโต้  3.ไอศกรีมโยเกิร์ต
        cout << "Cake Type = " << Cake::getType() << endl; //1.butter  2.foam  3.mousse  4.sponge
        showTopping();
        cout << "total topping = " << getNum() << endl;
    }
    void operator++() {//แก้แล้ว
        layer++;
    }
};



class FoodBox {         //Abstract class
    Dessert** dessert;  //เก็บpointer
    int num;
    string* foodDetail;
public:
    FoodBox() {
        set(1);
    }
    FoodBox(int num) { set(num); }
    virtual ~FoodBox() {
        cout << "num:" << num << endl;
        if (num != 0) {
            delete[] dessert;
            delete []foodDetail;
        }
    }
    void set(int n) {
        if (num != 0){
            delete[] dessert;
            delete []foodDetail;
        }
        num = (n < 1) ? 1 : n;
        dessert = new Dessert * [num];
        foodDetail = new string[num];
    }
    void setDessert(int i, Dessert* des) {
        dessert[i] = des;
    }
    void setDetail(int i, string detail) {
        foodDetail[i] = detail;
    }
    int getNum() { return num; }
    Dessert* getDessert(int i) { return dessert[i]; }
    string getDetail(int i) { return foodDetail[i]; }
    virtual void show() = 0;//
    virtual void print(ostream& os) {
        for (int i = 0; i < num; i++) {
            os << "box " << i + 1 << ". ";
            dessert[i]->show();
            os << "detail " << foodDetail[i] << endl;
            os << endl;
        }
        os << "total box : " << num << endl;
    }
    bool operator>(FoodBox& b) {//เพิ่มgetTotalPrice()ก็ได้
        double p1 = 0, p2 = 0;
        for (int i = 0; i < num; i++)
            p1 += dessert[i]->getPrice();
        for (int i = 0; i < num; i++)
            p2 += b.getDessert(i)->getPrice();
        if (p1 > p2)
            return true;
        else
            return false;
    }
    bool operator<=(FoodBox& b) {//ไหนอ.ว่าไม่ให้ใช้>;^;
        double p1 = 0, p2 = 0;
        for (int i = 0; i < num; i++)
            p1 += dessert[i]->getPrice();
        for (int i = 0; i < b.getNum(); i++)
            p2 += b.getDessert(i)->getPrice();
        if (p1 <= p2)
            return true;
        else
            return false;
    }
};
ostream& operator<<(ostream& os, FoodBox& f) {
    f.print(os);//ถ้ามีshow()ก็ใช้ได้เลยจ้า
    return os;
}
class SquareFoodBox :public FoodBox {
    int width;
    int height;
    int length;
public:
    SquareFoodBox() :FoodBox(3) {
        set(15, 8, 30);
    }
    SquareFoodBox(int width, int height, int length, int n) :FoodBox(n) {
        set(width, height, length);
    }
    ~SquareFoodBox() {
        cout << "w:" << width << " h:" << height << " l:" << length << endl;
    }
    void setWidth(int w) { width = (w < 1) ? 1 : w; }
    void setHeight(int h) { height = (h < 1) ? 1 : h; }
    void setLength(int l) { length = (l < 1) ? 1 : l; }
    void set(int w, int h, int l) {
        setWidth(w);
        setHeight(h);
        setLength(l);
    }
    int getW() { return width; }
    int getH() { return height; }
    int getL() { return length; }
    void show() {
        cout << "box size w: " << width << " h:" << height << " l:" << length << endl;
        for (int i = 0; i < getNum(); i++) {
            cout << "box " << i + 1 << ". ";
            getDessert(i)->show();
            cout << "detail " << getDetail(i) << endl;
            cout << endl;
        }
        cout << "total box : " << getNum() << endl;
    }
    void print(ostream& os) {
        show();
    }
};
class RoundFoodBox :public FoodBox {
    int diameter;   //เส้นผ่านศูนย์กลาง
    int height;
public:
    RoundFoodBox() :FoodBox(2) {
        set(15, 8);
    }
    RoundFoodBox(int diameter, int height, int num) :FoodBox(num) {
        set(diameter, height);
    }
    ~RoundFoodBox() {
        cout << "d:" << diameter << " h:" << height << endl;
    }
    void setDiameter(int d) { diameter = (d < 1) ? 1 : d; }
    void setHeight(int h) { height = (h < 1) ? 1 : h; }
    void set(int d, int h) {
        setDiameter(d);
        setHeight(h);
    }
    int getD() { return diameter; }
    int getH() { return height; }
    void show() {
        cout << "box size d:" << diameter << " h:" << height << endl;
        for (int i = 0; i < getNum(); i++) {
            cout << "box " << i + 1 << ". ";
            getDessert(i)->show();
            cout << "detail " << getDetail(i) << endl;
            cout << endl;
        }
        cout << "total box : " << getNum() << endl;
    }
    void print(ostream& os) {
        show();
    }
};

int IceCream::n;
int main()
{
    Chocolate dark("gradeA", 30, 1), white("grade premium", 35, 2), milk("from Chiang Mai", 25, 3);
    Fruit cherry("premium fruit", 20, "Cherry"), strawberry("sweet", 30, "Strawberry");
    IceCream icecream(90, "Tiramisu", 1, 2);
    icecream.setTopping(0, &dark);
    Cake butterCake(120, "Coffee", 2, 1);
    butterCake.setTopping(0, &white);
    butterCake.setTopping(1, &strawberry);
    IceCreamCake iceCake1(240, "vanilla", 2, 1, 4, 5), iceCake2(250, "Pistachio ice cream and vanilla cake", 1, 2, 1, 3);
    iceCake1.setTopping(0, &milk);
    iceCake1.setTopping(1, &cherry);
    iceCake2.setTopping(0, &strawberry);
    SquareFoodBox squareBox(15, 8, 30,3);
    squareBox.setDessert(0, &icecream);
    squareBox.setDessert(1, &butterCake);
    squareBox.setDessert(2, &iceCake1);
    squareBox.setDetail(0, "Tiramisu ice crream with dark chocolate");
    squareBox.setDetail(1, "Coffee cake with white chocolate and strawberry");
    squareBox.setDetail(2, "Ice cream cake + milk + cherry");
    RoundFoodBox roundBox(20, 10, 1);
    roundBox.setDessert(0, &iceCake2);
    roundBox.setDetail(0, "Ice cream cake + strawberry");

    for (int i = 0; i < 3; i++)
        squareBox.getDessert(i)->show();
    roundBox.getDessert(0)->show();

    string darkS = dark, whiteS = white, milkS = milk, cherryS = cherry, strawberryS = strawberry;
    cout << "----" << endl;
    cout << darkS << endl;
    cout << whiteS << endl;
    cout << milkS << endl;
    cout << cherryS << endl;
    cout << strawberryS << endl;
    cout << "----" << endl;

    string dark2S = "super premium", raspberryS = "raspberry";
    Chocolate dark2(dark2S);
    Fruit raspberry(raspberryS);
    dark2.show();
    raspberry.show();
    cout << "----" << endl;

    IceCreamCake iceCake3(iceCake2);
    iceCake3.Cake::setType(4);
    iceCake3.show();
    cout << "----" << endl;

    iceCake3.setNum(2);
    iceCake3.setTopping(0, &dark2);
    iceCake3.setTopping(1, &raspberry);
    iceCake3.show();
    cout << "======" << endl;

    Dessert* dessertArray[5]{ &icecream,&butterCake,&iceCake1,&iceCake2,&iceCake3 };
    for (int i = 0; i < 5; i++)
    {
        //dessertArray[i]++; ก็มรึงทำเป็นpreflix
        ++(*dessertArray[i]);//ต้องเขียนแบบนี้นะคะ***
        dessertArray[i]->show();
        cout << endl;
    }
    cout << "----" << endl;

    cout << squareBox << endl;
    cout << roundBox << endl;
    cout << "----" << endl;

    if (squareBox <= roundBox)
        cout << "round box expensive more" << endl;
    else
        cout << "square box expensive more" << endl;
    cout << "----" << endl;

    if (squareBox.getNum() > roundBox.getNum())
        cout << "dessert of square box more" << endl;
    else
        cout << "dessert of round box more" << endl;
    cout << "----" << endl;

}