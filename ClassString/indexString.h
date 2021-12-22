#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class String;
String operator+(const String &left, const String &right);
std::istream &operator>>(std::istream &is, String &obj);
std::ostream &operator<<(std::ostream &os, const String &obj);
std::istream &getline(std::istream &is, String &obj);
class String
{
    int size;
    char *str;

public:
    int get_size() const;
    const char *get_str() const;
    char *get_str();

    void setStr(const char *str1);
    explicit String(int size = 80);
    String(const char str[]);

    String(const String &other);
    ~String();

    String &operator=(const String &other);
    String &operator+=(const String &other);

    const char &operator[](int i) const;
    char &operator[](int i);

    //					Methods
    ostream &print(ostream &os) const;

    istream &fillCin(istream &os);
};
