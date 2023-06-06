#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

void print_menu()
{
    std::cout << "Enter the Option: " << std::endl;
    std::cout << "P - Print numbers " << std::endl;
    std::cout << "A - Add numbers " << std::endl;
    std::cout << "M - Display the mean of the numbers " << std::endl;
    std::cout << "S - Display the smallest numbers" << std::endl;
    std::cout << "L - Display the largest numbers" << std::endl;
    std::cout << "Q - Quit" << std::endl;
}

void display_smallest(std::vector<int> list)
{
    int size = list.size();
    sort(list.begin() , list.end());
    std::cout << "Smallest is " << list[0];
}

void display_largest(std::vector<int> list)
{
    int size = list.size();
    sort(list.begin() , list.end());
    std::cout << "Largest is " << list[size];
}

void display_mean(std::vector<int> list)
{
    int size = list.size();
    sort(list.begin() , list.end());
    std::cout << "Mean is " << list[size/2];
}

void add_number(std::vector<int> *list , int number)
{
    (*list).push_back(number);
}

void print_number(std::vector<int> list)
{
    int i;
    std::cout << "[";
    for (i = 0 ; i < list.size() ; i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout<< "]" << std::endl;
}

int main()
{
    char choice;
    int number;
    std::vector<int> list;
    std::vector<int> *list_ptr{nullptr};
    print_menu();
    std::cin >> choice;

    list_ptr = &list;

    while (choice != 'Q')
    {
        switch (choice)
        {
        case 'P':
            print_number(list);
            break;
        case 'A':
            std::cout << "Enter the number to add: ";
            std::cin >> number;
            add_number(list_ptr , number);
            break;
        case 'M':
            display_mean(list);
            break;
        case 'S':
            display_smallest(list);
            break;
        case 'L':
            display_largest(list);
            break;
        case 'Q':
            std::cout << "Bye Bye" << std::endl;
            return 0;
        default:
            std::cout << "Invalid Option" << std::endl;
            break;
        }
        print_menu();
        std::cin >> choice;
    }
    return 0;
}