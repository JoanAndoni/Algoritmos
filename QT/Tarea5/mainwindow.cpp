#include "mainwindow.h"
#include "ui_mainwindow.h"

//Include all the libraries that we are going to need

#include <QGraphicsItem>
#include <QtGui>
#include <iostream>
#include <QDebug>
#include <QPainterPath>
#include <QTransform>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsItem>
#include <QList>
#include <QRect>
#include <QWidget>
#include <QInputDialog>
#include <QPainter>

/*  void poligono(float m);
    void cubo(float m);
    void cono(float m);
    void prismaRectangular(float m);
    void prismaTriangular(float m);
    void arco(float m);
*/

int opcion;
QPainterPath poligono;
QPainterPath cubo;
QPainterPath cono;
QPainterPath prismaRectangular;
QPainterPath prismaTriangular;
QPainterPath arco;
QPointF punto;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    escena = new QGraphicsScene;
    escena->setSceneRect(0,0,290,235);
    ui->view->setScene(escena);
    ui->view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printPoligono(int show){

}
void MainWindow::printCubo(int show){
    punto.setX();
    punto.setY();
    punto.lineTo(-40, 40, 40, 40);
      painter.drawLine(-40, 40, -40, -40);
            painter.drawLine(40, 40, 40, -40);
            painter.drawLine(-40, -40, 40, -40);
            painter.drawLine(0, 0, 80, 0);
            painter.drawLine(0, 0, 0, -80);
            painter.drawLine(80, 0, 80, -80);
            painter.drawLine(0, -80, 80, -80);
            painter.drawLine(-40, 40, 0, 0);
            painter.drawLine(40, 40, 80, 0);
            painter.drawLine(-40, -40, 0, -80);
    painter.drawLine(40, -40, 80, -80);

    escena->addPath(cubo);
    ui->view->setScene(escena);
    ui->view->show();
}
void MainWindow::printCono(int show){

}
void MainWindow::printPrismaRectangular(int show){

}
void MainWindow::printPrismaTriangular(int show){

}
void MainWindow::printArco(int show){

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    opcion = index;
    escena->clear();
    switch(index){
        case 0:
        //printPoligono(1);
        break;

        case 1:
        printCubo(1);
        break;

        case 2:
        //printCono(1);
        break;

        case 3:
        //printPrismaRectangular(1);
        break;

        case 4:
        //printPrismaTriangular(1);
        break;

        case 5:
        //printArco(1);
        break;
    }
}
