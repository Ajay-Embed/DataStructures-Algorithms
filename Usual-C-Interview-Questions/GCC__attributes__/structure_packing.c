
#include <stdio.h>

//If this special directive is turned ON (pack(1)), then all the structs in the file will be packed.
#pragma pack(0)  //Currently packing is disabled.. to turn is ON, change to pack(1)


struct var2_t
{
    int a;
    char b;
    int c;
};


//To specially pack a single struct we can use GCC attrribute -  __attribute__((packed)).. Using this we can pack only that struct that we wish to pack
struct var1_t
{
    int a;
    char b;
    int c;
}__attribute__((packed));

int main()
{
    struct var1_t struct_obj_1;
    struct var2_t struct_obj_2;
    
    printf("The size of struct object 1 is - %lu\n", sizeof(struct_obj_1));
    printf("The size of struct object 2 is - %lu\n", sizeof(struct_obj_2));

    return 0;
}

/***********************************************************************************************************
Please go through - https://stackoverflow.com/questions/8568432/is-gccs-attribute-packed-pragma-pack-unsafe

Before using packed attributes/driective in your workplace or hobby projects
***********************************************************************************************************/