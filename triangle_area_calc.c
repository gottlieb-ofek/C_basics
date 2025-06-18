#include <stdio.h>

int main() {

    int base;
    int height;


    printf("Enter base of the triangle: ");
    scanf("%d", &base);

    printf("Enter height of the triangle: ");
    scanf("%d", &height);

    printf("Area of the triangle = %.2f sq. units", (float)height*base/2);

    return 0; 
}