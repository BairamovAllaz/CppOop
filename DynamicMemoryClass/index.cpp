#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char *str = new char[80]{};
public:
    String(/* const char *Pstr */)
    {
        // strcpy(str, Pstr);
    }
    void setStr(const char *str1)
    {
        strcpy(str, str1);
    }
    void print()
    {
        cout << str << endl;
    }
    ~String()
    {
        delete[] str;
    }
};
int main()
{
    // char arr[80];
    // cin.getline(arr, 80);
    String s;
    s.print();

    return 0;
}