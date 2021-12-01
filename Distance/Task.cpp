#include <iostream>
#include <cmath>
using namespace std;
class M
{
    double x, y;
public:
    ///constructor!
    M(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    ///get set methods
    double get_x() const
    {
        return x;
    }

    double get_y() const
    {
        return y;
    }

    void set_x(double x)
    {
        this->x = x;
    }

    void get_y(double y)
    {
        this->y = y;
    }

    //METHODS
    //method for power of number
    double pow(double num)
    {
        return num * num;
    }
    ///method distance
    double distance(M other)
    {
        return sqrt(pow((this->x - other.x)) + pow((this->y - other.y)));
        // double x_distance = this->x - other.x;
        // double y_distance = this->y - other.y;
        // return sqrt(x_distance * x_distance + y_distance * y_distance);
    }
    ///descturctors
    ~M()
    {
        cout << "I am desctructor: " << endl;
    }
};
//global distance function!
double distance2(M a, M b)
{
    return sqrt(a.pow((a.get_x() - b.get_x())) + a.pow((a.get_y() - b.get_y())));
    // double x_distance = a.get_x() - b.get_x();
    // double y_distance = a.get_y() - b.get_y();
    // return sqrt(x_distance * x_distance + y_distance * y_distance);
}

int main()
{
    M n(2, 3);
    M a(3, 4);
    cout << "Value: " << n.distance(a) << endl;
    cout << "Value 2: " << distance2(n, a) << endl;
    return 0;
}
