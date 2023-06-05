#include <iostream>
#include <string>

// Add sum the digits in a given integer
int sum_of_digits(int n) {
    if (n <= 0)
    {
        return 0;
    }
    else {
        return n%10 + sum_of_digits(n/10);
    }
}

// Factorial Function
unsigned long long factorial(int num)
{
    // Base Case
    if (num == 0)
    {
        return 1;
    }
    // Recursive Step
    return num * factorial(num-1);
}

// Fibonacci Function
unsigned long long fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    unsigned long long result;

    std::cout << "Factorial Result is " << factorial(8) << std::endl;
    std::cout << "Fibonacci Result is " << fibonacci(30) << std::endl;
    std::cout << "Sum_of_Digits Result is " << sum_of_digits(1234) << std::endl;

    return 0;
}
