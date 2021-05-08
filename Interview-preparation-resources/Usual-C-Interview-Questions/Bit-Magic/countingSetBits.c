#include <stdint.h>


//Counting the number of set bits in a number
int main(void)
{
uint8_t x = 255;

int count = 0;

for(int i = 0; i<sizeof(int)*8; i++)
{

    if( (x & (1<<i)) == (1<<i) )
    {
        count++;
    }

}
printf("%d", count);

return 0;
}

