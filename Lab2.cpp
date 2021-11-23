#include <iostream>

using namespace std;

class Point {

protected:
    int x, y;

public:

    Point() {

        printf("Point()\n");

        x = 0;
        y = 0;
    }

    Point(int x, int y) {

        printf("Point(int x, int y)\n");

        this->x = x;
        this->y = y;
    }

    Point(const Point& p) {

        printf("Point(const Point& p)\n");

        x = p.x;
        y = p.y;
    }

    ~Point() {

        printf("%d, %d\n", x, y);

        printf("~Point()\n");
    }

    void move(int dx, int dy) {

        x = x + dx;
        y = y + dy;
    }

    void reset();
};

class ColoredPoint: public Point {

protected:

    int color;

public:

    ColoredPoint() : Point() {

        printf("ColoredPoint()\n");

        color = 0;
    }

    ColoredPoint(int x, int y, int color) : Point(x, y) {

        printf("ColoredPoint(int x, int y)\n");

        this->color = color;
    }

    ColoredPoint(const ColoredPoint& p) {

        printf("ColoredPoint(const Point& p)\n");

        color = p.color;
        x = p.x;
        y = p.y;
    }

    ~ColoredPoint() {

        printf("%d, %d color = %d\n", x, y, color);

        printf("~ColoredPoint()\n");
    }

    void changeColor(int new_color) {

        color = new_color;
    }
};

void Point::reset() {
    x = 0;
    y = 0;
}

void chapterOne()
{
    // Работа со статическими и динамическими объектами
    // Их создание и уничтожение

    cout << "PART ONE!\n" << endl;

    cout << "Static objects: " << endl;

    {
        Point p;

        Point p2(10, 20);

        Point p3(p2);
    }

    cout << "\nDinamic objects: " << endl;

    Point* p = new Point;

    Point* p2 = new Point(10, 20);

    Point* p3 = new Point(*p2);

    cout << "\nDeleting" << endl;
    delete p;
    delete p2;
    delete p3;
}

void chapterTwo()
{
    // Реализация методов
    // Доступность атрибутов

    cout << "\nPART TWO!\n" << endl;

    Point* p = new Point(1, 2);

    p->reset();
    p->move(10, 10);
    
    cout << "\nDeleting" << endl;
    delete p;
}

void chapterThree()
{
    // Наследование

    cout << "\nPART THREE!\n" << endl;

    ColoredPoint* p = new ColoredPoint(1, 2, 42);

    cout << "\nDeleting" << endl;
    delete p;
}

void chapterFour()
{
    // Помещение объектов в переменные
    // различных типов

    cout << "\nPART FOUR!" << endl;

    // Помещение объекта потомка
    // в переменную-указатель на базовый класс:
    // Point* p = new ColoredPoint(1, 2, 42);

    // Невозможно. Нельзя поместить
    // объект базового класса в переменную- 
    // указатель на потомка.
    // ColoredPoint* p = new Point(1, 2, 42);

    // Невозможно. Та же ситуация.
    // Point* p2 = new Point(1, 2);
    // ColoredPoint* p3 = p2;

    cout << "\nPoint* p1 = new ColoredPoint(1, 2, 42)" << endl;
    Point* p1 = new ColoredPoint(1, 2, 42);

    cout << "\nColoredPoint* p2 = new ColoredPoint(1, 2, 42)" << endl;
    ColoredPoint* p2 = new ColoredPoint(1, 2, 42);

    // Если поместить объект в переменную-указатель
    // на базовый класс, то будут доступны только
    // методы базового класса.
    // Если же в переменную-указатель на
    // класс потомка, то будут доступны методы
    // и базового класса, и класса потомка.

    cout << "\nDeleting" << endl;

    delete p1;
    delete p2;
}

int main()
{
    chapterOne();

    chapterTwo();

    chapterThree();

    chapterFour();

    return 0;
}

