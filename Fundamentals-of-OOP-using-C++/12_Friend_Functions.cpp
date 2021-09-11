#include <iostream>

using namespace std;

/************** Friend Functions *************/

/* In C++ classes it's a known fact that the 
 * private & protected members of a class are
 * not accessible to functions outside of the 
 * respective class. However, C++ allows us to
 * define functions which are "friends" of some
 * class, thereby granting these friend funcions
 * the access to private & protected members of
 * the respective class. Let's see an example. 
 */


class Drivers
{
    private: 
        int a;
        void printa()
        {
            cout<<a<<endl; 
        }

        friend void interface_function(); 
    protected:
        int b; 
    public:
        int c;
        void printb()
        {
            cout<<b<<endl; 
        }

};

void interface_function()
{
    Drivers d; 

    d.a = 12;
    d.b = 23;
    d.c = 45;

    cout<<d.a<<endl;
    cout<<d.b<<endl;
    cout<<d.c<<endl;
    cout<<"Accessing private function: "; 
    d.printa();

}

int main(void)
{
    Drivers F; 

    // Illegal : 
    // F.a = 12; 
    // F.printa(); 

    interface_function(); 

    return 0;
}
