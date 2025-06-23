#include <stdio.h>

#define NUMBER_OF_INPUT_VARIABLES (1)
#define ARRAY_MAX_SIZE (100)

enum return_value_e
{
    UNINITIALIZED = -1, 
    SUCCESS = 0,
    ILLEGAL_INPUT = 1,
    ILLEGAL_POSITION = 2,
};

void print_array(int array[], int array_size);
void make_place_for_element(int array[], int array_size, int position);

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

    print_array(array, array_size);

    make_place_for_element(array, array_size, position);
    printf(" -> ");

    array[position] = element;

    print_array(array, array_size +1);
    printf("\n");

    error_code = SUCCESS;
Exit:
    return error_code;
}

void print_array(int array[], int array_size){
    for(int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
}

void make_place_for_element(int array[], int array_size, int position){
    for(int i = array_size; i >= position + 1; i--)
    {
        array[i] = array[i-1];
    }
}
