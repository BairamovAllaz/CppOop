#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

#define EMPLOYE_TAKE_PARAMETRS const std::string last_name, const std::string first_name, const std::string work_name, unsigned int age
#define EMPLOYE_GIVEN_PARAMETRS last_name, first_name, work_name, age
class Employe
{
private:
    std::string last_name;
    std::string first_name;
    std::string work_name;
    unsigned int age;

public:
    Employe(EMPLOYE_TAKE_PARAMETRS) : last_name(last_name),
                                      first_name(first_name),
                                      work_name(work_name),
                                      age(age)
    {
        std::cout << "Constructor\t" << this << std::endl;
    }

    std::string &get_lastname()
    {
        return last_name;
    }

    std::string &get_firstname()
    {
        return first_name;
    }

    std::string &get_workname()
    {
        return work_name;
    }

    unsigned int get_age()
    {
        return age;
    }

    void set_lastname(std::string &lastname)
    {
        this->last_name = lastname;
    }

    void set_firstname(std::string &firstname)
    {
        this->first_name = firstname;
    }

    void set_workname(std::string &workname)
    {
        this->work_name = workname;
    }

    void set_age(unsigned int age)
    {
        this->age = age;
    }

    virtual std::ofstream &printtotext(std::ofstream &in)
    {
        in << last_name << ',';
        in << first_name << ',';
        in << age << ',';
        in << work_name << ',';
        return in;
    }

    virtual std::ifstream &getfromtext(std::ifstream &out)
    {
        getline(out, last_name, ',');
        getline(out, first_name, ',');
        string buffer;
        getline(out, buffer, ',');
        set_age(stoi(buffer));
        getline(out, work_name, ',');
        return out;
    }

    void print() const
    {
        cout << "Lastname: " << last_name << endl;
        cout << "Firstname: " << first_name << endl;
        cout << "Work: " << work_name << endl;
        cout << "Age: " << age << endl;
    }

    virtual int calculate_salary()
    {
        return 0;
    }

    virtual ~Employe()
    {
        std::cout << "Econstructor\t" << this << std::endl;
    }
};

class SalariedEmployee : public Employe
{
private:
    double weeklysalary;

public:
    SalariedEmployee(
        EMPLOYE_TAKE_PARAMETRS,
        double weeklysalary) : Employe(EMPLOYE_GIVEN_PARAMETRS)
    {
        setweeklysalary(weeklysalary);
        std::cout << "Salariedconstructor\t" << this << endl;
    }

    int calculate_salary() override
    {
        return weeklysalary;
    }

    double getweeklysalary()
    {
        return this->weeklysalary;
    }

    void setweeklysalary(double salary)
    {
        if (salary < 0)
        {
            salary = 0;
        }
        this->weeklysalary = salary;
    }

    std::ofstream &printtotext(std::ofstream &in)
    {
        Employe::printtotext(in);
        in << weeklysalary << ',';
        in << calculate_salary() << ',';
        return in;
    }

    std::ifstream &getfromtext(std::ifstream &out)
    {
        Employe::getfromtext(out);
        string buffer;
        getline(out, buffer, ',');
        setweeklysalary(atof(buffer.c_str()));
        return out;
    }

    void print() const
    {
        Employe::print();
        std::cout << "Weekly salary: " << weeklysalary << std::endl;
    }

    ~SalariedEmployee()
    {
        std::cout << "SalariedDesctructor\t" << this << std::endl;
    }
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
        double hours) : Employe(EMPLOYE_GIVEN_PARAMETRS)
    {
        setwage(wage);
        sethours(hours);
        std::cout << "Salariedconstructor\t" << this << endl;
    }

    double getwage()
    {
        return this->wage;
    }
    double gethours()
    {
        return this->hours;
    }

    void setwage(double wage)
    {
        if (wage < 0)
        {
            wage = 0;
        }
        this->wage = wage;
    }
    void sethours(double hour)
    {
        if (hour < 0)
        {
            hour = 0;
        }
        this->hours = hour;
    }

    int calculate_salary() override
    {
        return this->wage * this->hours;
    }

    std::ofstream &printtotext(std::ofstream &in)
    {
        Employe::printtotext(in);
        in << wage << ',';
        in << hours << ',';
        in << calculate_salary() << ',';
        return in;
    }

    std::ifstream &getfromtext(std::ifstream &out)
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

    void print() const
    {
        Employe::print();
        std::cout << "Wage: " << wage << std::endl;
        std::cout << "Hours: " << hours << std::endl;
    }

    ~HourlyEmployee()
    {
        std::cout << "SalariedDesctructor\t" << this << std::endl;
    }
};

std::ofstream &operator<<(std::ofstream &in, Employe &obj)
{
    return obj.printtotext(in);
}
std::ifstream &operator>>(std::ifstream &out, Employe& obj)
{
    return obj.getfromtext(out);
}

int main()
{
    Employe *worker[] = {
        new SalariedEmployee("John", "Actor", "Whick", 36, 10000),
        new HourlyEmployee("John1", "Actor1", "Whick1", 36, 100, 10),
        new SalariedEmployee("Michael", "Schofield", "prison break", 36, 30000),
        new HourlyEmployee("Bill", "Gates", "Bussines man", 78, 1000, 13),
    };

    int sizeA = sizeof(worker) / sizeof(worker[0]);

    ofstream writefile("Employye.txt");

    if (writefile.is_open())
    {
        for (size_t i = 0; i < sizeA; i++)
        {
            writefile << typeid(*worker[i]).name() << '*';
            writefile << *worker[i];
            writefile << ';' << endl;
        }
    }
    else
    {
        cout << "We have a problem!" << endl;
    }

    writefile.close();

    for (size_t i = 0; i < sizeA; i++)
    {
        delete worker[i];
    }

    ifstream readfile("Employye.txt");
    Employe **newworker = nullptr;
    int sizeofarray = 0;
    if (readfile.is_open())
    {

        string line;
        while (getline(readfile, line, ';'))
        {
            ++sizeofarray;
        }
        --sizeofarray;
        cout << sizeofarray << endl;

        newworker = new Employe *[sizeofarray] {};
        readfile.clear();
        readfile.seekg(0);
        for (int i = 0; i < sizeofarray + 1; i++)
        {
            std::getline(readfile, line, '*');

            if (line.find("16SalariedEmployee") != std::string::npos)
            {
                newworker[i] = new SalariedEmployee("", "", "", 0, 0);
                // cout << "S" << endl;
            }
            else if (line.find("14HourlyEmployee") != std::string::npos)
            {
                newworker[i] = new HourlyEmployee("", "", "", 0, 0, 0);
                // cout << "H" << std::endl;
            }
            readfile >> *newworker[i];
            newworker[i]->print();
            cout << endl;
        }

        readfile.close();
    }
    else
    {
        cout << "Error while opening file " << endl;
    }

    for (size_t i = 0; i < sizeofarray + 1; i++)
    {
        delete newworker[i];
    }
    delete[] newworker;
    return 0;
}