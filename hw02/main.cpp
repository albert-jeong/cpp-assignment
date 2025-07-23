#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"

using namespace std;

int main() {
    Shape* pStart = nullptr;
    Shape* pLast = nullptr;

    for (int i = 0; i < 4; i++) {
        int choice;
        do {
            cout << "1. Line 2. Circle 3. Rect >> ";
            cin >> choice;
        } while (choice < 1 || choice > 3);

        Shape* newShape = nullptr;
        switch (choice) {
        case 1: { // �� ��ü ����
            int length;
            do {
                cout << "length: ";
                cin >> length;
            } while (length <= 0);
            newShape = new Line(length);
            break;
        }
        case 2: { // �� ��ü ����
            int radius;
            do {
                cout << "radius: ";
                cin >> radius;
            } while (radius <= 0);
            newShape = new Circle(radius);
            break;
        }
        case 3: { // �簢�� ��ü ����
            int width, height;
            do {
                cout << "width: ";
                cin >> width;
            } while (width <= 0);
            do {
                cout << "height: ";
                cin >> height;
            } while (height <= 0);
            newShape = new Rect(width, height);
            break;
        }
        }

        if (!pStart) {
            pStart = pLast = newShape;
        }
        else {
            pLast = pLast->add(newShape);
        }
    }

    // ���� ����� ��� ������ ȭ�鿡 �׸���.
    Shape* p = pStart;
    while (p != nullptr) {
        p->paint();
        p = p->getNext();
    }

    // ���� ����� ��� ������ �����Ѵ�.
    p = pStart;
    while (p != nullptr) {
        Shape* q = p->getNext();
        delete p;
        p = q;
    }

    return 0;
}
