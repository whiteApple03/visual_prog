#ifndef TRAPEZOID_H
#define TRAPEZOID_H
#include "shape.h"

#include <QPainter>
#include <QLineEdit>
#include <QtMath>

class Trapezoid : public Shape
{
    Q_OBJECT
public:
    Trapezoid(int height = 50, int sm_base = 100, int lg_base = 150);

   virtual void paintEvent(QPaintEvent *) override;
   virtual void set_default() override;
   virtual void get_area() const override;
   virtual void create_input_form(QVBoxLayout*& params) const override;

private slots:
    void read_height(const QString& value) {
        height = value.toInt();
        get_area();
    }
    void read_large_base(const QString& value) {
        large_base = value.toInt() * 16;
        get_area();
    }

    void read_smaller_base(const QString& value) {
        smaller_base = value.toInt() * 16;
        get_area();
    }


private:

    int a;
    int large_base;
    int smaller_base;
    int height;
    QPointF points[4];
    QLineEdit* height_line;
    QLineEdit* sm_base_line;
    QLineEdit* lg_base_line;

};

#endif // TRAPEZOID_H
