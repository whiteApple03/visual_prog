#ifndef RHOMB_H
#define RHOMB_H
#include <shape.h>

#include <QPainter>
#include <QLineEdit>
#include <QPointF>

class Rhomb : public Shape
{
    Q_OBJECT
public:
    Rhomb(int diagonal1 = 50, int diagonal2 = 100) : Shape(), d1(diagonal1), d2(diagonal2) {
        formula = new Formulas("S = 0.5 * d1 * d2");
        d2_line = new QLineEdit;

        d1_line = new QLineEdit;

        get_area();

    }

    void paintEvent(QPaintEvent *) override {
        QPainter painter;
        painter.begin(this);
        convert_to_coord();
        painter.drawPolygon(points, 4);
        painter.end();
    }

    virtual void set_default()  override {
        d1 = 50;
        d2 = 100;
        d1_line->setText(QString::number(d1));
        d2_line->setText(QString::number(d2));

        convert_to_coord();
        get_area();
        this->update();
    }

    void get_area() const override {
         area_line->setText("S = " + QString::number(0.5*d1*d2));
    }


    void create_input_form(QVBoxLayout*& params) const override {
        QLayoutItem *item;
             while ((item = params->takeAt(0))) {
                 delete item->widget();
                 delete item;
             }

        QLabel* text_d1 = new QLabel;
        connect(d1_line, &QLineEdit::textChanged, this, &Rhomb::read_d1);
        d1_line->setText(QString::number(d1));
        text_d1->setText("Введите первую диагональ");
        d1_line->setText(QString::number(d1));

        QLabel* text_d2 = new QLabel;
        connect(d2_line, &QLineEdit::textChanged, this, &Rhomb::read_d2);
        d2_line->setText(QString::number(d2));

        text_d2->setText("Введите вторую диагональ");
        params->addWidget(text_d1);
        params->addWidget(d1_line);
        params->addWidget(text_d2);

        params->addWidget(d2_line);
        params->addWidget(area_line);

    }
private slots:
    void read_d1(const QString& digit) {
        d1 = digit.toInt();
        get_area();
        convert_to_coord();
        this->update();
    }
    void read_d2(const QString& digit) {
        d2 = digit.toInt();
        get_area();
        convert_to_coord();
        this->update();
    }

private:

    void convert_to_coord() {
        points[0] = QPointF(0, d1/2);
        points[1] = QPointF(d2/2, 0);
        points[2] = QPointF(d2, d1/2);
        points[3] = QPointF(d2/2, d1);
    }

    int d1;
    int d2;
    QPointF points[4];
    QLineEdit* d1_line;
    QLineEdit* d2_line;
};

#endif // RHOMB_H
