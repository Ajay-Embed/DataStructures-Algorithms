/**************************************************************************************************************
	Here we will implement a safe version for free() function.

	The need of a safer free() arises when the programmer unknowingly frees the same pointer that is 
	pointing towards a particular block of memory in heap twice. This may lead to system crash.
	
	I leave it upto you to explore the reason why :)
	
	
	For example - 

	int *ptr = (int *)malloc(2000);
	--
	--
	--
	free(ptr);
	--
	--
	--
	--
	--
	...after a hundred/thousand/million lines of code...
	--
	--
	--
	free(ptr); 			^_^


	Pointers can cause problems even after they have been freed. 
	If we try to dereference a freed pointer, its behavior is undefined. As a result, some programmers will 
	explicitly assign NULL to a pointer to designate the pointer as invalid. 
	Subsequent use of such a pointer will result in a runtime exception.

	For example -

	int *ptr = (int *)malloc(2000);
	*ptr = 0xDEADBEEF;
	free(ptr);
	ptr = NULL;

	This technique attempts to address problems like dangling pointers. However, it is better
	to spend time addressing the conditions that caused the problems rather than crudely
	catching them with a null pointer. 
	In addition, you cannot assign NULL to a constant pointer except when it is initialized !
***************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define safeFree(p) saferFree((void**)&(p))


/*
	The saferFree function calls the free function that actually deallocates the memory.
	
	Its parameter is declared as a pointer to a pointer to void. 
	
	Using a pointer to a pointer allows us to modify the pointer passed. 

	Using the void type allows all types of pointers to be passed. 

	However, we get a warning if we do not explicitly cast the pointer type to void when we call the function. 

	If we explicitly perform the cast, then the warning goes away
*/
void saferFree(void **pp) 
{
	if (pp != NULL && *pp != NULL) 
	{
		free(*pp);
		*pp = NULL;
	}
}


//Usage of the implemented macro/
int main(void) 
{
	int *pi;
	pi = (int*) malloc(sizeof(int));
	*pi = 5;

	printf("Before: %p\n",pi);
	safeFree(pi);
	
	printf("After: %p\n",pi);
	safeFree(pi);

return 0;
}