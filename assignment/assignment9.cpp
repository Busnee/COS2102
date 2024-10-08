#include <iostream>
using namespace std;
class Date {
private:
    int *day, month, year;
public:
    Date() {
        day = new int;
        set(0, 0, 0);
    }
    Date(int d, int m, int y) {
        day = new int;
        set(d, m, y);
    }
    ~Date() {
        delete day;
        cout << "bye Date" << endl;
    }
    void set(int d, int m, int y) {
        *day = d;
        month = m;
        year = y;
    }
    int getDay() { return *day; }
    int getMonth() { return month; }
    int getYear() { return year; }
    void show() {
        cout << *day << "/" << month << "/" << year << endl;
    }
    Date& operator=( Date& d) {
        if (this == &d) return *this;
        *day = d.getDay();
        month = d.month;
        year = d.year;
        return *this;
    }
    Date(Date& d) {
        day = new int;
        *day = d.getDay();
        month = d.month;
        year = d.year;
    }
    void print(ostream& os) {
        os<< *day << "/" << month << "/" << year << endl;
    }
    void input(istream& is) {
        cout << "Enter Day ";    is >> *day;
        cout << "Enter Month ";  is >> month;
        cout << "Enter Year ";   is >> year;
    }
};
ostream& operator<<(ostream& os, Date& d) {
    d.print(os);
    return os;
}
istream& operator>>(istream& is, Date& d) {
    d.input(is);
    return is;
}
class Address { 
private:
    string houseNo, road, district, subdistrict, province, *postCode;
public:
    Address() {
        string temp = "none";
        postCode = new string;
        set("-", temp, temp, temp, temp, temp);
    }
    Address(string no, string r, string d, string subd, string pro, string post) {
        postCode = new string;
        set(no, r, d, subd, pro, post);
    }
    ~Address() {
        delete postCode;
        cout << "bye address" << endl;
    }
    void set(string no, string r, string d, string subd, string pro, string post) {
        houseNo = no;
        road = r;
        district = d;
        subdistrict = subd;
        province = pro;
        *postCode = post;
    }
    Address& get() { return *this; }
    string getPostCode() { return *postCode; }
    void set(Address& add) {
        set(add.houseNo, add.road, add.district, add.subdistrict, add.province,
            add.getPostCode());
    }
    void show() {
        cout << houseNo << " road " << road << " district " << district << " sub-district "
            << subdistrict << " province " << province << " " << *postCode << endl;
    }
    Address& operator=(Address& a) {
        if (this == &a) return *this;
        set(a);
        return *this;
    }
    Address(Address& a) {
        postCode = new string;
        set(a);
    }
    void input(istream& is) {
        cout << "Enter House No. "; is >> houseNo;
        cout << "Enter Road "; is >> road;
        cout << "Enter District "; is >> district;
        cout << "Enter Subdistrict "; is >> subdistrict;
        cout << "Enter Province "; is >> province;
        cout << "Enter Post code "; is >> *postCode;
    }
    void print(ostream& os) {
        os << houseNo << " road " << road << " district " << district << " sub-district "
            << subdistrict << " province " << province << " " << *postCode << endl;
    }
};
ostream& operator<<(ostream& os, Address& a) {
    a.print(os);
    return os;
}
istream& operator>> (istream& is, Address& a) {
    a.input(is);
    return is;
}
class Person {  
private:
    string id;
    string firstName, lastName;
    Date *birthday;
    Address address;
public:
    Person() {
        birthday = new Date(0,0,0);
        setID("1111111111111");
        setName("Firstname", "Lastname");
    }
    Person(string id, string fname, string lname, int d, int m, int y, Address& add) {
        birthday = new Date;
        set(id, fname, lname, d, m, y, add);
    }
    ~Person() {
        delete birthday;
        cout << "bye Person" << endl;
    }
    void set(string id, string fname, string lname, int d, int m, int y, Address& add) {
        setID(id);
        setName(fname, lname);
        birthday->set(d, m, y);
        address = add;
    }
    void setID(string id) {
        this->id = id;
    }
    void setName(string fname, string lname) {
        firstName = fname;
        lastName = lname;
    }
    string getID() { return id; }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    Date getBirthday() { return *birthday; }
    Address& getAddress() { return address; }
    void show() {
        cout << "ID : " << id << endl;
        cout << "Name : " << firstName << " " << lastName << endl;
        cout << "Birthday : "; birthday->show();
        address.show();
    }
    Person& operator=( Person& p) {
        if (this == &p)    return *this;
        id = p.id;
        firstName = p.firstName;
        lastName = p.lastName;
        birthday->set(p.birthday->getDay(), p.birthday->getMonth(), p.birthday->getYear());
        address = p.address;
        return *this;
    }
    Person(Person& p) {
        id = p.id;
        firstName = p.firstName;
        lastName = p.lastName;
        birthday = new Date(p.birthday->getDay(), p.birthday->getMonth(), p.birthday->getYear());
        address = p.address;
    }
    void print(ostream& os) {
        os << "ID : " << id << endl;
        os << "Name : " << firstName << " " << lastName << endl;
        birthday->show();
        address.print(os);
    }
    void input(istream &is) {
        cout << "Enter ID "; is >> id;
        cout << "Enter First name"; is >> firstName;
        cout << "Enter Last name";  is >> lastName;
        birthday->input(is);
        address.input(is);
    }
};
ostream& operator<<(ostream& os, Person& p) {
    p.print(os);
    return os;
}
istream& operator >> (istream& is, Person& p) {
    p.input(is);
    return is;
}
class Student :virtual public Person {
private:
    char *studentID;
    string faculty, department;
public:
    Student() {
        char stdID[11] = "1111111111";
        setStdID(stdID);
        faculty = "none";
        department = "none";
    }
    Student(char* stdID, string f, string d) {
        set(stdID, f, d);
    }
    Student(string id, string fname, string lname, int d, int m, int y, char* stdID,
        string fac, string de, Address& add) : Person(id, fname, lname, d, m, y, add) {
        set(stdID, fac, de);
    }
    ~Student() {
        cout << "bye Student" << endl;
    }
    string getStudentID() { return studentID; }
    string getFaculty() { return faculty; }
    string getDepartment() { return department; }
    void set(char* stdID, string f, string d) {
        setStdID(stdID);
        faculty = f;
        department = d;
    }
    void setStdID(char *i) {
        if (studentID != 0)
            delete studentID;
        studentID = new char[11];
        strcpy_s(studentID,11, i);
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
    Student& operator=(Student& s) {
        if (this == &s) return *this;
        Person::operator=(s);
        faculty = s.faculty;
        department = s.department;
        if (studentID != 0)
            delete studentID;
        studentID = new char[strlen(s.studentID) + 1];
        strcpy_s(studentID, strlen(s.studentID) + 1, s.studentID);
        return *this;
    }
    Student(Student& s) :Person(s.getID(), s.getFirstName(), s.getLastName(), s.getBirthday().getDay(), s.getBirthday().getMonth(),
        s.getBirthday().getYear(), s.getAddress().get()) {
        faculty = s.faculty;
        department = s.department;
        studentID = new char[strlen(s.studentID) + 1];
        strcpy_s(studentID, strlen(s.studentID) + 1, s.studentID);
    }
    void print(ostream& os) {
        Person::print(os);
        os << "Student ID : " << studentID << endl;
        os << "Faculty : " << faculty << endl;
        os << "Department : " << department << endl;
    }
    void input(istream& is) {
        Person::input(is);
        cout << "Enter Student ID ";    is >> studentID;
        cout << "Enter Faculty ";       is >> faculty;
        cout << "Enter Department ";    is >> department;
    }
};
ostream& operator<<(ostream& os, Student& s) {
    s.print(os);
    return os;
}
istream& operator>>(istream& is, Student& s) {
    s.input(is);
    return is;
}
class Teacher :virtual public Person {
private:
    string *teacherID;
    string faculty, department;
public:
    Teacher() {
        teacherID = new string;
        *teacherID = "0000000000";
        faculty = "none";
        department = "none";
    }
    Teacher(string tID, string f, string d) {
        teacherID = new string;
        set(tID, f, d);
    }
    Teacher(string id, string fname, string lname, int d, int m, int y, string tID,
        string fac, string de, Address& add) : Person(id, fname, lname, d, m, y, add) {
        teacherID = new string;
        set(tID, fac, de);
    }
    ~Teacher() {
        delete teacherID;
        cout << "bye teacher" << endl;
    }
    string getTeacherID() { return *teacherID; }
    string getFaculty() { return faculty; }
    string getDepartment() { return department; }
    void set(string tID, string f, string d) {
        *teacherID = tID;
        faculty = f;
        department = d;
    }
    void show() {
        cout << "Teacher ID : " << *teacherID << endl;
        cout << "Faculty : " << faculty << endl;
        cout << "Department : " << department << endl;
    }
    void show2() {
        Person::show();
        show();
    }
    Teacher& operator=(Teacher& t) {
        if (this == &t) return *this;
        Person::operator=(t);
        faculty = t.faculty;
        department = t.department;
        *teacherID = t.getTeacherID();
        return *this;
    }
    Teacher(Teacher& t) :Person(t.getID(), t.getFirstName(), t.getLastName(), t.getBirthday().getDay(), t.getBirthday().getMonth(),
        t.getBirthday().getYear(), t.getAddress().get()) {
        faculty = t.faculty;
        department = t.department;
        teacherID = new string;
        *teacherID = t.getTeacherID();
    }
    void print(ostream& os) {
        Person::print(os);
        os << "Teacher ID : " << *teacherID << endl;
        os << "Faculty : " << faculty << endl;
        os << "Department : " << department << endl;
    }
    void input(istream& is) {
        Person::input(is);
        cout << "Enter Student ID ";    is >> *teacherID;
        cout << "Enter Faculty ";       is >> faculty;
        cout << "Enter Department ";    is >> department;
    }
};
ostream& operator<<(ostream& os, Teacher& t) {
    t.print(os);
    return os;
}
istream& operator>>(istream& is, Teacher& t) {
    t.input(is);
    return is;
}
class TeachingAssistant :public Student, public Teacher {
    Person *teacher;
    string subject;     //วิชาที่สอน
    int day;           //วันที่สอน จ.-ศ.
public:
    TeachingAssistant() {   //....
        teacher = new Person;
        set("none subject", 0);
    }
    TeachingAssistant(string id, string fname, string lname, int d, int m, int y,
        char* stdID, string stdFaculty, string stdDepart, Address& add, Person& t,
        string tID, string tFaculty, string tDepartment, string subject, int day)
        :Student(stdID, stdFaculty, stdDepart), Teacher(tID, tFaculty, tDepartment),
        Person(id, fname, lname, d, m, y, add) {
        teacher = new Person(t);
        set(subject, day);
    }
    ~TeachingAssistant() {
        delete teacher;
        cout << "bye teaching assistant" << endl;
    }
    string getSubject() { return subject; }
    int getDay() { return day; }
    Person& getTeacher() { return *teacher; }
    void set(string subject, int day) {
        this->subject = subject;
        setDay(day);
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
        teacher->show();
        Teacher::show();
        cout << endl;
        cout << "Teaching info" << endl;
        cout << "Subject : " << subject << endl;
        cout << "Day : "; showDay();
        cout << endl;
    }
    TeachingAssistant& operator=(TeachingAssistant& ta) {
        if (this == &ta) return *this;
        Student::operator=(ta);
        Teacher::set(ta.getTeacherID(), ta.Teacher::getFaculty(), ta.Teacher::getDepartment());
        subject = ta.subject;
        day = ta.day;
        *teacher = ta.getTeacher();
        return *this;
    }
    TeachingAssistant(TeachingAssistant& ta){
        Student::operator=(ta);
        Teacher::set(ta.getTeacherID(), ta.Teacher::getFaculty(), ta.Teacher::getDepartment());
        subject = ta.subject;
        day = ta.day;
        teacher = new Person(ta.getTeacher());
    }
    void print(ostream& os) {
        os << "**Teaching Assistant info**" << endl;
        Student::show2();
        os << "**Teacher info**" << endl;
        teacher->show();
        Teacher::show();
        os << "**Teaching info**" << endl;
        os << "Subject : " << subject << endl;
        os << "Day : "; showDay();
        os << endl;
    }
    void input(istream& is) {
        cout << "student info" << endl;
        Student::input(is);
        cout << "teacher info" << endl;
        Teacher::input(is);
        cout << "Enter subject ";    is >> subject;
        cout << "Enter day ";        is >> day;
    }
};
ostream& operator<<(ostream& os, TeachingAssistant& ta) {
    ta.print(os);
    return os;
}
istream& operator>>(istream& is, TeachingAssistant& ta) {
    ta.input(is);
    return is;
}
int main()
{
    cout << "------class Date-------" << endl;
    Date d1(9, 11, 2002), d2 = d1, d3;
    cout << d1 << d2 << endl;
    d2.set(25, 10, 1998);
    d3 = d2;
    cout << d2 << d3;
    cout << "--------class Address-----" << endl;
    Address a1("4", "ram 118 33-3", "sapansung", "sapansung", "bankok", "10240"), a2 = a1, a3;
    cout << a1 << a2 << endl;
    a2.set("8", "a", "b", "c", "d", "8888");
    a3 = a2;
    cout << a2 << a3;
    cout << "-------class Person-------" << endl;
    Person p1("1104400004276", "Chananda", "Sehwiset", 9, 11, 2002, a1);
    Person p2=p1;
    cout << p1 << endl << p2 << endl;
    p2.set("2510199812345", "Lee", "Minho", 25, 10, 1998, a2);
    Person p3 = p2;
    p3 = p2;
    cout << p2 << endl << p3;
    cout << "---------class Student-----------" << endl;
    char c[11] = "6405001097";
    Student s1("1104400004276", "Chananda", "Sehwiset", 9, 11, 2002, c, "Scince", "Computer", a1), s2;
    s2 = s1;
    cout << s1 << endl << s2 << endl;
    s2.setName("busnee","seh.");
    Student s3 = s2;
    cout << s2 << endl << s3;
    cout << "------------class Teacher----------" << endl;
    Teacher t1("2510199812345", "Lee", "Minho", 25, 10, 1998, "2510199812", "Scince", "Math", a2);
    Teacher t2 = t1,t3;
    cout << t1 << endl << t2 << endl;
    t2.setName("Lee", "Know");
    t3 = t2;
    cout << t2 << endl << t3;
    cout << "----------class TeachingAssistant----------" << endl;
    //TeachingAssistant ta;
    //cout << ta << endl;
    TeachingAssistant ta1("1104400004276", "Chananda", "Sehwiset", 9, 11, 2002, c, "Scince", "Computer", a1, t1, "1234567890",
        "Scince", "Math", "MTH1000", 3);
    TeachingAssistant ta2 = ta1;
    cout << ta1 << endl;
    cout<< ta2 << endl;
    ta2.setDay(5);
    TeachingAssistant ta3;
    ta3 = ta2;
    cout << 2;
    cout << ta2 << endl << ta3;
    cout << "------end------" << endl;
}