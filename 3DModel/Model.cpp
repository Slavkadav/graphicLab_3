//
// Created by User on 14.11.2017.
//

#include "Model.h"
#include <QDebug>

Model::Model(const QVector<QOpenGLTriangle3D> &model) : polygons(model) {
    for (int i = 0; i < polygons.length(); ++i) {
        Polygon polygon;
        Vector3D p1(polygons[i].p1.x(), polygons[i].p1.y(), polygons[i].p1.z());
        Vector3D p2(polygons[i].p2.x(), polygons[i].p2.y(), polygons[i].p2.z());
        Vector3D p3(polygons[i].p3.x(), polygons[i].p3.y(), polygons[i].p3.z());
        polygon.addPoint(p1);
        polygon.addPoint(p2);
        polygon.addPoint(p3);
        polygon.setId(i);
        polygon.setColor(QColor(QRgba64::fromRgba64(255, 255, 128, 64)));
        pol3d.append(polygon);
    }
}

void Model::draw(QPainter *painter) {
//    for (auto polygon: this->polygons) {
//
//        Vector3D points[3];
//
//        points[0] = this->transform * Vector3D(polygon.p1.x(), polygon.p1.y(), polygon.p1.z());
//        points[1] = this->transform * Vector3D(polygon.p2.x(), polygon.p2.y(), polygon.p2.z());
//        points[2] = this->transform * Vector3D(polygon.p3.x(), polygon.p3.y(), polygon.p3.z());
//
//
//
//        for (auto point:points) {
//            qPolygon << QPointF(point.getX(), point.getY());
//        }
//
//    }
    QList<Polygon> sortPols = draw3D();

            foreach(Polygon pol, sortPols) {
            QPolygonF qPolygon;
                    foreach(Vector3D point, pol.getPoints()) {
                    qPolygon << QPointF(point.getX(), point.getY());
                }
            painter->setBrush(pol.getColor());
            painter->drawPolygon(qPolygon);
        }


}

QList<Polygon> Model::draw3D() {
    QList<Polygon> sortedPolygonList;
    for (auto &i : pol3d) {
        Polygon mutatePol;
        mutatePol.setColor(i.getColor());
        mutatePol.setId(i.getId());
        for (const auto &j : i.getPoints()) {
            auto mutatePoint = transform * j;
            mutatePoint.normalize();
            mutatePol.addPoint(mutatePoint);
        }


        if (i.getId() == mutatePol.getId()) {
            mutatePol.setColor(QColor(Qt::yellow));
        }
        mutatePol.findMiddleZ();
        sortedPolygonList.append(mutatePol);
    }
    sortedPolygonList = Polygon::sort(sortedPolygonList);
    return sortedPolygonList;
}

void Model::setTransform(const Matrix &transform) {
    Model::transform = transform;
}

const QVector<QOpenGLTriangle3D> &Model::getPolygons() const {
    return polygons;
}

Polygon Model::getPolygon(QList<Polygon> polygons, QPoint location) {
    auto vector = new Vector3D(location.x(), location.y(), 0);
    for (int i = polygons.length() - 1; i >= 0; --i) {
        if (polygons[i].inside(*vector)) {
            return polygons[i];
        }
    }
}

Model::Model() = default;
