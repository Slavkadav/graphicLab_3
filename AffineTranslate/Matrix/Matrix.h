//
// Created by User on 14.11.2017.
//

#ifndef GRAPHIC_LAB_2_MATRIX_H
#define GRAPHIC_LAB_2_MATRIX_H


#include "../Vector/Vector3D.h"

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

    friend Vector3D operator*(const Matrix &, const Vector3D &);

    static Matrix translate(const Vector3D &);

    static Matrix scale(const Vector3D &);

    static Matrix rotateX(double);

    static Matrix rotateY(double);

    static Matrix rotateZ(double);
};


#endif //GRAPHIC_LAB_2_MATRIX_H
