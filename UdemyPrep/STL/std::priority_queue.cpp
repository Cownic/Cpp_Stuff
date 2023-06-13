/*
    std::priority_queue
    - allows insertion and removal of elemenst in order drom the front of the container
    - elements are stored internally as a vector by default 
    - eleents are inserted in priority order --> largest value is at the front
    - no iterators are supported
    - push, pop, top, empty, size
*/

#include<queue>
#include<iostream>

int main()
{
    std::priority_queue<int> pq;

    pq.push(10);


    return 0;
}