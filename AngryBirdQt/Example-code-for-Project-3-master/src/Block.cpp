#include "Block.h"

block::block(float x,float y, float w,float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(w,h);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);
    b2PolygonShape bodyshape;
    bodyshape.SetAsBox(w/2,h/2);
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = 5;
    fixturedef.friction = 1;
    fixturedef.restitution = 0;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);


}
