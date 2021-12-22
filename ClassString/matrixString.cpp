#include "matrixString.h"

int Matrix::getHeight() const
{
    return this->height;
}
int Matrix::getWidth() const
{
    return this->width;
}

//constructors
Matrix::Matrix() : height(5), width(5)
{
    Allocate();
    FillMatrix();
}
Matrix::Matrix(int height, int width) : height(height), width(width)
{
    Allocate();
    FillMatrix();
}

Matrix::Matrix(Matrix &other) : Matrix(other.height, other.width)
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

Matrix Matrix::operator=(const Matrix &other)
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
int *&Matrix::operator[](int i)
{
    return matrix[i];
}
int *&Matrix::operator[](int i) const
{
    return matrix[i];
}

void Matrix::deleteMat()
{
    for (size_t i = 0; i < width; i++)
    {
        delete matrix[i];
    }
    delete[] matrix;
}

void Matrix::Allocate()
{
    matrix = new int *[height] {};
    for (size_t i = 0; i < height; i++)
    {
        matrix[i] = new int[width]{};
    }
}
void Matrix::FillMatrix()
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            matrix[i][j] = rand() % 20 + 1;
        }
    }
}

ostream &Matrix::print(ostream &os) const
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

Matrix::~Matrix()
{
    deleteMat();
}

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