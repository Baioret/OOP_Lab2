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

        printf("ColoredPoint(const ColoredPoint& p)\n");

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

class Section {

protected:
    Point* p1;
    Point* p2;

public:

    Section() {

        printf("Section()\n");

        p1 = new Point;
        p2 = new Point;
    }

    Section(int x1, int y1, int x2, int y2) {

        printf("Section(int x1, int y1, int x2, int y2)\n");

        p1 = new Point(x1, y1);
        p2 = new Point(x2, y2);
    }

    Section(const Section& s) {

        printf("Section(const Section& s)\n");

        p1 = new Point(*s.p1); // p1 - указатель на
        p2 = new Point(*s.p2); // Point - разименовываем
    }

    ~Section() {

        //printf("%d, %d\n", x, y);

        delete p1;
        delete p2;

        printf("~Section()\n");
    }
};

void Point::reset() {
    x = 0;
    y = 0;
}

void partOne()
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

void partTwo()
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

void partThree()
{
    // Наследование

    cout << "\nPART THREE!\n" << endl;

    ColoredPoint* p = new ColoredPoint(1, 2, 42);

    cout << "\nDeleting" << endl;
    delete p;
}

void partFour()
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

void partFive()
{
    cout << "\nPART FIVE!\n" << endl;


    // Вариант копирования #1 (поверхностное коп.)
    // p1 = s.p1;
    // p2 = s.p2;

    // В таком случае при удалении второго объекта
    // возникает ошибка!

    // Вместо этого мы используем 
    // конструктор копирования
    // (глубокое копирование)


     Section* s1 = new Section;
     Section* s2 = new Section(1, 2, 3, 4);
     Section* s3 = new Section(*s2);


     cout << "\nDeleting" << endl;

     delete s1;
     delete s2;
     delete s3;
}

int main()
{
    partOne();

    partTwo();

    partThree();

    partFour();

    partFive();

    return 0;
}

