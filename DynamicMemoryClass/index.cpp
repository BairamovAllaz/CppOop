#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char *str;
    int LengthOfString;

public:
    String(int size)
    {
        this->LengthOfString = size;
        str = new char[LengthOfString];
    }

    String()
    {
        this->LengthOfString = 80;
        this->str = new char[LengthOfString]{};
    }
    String(const char *n)
    {
        this->LengthOfString = strlen(n);
        this->str = new char[LengthOfString]{};
        strcpy(str, n);
    }

    char *getStr()
    {
        return this->str;
    }

    int getLength()
    {
        return this->LengthOfString;
    }

    void setStr(const char *str1)
    {
        this->LengthOfString = strlen(str1);
        this->str = new char[LengthOfString]{};
        strcpy(str, str1);
    }
    ostream &print(ostream &os) const
    {
        os << str << endl;
        return os;
    }

    istream &fill(istream &os)
    {
        os.getline(str, LengthOfString);
        return os;
    }

    ~String()
    {
        delete[] this->str;
    }
};

String operator+(String &left, String &right)
{
    int length = left.getLength() + right.getLength();
    char retstring[length];
    return String(strcat(left.getStr(), right.getStr()));
}

ostream &operator<<(ostream &os, const String &S)
{
    return S.print(os);
}

istream &operator>>(istream &is, String &S)
{
    return S.fill(is);
}

int main()
{
    String s;
    cout << "Nothing: " << s << endl;
    String str1 = "Hello";
    String str2 = "World";
    cout << "Str1: " << str1 << endl;
    cout << "Str2: " << str2 << endl;
    cout << "Your string: " << str1.getStr() << endl;

    String str3 = str1 + str2;
    cout << "Str3: " << str3 << endl;

    String str4;
    cout << "Enter str4: ";
    cin >> str4;
    cout << "Str4: " << str4 << endl;

    String str5(25);
    cout << "Nothing 2: " << endl;
    cout << str5 << endl;

    return 0;
}