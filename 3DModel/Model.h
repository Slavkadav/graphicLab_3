//
// Created by User on 14.11.2017.
//

#ifndef GRAPHIC_LAB_2_MODEL_H
#define GRAPHIC_LAB_2_MODEL_H

#include <QtGui/QVector2D>
#include <QtGui/QVector3D>
#include <QtCore/QVector>
#include <QtGui/QPainter>
#include "../AffineTranslate/Vector/Vector3D.h"
#include "../AffineTranslate/Matrix/Matrix.h"

struct QOpenGLTriangle3D {
    QVector3D p1;
    QVector3D p2;
    QVector3D p3;
    QVector3D p1Normal;
    QVector3D p2Normal;
    QVector3D p3Normal;
    QVector2D p1UV;
    QVector2D p2UV;
    QVector2D p3UV;
};

class Model {

    QVector<QOpenGLTriangle3D> polygons;
    Matrix transform;
public:
    explicit Model(const QVector<QOpenGLTriangle3D> &model);

    Model();

    void draw(QPainter *painter);

    void setTransform(const Matrix &transform);
};


#endif //GRAPHIC_LAB_2_MODEL_H
