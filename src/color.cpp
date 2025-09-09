#include "color.hpp"

Color::Color(double r, double g, double b) {
        this->r = r;
        this->g = g;
        this->b = b;
}

void Color::print() {
        printf("r = %f\ng = %f\nb = %f\n", r, g, b);
}

Color operator+(const Color& a, const Color& b) {
        return {a.r + b.r, a.g + b.g, a.b + b.b};
}

Color operator-(const Color& a, const Color& b) {
        return {a.r - b.r, a.g - b.g, a.b - b.b};
}

Color operator*(const Color& a, int n) {
        return {a.r * n, a.g * n, a.b * n};
}

Color operator*(int n, const Color& a) {
        return {a.r * n, a.g * n, a.b * n};
}
