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
    //constructors
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
        const std::string lastname, const std::string firstname, unsigned int age, //human
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

int main()
{
    Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_123", 85, 95);
    stud.print();
    return 0;
}
