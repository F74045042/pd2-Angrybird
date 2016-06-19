#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>

#include <gameitem.h>
#include <Cp.h>
#include <land.h>
#include <Bg.h>
#include <Block.h>
#include <bird.h>
#include <bird2.h>
#include <bird3.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    QList <Bird *> birdie;
    int num = 0;
    int i = 0;
    int j = 0;
    int use;
    int shoot = 0;
    int num1 = 0;
    int num2 = 0;

signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
    void ready();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
};

#endif // MAINWINDOW_H
