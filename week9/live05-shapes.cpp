//============================================================================
// Name        : live05-shapes.cpp
// Description : Any circle    is a shape.
//			 	 Any rectangle is a shape.
//			 	 Any square    is a rectangle --- and therefore, a shape.
//============================================================================

#include <iostream>
#include <vector>
//#include "shapes.h"

using namespace std;

class Shape {
protected:
double l;
double w;
vector<Shape *> shapes;

public:
Shape(double a, double b){
    this->l = a;
    this->w = b;
}

virtual double area(void)const =0;
virtual double perimeter(void)const =0;
virtual double height(void)const =0;
virtual double width(void)const =0;
void rotate();
};

class Circle: public Shape {
    public:
    Circle(double a):Shape(a,a){}
         virtual double height(void)const{return 2*l;}
         virtual double width(void)const{return 2*l;}
         virtual double area(void)const{return l*l*3.14;}
         virtual double perimeter(void)const{return l*3.14*2;}
};

class Rectangle: public Shape{
    public:
    Rectangle(double b, double c):Shape(b,c){}
     virtual double height(void)const{return l;}
     virtual double width(void)const{return w;}
     virtual double area(void)const{return l*w;}
     virtual double perimeter(void)const{return (l+w)*2;}
    
};

class Square: public Rectangle{
    public:
    Square(double d):Rectangle(d,d){
        }
    //  double height(void){return l;}
    //  double width(void){return l;}
    //  double area(void){return this->l * this->w;}
    //  double perimeter(void){return (this->l+this->w)*2;}
};

void Shape::rotate(){
        double temp = this->l;
        this->l = this->w;
        this->w = temp;
    }

int main(void){
    vector<Shape *> shapes;

    Rectangle u(2,5);
    shapes.push_back(&u);
    Square v(3);
    shapes.push_back(&v);
    Circle w(2);
    shapes.push_back(&w);

    // Enumerating all areas
    cout << "Areas..." << endl;
    double area = 0;
    for(int i=0;i<shapes.size();i++){
            Shape * p = shapes[i];
        cout << p->area() << " ";
        area += p->area();
    }
    cout << endl << "Total area is " << area << endl;

    // Enumerating all areas
    cout << "Perimeters..." << endl;
    double perimeter = 0;
    for (int i=0; i<shapes.size(); i++) {
            Shape * p = shapes[i];
        cout << p->perimeter() << " ";
        perimeter += p->perimeter();
    }
    cout << endl << "Total perimeter is " << perimeter << endl;

    // I want to put them side-by-side
    // And see how much space they use (width and height)
    cout << "Placing side-by-side..." << endl;
    double width = 0;
    double height = 0;
    for (int i=0; i<shapes.size(); i++) {
            Shape * p = shapes[i];
        width += p->width();
        if(height < p->height()){
            height = p->height();
        }
    }
    cout << "Total width is " << width << endl;
    cout << "Total height is " << height << endl;

    // I now try to do the same, but minimizing width
    // First, I rotate those shapes that need it
    for (int i=0; i<shapes.size(); i++) {
            Shape * p = shapes[i];
        if(p->width() > p->height()) {
            p->rotate();
        }
    }
    // Then I proceed as before
    cout << "Placing side-by-side..." << endl;
    width = 0;
    height = 0;
    for (int i=0; i<shapes.size(); i++) {
            Shape * p = shapes[i];
        width += p->width();
        if(height < p->height()){
            height = p->height();
        }
    }
    cout << "Total width is " << width << endl;
    cout << "Total height is " << height << endl;

    return 0;
}
