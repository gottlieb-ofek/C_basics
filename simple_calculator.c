#include <stdio.h>
#

enum return_value_e
{
    UNINITIALIZED = -1, 
    SUCCESS = 1,
    ILLEGAL_OPERATION = 2,
    DEVISION_BY_ZERO = 3,
    ILLEGAL_INPUT = 4,
};

int main() {
    enum return_value_e error_code = UNINITIALIZED;
    
    char operation = '\0'; 
    float num1 = 0;
    float num2 = 0;
    float result = 0;
    int scanning_return_code = -1; 
    int number_of_input_variables = 3 ;

    printf("Please enter number1 operation number2: ");
    scanning_return_code = scanf("%f %c %f", &num1, &operation, &num2);

    if(scanning_return_code != number_of_input_variables){
        printf("Error: recieved illegal input");
        error_code = ILLEGAL_INPUT;
        goto Exit;
    }

    switch (operation)
    {
    case '+':
        result = num1 + num2;
        break;

    case '-':
        result = num1 - num2;
        break;

    case '*':
        result = num1 * num2;
        break;

    case '/':
        if(num2 == 0){
            printf("Error: devision by zero");
            error_code = DEVISION_BY_ZERO;
            goto Exit;
            break;
        }

        result = num1 / num2;
        break;
    
    default:
        printf("Error: not a valid operation \n");
        error_code = ILLEGAL_OPERATION;
        goto Exit;
        break;
    }

    printf("%.2f %c %.2f = %.2f", num1, operation, num2, result);

    error_code = SUCCESS;
Exit:
    return error_code;
}
