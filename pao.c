#include <stdio.h>

int main() {
    
    int n1 = 0;
    int n2 = 0;

    printf("First number: ");
    scanf("%d", &n1);

    printf("Second number: ");
    scanf("%d", &n2);

    printf("Sum = %d\n", n1 + n2);
    printf("Difference = %d\n", n1 - n2);
    printf("Product = %d\n", n1 * n2);
    if (n2 == 0) {
        printf("Error: devision by zero");
        goto Exit;
    }
    printf("Quotient = %f\n", (float)n1 / n2);
    printf("Modulus = %d", n1 % n2);
   
Exit:
    return 0;
}