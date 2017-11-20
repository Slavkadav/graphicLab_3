//
// Created by User on 14.11.2017.
//

#include "Vector3D.h"

Vector3D::Vector3D(double v) {
    x = y = z = v;
}

Vector3D::Vector3D(double vx, double vy, double vz) {
    x = vx;
    y = vy;
    z = vz;
}

Vector3D &Vector3D::operator=(double f) {
    x = y = z = f;
    return *this;
}

double operator&(const Vector3D &u, const Vector3D &v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

double Vector3D::getX() const {
    return x;
}

void Vector3D::setX(double x) {
    Vector3D::x = x;
}

double Vector3D::getY() const {
    return y;
}

void Vector3D::setY(double y) {
    Vector3D::y = y;
}

double Vector3D::getZ() const {
    return z;
}

void Vector3D::setZ(double z) {
    Vector3D::z = z;
}
