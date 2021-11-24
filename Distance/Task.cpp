#include <iostream>
#include <cmath>
using namespace std;

class M
{
    int x1, x2, y1, y2;
   
    public:
        M(int x1, int x2, int y1, int y2)
        {
            this->x1 = x1;
            this->x2 = x2;
            this->y1 = y1;
            this->y2 = y2;
        }
        //METHODS
        //method for power of number
        int pow(int num)
        {
            return num * num;
        }
        int distance()
        {
            return sqrt(pow((x2 - x1) + pow(y2 - y1)));
        }
};

int main()
{

    cout << "Hello world: " << endl;
    M n(2, 0, 2, 3);

    cout << n.distance() << endl;

    return 0;
}