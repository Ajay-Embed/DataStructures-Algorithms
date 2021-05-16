#include <iostream>

using namespace std; 

/***************** Constructors in C++ ***********************
 *
 * In the previous example (1_classes.cpp)
 * we didn't consider a few cases of use. 
 *
 * What happens if someone calls the area function 
 * without setting the length and the breadth? 
 * It is possible that the values are garbage & -ve. 
 *
 * In order to avoid such scenarios, C++ offers us
 * to define special functions called "Constructors"
 * that decide the default values of data members of class 
 * while creation of it's instance (object). 
 *
 * Constructors are overloaded functions, (i.e. functions
 * with same names but different argument types or return 
 * types.) 
 *
 * The name of these constructor functions always has to be
 * the name of the class. 
 *
 * There can be 3 types of constructors: 
 *
 * 1. Unparametrized/Default (without arguments)
 * 2. Parametrized (with arguments)
 * 3. Copy Constructor (reference to an object as an argument)
 *
 **************************************************************/

/* Let's define the same class Rectangle and see how constructors work */

class Rectangle
{
    private: 
        float length; 
        float breadth;
    
    public:
        
        /* Constructor Prototypes */ 
        
        Rectangle();
        Rectangle(float l, float b); 
        Rectangle(Rectangle &r); 
        
        /* Other prototpyes */
        float area();
}; 

/****************************************************************************
 * NOTE: Defining functions inside classes are assumed to be inline functions
 *       by the C++ compiler. It is always a good coding practice to declare
 *       prototypes of member functions in the class definition and define
 *       member functions using the scope resolution operator. 
 *       In practice, never define inline functions with complex logic. 
 ***************************************************************************/

/* Notice constructors don't have a return type, adding one throws an error */ 

/* Unparamterized constructor */
Rectangle :: Rectangle()
{
    length = 1; 
    breadth = 1 ;
}

/* Paramterized constructor */
Rectangle :: Rectangle(float l, float b)
{
    length = l; 
    breadth = b; 
}

/* Copy constructor */
Rectangle :: Rectangle(Rectangle &r)
{
    length = r.length; 
    breadth = r.breadth; 
}

float Rectangle :: area()
{
    return (length*breadth); 
}

int main(void)
{
    /* Unparamterized constructor */
    Rectangle r; 
    
    /* Paramterized constructor */
    Rectangle r1(12,15); 
    
    /* Copy constructor */
    Rectangle r2(r1); 

    cout<<"Area r="<<r.area()<<endl;
    cout<<"Area r1="<<r1.area()<<endl;
    cout<<"Area r2="<<r2.area()<<endl;

    return 0; 
}


/************************* Problem with copy constructor *******************************
 *
 * Be mindful while using the copy constructor, with pointers. 
 * For example :
 *
 * class T
 * {
 *   int data; 
 *   int *arr;
 *
 *   T(int x)
 *   {
 *      data = x;
 *      arr = new int[data]; 
 *   }
 *
 *   T(T &t)
 *   {
 *      data = t.data; 
 *      arr = t.arr;  ==> Problem: This will point to the same array as the argument, 
 *                        whereas we need it to point to a freshly allocated array.
 *   }
 *
 * }; 
 *
 *************************************************************************************/ 

