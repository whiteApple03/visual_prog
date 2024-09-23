#include "rectangle.h"

#include "formulas.h"
#include <shape.h>


Rectangle::Rectangle(int width, int height) : Shape(), width(width), height(height) {
    formula = new Formulas("S = a * b");
    width_line = new QLineEdit;
    height_line = new QLineEdit;

    get_area();
}


