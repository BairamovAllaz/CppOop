#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class LongNumber
{
private:
    std::list<int> longnumber;

public:
    std::list<int> get_list() const
    {
        return longnumber;
    }

    void set_list(std::list<int> a)
    {
        for (int i : a)
        {
            longnumber.push_back(i);
        }
    }

    LongNumber(std::string number)
    {
        for (int i = 0; i < number.size(); ++i)
        {
            if (number[i] == 0)
            {
                number[i] = 0;
            }
            longnumber.push_back(number[i] - '0');
        }

        for (int i : longnumber)
        {
            cout << i << endl;
        }
    }

    ~LongNumber()
    {
    }
};

LongNumber operator+(const LongNumber &right, const LongNumber &left)
{
    


    return LongNumber("sh");
}

int main()
{
    LongNumber a("226343786478");

    return 0;
}