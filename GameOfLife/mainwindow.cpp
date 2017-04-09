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
    //Change random generation to some predefined starting points like Glider, Exploder, Tumbler etc.
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
    connect(ui->stepButton, SIGNAL(pressed()), this, SLOT(onStepButtonPressed()));
}

void MainWindow::onStepButtonPressed()
{
    qDebug() << "Next step";
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isChangingState(int row, int col)
{
    int aliveNeighbours = 0;
    for(int x = row - 1; x <= row + 1; x++)
    {
        for(int y = col - 1; y<= col + 1; y++)
        {
            if(y > 0 && y < 10 && y != row && x > 0 && x < 10 && x != row)
            {
                if((cellMatrix_[x][y])->getCellState())
                {
                    aliveNeighbours++;
                }
            }
        }
    }
    if((cellMatrix_[row][col])->getCellState())
    {
        if(aliveNeighbours < 2 && aliveNeighbours > 3)
            return true;
    }
    else
    {
        if(aliveNeighbours == 3)
            return true;
    }
}

void MainWindow::evaluateNextState()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(isChangingState(i, j))
            {
                //add cell to list
                qDebug() << "Cell[" << i << ", " << j << "] is changing state.";
            }
        }
    }
}
