#ifndef FORMULAS_H
#define FORMULAS_H

#include <QLabel>
#include <QString>

class Formulas : public QLabel
{
Q_OBJECT
public:
    Formulas(QString formula) : formula{formula} {
        this->setText(formula);
    }

private:

    QString formula;

};

#endif // FORMULAS_H
