#include <iostream>
#include <climits>

//import only what we need to use instead of the whole standard library
using std::cout;
using std::cin;
using std::endl;


int main()
{
  int cost {30};
  float tax {0.06};
  int numberOfRoom;
  int pricePerRoom = cost;

  cout << "Enter the number of rooms: "; 
  cin >> numberOfRoom;

  cout << "Number of Rooms: " << numberOfRoom << endl;
  cout << "Price per room: " << cost << endl;

  int totalCost;
  totalCost = cost * numberOfRoom;
  cout << "The total cost is " << totalCost << endl;
  float totalTax;
  totalTax = numberOfRoom * pricePerRoom * tax;
  cout << "The total tax is " << totalTax << endl;
  cout << "The total estimate is " << totalCost + totalTax << endl;

  return 0;

}