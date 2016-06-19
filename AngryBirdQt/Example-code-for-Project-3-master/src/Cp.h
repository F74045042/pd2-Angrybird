#ifndef CP_H
#define CP_H

#include <gameitem.h>
#include <QGraphicsScene>


class cp : public GameItem
{
public:
    cp(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // CP_H
