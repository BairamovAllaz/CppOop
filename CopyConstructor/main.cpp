#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point()
    {
        this->x = int();
        this->y = int();
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Point(const Point &other)
    {
        this->x = other.x;
        this->y = other.y;
    }

    void Print(){ 
        cout << this << " X: " << this->x << '\t';
        cout << this << " Y: " << this->y << endl;
    }


    ~Point()
    {
        cout << "Descturctor " << this << endl;
    }

    void operator=(const Point &other)
    {
        this->x = other.x;
        this->y = other.y;
    }
};

int main()
{

    Point A, B, C;
    A = Point(2,3);
    B = A;
    C = B;

    A.Print();
    B.Print();
    C.Print();

    cout << "Hello world" << endl;

    return 0;
}