#include <iostream>
#include <vector>
#include <algorithm>

/*
    - #include <vector>
    - Dynamic Size (handled automatically, can expand/contract as needed, elements are stored in contiguous memory as an array)
    - Direct Element accesss --> contanst time
    - Rapid Insertion and deletion at the back (constant time)
    - All Iterators available and may become invalidated
*/

using namespace std;

int main()
{
    vector<int> vec = {1,2,3,4,5};
    vector<int> vec1 = {9,6,7,45};

    cout << vec.size() << endl;
    cout << vec.front() << endl;
    cout << vec.back() << endl;
    cout << vec.capacity() << endl;

    vec.push_back(6);
    vec.pop_back();

    sort(vec.begin() ,vec.end());

    // Inserting at a particular location in the vector
    // Is not very efficient
    auto it = find(vec.begin() , vec.end() , 3);
    vec.insert(it, 10);

    auto it2 = find(vec.begin(), vec.end(), 10);

    vec.insert(it2 , vec1.begin() , vec1.end());

    for (const auto &vecc : vec)
    {
        cout << vecc << " ";
    }

    cout << endl;

    sort(vec.begin() ,vec.end());

       for (auto &vecc : vec)
    {
        cout << vecc << " ";
    }

    cout << endl;

    return 0;
}

/*
template<typename T>
void display(const vector<T> &vec)
{
    for (const auto &elem:vec)
    {
        cout << elem << endl;
    }
}
*/