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

int main() {
        Color c1 = Color(1, 0.2, 0.4);
        Color c2 = Color(0.9, 1, 0.1);
        (c1 * c2).print();
}
