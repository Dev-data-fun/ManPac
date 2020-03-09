#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QRectF>
#include <QPainter>
#include <QPixmap>

class MyScene : public QGraphicsScene
{
public:
    MyScene(QObject *parent);
    void drawBackground(QPainter* painter, const QRectF &rect);
};

#endif // MYSCENE_H

