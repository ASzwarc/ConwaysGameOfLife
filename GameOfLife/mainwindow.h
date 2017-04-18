#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <list>
#include <memory>
#include "predefinedconfigurations.h"


namespace Ui {
class MainWindow;
}

class Cell;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void onStepButtonPressed();
private:
    bool setDesiredStartingCellState(Configuration::Type type);
    void evaluateNextState();
    void setCellsToNextState();
    bool isChangingState(int row, int col);
    void cleanUp();
    int countAliveNeighbours(int col, int row);
    void populateAvailableConfigurations();

    Ui::MainWindow *ui;
    std::vector<std::vector<Cell*>> cellMatrix_;
    std::list<std::pair<int, int>> cellsToChange_;
    std::list<std::shared_ptr<Configuration>> availableConfigurations_;

};

#endif // MAINWINDOW_H
