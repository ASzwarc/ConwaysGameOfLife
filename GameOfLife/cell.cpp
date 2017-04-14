#include "cell.h"
#include <QDebug>
#include <QBrush>
#include <QColor>

Cell::Cell(int posX, int posY, int width,
           int height, QObject* parent, bool defaultState):
    QGraphicsRectItem(posX, posY, width, height),
    state_(defaultState)
{
}

Cell::~Cell()
{
    qDebug() << "Cell destroyed!";
}

bool Cell::getCellState()
{
    return state_;
}

void Cell::setCellState(bool state)
{
    state_ = state;
}

void Cell::updateCellView()
{
    if (state_)
        this->setBrush(QBrush(QColor(0, 0, 255)));
    else
        this->setBrush(QBrush(QColor(255, 255, 255)));
}
