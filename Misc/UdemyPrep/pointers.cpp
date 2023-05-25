#include <iostream>
#include <string.h>

int main()
{
    // if we dont initialize our pointers, we will have garbage data and can point anywhere
    char *char_ptr {nullptr};

    //&char_ptr --> give me the address which the pointer is at
    // Accessing the pointer address --> use & operator
    // Pointer must point to the correct type if not will have compiler error
    // Pointers are all of the same number of bytes but what the pointer points to is different
    // Accessing the data aty the pointer address can be achieved by using *

    // Dynamic Memeory Allocation --> done using the new keyword
    int *int_ptr {nullptr};
    int *array_ptr {nullptr};
    size_t size{5};
    int_ptr = new int;
    array_ptr = new int[size];
    
    *int_ptr = 100;

    // must do this to free the allocated storage
    delete int_ptr;  
    delete [] array_ptr;



    return 0;
}