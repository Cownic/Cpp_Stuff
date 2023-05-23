#include <iostream>
#include <vector>

void printVector(std::vector<char> vowels);

int main()
{
  // initialising array
  // Element_Type array_name [constant number of elements];

  // initializing vectors

  // std::vector<char> vowels{'a', 'e', 'i', 'o', 'u'};

  // printVector(vowels);

  // // getting a vector element at a particular position
  // std::cout << vowels.at(1) << std::endl;
  // // changing the value at a particular postion using .at
  // vowels.at(1) = 'b';
  // printVector(vowels);

  // // adding new values to back of the vectors
  // vowels.push_back('Z');
  // printVector(vowels);

  std::vector<int> vector1;
  std::vector<int> vector2;

  vector1.push_back(10);
  vector1.push_back(20);

  vector2.push_back(100);
  vector2.push_back(200);

  std::vector<std::vector<int>> vector_2d;

  vector_2d.push_back(vector1);
  vector_2d.push_back(vector2);

  std::cout << vector_2d.at(0).at(0);


  return 0;
}

void printVector(std::vector<char> vowels)
{
  for (int i = 0; i < vowels.size(); i++)
  {
    std::cout << vowels[i] << " ";
  }
  std::cout << "\n";
}