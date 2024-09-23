#ifndef CIRCLE_H
#define CIRCLE_H
#include <shape.h>
#include <QtMath>

#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QAction>
#include <QString>

class Circle : public Shape
{
    Q_OBJECT
public:
    Circle(int radius = 50) : Shape(), radius{radius} {
        formula = new Formulas("S = pi * r^2");
        radius_line = new QLineEdit;

        get_area();
    }

    void paintEvent(QPaintEvent *) override {
        QPainter painter;
        painter.begin(this);
        painter.drawEllipse(0, 0, radius*2, radius*2);
        painter.end();
    }

    virtual void set_default()  override {
        radius = 50;
        radius_line->setText(QString::number(radius));
        get_area();
        this->update();
    }

    void get_area() const override {
        area_line->setText("S = " + QString::number(M_PI * radius*radius));
    }
    void create_input_form(QVBoxLayout*& params) const override {
        QLayoutItem *item;
             while ((item = params->takeAt(0))) {
                 delete item->widget();
                 delete item;
             }

        QLabel* text_radius = new QLabel;
        connect(radius_line,  &QLineEdit::textChanged, this, &Circle::read_radius);
        radius_line->setText(QString::number(radius));
        text_radius->setText("Введите радиус");
        params->addWidget(text_radius);
        params->addWidget(radius_line);
        params->addWidget(area_line);
    }

private slots:

    void read_radius(const QString& digit) {
        radius = digit.toInt();
        this->update();
        get_area();

    }

private:
    int radius;
    QLineEdit* radius_line;
};

#endif // CIRCLE_H
