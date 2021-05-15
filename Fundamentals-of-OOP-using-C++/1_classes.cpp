#include <iostream>

using namespace std; 

/******************************* Classes in C++ *****************************************
 *
 * A class in C++ is a user-defined data type, which holds its own 
 * data members and member functions, which can be accessed and used
 * by creating an instance of that class (like we instantiate structures in C). 
 *
 * Below is a definition for class Rectangle. 
 ****************************************************************************************/

class Rectangle
{
    private: 
        float length; 
        float breadth;
    
    public:
        /* This is a data member */
        float perimeter;  

        /* These are member functions */ 
        float area()
        {
            return (length*breadth); 
        }

        void setLen(float l)
        {
            length = l; 
        }

        void setBreadth(float b)
        {
            breadth = b; 
        }

}; /* <= Don't forget this guy after the bracket */ 

/******************************* Access modifiers *****************************************
 *
 * Access modifiers enable implementing "data hiding" principle of OOP.
 * 
 * Access Modifiers or Access Specifiers in a class are used to decide the accessibility 
 * to the class members i.e. it allows to restrict access on the class members by the 
 * outside functions.
 *
 * There are 3 types of access modifiers available in C++: 
 * Public : Class members accessible by everyone. 
 *
 * Private: Class members can only be accessed by the function members of the class.
 *          They are not allowed to be accessed directly by any function outside the class. 
 *          Although some functions called as "friend functions" are allowed to access the 
 *          private data members of a class. We will demonstrate them in a separate file.
 *
 * Protected: Similar to private, class members can’t be accessed outside of the class 
 *            unless with the help of "friend class", the difference is that the
 *            class members declared as Protected can be accessed by any 
 *            subclass (derived class) of that (base) class as well. 
 *
 ******************************************************************************************
 * 
 * In our example, we have "hidden" the data members of the class by using "private", 
 * and exposed functions to manipulate those data members. This is how C++ enables
 * us (programmers) to implement "Abstraction" and "Encapsulation" principles.
 *
 ****************************************************************************************/

int main()
{
    /* Instantiate the class, r1 is called as an "object" */
    Rectangle r1;

    /* Set length of the rectangle r1 */ 
    r1.setLen(10); 

    /* Try doing this => 
     * 
     * r1.length = 10; 
     * r1.breadth= 4;
     *
     */ 

    /* Set the breadth */ 
    r1.setBreadth(4); 

    /* This is mishandling of data, and that's why we need "Data hiding"
     * It would've been smarter to keep perimeter private & expose a function
     * to calculate the perimeter correctly and store it in this variable */  
    r1.perimeter = 12; 
    
    /* That's how you call a member function */ 
    cout<<"Area = "<<r1.area()<<endl ;

    return 0; 
}

/******************************* Memory Details *****************************************
 *
 * For those of you who care, here's where and how the memory allocated to the objects. 
 * 
 * In the example above, the object r1 is allocated memory on the stack. For allocating
 * memory on the heap one may use : Rectangle *ptr = new Rectangle(); 
 *
 * But, 
 * 1. What is the size of the object? 
 * 2. Are the functions also stored on stack and included in the size?
 *
 * The size of the object (on stack) is just the size of the "data members" of the class
 * along with padding (similar to structure padding in C). 
 *
 * The functions are NOT stored on stack, since the functions are going to be the common 
 * for all the objects, the function members of a class are stored in in code segment or 
 * the text section.
 *
 ****************************************************************************************/




