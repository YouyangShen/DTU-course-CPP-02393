//============================================================================
// Name        : live03-templated-classes.cpp
// Description : An example of templated class with two parameters
//============================================================================

#include <iostream>
using namespace std;

// Example based on pairs
// see http://www.cplusplus.com/reference/utility/pair/

template<class A, class B>
class Pair {
private:
    A a;
    B b;
public:
    Pair(A a, B b);
    A first();
    B second();
    void display();
};

template<class A, class B>
Pair<A,B>::Pair(A a, B b) {
    this->a = a;
    this->b = b;
}

template<class A, class B>
A Pair<A,B>::first() {
    return this->a;
}

template<class A, class B>
B Pair<A,B>::second() {
    return this->b;
}

template<class A, class B>
void Pair<A,B>::display() {
    cout << "<" << a << "," << b << ">" << endl;
}

template<class A, class B>
Pair<B,A> flip(Pair<A,B> p) {
    return Pair<B,A>(p.second(), p.first());
}

int main(void) {

    Pair<int,int> a = Pair<int,int>(34, 46);
    Pair<string,double> b = Pair<string,double>("Hello!", 3.14);

    flip(a).display();
    b.display();
    flip(b).display();

    return 0;
}
