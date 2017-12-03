//
// Created by dev on 03.12.17.
//

#ifndef GRAPHIC_LAB_2_POLYGON_H
#define GRAPHIC_LAB_2_POLYGON_H


#include <QtCore/QList>
#include <QtGui/QColor>
#include "../../AffineTranslate/Vector/Vector3D.h"

class Polygon {
private:
    QList<Vector3D> points;
    QColor color;
    qreal avgDepth;
    int id;
public:
    Polygon();

    void addPoint(Vector3D point);

    const QList<Vector3D> &getPoints() const;

    void findMiddleZ();

    bool inside(Vector3D point);

    int cover(Polygon p1, Polygon p2);

    int intersectsPinP(Vector3D E, Vector3D v0, Vector3D v1, Vector3D v2);

    QList<Polygon> sort(QList<Polygon> polygons);
};


#endif //GRAPHIC_LAB_2_POLYGON_H
