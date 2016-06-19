#ifndef BLOCK_H
#define BLOCK_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>



class block : public GameItem
{
public:
    block(float x,float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // BLOCK_H
