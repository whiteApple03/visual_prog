#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <shapefactory.h>

#include <QPainter>
#include <QtDebug>
#include <QtWidgets>
#include <QLabel>
#include <QDebug>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);

//    this->setFixedSize((QSize(1000, 500)));
    cur_figure = nullptr;
    ShapeFactory factory;

    cur_figure = factory.create(0);
    cur_figure->create_input_form(ui->params);
    ui->ShapePlace->addWidget(cur_figure);
    ui->ShapePlace->addWidget(cur_figure->getFormula());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ComboBox_currentIndexChanged(int index)
{
    ShapeFactory* factory = new ShapeFactory;

    Shape* figure = factory->create(index);

    if (cur_figure != nullptr && figure != nullptr) {
        ui->ShapePlace->replaceWidget(cur_figure, figure);
        ui->ShapePlace->replaceWidget(cur_figure->getFormula(), figure->getFormula());
        figure->create_input_form(ui->params);
        delete cur_figure;
    } else if (figure != nullptr) {
        figure->create_input_form(ui->params);
        ui->ShapePlace->addWidget(figure);
        ui->ShapePlace->addWidget(figure->getFormula());

    }
    if (figure != nullptr) {
        cur_figure = figure;
    }

}


void MainWindow::on_action_3_triggered()
{
    this->close();
}

void MainWindow::on_action_triggered()
{
    QMessageBox message;
    message.about(this, "Автор", "Дель Александр ИП-211");
}

void MainWindow::on_action_2_triggered()
{
    cur_figure->set_default();
}
