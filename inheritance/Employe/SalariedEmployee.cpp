#include "mainClass.h"

SalariedEmployee::SalariedEmployee(
    EMPLOYE_TAKE_PARAMETRS,
    double weeklysalary) : Employe(EMPLOYE_GIVEN_PARAMETRS)
{
    setweeklysalary(weeklysalary);
    std::cout << "Salariedconstructor\t" << this << endl;
}

int SalariedEmployee::calculate_salary()
{
    return weeklysalary;
}

double SalariedEmployee::getweeklysalary()
{
    return this->weeklysalary;
}

void SalariedEmployee::setweeklysalary(double salary)
{
    if (salary < 0)
    {
        salary = 0;
    }
    this->weeklysalary = salary;
}

std::ofstream &SalariedEmployee::printtotext(std::ofstream &in)
{
    Employe::printtotext(in);
    in << weeklysalary << ',';
    in << calculate_salary() << ',';
    return in;
}

std::ifstream &SalariedEmployee::getfromtext(std::ifstream &out)
{
    Employe::getfromtext(out);
    string buffer;
    getline(out, buffer, ',');
    setweeklysalary(atof(buffer.c_str()));
    return out;
}

void SalariedEmployee::print() const
{
    Employe::print();
    std::cout << "Salary: " << weeklysalary << std::endl;
}

SalariedEmployee::~SalariedEmployee()
{
    std::cout << "SalariedDesctructor\t" << this << std::endl;
}