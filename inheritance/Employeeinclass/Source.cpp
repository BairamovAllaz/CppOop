#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
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

    Human() {
        set_lastname("");
        set_firstname(""); 
        set_age(0);
    }

    const std::string& get_lastname() const
    {
        return last_name;
    }

    const std::string& get_firstname() const
    {
        return first_name;
    }

    unsigned int get_age() const
    {
        return age;
    }

    void set_lastname(const std::string& lastname)
    {
        this->last_name = lastname;
    }

    void set_firstname(const std::string& firstname)
    {
        this->first_name = firstname;
    }

    void set_age(unsigned int age)
    {
        this->age = age;
    }

   virtual std::ostream& print(std::ostream& out) const
    {
        out << left;
        out.width(10);
        out << last_name;
        out.width(10);
        out << first_name;
        out.width(3);
        out << age <<  " age";
        return out;
    }

   virtual std::ofstream& print(std::ofstream& os) const
   {
        os << left;
        os.width(10);
        os << last_name;
        os.width(10);
        os << first_name;
        os.width(3);
        os << age;
        return os;
   }

   virtual std::ifstream& scan(std::ifstream &os) {
       os >> last_name >> first_name >> age;
       return os;
   }

   virtual std::istream& enter(std::istream &in) {
        cout << "Enter lastname: ";
        in >> last_name; 
        cout << "Enter firstname: ";
        in >> first_name;
        cout << "Enter age: "; 
        in >> age;
        return in;
    } 

    virtual ~Human()
    {
        cout << "Hdesctructor\t" << this << endl;
    }
};

std::ostream& operator<<(std::ostream& out, const Human& obj)
{
    return obj.print(out);
}

std::istream& operator>>(std::istream& in, Human& obj) {
    return obj.enter(in);
}

std::ofstream& operator<<(std::ofstream& os, const Human& obj) {
    return obj.print(os);
}

std::ifstream& operator>>(std::ifstream& is,Human& obj) {
    return obj.scan(is);
}

#define EMPLOYEE_TAKE_PARAMETRS const std::string &position
#define EMPLOYEE_GIVEN_PARAMETRS position

class Employee : public Human
{
private:
    std::string position;

public:
    const std::string& get_position() const
    {
        return position;
    }
    void set_position(const std::string& position)
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

    Employee() :Human() {
        set_position("");
    }

    std::ostream& print(std::ostream& out) const
    {
        Human::print(out);
        out << left; 
        out.width(10);
        out << right;
        out << position << " ";
        return out;
    } 
    std::ofstream& print(std::ofstream& out) const
    {
        Human::print(out) << " ";
        out.width(10);  
        out << position;
        return out;
    }

    std::istream& enter(std::istream& in) {
         Human::enter(in);
         cout << "Enter position: ";
         in >> position;
         return in;
     }


    std::ifstream& scan(std::ifstream& is) {
        Human::scan(is);
        is >> position; 
        return is;
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


    Permanent() : Employee() {
        this->salary = double();
    }

    std::ostream& print(std::ostream& out) const
    {
        Employee::print(out);
        out << left;
        out.width(10);
        out << right;
        out << salary << " ";
        return out;
    } 
    std::ofstream& print(std::ofstream& out) const
    {
        Employee::print(out) << " ";
        out.width(10);
        out << right;
        out << salary;
        return out;
    }

    std::istream& enter(std::istream& in) {
        Employee::enter(in);
        cout << "Enter salary: ";
        in >> salary;
        return in;
    }

    std::ifstream& scan(std::ifstream& is) {
        Employee::scan(is);
        is >> salary;
        return is;
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
    double hours;

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

    double get_hours() const
    {
        return hours;
    }

    void set_hours(double hours)
    {
        this->hours = hours;
    }

    std::ostream& print(std::ostream& out) const
    {
        Employee::print(out);
        out << " rate:";
        out.width(5);
        out << right;
        out << rate;
        //out << left;
        out << ", hours";
        out.width(3);
        out << hours << ", salary:" << get_salary();
        return out;
    } 
    
    std::ofstream& print(std::ofstream& out) const
    {
        Employee::print(out);
        out.width(10);   
        out << right;
        out << rate;
        out.width(3);
        out << hours;
        return out;
    }

    std::istream& enter(std::istream& in) {
        Employee::enter(in);
        cout << "Enter rate: ";
        in >> rate;
        cout << "Enter hours: ";
        in >> hours;
        return in;
    }

    std::ifstream& scan(std::ifstream& os) {
        Employee::scan(os);
        os >> rate >> hours;
        return os;
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

    HourlyEmployee() : Employee() {
        this->rate = double();
        this->hours = double();
    }


    ~HourlyEmployee()
    {
        cout << "Pdesctructor\t" << this << endl;
    }
};

Employee* EmployeeFactory(const string& type) {
    if (type.find("class Permanent") != std::string::npos) {
        return new Permanent("", "", 0, "", 0);
    }
    if (type.find("class HourlyEmployee") != std::string::npos) {
        return new HourlyEmployee("", "", 0, "", 0, 0);
    }
}

//#define DEPARTMANENT_CHECK
int main()
{

#ifdef DEPARTMANENT_CHECK

    Employee* department[] = {
        new Permanent("Rosenberg", "Ken", 30, "Lawyer", 2000),
        new Permanent("Diaz", "Ricardo", 50, "Boss", 50000),
        new HourlyEmployee("Vercetty", "Tomas", 30, "Security", 500, 8),
    };

    double total_salary = 0;
    cout << "\n-------------------------------------\n";
    for (size_t i = 0; i < sizeof(department) / sizeof(Employee*); i++)
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
   
    ofstream fout("file.txt");
    for (size_t i = 0; i < sizeof(department) / sizeof(department[0]); i++)
    {
        fout.width(25);
        fout << left;
        fout << string(typeid(*department[i]).name()) + ":";
        fout << *department[i] << endl;
    }

    fout.close();
    
    system("start notepad file.txt");
    for (size_t i = 0; i < sizeof(department) / sizeof(Employee*); i++)
    {
        delete department[i];
    }
#endif // DEPARTMANENT_CHECK

   Employee** department = nullptr;
   int n = 0; //size of array;
   ifstream fin("file.txt");
       if (fin.is_open()) {
            std::string employee_type;

           for (;!fin.eof();n++)
           {
                std::getline(fin, employee_type);
           }
            n--;
            cout << n << endl;
            department = new Employee * [n] {};
            cout << fin.tellg() << endl;
            fin.clear();
            fin.seekg(0);
            cout << fin.tellg() << endl;

            for (int i = 0; i < n; i++)
            {
                getline(fin, employee_type, ':');
                department[i] = EmployeeFactory(employee_type);
                fin >> *department[i];
                cout << *department[i] << endl;
            }

        }else{
            cout << "File is not found" << endl;
        }

       for (int i = 0; i < n; i++)
       {
           delete department[i];
       }
       delete[] department;
    fin.close();
    return 0;
}
