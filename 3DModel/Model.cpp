//
// Created by User on 14.11.2017.
//

#include "Model.h"

Model::Model(const QVector<QOpenGLTriangle3D> &model) : model(model) {}

void Model::draw(QPainter *painter) {
    for (auto polygon: this->model) {
        QPolygonF qPolygon;
//        qPolygon << QPointF(polygon.p1.x(), polygon.p2.y()) << polygon.p2 << polygon.p3;
    }
}
