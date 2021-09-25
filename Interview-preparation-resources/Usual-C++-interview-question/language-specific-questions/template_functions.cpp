#include <iostream>

using namespace std; 

/* Template functions are useful for defining
 * functions which are expected to be commonly
 * used with different data types, let's take
 * an example of a function that returns the
 * max of elements. 
 *
 * With the help of template functions we can
 * define a single function that can work for
 * all data types, i.e. primitive (int, double etc.)
 * & user defined(classes, structs etc).
 * Let's see an example.
 *
 */

template <class GenType>

GenType maximum(GenType a, GenType b)
{
    /* In case one is using a user-defined
     * class here (say a class representing
     * complex numbers), they will need to
     * overload the operator ">" in that 
     * class to provide this functionality
     */

    return a>b?a:b;
}


int main(void)
{
    int a=3; int b=4;
    cout<<maximum(a,b)<<endl;

    float d=2.3, c=3.4;
    cout<<maximum(c,d)<<endl;
    
    return 0;
}
