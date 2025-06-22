#include <stdio.h>

int main() {

    int num = 0;
    int nth_bit  = 0;
    int num_after_toggle = 0;

    printf("Input number: ");
    scanf("%d", &num);

    printf("Input nth bit to toggle: ");
    scanf("%d", &nth_bit);
    
    int mask_for_nth_bit_on = 1 << (nth_bit - 1);
    num_after_toggle = num ^  mask_for_nth_bit_on;

    printf("After toggling nth bit: %d", num_after_toggle);

    return 0; 
}
