#include <iostream>
#include <vector>
#include <algorithm>

void displayOption()
{
  std::cout << "A - Add an element into the list\n";
  std::cout << "M - Mean/Aveage of the elements in the list\n";
  std::cout << "S - Display Smallest Number in the List\n";
  std::cout << "L - Display Largest Number in the List\n";
  std::cout << "P - Print the current List\n";
  std::cout << "Q - Quit\n";
}

void addElement(std::vector<int> &vec, int newNumber)
{
  vec.push_back(newNumber);
}

float calculateMean(std::vector<int> &vec)
{
  float mean{0};

  if (vec.size() == 0)
  {
    return 0.0;
  }

  for (auto vec_t : vec)
  {
    mean += vec_t;
  }
  mean /= vec.size();

  return mean;
}

int displaySmallest(std::vector<int> vec)
{
  if (vec.size() == 0){
    return 0;
  }
  std::sort(vec.begin() , vec.end());
  return vec.at(0);
}

int displayLargest(std::vector<int> vec)
{
  if (vec.size() == 0){
    return 0;
  }
  std::sort(vec.begin() , vec.end());
  return vec.at(vec.size() -1);
}

void printVector(std::vector<int> &vec)
{
  if (vec.size() == 0){
    std::cout << "Empty List\n";
  }
  else {
    for (auto vec_t : vec){
      std::cout << vec_t << " ";
    }
    std::cout << "\n";
  }
}


int main()
{
  char choice;
  bool quit = false;
  std::vector<int> vec;
  displayOption();
  std::cin >> choice;

  while (!quit)
  {
    switch (choice)
    {
    case 'A':
    case 'a':
      int newNumber;
      std::cout << "Enter the number you wanna enter:\n";
      std::cin >> newNumber;
      addElement(vec, newNumber);
      break;

    case 'M':
    case 'm':
    {
      float result = calculateMean(vec);
      printf("%.2f\n" , result);
      break;

    }
    case 'S':
    case 's':
    {
      int answer = displaySmallest(vec);
      if (answer == 0){
        std::cout << "The vector is empty\n";
      }
      else {
        std::cout << answer;
      }
      break;

    }
      

    case 'L':
    case 'l':
    {
      int answer1;
      answer1 = displayLargest(vec);
      if (answer1 == 0){
        std::cout << "The vector is empty\n";
      }
      else {
        std::cout << answer1;
      }
      break;

    }
      
    
    case 'P':
    case 'p':
      std::cout << "The current list is: \n";
      printVector(vec);
      break;

    case 'Q':
    case 'q':
      quit = true;
      break;

    default:
      std::cout << "Invalid Choice entered, PLease Try again!\n";
    }

    if (!quit)
    {
      displayOption();
      std::cin >> choice;
    }
  }
}