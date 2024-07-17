#include <iostream>
using namespace std;
class Date {
private:
    int day, month, year;
public:
    Date() {
        set(0, 0, 0);
        //show();
    }
    Date(int d, int m, int y) {
        set(d, m, y);
        //show();
    }
    ~Date() {
        cout << "bye Date" << endl;
    }
    void set(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
    void show() {
        cout << day << "/" << month << "/" << year << endl;
    }
};
class Address {
private:
    string houseNo, road, district, subdistrict, province, postCode;
public:
    Address() {
        string temp = "none";
        set("-", temp, temp, temp, temp, temp);
        cout << "Add" << endl;
    }
    Address(string no, string r, string d, string subd, string pro, string post) {
        set(no, r, d, subd, pro, post);
        cout << "Add" << endl;
    }
    ~Address() {
        cout << "bye address" << endl;
    }
    void set(string no, string r, string d, string subd, string pro, string post) {
        houseNo = no;
        road = r;
        district = d;
        subdistrict = subd;
        province = pro;
        postCode = post;
    }
    Address getAddress() { return *this; }
    void set(Address add) {
        set(add.houseNo, add.road, add.district, add.subdistrict, add.province,
            add.postCode);
    }
    void show() {
        cout << houseNo << " road " << road << " district " << district << " sub-district "
            << subdistrict << " province " << province << " " << postCode << endl;
    }
};
class Person {
private:
    string id;
    string firstName, lastName;
    Date birthday;
    Address address;
public:
    Person() {
        setID("1111111111111");
        setName("Firstname", "Lastname");
        //show();
    }
    Person(string id, string fname, string lname, int d, int m, int y, Address add) {
        set(id, fname, lname, d, m, y, add);
        //show();
    }
    Person(string id, string fname, string lname, Date birth, Address add) {
        setID(id);
        setName(fname, lname);
        birthday = birth;
        address = add;
        //show();
    }
    ~Person() {
        cout << "bye Person" << endl;
    }
    void set(string id, string fname, string lname, int d, int m, int y, Address add) {
        setID(id);
        setName(fname, lname);
        birthday.set(d, m, y);
        address.set(add);
    }
    void setID(string id) {
        this->id = id;
    }
    void setName(string fname, string lname) {
        firstName = fname;
        lastName = lname;
    }
    void setBirthday(int d, int m, int y) {
        birthday.set(d, m, y);
    }
    void setAddress(Address add) {
        address.set(add);
    }
    void setBirthday(Date bd) {
        birthday.set(bd.getDay(), bd.getMonth(), bd.getYear());
    }
    string getID() { return id; }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    Date getBirthday() { return birthday; }
    Address getAddress() { return address; }
    void show() {
        cout << "ID : " << id << endl;
        cout << "Name : " << firstName << " " << lastName << endl;
        cout << "Birthday : " << birthday.getDay() << "/" << birthday.getMonth() << "/"
            << birthday.getYear() << endl;
        address.show();
    }
};
class Student :virtual public Person {
private:
    string studentID;
    string faculty, department;
public:
    Student() {
        set("1111111111", "none faculty", "none department");
        //show();
    }
    Student(string stdID, string f, string d) {
        set(stdID, f, d);
        //show();
    }
    Student(string id, string fname, string lname, int d, int m, int y, string stdID,
        string fac, string de, Address add) : Person(id, fname, lname, d, m, y, add) {
        set(stdID, fac, de);
    }
    ~Student() {
        cout << "bye Student" << endl;
    }
    string getStudentID() { return studentID; }
    string getFaculty() { return faculty; }
    string getDepartment() { return department; }
    void set(string stdID, string f, string d) {
        studentID = stdID;
        faculty = f;
        department = d;
    }
    void show() {
        cout << "Student ID : " << studentID << endl;
        cout << "Faculty : " << faculty << endl;
        cout << "Department : " << department << endl;
    }
    void show2() {
        Person::show();
        show();
    }
};
class Teacher :virtual public Person {
private:
    string teacherID;
    string faculty, department;
public:
    Teacher() {
        set("1111111111", "none faculty", "none department");
        //show();
    }
    Teacher(string tID, string f, string d) {
        set(tID, f, d);
        //show();
    }
    Teacher(string id, string fname, string lname, int d, int m, int y, string tID,
        string fac, string de, Address add) : Person(id, fname, lname, d, m, y, add) {
        set(tID, fac, de);
    }
    ~Teacher() {
        cout << "bye teacher" << endl;
    }
    string getTeacherID() { return teacherID; }
    string getFaculty() { return faculty; }
    string getDepartment() { return department; }
    void set(string tID, string f, string d) {
        teacherID = tID;
        faculty = f;
        department = d;
    }
    void show() {
        cout << "Teacher ID : " << teacherID << endl;
        cout << "Faculty : " << faculty << endl;
        cout << "Department : " << department << endl;
    }
    void show2() {
        Person::show();
        show();
    }
};
class TeachingAssistant :public Student,public Teacher {
    Person teacher;
    string subject;     //วิชาที่สอน
    int day;           //วันที่สอน จ.-ศ.
public:
    TeachingAssistant() {
        set("none subject", 0);
    }
    TeachingAssistant(string id, string fname, string lname, int d, int m, int y,
        string stdID, string stdFaculty, string stdDepart, Address add, Person t, 
        string tID, string tFaculty, string tDepartment, string subject,int day)
        :Student( stdID, stdFaculty, stdDepart),Teacher(tID,tFaculty,tDepartment),
        Person(id,fname,lname,d,m,y,add) {
        teacher = t;
        set(subject, day);
    }
    ~TeachingAssistant() {
        cout << "bye teaching assistant" << endl;
    }
    string getSubject() { return subject; }
    int getDay() { return day; }
    void set(string subject, int day) {
        this->subject = subject;
        setDay(day);
    }
    void setTeacher(string id, string fname, string lname, int d, int m, int y, Address add) {
        teacher.Person::set(id, fname, lname, d, m, y, add);
    }
    void setDay(int day) {
        this->day = (day < 1 || day>5) ? 0 : day;
    }
    void showDay() {
        switch (day) {
        case 1:cout << "Monday";    break;
        case 2:cout << "Tuesday";   break;
        case 3:cout << "Wednesday"; break;
        case 4:cout << "Thursday";  break;
        case 5:cout << "Friday";    break;
        default:cout << "-";
        }
    }
    void show() {
        cout << "Teaching Assistant info" << endl;
        Student::show2();
        cout << endl;
        cout << "Teacher info" << endl;
        teacher.show();
        Teacher::show();
        cout << endl;
        cout << "Teaching info" << endl;
        cout << "Subject : " << subject << endl;
        cout << "Day : "; showDay();
        cout << endl;
    }
};
int main()
{
    Date d1, d2(9, 11, 2002);       cout << endl;
    Address a1, a2("4", "ram 118 33-3", "sapansung", "sapansung", "bankok", "10240");
    a1.show();  a2.show();  cout << endl;
    Person p1, p2("1104400004276", "Chananda", "Sehwiset", d2, a2);
    p1.show();  p2.show();  cout << endl;
    a1.set("8", "skz", "jyp", "ent.", "sol", "2510");
    Person p3("2510199812345", "Lee", "Minho", 25, 10, 1998, a1);
    p3.show();  cout << endl;
    Student s1, s2("6405001097", "Scince", "Computer");
    s1.show();  s2.show();  cout << endl;
    Teacher t1, t2("3105199712", "Scince", "Bio");
    t1.show();  t2.show();  cout << endl;

    //s2.setPerson(p2);
    s2.Person::show();
    s2.show();  cout << endl;
    Address a3;
    a3.set("31", "a", "b", "c", "d", "1997");
    t2.Person::set("3105199712345", "Jeong", "Sewoon", 31, 5, 1997, a3);
    t2.Person::show();
    t2.show();          cout << endl;

    Student n1("1104400004276", "Chananda", "Sehwiset", 9, 11, 2002, "6405001097", "Scince",
        "Computer", a2);
    //n1.Person::show();
    cout << "----" << endl;
    n1.show2();  cout << endl;
    Teacher m1("3105199712345", "Jeong", "Sewoon", 31, 5, 1997, "3105199712", "Scince", "Math", a3);
    //m1.Person::show();
    m1.show2();  cout << endl;

    cout << "---------------- - 7.2-------------------" << endl;

    TeachingAssistant ta1("1104400004276", "Chananda", "Sehwiset", 9, 11, 2002, "6405001097", "Scince",
        "Computer", a2, t2, "3105199712", "Scince", "Math", "mth1000", 3);
    ta1.show();

    TeachingAssistant ta2;
    ta2.show();

    ta2.Person::set("2510199812345", "Lee", "Minho", 25, 10, 1998, a1);
    ta2.Student::set("2510100812", "Scince", "Math");
    ta2.setTeacher("3105199712345", "Jeong", "Sewoon", 31, 5, 1997,a3);
    ta2.Teacher::set("3105199712", "Scince", "Math");
    ta2.set("MTH0002", 1);
    ta2.show();
}