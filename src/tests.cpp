#include "includes.hpp" 

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

int main() {
        Color c1 = Color(0.9, 0.6, 0.75);
        Color c2 = Color(0.7, 0.1, 0.25);
        Color c3 = c1 - c2;
        // c3.print();

        Color c4 = Color(0.2, 0.3, 0.4);
        (2 * c4).print();
}
