#include "color.hpp"

Color::Color(double r, double g, double b) {
        this->r = r;
        this->g = g;
        this->b = b;
}

void Color::print() {
        printf("r = %f\ng = %f\nb = %f\n", r, g, b);
}
