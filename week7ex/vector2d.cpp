#include "vector2d.h"
#include <cmath>

v2d::v2d(double a, double b){
    x=a;
    y=b;
// put something here
}

v2d::v2d(const v2d & v){
    this->x = v.x;
    this->y = v.y;
// put something here
}

v2d::~v2d(){
// put something here
}

v2d & v2d::operator=(const v2d &v){
    this->x = v.x;
    this->y = v.y;
    return *this;
// put something here
}

v2d & v2d::operator+(const v2d &v){
    this->x = this->x + v.x;
    this->y = this->y + v.y;
    return *this;
// put something here
}

double v2d::operator*(const v2d &v){
    return this->x * v.x + this->y * v.y;
// put something here
}

v2d & v2d::operator*(double k){
    this->x = this->x * k;
    this->y = this->y * k;
    return *this;
// put something here
}

double v2d::length(){
    double len;
    len = x*x + y*y;
    return sqrt(len);
// put something here
}
