#include <iostream>
#include <cstring>
using namespace std;

class Human
{
private:
    std::string last_name;
    std::string first_name;
    unsigned int age;

public:
    // constructors
    Human(const std::string lastname, const std::string firstname, unsigned int age)
    {
        set_lastname(lastname);
        set_firstname(firstname);
        set_age(age);
        cout << "Hconstructor\t" << this << endl;
    }

    const std::string &get_lastname() const
    {
        return last_name;
    }

    const std::string &get_firstname() const
    {
        return first_name;
    }

    unsigned int get_age() const
    {
        return age;
    }

    void set_lastname(const std::string &lastname)
    {
        this->last_name = lastname;
    }

    void set_firstname(const std::string &firstname)
    {
        this->first_name = firstname;
    }

    void set_age(unsigned int age)
    {
        this->age = age;
    }

    void print() const
    {
        cout << last_name << " " << first_name << " " << age
             << " age" << endl;
    }

    ~Human()
    {
        cout << "Hdesctructor\t" << this << endl;
    }
};

class Student : public Human
{
private:
    std::string speciality;
    std::string group;
    double rating;
    double attendace;

public:
    const std::string &get_speciality() const
    {
        return speciality;
    }
    const std::string &get_group() const
    {
        return group;
    }
    double get_rating() const
    {
        return rating;
    }
    double get_attendace() const
    {
        return attendace;
    }

    void set_speciality(const std::string &spe)
    {
        this->speciality = spe;
    }

    void set_group(const std::string &group)
    {
        this->group = group;
    }

    void set_rating(double rating)
    {
        this->rating = rating;
    }
    void set_attendace(double attendace)
    {
        this->attendace = attendace;
    }

    Student(
        const std::string lastname, const std::string firstname, unsigned int age, // human
        const std::string &speciality, const std::string &group, double rating, double attendace) : Human(lastname, firstname, age)
    {
        set_speciality(speciality);
        set_group(group);
        set_rating(rating);
        set_attendace(attendace);
        cout << "Sconstructor\t" << this << endl;
    }

    void print() const
    {
        Human::print();
        cout << speciality << " " << group << " " << rating << " " << attendace << endl;
    }

    ~Student()
    {
        cout << "Sdesctructor\t" << this << endl;
    }
};

class Teacher : public Human
{
private:
    std::string speciality;
    unsigned int experience;
    double evil;

public:
    const std::string &get_speciality() const
    {
        return speciality;
    }
    unsigned int get_experience()
    {
        return experience;
    }
    double get_evil()
    {
        return evil;
    }

    void set_speciality(const std::string &speciality)
    {
        this->speciality = speciality;
    }

    void set_experience(unsigned int experience)
    {
        this->experience = experience;
    }

    void set_evil(double evil)
    {
        this->evil = evil;
    }
    Teacher(
        const std::string last_name,
        const std::string first_name,
        unsigned int age,
        const std::string speciality,
        unsigned int experience,
        double evil) : Human(last_name, first_name, age)
    {
        set_speciality(speciality);
        set_experience(experience);
        set_evil(evil);
        cout << "Tconstructor\t" << this << endl;
    }
    void print() const
    {
        Human::print();
        cout << "Teacher " << endl;
        cout << "Speciality: " << speciality << " Experience " << experience << " evil" << evil << endl;
    }
    ~Teacher()
    {
        cout << "TDesctructor\t" << this << endl;
    }
};

class Graduate : public Student
{
private:
    std::string graduate_subject;
    unsigned int graduate_year;

public:
    const std::string &get_graduate_subject() const
    {
        return graduate_subject;
    }

    unsigned int get_graduate_year()
    {
        return graduate_year;
    }

    void set_graduate_subject(const std::string &sub)
    {
        this->graduate_subject = sub;
    }

    void set_graduate_year(unsigned int y)
    {
        this->graduate_year = y;
    }

    Graduate(
        const std::string lastname,
        const std::string firstname,
        unsigned int age, //human constructor
        const std::string &speciality,
        const std::string &group,
        double rating,
        double attendace, ///student constructor
        const std::string graduate_subject,
        unsigned int graduate_year) : Student(lastname, firstname, age, speciality, group, rating, attendace)
    {
        set_graduate_subject(graduate_subject);
        set_graduate_year(graduate_year);
        cout << "Gconstructor\t" << this << endl;
    }
    void print() const
    {
        Student::print();
        cout << "Graduate student" << endl;
        cout << "Graduate subeject --- " << graduate_subject << " "
             << "Graduate year --- " << graduate_year << endl;
    }
    ~Graduate()
    {
        cout << "Gdesctructor\t" << this << endl;
    }
};

int main()
{
    Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_123", 85, 95);
    stud.print();

    Teacher teach("Walter", "White", 50, "Chemistry", 100, 67.8);
    teach.print();

    Graduate s("Hank", "Schrader", 43, "DEA", "Police", 100, 100, "DEA", 1999);
    s.print();

    return 0;
}
