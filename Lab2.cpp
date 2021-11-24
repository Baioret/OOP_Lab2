#include <iostream>

using namespace std;

class Point {

protected:

    int x, y;

public:

    Point() { // Конструктор по умолчанию

        printf("Point()\n");

        x = 0;
        y = 0;
    }

    Point(int x, int y) { // Конструктор с парам.

        printf("Point(int x, int y)\n");

        this->x = x;
        this->y = y;
    }

    Point(const Point& p) { // Конструктор копир-я

        printf("Point(const Point& p)\n");

        x = p.x;
        y = p.y;
    }

    ~Point() { // Деструктор

        printf("%d, %d\n", x, y);

        printf("~Point()\n");
    }

    void move(int dx, int dy) {

        x = x + dx;
        y = y + dy;
    }

    virtual void reset();
};

void Point::reset() { // Реализация после определения
    x = 0;
    y = 0;
}

class ColoredPoint: public Point {

protected:

    int color;

public:

    ColoredPoint() : Point() {

        printf("ColoredPoint()\n");

        color = 0;
    }

    ColoredPoint(int x, int y, int color) : Point(x, y) {

        printf("ColoredPoint(int x, int y, int color)\n");

        this->color = color;
    }

    ColoredPoint(const ColoredPoint& p) : Point(p) {

        printf("ColoredPoint(const ColoredPoint& p)\n");

        color = p.color;
    }

    ~ColoredPoint() {

        printf("%d, %d color = %d\n", x, y, color);

        printf("~ColoredPoint()\n");
    }

    void changeColor(int new_color) {

        color = new_color;
    }

    void reset() {
        color = 0;
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

    Section(const Section& s) { // Глубокое копирование

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

//____________________________

class Point3D {

private:

    void movePoint3DPrivate(int dx, int dy, int dz)
    {
        x = x + dx;
        y = y + dy;
        z = z + dz;
    }

    /*virtual void reset()
    {
        x = 0;
        y = 0;
        z = 0;
    }*/

protected:

    int x, y, z;

    /*virtual void reset()
    {
        x = 0;
        y = 0;
        z = 0;
    }*/

    void foo()
    {
        cout << "\n!Protected! method foo\n";
    }

public:

    void movePoint3D(int dx, int dy, int dz)
    {
        movePoint3DPrivate(dx, dy, dz); // Использовать private методы
                                        // можно только внутри класса
    }

    Point3D()
    {
        printf("Point3D()\n");

        x = 0;
        y = 0;
        z = 0;
    }

    Point3D(int x, int y, int z) {

        printf("Point3D(int x, int y, int z)\n");

        this->x = x;
        this->y = y;
        this->z = z;
    }

    Point3D(const Point3D& p) {

        printf("Point3D(const Point3D& p)\n");

        x = p.x;
        y = p.y;
        z = p.z;
    }

    ~Point3D() {

        printf("%d, %d, %d\n", x, y, z);

        printf("~Point3D()\n");
    }

    virtual void reset()
    {
        cout << "\nreset (Point3D)\n";

        x = 0;
        y = 0;
        z = 0;
    }
};

class ColoredPoint3D : public Point3D {

protected:

    int color;

public:

    ColoredPoint3D() : Point3D()
    {
        printf("ColoredPoint3D()\n");

        color = 0;
    }

    ColoredPoint3D(int x, int y, int z, int color) : Point3D(x, y, z) {

        printf("ColoredPoint3D(int x, int y, int z, int color)\n");

        this->color = color;
    }

    ColoredPoint3D(const ColoredPoint3D& p) : Point3D(p){

        printf("ColoredPoint3D(const ColoredPoint3D& p)\n");

        color = p.color;
    }

    ~ColoredPoint3D() {

        printf("%d, %d, %d, color = %d\n", x, y, z, color);

        printf("~ColoredPoint3D()\n");
    }

    void reset() // Перекрытие метода reset
    {
        cout << "\nreset (ColoredPoint)\n";

        x = 0;
        y = 0;
        z = 0;
        color = 0;
    }

    void foo2()
    {
        cout << "\nfoo2";
        foo(); // protected метод можно использовать только внутри потомка
    }
};

//class A {
//
//public:
//    void foo3() {
//        foo(); // потому что это не потомок Point3D
//    }
//
//};

//____________________________

class Base {

public:

    Base() {
        cout << "Base constructor\n";
    }

    ~Base() {
        cout << "Base destructor\n";
    }

};

class Descendant1 : public Base {

public:

    Descendant1() {
        cout << "Descendant1 constructor\n";
    }

    ~Descendant1() {
        cout << "Descendant1 destructor\n";
    }

};

class Descendant2 : public Base {

};

void partSix()
{

    cout << "\nPART SIX!\n" << endl;

    Point3D* p1 = new ColoredPoint3D();

    cout << "\n";

    ColoredPoint3D* p2 = new ColoredPoint3D(1, 2, 3, 4);

    cout << "\n";

    ColoredPoint3D* p3 = new ColoredPoint3D(*p2);

    p1->movePoint3D(1, 2, 3);
    p1->reset();

    p2->movePoint3D(1, 2, 3);
    p2->reset();

    cout << "\nDeleting\n\n";

    delete p1;

    cout << "\n";

    delete p2;

    cout << "\n";

    delete p3;
}

void partSeven()
{
    cout << "\nPART SEVEN!\n" << endl;

    Base* a1 = new Base;

    cout << endl;

    Base* b1 = new Descendant1;

    cout << endl;

    Descendant1* c1 = new Descendant1;

    cout << endl << endl;

    Base* a2 = new Base;

    cout << endl;

    Base* b2 = new Descendant2;

    cout << endl;

    Descendant2* c2 = new Descendant2;

    cout << "\nDeleting\n\n";

    delete a1;
    cout << endl;
    delete b1;
    cout << endl;
    delete c1;

    cout << endl << endl;

    delete a2;
    cout << endl;
    delete b2;
    cout << endl;
    delete c2;
}

int main()
{
    partOne();

    partTwo();

    partThree();

    partFour();

    partFive();

    partSix();

    partSeven();

    return 0;
}