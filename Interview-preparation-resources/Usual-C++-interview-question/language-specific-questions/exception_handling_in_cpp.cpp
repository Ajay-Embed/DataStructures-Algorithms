#include <iostream>

using namespace std; 

/* Exception handling is a feature provided by C++
 * to handle run-time anomalies or abnormal conditions
 * that a program encounters during its execution, e.g.
 * disc failure, CPU faults etc. C++ provides following
 * specialized keywords for this purpose-
 * 
 * 1. try: Represents a block of code that can throw an 
 *    exception.
 *
 * 2. catch: Represents a block of code that is executed 
 *    when a particular exception is thrown, i.e. the handler 
 *    of that exception.
 * 
 * 3. throw: Used to "throw" an exception, which is typically 
 *    like an argument that is passed to the "catch" block.
 *
 * Exception handling is typically used when functions run
 * into some issue while executing & aren't able to "return".
 *
 * Let's take a simple example of dividing a number by zero. 
 *
 */

int divide(int numerator, int denominator)
{
    /* We see that denominator can't be 0, so why not put an
     * if condition say if(denominator == 0) return -1 ?
     *
     * Because, how do we tell the caller-function that there
     * was an exception? We can't return any integer/number as
     * the caller-function will treat it as the result of the 
     * division! This is why exception handling is needed.
     */
    
    if(denominator == 0)
        throw -1; 

    return (numerator/denominator); 
}


int main(void)
{
    int a=0, b=10, c=0; 

    try
    {
        c = divide(b,a); 
        cout<<"Result of division= "<<c<<endl;
    }
    
    /* An ellipsis can also be used to make it variadic: catch(...) */
    catch(int errorcode)
    {
        cout<<"Exception Hit! "; 

        /* We can have a separate handler for each errno */ 
        if(errorcode == -1)
        {
            cout<<"Error: "<<errorcode<<" Division by Zero attempted."<<endl;
        }
    }
    
    cout<<"End of Program"<<endl;

    return 0;
}
