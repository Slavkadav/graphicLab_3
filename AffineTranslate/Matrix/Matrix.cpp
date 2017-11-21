//
// Created by User on 14.11.2017.
//

#include <cmath>
#include "Matrix.h"

#define RADIAN(angle) ((angle)/180*3.14157)

Matrix::Matrix(double v) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matr[i][j] = (i == j) ? v : 0;
        }
    }
}

Matrix &Matrix::operator+=(const Matrix &A) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matr[i][j] += A.matr[i][j];
        }
    }
}

Matrix &Matrix::operator*=(const Matrix &A) {
    Matrix res = *this;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            double sum = 0;
            for (int k = 0; k < 4; ++k) {
                sum += res.matr[i][k] * A.matr[k][j];
                matr[i][j] = sum;
            }
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(double v) {
    for (auto &i : matr) {
        for (double &j : i) {
            j *= v;
        }
    }
    return *this;
}

void Matrix::Identity() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matr[i][j] = (i == j) ? 1 : 0;
        }
    }


}

Matrix operator+(const Matrix &A, const Matrix &B) {
    Matrix res;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            res.matr[i][j] = A.matr[i][j] + B.matr[i][j];
        }
    }
    return res;
}

Matrix operator-(const Matrix &A, const Matrix &B) {
    Matrix res;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            res.matr[i][j] = A.matr[i][j] - B.matr[i][j];
        }
    }
    return res;
}

Matrix operator*(const Matrix &A, const Matrix &B) {
    Matrix res;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            double sum = 0;
            for (int k = 0; k < 4; ++k) {
                sum += A.matr[i][k] * B.matr[k][j];
                res.matr[i][j] = sum;
            }
        }
    }
    return res;
}

Matrix operator*(const Matrix &A, const double v) {
    Matrix res;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            res.matr[i][j] = A.matr[i][j] * v;
        }
    }
    return res;
}

Vector3D operator*(const Matrix &m, const Vector3D &v) {
    Vector3D res;
    res.setX(v.getX() * m.matr[0][0] + v.getY() * m.matr[0][1] + v.getZ() * m.matr[0][2] + m.matr[0][3]);
    res.setY(v.getX() * m.matr[1][0] + v.getY() * m.matr[1][1] + v.getZ() * m.matr[1][2] + m.matr[1][3]);
    res.setZ(v.getX() * m.matr[2][0] + v.getY() * m.matr[2][1] + v.getZ() * m.matr[2][2] + m.matr[2][3]);
    return res;
}

Matrix Matrix::translate(const Vector3D &loc) {
    Matrix res(1);
    res.matr[0][3] = loc.getX();
    res.matr[1][3] = loc.getY();
    res.matr[2][3] = loc.getZ();
    return res;
}

Matrix Matrix::scale(const Vector3D &v) {
    Matrix res(1);
    res.matr[0][0] = v.getX();
    res.matr[1][1] = v.getY();
    res.matr[2][2] = v.getZ();
    return res;
}

Matrix Matrix::scale(int size) {
    Matrix res(1);
    res.matr[0][0] = size;
    res.matr[1][1] = size;
    res.matr[2][2] = size;
    return res;
}

Matrix Matrix::rotateX(double angle) {
    Matrix res(1);
    double phi = RADIAN(angle);
    double cosinus = cos(phi);
    double sinus = sin(phi);
    res.matr[1][1] = cosinus;
    res.matr[1][2] = sinus;
    res.matr[2][1] = -sinus;
    res.matr[2][2] = cosinus;
    return res;
}

Matrix Matrix::rotateY(double angle) {
    Matrix res(1);
    double phi = RADIAN(angle);
    double cosinus = cos(phi);
    double sinus = sin(phi);
    res.matr[0][0] = cosinus;
    res.matr[0][2] = sinus;
    res.matr[2][0] = -sinus;
    res.matr[2][2] = cosinus;
    return res;
}

Matrix Matrix::rotateZ(double angle) {
    Matrix res(1);
    double phi = RADIAN(angle);
    double cosinus = cos(phi);
    double sinus = sin(phi);
    res.matr[0][0] = cosinus;
    res.matr[0][1] = sinus;
    res.matr[1][0] = -sinus;
    res.matr[1][1] = cosinus;
    return res;
}

Matrix Matrix::angleProjection(double k, double alpha) {
    Matrix res(1);
    double angle = RADIAN(alpha);
    res.matr[2][2] = 0;
    res.matr[2][0] = -k * cos(angle);
    res.matr[2][1] = -k * sin(angle);
    return res;
}
