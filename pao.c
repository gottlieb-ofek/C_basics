#include <stdio.h>

int main() {
    
    int n1;
    int n2;

    printf("First number: ");
    scanf("%d", &n1);

    printf("Second number: ");
    scanf("%d", &n2);

    printf("Sum = %d\n", n1 + n2);
    printf("Difference = %d\n", n1 - n2);
    printf("Product = %d\n", n1 * n2);
    // we can have devision by zero but exceptions is not part of the basic exercise 
    printf("Quotient = %f\n", (float)n1 / n2);
    printf("Modulus = %d", n1 % n2);
   
    return 0;
}