#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.h"
#include <QGraphicsScene>
#include <QDebug>
#include <random>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene* scene = new QGraphicsScene(0, 0, 600, 600, ui->mainGraphicsView);
    int cellHeight = 60;
    int cellWidth = 60;
    ui->mainGraphicsView->setScene(scene);
    std::default_random_engine engine((std::random_device())());
    std::uniform_int_distribution<int> uni_dist(0, 2);
    bool state = false;
    for(int i = 0; i < 10; i++)
    {
        cellMatrix_.push_back(std::vector<Cell*>(10, nullptr));
        for(int j = 0; j < 10; j++)
        {
            state = static_cast<bool>(uni_dist(engine));
            qDebug() << "Random state is: " << state;
            cellMatrix_[i][j] = (new Cell(i * cellHeight, j * cellWidth, cellHeight, cellWidth, nullptr, state));
            ui->mainGraphicsView->scene()->addItem(cellMatrix_[i][j]);
        }
    }
    ui->mainGraphicsView->show();
    connect(ui->stepButton, SIGNAL(pressed()), this, SLOT(onButtonPressed()));
}

void MainWindow::onButtonPressed()
{
    qDebug() << "Button was pressed";
}

MainWindow::~MainWindow()
{
    delete ui;
}
