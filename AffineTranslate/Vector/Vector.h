//
// Created by User on 14.11.2017.
//

#ifndef GRAPHIC_LAB_2_VECTOR_H
#define GRAPHIC_LAB_2_VECTOR_H


class Vector {
    double x, y, z;
public:
    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    double getZ() const;

    void setZ(double z);

private:
    Vector(double v);

    Vector(const Vector &v);

    Vector(double vx, double vy, double vz);

    Vector &operator=(double f);

    friend double operator&(const Vector &u, const Vector &v);
};


#endif //GRAPHIC_LAB_2_VECTOR_H
