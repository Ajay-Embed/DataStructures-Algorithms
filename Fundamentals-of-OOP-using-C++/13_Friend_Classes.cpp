#include <iostream>

using namespace std;

/************** Friend Functions *************/

/* Similar to Friend functions, C++ allows 
 * definition of "friend classes", this allows
 * classes to share all types of members among
 * themselves. These can be used at places where
 * multiple classes are interacting at the same 
 * level (i.e. no inheritance) to execute tasks.
 *
 */

class Drivers; 

class Registers
{
    private:
        int a;
    friend Drivers; 
};

class Drivers
{
    Registers R; 
    public:
        void fun()
        {
            R.a = 12; 
            cout<<R.a<<endl; 
        }
};

int main(void)
{
    Drivers d;
    d.fun();
    
    return 0; 
}
