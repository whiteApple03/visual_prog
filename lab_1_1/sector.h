#ifndef SECTOR_H
#define SECTOR_H
#include <shape.h>
#include <QPainter>
#include <QLineEdit>
#include <QtMath>

class Sector : public Shape
{
    Q_OBJECT
public:
    Sector(int radius = 100, int start_angle = 30*16, int span_angle = 120 * 16) : Shape(), radius(radius), start_angle(start_angle), span_angle(span_angle) {
        formula = new Formulas("S = pi*r^2 * (второй угол - первый угол)/(2*pi)");
        radius_line = new QLineEdit;
        start_angle_line = new QLineEdit;
        span_angle_line = new QLineEdit;
        get_area();

    }

    void paintEvent(QPaintEvent *) override {
        QPainter painter;
        QRectF rectangle(0, 0, radius*2, radius*2);
        painter.begin(this);
        painter.drawPie(rectangle, start_angle, span_angle);
        painter.end();
    }


    virtual void set_default()  override {
        radius = 100;
        start_angle = 30*16;
        span_angle = 120*16;
        radius_line->setText(QString::number(radius));
        start_angle_line->setText(QString::number(start_angle/16));

        span_angle_line->setText(QString::number(span_angle/16));

        get_area();
        this->update();
    }

    void get_area() const override {
         area_line->setText("S = " + QString::number(M_PI * radius*radius * (((span_angle - start_angle)/16 * (M_PI / 180)) / (2 * M_PI))));
    }


    void create_input_form(QVBoxLayout*& params) const override {
        QLayoutItem *item;
             while ((item = params->takeAt(0))) {
                 delete item->widget();
                 delete item;
             }

        QLabel* text_radius = new QLabel;

        connect(radius_line, &QLineEdit::textChanged, this, &Sector::read_radius);
        radius_line->setText(QString::number(radius));
        text_radius->setText("Введите  радиус");

        QLabel* text_start_angle = new QLabel;

        connect(start_angle_line, &QLineEdit::textChanged, this, &Sector::read_start_angle);
        start_angle_line->setText(QString::number(start_angle/16));
        text_start_angle->setText("Введите первый угол");

        QLabel* text_span_angle = new QLabel;

        connect(span_angle_line, &QLineEdit::textChanged, this, &Sector::read_span_angle);
        span_angle_line->setText(QString::number(span_angle / 16));
        text_span_angle->setText("Введите второй угол");
        params->addWidget(text_radius);
        params->addWidget(radius_line);

        params->addWidget(text_start_angle);
        params->addWidget(start_angle_line);

        params->addWidget(text_span_angle);
        params->addWidget(span_angle_line);


        params->addWidget(area_line);


    }
private slots:
    void read_radius(const QString& value) {
        radius = value.toInt();
        get_area();
        this->update();
    }
    void read_span_angle(const QString& value) {
        span_angle = value.toInt() * 16;
        get_area();
        this->update();
    }

    void read_start_angle(const QString& value) {
        start_angle = value.toInt() * 16;
        get_area();
        this->update();
    }



private:
    QLineEdit* span_angle_line;
    QLineEdit* start_angle_line;
    QLineEdit* radius_line;
    int radius;
    int start_angle;
    int span_angle;
};

#endif // SECTOR_H
