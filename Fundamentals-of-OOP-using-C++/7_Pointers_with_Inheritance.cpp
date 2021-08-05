#include <iostream>


using namespace std;

/* We can assign pointers of type Base class 
 * to objects of their derived clsses. Look 
 * at the code below to understand. 
 */ 

class Base
{
    public: 
        int a;
        int b;
        int c;
};

class Derived : public Base
{
    public:
        int d;
        int e;
};

int main(void)
{
    Derived derivedObj;
    Base *Baseptr;

    Baseptr = &derivedObj; 

    /* That being said, using this pointer we can access 
     * only those members that are present in the base class
     */

    Baseptr->a = 1; 
    Baseptr->b = 2;
    Baseptr->c = 3; 

    /* See what happens if the followinf line is uncommented */
    //Baseptr->d = 4;
    
    cout<<Baseptr->a<<endl<<Baseptr->c; 

    return 0;
}
