//
// Created by User on 13.11.2017.
//

#ifndef GRAPHIC_LAB_2_AFFINETRANSFORM_H
#define GRAPHIC_LAB_2_AFFINETRANSFORM_H


#include <Qt3DCore/QTransform>

enum Axis {
    X, Y, Z
};

class AffineTransform {

    void getRotateTransform(double phi, Axis axis);

    void getTranslateTransorm(double x, double y, double z);

};


#endif //GRAPHIC_LAB_2_AFFINETRANSFORM_H
