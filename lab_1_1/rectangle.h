#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QAction>
#include <QString>


#include "shape.h"
class Rectangle : public Shape
{
    Q_OBJECT
public:
    Rectangle(int width = 50, int height = 30);
    void paintEvent(QPaintEvent *) override {
        QPainter painter;
        painter.begin(this);
        painter.drawRect(0, 0, width, height);
        painter.end();
    }

    virtual void set_default()  override {
        width = 50;
        height = 30;
        height_line->setText(QString::number(height));
        width_line->setText(QString::number(width));

        get_area();
        this->update();
    }

    void get_area() const override {
        area_line->setText("S = " + QString::number(width * height));
    }
    void create_input_form(QVBoxLayout*& params) const override {
        QLayoutItem *item;
             while ((item = params->takeAt(0))) {
                 delete item->widget();
                 delete item;
             }
        QLabel* text_width = new QLabel;
        text_width->setText("Введите ширину");
        params->addWidget(text_width);
        params->addWidget(width_line);

        QLabel* text_height = new QLabel;
        connect(height_line,  &QLineEdit::textChanged, this, &Rectangle::read_height);
        connect(width_line, &QLineEdit::textChanged, this, &Rectangle::read_width);
        width_line->setText(QString::number(width));
        height_line->setText(QString::number(height));
        text_height->setText("Введите длинну");
        params->addWidget(text_height);
        params->addWidget(height_line);
        params->addWidget(area_line);
    }

private slots:
    void read_height(const QString& digit) {
        height = digit.toInt();
        this->update();
        get_area();
    }

    void read_width(const QString& digit) {
        width = digit.toInt();
        this->update();
        get_area();

    }

private:

    int width;
    int height;
    QLineEdit* height_line;
    QLineEdit* width_line;

};

#endif // RECTANGLE_H
