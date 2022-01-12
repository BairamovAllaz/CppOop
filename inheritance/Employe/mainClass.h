#pragma once
#include "stdrfx.h"
#define EMPLOYE_TAKE_PARAMETRS const std::string last_name, const std::string first_name, const std::string work_name, unsigned int age
#define EMPLOYE_GIVEN_PARAMETRS last_name, first_name, work_name, age

class Employe;

std::ofstream &operator<<(std::ofstream &in, Employe &obj);
std::ifstream &operator>>(std::ifstream &out, Employe &obj);

class Employe
{
private:
    std::string last_name;
    std::string first_name;
    std::string work_name;
    unsigned int age;

public:
    Employe(EMPLOYE_TAKE_PARAMETRS);
    std::string &get_lastname();
    std::string &get_firstname();
    std::string &get_workname();
    unsigned int get_age();
    void set_lastname(std::string &lastname);
    void set_firstname(std::string &firstname);
    void set_workname(std::string &workname);
    void set_age(unsigned int age);
    virtual std::ofstream &printtotext(std::ofstream &in);
    virtual std::ifstream &getfromtext(std::ifstream &out);
    virtual void print() const;
    virtual int calculate_salary();
    virtual ~Employe();
};

class SalariedEmployee : public Employe
{
private:
    double weeklysalary;

public:
    SalariedEmployee(
        EMPLOYE_TAKE_PARAMETRS,
        double weeklysalary);

    int calculate_salary() override;
    double getweeklysalary();
    void setweeklysalary(double salary);

    std::ofstream &printtotext(std::ofstream &in);

    std::ifstream &getfromtext(std::ifstream &out);
    void print() const;

    ~SalariedEmployee();
};

class HourlyEmployee : public Employe
{

private:
    double wage;  // wage per hour;
    double hours; // hours worked for wheek;

public:
    HourlyEmployee(
        EMPLOYE_TAKE_PARAMETRS,
        double wage,
        double hours);

    double getwage();
    double gethours();

    void setwage(double wage);
    void sethours(double hour);
    int calculate_salary() override;

    std::ofstream &printtotext(std::ofstream &in);
    std::ifstream &getfromtext(std::ifstream &out);
    void print() const;
    ~HourlyEmployee();
};
