#include <vector>
#include <algorithm>
#include <iostream>

struct Square_Functor{
    void operator()(int x){ // overloads () operator, which stands for function method
        std::cout << x*x << " ";
    }
};

void square1(int x) //using function pointer
{
    std::cout << x*x << " ";
}

int main()
{
    Square_Functor square;
    std::vector<int> vec{1,2,3,4};
    std::for_each(vec.begin(), vec.end() , square);
    std::for_each(vec.begin(), vec.end() , square1); // dont put () after the name of function
    std::for_each(vec.begin(), vec.end() , [] (int x){std::cout << x*x << " ";}); // using lambda 

    std::vector<int> vec1{1,2,3,4};
    auto it = std::find(vec1.begin(), vec1.end() , 3);
    if (it != vec1.end()){
        std::cout << *it << std::endl;
    }
    else 
    {
        std::cout << "Could not find the number" << std::endl;
    }
    std::cout << std::endl;

    int num = std::count(vec1.begin(), vec1.end() , 1); // count the number of 1 in the vector
    std::cout << num << std::endl;

    int num1 = std::count_if(vec1.begin(), vec1.end(), [](int x){return x%2 == 0;}); // return count for even number only
    std::cout << num1 << std::endl;

    return 0;
}