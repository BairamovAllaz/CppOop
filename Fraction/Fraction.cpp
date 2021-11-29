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
    void set_denominator(int demoinator)
    {
        if (demoinator = 0)
            demoinator = 1;
        this->denominator = demoinator;
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

    Fraction(int integer, int numerator, int denominator)
    {
        this->integer = integer;
        this->denominator = denominator;
        this->numerator = numerator;
        cout << "Constructor" << endl;
    }
    ///Methods
    void to_improrer()
    {
        numerator += integer * denominator;
        integer = 0;
    }

    void to_proper()
    {
        integer += numerator / denominator;
        numerator %= denominator;
    }

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
Fraction operator*(Fraction left, Fraction right)
{
    left.to_improrer();
    right.to_improrer();
    Fraction copy(
        left.get_numerator() * right.get_numerator(),
        left.get_denominator() * right.get_denominator()
        );
    // copy.set_numerator(left.get_numerator() * right.get_numerator());
    // copy.set_denominator(left.get_denominator() * right.get_denominator());
    // copy.to_proper();
    return copy;
}
// #define CONSTUCTORCHECK
int main()
{
#ifdef CONSTUCTORCHECK
    Fraction A;
    A.print();

    Fraction B = 5;
    B.print();

    Fraction C(3, 4);
    C.print();

    Fraction D(2, 3, 4);
    D.print();
#endif

    Fraction A(2, 1, 2);
    Fraction B(3, 2, 5);
    Fraction C = A * B;
    C.print();

    return 0;
}