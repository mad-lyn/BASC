#include "basc.h"
#include "iostream"

#include <string>
#include <vector>

Basc::Basc(int b_init){
  b = b_init;
}

void Basc::set_nums(std::vector<int> given_nums){
  nums = given_nums;
}

void Basc::set_bits(std::string given_bits){
  bits = given_bits;
}

void Basc::show_nums(){
  for(int x : nums){
    std::cout << x << '\n';
  }
}

void Basc::show_bits(){
  std::cout << bits << '\n';
}
