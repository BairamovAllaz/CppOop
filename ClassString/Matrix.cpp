#include <iostream>
#include <ctime>
using namespace std;

class Matrix;
void Allocate();
void FillMatrix();

class Matrix
{
    int **matrix;
    int height;
    int width;
public:
    //constructors
    Matrix()
    {
        this->width = 5;
        this->height = 5;
        Allocate();
        FillMatrix();
    }
    Matrix(int height, int width)
    {
        this->height = height;
        this->width = width;
        Allocate();
        FillMatrix();
    }
    // Matrix(const Matrix &other)
    // {
    //     this->height = other.height;
    //     this->width = other.width;

    //     Allocate();

    //     for (size_t i = 0; i < height; i++)
    //     {
    //         for (size_t j = 0; j < width; j++)
    //         {
    //             matrix[i][j] = other.getM(i,j);
    //         }
    //     }
    // }
    void Allocate()
    {
        matrix = new int *[height];
        for (size_t i = 0; i < height; i++)
        {
            matrix[i] = new int[width];
        }
    }
    void FillMatrix()
    {
        for (size_t i = 0; i < height; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                matrix[i][j] = rand() % 20 + 1;
            }
        }
    }
    ///methods
    void print()
    {

        for (size_t i = 0; i < height; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~Matrix()
    {
        for (size_t i = 0; i < width; i++)
        {
            delete matrix[i];
        }
        delete[] matrix;
    }
};

int main()
{
    srand(time(0));

    Matrix m(3, 3);

    m.print();

    Matrix N;
    N = m;
    N.print();

    return 0;
}