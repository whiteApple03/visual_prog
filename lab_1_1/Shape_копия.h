#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>


#include "Formulas.h"


class Shape : public QWidget {
    Q_OBJECT
public:
    Shape(QWidget* parant) : QWidget{parant} {}
    virtual void paintEvent(QPaintEvent *) {}
    virtual void read_params() const = 0;
    virtual double get_area()  const = 0;
//    ~Shape() {
////        delete formula;
//    }
    Formulas* getFormula() {
        return formula;
    }


protected:
    Formulas* formula;


};

#endif // SHAPE_H
