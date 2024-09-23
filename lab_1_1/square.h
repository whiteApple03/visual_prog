#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QtDebug>
class Square : public Shape
{
    Q_OBJECT
public:
    Square(int width = 50) : Shape(), a{width} {
        formula = new Formulas("S = a^2");
        widht_line = new QLineEdit;
        get_area();

    }

    void paintEvent(QPaintEvent *) override {
        QPainter painter;
        painter.begin(this);
        painter.drawRect(0, 0, a, a);
        painter.end();
    }


    virtual void set_default() override {
        this->a = 50;
        widht_line->setText(QString::number(a));
        get_area();
        this->update();
        return;
    }

    void get_area() const override {
         area_line->setText("S = " + QString::number(a*a));
    }


    void create_input_form(QVBoxLayout*& params) const override {
        QLayoutItem *item;
             while ((item = params->takeAt(0))) {
                 delete item->widget();
                 delete item;
             }

        QLabel* text_height = new QLabel;

        connect(widht_line, &QLineEdit::textChanged, this, &Square::read_width);
        widht_line->setText(QString::number(a));

        text_height->setText("Введите длинну");
        params->addWidget(text_height);
        params->addWidget(widht_line);
        params->addWidget(area_line);

    }
private slots:
    void read_width(const QString& digit) {
        a = digit.toInt();
        get_area();
        this->update();
    }

private:
    int const DEFAULT_LENGHT = 50;
    int a;
    QLineEdit* widht_line;
};

#endif // SQUARE_H
