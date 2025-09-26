#include "color.h"
#include "includes.h" 

typedef struct {
        Point position;
        Vector velocity;
} Proj;

typedef struct {        
        Vector gravity;
        Vector wind;
} Env;

Proj tick(Env env, Proj proj) {
        Point position = proj.position + proj.velocity;
        Vector velocity = proj.velocity + env.gravity + env.wind;
        return {position, velocity};
}

void putting_it_together_ch1() {
        Proj p = {Point(0, 1, 0), Vector(1, 1, 0).normalize()};
        Env e = {Vector(0, -0.1, 0), Vector(-0.01, 0, 0)};

        while(p.position.y >= 0) {
                p.position.print();
                p = tick(e, p);
        }
}

void putting_it_together_ch2() {
        Canvas c = Canvas(900, 550);
        Color c1 = Color(0.0, 0, 0);
        Color c2 = Color(1.0, 0.0, 0.0);

        Proj p = {Point(0, 1, 0), Vector(1, 1.8, 0).normalize() * 11.25};
        Env e = {Vector(0, -0.1, 0), Vector(-0.01, 0, 0)};

        while(p.position.y >= 0) {
                p = tick(e, p);
                c.write_pixel(p.position.x, p.position.y, c2);
        }

        char* ppm = canvas_to_ppm(&c);

        printf("%s\n", ppm);
}

int main() {
        double matrix[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ,11, 12, 13, 14, 15, 16};
        Matrix m = Matrix(4, 4, matrix);
        m.print();
}
