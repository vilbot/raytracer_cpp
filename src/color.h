#ifndef COLOR_H
#define COLOR_H

#include <stdio.h>

class Color {
public:
        double r, g, b;

        Color();
        Color(double r, double g, double b);
        void print();
};

class Canvas {
public:
        int width, height;
        Color* pixels;

        Canvas(int width, int height);

        void write_pixel(int x, int y, Color rgb);
        Color pixel_at(int x, int y);
};

Color pixel_at(Canvas* c, int x, int y);
char* canvas_to_ppm(Canvas* c);
int d_to_int(double a);

Color operator+(const Color& a, const Color& b);
Color operator-(const Color& a, const Color& b);
Color operator*(const Color& a, int n);
Color operator*(int n, const Color& a);
Color operator*(const Color& a, const Color& b);
#endif
