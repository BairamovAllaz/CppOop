#include <iostream>
using namespace std;
class Fraction
{
    int integer;
    int numerator;
    int denominator;

public:
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
        if (denominator == 0)
            denominator = 1;
        this->denominator = denominator;
    }
    //Constructors:
    Fraction()
    {
        this->integer = 0;
        this->numerator = 0;
        this->denominator = 1;
        cout << "DefaultConstruct:\t" << this << endl;
    }
    Fraction(int integer)
    {
        this->integer = integer;
        this->numerator = 0;
        this->denominator = 1;
        cout << "1argConstructor:\t" << this << endl;
    }
    Fraction(int numerator, int denominator)
    {
        this->integer = 0;
        this->numerator = numerator;
        set_denominator(denominator);
        cout << "Constructor:\t" << this << endl;
    }
    Fraction(int integer, int numerator, int denominator)
    {
        this->integer = integer;
        this->numerator = numerator;
        set_denominator(denominator);
        cout << "Constructor:\t" << this << endl;
    }
    ~Fraction()
    {
        cout << "Destructor:\t" << this << endl;
    }

    //Methods:
    void to_improper()
    {
        numerator += integer * denominator;
        integer = 0;
    }
    void to_proper()
    {
        integer += numerator / denominator;
        numerator %= denominator;
    }

    void reduce()
    {
        for (int i = 1; i < denominator * numerator; ++i)
        {
            if ((denominator % i == 0) && (numerator % i == 0))
            {
                denominator /= i;
                numerator /= i;
            }
        }
    }
    void print()
    {
        if (integer)
        {
            cout << integer;
        }
        if (numerator)
        {
            if (integer)
            {
                cout << "(";
            }
            cout << numerator << "/" << denominator;
            if (integer)
            {
                cout << ")";
            }
        }
        else if (integer == 0)
        {
            cout << 0;
        }
        cout << endl;
    }
};

Fraction operator*(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    Fraction result;
    result.set_numerator(left.get_numerator() * right.get_numerator());
    result.set_denominator(left.get_denominator() * right.get_denominator());
    result.to_proper();
    return result;
}

int main()
{
    Fraction A(2, 1, 2);
    Fraction B(3, 2, 5);
    Fraction C = A * B;
    cout << "First value: ";
    C.print();
    cout << "First value: ";
    C.to_improper();    
    C.print();
    cout << "With reduce method: ";
    C.reduce();
    C.print();
    return 0;
}