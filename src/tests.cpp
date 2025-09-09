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

int main() {
        Proj p = {Point(0, 1, 0), Vector(1, 1, 0).normalize()};
        Env e = {Vector(0, -0.1, 0), Vector(-0.01, 0, 0)};

        while(p.position.y >= 0) {
                p.position.print();
                p = tick(e, p);
        }
}
