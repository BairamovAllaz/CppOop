#include <iostream>
#include <cstring>
using namespace std;
class Binary
{
private:
    unsigned int capacity;
    bool *number;

public:
    unsigned int get_capacity() const
    {
        return capacity;
    }

    const bool *get_number() const
    {
        return number;
    }

    bool *get_number()
    {
        return number;
    }

    void set_capacity(int capacity)
    {
        if (capacity > 32)
        {
            capacity = 32;
        }
        bool *newnumber = new bool[capacity]{};
        for (int i = 0; i < (this->capacity < capacity ? this->capacity : capacity); i++)
        {
            newnumber[i] = this->number[i];
        }
        this->capacity = capacity;
        delete[] this->number;
        this->number = newnumber;
    }

    //default constructor
    Binary()
    {
        capacity = 8;
        number = new bool[capacity]{};
    }
    Binary(int decimal)
    {

        int buffer = decimal;
        capacity = 0;
        while (buffer)
        {
            buffer /= 2;
            capacity++;
        }
        if (capacity <= 8)
        {
            capacity = 8;
        }
        else if (capacity <= 16)
        {
            capacity = 16;
        }
        else if (capacity <= 24)
        {
            capacity = 24;
        }
        else if (capacity <= 32)
        {
            capacity = 32;
        }
        number = new bool[capacity]{};
        for (int i = 0; decimal; i++)
        {
            number[i] = decimal % 2;
            decimal /= 2;
        }
    }

    Binary(const char *bit)
    {
        this->capacity = strlen(bit);
        if (capacity <= 8)
        {
            capacity = 8;
        }
        else if (capacity <= 16)
        {
            capacity = 16;
        }
        else if (capacity <= 24)
        {
            capacity = 24;
        }
        else if (capacity <= 32)
        {
            capacity = 32;
        }
        number = new bool[capacity]{};
        for (int i = 0; i < strlen(bit); i++)
        {
            number[i] = bit[i] == '0' ? 0 : 1;
        }
    }

    Binary(const Binary &other)
    {
        this->capacity = other.capacity;
        this->number = new bool[this->capacity]{};
        for (int i = 0; i < capacity; i++)
            this->number[i] = other.number[i];
        cout << "Copy constructor\t" << this << endl;
    }

    Binary(Binary &&other)
    {
        this->capacity = other.capacity;
        this->number = other.number;
        other.number = nullptr;
        other.capacity = 0;
        cout << "MoveConstructor\t" << this << endl;
    }

    Binary &operator=(Binary &&other)
    {
        if (this == &other)
            return *this;
        delete[] number;
        this->capacity = other.capacity;
        this->number = other.number;
        other.number = nullptr;
        other.capacity = 0;
        cout << "MoveAssigment\t" << this << endl;
        return *this;
    }

    Binary operator~() const
    {
        Binary inversion = *this;
        for (int i = 0; i < capacity; i++)
        {
            // if (inversion[i] == 1)
            // {
            //     inversion[i] = 0;
            // }
            // else
            // {
            //     inversion[i] = 1;
            // }
            inversion.number[i] = inversion.number[i] ? 0 : 1;
        }
        return inversion;
    }

    std::ostream &print(std::ostream &os) const
    {
        if (capacity == 8)
            os.width(11 * 3);
        if (capacity == 16)
            os.width(11 * 2);
        if (capacity == 24)
            os.width(11);
        for (int i = capacity - 1; i >= 0; i--)
        {
            os << number[i];
            if (i % 8 == 0)
                cout << " ";
            if (i % 4 == 0)
                cout << " ";
        }
        return os;
    }

    ///overloads
    Binary &operator=(const Binary &other)
    {
        if (this == &other)
            return *this;
        delete[] this->number;
        this->capacity = other.capacity;
        this->number = new bool[this->capacity]{};
        for (int i = 0; i < capacity; i++)
            this->number[i] = other.number[i];

        cout << "Copy assigment\t" << this << endl;

        return *this;
    }

    ~Binary()
    {
        delete[] number;
        number = nullptr;
        capacity = 0;
        cout << "Descturctor\t" << this << endl;
    }
};

Binary operator|(Binary &left, Binary &right)
{
    Binary result;

    if (right.get_capacity() > left.get_capacity())
    {
        left.set_capacity(right.get_capacity());
    }
    else
    {
        right.set_capacity(left.get_capacity());
    }
    result.set_capacity(left.get_capacity());
    for (int i = 0; i < result.get_capacity(); i++)
    {
        result.get_number()[i] = (left.get_number()[i] | right.get_number()[i]);
    }
    // int min_capacity = left.get_capacity() > right.get_capacity() ? right.get_capacity() : left.get_capacity();
    // int max_capacity = left.get_capacity() < right.get_capacity() ? right.get_capacity() : left.get_capacity();
    // result.set_capacity(min_capacity);

    // for (int i = 0; i < min_capacity; i++)
    // {
    //     result.get_number()[i] = ((left.get_number()[i] || right.get_number()[i]) ? 1 : 0);
    // }

    // for (int i = min_capacity; i < max_capacity; i++)
    // {
    //     result.get_number()[i] = left.get_capacity() > right.get_capacity() ? left.get_number()[i] : right.get_number()[i];
    // }

    ///basic solution
    /* if (left.get_capacity() > right.get_capacity())
    {
        for (int i = min_capacity; i < max_capacity; i++)
        {
            result.get_number()[i] = left.get_number()[i];
        }
    }
    else
    {
        for (int i = min_capacity; i < max_capacity; i++)
        {
            result.get_number()[i] = right.get_number()[i];
        }
    } */
    return result;
}

Binary operator&(Binary &left, Binary &right)
{
    Binary result;

    if (right.get_capacity() > left.get_capacity())
        left.set_capacity(right.get_capacity());
    else
        right.set_capacity(left.get_capacity());

    result.set_capacity(left.get_capacity());

    for (size_t i = 0; i < result.get_capacity(); i++)
        result.get_number()[i] = (left.get_number()[i] & right.get_number()[i]);

    return result;
}

Binary operator^(Binary &left, Binary &right)
{
    Binary result;

    if (right.get_capacity() > left.get_capacity())
        left.set_capacity(right.get_capacity());
    else
        right.set_capacity(left.get_capacity());

    result.set_capacity(left.get_capacity());

    for (size_t i = 0; i < result.get_capacity(); i++)
        result.get_number()[i] = (left.get_number()[i] ^ right.get_number()[i]);

    return result;
}
std::ostream &operator<<(std::ostream &os, const Binary &F)
{
    return F.print(os);
};

// #define CONSTRUCTOR_CHECK

int main()
{
#ifdef CONSTRUCTOR_CHECK
    Binary num1;
    num1.print();
    cout << endl;
    Binary num2 = 360;
    cout << num2 << endl;
    Binary num3;
    num3 = num2;
    cout << (~num3) << endl;
#endif // DEBUG

    Binary bin1 = 202;
    Binary bin2 = 27;
    Binary bin3 = (bin1 | bin2);
    cout << bin3 << endl;

    Binary bin4 = 5;
    Binary bin5 = 5;
    Binary bin6 = (bin4 & bin5);
    cout << bin6 << endl;

    Binary bin7 = 5;
    Binary bin8 = 2;
    Binary bin9 = (bin7 ^ bin8);
    cout << bin9 << endl;

    Binary f1("1011");
    cout << f1 << endl;

    return 0;
}