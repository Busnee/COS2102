//อันในคลิป
//exercise 28 ข้อ 3
#include <iostream>
using namespace std;

class Meat{
    	int type;
    	public:
    	Meat(){
		type = 1;
	}
	Meat(int type){
		/*แบบที่ 1
		if(type<1||type>6)
			this->type = 1;
		else
			this->type = type;
		*/
		/*แบบที่2
		this->type = (type<1||type>6?1:type);
		*/
		setType(type);
	}
	void setType(int t){
		type = (t<1||t>6?1:t);
	}
	~Meat(){
		cout<<"~meat type:"<<type<<endl;
	}
	int getType();
};

int Meat::getType(){
	return type;
}
	
class Vegetable{
	string name;
	public:
	Vegetable(){
		name = "";
	}
	void setName(string n){
		name = n;
	}
	Vegetable(string name){
		setName(name);
	}
	string getName(){
		return name;
	}
	~Vegetable(){
		cout<<"~veg name:"<<name<<endl;
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
	void setPrice(double p){
		price = (p<0?0:p);
	}
	void setMeat(int i, int type){
		meat[i].setType(type);
	}
	void setVeg(int i, string name){
		veg[i].setName(name);
	}
	void setMeatNum(int n){
		if(meatNum>0)
			delete[] meat;
		meatNum = (n<0?0:n);
		meat = new Meat[meatNum];
	}
	void setVegNum(int n){
		if(vegNum>0)
			delete[] veg;
		vegNum = (n<0?0:n);
		veg = new Vegetable[vegNum];
	}
	Food(int price){
		setPrice(price);
		setMeatNum(0);
		setVegNum(0);
		meat = 0;
		veg = 0;
		num++;
	}
	double getPrice(){
		return price;
	}
	int getMeatNum(){
		return meatNum;
	}
	int getVegNum(){
		return vegNum;
	}
	Meat getMeat(int i){
		return meat[i];
	}
	Vegetable getVeg(int i){
		return veg[i];
	}
	~Food(){
		cout<<"~price:"<<price;
		cout<<"~meat n:"<<meatNum;
		cout<<"~veg n:"<<vegNum;
		cout<<"~meat:";
		for(int i=0;i<meatNum;i++)
			cout<<meat[i].getType();
		cout<<"~veg:";
		for(int i=0;i<vegNum;i++)
			cout<<veg[i].getName();
		delete[] meat;
		delete[] veg;
		num--;
	}
	void showFoodNum(){
		cout<<"current number of Food : "<<num<<endl;
	}
};

class Kaopad:public Food{
	int type;
	public:
	Kaopad(){
		type = 1;
	}
	void setType(int t){
		type = (t<1||t>2?1:t);
	}
	Kaopad(double price, int type):Food(price){
		setType(type);
	}
	int getType(){
		return type;
	}
	~Kaopad(){
		cout<<"~kaopad type:"<<type;
		cout<<"~price:"<<getPrice();
		cout<<"~meat n:"<<getMeatNum();
		cout<<"~veg n:"<<getVegNum();
		cout<<"~meat:";
		/*
		for(int i=0; i<getMeatNum(); i++)
			cout<<getMeat(i).getType();
		*/
		showMeat();
		cout<<"~veg:";
		for(int i=0; i<getVegNum(); i++)
			cout<<getVeg(i).getName();
		//ยังไม่ delete meat and veg เพราะ ~Food ต้องใช้
	}
	bool isMoreExpensiveThan(Kaopad k){
		if(getPrice()>k.getPrice())
			return true;
		else
			return false;
	}
	void showMeat(){
		for(int i=0; i<getMeatNum(); i++)
			cout<<" "<<getMeat(i).getType();
	}
};


class Soup:public Food{
	int type;
	int spicyLevel;
	public:
	Soup(){
		type = 1;
		spicyLevel = 1;
	}
	void setType(int t){
		type = (t<1||t>4?1:t);
	}
	void setSpicyLevel(int level){
		spicyLevel = (level<1||level>4?1:level);
	}
	Soup(double price, int type, int spicyLevel){
		setPrice(price);
		this->type = (type<1||type>4?1:type);	
		setSpicyLevel(spicyLevel);
	}
	int getType(){
		return type;
	}
	int getSpicyLevel(){
		return spicyLevel;
	}
	~Soup(){
		cout<<"~soup";
		show();
	}
	void show(){
		cout<<"soup type = "<<type<<endl;
		cout<<"spicy level = "<<spicyLevel<<endl;
		cout<<"price ="<<getPrice()<<endl;
		cout<<"meat = ";
		for(int i=0; i<getMeatNum(); i++)
			cout<<" "<<getMeat(i).getType();
		cout<<", total meat "<<getMeatNum()<<endl;
		cout<<"veg = ";
		for(int i=0; i<getVegNum(); i++)
			cout<<" "<<getVeg(i).getName();
		cout<<", total veg "<<getVegNum()<<endl;
	}
};

int Food::num;

int main(){
	Soup *s[2];
	s[0] = new Soup(250, 1, 4);
	s[0]->setMeatNum(3);
	s[0]->setMeat(0,4);
	s[0]->setMeat(1,5);
	s[0]->setMeat(2,6);
	
	s[1] = new Soup(100, 2, 3);
	s[1]->setMeatNum(1);
	s[1]->setVegNum(2);
	s[1]->setMeat(0,3);
	s[1]->setVeg(0,"มะละกอ");
	s[1]->setVeg(1,"ถั่วฝักยาว");

	Kaopad k(120, 2);
	k.setMeatNum(1);
	k.setVegNum(2);
	k.setMeat(0,1);
	k.setVeg(0,"แครอท");
	k.setVeg(1,"ต้นหอม");

	//cout<<"s[0]"<<endl;
	//s[0]->show();
	//cout<<"s[1]"<<endl;
	//s[1]->show();
	for(int i=0; i<2; i++){
		cout<<"s"<<i<<endl;
		s[i]->show();
	}

	cout<<"k"<<endl;
	cout<<"price = "<<k.getPrice();
	cout<<"type = "<<k.getType();
	cout<<"meat = ";
	k.showMeat();
	cout<<", total meat "<<k.getMeatNum()<<endl;
	cout<<"veg = ";
	for(int i=0; i<k.getVegNum(); i++)
		k.getVeg(i).getName();
	cout<<", total veg "<<k.getVegNum()<<endl;
	
	double totalPrice = k.getPrice();
	for(int i=0; i<2; i++)
		totalPrice += s[i]->getPrice();
	cout<<"total price = "<<totalPrice<<endl;
	
	s[0]->setVegNum(1);
	s[0]->setVeg(0,"เห็ด");
	s[0]->show();
	
	cout<<"--finish--"<<endl;
}