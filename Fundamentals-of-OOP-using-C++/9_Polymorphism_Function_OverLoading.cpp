#include <iostream>

using namespace std;

/* Function Over-loading is a feature in C++ that allows a developer
 * to define functions with exactly the same name. In case of function
 * overloading the function names can be same but signatures NEED to 
 * differ, i.e. 2 functions can have the same name but need to have 
 * different arguments/return type. Take a look at this code. 
 *
 */

int add(int a, int b)
{
    cout<<"2 Integer args added=";
    return a+b; 
}

int add(int a, int b, int c)
{    
    cout<<"3 Integer args added=";
    return a+b+c;
}

double add(double a, double b)
{
    cout<<"2 Double args added=";
    return a+b; 
}

int main()
{
    /* We have 3 functions with the same name but let's see which 
     * one gets called based on the arguments passed to it.
     */
    
    cout<<add(2,3)<<endl;

    cout<<add(3,4,5)<<endl; 

    cout<<add(2.3, 3.4)<<endl;


}
