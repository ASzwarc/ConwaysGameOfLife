#include "cell.h"
#include <QDebug>
#include <QBrush>
#include <QColor>

Cell::Cell(int posX, int posY, int height,
           int width, QObject* parent, bool defaultState):
    QGraphicsRectItem(posX, posY, height, width),
    state_(defaultState)
{
    if (state_)
        this->setBrush(QBrush(QColor(0, 0, 255)));
}

Cell::~Cell()
{
    qDebug() << "Cell destroyed!";
}

bool Cell::getCellState()
{
    return state_;
}

bool Cell::setCellState(bool state)
{
    state_ = state;
}
