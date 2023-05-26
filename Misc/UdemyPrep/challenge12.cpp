/* Write a C++ Function named apply_all that expects 2 arrays of integers and their sizes and dynamically allocates a new array of integers
    whose size is the product of the 2 array sizes

    function should loop through the second arrau ana multiple each element across each element of array 1 and store the product in the newly created array
    function should also return a pointer to a newly allocated array

    print function also --> inputs : array + size
*/

#include <iostream>

using namespace std;

void print(int array[] , int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        printf("%d ", *(array+i));
    }
    printf("\n");
}

int *apply_all(const int array1[],  int array1size , const int array2[] , int array2size)
{
    int result_size = array1size * array2size;
    int *result_array = new int[result_size];
    int z = 0;

    for (int i = 0 ; i < array2size ; i++)
    {
        for (int j = 0 ; j < array1size ; j++)
        {
            result_array[z] = *(array2+i) * *(array1+j);
            result_array[z];
            ++z;
        }
    }
    return result_array;
}

int main()
{
    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};

    cout << "Array 1: ";
    print(array1,5);

    cout << "Array 2: ";
    print(array2,3);

    int *result = apply_all(array1,5,array2,3);
    cout << "Result: ";
    print(result,15);

    return 0;
}