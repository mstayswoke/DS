//#include <iostream>
//using namespace std;
//
//class Shape {
//public:
//    virtual float area() = 0;
//};
//
//class Circle : public Shape {
//private:
//    float radius;
//
//public:
//    Circle(float r) {
//        radius = r;
//    }
//
//    float area() {
//        return 3.1416 * radius * radius;
//    }
//};
//
//class Rectangle : public Shape {
//private:
//    float len;
//    float wid;
//
//public:
//    Rectangle(float l, float w) {
//        len = l;
//        wid = w;
//    }
//
//    float area() {
//        return len * wid;
//    }
//};
//
//int main() {
//    Circle c1(5);
//    Rectangle r1(4, 6);
//
//    cout << "Area of Circle: " << c1.area() << endl;
//    cout << "Area of Rectangle: " << r1.area() << endl;
//
//    return 0;
//}