#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <list>
#include <pair>

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
    void evaluateNextState();
    bool isChangingState(int row, int col);
    Ui::MainWindow *ui;
    std::vector<std::vector<Cell*>> cellMatrix_;
    std::list<std::pair<int, int>> cellsToChange_;
};

#endif // MAINWINDOW_H
