#include <iostream>
#include <list>
#include <cstring>
#include <vector>
using namespace std;
class Large
{
private:
    std::vector<int> longnumber;
public:
    Large()
    {
        longnumber.clear();
    }
    Large(std::vector<int> &vec) : Large()
    {
        for (int i : vec)
        {
            longnumber.push_back(i);
        }
    }
    Large(long long int a)
    {
        while (a > 0)
        {
            longnumber.push_back(a % 10);
            a = a / 10;
        }
    }
    ~Large() {}

    std::vector<int> getlongnumber()
    {
        return longnumber;
    }

    void setLongNumber(std::vector<int> a)
    {
        // this->longnumber = a;
        for(int f : a) { 
            longnumber.push_back(f);
        }
    }

    void print() const
    {
        for (int i : longnumber)
        {
            cout << i << endl;
        }
    }

    // overload
};

ostream &operator>>(ostream &in, Large &other)
{
    for (int i : other.getlongnumber())
    {
        in << i << endl;
    }
    return in;
}

Large operator+(Large a, Large b)
{
    std::vector<int> sum;
    std::vector<int> max;
    std::vector<int> min;

    int rest = 0;

    max = a.getlongnumber();
    min = b.getlongnumber();

    if (a.getlongnumber().size() > b.getlongnumber().size())
    {
        max = a.getlongnumber();
    }
    else
    {
        min = b.getlongnumber();
    }

    for (int i = 0; i < min.size(); i++)
    {
        int l = min[i] + max[i] + rest;
        sum.push_back(l % 10);
        rest = l / 10;
    }

    for (int i = min.size(); i < max.size(); i++)
    {
        int l = max[i] + rest;
        sum.push_back(l % 10);
        rest = l / 10;
    }

    while (rest > 0)
    {
        sum.push_back(rest % 10);
        rest = rest / 10;
    }

    Large buffclass;

    buffclass.setLongNumber(sum);
    return a;
}

// istream &operator>>(istream &out, Large &other)
// {
//     std::string str;
//     cout << "Enter a number: ";
//     out >> str;
//     int item;
//     for (int i = 0; i != str.length(); i++)
//     {
//         item = (str.at(i) - '0'); // to number
//         other.getlongnumber().push_back(item);
//     }
//     return out;
// }

int main()
{
    // std::vector<int> js = {2, 3, 4, 4, 3, 0, 1, 2, 3, 5, 7, 8, 9, 5, 4, 3, 2};
    Large a(68536565);
    // std::vector<int> oq = {8, 3, 1, 2, 4, 6, 7, 8, 9};
    Large b(20382);

    Large c = a + b;

    // cout << c << endl;
    c.print();

    return 0;
}