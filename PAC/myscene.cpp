#include "myscene.h"

MyScene::MyScene(QObject *parent):QGraphicsScene(parent)
{

}

void MyScene::drawBackground(QPainter* painter,const QRectF &rect){
    const QPixmap pm(":/images/images/layout.png");
    painter->drawPixmap(0,0,pm.width(),pm.height(),pm);
    this->setSceneRect(0,0,pm.width(),pm.height());
}
