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
            cellMatrix_[i][j] = (new Cell(i * cellWidth, j * cellHeight, cellWidth, cellHeight, nullptr, false));
            (cellMatrix_[i][j])->updateCellView();
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
    this->setCellsToNextState();
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
        (cellMatrix_[elem.first][elem.second])->updateCellView();
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
    for(int x = col - 1; x <= col + 1; x++)
    {
        for(int y = row - 1; y<= row + 1; y++)
        {
            if(y > 0 && y < 10 && x > 0 && x < 10 && (x != col || y != row))
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

bool MainWindow::isChangingState(int col, int row)
{
    /*
     * Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
     * Any live cell with two or three live neighbours lives on to the next generation.
     * Any live cell with more than three live neighbours dies, as if by overpopulation.
     * Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
     */
    int aliveNeighbours = countAliveNeighbours(col, row);
    if((cellMatrix_[col][row])->getCellState())
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

void MainWindow::setCellsToNextState()
{
    for(const auto& elem: cellsToChange_)
    {
        (cellMatrix_[elem.first][elem.second])->getCellState() ?
                    (cellMatrix_[elem.first][elem.second])->setCellState(false) :
                    (cellMatrix_[elem.first][elem.second])->setCellState(true);
        (cellMatrix_[elem.first][elem.second])->updateCellView();
    }
}

void MainWindow::cleanUp()
{
    cellsToChange_.clear();
}
