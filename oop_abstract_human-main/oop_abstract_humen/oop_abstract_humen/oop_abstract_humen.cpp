#include <iostream>
using namespace std;

class Human {
private:
    string name;
    int age;
    string country;
public:
    Human() : name(name), age(0), country(country){}
    Human(string n, int age, string c) : name(n), age(age), country(country) {
        this->name = n;
        this->age = age;
        this->country = c;
    }

    virtual void Show() {
        cout << "\nHUMAN:\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Country: " << country << endl;
    }

};

class Tutor : public Human {
private:
    string nameTutor;
    string niche;
public:
    Tutor(string name, int age, string country, string nameTutor, string niche)
        : Human(name, age, country), niche(niche), nameTutor(nameTutor)
    {
        this->niche = niche;
        this->nameTutor = nameTutor;
    }

    void Show() override {
        Human::Show();
        cout << "Niche tutor: " << niche << endl;
        cout << "Name tutor: " << nameTutor << endl;
    }

};

class Learner : public Human {
private:
    string institution;
    string niche;
public:
    Learner(string name, int age, string country, string niche, string institution)
        : Human(name, age, country), niche(niche), institution(institution)
    {
        this->niche = niche;
        this->institution = institution;
    }

    void Show() override {
        Human::Show();
        cout << "Niche tutor: " << niche << endl;
        cout << "Name institution: " << institution << endl;
    }

};

class SchoolChild : public Learner {
private:
    int clas;
public:
    SchoolChild(string name, int age, string country, string niche, string institution, int clas)
        : Learner(name, age, country, niche, institution), clas(clas)
    {
        this->clas = clas;
    }

    void Show() override {
        Learner::Show();
        cout << "Clas: " << clas << endl;
    }
};

class Student : public Learner {
private:
    int course;
public:
    Student(string name, int age, string country, string niche, string institution, int course)
        : Learner(name, age, country, niche, institution), course(course)
    {
        this->course = course;
    }

    void Show() override {
        Learner::Show();
        cout << "Course: " << course << endl;
    }
};

class Employee : public Human {
private:
    string work;
    int experience;
public:
    Employee(string name, int age, string country, string work, int experience)
        : Human(name, age, country), work(work), experience(experience)
    {
        this->work = work;
        this->experience = experience;
    }

    void Show() override {
        Human::Show();
        cout << "Work place: " << work << endl;
        cout << "Experience: " << experience << " year/s" << endl;
    }

};

class Scientist : public Employee {
private:
    string science;
    int numProjects;
public:
    Scientist(string name, int age, string country, string work, int experience, string science, int numProjects)
        : Employee(name, age,country, work, experience), science(science), numProjects(numProjects) {
        this->science = science;
        this->numProjects = numProjects;
    }

    void Show() override {
        Employee::Show();
        cout << "Science: " << science << endl;
        cout << "Number projects: " << numProjects << endl;
    }

};

class Manager : public Employee {
private:
    string company;
public:
    Manager(string name, int age, string country, string work, int experience, string company)
        : Employee(name, age, country, work, experience), company(company){
        this->company = company;
    }

    void Show() override {
        Employee::Show();
        cout << "Company: " << company << endl;
    }

};

class Specialist : public Employee {
private:
    string niche;
public:
    Specialist(string name, int age, string country, string work, int experience, string niche)
        : Employee(name, age, country, work, experience), niche(niche) {
        this->niche = niche;
    }

    void Show() override {
        Employee::Show();
        cout << "Niche: " << niche << endl;
    }

};

int main()
{
    Human p("Vlad", 16, "Ukraine");

    p.Show();

    Specialist s("Vlad", 16, "Ukraine", "Specialist", 3, "transportains");

    s.Show();

}