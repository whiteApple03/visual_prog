#include "parallelogram.h"


void Parallelogram::convert_to_coord() {
    double offset = 0;
    offset = (1/qTan(angle * M_PI / 180) * height);

    if (angle <= 90) {
        points[0] = QPointF(offset, 0);
        points[1] = QPointF(offset+base_length, 0);
        points[2] = QPointF(base_length, height);
        points[3] = QPointF(0, height);
    } else if (angle < 180) {
        offset = -offset;
        points[0] = QPointF(0, 0);
        points[1] = QPointF(base_length, 0);
        points[2] = QPointF(offset+base_length, height);
        points[3] = QPointF(offset, height);
    }
}
