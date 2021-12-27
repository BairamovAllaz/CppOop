#include <iostream>
#include <bitset>
#include <cassert>
using namespace std;
//https://en.wikipedia.org/wiki/Bitwise_operation
class Binary;
Binary operator+(Binary &left, Binary &right);
Binary operator-(Binary &left, Binary &right);

Binary operator*(Binary &left, Binary &right);
class Binary
{
private:
    std::bitset<32> b1{};

public:
    Binary() : b1(0) { cout << "Default" << endl; };
    Binary(int a) : b1(a) { cout << "Two argument" << endl; };
    Binary(bitset<32> val) : b1(val) { cout << "Value" << endl; };

    Binary(const Binary &other) : b1(other.b1) { cout << "Copy assigment"; };
    Binary(Binary &&other) : b1(other.b1)
    {
        other.b1 = {};
        cout << "MoveConstructor\t" << this << endl;
    }

    Binary &operator=(Binary &&other)
    {
        if (this == &other)
            return *this;
        this->b1 = other.b1;
        other.b1 = {};
        cout << "MoveAssigment\t" << this << endl;
        return *this;
    }

    bitset<32> getb1()
    {
        return b1;
    }

    std::ostream &print(std::ostream &os) const
    {
        os << b1 << endl;
        return os;
    }

    ~Binary()
    {
        cout << "Desctructor" << endl;
    }
};
std::ostream &operator<<(std::ostream &os, const Binary &F)
{
    return F.print(os);
};

std::bitset<32> multipilaction(std::bitset<32> b1, std::bitset<32> b2)
{
    std::bitset<32> Result{};

    bool borrow = false;
    for (size_t i = 0; i < 32; i++)
    {
        bool diff;
        if (borrow)
        {
            diff = !(b1[i] ^ b2[i]);
            borrow = !b1[i] || (b1[i] && b2[i]);
        }
        else
        {
            diff = b1[i] ^ b2[i];
            borrow = !b1[i] && b2[i];
        }
        Result[i] = diff;
    }
    return Result;
}

Binary operator+(Binary &left, Binary &right)
{
    //For example: 101 + 10 = 0111
    ///Algorithm
    /* 
    sum = a xor b xor c
    carry = a&b|b&c|c&a 
    */
    /* 
        1 or 1 = 0
        1 or 0 = 1
        0 or 1 = 1
        0 or 0 = 0
    */
    std::bitset<32> Ne{};
    int y = 0;
    for (size_t i = 0; i < 32; i++)
    {
        Ne[i] = (left.getb1()[i] ^ right.getb1()[i]) ^ y;
        y = (left.getb1()[i] & right.getb1()[i]) | (left.getb1()[i] & y) | (right.getb1()[i] & y);
    }
    return Binary(Ne);
}

Binary operator-(Binary &left, Binary &right)
{
    //for example: 101 - 10 = 011
    std::bitset<32> Result{};

    bool borrow = false;
    for (size_t i = 0; i < 32; i++)
    {
        bool diff;
        if (borrow)
        {
            diff = !(left.getb1()[i] ^ right.getb1()[i]);
            borrow = !left.getb1()[i] || (left.getb1()[i] && right.getb1()[i]);
        }
        else
        {
            diff = left.getb1()[i] ^ right.getb1()[i];
            borrow = !left.getb1()[i] && right.getb1()[i];
        }
        Result[i] = diff;
    }
    return Binary(Result);
}

Binary operator*(Binary &left, Binary &right)
{
    //for example : 101 * 10 = 01010
    //algorithm multipilaction binary
    //https://study.com/academy/lesson/binary-division-multiplication-rules-examples.html

    /* 
            1 and 1 = 1
            1 and 0 = 0
            0 and 1 = 0
            0 and 0 = 0
     */
    std::bitset<32> Ne{};
    std::bitset<32> K{};
    std::bitset<32> Result{};
    for (size_t i = 0; i < 32; i++)
    {
        for (size_t j = 0; j < 32; j++)
        {
            K[j] = right.getb1()[j] & left.getb1()[i];
        }
        if (i != 0)
        {
            K = (K << 1);
        }
        int y = 0;
        Ne = Result;
        for (size_t l = 0; l < 32; l++)
        {
            Result[l] = (K[l] ^ Ne[l]) ^ y;
            y = (K[l] & Ne[l]) | (K[l] & y) | (Ne[l] & y);
        }
        K = {};
    }
    return Binary(Result);
}
///Binary division is not complete yet!!
Binary operator/(Binary &left, Binary &right)
{

    std::bitset<32> result{};
    std::bitset<32> down{};

    for (int i = 0; i < 32; i++)
    {
        if (down.to_ulong() < left.getb1().to_ullong())
        {

        }
    }
    return Binary(5);
}
int main()
{
    Binary b1{2};
    Binary b2;
    Binary b4{5};
    b2 = b1 + b4;
    cout << b2 << endl;

    cout << "-------------------" << endl;
    Binary b6;
    Binary b9{2};
    Binary b8{5};
    b6 = b8 - b9;
    cout << b6 << endl;

    cout << "-------------------" << endl;
    Binary C1;
    Binary C2(2);
    Binary C3(5);
    C1 = C2 * C3;
    cout << C1 << endl;

    cout << "-------------------" << endl;
    Binary C4;
    Binary C5(42);
    Binary C6(6);
    C4 = C6 / C5;
    cout << C4 << endl;
    return 0;
}