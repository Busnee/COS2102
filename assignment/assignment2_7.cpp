#include <iostream>
using namespace std;
class Address {
private:
    static int num;
    string name;
    string address;
public:
    Address() {
        num++;
        set("noname", "noaddress");
    }
    Address(string name,string add) {
        num++;
        set(name,add);
    }
    ~Address() {
        num--;
        cout << "bye bye "<<name;
    }
    void set(string name,string add) {
        this->name = name;
        address = add;
    }
    string get() {
        return address;
    }
    string getName() {
        return name;
    }
    static void count() {
        cout << num << endl;
    }
    void show();
};
void Address::show() {
    cout << name << endl;
    cout << address << endl;
}
int Address::num;
int main()
{
    Address::count();
    Address a("Busnee", "4 ramkhamheang 118 33-3");
    Address::count();
    a.show();
}