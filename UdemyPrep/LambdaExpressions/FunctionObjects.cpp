#include <vector>
#include <iostream>
#include <algorithm>

class Multiplier{
    private:
        int num{};
    public:
        Multiplier(int n) : num{n} {}
        int operator()(int n) const { // they always have a overloaded function call operator
            return num*n;
        }
};

template<typename T>
struct Displayer
{
    void operator()(const T &data)
    {
        std::cout << data << " ";
    }
};


int main()
{
    std::vector<int> v{1,2,3,4,5};
    Multiplier mult{10}; // Function Object

    std::transform(v.begin(), v.end() , v.begin(), mult);

    std::for_each(v.begin() , v.end() , [](int x){std::cout << x << " ";});


    return 0;
}