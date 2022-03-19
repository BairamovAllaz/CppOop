#include <iostream>
#include <cstring>
#include <map>
#include <list>
#include <fstream>
#include <string>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <chrono>
#include "Crime.h"
using namespace std;
using std::cin;
using std::cout;
using std::endl;
void print(const std::map<std::string, std::list<Crime>> &base);
void printLaws(const std::map<std::string, std::list<Crime>> &base, size_t lawNum);
void printToFile(std::string &filename, const std::map<std::string, std::list<Crime>> &base);
void printDiapoz(const std::map<std::string, std::list<Crime>> &base);
void add(std::map<std::string, std::list<Crime>> &base);
void erase(std::map<std::string, std::list<Crime>> &base);
void load(std::map<std::string, std::list<Crime>> &base, const std::string &filename);
void print(const std::map<std::string, std::list<Crime>> &base, const std::string &licence_plate_first,
           const std::string &licence_plate_last);
int main()
{
    setlocale(LC_ALL, "");
    std::map<std::string, std::list<Crime>> base = {
        {"a77km", {Crime(1, "ленина"), Crime(2, "фрунзе")}},
        {"a55ab", {Crime(4, "Mystreet")}},
        {"a52", {Crime(1, "Mystreet2")}},
    };
    // std::map<std::string, std::list<Crime>> base;
    
    int operation;
    cout << "1: Insert Element , 2: Print Element, 3: Print By Laws , 4 : Print diapozan,5: erase , 6 : write to file , 7  : Read from file! , 8 : exit ";
    cin >> operation;
    while (operation > 8)
    {
        cout << "Enter operation again" << endl;
        cin >> operation;
    }

    while (true)
    {
        if (operation == 8)
        {
            break;
        }

        switch (operation)
        {
        case 1:
        {
            add(base);
            break;
        }
        case 2:
        {
            print(base);
            break;
        }
        case 3:
        {
            int lawnumber;
            cout << "Enter a law number: ";
            cin >> lawnumber;
            printLaws(base, lawnumber);
            break;
        }
        case 4:
        {
            printDiapoz(base);
        }

        case 5:
        {
            erase(base);
            break;
        }
        case 6:
        {
            std::string filename;
            cout << "Enter a filename: " << endl;
            cin.ignore();
            std::getline(cin, filename);
            printToFile(filename, base);
            break;
        }
        case 7:
        {
            std::string place;
            cout << "Enter a filename:";
            cin.ignore();
            std::getline(cin, place);
            load(base, place);
            print(base);
            break;
        }

        default:
            break;
        }
        cout << "1: Insert Element , 2: Print Element, 3: Print By Laws , 4 : Print diapozan,5: erase , 6 : write to file , 7  : Read from file! , 8 : exit ";
        cin >> operation;
    }

    return 0;
}

void print(const std::map<std::string, std::list<Crime>> &base)
{
    for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
    {
        std::cout << it->first + ":\n";
        for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
        {
            std::cout << "\t" << *jt << ";" << endl;
        }
        std::cout << "\n------------------------------------\n";
    }
}

void printLaws(const std::map<std::string, std::list<Crime>> &base, size_t lawNum)
{
    for (std::map<std::string, std::list<Crime>>::const_iterator it = base.begin(); it != base.end(); ++it)
    {
        std::list<Crime>::const_iterator findLaw = std::find_if(it->second.begin(), it->second.end(), [&](const Crime &crime)
                                                                { return crime.get_id() == lawNum; });
        if (findLaw != it->second.end())
        {
            std::cout << it->first + ":\n";
            for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
            {
                std::cout << "\t" << *jt << ";" << std::endl;
            }
        }
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
    std::cout << "Enter start element: ";
    std::cin.ignore();
    std::getline(cin, a);
    std::cout << "Enter end element: ";
    cin.ignore();
    std::getline(cin, b);

    for (std::map<std::string, std::list<Crime>>::const_iterator it = base.lower_bound(a); it != base.upper_bound(b); ++it)
    {
        std::cout << it->first + ":/n";
        for (std::list<Crime>::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
        {
            std::cout << "\t" << *jt << ";" << endl;
        }
        std::cout << endl;
    }
}

void add(std::map<std::string, std::list<Crime>> &base)
{
    int id;
    std::string licence_place;
    std::string place;
    std::cout << "Enter number car : ";
    cin.clear();
    cin.ignore();
    std::getline(cin, licence_place);
    std::cout << "Enter nomer law ";
    cin >> id;
    std::cout << "Enter place: ";
    cin.clear();
    cin.ignore();
    std::getline(cin, place);
    base[licence_place].push_back(Crime(id, place));
}

void erase(std::map<std::string, std::list<Crime>> &base)
{
    std::string key;
    std::cout << "Enter a car number to delete: ";
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

// void load(std::map<std::string, std::list<Crime>> &base, const std::string &filename)
// {
//     std::ifstream fin(filename + ".txt");

//     if (fin.is_open())
//     {
//         while (!fin.eof())
//         {
//             int id;
//             std::string licence_plate;
//             std::string place;
//             std::string crimes;
//             std::string date;
//             char *buffer;
//             std::getline(fin, licence_plate, ':');
//             std::getline(fin, crimes);
//             if (crimes.empty())
//             {
//                 continue;
//             }
//             if (crimes.find(',') != std::string::npos)
//             {
//                 char *dup = strdup(crimes.c_str());
//                 buffer = strtok(dup, ";");
//                 while (buffer != NULL)
//                 {
//                     id = stoi(strtok(buffer, " "));
//                     place = strtok(buffer, " ");
//                     date = strtok(NULL, ",");
//                     base[licence_plate].push_back(Crime(id, place));
//                     buffer = strtok(NULL, ";");
//                 }
//             }
//             else
//             {
//                 char *dup = strdup(crimes.c_str());
//                 id = stoi(strtok(dup, " "));
//                 place = strtok(dup, " ");
//                 date = strtok(dup, ";");
//                 base[licence_plate].push_back(Crime(id, place));
//             }
//         }
//         fin.close();
//     }
//     else
//     {
//         std::cerr << "File is not found" << endl;
//     }
// }

void load(std::map<std::string, std::list<Crime>> &base, const std::string &file_name)
{
    std::ifstream fin(file_name + ".txt");
    if (fin.is_open())
    {
        while (!fin.eof())
        {
            std::string licence_plate;
            int id;

            std::string place;
            std::string crimes;
            std::getline(fin, licence_plate, ':');
            std::getline(fin, crimes);
            if (crimes.empty())
                continue;
            char *sz_crimes = new char[crimes.size() + 1];
            std::strcpy(sz_crimes, crimes.c_str());
            char sz_delimiters[] = ",;";
            for (char *pch = strtok(sz_crimes, sz_delimiters); pch; pch = strtok(NULL, sz_delimiters))
            {
                id = std::atoi(pch);
                while (*pch == ' ')
                    pch++;
                pch = std::strchr(pch, ' ') + 1;
                if (std::find(base[licence_plate].begin(), base[licence_plate].end(), Crime(id, pch)) == base[licence_plate].end())
                    base[licence_plate].push_back(Crime(id, pch));
            }
            delete[] sz_crimes;
        }
        fin.close();
    }
    else
    {
        std::cerr << "Error: file not found" << endl;
    }
}

void print(const std::map<std::string, std::list<Crime>> &base, const std::string &licence_plate_first,
           const std::string &licence_plate_last)
{
    try
    {
        for (std::map<std::string, std::list<Crime>>::const_iterator it = base.lower_bound(licence_plate_first);
             it != base.upper_bound(licence_plate_last);
             ++it)
        {
            cout << it->first << " : \n";
            for (std::list<Crime>::const_iterator jt = it->second.begin();
                 jt != it->second.end(); ++jt)
            {
                cout << *jt << endl;
            }
        }
    }
    catch (...)
    {
        std::cerr << "Error";
    }
}