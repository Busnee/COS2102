#include <iostream>
#include <iomanip>
using namespace std;
class Person {
private:
    static int num;
    string firstName, lastName;
    char id[13];
    int date, month, year;
    char studentID[11];
    string faculy, department;
    float gpa;
    void setGPA(float grade) {
        gpa = grade;
    }
public:
    Person() {
        num++;  cout << num << endl;
        char id[14] = "0000000000000";
        set(id, "FirstName", "LastName", 0, 0, 0);
        char stdID[11] = "0000000000";
        setStudent(stdID, "Faculy", "Department");
        setGPA(0);
    }
    Person(char* id, string firstN, string lastN, int d, int m, int y) {    
        num++;  cout << num << endl;
        set(id, firstN, lastN, d, m, y); //
        char stdID[11] = "0000000000";
        setStudent(stdID, "none", "none");
        setGPA(0);
    }
    Person(string firstN, string lastN, int d, int m, int y) {
        num++;  cout << num << endl;
        char id[14] = "0000000000000";
        setID(id);
        setBirhtday(d, m, y);                       //
        setName(firstN, lastN);                     //
        char stdID[11] = "0000000000";
        setStudent(stdID, "Faculy", "Department");
        setGPA(0);
    }
    Person(string firstN,string lastN,char *stdID,string faculy,string department) { //student
        num++;  cout << num << endl;
        char id[14] = "0000000000000";
        setID(id);
        setBirhtday(0, 0, 0);
        setName(firstN, lastN);                 //
        setStudent(stdID, faculy, department);  //
        setBirhtday(0, 0, 0);
        setGPA(0);
    }
    Person(string firstN, string lastN, string faculy, string department) { //student
        num++;  cout << num << endl;
        char id[14] = "0000000000000";
        setID(id);
        setBirhtday(0, 0, 0);
        setName(firstN, lastN);             //
        char stdID[11] = "0000000000";      
        setStudentID(stdID);                
        setFaculy(faculy);                  //
        setDepartment(department);          //
        setGPA(0);
    }
    ~Person() {
        num--;
        cout << "bye bye " << firstName << endl;
    }
    void set(char* i, string fName, string lName, int d, int m, int y) {
        setID(i);
        setName(fName, lName);
        setBirhtday(d, m, y);
    }
    void setID(char* i) {
        strcpy_s(id, 14, i);
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
    void setStudent(char* stdID, string faculy, string department) {
        setStudentID(stdID);
        setFaculy(faculy);
        setDepartment(department);
    }
    void setStudentID(char* i) {
        strcpy_s(studentID, 11, i);
    }
    void setFaculy(string f) {
        faculy = f;
    }
    void setDepartment(string d) {
        department = d;
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
    string getStudentID() {
        return studentID;
    }
    string getFaculy() {
        return faculy;
    }
    string getDepartment() {
        return department;
    }
    float getGPA() {
        return gpa;
    }
    void show() {
        cout << "ID " << id << endl;
        cout << firstName << " " << lastName << endl;
        cout << "Birhtday " << date << "/" << month << "/" << year << endl;
        cout << endl;
    }
    void showStudent() {
        cout << fixed << setprecision(2);
        cout << "Student ID " << studentID << endl;
        cout << firstName << " " << lastName << endl;
        cout << "Faculy " << faculy << " Department " << department << endl;
        cout << "GPA " << gpa << endl;
        cout << endl;
    }
    static int count() {
        return num;
    }
    int findAge(int d, int m, int y); //daet current
    void findGPA(float,float,float);
    void findGPA2(float[3]);
};
int Person::findAge(int d, int m, int y) {
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
void Person::findGPA(float subj1, float subj2,float subj3) {
    gpa = (subj1 + subj2 + subj3) / 3;
}
void Person::findGPA2(float sub[3]) {
    float grade = 0;
    for (int i = 0; i < 3; i++)
        grade += sub[i];
    gpa = grade / 3;
}
int Person::num;
int main() {
    char id1[14] = "1104400004276";
    Person busnee(id1, "Chananda", "Sehwiset", 9, 11, 2002);
    char stdID1[11] = "6405001097";
    busnee.setStudent(stdID1, "Science", "Computer");
    busnee.show();
    busnee.findGPA(4, 3, 3);
    busnee.showStudent();

    char stdID2[11] = "L25101998";
    Person leeknow( "Minho", "Lee" , stdID2, "Science", "Computer");
    leeknow.show();
    float grade1[3] = { 1,3,2 };
    leeknow.findGPA2(grade1);
    leeknow.showStudent();

    Person sewoon( "Sewoon","Jeong" , "Supervision", "Musical");
    sewoon.show();
    float grade2[3] = {2.5,3,4};
    sewoon.findGPA2(grade2);
    sewoon.showStudent();

    cout << "avg " << (busnee.getGPA() + leeknow.getGPA() + sewoon.getGPA()) / 3 << endl;
    cout << busnee.getFirstName() << " " << busnee.getFaculy() << " " << busnee.getDepartment() << " " << busnee.getGPA() << endl;
}