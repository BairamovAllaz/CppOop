#include "indexString.h"
#include <cstring>
int String::get_size() const
{
    return size;
}
const char *String::get_str() const
{
    return str;
}
char *String::get_str()
{
    return str;
}
void String::setStr(const char *str1)
{
    this->size = strlen(str1) + 1;
    this->str = new char[size]{};
    strcpy(str, str1);
}
String::String(int size) : size(size), str(new char[size]{})
{
    cout << "SizeConstructor:\t" << this << endl;
}

String::String(const char str[]) : String(strlen(str) + 1)
{
    strcpy(this->str, str);
    cout << "Constructor:\t" << this << endl;
}

String::String(const String &other) : String(other.str)
{
    cout << "CopyConstructor:\t" << this << endl;
}

String::~String()
{
    delete[] this->str;
}
//type			name		(parameters)
String &String::operator=(const String &other)
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

String &String::operator+=(const String &other)
{
    return *this = *this + other;
}

const char &String::operator[](int i) const
{
    return str[i];
}

char &String::operator[](int i)
{
    return str[i];
}

ostream &String::print(ostream &os) const
{
    os << "Size\t" << size << endl;
    os << "String\t" << str << endl;
    return os;
}

istream &String::fillCin(istream &os)
{
    char arr[10240] = {};
    cin >> arr;
    setStr(arr);
    return os;
}
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
    return is;
}
