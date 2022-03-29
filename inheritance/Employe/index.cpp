#include "mainClass.h"
#include "Employee.cpp"
#include "SalariedEmployee.cpp"
#include "HourlyEmployee.cpp"
int main()
{
    Employe *worker[] = {
        new SalariedEmployee("John", "Actor", "Whick", 36, 10000),
        new HourlyEmployee("John1", "Actor1", "Whick1", 36, 100, 10),
        new SalariedEmployee("Michael", "Schofield", "prison break", 36, 30000),
        new HourlyEmployee("Bill", "Gates", "Bussines man", 78, 1000, 13),
        new HourlyEmployee("Elon", "Musk", "Bussines man", 78, 2000, 15),
    };

    int sizeA = sizeof(worker) / sizeof(worker[0]);
    int netincomesalary = 0;
    ofstream writefile("Employye.txt");

    if (writefile.is_open())
    {
        for (size_t i = 0; i < sizeA; i++)
        {
            writefile << typeid(*worker[i]).name() << '*';
            writefile << *worker[i];
            writefile << ';' << endl;
            netincomesalary += worker[i]->calculate_salary();
        }
        writefile << netincomesalary << ",";
    }
    else
    {
        cout << "We have a problem!" << endl;
    }

    writefile.close();

    ifstream readfile("Employye.txt", std::ios::in | std::ios::binary);
    streampos end, begin;
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

        begin = readfile.tellg();
        readfile.clear();
        readfile.seekg(0);
        newworker = new Employe *[sizeofarray] {};
        for (int i = 0; i < sizeofarray; i++)
        {
            std::getline(readfile, line, '*');

            if (line.find("16SalariedEmployee") != string::npos)
            {
                newworker[i] = new SalariedEmployee("", "", "", 0, 0);
                // cout << "S" << endl;
            }
            else if (line.find("14HourlyEmployee") != string::npos)
            {
                newworker[i] = new HourlyEmployee("", "", "", 0, 0, 0);
                // cout << "H" << std::endl;
            }
            readfile >> *newworker[i];
            newworker[i]->print();
            cout << endl;
            string buffer;
            std::getline(readfile, buffer, ',');
            cout << "Net income Employe: " << buffer;
        }

        readfile.seekg(0, std::ios::end);
        end = readfile.tellg();
        cout << "Size of this file: " << (end - begin) << " byte" << endl;
        readfile.close();
    }
    else
    {
        cout << "Error while opening file " << endl;
    }
    for (size_t i = 0; i < sizeofarray; i++)
    {
        delete newworker[i];
    }
    for (size_t i = 0; i < sizeA; i++)
    {
        delete worker[i];
    }

    return 0;
}