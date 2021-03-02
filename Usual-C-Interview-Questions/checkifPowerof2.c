#include <stdio.h>
#include <stdint.h>
 
 //******Prototype*************
 uint8_t CheckPowerOfTwo (int val);
 

//*****Implementation*********
uint8_t CheckPowerOfTwo (int val)
{
  if((val && ( ! (val & (val-1) ) )))
  	return 1 ;
  else
  	return 0;
}
 
 
 

/*Driver program to test above function*/
int main(void)
{
	int x=0;

	printf("Enter the number to test\n");
	scanf("%d", &x);

  if(CheckPowerOfTwo(x))
  	printf("Yes");
  else
  	printf("NO");
  
  return 0;
}