#ifndef COLOR_HPP
#define COLOR_HPP

#include <stdio.h>

class Color {
public:
        double r, g, b;

        Color(double r, double g, double b);
        void print();
};

Color operator+(const Color& a, const Color& b);
Color operator-(const Color& a, const Color& b);
Color operator*(const Color& a, int n);
Color operator*(int n, const Color& a);
#endif
