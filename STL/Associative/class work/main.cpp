#include <iostream>
#include <cstring>
#include <map>
#include <list>
#include <fstream>
#include "Crime.h"
using namespace std;

void print(const std::map<std::string, std::list<Crime>> &base);
void printToFile(const std::map<std::string, std::list<Crime>> &base);
void printDiapoz(const std::string &a, const std::string &b, const std::map<std::string, std::list<Crime>>);
int main()
{
    std::map<std::string, std::list<Crime>> base = {
        {"a77km", {Crime(1, "ленина"), Crime(2, "фрунзе")}},
        {"a55ab", {Crime(4, "Mystreet")}},
    };
    print(base);
    int id;
    std::string licence_place;
    std::string place;
    cout << "Enter number car : ";
    cin.clear();
    cin.ignore();
    std::getline(cin, licence_place);
    cout << "Enter nomer law ";
    cin >> id;
    cout << "Enter place: ";
    cin.clear();
    cin.ignore();
    std::getline(cin, place);

    base[licence_place].push_back(Crime(id, place));
    print(base);

    printToFile(base);

    std::string key;
    cout << "Enter a car number to delete: ";
    cin.clear();
    cin.ignore();
    std::getline(cin, key);
    std::map<std::string, std::list<Crime>>::iterator it = base.find(key);
    if (it != base.end())
    {
        base.erase(it);
        cout << "Car is deleted!!!" << endl;
    }
    else
    {
        std::cerr << "there not this car!" << endl;
    }

    print(base);

    cout << endl;
    std::string a, b;
    cout << "Enter start element: ";
    // cin >> a;
    cin.ignore();
    std::getline(cin, a);
    cout << "Enter end element: ";
    // cin >> b;
    cin.ignore();
    std::getline(cin, b);

    printDiapoz(a, b, base);

    return 0;
}

void print(const std::map<std::string, std::list<Crime>> &base)
{

    for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
    {
        cout << it->first + ":\n";
        for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
        {
            cout << "\t" << *jt << ";" << endl;
        }
        cout << "\n------------------------------------\n";
    }
}

void printToFile(const std::map<std::string, std::list<Crime>> &base)
{
    std::ofstream fout("Base.txt");

    if (fout.is_open())
    {
        for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
        {
            fout << it->first << " : ";
            for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
            {
                fout << *jt << endl;
            }
            fout << endl;
        }
        fout.close();
    }
    else
    {
        std::cerr << "File is not founded" << endl;
    }
}

void printDiapoz(const std::string &a, const std::string &b, const std::map<std::string, std::list<Crime>> &base)
{
    for (std::map<std::string, std::list<Crime>>::const_iterator it = base.lower_bound(a); it != base.upper_bound(b); ++it)
    {
        cout << it->first + ":/n";
        for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
        {
            cout << "\t" << *jt << ";" << endl;
        }
        cout << endl;
    }
}
