#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include <shape.h>

#include <QPainter>
#include <QtMath>
#include <QLineEdit>
#include <QDebug>

class Parallelogram : public Shape
{
    Q_OBJECT
public:
    Parallelogram(int angle = 45, int h = 50, int a = 100) : Shape(), angle(angle), base_length(a), height(h) {
        formula = new Formulas("S = h*a");
        angle_line = new QLineEdit;
        base_line = new QLineEdit;
        height_line = new QLineEdit;

        convert_to_coord();
        get_area();

    }

    void paintEvent(QPaintEvent *) override {
        QPainter painter;
        painter.begin(this);
        painter.drawPolygon(points, 4);
        painter.end();
    }

    virtual void set_default()  override {
        angle = 45;
        height = 50;
        base_length = 100;
        angle_line->setText(QString::number(angle));
        height_line->setText(QString::number(height));

        base_line->setText(QString::number(base_length));

        convert_to_coord();
        get_area();
        this->update();
    }

    void get_area() const override {
         area_line->setText("S = " + QString::number(height*base_length));
    }


    void create_input_form(QVBoxLayout*& params) const override {
        QLayoutItem *item;
             while ((item = params->takeAt(0))) {
                 delete item->widget();
                 delete item;
             }

        QLabel* text_height = new QLabel;
        text_height->setText("Введите высоту");
        height_line->setText(QString::number(height));
        connect(height_line, &QLineEdit::textChanged, this, &Parallelogram::read_height);

        QLabel* text_base = new QLabel;
        text_base->setText("Введите длину основания");
        base_line->setText(QString::number(base_length));
        connect(base_line, &QLineEdit::textChanged, this, &Parallelogram::read_base_lenght);

        QLabel* text_angle = new QLabel;
        text_angle->setText("Введите угол между сторонами 0 < angle < 180");
        angle_line->setText(QString::number(angle));
        connect(angle_line, &QLineEdit::textChanged, this, &Parallelogram::read_angle);

        params->addWidget(text_height);
        params->addWidget(height_line);

        params->addWidget(text_base);
        params->addWidget(base_line);

        params->addWidget(text_angle);
        params->addWidget(angle_line);
        params->addWidget(area_line);

    }
private slots:
    void read_base_lenght(const QString& value) {
        base_length = value.toInt();
        convert_to_coord();
        get_area();

        this->update();

    }
    void read_angle(const QString& value) {
        angle = value.toInt();
        convert_to_coord();
        get_area();

        this->update();

    }
    void read_height(const QString& value) {
        height = value.toInt();
        convert_to_coord();
        get_area();
        this->update();
    }

private:

    void convert_to_coord();
    QLineEdit* height_line;
    QLineEdit* base_line;
    QLineEdit* angle_line;

    int angle;
    int base_length;
    int height;
    QPointF points[5];
};

#endif // PARALLELOGRAM_H
