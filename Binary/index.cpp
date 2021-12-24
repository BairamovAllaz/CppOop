#include <iostream>
#include <bitset>
#include <cassert>
using namespace std;
class Binary;
class Binary
{
private:
    std::bitset<32> b1{};
    std::bitset<32> value{};

public:
    Binary() : b1(0) { cout << "Default" << endl; };
    Binary(int a) : b1(a) { cout << "Two argument"; };
    Binary(bitset<32> val) : b1(val) { cout << "Value"; };
    bitset<32> getb1()
    {
        return b1;
    }

    bitset<32> getvalue()
    {
        return value;
    }
    void print()
    {
        cout << "Answer: " << b1 << endl;
    }
};

Binary operator+(Binary &left, Binary &right)
{
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
    for (size_t i = 0; i < 32; i++)
    {
        int b = (~left.getb1()[i] & right.getb1()[i]);
        right.getb1()[i] = (right.getb1()[i] ^ left.getb1()[i]);
        left.getb1()[i] = b << 1;
    }
    return Binary(left.getb1());
}

int main()
{

    Binary b1{3};
    b1.print();

    Binary b2;
    Binary b4{8};
    b2 = b1 + b4;
    b2.print();

    cout << "-------------------" << endl;
    Binary b6;
    Binary b9{2};
    Binary b8{8};
    b6 = b8 - b9;
    b6.print();

    ////operator +
    // std::bitset<32> b1{25};
    // std::bitset<32> b2{15};
    // std::bitset<32> Ne{};
    // int y = 0;
    // for (size_t i = 0; i < 32; i++)
    // {
    //     Ne[i] = (b1[i] ^ b2[i]) ^ y;
    //     y = (b1[i] & b2[i]) | (b1[i] & y) | (b2[i] & y);
    // }
    // cout << Ne << endl;

    //operator -
    // std::bitset<32> b1{"01001"};
    // std::bitset<32> b2{"10011"};
    // for (size_t i = 0; i < 32; i++)
    // {
    //     int b = (~b1[i] & b2[i]);
    //     cout << b << endl;
    //     b1[i] = (b1[i] ^ b2[i]);
    //     b2[i] = b << 1;
    // }
    // cout << b1 << endl;

    // std::bitset<32> b1{"11001"};
    // std::bitset<32> b2{"10011"};
    // std::bitset<32> Ne{};
    // std::bitset<32> K{};
    // for (size_t i = 0; i < 32; i++)
    // {
    //     for (size_t j = 0; j < 32; j++)
    //     {
    //         K[i] = b1[j] & b2[i];
    //     }
    //     if (i != 1)
    //     {
    //         K = (K << 1);
    //     }
    //     int y = 0;
    //     for (size_t i = 0; i < 32; i++)
    //     {
    //         Ne[i] = (K[i] ^ Ne[i]) ^ y;
    //         y = (K[i] & Ne[i]) | (K[i] & y) | (Ne[i] & y);
    //     }
    //     // K = {};
    // }

    // cout << Ne << endl;
    return 0;
}
