#include "mainClass.h"

HourlyEmployee::HourlyEmployee(
    EMPLOYE_TAKE_PARAMETRS,
    double wage,
    double hours) : Employe(EMPLOYE_GIVEN_PARAMETRS)
{
    setwage(wage);
    sethours(hours);
    std::cout << "Hourlyconstructor\t" << this << endl;
}

double HourlyEmployee::getwage()
{
    return this->wage;
}
double HourlyEmployee::gethours()
{
    return this->hours;
}

void HourlyEmployee::setwage(double wage)
{
    if (wage < 0)
    {
        wage = 0;
    }
    this->wage = wage;
}
void HourlyEmployee::sethours(double hour)
{
    if (hour < 0)
    {
        hour = 0;
    }
    this->hours = hour;
}

int HourlyEmployee::calculate_salary()
{
    return this->wage * this->hours;
}

std::ofstream &HourlyEmployee::printtotext(std::ofstream &in)
{
    Employe::printtotext(in);
    in << wage << ',';
    in << hours << ',';
    in << calculate_salary() << ',';
    return in;
}

std::ifstream &HourlyEmployee::getfromtext(std::ifstream &out)
{
    Employe::getfromtext(out);
    string buffer1;
    getline(out, buffer1, ',');
    setwage(atof(buffer1.c_str()));
    string buffer2;
    getline(out, buffer2, ',');
    sethours(atof(buffer2.c_str()));
    return out;
}

void HourlyEmployee::print() const
{
    Employe::print();
    std::cout << "Wage: " << wage << std::endl;
    std::cout << "Hours: " << hours << std::endl;
}

HourlyEmployee::~HourlyEmployee()
{
    std::cout << "HourlyDesctructor\t" << this << std::endl;
}