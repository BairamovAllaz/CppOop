#include <iostream>
#include <bitset>
#include <cassert>
using namespace std;

//https://en.wikipedia.org/wiki/Bitwise_operation

class Binary;
class Binary
{
private:
    std::bitset<32> b1{};
public:
    Binary() : b1(0) { cout << "Default" << endl; };
    Binary(int a) : b1(a) { cout << "Two argument"; };
    Binary(bitset<32> val) : b1(val) { cout << "Value"; };
    bitset<32> getb1()
    {
        return b1;
    }
    void print()
    {
        cout << "Answer: " << b1 << endl;
    }
};

Binary operator+(Binary &left, Binary &right)
{
    //For example: 101 + 10 = 0111
    ///Algorithm

    /* 
    sum = a xor b xor c
    carry = a&b|b&c|c&a 
    
    */
    /* 
        1 or 1 = 1
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
    //for example : 01010
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
///Binary division not complete!!
int main()
{
    Binary b1{3};
    Binary b2;
    Binary b4{8};
    b2 = b1 + b4;
    b2.print();

    cout << "-------------------" << endl;
    Binary b6;
    Binary b9{5};
    Binary b8{2};
    b6 = b8 - b9;
    b6.print();

    cout << "-------------------" << endl;
    Binary C1;
    Binary C2(12);
    Binary C3(15);
    C1 = C2 * C3;
    C1.print();
    return 0;
}
