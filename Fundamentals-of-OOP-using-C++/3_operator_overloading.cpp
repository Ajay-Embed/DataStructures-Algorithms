#include <iostream>

using namespace std;

class Complex
{
    public: 
        float real;
        float img; 
        
        Complex operator+(Complex C)
        {
            Complex temp; 
            
            temp.real = real + C.real; 
            temp.img = img + C.img; 
            return temp; 
        }
};


int main(void)
{
    Complex n1, n2, n3; 

    n1.real = 5; 
    n1.img = 4;
    n2.real = 23; 
    n2.img = 21; 

    n3 = n1 + n2 ;
    
    cout<<"Result: "<<n3.real<<"+i"<<n3.img;

}
