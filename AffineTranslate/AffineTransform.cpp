//
// Created by User on 13.11.2017.
//

#include <cmath>
#include <QtGui/QtGui>
#include "AffineTransform.h"

void AffineTransform::getRotateTransform(double phi, Axis axis) {
    QMatrix4x4 *matrix4x4 = nullptr;
    phi = qDegreesToRadians(phi);
    switch (axis) {
        case X:
            matrix4x4 = new QMatrix4x4(
                    1, 0, 0, 0,
                    0, cos(phi), sin(phi), 0,
                    0, -sin(phi), cos(phi), 0,
                    0, 0, 0, 1
            );
            break;
        case Y:
            matrix4x4 = new QMatrix4x4(
                    cos(phi), 0, -sin(phi), 0,
                    0, 1, 0, 0,
                    sin(phi), 0, cos(phi), 0,
                    0, 0, 0, 1
            );
            break;
        case Z:
            matrix4x4 = new QMatrix4x4(
                    cos(phi), sin(phi), 0, 0,
                    -sin(phi), cos(phi), 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 1
            );
            break;
    }
    Qt3DCore::QTransform transform;
    transform.setMatrix(*matrix4x4);
}

void AffineTransform::getTranslateTransorm(double x, double y, double z) {
    QMatrix4x4 matrix4x4(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            x, y, z, 1
    );
    Qt3DCore::QTransform transform;
    transform.setMatrix(matrix4x4);
}