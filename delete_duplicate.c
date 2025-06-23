#include <stdio.h>
#include <stdbool.h>

#define NUMBER_OF_INPUT_VARIABLES (1)
#define ARRAY_MAX_SIZE (100)

enum return_value_e
{
    UNINITIALIZED = -1, 
    SUCCESS = 0,
    ILLEGAL_INPUT = 1,
};

void print_array(int array[], int array_size);
bool is_element_in_array(int array[], int element, int array_size);
construct_new_array_with_no_duplicates(int array[], int array_size, int no_duplicates_array[]);

int main() {
    enum return_value_e error_code = UNINITIALIZED;

    int array_size = 0;
    int current_recieved_element = 0;
    int no_duplicates_array_size = 0;
    int array[ARRAY_MAX_SIZE];
    int no_duplicates_array[ARRAY_MAX_SIZE];

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

    no_duplicates_array_size = construct_new_array_with_no_duplicates(array, array_size, no_duplicates_array);
    
    print_array(array, array_size);
    printf("-> ");
    print_array(no_duplicates_array, no_duplicates_array_size);

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

bool is_element_in_array(int array[], int element, int array_size){

    for(int i = 0; i < array_size; i++)
    {
        if(element == array[i])
        {
            return true;
        }
        
    }
    
    return false;
}

int construct_new_array_with_no_duplicates(int array[], int array_size, int no_duplicates_array[]){
    int current_element_to_inspect_duplicates = 0;
    int array_index = 0;

    for(int i = 0; i < array_size; i++)
    {
        current_element_to_inspect_duplicates = array[i];
        if(is_element_in_array(no_duplicates_array, current_element_to_inspect_duplicates, array_index))
        {
            continue;
        }
        no_duplicates_array[array_index] = current_element_to_inspect_duplicates;
        array_index += 1;
    }

    return array_index;
}
