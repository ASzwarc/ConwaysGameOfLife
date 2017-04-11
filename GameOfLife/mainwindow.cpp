#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.h"
#include <QGraphicsScene>
#include <QDebug>
#include <random>
#include <utility>
#include <memory>

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
        cellMatrix_.push_back(std::vector<Cell*>(10, nullptr));
        for(int j = 0; j < 10; j++)
        {
            cellMatrix_[i][j] = (new Cell(i * cellHeight, j * cellWidth, cellHeight, cellWidth, nullptr, false));
            ui->mainGraphicsView->scene()->addItem(cellMatrix_[i][j]);
        }
    }
    if(setDesiredStartingCellState(Configuration::Type::Glider))
    {
        qDebug() << "Desired state was set";
    }
    ui->mainGraphicsView->show();
    connect(ui->stepButton, SIGNAL(pressed()), this, SLOT(onStepButtonPressed()));
}

void MainWindow::onStepButtonPressed()
{
    qDebug() << "Next step";
    this->evaluateNextState();
    //set states
    cleanUp();
}

bool MainWindow::setDesiredStartingCellState(Configuration::Type type)
{
    std::shared_ptr<Configuration> configuration;
    switch(type)
    {
        case Configuration::Type::Glider:
            configuration = std::make_shared<GliderConfiguration>();
            break;
        default:
            qDebug() << "Configuration is not supported!";
            return false;
    }
    for(const auto& elem: configuration->activeCells_)
    {
        (cellMatrix_[elem.first][elem.second])->setCellState(true);
    }
    return true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::countAliveNeighbours(int col, int row)
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

    return aliveNeighbours;
}

bool MainWindow::isChangingState(int row, int col)
{
    int aliveNeighbours = countAliveNeighbours(col, row);
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
    return false;
}

void MainWindow::evaluateNextState()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(isChangingState(i, j))
            {
                cellsToChange_.emplace_back(std::make_pair(i, j));
                qDebug() << "Cell[" << i << ", " << j << "] is changing state.";
            }
        }
    }
}

void MainWindow::cleanUp()
{
    cellsToChange_.clear();
}
