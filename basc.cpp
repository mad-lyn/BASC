#include "basc.h"
#include "iostream"

#include <string>
#include <vector>

Basc::Basc(){
  nums.push_back(15);
  bits = "We bits work";
  b = 5;
}

void Basc::do_something(){
  std::cout << bits << '\n';
  std::cout << nums[0] << '\n';
  std::cout << b << '\n';
}
