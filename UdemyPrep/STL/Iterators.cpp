#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

void test1()
{
    std::vector<int> num1{1,2,3,4};
    auto it = num1.begin(); // std::vector<int>::iterator it = num1.begin();
    for (; it != num1.end() ; it++)
    {
        std::cout << *it << " ";
    }

    it = num1.begin();

    it += 2;
    std::cout << *it << " ";
    it -= 1;
    std::cout << *it << " ";
    it--;
    std::cout << *it << " ";

    std::cout << std::endl;
}


// Const Iterator --> i cant change what i am pointing to
void test2()
{
    std::map<std::string, std::string> hi{};
    hi.insert({"Bill" , "Java"});
    hi.insert({"Frank", "C++"});
    std::map<std::string, std::string>::iterator it = hi.begin();
    for (; it != hi.end() ; it++)
    {
        std::cout<< it->first << " " << it->second << std::endl;
        std::cout << std::endl;
    }
}

int main()
{
    test1();
    test2();
    
    return 0;
}