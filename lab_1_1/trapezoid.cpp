#include <trapezoid.h>
#include <QLineEdit>

void Trapezoid::get_area() const {
      area_line->setText("S = " + QString::number((smaller_base+large_base)/2*height));
 }


Trapezoid::Trapezoid(int height, int sm_base, int lg_base) : Shape(), large_base(lg_base), smaller_base(sm_base), height(height) {
    formula = new Formulas("S = ((a+b)/2) * h");
    height_line = new QLineEdit;
    lg_base_line = new QLineEdit;
    sm_base_line = new QLineEdit;
    set_default();
    get_area();

}

void Trapezoid::paintEvent(QPaintEvent *) {
        QPainter painter;
        painter.begin(this);
        painter.drawPolygon(points, 4);
        painter.end();
    }

void Trapezoid::create_input_form(QVBoxLayout*& params) const {
        QLayoutItem *item;
             while ((item = params->takeAt(0))) {
                 delete item->widget();
                 delete item;
             }

        QLabel* text_height = new QLabel;
        height_line->setText(QString::number(height));
        text_height->setText("Введите высоту");
        connect(height_line, &QLineEdit::textChanged, this, &Trapezoid::read_height);

        QLabel* text_sm_base = new QLabel;
        sm_base_line->setText(QString::number(smaller_base));
        text_sm_base->setText("Введите меньшее основание");
        connect(sm_base_line, &QLineEdit::textChanged, this, &Trapezoid::read_smaller_base);

        QLabel* text_lg_base = new QLabel;
        lg_base_line->setText(QString::number(large_base));
        text_lg_base->setText("Введите большее основание");
        connect(lg_base_line, &QLineEdit::textChanged, this, &Trapezoid::read_large_base);


        params->addWidget(text_height);
        params->addWidget(height_line);

        params->addWidget(text_sm_base);
        params->addWidget(sm_base_line);

        params->addWidget(text_lg_base);
        params->addWidget(lg_base_line);

        params->addWidget(area_line);
    }

void Trapezoid::set_default() {
    points[0] = QPointF(50, 0);
    points[1] = QPointF(100, 0);
    points[2] = QPointF(150, 50);
    points[3] = QPointF(0, 50);
    height = 50;
    smaller_base = 100;
    large_base = 150;
    height_line->setText(QString::number(height));
    sm_base_line->setText(QString::number(smaller_base));

    lg_base_line->setText(QString::number(large_base));

    get_area();
}
