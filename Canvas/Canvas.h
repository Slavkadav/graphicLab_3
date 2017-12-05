//
// Created by User on 14.11.2017.
//

#ifndef GRAPHIC_LAB_2_CANVAS_H
#define GRAPHIC_LAB_2_CANVAS_H


#include <QtWidgets/QWidget>
#include "../3DModel/Model.h"
#include "../3DModel/Polygon/Polygon.h"

class Canvas : public QWidget {
public:
    explicit Canvas(Model model);

    static Vector3D getCenter(QList<Polygon> polygons);
private:
    Model frontView;
    Model sideView;
    Model topView;
    Model rollView;
    double angleX = 0;
    double angleY = 0;
protected:
    void paintEvent(QPaintEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

    Polygon GetPolygon(QList<Polygon> polygons, QPoint location);

    void loadObj();

    Polygon getPolygon(QList<Polygon> polygons, QPoint location);
};


#endif //GRAPHIC_LAB_2_CANVAS_H
