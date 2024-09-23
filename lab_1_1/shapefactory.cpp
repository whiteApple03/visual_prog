#include "shapefactory.h"
#include "rectangle.h"
#include "square.h"
#include "circle.h"
#include "triangle.h"
#include "parallelogram.h"
#include "rhomb.h"
#include "sector.h"
#include "trapezoid.h"


Shape* ShapeFactory::create(int index) {
    Shape* returned = nullptr;
    switch (index) {
    case 0:
        returned = new Square();
        break;
    case 1:
        returned = new Rectangle();
        break;
    case 2:
        returned = new Triangle();
        break;
    case 3:
        returned = new Parallelogram();

        break;
    case 4:
        returned = new Rhomb();
        break;
    case 5:
        returned = new Circle();
        break;
    case 6:
        returned = new Trapezoid();
        break;
    case 7:
        returned = new Sector();
        break;
    }
    return returned;
}
