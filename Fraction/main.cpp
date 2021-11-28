#include <iostream>
using namespace std;
#define tab '\t'
#define PATH "\n ------------------- \n"
class Fraction
{
    int x, y;

public:
    /////constructors////////
    ////default constructor
    Fraction()
    {
        this->x = int();
        this->y = int();
    }

    Fraction(int x)
    {
        this->x = x;
        this->y = int();
    }

    Fraction(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    ///shallow copy

    Fraction(const Fraction &other)
    {
        this->x = other.x;
        this->y = other.y;
    }

    ////////get set methods
    int get_x() const
    {
        return x;
    }
    int get_y() const
    {
        return y;
    }
    void set_x(int x)
    {
        this->x = x;
    }
    void set_y(int y)
    {
        this->y = y;
    }

    /////methods
    ///print method
    void print()
    {
        cout << "X: " << x << tab << " Y : " << y << endl;
    }
    Fraction &operator++()
    {
        this->x = ++x;
        this->y = ++y;
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction old;
        this->x = x++;
        this->y = y++;
        return old;
    }

    Fraction &operator--()
    {
        this->x = --x;
        this->y = --y;
        return *this;
    }
    Fraction operator--(int)
    {
        Fraction old;
        this->x = x--;
        this->y = y--;
        return old;
    }

    Fraction operator=(const Fraction &other)
    {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }

    Fraction operator+=(const Fraction &other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Fraction operator-=(const Fraction &other)
    {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    Fraction operator/=(const Fraction &other)
    {
        this->x /= other.x;
        this->y /= other.y;
        return *this;
    }

    Fraction operator*=(const Fraction &other)
    {
        this->x *= other.x;
        this->y *= other.y;
        return *this;
    }

    ~Fraction()
    {
        cout << "Desctructor " << endl;
    }
};

Fraction operator+(const Fraction &left, const Fraction &right)
{
    Fraction n;
    n.set_x(left.get_x() + right.get_x());
    n.set_y(left.get_y() + right.get_y());
    return n;
}

Fraction operator-(const Fraction &left, const Fraction &right)
{
    Fraction n;
    n.set_x(left.get_x() - right.get_x());
    n.set_y(left.get_y() - right.get_y());
    return n;
}

Fraction operator/(const Fraction &left, const Fraction &right)
{
    Fraction n;
    n.set_x(left.get_x() / right.get_x());
    n.set_y(left.get_y() / right.get_y());
    return n;
}

Fraction operator*(const Fraction &left, const Fraction &right)
{
    Fraction n;
    n.set_x(left.get_x() * right.get_x());
    n.set_y(left.get_y() * right.get_y());
    return n;
}

Fraction operator%(const Fraction &left, const Fraction &right)
{
    Fraction n;
    n.set_x(left.get_x() % right.get_x());
    n.set_y(left.get_y() % right.get_y());
    return n;
}

int main()
{
    //default constructor
    Fraction A;
    A.print();
    cout << PATH << endl;
    ////one paramter
    Fraction B = 1;
    B.print();
    cout << PATH << endl;
    ///two parametr
    Fraction C(2, 1);
    C.print();
    cout << PATH << endl;
    //////

    ///Overload +
    Fraction BC = B + C;
    cout << "BC " << endl;
    BC.print();
    ///Overload -

    Fraction CB = C - B;
    cout << "CB " << endl;
    CB.print();
    //////Unary operators

    ///prefix
    ++CB;
    cout << "Prefix: " << endl;
    CB.print();
    cout << "Postfix: " << endl;
    CB++;
    CB.print();
    ///minus
    --CB;
    cout << "--" << endl;
    CB.print();
    cout << "---" << endl;
    CB--;
    CB.print();
    cout << PATH << endl;

    /////////
    Fraction XF = Fraction(4, 2) / Fraction(2, 2);
    XF.print();
    cout << PATH << endl;
    //////

    /////////
    Fraction FX = Fraction(1, 1) * Fraction(2, 2);
    cout << "Operator * " << endl;
    FX.print();
    cout << PATH << endl;
    //////

    /////////
    Fraction NX = Fraction(4, 6) % Fraction(3, 7);
    cout << "Operator % " << endl;
    NX.print();
    cout << PATH << endl;
    //////

    Fraction FL(1, 6);
    cout << "+=" << endl;
    FL += Fraction(2, 2);
    FL.print();
    cout << PATH << endl;

    cout << "-=" << endl;
    FL -= Fraction(2, 1);
    FL.print();
    cout << PATH << endl;

    cout << "*=" << endl;
    FL *= Fraction(2, 2);
    FL.print();
    cout << PATH << endl;

    cout << "/=" << endl;
    FL /= Fraction(1, 2);
    FL.print();
    cout << PATH << endl;

    return 0;
}
