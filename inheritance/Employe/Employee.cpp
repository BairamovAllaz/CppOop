#include "mainClass.h"

#define EMPLOYE_TAKE_PARAMETRS const std::string last_name, const std::string first_name, const std::string work_name, unsigned int age
#define EMPLOYE_GIVEN_PARAMETRS last_name, first_name, work_name, age

std::ofstream &operator<<(std::ofstream &in, Employe &obj)
{
    return obj.printtotext(in);
}
std::ifstream &operator>>(std::ifstream &out, Employe &obj)
{
    return obj.getfromtext(out);
}

Employe::Employe(EMPLOYE_TAKE_PARAMETRS) : last_name(last_name),
                     first_name(first_name),
                     work_name(work_name),
                     age(age)
{
    std::cout << "Constructor\t" << this << std::endl;
}

std::string &Employe::get_lastname()
{
    return last_name;
}
std::string &Employe::get_firstname()
{
    return first_name;
}

std::string &Employe::get_workname()
{
    return work_name;
}

unsigned int Employe::get_age()
{
    return age;
}

void Employe::set_firstname(std::string &firstname)
{
    this->first_name = first_name;
}

void Employe::set_lastname(std::string &lastname)
{
    this->last_name = last_name;
}

void Employe::set_workname(std::string &workname)
{
    this->work_name = work_name;
}

void Employe::set_age(unsigned int age)
{
    this->age = age;
}

std::ofstream &Employe::printtotext(std::ofstream &in)
{
    in << last_name << ',';
    in << first_name << ',';
    in << age << ',';
    in << work_name << ',';
    return in;
}
std::ifstream &Employe::getfromtext(std::ifstream &out)
{
    getline(out, last_name, ',');
    getline(out, first_name, ',');
    string buffer;
    getline(out, buffer, ',');
    set_age(stoi(buffer));
    getline(out, work_name, ',');
    return out;
}

void Employe::print() const
{
    cout << "Lastname: " << last_name << endl;
    cout << "Firstname: " << first_name << endl;
    cout << "Work: " << work_name << endl;
    cout << "Age: " << age << endl;
}

int Employe::calculate_salary()
{
    return 0;
}

Employe::~Employe()
{
    std::cout << "Econstructor\t" << this << std::endl;
}