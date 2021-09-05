#include <iostream>

using namespace std; 


/************** Virtual Functions & their requirement ******************
 *
 * In the previous examples we saw how functions can
 * be over-ridden, a base class object calls base class
 * functions, whereas a derived class' object can call
 * both base & derived class's functions with same sign.
 *
 * But what happens when we need to call a derived class' function
 * by using the base class pointer? 
 *
 * Let's consider a practical scenario, supppose, 
 * we need to write a certain call to make use of the 
 * hardware for an OS like Windows. As we all know, 
 * the hardware may differ from device to device.
 *
 * In such cases, we would create a base class & add
 * some functions which are expected to be over-ridden
 * depending on the nitty-gritties of the hardware, i.e.
 * the manufcaturer will implement those functions. 
 *
 * In this scenario, we might need the base class to 
 * be able to call the over-ridden function in the derived
 * class, since it would have the implementaions specific
 * to the underlying hardware. 
 *
 * A typical implementation in such a case would be, the 
 * windows would call a hardware specific initialization
 * function, say Init_Disk, which will return a reference
 * or pointer of base class Disk. This pointer will be 
 * pointing to a derived class object which has the details
 * of the specific disk we have on hardware. 
 *
 * Prototype: Disk* Init_Disk(args); 
 *
 * Typical call by windows system: Disk *d = Init_Disk(args); 
 * 
 * Partial implementation in driver: return (Disk*)&Toshiba_Disk_obj;
 *
 * Now, say the windows system wishes to read/write from this disk, 
 * it will invoke d->ReadDisk(); but the "ReadDisk()" will vary based
 * on the hardware.
 *
 * Virtual functions help us in such scenarios. Let's see how.
 *
 **********************************************************************/

/* Disk class as windows system would define it */

class Disk
{
    public:

        /* We need to declare these functions in base class, 
         * else we won't be able to call them from base's scope
         */

        void Read()
        {
            cout<<"Output from windows read"<<endl; 
        }

        virtual void Write()
        {
            cout<<"Output from windows write"<<endl;
        }

};

/* Derived class defined in hardware-specifc driver */ 
class Toshiba_Disk : public Disk
{
    public:
        
        /* The actual hardware specific read */ 
        void Read()
        {
            cout<<"Output from hardware read"<<endl;
        }

        /* The actual hardware specific write */
        void Write()
        {
            cout<<"Output from hardware write"<<endl;
        }
};

int main()
{

    /* What happens if we have a base class pointer to the derived class object? Let's see */
    Disk *ptrBase = new Toshiba_Disk();
    
    /* The pointer type will define which class's function will be called. */
    ptrBase->Read(); 

    /* The above call resulted in calling of our window's dummy call */ 
    
    /* Let's see how does virtual functions help */
    ptrBase->Write(); /* This calls the derived class's over-ridden function, 
                         since it's delared as a virtual function in base class */

    return 0; 
}
