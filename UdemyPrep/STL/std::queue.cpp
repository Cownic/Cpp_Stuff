/*
    std::queue
    - FIFO data structure
    - Implemented as an adaptor over other STL container
    - Implemented as a list or deque
    - Elements pushed at the back and popped from the front
    - No iterators are supported
    - #include <queue>
    - push(back), pop(front), front, back, empty, size methods
*/

#include <queue>
#include <deque>
#include <iostream>
#include <list>


int main()
{
    std::queue<int> q; // use deque
    std::queue<int, std::list<int>> q1;
    q.push(10);
    q.push(20);
    q.pop();
    q.size();


    return 0;
}