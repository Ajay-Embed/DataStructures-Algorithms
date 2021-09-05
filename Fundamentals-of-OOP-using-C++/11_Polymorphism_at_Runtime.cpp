#include <iostream>

using namespace std; 

/* Suppose a situation, wherein there are multiple disks
 * on a device. The Windows system programs need to invoke
 * the particular functions of a brand of disks in such case.
 * Say, user asks to write on Disk A & then read from Disk B. 
 *
 * Here's where the need of runtime polymorphism would arise. 
 * Based on the disk of choice, the Windows system will just 
 * modify the pointer of the base class. Let's see an example.
 */

/* Disk class as windows system would define it, such a definition
 * of a class is called an "Abstract class" . This class NEEDS to 
 * be used in conjunction with a derived class & won't work alone.
 *
 * If a class is having pure virtual function(s), it's called an
 * abstract class. We can't create objects of abstract classes 
 * but we can create pointers of such classes.
 */

class Disk
{
    public:

        /* We need to declare these functions in base class, 
         * else we won't be able to call them from base's scope
         * Note that we haven't defined them this time. 
         *
         * The following declaration makes it necessary for the
         * derived classes to define these functions. Such functions
         * are called "Pure virtual" functions.
         */

        virtual void Read() = 0; 
   

        virtual void Write() = 0;
};

/* Derived class defined in hardware-specifc driver */ 
class Toshiba_Disk : public Disk
{
    public:
        
        /* The actual hardware specific read */ 
        void Read()
        {
            cout<<"Output from Toshiba read"<<endl;
        }

        /* The actual hardware specific write */
        void Write()
        {
            cout<<"Output from Toshiba write"<<endl;
        }
};

class Samsung_Disk : public Disk
{
    public:

       /* The actual hardware specific read */ 
        void Read()
        {
            cout<<"Output from Samsung read"<<endl;
        }

        /* The actual hardware specific write */
        void Write()
        {
            cout<<"Output from Samsung write"<<endl;
        }


};

int main()
{
    /* Runtime Polymorphism: We are invoking two different functions from the same place */

    Disk *baseptr = new Toshiba_Disk();

    baseptr->Read(); 

    baseptr = new Samsung_Disk();

    baseptr->Read();

}

/* Conclusion: Classes in C++ can be used for multiple purposes. 
 * Normal classes along with inheritance can be used for re-usability. 
 * Abstract classes along with inheritance can be used as "interfaces" as depicted above. 
 * Both of the above can be combined as well (i.e. have both pure virtual
 * & non-virtual functions) & be used for re-usable interfaces (most common use case).
 */
