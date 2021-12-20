#include <iostream>
#include <ctime>
using namespace std;

class Matrix;
Matrix operator+(const Matrix &left, const Matrix &right);
Matrix operator/(const Matrix &left, const Matrix &right);
Matrix operator*(const Matrix &left, const Matrix &right);
Matrix operator-(const Matrix &left, const Matrix &right);

class Matrix;
void Allocate();
void FillMatrix();

class Matrix
{
    int **matrix;
    int height;
    int width;

public:
    int getHeight() const
    {
        return this->height;
    }

    int getWidth() const
    {
        return this->width;
    }

    //constructors
    Matrix() : height(5), width(5)
    {
        Allocate();
        FillMatrix();
    }
    Matrix(int height, int width) : height(height), width(width)
    {
        Allocate();
        FillMatrix();
    }

    Matrix(Matrix &other) : Matrix(other.height, other.width)
    {
        // matrix = new int *[height] {};
        for (int i = 0; i < height; i++)
        {
            // matrix[i] = new int[width]{};
            for (int j = 0; j < width; j++)
            {
                matrix[i][j] = other[i][j];
            }
        }
    }

    Matrix operator=(const Matrix &other)
    {
        this->height = other.height;
        this->width = other.width;
        deleteMat();
        matrix = new int *[height] {};
        for (int i = 0; i < height; i++)
        {
            matrix[i] = new int[width]{};
            for (int j = 0; j < width; j++)
            {
                matrix[i][j] = other[i][j];
            }
        }
        return *this;
    }
    ///methods
    int *&operator[](int i)
    {
        return matrix[i];
    }
    int *&operator[](int i) const
    {
        return matrix[i];
    }

    void deleteMat()
    {
        for (size_t i = 0; i < width; i++)
        {
            delete matrix[i];
        }
        delete[] matrix;
    }

    void Allocate()
    {
        matrix = new int *[height] {};
        for (size_t i = 0; i < height; i++)
        {
            matrix[i] = new int[width]{};
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

    ostream &print(ostream &os) const
    {
        for (size_t i = 0; i < height; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        return os;
    }

    ~Matrix()
    {
        deleteMat();
    }
};

ostream &operator<<(ostream &os, const Matrix &m)
{
    return m.print(os);
}

Matrix operator+(const Matrix &left, const Matrix &right)
{
    Matrix Bf(left.getHeight(), left.getWidth());
    for (int i = 0; i < Bf.getHeight(); i++)
    {
        for (size_t j = 0; j < Bf.getWidth(); j++)
        {
            Bf[i][j] = left[i][j] + right[i][j];
        }
    }
    return Bf;
}
Matrix operator-(const Matrix &left, const Matrix &right)
{
    Matrix Bf(left.getHeight(), left.getWidth());
    for (int i = 0; i < Bf.getHeight(); i++)
    {
        for (size_t j = 0; j < Bf.getWidth(); j++)
        {
            Bf[i][j] = left[i][j] - right[i][j];
        }
    }
    return Bf;
}
Matrix operator*(const Matrix &left, const Matrix &right)
{
    Matrix Bf(left.getHeight(), left.getWidth());
    for (int i = 0; i < Bf.getHeight(); i++)
    {
        for (size_t j = 0; j < Bf.getWidth(); j++)
        {
            Bf[i][j] = left[i][j] * right[i][j];
        }
    }
    return Bf;
}
Matrix operator/(const Matrix &left, const Matrix &right)
{
    Matrix Bf(left.getHeight(), left.getWidth());
    for (int i = 0; i < Bf.getHeight(); i++)
    {
        for (size_t j = 0; j < Bf.getWidth(); j++)
        {
            Bf[i][j] = left[i][j] / right[i][j];
        }
    }
    return Bf;
}

int main()
{
    srand(time(0));

    Matrix m(3, 3);

    cout << "M: " << m << endl;

    Matrix N = m;
    cout << "N : " << N << endl;

    Matrix F;
    F = N;
    cout << "F: " << F << endl;

    Matrix H = F + N;
    cout << "H: " << H << endl;

    Matrix L = H - N;
    cout << "L: " << L << endl;

    Matrix K = N * N;
    cout << "K: " << K << endl;

    Matrix D = K / F;
    cout << "D: " << D << endl;
    return 0;
}