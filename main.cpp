#include <iostream>
#include<list>
#include<algorithm>
#include <string>
#include<vector>
using namespace std;


class Student {
private:
    string name;
    string surname;
    int age;
    string email;
    string group;
public:
    void setName(string newName) {
        if (!newName.empty())
            name = newName;
        else
            throw invalid_argument("Name bos qala bilmez");
    }

    void setSurname(string newSurname) {
        if (!newSurname.empty())
            surname = newSurname;
            else
                throw invalid_argument("Surname bos qala bilmesz");
    }

    void setAge(int newAge) {
        if (newAge >= 14)
            age = newAge;
        else
            throw invalid_argument("yas minimum 14 ola biler");
    }

    void setEmail(string newEmail) {
        if (!newEmail.empty() && newEmail.find("@itstep.edu.az") != string::npos)
            email = newEmail;
        else
            throw invalid_argument("email bos qala bilme ve @itstepe mexsus olmalidir");
    }

    void setGroup(string newGroup) {
        if (!newGroup.empty())
            group = newGroup;
        else
            throw invalid_argument("Group bos qala bilmez");
    }
        string getName() const { return name; }
        string getSurname() const { return surname; }
        int getAge() const { return age; }
        string getEmail() const { return email; }
        string getGroup() const { return group; }
    void display() const {
        cout << "--------" << "Name: " << getName() << endl;
        cout << "--------" << "Surname: " << getSurname() << endl;
        cout << "--------" << "Age: " << getAge() << endl;
        cout << "--------" << "Email: " << getEmail() << endl;
        cout << "--------" << "Group: " << getGroup() << endl;
        cout <<endl << endl;
    }
    Student() = delete;
    Student(string name, string surname, int age, string email, string group) {
        setName(name);
        setSurname(surname);
        setAge(age);
        setEmail(email);
        setGroup(group);
    }
};


bool funk(Student *& a, Student *& b) {
    return a->getAge() > b->getAge();
}
int main() {
    vector<Student *> students;
    students.push_back(new Student("Amin","Ali",18,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Ali","Sariyev",19,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Murad","Mirzo",19,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Elshen","Mirzeyev",50,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Amin","Ali",20,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Kamran","Memmedov",23,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Sara","soyad",20,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Ayla","Askerova",15,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Aliya","soyad",15,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Comran","Comran",17,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Nair","Bayramli",20,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Omar","Bayramli",21,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Hesen","soyad",19,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Ilham","Quliyev",20,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Hikmet","Penahli",20,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Sehri","Aliyeva",20,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Nezrin","Abbasova",20,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Cavid","QUliyev",20,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Ziya","Hesenli",29,"aminali@itstep.edu.az","11C"));
    students.push_back(new Student("Ismayil","Elekberov",20,"aminali@itstep.edu.az","11C"));

    
//    sort(begin(students),end(students),funk);
//
//    auto enboyukyas = students.begin();
//    auto enkicikyas = prev(students.end());
//    cout << "EN yasli: " << (*enboyukyas)->getName();
//    cout << "EN cavan: " << (*enkicikyas)->getName();
//    cout << endl;
    
    auto find_deyisen = find_if(students.begin(), students.end(), [](Student*& a)->bool{return a->getAge() > 20;});
    cout << "Yasi 23 den yuxari ilk tapilan telebe: " << (*find_deyisen)->getName();
    cout << endl;
    
    int count = count_if(students.begin(), students.end(), [](Student * a)->bool{return a->getAge() > 20; });
    
    cout << "Yasi 20-den cox olan student sayi: " << count << endl;
    for(auto item: students){
        item->display();
    }
    return 0;
}
