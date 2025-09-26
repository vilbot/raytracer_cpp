#include "color.h"

Color::Color() {
        r = 0;
        g = 0;
        b = 0;
}

Color::Color(double r, double g, double b) {
        this->r = r;
        this->g = g;
        this->b = b;
}

void Color::print() {
        printf("r = %f\ng = %f\nb = %f\n", r, g, b);
}

Canvas::Canvas(int width, int height) {
        this->width = width;
        this->height = height;
        pixels = new Color[width * height];
}

void Canvas::write_pixel(int x, int y, Color color) {
        this->pixels[y * this->width + x] = color;   
}

Color Canvas::pixel_at(int x, int y) {
        return this->pixels[y * this->width + x];   
}

Color pixel_at(Canvas* c, int x, int y) {
        return c->pixels[y * c->width + x];   
}

double r_at(Canvas* c, int x, int y) {
        return pixel_at(c, x, y).r;
}

double g_at(Canvas* c, int x, int y) {
        return pixel_at(c, x, y).g;
}

double b_at(Canvas* c, int x, int y) {
        return pixel_at(c, x, y).b;
}

char* canvas_to_ppm(Canvas* c) {
        int header_size = 50;
        int pixel_data_size = 12 * c->width * c->height;
        int total_size = header_size + pixel_data_size + 1e6;
        char* ppm = new char[total_size];
        int new_size = sprintf(ppm,"P3\n%d %d\n255\n", c->width, c->height); 

        for(int y = 0; y < c->height; y++) {
                int col_len = 0;
                for(int x = 0; x < c->width; x++) {
                        char pixel_str[20];
                        int pixel_len = sprintf(pixel_str, "%d %d %d ", d_to_int(r_at(c, x, y)), d_to_int(g_at(c, x, y)), d_to_int(b_at(c, x, y)));

                        if (col_len + pixel_len > 70) {
                                new_size += sprintf(ppm + new_size, "\n"); 
                                col_len = 0;
                        }
                        new_size += sprintf(ppm + new_size, "%s", pixel_str);
                        col_len += pixel_len;
                        if (new_size >= total_size - 100) {  // Leave some safety margin
                                fprintf(stderr, "APPROACHING BUFFER LIMIT at y=%d, x=%d, new_size=%d\n", y, x, new_size);
                        }
                }
                new_size += sprintf(ppm + new_size, "\n"); 
        }
        ppm[new_size] = '\0';  // Ensure null termination
        return ppm;
}

int d_to_int(double a) {
        if (a > 1.0) a = 1.0;
        if (a < 0.0) a = 0.0;
        return (int)255 * a;
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

Color operator*(const Color& a, const Color& b) {
        return {a.r * b.r, a.g * b.g, a.b * b.b};
}
