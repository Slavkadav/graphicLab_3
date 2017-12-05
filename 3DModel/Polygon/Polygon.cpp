//
// Created by dev on 03.12.17.
//

#include "Polygon.h"
#include "../../Canvas/Canvas.h"

Polygon::Polygon() {
}

void Polygon::addPoint(Vector3D point) {
    points.append(point);
}


void Polygon::findMiddleZ() {

    for (int i = 0; i < points.length(); ++i) {
        avgDepth += points[i].getZ();
    }
    avgDepth /= points.length();
}

bool Polygon::inside(Vector3D point) {
    auto a1 = new Vector3D(point.getX() - points[0].getX(),
                           point.getY() - points[0].getY(),
                           point.getZ() - points[0].getZ());
    auto a2 = new Vector3D(point.getX() - points[1].getX(),
                           point.getY() - points[1].getY(),
                           point.getZ() - points[1].getZ());

    auto r1 = a1->getX() * a2->getY() - a1->getY() * a2->getX();
    a1 = a2;
    for (int i = 2; i < points.length(); ++i) {
        a2 = new Vector3D(
                point.getX() - points[i % points.length()].getX(),
                point.getY() - points[i % points.length()].getY(),
                point.getY() - points[i % points.length()].getY()
        );
        auto r2 = a1->getX() * a2->getY() - a1->getY() * a2->getX();
        if (qAbs(r2) < 1e-6 || qAbs(r1) < 1e-6) return false;
        if (r1 > 0 != r2 > 0) return false;
        a1 = a2;
    }
    return true;
}

int Polygon::cover(Polygon p1, Polygon p2) {
    for (int i = 1; i < p1.points.length() + 1; ++i) {
        for (int j = 1; j < p2.points.length() + 1; ++j) {
            double zAB, zCD;
            auto inter = Vector3D::intersects(
                    p1.points[(i - 1) % p1.points.length()],
                    p1.points[i % p1.points.length()],
                    p2.points[(j - 1) % p2.points.length()],
                    p2.points[j % p2.points.length()],
                    &zAB,
                    &zCD
            );

            if (inter) {
                return zAB < zCD ? 1 : (qAbs(zAB - zCD) < 1e-6 ? 0 : -1);
            }
        }
    }

    bool f = true;
    bool m = true;
    for (int i = 1; i < p1.points.length() + 1; ++i) {
        f = f && p2.inside(p1.points[(i - 1) % p1.points.length()]);
        m = m && p1.inside(p2.points[(i - 1) % p2.points.length()]);
    }
    if (f || m) {
        auto center = m ? p1 : p2;
        QList<Polygon> list;
        list.append(f ? p1 : p2);
        return intersectsPinP(
                Canvas::getCenter(list),
                center.getPoints()[0],
                center.getPoints()[1],
                center.getPoints()[2]
        );
    }

    return 0;
}

int Polygon::intersectsPinP(Vector3D E, Vector3D v0, Vector3D v1, Vector3D v2) {
    double Ex0 = E.getX() - v0.getX();
    double Ey0 = E.getY() - v0.getY();

    double x10 = v1.getX() - v0.getX();
    double x20 = v2.getX() - v0.getX();

    double y10 = v1.getY() - v0.getY();
    double y20 = v2.getY() - v0.getY();

    double z10 = v1.getZ() - v0.getZ();
    double z20 = v2.getZ() - v0.getZ();

    double A = Ex0 * y10 * z20 + Ey0 * z10 * x20;
    double B = Ex0 * z10 * y20 + Ey0 * x10 * z20;
    double Z = v0.getZ() + (B - A) / (x10 * y20 - y10 * x20);

    return E.getZ() < Z ? 1 : (qAbs(E.getZ() - Z) < 1e-6 ? 0 : -1);
}

const QList<Vector3D> &Polygon::getPoints() const {
    return points;
}


QList<Polygon> Polygon::sort(QList<Polygon> polygons) {
    QList<Polygon> list;

    while (polygons.length() > 0) {
        auto p = polygons[0];
        for (const auto &polygon : polygons) {
            if (cover(p, polygon) == -1) {
                p = polygon;
            }
        }
        list.append(p);
        polygons.removeAll(p);
    }

    return list;
}

void Polygon::setPoints(const QList<Vector3D> &points) {
    Polygon::points = points;
}

qreal Polygon::getAvgDepth() const {
    return avgDepth;
}

void Polygon::setAvgDepth(qreal avgDepth) {
    Polygon::avgDepth = avgDepth;
}

int Polygon::getId() const {
    return id;
}

void Polygon::setId(int id) {
    Polygon::id = id;
}

const QColor &Polygon::getColor() const {
    return color;
}

void Polygon::setColor(const QColor &color) {
    Polygon::color = color;
}

bool Polygon::operator==(const Polygon &rhs) const {
    return points == rhs.points &&
           color == rhs.color &&
           avgDepth == rhs.avgDepth &&
           id == rhs.id;
}

bool Polygon::operator!=(const Polygon &rhs) const {
    return !(rhs == *this);
}
