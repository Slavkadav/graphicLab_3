#include <iostream>
#include <QtWidgets/QApplication>
#include <QtCore/QFile>
#include <QtCore/QVector>
#include <QtGui/QVector2D>
#include <QtGui/QVector3D>
#include <QRegularExpression>
#include <QDebug>
#include <QtCore/QDir>
#include "3DModel/Model.h"
#include "Canvas/Canvas.h"

void parseObjFile(const QString &fileName,
                  QStringList comments,
                  QVector<QOpenGLTriangle3D> &triangles) {
    comments.clear();
    triangles.clear();
    QFile file(fileName);
    if (file.exists()) {
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            QVector<QVector3D> v, vn;
            QVector<QVector2D> vt;
            int i = 0;
            while (!file.atEnd()) {
                QString line = file.readLine().trimmed();
                QStringList lineParts = line.split(QRegularExpression("\\s+"));
                if (lineParts.count() > 1) {
                    // if it’s a comment
                    if (lineParts.at(0).compare("#", Qt::CaseInsensitive) == 0) {
                        comments.append(line.remove(0, 1).trimmed());
                    }

                        // if it’s a vertex position (v)
                    else if (lineParts.at(0).compare("v", Qt::CaseInsensitive) == 0) {
                        v.append(QVector3D(lineParts.at(1).toFloat(),
                                           lineParts.at(2).toFloat(),
                                           lineParts.at(3).toFloat()));
                    }

                        // if it’s a normal (vn)
                    else if (lineParts.at(0).compare("vn", Qt::CaseInsensitive) == 0) {
                        vn.append(QVector3D(lineParts.at(1).toFloat(),
                                            lineParts.at(2).toFloat(),
                                            lineParts.at(3).toFloat()));
                    }

                        // if it’s a texture (vt)
                    else if (lineParts.at(0).compare("vt", Qt::CaseInsensitive) == 0) {
                        vt.append(QVector2D(lineParts.at(1).toFloat(),
                                            lineParts.at(2).toFloat()));
                    }

                        // if it’s face data (f)
                        // there’s an assumption here that faces are all triangles
                    else if (lineParts.at(0).compare("f", Qt::CaseInsensitive) == 0) {
                        QOpenGLTriangle3D triangle;

                        // get points from v array
                        triangle.p1 = v.at(lineParts.at(1).split("/").at(0).toInt() - 1);
                        triangle.p2 = v.at(lineParts.at(2).split("/").at(0).toInt() - 1);
                        triangle.p3 = v.at(lineParts.at(3).split("/").at(0).toInt() - 1);

                        if (vt.count() > 0) // check if really there are any UV coords
                        {
                            triangle.p1UV = vt.at(lineParts.at(1).split("/").at(1).toInt() - 1);
                            triangle.p2UV = vt.at(lineParts.at(2).split("/").at(1).toInt() - 1);
                            triangle.p3UV = vt.at(lineParts.at(3).split("/").at(1).toInt() - 1);
                        }

                        // get normals from vn array
                        triangle.p1Normal = vn.at(lineParts.at(1).split("/").at(2).toInt() - 1);
                        triangle.p2Normal = vn.at(lineParts.at(2).split("/").at(2).toInt() - 1);
                        triangle.p3Normal = vn.at(lineParts.at(3).split("/").at(2).toInt() - 1);

                        triangles.append(triangle);
                    }

                }
            }
            qDebug() << triangles.length();
            file.close();
        }
    }
}


int main(int argc, char **argv) {

    QApplication application(argc, argv);

    QString filename = "Porsche_911_GT2.obj";
    QStringList comments;
    QVector<QOpenGLTriangle3D> vector;

    parseObjFile(filename, comments, vector);

    qDebug() << vector.length();

    Model model(vector);

    Canvas canvas(model);

    canvas.setFixedSize(1024, 768);

    canvas.show();

    return application.exec();
}



