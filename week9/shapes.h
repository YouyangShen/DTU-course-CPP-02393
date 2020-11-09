#ifndef SHAPES_H_
#define SHAPES_H_

#include <string>
#include <cmath>
#include <vector>

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
#endif /* SHAPES_H_ */