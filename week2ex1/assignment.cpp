#include <iostream>
using namespace std;
int sumEven(int n)
{
    int value = 0;
    for (int i = 0;i <= n/2;i++)
    {
        value = value + 2*i;
    }
    return value;
}

int gaussian_sum(int n){
    if (n==1) {
        return 1 ;
    }
    
    if (n<1) {
        return 0;
    }
    else {
        return gaussian_sum(n-1)+n;
    }
}

int term(int n){
    if (n==1) {
        return 1;
    }
    if (n<1) {
        return 0;
    }
    else{
        return term(n-1)*(-1);
    } 
    

}

double pi(int n){
    double value = 0;
    for (double i=1;i<=n;i++){
        value = value + (term(i))/(2*i-1);
    }
    return value;
}

int prime_factor(int n){
    for (int i = 2; i<=n/2; i++)
        if (n % i == 0){
            if (n > i){
                cout << i << " * ";
            }
            else{
                cout << i << endl;
            }
        return prime_factor(n/i);
        } 
        return n;
    }

int main()
{
   int n = 0; 
   cin >>  n;
   cout << prime_factor(n);

}
