#include <iostream>
#include <cstring>
using namespace std;

class String
{
    char *str;
    int LengthOfString;

public:
    explicit String(int size)
    {
        this->LengthOfString = size;
        this->str = new char[LengthOfString]{};
    }

    String()
    {
        this->LengthOfString = 80;
        this->str = new char[LengthOfString]{};
        cout << "Constructor\t " << this << endl;
    }
    String(const char *str)
    {
        this->LengthOfString = strlen(str) + 1;
        this->str = new char[LengthOfString]{};
        strcpy(this->str, str);
        // for (size_t i = 0;n[i]; i++)
        // {
        //     this->str[i] = n[i];
        // }
    }

    //deep copy
    String(const String &other)
    {
        this->LengthOfString = other.LengthOfString;
        this->str = new char[LengthOfString]{};
        strcpy(str, other.getStr());
        // for (size_t i = 0;str[i]; i++)
        // {
        //     this->str[i] = other.str[i];
        // }
    }

    ///get methods
    const char *getStr() const
    {
        return this->str;
    }

    char *getStr()
    {
        return this->str;
    }

    int getLength() const
    {
        return this->LengthOfString;
    }

    //set methods
    void setStr(const char *str1)
    {
        this->LengthOfString = strlen(str1) + 1;
        this->str = new char[LengthOfString]{};
        strcpy(str, str1);
    }

    //overload operator =
    String &operator=(const String &other)
    {
        if (this == &other)
            return *this; // String s3("Hello world") !(    s3 = s3    );
        delete[] this->str;
        this->LengthOfString = other.LengthOfString;
        this->str = new char[LengthOfString]{};
        strcpy(str, other.getStr());
        // for (size_t i = 0; str[i]; i++)
        // {
        //     this->str[i] = other.str[i];
        // }
        cout << "CopyAssigment\t" << this << endl;
        return *this;
    }

    //overload ostream
    ostream &print(ostream &os) const
    {
        os << "Size\t" << LengthOfString << endl;
        os << "String\t" << str << endl;
        return os;
    }

    ///overload istream
    istream &fill(istream &os)
    {
        os.getline(str, LengthOfString);
        return os;
    }

    ///desctructor
    ~String()
    {
        delete[] this->str;
        cout << "Desctructor\t " << this << endl;
    }
};

String operator+(const String left, const String right)
{
    // return String(strcat(left.getStr(), right.getStr()));
    String result(left.getLength() + right.getLength() - 1);
    for (size_t i = 0; i < left.getLength(); i++)
    {
        result.getStr()[i] = left.getStr()[i];
    }
    for (size_t i = 0; i < right.getLength(); i++)
    {
        result.getStr()[i + left.getLength() - 1] = right.getStr()[i];
    }
    return result;
}

ostream &operator<<(ostream &os, const String &S)
{
    return S.print(os);
}

istream &operator>>(istream &is, String &S)
{
    return S.fill(is);
}

// #define CONSTRUCTORS_CHECK

int main()
{
#ifdef CONSTRUCTORS_CHECK
    String s;
    cout << "s: " << s << endl;
    String str1 = "Hello";
    String str2 = "World";
    cout << "Str1: " << str1 << endl;
    cout << "Str2: " << str2 << endl;
    cout << "Your string: " << str1.getStr() << endl;

    String copy = str2;
    cout << "Copy:" << copy << endl;
    // String str3 = str1 + str2;
    // cout << "Str3: " << str3 << endl;

    // String str4;
    // cout << "Enter str4: ";
    // cin >> str4;
    // cout << "Str4: " << str4 << endl;

    // String str5(25);
    // cout << "Nothing 2: " << endl;
    // cout << str5 << endl;

    String s7 = str1;
    cout << "S7: " << s7 << endl;

    String s8;
    s8 = s7;
    cout << "S8: " << s8 << endl;

#endif // DEBUG

    String str1("Hello");
    String str2("World");
    String str3 = str1 + str2;
    cout << str3 << endl;

    return 0;
}
