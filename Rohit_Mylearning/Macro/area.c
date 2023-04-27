//In macros, there is no type checking of arguments so we can use it as an advantage to pass different datatypes in same macros in C

#include <stdio.h>

//object like macro
#define PI 3.14

// function like macro
#define Area(r) (PI*(r*r))

void main()
{
    // declaration and initialization of radius
    float radius = 2.5;

    // declaring and assigning the value to area
    float area = Area(radius);

    // Printing the area of circle
    printf("Area of circle is %f\n", area);
    
    // Using radius as int data type
    int radiusInt = 5;
    printf("Area of circle is %f\n", Area(radiusInt));
 
}
