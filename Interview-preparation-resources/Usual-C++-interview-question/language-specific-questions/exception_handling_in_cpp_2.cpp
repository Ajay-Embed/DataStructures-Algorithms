#include <iostream>

using namespace std;

/* More about exceptions, we can explicitly mention
 * if a function "throws" a particular type of value
 * as show below. This makes the code more readable. 
 * 
 * Note: This feature was deprecated in C++11 standard
 */ 

int divide(int numerator, int denominator) throw(int)
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

float div_float(float numerator, float denominator) throw(float)
{
        
    if(denominator == 0)
        throw float(1.25); 

    return (numerator/denominator); 
}



int main(void)
{
    int a=0, b=10, c=0; 
    float d=0.00, e=2.32, f = 0; 
    try
    {
        c = divide(b,a); // comment this to allow div_float to execute
        
        f = div_float(e,d); 
        cout<<"Result of division= "<<c<<endl;
    }
    
    /* We can also have multiple catch blocks, each for a type of throw */
    catch(int errorcode)
    {
        cout<<"Exception Hit! "; 

        /* We can have a separate handler for each errno */ 
        if(errorcode == -1)
        {
            cout<<"Error: "<<errorcode<<" Division by Zero attempted."<<endl;
        }
    }

    catch(float errorcode)
    {
        if(errorcode == (float)1.25)
        {
            cout<<"Error: "<<errorcode<<" Division by Zero attempted.(float)"<<endl;
        }
    }
    
    cout<<"End of Program"<<endl;

    return 0;
}
