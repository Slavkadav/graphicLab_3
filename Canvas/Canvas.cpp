//
// Created by User on 14.11.2017.
//

#include "Canvas.h"
#include <QDebug>
#include <QKeyEvent>

void Canvas::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    this->rollView.setTransform(
            Matrix::translate(Vector3D(width() / 2, height() / 2, 1)) * Matrix::scale(100) *
            Matrix::rotateX(90 + angleX) * Matrix::rotateY(angleY)
    );
    this->rollView.draw(&painter);
}

Canvas::Canvas(Model model) : QWidget(), frontView(model) {
    this->sideView = Model(model);
    this->topView = Model(model);
    this->frontView = Model(model);
    this->rollView = Model(model);
}

void Canvas::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Up:
            angleX++;
            break;
        case Qt::Key_Down:
            angleX--;
            break;
        case Qt::Key_Left:
            angleY--;
            break;
        case Qt::Key_Right:
            angleY++;
            break;
    }
    update();

}

Vector3D Canvas::getCenter(QList<Polygon> polygons) {
    double ox = 0;
    double oy = 0;
    double oz = 0;
    int count = 0;

            foreach(Polygon polygon, polygons) {
                    foreach(Vector3D point, polygon.getPoints()) {
                    ox += point.getX();
                    oy += point.getY();
                    oz += point.getZ();
                    count++;
                }
        }

    return {-ox / count, -oy / count, -oz / count};


}


