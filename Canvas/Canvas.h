//
// Created by User on 14.11.2017.
//

#ifndef GRAPHIC_LAB_2_CANVAS_H
#define GRAPHIC_LAB_2_CANVAS_H


#include <QtWidgets/QWidget>
#include "../3DModel/Model.h"

class Canvas : public QWidget {
public:
    explicit Canvas(Model model);

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

};


#endif //GRAPHIC_LAB_2_CANVAS_H
