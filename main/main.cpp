#include<iostream>
using namespace std;
class Student
{
    char* name;
    int age;
public:
    Student();
    Student(const char* n, int a);
    Student(const Student& obj);
    ~Student();
    void Print();
    void Input();

    void SName(const char* n);
    void SAge(int a);
    const char* GName() const;
    int GAge() const;
};
Student::Student()
{
    name = nullptr;
    age = 0;
}
Student::Student(const char* n, int a)
{
    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
    age = a;
}
Student::Student(const Student& obj)
{
    name = new char[strlen(obj.name) + 1];
    strcpy_s(name, strlen(obj.name) + 1, obj.name);
    age = obj.age;
    cout << "Copy constructor\n";
}
Student::~Student()
{
    delete[] name;
    age = 0;
}
void Student::Print()
{
    cout << "Name: " << name << "Age: " << age << endl;
}
void Student::Input()
{
    char nam[100];
    cout << "Name: ";
    cin >> nam;
    name = new char[strlen(nam) + 1];
    strcpy_s(name, strlen(nam) + 1, nam);

    cout << "Age: ";
    cin >> age;
}
void Student::SName(const char* n)
{
    if (name) {
        delete[] name;
    }
    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
}
void Student::SAge(int a)
{
    age = a;
}
int Student::GAge() const
{
    return age;
}
const char* Student::GName() const
{
    return name;
}
int main()
{
    Student a("Ivan", 16);
    a.Print();
    Student b = a;
    Student c;
    c.Input();
    c.Print();
    c.SName("Zack");
    c.SAge(16);
    cout << "Name: " << c.GName() << "Age: " << c.GAge() << endl;
}

