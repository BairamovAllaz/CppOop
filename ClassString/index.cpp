#include <iostream>
#include <cstring>
using namespace std;
class String;
String operator+(const String &left, const String &right);

class String
{
    int size;
    char *str;

public:
    int get_size() const
    {
        return size;
    }
    const char *get_str() const
    {
        return str;
    }
    char *get_str()
    {
        return str;
    }

    void setStr(const char *str1)
    {
        this->size = strlen(str1) + 1;
        this->str = new char[size]{};
        strcpy(str, str1);
    }

    explicit String(int size = 80) : size(size), str(new char[size]{})
    {
        cout << "SizeConstructor:\t" << this << endl;
    }
    String(const char str[]) : String(strlen(str) + 1)
    {
        strcpy(this->str, str);
        cout << "Constructor:\t" << this << endl;
    }
    String(const String &other) : String(other.str)
    {
        cout << "CopyConstructor:\t" << this << endl;
    }
    ~String()
    {
        delete[] str;
        cout << "Destructor:\t" << this << endl;
    }
    String &operator=(const String &other)
    {
        if (this == &other)
            return *this; // String s3("Hello world") !(    s3 = s3    );
        delete[] this->str;
        this->size = other.size;
        this->str = new char[size]{};
        strcpy(str, other.get_str());
        // for (size_t i = 0; str[i]; i++)
        // {
        //     this->str[i] = other.str[i];
        // }
        cout << "CopyAssigment\t" << this << endl;
        return *this;
    }
    String &operator+=(const String &other)
    {
        return *this = *this + other;
    }

    const char &operator[](int i) const
    {
        return str[i];
    }
    char &operator[](int i)
    {
        return str[i];
    }

    //					Methods
    ostream &print(ostream &os) const
    {
        os << "Size\t" << size << endl;
        os << "String\t" << str << endl;
        return os;
    }

    istream &fillCin(istream &os)
    {
        char arr[10240] = {};
        cin >> arr;
        setStr(arr);
        return os;
    }
};

String operator+(const String &left, const String &right)
{
    String result(left.get_size() + right.get_size() - 1);
    for (int i = 0; i < left.get_size(); i++)
        result[i] = left[i];
    for (int i = 0; i < right.get_size(); i++)
        result[i + left.get_size() - 1] = right[i];
    return result;
}

std::ostream &operator<<(std::ostream &os, const String &obj)
{
    return obj.print(os);
}
std::istream &operator>>(std::istream &is, String &obj)
{
    return obj.fillCin(is);
}

std::istream &getline(std::istream &is, String &obj)
{
    const int SIZE = 1024 * 1000;
    char buffer[SIZE] = {};
    is.getline(buffer, SIZE);
    obj = buffer;
    return is; //winver
}
// #define CONSTRUCTORS_CHECK
// #define CONSTRUCTORS_CHECK2
#define CONSTRUCTORS_CHECK3

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

#ifdef CONSTRUCTORS_CHECK2

    String str1("Hello");
    String str2("World");
    String str3 = str1 + str2;
    cout << str3 << endl;
    str1 += str2;
    cout << "Str1 : " << str1 << endl;
    String s4;
    cout << "Enter s4: ";
    getline(cin, s4);
    cout << "S4 : " << s4 << endl;

#endif // DEBUG

#ifdef CONSTRUCTORS_CHECK3
    String s(10);
    cout << "s : " << s << endl;
#endif // DEBUG
    return 0;
}