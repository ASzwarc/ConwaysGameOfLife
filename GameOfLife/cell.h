#ifndef CELL_H
#define CELL_H

#include <QObject>
#include <QGraphicsRectItem>

class Cell: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Cell(int posX, int posY, int height, int width, QObject* parent = nullptr);
    ~Cell();
};

#endif // CELL_H
