//
// Created by User on 14.11.2017.
//

#include "Model.h"
#include <QDebug>

Model::Model(const QVector<QOpenGLTriangle3D> &model) : polygons(model) {}

void Model::draw(QPainter *painter) {
    for (auto polygon: this->polygons) {

        Vector3D points[3];

        points[0] = this->transform * Vector3D(polygon.p1.x(), polygon.p1.y(), polygon.p1.z());
        points[1] = this->transform * Vector3D(polygon.p2.x(), polygon.p2.y(), polygon.p2.z());
        points[2] = this->transform * Vector3D(polygon.p3.x(), polygon.p3.y(), polygon.p3.z());


        QPolygonF qPolygon;
        for (auto point:points) {
            qPolygon << QPointF(point.getX(), point.getY());
        }
        painter->drawPolygon(qPolygon);
    }
}


void Model::setTransform(const Matrix &transform) {
    Model::transform = transform;
}

Model::Model() = default;
