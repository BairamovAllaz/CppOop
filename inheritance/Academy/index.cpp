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
        cout << "Firstname: " << last_name << endl;
        cout << "Lastname: " << first_name << endl;
        cout << "Age: " << age << endl;
    }

    ////write to file

    virtual ofstream &printtotext(ofstream &in)
    {
        in << last_name << ",";
        in << first_name << ",";
        in << age << ",";
        return in;
    }

    virtual ifstream &takefromtext(ifstream &out)
    {
        std::getline(out, last_name, ',');
        std::getline(out, first_name, ',');
        std::string bufferage;
        std::getline(out, bufferage, ',');
        set_age(stoi(bufferage));
        // set_lastname(lastname);
        // set_firstname(firstname);
        // set_age(stoi(age));
        return out;
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
        cout << "Speciality: " << speciality << endl;
        cout << "Group: " << group << endl;
        cout << "Rating: " << rating << endl;
        cout << "Attendace: " << attendace << endl;
    }

    ofstream &printtotext(ofstream &in)
    {
        Human::printtotext(in);
        in << speciality << ",";
        in << group << ",";
        in << rating << ",";
        in << attendace << ",";
        return in;
    }

    ifstream &takefromtext(ifstream &out)
    {
        Human::takefromtext(out);
        std::getline(out, speciality, ',');
        std::getline(out, group, ',');

        std::string bufferrating, bufferattendace;

        std::getline(out, bufferrating, ',');
        std::getline(out, bufferattendace, ',');

        set_rating(atof(bufferrating.c_str()));
        set_attendace(atof(bufferattendace.c_str()));
        // set_speciality(speciality);
        // set_group(group);
        // set_rating(stoi(rating));
        // set_attendace(stoi(attendace));
        return out;
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
    void print() const override
    {
        Human::print();
        cout << "Speciality: " << speciality << endl;
        cout << "Experience: " << experience << endl;
        cout << "Evil: " << evil << endl;
    }

    ////write to file

    ofstream &printtotext(ofstream &in) override
    {
        Human::printtotext(in);
        in << speciality << ",";
        in << experience << ",";
        in << evil << ",";
        return in;
    }

    ifstream &takefromtext(ifstream &out) override
    {
        Human::takefromtext(out);
        std::getline(out, speciality, ',');
        std::string bufferexperience;
        std::getline(out, bufferexperience, ',');
        set_experience(stoi(bufferexperience));
        std::string bufferevil;
        std::getline(out, bufferevil, ',');
        set_evil(atof(bufferevil.c_str()));
        return out;
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
    void print() const override
    {
        Student::print();
        cout << "Graduate subject: " << graduate_subject << endl;
        cout << "Graduate year: " << graduate_year << endl;
    }
    ////write to file

    ofstream &printtotext(ofstream &in) override
    {
        Student::printtotext(in);
        in << graduate_subject << ",";
        in << graduate_year << ",";
        return in;
    }

    ifstream &takefromtext(ifstream &out) override
    {
        Student::takefromtext(out);
        std::getline(out, graduate_subject, ',');
        std::string buffer;
        std::getline(out, buffer, ',');
        set_graduate_year(stoi(buffer));
        return out;
    }
    ~Graduate()
    {
        cout << "Gdesctructor\t" << this << endl;
    }
};

/////////////////////////////////////
// overload operator ofstream<<
// template <typename T1, typename T2>
// ofstream &operator<<(T1 &in, T2 h)
// {
//     return h->getvalues(in);
// }
////////////////////////////////////
std::ofstream &operator<<(std::ofstream &in, Human *obj)
{
    return obj->printtotext(in);
}
std::ifstream &operator>>(std::ifstream &out, Human *obj)
{
    return obj->takefromtext(out);
}
// #define INHERITANCE_CHECK
// #define FILE_OPERATIONS

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

    #ifdef FILE_OPERATIONS
    
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
    ////write to file
    int size = sizeof(group) / sizeof(group[0]);

    // write array to file
    ofstream writefile("Academy.txt", std::ios::out);
    if (writefile.is_open())
    {
        for (int i = 0; i < size; ++i)
        {
            writefile << typeid(*group[i]).name() << "*" << endl;
            writefile << group[i];
            writefile << '-' << endl;
        }
    }
    else
    {
        cout << "Error while opening file" << endl;
    }
    writefile.close();

    for (int i = 0; i < size; i++)
    {
        delete group[i];
    }
    ////read data from file solution 1

    // ifstream readfile("Academy.txt");
    // string line;
    // if (readfile.is_open())
    // {
    //     while (getline(readfile, line))
    //     {
    //         cout << line << endl;
    //         // cout << readfile.tellg() << endl;
    //     }
    //     readfile.close();
    // }
    // else
    // {
    //     cout << "Error while opening file!!!!" << endl;
    // }

    /// read data from any file solution 2
    cout << endl;
    std::streampos begin, end;
    ifstream read("Academy.txt", std::ios::in | std::ios::binary);

    // 2d array object
    // https://stackoverflow.com/questions/45176135/c-how-do-i-create-a-dynamic-array-of-objects-inherited-from-an-abstract-class
    // http://www.functionx.com/bcb/articles/dynarray.htm
    Human **groupfromfile = nullptr;
    int groupsize = 0;

    if (read.is_open())
    {
        //string documentation
        //https://en.cppreference.com/w/cpp/string/basic_string
        string line;
        //getline documentation
        //https://www.geeksforgeeks.org/getline-string-c/
        while (getline(read, line, '-'))
        {
            ++groupsize;
        }
        --groupsize;
        cout << groupsize << endl;

        /// https://www.cplusplus.com/doc/tutorial/files/
        begin = read.tellg();
        read.clear();
        read.seekg(0); //change reading location to 0
        groupfromfile = new Human *[groupsize] {};
        for (int i = 0; i < groupsize; i++)
        {
            std::getline(read, line, '*');

            /// string find
            // https://www.geeksforgeeks.org/string-find-in-cpp/

            if (line.find("7Student") != string::npos)
            {
                groupfromfile[i] = new Student("", "", 0, "", "", 0, 0);
                // cout << "Type student success " << endl;
            }
            else if (line.find("7Teacher") != string::npos)
            {
                groupfromfile[i] = new Teacher("", "", 0, "", 0, 0);
                // cout << "Type teacher success " << endl;
            }
            else if (line.find("8Graduate") != string::npos)
            {
                groupfromfile[i] = new Graduate("", "", 0, "", "", 0, 0, "", 0);
                // cout << "Type graduate success " << endl;
            }

            read >> groupfromfile[i];
            groupfromfile[i]->print();
            cout << endl;
        }
        read.seekg(0, std::ios::end);
        end = read.tellg();

        read.close();
        std::cout << std::endl;
        std::cout << "Size of this file: " << (end - begin) << " binary" << std::endl;
    }
    else
    {
        std::cout << "Problem when opening group " << std::endl;
    }

    for (int i = 0; i < groupsize; i++)
    {
        delete groupfromfile[i];
    }
    #endif // DEBUG

    cout << "Hello world" << endl; 
    return 0;
}