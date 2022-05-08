#include <iostream>
#include <vector>
int main()
{
  //for loops
  for (int i = 0 ; i < 5 ; i++){
    std::cout << "Hello ";
  }

  //range-based for loops

  std::vector<double> temps {87.2, 77.1 , 80.0, 72.5};


  //neater than a normal for loop, added in c++
  for (auto temp: temps){
    std::cout << " " << temp;
  }
  return 0;
}