
#include <stdio.h>

#define CHOICE 4

float Sum (float num1, float num2 ) 
{
    return (num1 + num2);
}

float Subtraction (float num1, float num2 ) 
{
    return (num1 - num2);
}
 
float Multiply (float num1, float num2 ) 
{
    return (num1 * num2);
}

float Division (float num1, float num2 ) 
{
    return (num1 / num2);
}

int main()
{
    float (*calculator[CHOICE])(float, float) = {Sum, Subtraction, Multiply, Division};
    
    printf("Enter\n 0 for Sum\n 1 for Subtraction\n 2 for Multiplication\n 3 for Division\n ");
    
    int choice;
    float a, b;
    scanf("%d", &choice);
    
    printf("\nEnter the two numbers\n");
    scanf("%f %f", &a, &b);
    
    printf("%.2f", calculator[choice](a, b));

    return 0;
}
