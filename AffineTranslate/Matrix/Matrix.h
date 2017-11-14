//
// Created by User on 14.11.2017.
//

#ifndef GRAPHIC_LAB_2_MATRIX_H
#define GRAPHIC_LAB_2_MATRIX_H


#include "../Vector/Vector.h"

class Matrix {
public:
    double matr[4][4];

    Matrix() {};

    explicit Matrix(double);

    Matrix &operator+=(const Matrix &);

    Matrix &operator*=(const Matrix &);

    Matrix &operator*=(double);

    void Identity();

    friend Matrix operator+(const Matrix &, const Matrix &);

    friend Matrix operator-(const Matrix &, const Matrix &);

    friend Matrix operator*(const Matrix &, const Matrix &);

    friend Matrix operator*(const Matrix &, double);

    friend Vector operator*(const Matrix &, const Vector &);
};

Matrix translate(const Vector &);

Matrix scale(const Vector &);

Matrix rotateX(double);

Matrix rotateY(double);

Matrix rotateZ(double);

#endif //GRAPHIC_LAB_2_MATRIX_H
