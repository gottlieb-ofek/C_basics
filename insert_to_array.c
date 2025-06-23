#include <stdio.h>

#define NUMBER_OF_INPUT_VARIABLES (1)
#define ARRAY_MAX_SIZE (100)

enum return_value_e
{
    UNINITIALIZED = -1, 
    SUCCESS = 1,
    ILLEGAL_INPUT = 2,
    ILLEGAL_POSITION = 3,
};

int main() {
    enum return_value_e error_code = UNINITIALIZED;

    int array_size = 0;
    int element = 0;
    int position = 0;
    int current_recieved_element = 0;

    int array[ARRAY_MAX_SIZE];

    printf("Input size of array: ");
    if(NUMBER_OF_INPUT_VARIABLES != scanf("%d", &array_size))
    {
        printf("Error: illegal input");
        error_code = ILLEGAL_INPUT;
        goto Exit;
    }

    printf("Input array elements: ");
    for(int i = 0; i < array_size; i++)
    {
        if(NUMBER_OF_INPUT_VARIABLES != scanf("%d", &current_recieved_element)){
            printf("Error: illegal input");
            error_code = ILLEGAL_INPUT;
            goto Exit;
        }
        array[i] = current_recieved_element;
    }
    
    printf("Input element to insert: ");
    if(NUMBER_OF_INPUT_VARIABLES != scanf("%d", &element))
    {
        printf("Error: illegal input");
        error_code = ILLEGAL_INPUT;
        goto Exit;
    }
    
    printf("Input position where to insert: ");
    if(NUMBER_OF_INPUT_VARIABLES != scanf("%d", &position))
    {
        printf("Error: illegal input");
        error_code = ILLEGAL_INPUT;
        goto Exit;
    }

    if(position < 0 || position > array_size){
        printf("Error: illegal position");
        error_code = ILLEGAL_POSITION;
        goto Exit;
    }

    for(int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }

    //shift all element to make place
    for(int i = array_size; i >= position + 1; i--)
    {
        array[i] = array[i-1];
    }
    printf(" -> ");

    array[position] = element;

    for(int i = 0; i < array_size + 1; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    error_code = SUCCESS;
Exit:
    return error_code;
}