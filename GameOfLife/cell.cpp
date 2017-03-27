#include "cell.h"
#include <QDebug>

Cell::Cell(int posX, int posY, int height, int width, QObject* parent):
    QGraphicsRectItem(posX, posY, height, width)
{

}
Cell::~Cell()
{
    qDebug() << "Cell destroyed!";
}
