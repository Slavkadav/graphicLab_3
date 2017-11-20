//
// Created by User on 14.11.2017.
//

#include "Canvas.h"
#include <QDebug>
#include <QKeyEvent>

void Canvas::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    this->frontView.setTransform(
            Matrix::translate(Vector3D(width() / 4, height() / 4, 1)) * Matrix::scale(75) * Matrix::rotateZ(180));
    this->frontView.draw(&painter);

    this->sideView.setTransform(
            Matrix::translate(Vector3D(width() / 4, height() * 3 / 4, 1)) * Matrix::scale(75) * Matrix::rotateZ(180) *
            Matrix::rotateY(90));
    this->sideView.draw(&painter);

    this->topView.setTransform(
            Matrix::translate(Vector3D(width() * 3 / 4, height() / 4, 1)) * Matrix::scale(75) * Matrix::rotateX(90));
    this->topView.draw(&painter);


    this->rollView.setTransform(
            Matrix::translate(Vector3D(width() * 3 / 4, height() * 3 / 4, 1)) * Matrix::scale(75) *
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
