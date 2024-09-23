#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QTextBrowser>

#include "formulas.h"


class Shape : public QWidget {
    Q_OBJECT
public:
    Shape() {
        input_form = new QVBoxLayout;
        area_line = new QLabel;

    }
    virtual void paintEvent(QPaintEvent *) {}
    virtual void set_default() {}
    virtual void get_area()  const = 0;
    virtual void create_input_form(QVBoxLayout*&) const = 0;
    ~Shape() {
        delete formula;
        input_form->deleteLater();
    }
    Formulas* getFormula() {
        return formula;
    }


protected:
    QVBoxLayout* input_form;
    QLabel* area_line;
    Formulas* formula;


};

#endif // SHAPE_H
