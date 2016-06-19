#ifndef BG_H
#define BG_H

#include <gameitem.h>
#include <QGraphicsScene>

class Bg : public GameItem
{
public:
    Bg(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);

};

#endif // BG_H
