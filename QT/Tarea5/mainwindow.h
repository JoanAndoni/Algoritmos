#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <cstdio>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void printPoligono(int show);
    void printCubo(int show);
    void printCono(int show);
    void printPrismaRectangular(int show);
    void printPrismaTriangular(int show);
    void printArco(int show);

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QGraphicsScene * escena = new QGraphicsScene;
};

#endif // MAINWINDOW_H
