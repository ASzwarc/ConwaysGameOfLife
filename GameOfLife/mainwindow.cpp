#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.h"
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene* scene = new QGraphicsScene(0, 0, 600, 600, ui->mainGraphicsView);
    int cellHeight = 60;
    int cellWidth = 60;
    ui->mainGraphicsView->setScene(scene);
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            Cell* cell = new Cell(i * cellHeight, j * cellWidth, cellHeight, cellWidth);
            ui->mainGraphicsView->scene()->addItem(cell);
        }
    }
    ui->mainGraphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
