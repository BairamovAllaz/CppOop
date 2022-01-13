#include <iostream>
#include <cstring>
using namespace std;
#define HUMAN_TAKE_PARAMETRS const std::string lastname, const std::string firstname, unsigned int age
#define HUMAN_GIVEN_PARAMETRS lastname, firstname, age
class Human
{
private:
    std::string last_name;
    std::string first_name;
    unsigned int age;

public:
    // constructors
    Human(HUMAN_TAKE_PARAMETRS)
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

    std::ostream &print(std::ostream &out) const
    {
        out << "Firstname: " << last_name << endl;
        out << "Lastname: " << first_name << endl;
        out << "Age: " << age << endl;
        out << endl;
        return out;
    }

    virtual ~Human()
    {
        cout << "Hdesctructor\t" << this << endl;
    }
};

#define EMPLOYEE_TAKE_PARAMETRS const std::string &position
#define EMPLOYEE_GIVEN_PARAMETRS position

class Employee : public Human
{
private:
    std::string position;

public:
    const std::string &get_position() const
    {
        return position;
    }
    void set_position(const std::string &position)
    {
        this->position = position;
    }

    virtual double get_salary() const = 0;

    Employee(HUMAN_TAKE_PARAMETRS, EMPLOYEE_TAKE_PARAMETRS) : Human(HUMAN_GIVEN_PARAMETRS)
    {
        set_position(position);
        cout << "Econstructor\t"
             << this << endl;
    }

    virtual std::ostream &print(std::ostream &out) const
    {
        Human::print(out);
        out << "Position " << position << endl;
        out << endl;
        return out;
    }

    virtual ~Employee()
    {
        cout << "Edesctructor\t" << this << endl;
    }
};

#define PERMANENT_TAKE_PARAMETRS double salary
#define PERMANENT_GIVE_PARAMETRS salary

class Permanent : public Employee
{
private:
    double salary;

public:
    double get_salary() const
    {
        return salary;
    }
    void set_salary(double salary)
    {
        this->salary = salary;
    }

    Permanent(
        HUMAN_TAKE_PARAMETRS,
        EMPLOYEE_TAKE_PARAMETRS,
        PERMANENT_TAKE_PARAMETRS) : Employee(HUMAN_GIVEN_PARAMETRS, EMPLOYEE_GIVEN_PARAMETRS)
    {
        this->salary = salary;
        cout << "Pconstructor: \t" << this << endl;
    }

    std::ostream &print(std::ostream &out) const
    {
        Employee::print(out);
        out << "Salary " << salary << endl;
        out << endl;
        return out;
    }

    ~Permanent()
    {
        cout << "Pdesctructor: \t" << this << endl;
    }
};

#define HOURLY_EMPLOYE_TAKE_PARAMETRS double rate, int hours
#define HOURLY_EMPLOYE_GIVE_PARAMETRS rate, hours

class HourlyEmployee : public Employee
{
private:
    double rate;
    int hours;

public:
    double get_rate() const
    {
        return rate;
    }

    void set_rate(double rate)
    {
        this->rate = rate;
    }

    double get_salary() const
    {
        return rate * hours;
    }

    int get_hours() const
    {
        return hours;
    }

    void set_hours(double hours)
    {
        this->hours = hours;
    }

    std::ostream &print(std::ostream &out) const
    {
        Employee::print(out);
        out << "Rate " << rate << endl;
        out << "Hours " << hours << endl;
        out << endl;
        return out;
    }

    HourlyEmployee(
        HUMAN_TAKE_PARAMETRS,
        EMPLOYEE_TAKE_PARAMETRS,
        HOURLY_EMPLOYE_TAKE_PARAMETRS) : Employee(HUMAN_GIVEN_PARAMETRS, EMPLOYEE_GIVEN_PARAMETRS)
    {
        this->rate = rate;
        this->hours = hours;
        cout << "Pconstructor: \t" << this << endl;
    }

    ~HourlyEmployee()
    {
        cout << "Pdesctructor\t" << this << endl;
    }
};

std::ostream &operator<<(std::ostream &out, const Employee &obj)
{
    return obj.print(out);
}



int main()
{
    Employee *department[] = {
        new Permanent("Rosenberg", "Ken", 30, "Lawyer", 2000),
        new Permanent("Diaz", "Ricardo", 50, "Boss", 50000),
        new HourlyEmployee("Vercetty", "Tomas", 30, "Security", 500, 8),
    };

    int size = sizeof(department) / sizeof(Employee *);

    double total_salary = 0;
    cout << "\n-------------------------------------\n";
    for (size_t i = 0; i < size; i++)
    {
        // department[i]->print();
        cout << typeid(*department[i]).name() << endl;
        // if (typeid(*department[i]) == typeid(Permanent))
        // {
        //     cout << *dynamic_cast<Permanent*>(department[i]) << endl;
        // }
        // if (typeid(*department[i]) == typeid(HourlyEmployee))
        // {
        //     cout << *dynamic_cast<HourlyEmployee*>(department[i]) << endl;
        // }
        // cout << *department[i] << endl;
        cout << *department[i] << endl;
        total_salary += department[i]->get_salary();
        cout << "\n-------------------------------------\n";
    }
    cout << "Total salary: " << total_salary << endl;
    cout << "\n-------------------------------------\n";

    for (size_t i = 0; i < size; i++)
    {
        delete department[i];
    }

    return 0;
}