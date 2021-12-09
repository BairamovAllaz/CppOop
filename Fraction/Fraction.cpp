#include <iostream>
using namespace std;
#define PATH "------------"
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
bool operator==(const Fraction &left, const Fraction &right);
bool operator!=(const Fraction &left, const Fraction &right);
bool operator<(const Fraction &left, const Fraction &right);
bool operator>(const Fraction &left, const Fraction &right);
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
        cout << "Default constructor" << endl;
    }
    explicit Fraction(int integer)
    {
        this->integer = integer;
        this->numerator = 0;
        this->denominator = 1;
        cout << "1arg constuctor" << endl;
    }
    Fraction(int numerator, int denominator)
    {
        this->integer = 0;
        this->numerator = numerator;
        set_denominator(denominator);
    }
    Fraction(int integer, int numerator, int denominator)
    {
        this->integer = integer;
        this->numerator = numerator;
        set_denominator(denominator);
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
    Fraction &operator*=(const Fraction &other)
    {
        return *this = *this * other;
    }

    Fraction &operator+=(const Fraction &other)
    {
        return *this = *this + other;
    }

    Fraction &operator-=(const Fraction &other)
    {
        return *this = *this - other;
    }

    Fraction &operator/=(const Fraction &other)
    {
        return *this = *this / other;
    }

    Fraction inverted()
    {
        return Fraction(this->denominator, this->numerator);
    }

    Fraction SumFunc()
    {
        return Fraction(this->denominator, this->numerator);
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

    explicit operator int() const
    {
        return integer;
    }
    explicit operator double() const
    {
        double n = numerator / (double)denominator;
        return n;
    }

    ~Fraction()
    {
        cout << "Desctructor: " << this << endl;
    }
};

Fraction operator*(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    return Fraction(
        left.get_numerator() * right.get_numerator(),
        left.get_denominator() * right.get_denominator());
};

Fraction operator/(Fraction left, Fraction right)
{
    return left * right.inverted();
};

Fraction operator+(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    return Fraction(
        left.get_numerator() * right.get_denominator() +
            right.get_numerator() * left.get_denominator(),
        left.get_denominator() * right.get_denominator());
}

Fraction operator-(Fraction left, Fraction right)
{
    left.to_improper();
    right.to_improper();
    return Fraction(
        left.get_numerator() * right.get_denominator() -
            right.get_numerator() * left.get_denominator(),
        left.get_denominator() * right.get_denominator());
}

bool operator==(const Fraction &left, const Fraction &right)
{
    return (left.get_numerator() == right.get_numerator()) &&
           (left.get_denominator() == right.get_denominator());
}
bool operator!=(const Fraction &left, const Fraction &right)
{
    return !(left == right);
}
bool operator>(const Fraction &left, const Fraction &right)
{
    return (left.get_numerator() * right.get_denominator() >
            right.get_numerator() * left.get_denominator());
}

bool operator<(const Fraction &left, const Fraction &right)
{
    return (left.get_numerator() * right.get_denominator() <
            right.get_numerator() * left.get_denominator());
}

bool operator>=(const Fraction &left, const Fraction &right)
{
    return (left == right) || (left > right);
}

bool operator<=(const Fraction &left, const Fraction &right)
{
    return (left == right) || (left < right);
}

// #define OPERATORSCHECK
// #define FROM_OTHER_TO_CLASS
#define HOME_WORK
int main()
{
#ifdef OPERATORSCHECK
    bool value1, value2;
    Fraction A(2, 1, 2);
    Fraction B(3, 2, 5);
    ///*=
    A *= B;
    A.print();
    cout << "*=" << endl;
    B.print();
    cout << "Value: " << endl;
    A.print();
    cout << PATH << endl;
    ///*=

    ///*
    Fraction BA(2, 1, 2);
    Fraction BB(3, 2, 5);
    Fraction C = BA * BB;
    BA.print();
    cout << " * " << endl;
    BB.print();
    cout << "Value: " << endl;
    C.print();
    cout << PATH << endl;
    ////*

    // /// /

    Fraction CA(2, 1, 2);
    Fraction CB(3, 2, 5);
    Fraction T = CA / CB;
    CA.print();
    cout << " / " << endl;
    CB.print();
    T.print();
    cout << PATH << endl;
    /// +

    Fraction DA(3, 1);
    Fraction DB(5, 2);
    DA.print();
    cout << " + " << endl;
    DB.print();
    Fraction h = DA + DB;
    h.print();
    cout << "Operator == " << endl;
    value1 = DA == DB;
    cout << "VALUE 1: == " << boolalpha << value1 << endl;
    value2 = DA != DB;
    cout << "VALUE 2: != " << boolalpha << value2 << endl;
    cout << PATH << endl;
    /// +

    /// +=
    Fraction J(3, 1);
    Fraction CD(3, 2);
    J.print();
    cout << "+=" << endl;
    CD.print();
    J += CD;
    J.print();
    value1 = J > CD;
    cout << "Value1 : > " << boolalpha << value1 << endl;
    value2 = J < CD;
    cout << "Value2 < " << boolalpha << value2 << endl;
    cout << PATH << endl;
    ///+=

    ///-
    Fraction FA(3, 1);
    Fraction FB(5, 2);
    FA.print();
    cout << " - " << endl;
    FB.print();
    Fraction L = FA - FB;
    L.print();
    value1 = FA >= FB;
    cout << "Value1: >= " << boolalpha << value1 << endl;
    cout << PATH << endl;
    ///-

    /// +=
    Fraction G(3, 1);
    Fraction F(3, 2);
    G.print();
    cout << "+=" << endl;
    F.print();
    value1 = G <= F;
    cout << "Value: <= " << boolalpha << value1 << endl;
    G -= F;
    G.print();
    cout << PATH << endl;
    ///+=

    /// /=
    Fraction K(3, 1);
    Fraction N(3, 2);
    K.print();
    cout << "/=" << endl;
    N.print();
    K /= N;
    K.print();
////=
#endif // DEBUG
#ifdef FROM_OTHER_TO_CLASS
    double a = 2;
    Fraction A = Fraction(5);
    A.print();
    cout << "\n ---------------\n"
         << endl;
    Fraction B;
    B = (Fraction)8;
    B.print();
#endif

#ifdef HOME_WORK
    Fraction A(2, 3, 4);
    A.to_improper();
    double a = (double)A;
    cout << a << endl;
    cout << PATH << endl;

    
    double b = 2.75;
    Fraction C = Fraction(b);
    C.print();
#endif // DEBUG

    return 0;
}