#include <stdio.h>

enum return_value_e
{
    UNINITIALIZED = -1, 
    SUCCESS = 1,
};

int main() {
    enum return_value_e error_code = UNINITIALIZED;
    int year = 0;

    printf("Input year: ");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || year %400 == 0) {
        printf("Yay we have leap year 🤰🏻");
    }
    else {
        printf("Nah just a regular year... ");
    }

    error_code = SUCCESS;
    return error_code;
}
