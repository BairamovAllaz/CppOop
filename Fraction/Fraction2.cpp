#include <iostream>
using namespace std;

class Fraction
{
    int integer;
    int numerator;
    int denominator;

public:
    //Encasilpation

    int get_integer() const
    {
        return integer;
    }

    int get_numerator() const
    {
        return numerator;
    }

    int get_denominator() const
    {
        return denominator;
    }

    void set_integer(int integer)
    {
        this->integer = integer;
    }

    void set_numerator(int numerator)
    {
        this->numerator = numerator;
    }

    void set_denominator(int denominator)
    {
        if (denominator = 0)
            denominator = 1;
        this->denominator = denominator;
    }

    //default constructor
    Fraction()
    {
        this->integer = int();
        this->denominator = 1;
        this->numerator = int();
        cout << "Default constructor" << endl;
    }

    Fraction(int integer)
    {
        this->integer = integer;
        this->numerator = int();
        this->denominator = 1;
        cout << "1agrconsturctor" << endl;
    }

    Fraction(int numerator, int denomantor)
    {
        this->integer = int();
        this->numerator = numerator;
        set_denominator(denomantor);
    }

    Fraction(int integer = 0, int numerator = 0, int denominator = 1)
    {
        this->integer = integer;
        this->denominator = denominator;
        this->numerator = numerator;
        cout << "Constructor" << endl;
    }

    ///Methods

    void print()
    {
        if (integer)
            cout << integer;

        if (numerator)
        {
            if (integer)
                cout << "(";
            cout << numerator << "/" << denominator;
            if (integer)
                cout << ")";
        }
        else if (integer == 0)
            cout << 0;
        cout << endl;
    }
    ~Fraction()
    {
        cout << "Desctructor" << endl;
    }
};
//
int main()
{
    Fraction A;
    A.print();

    Fraction B = 5;
    B.print();

    Fraction C(3, 4);
    C.print();

    Fraction D(3, 4, 2);
    D.print();

    return 0;
}