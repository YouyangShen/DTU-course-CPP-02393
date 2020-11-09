#include <iostream>
#include <string>
#include <vector>


using namespace std;

class fraction {
private:
// Internal representation of a fraction as two integers
  int numerator;
  int denominator;
public:
// Class constructor
  fraction(int n, int d);
// Methods to update the fraction
  void add(const fraction& a,const fraction& b);
  void mult(const fraction& a,const fraction& b);
  void div(const fraction& a,const fraction& b);
// Display method
  void display(void);
  int maxFactor(int nr,int dr); 
};

fraction::fraction(int n, int d){
    numerator=n;
    denominator=d;
}


void fraction::display(void){
    int a = maxFactor(numerator,denominator);
    if(a>1){
		denominator /= a;
		numerator /= a;
        cout << numerator <<" / "<<denominator << endl;
	} 
    else {
        cout << numerator <<" / "<<denominator << endl;
    }   
}

int fraction::maxFactor(int nr,int dr){
    numerator = nr;
    denominator = dr;
    int d;
	 for(d=(numerator<denominator?numerator:denominator);d>=1;d--)
	if(numerator%d==0&&denominator%d==0) 
	{   break;  }
	 return d;
}

void fraction::add(const fraction& a,const fraction& b){
    numerator = a.numerator*b.denominator+b.numerator*a.denominator;
    denominator = a.denominator*b.denominator;
    fraction c (numerator,denominator);
}

void fraction::mult(const fraction& a,const fraction& b){
    numerator = a.numerator*b.numerator;
    denominator = a.denominator*b.denominator;
    fraction c (numerator,denominator);
}

void fraction::div(const fraction& a,const fraction& b){
    numerator = a.numerator*b.denominator;
    denominator = a.denominator*b.numerator;
    fraction c (numerator,denominator);
}

vector<int> fVector;

 void fvector(vector<string> &s){
	unsigned int x;
    for (int j=0; j<3;j++){
		for (int i=0;i<7;i=i+2){
			x=stoi(s[i+7*j]);
			fVector.push_back(x);
		}
    }
	}

int main(){
    string value;
    vector<string> input;
    //cin >> value;
    //input.push_back(value);
   
    while (true) {
        cin >> value;
        input.push_back(value);
        if (cin.fail()) {
            break;
        }
       // cout << "Input: " << value << endl;
    }
    

    


        
           fvector(input);
           for (int i = 0; i < 3; i++){
              
           
        
    
    
      fraction f1(fVector[4*i],fVector[4*i+1]);
      fraction f2(fVector[4*i+2],fVector[4*i+3]);
      fraction f3(1,1);
      if (input[7*i+3]=="+"){
         f3.add(f1,f2);
         f3.display();
      }
      else if (input[7*i+3]=="*"){
          f3.mult(f1,f2);
          f3.display();
      }
      else if (input[7*i+3]=="div"){
          f3.div(f1,f2);
          f3.display();
      }
    
    
      } 
}
        
   
