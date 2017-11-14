//
// Created by User on 14.11.2017.
//

#include "Vector.h"

Vector::Vector(double v) {
    x = y = z = v;
}

Vector::Vector(double vx, double vy, double vz) {
    x = vx;
    y = vy;
    z = vz;
}

Vector &Vector::operator=(double f) {
    x = y = z = f;
    return *this;
}

double operator&(const Vector &u, const Vector &v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

double Vector::getX() const {
    return x;
}

void Vector::setX(double x) {
    Vector::x = x;
}

double Vector::getY() const {
    return y;
}

void Vector::setY(double y) {
    Vector::y = y;
}

double Vector::getZ() const {
    return z;
}

void Vector::setZ(double z) {
    Vector::z = z;
}
