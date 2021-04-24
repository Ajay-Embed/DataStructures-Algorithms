
#include <stdio.h> 
#include <stdint.h> 

int main(void)  
{ 
   uint32_t i = 1; 
   uint8_t *p = (uint8_t*)&i; 
   if (*p != 0)
   {
       printf("Little endian");  
   }
   else
       printf("Big endian");
   return 0; 
}


