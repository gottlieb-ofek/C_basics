#include <stdio.h>

int main() {

    int num = 0;
    int nth_bit  = 0;

    printf("Input number: ");
    scanf("%d", &num);

    printf("Input nth bit to toggle: ");
    scanf("%d", &nth_bit);

    int num_after_toggle = 0;
    
    num_after_toggle = num ^ (1 << (nth_bit - 1) );

    printf("After toggling nth bit: %d", num_after_toggle);

    return 0; 
}