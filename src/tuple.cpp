#include "tuple.hpp"

Tuple::Tuple(double x, double y, double z, double w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
}

void Tuple::print() {
        printf("tuple(%8.5f, %8.5f, %8.5f, %8.5f)\n", x, y, z, w);
}

Point::Point(double x, double y, double z) : Tuple(x, y, z, 1) {}

Vector::Vector(double x, double y, double z) : Tuple(x, y, z, 0) {}

double Vector::magnitude() {
        return std::sqrt(std::pow(x, 2) + 
                         std::pow(y, 2) +
                         std::pow(z, 2));
}

Vector Vector::normalize() {
        return Vector(x / magnitude(), 
                      y / magnitude(),
                      z / magnitude());
}

double Vector::dot(Vector v) {
        return x * v.x + y * v.y + z * v.z;
}

double dot(const Vector& a, const Vector& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;   
}

Vector cross(const Vector& a, const Vector& b) {
        return Vector(a.y * b.z - a.z * b.y,
                      a.z * b.x - a.x * b.z,
                      a.x * b.y - a.y * b.x);
}

bool is_equal(const double a, const double b) {
        return std::fabs(a - b) < EPSILON;
}

bool operator==(const Tuple& a, const Tuple& b) {
        return
        is_equal(a.x, b.x) &&
        is_equal(a.y, b.y) &&
        is_equal(a.z, b.z) &&
        is_equal(a.w, b.w);
}

bool operator==(const Point& a, const Point& b) {
        return 
        is_equal(a.x, b.x) &&
        is_equal(a.y, b.y) &&
        is_equal(a.z, b.z) &&
        is_equal(a.w, b.w);
}

bool operator==(const Vector& a, const Vector& b) {
        return
        is_equal(a.x, b.x) &&
        is_equal(a.y, b.y) &&
        is_equal(a.z, b.z) &&
        is_equal(a.w, b.w);
}

bool operator!=(const Tuple& a, const Tuple& b) {
        return 
        !(is_equal(a.x, b.x) &&
        is_equal(a.y, b.y) &&
        is_equal(a.z, b.z) &&
        is_equal(a.w, b.w));
}

bool operator!=(const Point& a, const Point& b) {
        return 
        !(is_equal(a.x, b.x) &&
        is_equal(a.y, b.y) &&
        is_equal(a.z, b.z) &&
        is_equal(a.w, b.w));
}

bool operator!=(const Vector& a, const Vector& b) {
        return 
        !(is_equal(a.x, b.x) &&
        is_equal(a.y, b.y) &&
        is_equal(a.z, b.z) &&
        is_equal(a.w, b.w));
}

Tuple operator+(const Tuple& a, const Tuple& b) {
        return Tuple(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

Vector operator+(const Vector& a, const Vector& b) {
        return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Point operator+(const Vector& a, const Point& b) {
        return Point(a.x + b.x, a.y + b.y, a.z + b.z);
}

Point operator+(const Point& a, const Vector& b) {
        return Point(a.x + b.x, a.y + b.y, a.z + b.z);
}

Tuple operator-(const Tuple& a, const Tuple& b) {
        return Tuple(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

Vector operator-(const Vector& a, const Vector& b) {
        return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Point operator-(const Point& a, const Vector& b) {
        return Point(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector operator-(const Point& a, const Point& b) {
        return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Tuple operator-(const Tuple& a) {
        return Tuple(-a.x, -a.y, -a.z, -a.w);
}

Point operator-(const Point& a) {
        return Point(-a.x, -a.y, -a.z);
}

Vector operator-(const Vector& a) {
        return Vector(-a.x, -a.y, -a.z);
}

Tuple operator*(const Tuple& a, const double& b) {
        return Tuple(a.x * b, a.y * b, a.z * b, a.w * b);
}

Tuple operator*(const double& b, const Tuple& a) {
        return Tuple(a.x * b, a.y * b, a.z * b, a.w * b);
}

Tuple operator/(const Tuple& a, const double& b) {
        return Tuple(a.x / b, a.y / b, a.z / b, a.w / b);
}
