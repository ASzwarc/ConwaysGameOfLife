#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

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
    void onButtonPressed();
private:
    Ui::MainWindow *ui;
    std::vector<std::vector<Cell*>> cellMatrix_;
};

#endif // MAINWINDOW_H
