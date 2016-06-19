#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,ui->graphicsView->width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground (You can edit here)
    /*QPixmap background;
    background.load(":/image/bg.jpg");
    background.scaled(500,300);
    Bg = new QGraphicsPixmapItem;
    Bg->setPixmap(background);
    Bg->setPos(0,0);
    scene->addItem(Bg);*/
    itemList.push_back(new Bg(0,25,32,3,QPixmap(":/image/bg.jpg"),world,scene));
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));
    itemList.push_back(new cp(6,5.9,0.5,2,QPixmap(":/image/1.png").scaled(30,120),world,scene));

    // Create bird (You can edit here)
    birdie.push_back(new Bird(5.0f,10.0f,0.3f,&timer,QPixmap(":/bird.png").scaled(1.9*960/32,1.9*960/32),world,scene));
    birdie.push_back(new bird3(1.0f,15.0f,0.27f,&timer,QPixmap(":/image/bird3.png").scaled(1.7*960/32,2.0*960/32),world,scene));
    birdie.push_back(new bird2(1.0f,10.0f,0.27f,&timer,QPixmap(":/image/bird2.png").scaled(1.7*960/32,2.0*960/32),world,scene));


    itemList.push_back(new cp(5.3,5.9,0.5,2,QPixmap(":/image/2.png").scaled(30,70),world,scene));

    itemList.push_back(new block(15.0f,7.5f,1.0f,4.0f,&timer,QPixmap(":/image/stone2.png").scaled(width()/32.0*1,height()/18.0*5.5),world,scene));


    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(ready()));
    timer.start(100/6);
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    QMouseEvent *e = static_cast<QMouseEvent *>(event);
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        /* TODO : add your code here */
        //std::cout << "Press !" << std::endl ;
        if(num == 0)
        {
            if(use == 1)
            {
                birdie.at(i)->ability();
                use = 0;
            }
            num++;
        }

    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
        //std::cout << "x:" <<e->globalX() << std::endl ;
        //std::cout << "y:" <<e->globalY() << std::endl ;


    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        /* TODO : add your code here */
        if(num2 == 0)
        {
            shoot = 1;
            std::cout << "hi" << std::endl ;
            birdie.at(i)->setLinearVelocity(b2Vec2((666-e->globalX())/10,-(603-e->globalY())/10));
            num = 0;
            num2++;
        }

    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}

void MainWindow::ready()
{
    if(shoot == 1)
    {
        num1++;
        std::cout << num1 << std::endl ;
        use = 1;
        if(num1 == 300 && i<2)
        {
            i++;
            std::cout << i << std::endl ;
            birdie.at(i)->g_body->SetTransform(b2Vec2(5.3f,7.2f),birdie.at(i)->g_body->GetAngle());
            shoot = 0;
            num2 = 0;
            num1 = 0;
            use = 0;
        }
    }
}
