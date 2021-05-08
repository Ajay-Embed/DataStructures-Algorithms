

#include <stdio.h>

//This demonstrates the example of variable shadowing.
//"extern" means "get this symbol from the enclosing scope", not "get this symbol from some other link unit".
//That enclosing scope /may/ be another link unit.


int x = 42;

int func_0()
{
    int x = 3840;
    {
        return x;
    }
}


int func_1()
{
    int x = 3840;
    {
        extern int x;
        return x;
    }
}

int main(void)
{
    printf("%d", func_1());

    return 0;
}
