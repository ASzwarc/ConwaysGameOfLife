#ifndef CELL_H
#define CELL_H

#include <QObject>
#include <QGraphicsRectItem>

class Cell: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Cell(int posX, int posY, int width, int height, QObject* parent = nullptr, bool defaultState = false);
    ~Cell();
    bool getCellState();
    void setCellState(bool state);
    void updateCellView();
private:
    bool state_;
};

#endif // CELL_H
