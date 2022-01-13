#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// #define WRITE_TO_FILE
#define READ_FROM_FILE

int main()
{
#ifdef WRITE_TO_FILE
    std::cout << "Hello world" << std::endl;
    ofstream fout("file.txt", ios::app); // ios::app append for all time
    fout << "Hello world" << endl;
    fout.close();

    system("code file.txt");
#endif // DEBUG

    #ifdef READ_FROM_FILE
    
        cerr << "Fuck you is true" << endl;

    // const int SIZE = 256;
    // char buffer[SIZE] = {};
    std::string buffer;
    ifstream fin;
    int line = 0;
    fin.open("file.txt");

    if(fin.is_open()) { 

        /////read file
        while (!fin.eof())  ///eof - end of file
        {
            getline(fin,buffer);
            cout << buffer << endl;
            ++line;
        }
    }else{ 
        cerr << "File not found" << endl;
    }

    cout <<"Size of line: " << line << endl;

    fin.close();
    #endif // DEBUG


    return 0;
}