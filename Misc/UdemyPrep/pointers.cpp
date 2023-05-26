#include <iostream>
#include <string.h>

int main()
{
    // if we dont initialize our pointers, we will have garbage data and can point anywhere
    char *char_ptr {nullptr};

    // &char_ptr --> give me the address which the pointer is at
    // Accessing the pointer address --> use & operator
    // Pointer must point to the correct type if not will have compiler error
    // Pointers are all of the same number of bytes but what the pointer points to is different
    // Accessing the data at the pointer address can be achieved by using *

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

    // Relationship between Arrays and Pointers
    // Array points to the first addresss of the array
    // Pointer also points to a address

    int scores[] {100, 95, 89};
    int *scores_ptr {scores};
    std::cout << (scores+1) << std::endl;  // obtain the address at scores[1]
    std::cout << *(scores+1) << std::endl; // obtain the value at scores[1]

    // Comparing pointer will compare if the pointers are pinting to the same location, not same data
    // Pointers to constants --> pointer itself can change but data pointed to canot be changed
    int high_score{100};
    const int *int_ptr{&high_score};
    const int *const intt_ptr{&high_score}; // cannot change the pointer also 

    // Passing pointer into function --> int hello(int *a);
    // Returning pointer from a function --> int *return();

    // Check for uninitialised pointers, dangling pointer, check if allocation o memory is successful




    return 0;
}