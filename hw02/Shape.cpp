#include <iostream>
#include "Shape.h"
using namespace std;

void Shape::paint() {
    draw();
}

void Shape::draw() {
    cout << "--Shape--";
}

Shape* Shape::add(Shape* p) {
    next = p;
    return p;
}