#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main()
{
    /*
        Unique Pointers - unique_ptr<T>
        - points to an object of type T on the heap
        - only can have one unique+ptr<T> pointing to the object on the heap
        - Owns what it points to, cannot be assigned or copied, but can be moved
        - When pointer is destroyed, what it points to is automatically destroyed
    */
    unique_ptr<int> p1{new int{100}};
    cout << *p1 << endl;
    cout << p1.get() << endl;
    p1.reset();
    if (p1) // check if the pointer is created
    {
        cout << *p1 << endl;
    }
    vector<unique_ptr<int>> vec;
    unique_ptr<int> ptr{new int{100}};
    vec.push_back(move(ptr)); // move method is needed to move our unique pointers
    vec.push_back(make_unique<int>(200));

    // A better way to make unique pointers (C++14)
    // unique_ptr<T> <name> = make_unique<T>(T);
    unique_ptr<int> p11 = make_unique<int>(100);
    auto p22 = make_unique<int>(200);
    unique_ptr<int> p33;
    p33 = move(p11); // change the ownership from p1 to p3
                     // for (const auto &acc:accounts){} --> by reference, if not it will do a copy then go into the for loop

    /*
        Shared Pointers
        - Provides shared ownership of heap objects
        - Points to an object of type T on the heap
        - not unique, can have many shared_ptr pointing to the same objects
        - can be assigned, copied and moved
        - doesnt support managing arrays by default
        - when use count is 0, the managed object on the heap is destroyed
    */
    shared_ptr<int> ptr1{new int{100}};
    ptr1.use_count(); // 1
    shared_ptr<int> ptr2{ptr1};
    ptr2.use_count(); // 2
    ptr1.reset();     // -1 of the count

    vector<unique_ptr<int>> vec1;
    shared_ptr<int> ptr{new int{100}};
    vec1.push_back(ptr); // copy is allowed

    // Better way to initialize shared pointers
    shared_ptr<int> ptr11 = make_shared<int>(100);
    auto ptr111 = make_shared<int>(1000);

    return 0;
}

/*
    Issue with raw pointers
    - Allocation, deallocation, lifetime mangement
    - Uninitialized (wild) pointers
    - Memory Leaks
    - Dangling pointers
    - Not exception safe
    - No ownership
*/

/*
    Smart Pointers
    - #include <memory>
    - Defined by class templates
        wrapper around a raw pointer
        overloaded operators : dereference, member selection, pointer arithmetic not supported(++,-- etc)
        can have custom deleters
    - Syntax
        std::smart_pointer<some_class> ptr = ...
        ptr->method;
        cout << *ptr << endl;

    - RAII (Resource Acquisition Is Initialization)
        RAII objects are allocated on the stack
        Resource Allocation
        Is Initialization
        Resource relinquishing
*/