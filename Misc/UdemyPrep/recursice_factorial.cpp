#include <iostream>

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

int main()
{
    unsigned long long result = factorial(8);

    std::cout << "Result is " << result << std::endl;

    return 0;
}
