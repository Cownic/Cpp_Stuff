/*
    Associative Containers - Maps
    - Collection od stored objects that allow fast retrival using a key
    - STL provids Sets and Maps
    - Usually implemented as a balanced binary tree or hashsets
    - Most operations are very efficient

    Sets
    - std::map
    - std::unordered_map
    - std::multimap
    - std::unordered_multimap

    std::map
    - #include <map>
    - Similiar to a dictionary
    - Elements are stored as key-value pair
    - ordered by key
    - no dups allowed
    - direct element access using key
    - all iterators available and invalidate when corresponding element is deleted

    std::multimap
    - #include <map>
    - ordered by key
    - allows dup elements
    - all iterators are available
*/

#include <map>
#include <iostream>
#include <string>

int main()
{
    std::map<int, std::string> m {
        {1,"First"},
        {2,"Second"},
        {3,"Third"}
    };
    // No concept of front or back
    std::cout << m.size() << std::endl;
    m.insert(std::make_pair(4 , "Four"));

    m[1] = "Value_Changed"; // accessing a element using its key

    auto it = m.find(1);

    if (it != m.end())
    {
        m.erase(it);
    }

    return 0;
}