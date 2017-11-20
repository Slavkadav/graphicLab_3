//
// Created by User on 14.11.2017.
//

#include "Canvas.h"
#include <QDebug>

void Canvas::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    qDebug() << "Call paint event";
    this->frontView.setTransform(
            Matrix::scale(Vector3D(100, 100, 100)) * Matrix::translate(Vector3D(1, 1, 1)) * Matrix::rotateZ(180));
    this->frontView.draw(&painter);

    this->sideView.setTransform(
            Matrix::scale(Vector3D(100, 100, 100)) * Matrix::translate(Vector3D(2, 4, 1)) * Matrix::rotateZ(180) *
            Matrix::rotateY(90));
    this->sideView.draw(&painter);

    this->sideView.setTransform(
            Matrix::scale(Vector3D(100, 100, 100)) * Matrix::translate(Vector3D(6, 3, 1)) * Matrix::rotateX(90));
    this->sideView.draw(&painter);
}

Canvas::Canvas(Model model) : QWidget(), frontView(model) {
    this->sideView = Model(model);
    this->topView = Model(model);
}
