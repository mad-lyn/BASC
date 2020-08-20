#include "basc.h"
#include "iostream"

#include <string>
#include <vector>
#include <math.h>
#include <bitset>

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

void Basc::encode(){
  for(int i = 0; i < nums.size(); i++){

    std::cout << "coding " << nums[i] << " now\n";

    int new_b;
    std::bitset<8> coded_num(nums[i]);
    std::string coded_string;

    if(nums[i] != 0){
      new_b = floor((double)log2(nums[i])) + 1;
    }else{
      new_b = 0;
    }

    if(new_b > b){
      bits += std::string(new_b-b, '1');
      bits += "0";
      coded_string = coded_num.to_string().substr(9-(new_b));
      bits += coded_string;
      std::cout << "coded to -> " << coded_string << '\n';
    }else{
      bits += "0";
      coded_string = coded_num.to_string().substr(8-b);
      bits += coded_string;
      std::cout << "coded to -> " << coded_string << '\n';
    }

    b = new_b;
  }
}
