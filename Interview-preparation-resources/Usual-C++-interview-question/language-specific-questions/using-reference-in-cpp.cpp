/*
	Reference of a variable must not be confused with the concept of pointers.
*/


#include <iostream>

int main(void)
{

	int a = 10;

	//We can create an alias for the variable a that can be used as a reference to a.
	int &b = a;

	//Now the operations the we perform on b will indicate the same effect on a as well
	//Note : the initial value of a was 10

	b = 100;
	std::cout <<"Value of b is - " << b  << std::endl;

	//a is now 100 
	std::cout <<"Value of a is - " << a << std::endl;



	//Reference of a variblae in C++ must not be confused with the concept of pointers. It's simply an alias. Note how the addresses of both a & b are same :)
    std::cout <<"address of a is - " << &a << std::endl;
    std::cout <<"address of b is - " << &b << std::endl;

    return 0;
}