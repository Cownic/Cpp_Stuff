/*
    std::list | std::forward_list
    - Seqeunce Containers
    - Non-contiguous in memory
    - No direct access to elements
    - Very efficient for inserting and deleting elements once an element is found

    LIST
    - #include <list>
    - Dynamic size : list of elements, is a bidirectional doubly-linked 
    - Direct element access is not provided
    - Rapid Insertion and deletion of elements anywhere in the container --> constant time
    - All iterators available and invalidate when corresponding element is deleted

    FORWARD LIST
    - #include <forward_list>
    - Dynamic size : lists of elements, unidirectional singly-linked
    - Lesser overhead than list
    - Rapid Insertion and deletion of elements anywhere in the container --> constant time
    - Reverse iterators not availiable, Iterators invalidated when corresponding element is deleted
*/

#include <list>
#include <forward_list>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    list<int> l {1,2,3,4,5};
    cout << l.size() << endl;
    cout << l.back() << endl;
    l.push_front(0);
    auto it = find(l.begin(), l.end() , 3);
    l.insert(it, 10);
    l.resize(10);

    for (const auto &elem:l)
    {
        cout << elem << " ";
    }
    cout << endl;

    // all back iterators are gone
    forward_list<int> fl{9,8,7,6,5};
    fl.front();
    return 0;
}