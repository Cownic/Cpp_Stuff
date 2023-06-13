/*
    Associative Containers - Sets
    - Collection od stored objects that allow fast retrival using a key
    - STL provids Sets and Maps
    - Usually implemented as a balanced binary tree or hashsets
    - Most operations are very efficient

    Sets
    - std::set
    - std::unordered_set
    - std::multiset
    - std::unordered_multiset

    std::set
    - similiar to a mathematical set
    - ordered by key
    - no duplicate of elements
    - all iterators available and invalidate when corresponding element is deleted

    std::multi_set
    - sorted by key
    - allow dup elements
    - all iterators are availiable

    std::unordered_set
    - #include <unordered_set>
    - elements are unordered
    - no duplicate elements are allowed
    - elements cannot be modified --> erase and insert only
    - no reverse iterators allowed
*/

#include <iostream>
#include <algorithm>
#include <set>

int main()
{
    // set are sorted with duplicates removed
    // uses operator < for ordering, there is a need to overload the < operator for user-defined classes
    std::set<int> s {1,20,4,2,3,4,5}; 

    // No concept of front or back
    auto result  = s.insert(7); // --> returns a std::pair<iterator,bool> , first is iterator to the inserted element or dup in the set, second is the boolean result
    auto it = s.find(20);
    if (it != s.end())
    {
        s.erase(it);
    }


    return 0;
}