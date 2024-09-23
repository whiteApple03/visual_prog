#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <shape.h>

#include <QPainter>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QAction>
#include <QString>
#include <QWidget>
#include <QtMath>


class InputPoint : public QGroupBox
{
    Q_OBJECT
public:
   explicit InputPoint(int index, QPointF point) : index(index) {
        QHBoxLayout* container_x = new QHBoxLayout;
        QHBoxLayout* container_y = new QHBoxLayout;
        main_container = new QVBoxLayout;
        text_x = new QLabel;
        text_y = new QLabel;
        coord_x = new QLineEdit;
        coord_y = new QLineEdit;

        text_x->setText("Введите координату x");
        text_y->setText("Введите координату y");

        coord_x->setText(QString::number(point.x()));
        coord_y->setText(QString::number(point.y()));

        container_x->addWidget(text_x);
        container_x->addWidget(coord_x);
        container_y->addWidget(text_y);
        container_y->addWidget(coord_y);
        main_container->addLayout(container_x);
        main_container->addLayout(container_y);
        this->setTitle("Введити точку " + QString::number(index));
        this->setLayout(main_container);

    }

    QLineEdit* coord_x;
    QLineEdit* coord_y;
private:
    QLabel * text_x;
    QLabel * text_y;


    QVBoxLayout* main_container;
    int index;

};

class Triangle : public Shape
{
    Q_OBJECT

public:
    Triangle() : Shape() {
        formula = new Formulas("S = 0.5 * |x1(y2-y3) + x2(y3 - y1) + x3(y1 - y2)|");
        first_point = new InputPoint(0, points[0]);
        second_point = new InputPoint(1, points[1]);
        third_point = new InputPoint(2, points[2]);
        set_default();
        get_area();
    }

    void paintEvent(QPaintEvent *) override {
        QPainter painter;
        painter.begin(this);
        painter.drawPolygon(points, 3);
        painter.end();

    }

    virtual void set_default() override {
        points[0].setX(0);
        points[0].setY(0);

        first_point->coord_x->setText(QString::number(0));
        first_point->coord_y->setText(QString::number(0));

        points[1].setX(50);
        points[1].setY(0);
        second_point->coord_x->setText(QString::number(50));
        second_point->coord_y->setText(QString::number(0));

        points[2].setX(50);
        points[2].setY(100);
        third_point->coord_x->setText(QString::number(50));
        third_point->coord_y->setText(QString::number(100));


        get_area();
        this->update();
    }

    void get_area() const override {
        double area = 0.5* abs(points[0].x()*(points[1].y() - points[2].y()) + points[1].x() * (points[2].y()-points[0].y()) + points[2].x()*(points[0].y()-points[1].y()));
        area_line->setText("S = " + QString::number(area));
    }
    void create_input_form(QVBoxLayout*& params) const override {
        QLayoutItem *item;
             while ((item = params->takeAt(0))) {
                 delete item->widget();
                 delete item;
             }



        connect(first_point->coord_x, &QLineEdit::textChanged, this, &Triangle::get_point_x_f);
        connect(first_point->coord_y, &QLineEdit::textChanged, this, &Triangle::get_point_y_f);

        connect(second_point->coord_x, &QLineEdit::textChanged, this, &Triangle::get_point_x_s);
        connect(second_point->coord_y, &QLineEdit::textChanged, this, &Triangle::get_point_y_s);

        connect(third_point->coord_x, &QLineEdit::textChanged, this, &Triangle::get_point_x_t);
        connect(third_point->coord_y, &QLineEdit::textChanged, this, &Triangle::get_point_y_t);


        params->addWidget(first_point);
        params->addWidget(second_point);
        params->addWidget(third_point);

        params->addWidget(area_line);
    }

private slots:
    void get_point_x_f(const QString& coord) {
        points[0].setX(coord.toInt());
        get_area();
        this->update();

    }
    void get_point_y_f(const QString& coord) {
        points[0].setY(coord.toInt());
        get_area();
        this->update();

    }
    void get_point_x_s(const QString& coord) {
        points[1].setX(coord.toInt());
        get_area();
        this->update();

    }
    void get_point_y_s(const QString& coord) {
        points[1].setY(coord.toInt());
        get_area();
        this->update();


    }
    void get_point_x_t(const QString& coord) {
        points[2].setX(coord.toInt());
        get_area();
        this->update();


    }
    void get_point_y_t(const QString& coord) {
        points[2].setY(coord.toInt());
        get_area();
        this->update();

    }



private:
    QPointF points[3];
    InputPoint* first_point;
    InputPoint* second_point;
    InputPoint* third_point;

};



#endif // TRIANGLE_H
