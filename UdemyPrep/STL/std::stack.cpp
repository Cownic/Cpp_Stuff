/*
    std::stack
    - LIFO data structure
    - Implemented as an adapter over other STL container
    - Can be implemented as a vector, list or deque
    - all operations occur on one end of the stack
    - no iterators are supported
    - #include <stack>
    - push, pop, top, empty, size methods supported
    - if no container is specified, a deque will be used
*/

#include <stack>
#include <vector>
#include <iostream>

int main()
{
    std::stack<int> s; // use deque container
    std::stack<int, std::vector<int>> s1;

    s.push(10);
    s.push(20);
    std::cout << s.top();
    s.pop();
    
    return 0;
}