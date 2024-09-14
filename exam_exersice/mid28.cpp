//ใน comment เป็นnoteคำแนะนำ กับบอกจุดที่เราเขียนผิดตอนเขียนด้วยมือ (cout เป็นเวอร์ชั่นปรับแล้วให้ output ดูง่าย)
#include <iostream>
using namespace std;

class Meat{
    int type;
    public:
    Meat(){
        type = 1;
    }
    Meat(int type){
        setType(type);
    }
    ~Meat(){
        cout<<"~Meat"<<endl;
        cout<<"meat type:"<<type<<endl;
        cout<<"~~~"<<endl;
    }
    void setType(int t){
        type = ((t<1||t>6)?1:t);    //แบบย่อ
        /*
            แบบเต็ม
       if(t<1||t>6)
            type = 1;
        else
            type = t;    
        */
    }
    int getType(){
        return type;
    }
};

class Vegetable{
    string name;
    public:
    Vegetable(){
        name = "";
    }
    Vegetable(string name){
        setName(name);
    }
    ~Vegetable(){
        cout<<"~Vegetable"<<endl;
        cout<<"vegetable name:"<<name<<endl;
        cout<<"~~~"<<endl;
    }
    void setName(string n){
        name = n;
    }
    string getName(){
        return name;
    }
};

class Food{
    double price;
    Meat *meat;
    int meatNum;
    Vegetable *veg;
    int vegNum;
    static int num;
    public:
    Food(){
        price = 99;
        meat = 0;
        veg = 0;
        meatNum = vegNum = 0;
        num++;
    }
    Food(double price){
        setPrice(price);
        meat = 0;
        veg = 0;
        setMeatNum(0);
        setVegNum(0);
        // setMeat(0,0);    //เขียนแบบนี้แล้วรันไม่ผ่าน น่าจะเพราะ array 0 ไม่มี obj เลยทำ meat[i].setType(type); ไม่ได้
        // setVeg(0,0);
        num++;
    }
    ~Food(){
        cout<<"~Food"<<endl;
        cout<<"Food price:"<<price<<endl;
        cout<<"meat:";
        for(int i=0; i<meatNum; i++)
            cout<<" "<<meat[i].getType();
        cout<<", total "<<meatNum<<endl;
        delete[] meat;
        cout<<"veg:";
        for(int i=0; i<meatNum; i++)
            cout<<" "<<veg[i].getName();
        cout<<", total "<<vegNum<<endl;
        delete[] veg;
        showFoodNum();
        cout<<"~~~"<<endl;
    }
    void setPrice(int p){
        price = ((p<0)?0:p);            //ลืมใส่เงื่อนไข
    }
    void setMeatNum(int n){
        if(meatNum!=0)
            delete[] meat;
        meatNum = (n<0?0:n);
        meat = new Meat[meatNum];
    }
    void setMeat(int i, int type){
        meat[i].setType(type);
    }
    void setVegNum(int n){
        if(meatNum!=0)
            delete[] veg;
        vegNum = ((n<0)?0:n);
        veg = new Vegetable[vegNum];
    }   
    void setVeg(int i, string name){
        veg[i].setName(name);
    } 
    void showFoodNum(){
        cout<<"current number of food "<<num<<endl;
    }
    double getPrice();
    Meat getMeat(int i);
    int getMeatNum();
    Vegetable getVeg(int i);
    int getVegNum();
};

class Kaopad:public Food{
    int type;
    public:
    Kaopad(){
        type = 1;
    }
    Kaopad(double price, int type):Food(price){
        setType(type);
    }
    ~Kaopad(){                                      //class ลูกเรียก private ของ class แม่ไม่ได้
        cout<<"~kaopad"<<endl;
        cout<<"Kaopad price:"<<getPrice()<<endl;
        cout<<"Kaopad type:"<<type<<endl;
        cout<<"meat :";
        for(int i=0; i<getMeatNum(); i++)
            cout<<" "<<getMeat(i).getType();
        cout<<", total "<<getMeatNum()<<endl;
        cout<<"veg:";
        for(int i=0; i<getMeatNum(); i++)
            cout<<" "<<getVeg(i).getName();
        cout<<", total "<<getVegNum()<<endl;
        cout<<"~~~"<<endl;
        //note ยังไม่ delete meat&veg เพราะ Food ต้องใช้
    }
    void setType(int t){        //ลืมใส่ retrun type
        type = ((t<1||t>2)?1:t);
    }
    int getType(){              //ลืมใส่ retrun type 
        return type;
    }
    bool isMoreExpensiveThan(Kaopad k){
        if(getPrice() > k.getPrice())
            return true;
        else
            return false;
    }
    void showMeat(){
        for(int i=0; i<getMeatNum(); i++)
            cout<< getMeat(i).getType();
    }
};

double Food::getPrice(){        //ต้องใส่ return type
        return price;
    }
Meat Food::getMeat(int i){      //ต้องใส่ return type
        return meat[i];
    }
int Food::getMeatNum(){         //ต้องใส่ return type
        return meatNum;
    }
Vegetable Food::getVeg(int i){  //ต้องใส่ return type
        return veg[i];
    }
int Food::getVegNum(){          //ต้องใส่ return type
        return vegNum;
    }

class Soup:public Food{
    int type;
    int spicyLevel;
    public:
    Soup(){
        type = 1;
        spicyLevel = 1;
    }
    Soup(double price, int type, int spicyLevel):Food(price){
        setType(type);
        setSpicyLevel(spicyLevel);
    }
    void setType(int t){
        type = ((t<1||t>4)?1:t);
    }
    void setSpicyLevel(int level){
        spicyLevel = ((level<1||level>4)?1:level);
    }
    int getType(){
        return type;
    }
    int getSpicyLevel(){
        return spicyLevel;
    }
    void show(){
        cout<<"soup price:"<<getPrice()<<endl;   //ลืมแสดงค่า price
        cout<<"soup type:"<<type<<endl;
        cout<<"soup spicy level "<<spicyLevel<<endl;
        cout<<"-meat-"<<endl;
        for(int i=0; i<getMeatNum(); i++)
            cout<<i+1<<")"<<getMeat(i).getType()<<endl;
        cout<<"total meat "<<getMeatNum()<<endl;
        cout<<"-veg-"<<endl;
        for(int i=0; i<getVegNum(); i++)
            cout<<i+1<<")"<<getVeg(i).getName()<<endl;
        cout<<"total veg "<<getVegNum()<<endl;
    }
    ~Soup(){
        cout<<"~Soup"<<endl;
        show();
        cout<<"~~~"<<endl;
    }
};

int Food::num;       //ลืมประกาศ

int main(){
    Soup *s[2];
    s[0] = new Soup(250, 1, 4);
    s[0]->setMeatNum(3);            //ต้องใช้ -> ไม่ใช่ .
    s[0]->setMeat(0,4);
    s[0]->setMeat(1,5);
    s[0]->setMeat(2,6);

    s[1] = new Soup(100,2,3);
    s[1]->setMeatNum(1);
    s[1]->setMeat(0,3);
    s[1]->setVegNum(2);
    s[1]->setVeg(0,"มะละกอ");       //ใส่ index ผิด
    s[1]->setVeg(1,"ถั่วฝักยาว");      //ใส่ index ผิด

    Kaopad k = Kaopad(120,2);       //เขียนผิด k = new Kaopad(120,2);
    k.setMeatNum(1);
    k.setMeat(0,1);
    k.setVegNum(2);
    k.setVeg(0,"แครอท");
    k.setVeg(1,"ต้นหอม");

    for(int i=0; i<2; i++){
        cout<<"--show s"<<i+1<<endl;
        s[i]->show();
    }
    
    cout<<"--show k--"<<endl;
    cout<<"type :"<<k.getType()<<endl;
    cout<<"price :"<<k.getPrice()<<endl;
    cout<<"-meat-"<<endl;
    for(int i=0; i<k.getMeatNum(); i++)
        cout<<i+1<<")"<<k.getMeat(i).getType()<<endl;
    cout<<"total meat "<<k.getMeatNum()<<endl;
    cout<<"-veg-"<<endl;
    for(int i=0; i<k.getVegNum(); i++)
            cout<<i+1<<")"<<k.getVeg(i).getName()<<endl;
    cout<<"total veg "<<k.getVegNum()<<endl;
    
    double totalPrice = k.getPrice();
    for(int i=0; i<2; i++)
        totalPrice += s[i]->getPrice();
    cout<<"total price = "<<totalPrice<<endl;
    
    s[0]->setVegNum(1);
    s[0]->setVeg(0,"เห็ด");
    cout<<"--show s0 again"<<endl;
    s[0]->show();
    cout<<"--finish--"<<endl;
}