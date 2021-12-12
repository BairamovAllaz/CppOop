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
    long long int integer;
    long long int numerator;
    long long int denominator;

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

    Fraction &reduce()
    {
        if (numerator == 0)
            return *this; //Прерывам работу функции
        int more, less;
        int rest; //остаток от деления
        if (numerator > denominator)
        {
            more = numerator;
            less = denominator;
        }
        else
        {
            less = numerator;
            more = denominator;
        }
        do
        {
            rest = more % less;
            more = less;
            less = rest;
        } while (rest);
        int GCD = more;
        numerator /= GCD;
        denominator /= GCD;
        return *this;
    }

    // int gcd(int n1, int n2)
    // {
    //     int more, less;
    //     int rest;
    //     if (n1 > n2)
    //     {
    //         more = n1;
    //         less = n2;
    //     }
    //     else
    //     {
    //         less = n1;
    //         more = n2;
    //     }
    //     do
    //     {
    //         rest = more % less;
    //         more = less;
    //         less = rest;
    //     } while (rest);
    //     int GCD = more;
    //     return GCD;
    // }

    explicit Fraction(double doublenumber)
    {
        // //for example 2.45
        // int intnumber = doublenumber, c = 10000;
        // //intnumber = 2
        // double newdouble = doublenumber - intnumber;
        // //newdouble = 0.45
        // int gcdvalue = gcd((newdouble * c), c);
        // ///gcdvalue = 0.45 * 10000 = 4500 and 10000
        // //gcdvalue of 4500 and 10000 is 500
        // this->numerator = (newdouble * c) / gcdvalue;
        // ///to find numerator we need to do (  0.45 * 10000 = 4500 / 500 = 9 )
        // this->denominator = c / gcdvalue;
        // ;
        // //to find denominator we need to do (  10000 / 500 = 20 )
        // ///output : 9/20
        // this->integer = intnumber;
        //doublenumber = 2.45
        // integer = doublenumber;
        doublenumber += 1e-11;
        //integer = 2;
        denominator = 1e9;
        //denominator = 1000000000
        doublenumber -= integer;
        //doublenumber = 2.45 - 2 = 0.45
        numerator = (doublenumber * denominator);
        //numerator = 0.45 * 1000000000
        reduce();
        ///reduce methode in top!
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
  

    //overload ostream and istream!
    //////////////////////////////////////////
    //////////////////////////////////////////
    ostream &print(ostream &os) const
    {
        if (integer)
        {
            os << integer;
        }
        if (numerator)
        {
            if (integer)
            {
                os << "(";
            }
            os << numerator << "/" << denominator;
            if (integer)
            {
                os << ")";
            }
        }
        else if (integer == 0)
        {
            os << 0;
        }
        os << endl;
        return os;
    }
    istream &initP(istream &in)
    {
        cout << "Enter integer: ";
        in >> integer;
        cout << "Enter denominator: ";
        in >> denominator;
        cout << "Enter numerator: ";
        in >> numerator;
        return in;
    }
    //////////////////////////////////////////
    //////////////////////////////////////////



    explicit operator int() const
    {
        return integer;
    }
    ///overload double double(Fraction!);
    explicit operator double() const
    {
        double n = integer + (numerator / (double)denominator);
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

ostream &operator<<(ostream &os, const Fraction &F)
{
    return F.print(os);
    // if (F.integer)
    // {
    //     os << F.integer;
    // }
    // if (F.numerator)
    // {
    //     if (F.integer)
    //     {
    //         os << "(";
    //     }
    //     os << F.numerator << "/" << F.denominator;
    //     if (F.integer)
    //     {
    //         os << ")";
    //     }
    // }
    // else if (F.integer == 0)
    // {
    //     os << 0;
    // }
    // return os;
};

istream &operator>>(istream &in, Fraction &F)
{
    return F.initP(in);
};

// #define OPERATORSCHECK
// #define FROM_OTHER_TO_CLASS
// #define HOME_WORK
#define TYPE_CONVERSIONS
int main()
{

#ifdef TYPE_CONVERSIONS
    // Fraction A(2, 4, 5);
    // cout << A << endl;
    // Fraction B = A;
    // cout << B << endl;
    Fraction A;
    cin >> A;
    cout << A << endl;
#endif // DEBUG

#ifdef HOME_WORK

    Fraction A(2, 3, 4);
    A.to_improper();
    double a = (double)A;
    cout << a << endl;
    cout << PATH << endl;

    double b = 2.76;
    Fraction C = Fraction(b);
    cout << C << endl;
#endif // DEBUG

#ifdef OPERATORSCHECK
    bool value1, value2;
    Fraction A(2, 1, 2);
    Fraction B(3, 2, 5);
    ///*=
    A *= B;
    cout << A << endl;
    cout << "*=" << endl;
    cout << B << endl;
    cout << "Value: " << endl;
    cout << A << endl;
    cout << PATH << endl;
    ///*=

    ///*
    Fraction BA(2, 1, 2);
    Fraction BB(3, 2, 5);
    Fraction C = BA * BB;
    cout << BA << endl;
    cout << " * " << endl;
    cout << BB << endl;
    cout << "Value: " << endl;
    cout << C << endl;
    cout << PATH << endl;
    ////*
    // /// /
    Fraction CA(2, 1, 2);
    Fraction CB(3, 2, 5);
    Fraction T = CA / CB;
    cout << CA << endl;
    cout << " / " << endl;
    cout << CB << endl;
    cout << T << endl;
    cout << PATH << endl;
    /// +
    Fraction DA(3, 1);
    Fraction DB(5, 2);
    cout << DA << endl;
    cout << " + " << endl;
    cout << DB << endl;
    Fraction h = DA + DB;
    cout << h << endl;
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
    cout << J << endl;
    cout << "+=" << endl;
    cout << CD << endl;
    J += CD;
    cout << J << endl;
    value1 = J > CD;
    cout << "Value1 : > " << boolalpha << value1 << endl;
    value2 = J < CD;
    cout << "Value2 < " << boolalpha << value2 << endl;
    cout << PATH << endl;
    ///+=
    ///-
    Fraction FA(3, 1);
    Fraction FB(5, 2);
    cout << FA << endl;
    cout << " - " << endl;
    cout << FB << endl;
    Fraction L = FA - FB;
    cout << L << endl;
    value1 = FA >= FB;
    cout << "Value1: >= " << boolalpha << value1 << endl;
    cout << PATH << endl;
    ///-
    /// +=
    Fraction G(3, 1);
    Fraction F(3, 2);
    cout << G << endl;
    cout << "+=" << endl;
    cout << F << endl;
    value1 = G <= F;
    cout << "Value: <= " << boolalpha << value1 << endl;
    G -= F;
    cout << G << endl;
    cout << PATH << endl;
    ///+=
    /// /=
    Fraction K(3, 1);
    Fraction N(3, 2);
    cout << K << endl;
    cout << "/=" << endl;
    cout << N << endl;
    K /= N;
    cout << K << endl;
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


    return 0;
}
