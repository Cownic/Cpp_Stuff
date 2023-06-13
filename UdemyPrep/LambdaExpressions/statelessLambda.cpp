/*
    An empty capture list means that the expression captures no information from its environment and only knows about the information passed to it via the function paramemter list
    This is what is known as a stateless lambda expression

    Lambda Expression have the ability to be passed into functions as parameters
    #include <functional>
    void foo(std::function<void(int)> l){l(10);} //c++14
    or
    void foo(void (*l)(int)){l(10);} //c++14
    or 
    void foo(auto l){l(10);} //c++20

    Lambda expressions can be returned from functions
    std::function<void(int)> foo{
        return [](int x){std::cout << x;}
    }
    or 
    auto foo(){
        return [](int x){std::cout << x;}
    }

    to use: auto l = foo();
            l(10);

    Using Lambda Function as function parameters
    foo([](int x){std::cout << x;}) // declare the lambda in the parameter list
    or
    auto l = [](int x){std::cout << x;}
    foo(l);
*/

#include <iostream>

int main()
{
    // for parameter list, we can either pass by reference or value or pointer parameter
    [](){std::cout << "Hi ";};
    int x{10};

    // using auto for parameter type specifier will allow it to take in different kind of type
    [](auto &x){std::cout << x;}(x); // display 100 since it has no knowledge that x was declared at the top

    const int n{3};
    int nums[n]{10,20,30};

    auto sum = [](auto nums[] , auto n){
        auto sum{0};
        for (auto i=0; i < n; i++)
        {
            sum += nums[i];
        }
        return sum;
    };

    std::cout << sum(nums,3);
}

/*
    void test(std::vector<int> v , std::function<bool(int)> func)
    {// do sth;}

    call test(nums , [](int x){return x>50;}) // can return any lambda as long as it has the same input and return type
*/