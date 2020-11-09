// this is just a simple program to test your implementation
#include <iostream>

#include <cmath>

using namespace std;

template<class A, class B>
class v2d{

public:
    // standard constructor
    // builds a vector (a,b)
    v2d(A a, B b);
    
    // copy constructor
    // builds a vector that is exactly as v
    v2d(const v2d & v);
    
    // destructor
    ~v2d(void);
    
    // assignment
    // updates the vector to make it as v
    v2d & operator=(const v2d &v);
    
    // vector addition
    // updates the vector by adding v
    v2d & operator+(const v2d &v);
    
    // scalar multiplication
    // updates the vector by scaling by k
    v2d & operator*(double k);
    
    // scalar product of the current vector
    // by another vector v 
    double operator*(const v2d &v);    
    
    // computes the length of a vector
    double length(void);

private:
    // internal representation of a vector
    // with just two doubles x and y
    A x;
    B y;
    
};


template<class A, class B>
v2d<A,B>::v2d(A a, B b){
    x=a;
    y=b;
// put something here
}

template<class A, class B>
v2d<A,B>::v2d(const v2d & v){
    this->x = v.x;
    this->y = v.y;
// put something here
}

template<class A, class B>
v2d<A,B>::~v2d(){
// put something here
}

template<class A, class B>
v2d<A,B> & v2d<A,B>::operator=(const v2d<A,B> &v){
    this->x = v.x;
    this->y = v.y;
    return *this;
// put something here
}

template<class A, class B>
v2d<A,B> & v2d<A,B>::operator+(const v2d<A,B> &v){
    this->x = this->x + v.x;
    this->y = this->y + v.y;
    return *this;
// put something here
}

template<class A, class B>
double v2d<A,B>::operator*(const v2d<A,B> &v){
    return this->x * v.x + this->y * v.y;
// put something here
}

template<class A, class B>
v2d<A,B> & v2d<A,B>::operator*(double k){
    this->x = this->x * k;
    this->y = this->y * k;
    return *this;
// put something here
}

template<class A, class B>
double v2d<A,B>::length(){
    double len;
    double X,Y;
    X = this->x;
    Y = this->y;
    len = sqrt(X*X + Y*Y);
    return len;
// put something here
}

int main(){
    
    // we crate here some vectors with fixed values
    v2d <int,int> v1 = v2d <int,int> (3,0); //(3,0)
    v2d <int,int> v2 = v2d <int,int>(0,4);
    v2d <int,int> v3 = v2d <int,int> (3,2);
    // we create here v4 as vector which is like v2
    v2d <int,int>v4(v2);
    
    //
    cout << "Pythagoras holds on perpendicular triangles (a,b,c):\n";
    cout << "a = " << v1.length();
    cout << " , b = " << v2.length();
    
    // we create a new vector v5 here by combining other vectors
    // this vector corresponds to the diagonal of the triangle defined by v1 and v2
    v2d <int,int>v5 = v1 + v2 * (-1);
    
    cout << " , c = " << v5.length() << endl;
    
    cout << "...but not on non-perpendicular triangles (a,b,c):\n";
    cout << "a = " << v3.length();
    cout << " , b = " << v4.length();
    
    v5 = v3 + v4 * (-1);
    
    cout << " , c = " << v5.length() << endl;
    
    /* Output should be:
     Pythagoras holds on perpendicular triangles:
     a=3 b=4 c=5
     ...but not on non-perpendicular triangles:
     a=3.60555 b=4 c=3.60555
     */
    
    // Note that vector operations like + and *
    // modify the vectors on their lhs!
    
    v2d <double,double> w1 =  v2d <double,double> (0,0);
    v2d <double,double> w2 =  v2d <double,double> (1,1);
    v2d <double,double> w3 =  v2d <double,double> (0,0);
    
    cout << "Before w3 = w1 + w2 the length of w1 is... " << w1.length() << endl;
    w3 = w1 + w2;
    cout << "After  w3 = w1 + w2 the length of w1 is... " << w1.length() << endl;
    
    /* Output should be
     Before w3 = w1 + w2 the length of w1 is... 0
     After  w3 = w1 + w2 the length of w1 is... 1.41421
    */
    
    return 0;
}
