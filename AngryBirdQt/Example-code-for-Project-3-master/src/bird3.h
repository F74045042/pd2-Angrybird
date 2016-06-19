#ifndef BIRD3_H
#define BIRD3_H

#include <bird.h>


class bird3:public Bird
{
public:
    bird3(float x,float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void ability();
};

#endif // BIRD3_H
