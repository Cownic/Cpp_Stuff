// Section 17
// Challenge 1
/***********************************************************************************************************
Create a program that has the following:

1. a function named make that creates and returns a unique_ptr to a vector of shared_ptrs to Test objects. 

2. a function named fill that expects a vector of shared pointers to Test objects and a int
   representing the number of Test objects to create dynamically and add to the vector.
   
   This function will prompt the user to enter an integer, create a shared_ptr to a Test object 
   initialized to the entered integer and add that shared pointer to the vector.
   
3. a function named display that expects a vector of shared_ptrs to Test object and displays the
   data in each Test object
*/
#include <iostream>
#include <vector>
#include <memory>


class Test
{
private:
    /* data */
    int data;
public:
    Test():data{0}{
        std::cout << "No-arg Constructor called" << std::endl;
    }
    Test(int num): data{num}{
        std::cout << "Constructor called for (" << num << ")" << std::endl;
    }
    ~Test(){
        std::cout << "Destructor called for (" << data << ")" << std::endl;
    };
    int get_data()
    {
        return data;
    }
};

// Function Prototype
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num); // need to by reference if not the copy of vector will not be updated
void display(const std::vector<std::shared_ptr<Test>> &vec);

int main()
{
    int num;
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: " << std::endl;
    std::cin >> num;
    fill(*vec_ptr , num);
    display(*vec_ptr);
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()
{
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num)
{
    int num1;
    for (int i = 0 ; i < num ; i++)
    {
        std::cin >> num1;
        std::shared_ptr<Test> t1 = std::make_shared<Test>(num1);
        vec.push_back(t1);
    }
}
void display(const std::vector<std::shared_ptr<Test>> &vec)
{
    for (const auto &num: vec)
    {
        std::cout << num->get_data() << " ";
    }
    std::cout << " " << std::endl;
}


