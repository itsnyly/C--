#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
#include <algorithm>
using namespace std;

std::vector<uint64_t> powers_of_two(int n)
{
  std::vector<uint64_t> powers(n);
  if (n > 0)
  {
    for (int i = 0; i < n; i++)
    {
      powers[i] = pow(2, i);
    }
  }
  else
  {
    powers[0] = 1;
  }
  return powers;
}

bool feast(std::string beast, std::string dish){
  cout << *beast.begin() << *dish.begin();
  cout << "end: " << beast.back();
  if((beast.begin() == dish.begin()) && (beast.end() == dish.end())) return true;
  else return false;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string> // Include the necessary header file for the 'cout' object

std::vector<int> divisible_by(std::vector<int> numbers, int divisor)
{
  std::vector<int> divisibles;
  std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(divisibles), [divisor](int num) { return num % divisor == 0; });
  return divisibles;
}

int main()
{
  std::vector<int> result = divisible_by({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1);
  for (int num : result)
  {
    std::cout << num << " "; // Convert the vector elements to strings before printing them
  }
  return 0;
}