#include <iostream>

using namespace std; 


/* Function Over-riding is a feature in C++ that allows a developer
 * to define functions with exactly the same signature to perform
 * different tasks. Function "Overriding" differs from "overloading"
 * because in case of function "overloading" the function names can
 * be same but signatures NEED to differ, i.e. 2 functions can have 
 * the same name but need to have different argument/return types. 
 *
 * In case of function "overriding", multiple functions with exactly 
 * the same signature can be written to perform different tasks. In
 * this case, inheritance facilitates a way for doing this. 
 * Read the following code to understand further. 
 */

class Base
{
    public:
        void print()
        {
            cout<<"Hello from the Base class"<<endl;
        }
};

class Derived : public Base
{
    public: 
        void print()
        {
            cout<<"Hello from Derived class"<<endl;
        }
};

int main(void)
{
    /* We have two classes, one inheriting from the other
     * and both these classes have a public function with 
     * the same exact signature, i.e. name, arguments & 
     * return types are the same. The developer can control
     * which function gets called and when, let's see how. 
     */

    Base b; 
    Derived d; 
    
    /* Since we are using an object of Base class, it's function will be called */ 
    b.print(); 
    
    /* Since we are using an object of Derived class, it's function will be called */ 
    d.print(); 

    /* But can't we call base class' function from the derived? Yes we can! Here's how */
    d.Base::print();

    return 0;
}
