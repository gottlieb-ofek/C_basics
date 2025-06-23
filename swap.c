#include <stdio.h>
#define NUMBER_OF_INPUT_VARIABLES (1)


enum return_value_e
{
    UNINITIALIZED = -1, 
    SUCCESS = 1,
    ILLEGAL_INPUT = 2,
};

int main() {
    enum return_value_e error_code = UNINITIALIZED;

    int original_number = 0;
    int number = 0;
    int swapped_number = 0;
    int units_digit = 0;

    printf("Input any number: ");
    if(scanf("%d", &number) != NUMBER_OF_INPUT_VARIABLES){
        printf("Error: illegal input");
        error_code = ILLEGAL_INPUT;
        goto Exit;
    }

    original_number = number;

    while(0 != number){
        units_digit = number % 10;
        number = number / 10;
        swapped_number = (swapped_number * 10) + units_digit;
    }

    printf("%d -> %d", original_number, swapped_number);

    error_code = SUCCESS;
Exit:
    return error_code;
}