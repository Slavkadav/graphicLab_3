//
// Created by User on 14.11.2017.
//

#include <QtMath>
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

bool Vector3D::intersects(Vector3D a, Vector3D b, Vector3D c, Vector3D d, double *zAB, double *zCD) {
    *zAB = 0;
    *zCD = 0;
    bool isLine = false;
    auto ab = new Vector3D(b.getX() - a.getX(), b.getY() - a.getY(), 0);
    auto cd = new Vector3D(d.getX() - c.getX(), d.getY() - c.getY(), 0);
    double A1 = -ab->getY();
    double B1 = ab->getX();
    double C1 = -A1 * a.getX() - B1 * a.getY();

    double A2 = -cd->getY();
    double B2 = cd->getX();
    double C2 = -A2 * c.getX() - B2 * c.getY();

    double D = A1 * B2 - A2 * B1;
    double Dx = -C1 * B2 + C2 * B1;
    double Dy = -C2 * A1 + C1 * A2;

    if (qAbs(D) < 1e-6) return false;

    double ox = Dx / D;
    double oy = Dy / D;

    if (!isLine) {
        if (!(qMin(a.getX(), b.getX()) <= ox && ox <= qMax(a.getX(), b.getX()))) return false;

        if (!(qMin(a.getY(), b.getY()) <= oy && oy <= qMax(a.getY(), b.getY()))) return false;

        if (!(qMin(c.getX(), d.getX()) <= ox && ox <= qMax(c.getX(), d.getX()))) return false;

        if (!(qMin(c.getY(), d.getY()) <= oy && oy <= qMax(c.getY(), d.getY()))) return false;
    }

    *zAB = getZ1(ox, oy, a.getX(), a.getY(), a.getZ(), b.getX(), b.getY(), b.getZ());
    *zCD = getZ1(ox, oy, c.getX(), c.getY(), c.getZ(), d.getX(), d.getY(), d.getZ());
}

double Vector3D::getZ1(double ox, double oy, double Ax, double Ay, double Az, double Bx, double By, double Bz) {
    if (qAbs(Bx - Ax) > qAbs(By - Ay)) {
        return (ox - Ax) / (Bx - Ax) * (Bz - Az) + Az;
    }

    if (qAbs(Bx - Ax) < qAbs(By - Ay)) {
        return (oy - Ay) / (By - Ay) * (Bz - Az) + Az;
    }
    if (qAbs(Bx - Ax) < 1e-6) { return 0; }

    return (ox - Ax) / (Bx - Ax) * (Bz - Az) + Az;
}

void Vector3D::normalize() {
    x /= h;
    y /= h;
    z /= h;
    h = 1;
}

bool Vector3D::operator==(const Vector3D &rhs) const {
    return x == rhs.x &&
           y == rhs.y &&
           z == rhs.z &&
           h == rhs.h;
}

bool Vector3D::operator!=(const Vector3D &rhs) const {
    return !(rhs == *this);
}
