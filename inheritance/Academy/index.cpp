#include <iostream>
#include <cstring>
#include <fstream>
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

    virtual void print() const
    {
        cout << last_name << " " << first_name << " " << age
             << " age" << endl;
    }
    
     ////write to file
    virtual ofstream &getvalues(ofstream &in)
    {
        in << "Lastname: " << last_name << endl;
        in << "Firstname: " << first_name << endl;
        in << "age: " << age << endl;
        return in;
    }

    virtual ~Human()
    {
        cout << "Hdesctructor\t" << this << endl;
    }
};

#define STUDENT_TAKE_PARAMETRS const std::string &speciality, const std::string &group, double rating, double attendace
#define STUDENT_GIVEN_PARAMETRS speciality, group, rating, attendace
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
        HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS) : Human(HUMAN_GIVEN_PARAMETRS)
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
    ofstream &getvalues(ofstream &in)
    {
        Human::getvalues(in);
        in << "Speciality: " << speciality << endl;
        in << "Group: " << group << endl;
        in << "Rating: " << rating << endl;
        in << "attendace: " << attendace << endl;
        return in;
    }

    ~Student()
    {
        cout << "Sdesctructor\t" << this << endl;
    }
};

#define TEACHER_TAKE_PARAMETRS const std::string speciality, unsigned int experience, double evil
#define TEACHER_GIVEN_PARAMETRS speciality, experience, evil
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
        HUMAN_TAKE_PARAMETRS,
        TEACHER_TAKE_PARAMETRS) : Human(HUMAN_GIVEN_PARAMETRS)
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

     ////write to file
    ofstream &getvalues(ofstream &in)
    {
        Human::getvalues(in);
        in << "Speciality: " << speciality << endl;
        in << "Exprience: " << experience << endl;
        in << "Evil: " << evil << endl;
        return in;
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
        HUMAN_TAKE_PARAMETRS,
        STUDENT_TAKE_PARAMETRS,
        const std::string graduate_subject,
        unsigned int graduate_year) : Student(HUMAN_GIVEN_PARAMETRS, STUDENT_GIVEN_PARAMETRS)
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


    ////write to file
    ofstream &getvalues(ofstream &in)
    {
        Student::getvalues(in);
        in << "Graduate subject: " << graduate_subject << endl;
        in << "Graduate year: " << graduate_year << endl;
        return in;
    }


    ~Graduate()
    {
        cout << "Gdesctructor\t" << this << endl;
    }
};
// #define INHERITANCE_CHECK

/////////////////////////////////////
//overload operator ofstream<<
template <typename T1, typename T2>
ofstream &operator<<(T1 &in, T2 h)
{
    return h->getvalues(in);
}
////////////////////////////////////


int main()
{
#ifdef INHERITANCE_CHECK
    Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_123", 85, 95);
    stud.print();

    Teacher teach("Walter", "White", 50, "Chemistry", 100, 67.8);
    teach.print();

    Graduate s("Hank", "Schrader", 43, "DEA", "Police", 100, 100, "DEA", 1999);
    s.print();
#endif // DEBUG
    Human *group[] = {
        new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_123", 85, 95),
        new Teacher("Walter", "White", 50, "Chemistry", 100, 67.8),
        new Graduate("Hank", "Schrader", 43, "DEA", "Police", 100, 100, "DEA", 1999),
        new Student("Vercetti", "Tomas", 30, "City Bussines", "Vice", 98, 99),
        new Teacher("Diaz", "Ricardo", 25, "Weapons distribiton", 100, 30),
        new Student("Monatana", "Antonio", 30, "Criminalistic", "Vice", 90, 80),
        new Teacher("Walter", "White", 50, "Chemistry", 100, 67.8),
        new Graduate("Hank", "Schrader", 43, "DEA", "Police", 100, 100, "DEA", 1999),
    };

    int size = sizeof(group) / sizeof(group[0]);

    //write array to file
    ofstream writefile("Academy.txt");
    if (writefile.is_open())
    {
        for (int i = 0; i < size; ++i)
        {
            writefile << group[i] << endl;
        }
    }
    else
    {
        cout << "Error while opening file" << endl;
    }
    writefile.close();

    /// read text from file
    cout << endl;
    ifstream readfile("Academy.txt");
    string line;
    if (readfile.is_open())
    {
        while (getline(readfile, line))
        {
            cout << line << endl;
        }
        readfile.close();
    }
    else
    {
        cout << "Error while opening file!!!!" << endl;
    }
    for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
    {
        delete group[i];
    }
    return 0;
}