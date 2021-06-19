#include <iostream>

using namespace std; 


/************************************************
 *
 * In the previous examples, we have always used 
 * public inheritance. Let's understand the other
 * kinds of access inheritance.
 *
 ************************************************/

class Base
{
    public:
        int public_member;
    protected:
        int protected_member;
    private:
        int private_member;
};
 


/************** Public Inheritance **************
 *
 * Public inheritance is the most common. It means
 * when you inherit a base class publicly, 
 * 
 * 1. Inherited public members stay public
 *
 * 2. Inherited protected members stay protected.
 *
 * 3. Inherited private members, which were 
 *    inaccessible because they were private in the
 *    base class, stay inaccessible.
 *
 *************************************************/
class PublicDerived: public Base 
{
    // public_member is public
    // protected_member is protected
    // private_member is not accessible 
};

/************** Protected Inheritance **************
 *
 * Protected inheritance is the least common.
 * With protected inheritance, the public and 
 * protected members become protected, and private 
 * members stay inaccessible.
 *
 *************************************************/
class ProtectedDerived: protected Base 
{
    // public_member is protected
    // protected_member is protected
    // private_member is not accessible
};

/************** Private Inheritance **************
 *
 * With private inheritance, all members from the
 * base class are inherited as private. This means
 * private members stay private, and protected and
 * public members become private.
 *
 * Note that this does not affect the way that the 
 * derived class accesses members inherited from its
 * parent. It only affects the code trying to access
 * those members through the derived class.
 *
 *************************************************/
class PrivateDerived: private Base 
{
    // public_member is private
    // protected_member is private
    // private_member is not accessible
};
 
int main()
{
    
    Base base;
    base.public_member = 1;     // Allowed: Member is public in Base
    
    /* Uncomment & Try */ 
    //base.protected_member = 2; // Not allowed: Member is protected in Base
    //base.private_member = 3;  // Not allowed: Member is private in Base
 
    PublicDerived pub;
    pub.public_member = 1;     // Allowed: Member is public in Derived class
    
    /* Uncomment & Try */ 
    //pub.protected_member = 2; // Not allowed: Member is protected in Derived
    //pub.private_member = 3; // Not allowed: Member is inaccessible in Derived
 
    return 0;
}




