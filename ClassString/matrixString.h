#pragma once
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
    int getHeight() const;
    int getWidth() const;

    //move constructor
    Matrix(Matrix &&obj);
    ///moveassigment
    Matrix &operator=(Matrix &&x);

    //constructors
    Matrix();
    Matrix(int height, int width);

    Matrix(Matrix &other);
    Matrix operator=(const Matrix &other);
    ///methods
    int *&operator[](int i);
    int *&operator[](int i) const;

    void deleteMat();

    void Allocate();
    void FillMatrix();

    ostream &print(ostream &os) const;

    ~Matrix();
};
ostream &operator<<(ostream &os, const Matrix &m);
Matrix operator+(const Matrix &left, const Matrix &right);
Matrix operator-(const Matrix &left, const Matrix &right);
Matrix operator*(const Matrix &left, const Matrix &right);
Matrix operator/(const Matrix &left, const Matrix &right);