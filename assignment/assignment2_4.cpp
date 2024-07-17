#include <iostream>
using namespace std;
class Person {
private:
    static int num;
    string firstName, lastName;
    char id[13];
    int date, month, year;
public:
    Person() {
        num++;  cout << num << endl;
        char id[14] = "0000000000000";
        set(id, "FirstName", "LastName", 0, 0, 0);
    }
    Person(char *i, string firstN, string lastN, int d, int m, int y) {
        num++;  cout << num << endl;
        set(i, firstN, lastN, d, m, y);
    }
    Person( string firstN, string lastN, int d, int m, int y) {
        char id[14] = "0000000000000";
        setID(id);
        num++;  cout << num << endl;
        setName(firstN, lastN);
        setBirhtday(d, m, y);
    }
    ~Person() {
        num--;
        cout << "bye bye " << firstName << endl;
    }
    void set(char *i,string fName,string lName,int d,int m,int y) {
        setID(i);
        setName(fName, lName);
        setBirhtday(d, m, y);
    }
    void setID(char* i) {
        strcpy_s(id,14, i);
    }
    void setName(string first, string last) {
        setFirstName(first);
        setLastName(last);
    }
    void setFirstName(string first) {
        firstName = first;
    }
    void setLastName(string last) {
        lastName = last;
    }
    void setBirhtday(int d, int m, int y) {
        date = d;
        month = m;
        year = y;
    }
    string getID() {
        return id;
    }
    string getFirstName() {
        return firstName;
    }
    string getLastName() {
        return lastName;
    }
    int getDate() {
        return date;
    }
    int getMonth() {
        return month;
    }
    int getYear() {
        return year;
    }
    void show() {
        cout << "ID " << id << endl;
        cout << firstName << " " << lastName << endl;
        cout << "Birhtday " << date << "/" << month << "/" << year << endl;
        //cout << endl;
    }
    static int count() {
        return num;
    }
    int FindAge(int d,int m,int y); //daet current
};
int Person::FindAge(int d, int m, int y) {
    int age;
    age = y - year;
    if (m - month < 0) 
        --age;
    if (m - month == 0) {
        if (d - date < 0)
            --age;
    }
    return age;
}
int Person::num;
int main()
{
    Person busnee;
    busnee.show();  cout << endl;
    char id1[14] = "1104400004276";
    busnee.set(id1, "Chananda", "Sehwiset", 9, 11, 2002);
    busnee.show();
    cout<<busnee.getFirstName() << " age " << busnee.FindAge(18, 8, 2022) << endl<<endl;

    char id2[14] = "lino25101998";
    Person leeknow(id2, "Minho", "Lee", 25, 10, 1998);
    leeknow.show();
    cout << leeknow.getFirstName() << " age " << leeknow.FindAge(18, 8, 2022) << endl<<endl;

    Person sewoon("Sewoon", "Jeong", 30, 5, 1997);
    sewoon.show();
    cout << sewoon.getFirstName() << " age " << sewoon.FindAge(18, 8, 2022) << endl<<endl;

    cout << "object now " << Person::count() << endl<<endl;

}