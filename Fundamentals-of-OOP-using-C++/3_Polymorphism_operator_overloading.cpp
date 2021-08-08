#include <iostream>

using namespace std;

/**************************************************************
 * Operator overloading is an example of Polymorphism
 * i.e. the same operator acts differently depending on
 * situations. The best example of this in C++ is the 
 * operator " << ", with std::cout it behaves differently
 * and with numbers (int a = 1<<2) it behaves as a binary
 * left shift operator. The reason is that it's overloaded.
 *
 * The following piece of code demonstrates the way one can
 * overload operators. It overloads the "+" arithmetic operator 
 * to add two variables of the complex class (2 complex numbers)
 *
 ***************************************************************/

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
