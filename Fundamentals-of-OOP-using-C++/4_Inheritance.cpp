#include <iostream>

using namespace std; 


/*****************************************************
 *
 * C++ allows classes to "inherit" some members
 * from other classes. A "Base class" is the one
 * whose features are inherited by a "Derived class".
 *
 * Inheritance can be useful in many ways, for e.g. 
 * we have a class rectangle & we wish to develop a 
 * class for cuboid. In this case, we can "inherit"
 * members from the rectangle class in our cuboid 
 * class. This file introduces a basic implementation.
 *
 *****************************************************/

class Rectangle
{
    public: 
        int length;
        int breadth;

        void print()
        {
            cout<<"L="<<length<<endl<<"B="<<breadth<<endl ;
        }
};

/* Deriving a class from class Rectangle */

class Cuboid : public Rectangle
{
    public:

        int height; 

        void display()
        {
            /* Note that we didn't declare any object of
             * class Rectangle here, but still we can call
             * print() as defined in class Rectangle 
             */ 

            print(); 
            cout<<"H="<<height;
        }
};


int main(void)
{
    Cuboid c; 
    
    /* Note that we haven't declared any object of
     * class Rectangle, still we can set length &
     * breadth which are defined in class Rectangle.
     * This depicts "inheritance" of a members from 
     * one class to the other. 
     */

    c.length = 5; 
    c.breadth = 4;
    c.height = 2; 

    c.display();

    return 0;
}

