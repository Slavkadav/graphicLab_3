//
// Created by User on 14.11.2017.
//

#ifndef GRAPHIC_LAB_2_VECTOR_H
#define GRAPHIC_LAB_2_VECTOR_H


class Vector3D {
    double x{}, y{}, z{};
public:
    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    double getZ() const;

    void setZ(double z);

    Vector3D() = default;;

    explicit Vector3D(double v);

//    Vector3D(const Vector3D &v);

    Vector3D(double vx, double vy, double vz);

    Vector3D &operator=(double f);

    friend double operator&(const Vector3D &u, const Vector3D &v);

    static bool
    intersects(Vector3D a, Vector3D b, Vector3D c, Vector3D d, double *zAb, double *zCD, bool isLine = false);

    double getZ(double ox, double oy, double Ax, double Ay, double Az, double Bx, double By, double Bz);
};


#endif //GRAPHIC_LAB_2_VECTOR_H
