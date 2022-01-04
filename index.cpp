#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{

    ifstream read("group.txt");

    string line;
    int size = 0;
    while (getline(read, line, ';'))
    {
        ++size;
    }
    cout << size << endl;

    read.clear();
    read.seekg(0);

    for (size_t i = 0; i < size; i++)
    {
        std::getline(read, line, '*');
        cout << line << endl;
        if (line.find("7Student") != std::string::npos)
        {
            cout << "Yeah this is hello world" << endl;
        }

        std::getline(read, line, ';');
        std::getline(read, line, ',');
        cout << "L: " << line;
        // std::getline(read,line,',');
    }

    read.close();

    return 0;
}