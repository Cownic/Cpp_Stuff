#include <iostream>


int main()
{
  enum Direction{
    left , right , up , down
  };

  Direction heading (left);

  switch (heading)
  {
  case left:
    std::cout << "Going Left\n";
    break;
  case right:
    std::cout << "Going Right\n";

  default:
    std::cout << "Invalid\n";
    break;
  }
  return 0;
}
