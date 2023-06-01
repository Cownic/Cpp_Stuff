#include <iostream>
#include <string>
#include <cstring>

//Letter Pyramid

int main()
{
  std::string new_string {};

  std::cout << "Enter the string please: ";

  std::cin >> new_string;

  //will increase in each iteration
  int position {0};

  int length_of_string = new_string.size();

  for (auto new_string_a : new_string){
    //To generate the empty space for my pyramid
    int num_space = length_of_string - position;
    while (num_space){
      std::cout << " ";
      --num_space;
    }
    

    //Display the order up to the current character
    for (int i = 0 ; i < position ; i++){
      std::cout << new_string.at(i);
    }

    std::cout << new_string.at(position);

    for (int j = position-1 ; j>= 0 ; j--){
      std::cout << new_string.at(j);
    }
    std::cout << "\n";
    position++;
  }
  return 0;
}