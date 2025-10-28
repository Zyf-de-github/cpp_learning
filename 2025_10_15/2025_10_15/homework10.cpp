#if 0

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <random>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};


class Circle : public Shape {
private:
    double r;
public:
    Circle(double radius) : r(radius) {}
    double area() const override {
        return 3.14 * r * r;
    }
};

class Square : public Shape {
private:
    double a;
public:
    Square(double side) : a(side) {}
    double area() const override {
        return a * a;
    }
};

class Rectangle : public Shape {
private:
    double w, h;
public:
    Rectangle(double width, double height) : w(width), h(height) {}
    double area() const override {
        return w * h;
    }
};

class Trapezoid : public Shape {
private:
    double a, b, h;
public:
    Trapezoid(double top, double bottom, double height)
        : a(top), b(bottom), h(height) {}
    double area() const override {
        return (a + b) * h / 2;
    }
};

class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double x, double y, double z) : a(x), b(y), c(z) {}
    double area() const override {
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

int main() {
    Shape* shapes[5];
    shapes[0] = new Circle(2.3);
    shapes[1] = new Square(2.5);
    shapes[2] = new Rectangle(2.5, 3.6);
    shapes[3] = new Trapezoid(2.7, 3.1, 4.5);
    shapes[4] = new Triangle(3.6, 4.4, 4.5);

    cout << "the area of Circle:" << shapes[0]->area() << endl;
    cout << "the area of Square:" << shapes[1]->area() << endl;
    cout << "the area of Rectangle:" << shapes[2]->area() << endl;
    cout << "the area of Trapezoid:" << shapes[3]->area() << endl;
    cout << "the area of Triangle:" << shapes[4]->area() << endl;
    double total = 0;
    for (int i = 0; i < 5; i++)
    {
        total += shapes[i]->area();
    }
    cout << "the area of Total:" << total << endl;
    return 0;
}


#endif