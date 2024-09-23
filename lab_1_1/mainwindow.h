#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "shape.h"

#include <QMainWindow>
#include <Qpainter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_ComboBox_currentIndexChanged(int index);

    void on_action_3_triggered();

    void on_action_triggered();

    void on_action_2_triggered();

private:
    Ui::MainWindow *ui;
    Shape* cur_figure;
};

#endif // MAINWINDOW_H
