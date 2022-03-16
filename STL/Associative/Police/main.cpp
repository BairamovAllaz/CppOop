#include <iostream>
#include <cstring>
#include <map>
#include <list>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "Crime.h"
using namespace std;
void print(const std::map<std::string, std::list<Crime>> &base);
void printToFile(std::string &filename, const std::map<std::string, std::list<Crime>> &base);
void printDiapoz(const std::map<std::string, std::list<Crime>> &base);
void add(std::map<std::string, std::list<Crime>> &base);
void erase(std::map<std::string, std::list<Crime>> &base);
void load(std::map<std::string, std::list<Crime>> &base, const std::string &filename);
int main()
{
    setlocale(LC_ALL,"");
    // std::map<std::string, std::list<Crime>> base = {
    //     {"a77km", {Crime(1, "ленина"), Crime(2, "фрунзе")}},
    //     {"a55ab", {Crime(4, "Mystreet")}},
    // };
    std::map<std::string, std::list<Crime>> base;
    std::string place = "est";
    load(base, place);
    print(base);
    // add(base);
    // print(base);
    // std::string filename;
    // cout << "Enter a filename: " << endl;
    // cin.ignore();
    // std::getline(cin, filename);
    // printToFile(filename, base);
    // print(base);
    // cout << endl;

    // printDiapoz(base);
    // print(base);
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

void printToFile(std::string &filename, const std::map<std::string, std::list<Crime>> &base)
{
    std::ofstream fout(filename + ".txt");

    if (fout.is_open())
    {
        // for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
        // {
        //     fout << it->first << ":\t";
        //     for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
        //     {
        //         fout << *jt << ", ";
        //     }
        //     fout << "\n";
        // }
        for (std::pair<std::string, std::list<Crime>> i : base)
        {
            fout << i.first << ":\t";
            for (Crime j : i.second)
            {
                fout << j << ", ";
            }
            fout.seekp(-2, std::ios::cur);
            fout << ";\n";
        }
        fout.close();
    }
    else
    {
        std::cerr << "File is not founded" << endl;
    }
    std::string command = std::string("start notepad ") + filename;
    system(command.c_str());
}

void printDiapoz(const std::map<std::string, std::list<Crime>> &base)
{
    std::string a, b;
    cout << "Enter start element: ";
    cin.ignore();
    std::getline(cin, a);
    cout << "Enter end element: ";
    cin.ignore();
    std::getline(cin, b);

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

void add(std::map<std::string, std::list<Crime>> &base)
{
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
}

void erase(std::map<std::string, std::list<Crime>> &base)
{
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
}

void load(std::map<std::string, std::list<Crime>> &base, const std::string &filename)
{
    std::ifstream fin(filename + ".txt");

    if (fin.is_open())
    {
        while (!fin.eof())
        {
            std::string licence_plate;
            int id;
            std::string place;
            std::string crimes;
            char *buffer;
            std::getline(fin, licence_plate, ':');
            std::getline(fin, crimes);
            if (crimes.empty())
            {
                continue;
            }
            if (crimes.find(',') != std::string::npos)
            {
                char *dup = strdup(crimes.c_str());
                buffer = strtok(dup, ";");
                while (buffer != NULL)
                {
                    id = stoi(strtok(buffer, " "));
                    place = strtok(NULL, ",");
                    base[licence_plate].push_back(Crime(id, place));
                    buffer = strtok(NULL, ";");
                }
            }
            else
            {
                char *dup = strdup(crimes.c_str());
                id = stoi(strtok(dup, " "));
                place = strtok(dup, ";");
                base[licence_plate].push_back(Crime(id, place));
            }
        }
        fin.close();
    }
    else
    {
        std::cerr << "File is not found" << endl;
    }
}
