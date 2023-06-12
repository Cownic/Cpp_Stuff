#include <deque>
#include <iostream>

/*
    - #include <deque>
    - Dynamic Size : handled automatically, elements are not store in contiguous memory
    - Direct element access
    - Rapid insertion and deletion at the front and back
    - Insertion or removal of elements in linear time
    - All iterators availiable and may become invalidated
    - Is like a linked-list of vectors
*/

using namespace std;
template<typename T>
void display(const deque<T> &d)
{
    for (const auto &elem : d)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    deque<int> d{1,2,3,4,5};
    deque<int> d1(10,100); // create 10 100 in the data structure
    display(d);
    d.push_back(6);
    display(d);
    d.push_front(0);
    display(d);

    cout << d.at(0) << endl;
    



    return 0;
}