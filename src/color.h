#ifndef COLOR_HPP
#define COLOR_HPP

#include <stdio.h>

class Color {
public:
        double r, g, b;

        Color();
        Color(double r, double g, double b);
        void print();
};

class Canvas {
        int width, height;
        Color* pixels;

        Canvas(int width, int height);
};

Color operator+(const Color& a, const Color& b);
Color operator-(const Color& a, const Color& b);
Color operator*(const Color& a, int n);
Color operator*(int n, const Color& a);
Color operator*(const Color& a, const Color& b);
#endif
