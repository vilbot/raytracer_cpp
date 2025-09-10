#ifndef TUPLE_HPP
#define TUPLE_HPP

#include <iostream>
#include <stdio.h>
#include <cmath>

#define EPSILON 0.00001

class Tuple {
public:
        double x, y, z, w;

        Tuple(double x, double y, double z, double w);
        void print();
};

class Point : public Tuple {
public:
        Point(double x, double y, double z);
};

class Vector : public Tuple {
public:
        Vector(double x, double y, double z);

        double magnitude();
        Vector normalize();
        double dot(Vector v);
};

double dot(const Vector& a, const Vector& b);
Vector cross(const Vector& a, const Vector& b);

bool is_equal(const double a, const double b);
bool operator==(const Point& a, const Point& b);
bool operator==(const Vector& a, const Vector& b);
bool operator==(const Tuple& a, const Tuple& b);
bool operator!=(const Tuple& a, const Tuple& b);
bool operator!=(const Point& a, const Point& b);
bool operator!=(const Vector& a, const Vector& b);
Tuple operator+(const Tuple& a, const Tuple& b);
Vector operator+(const Vector& a, const Vector& b);
Point operator+(const Vector& a, const Point& b);
Point operator+(const Point& a, const Vector& b);
Tuple operator-(const Tuple& a, const Tuple& b);
Vector operator-(const Vector& a, const Vector& b);
Point operator-(const Point& a, const Vector& b);
Vector operator-(const Point& a, const Point& b);
Tuple operator-(const Tuple& a);
Point operator-(const Point& a);
Vector operator-(const Vector& a);
Tuple operator*(const Tuple& a, const double& b);
Tuple operator*(const double& b, const Tuple& a);
Tuple operator/(const Tuple& a, const double& b);

#endif
