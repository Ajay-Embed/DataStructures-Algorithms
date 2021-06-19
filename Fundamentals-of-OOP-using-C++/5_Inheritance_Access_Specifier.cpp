#include <iostream>

using namespace std;


/***************************************
 *
 * In the previous example, we saw how a
 * Derived class could access members of
 * a Base class. However, note that we 
 * kept all membersof base class public. 
 *
 * In this example, let's see what happens
 * if we use other access specifiers for
 * members in the base class in case of 
 * inheritance. 
 *
 ****************************************/

class Rectangle
{
    private:
        int length;

    protected:
        int breadth; 

    public:
        int area; 
        
        void calc_area()
        {
            area = length*breadth; 
        }

        void setlen(int l)
        {
            length = l;
        }
};

/* Note: "public" keyword before Base class name 
 * denotes we are "publically inheriting" */ 

class Cuboid : public Rectangle
{
    public:
        int height; 
        
        void set_breadth(int b)
        {
            /* We can access protected member of base class 
             * within the derived class */ 

            breadth = b; 
        }

        int calc_volume()
        {
            calc_area();
            return height*area;
        }
};


int main()
{
    Cuboid c;
    
    c.height = 4; 
    
        
    /* Private members can't be accessed via object or within the derived class. */ 
    
    /* Uncomment and observe the result */ 
    //c.length = 10;

    /* Protected members can't be accessed via object but can be accessed within the class. */ 

    /* Uncomment and observe the result */ 
    //c.breadth = 3;

    /* To modify the private member of the base class we need to 
     * use the mutator function exposed by the base class */ 
    c.setlen(10); 

    /* To modify the protected member of the base class we can 
     * use the mutator function exposed by the derived class since
     * the derived class can access protected members of the base class */
    c.set_breadth(3);

    c.calc_area();

    cout<<c.area<<endl<<c.calc_volume(); 

    return 0; 
}


