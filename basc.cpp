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
    std::cout << x << ' ';
  }
  std::cout << '\n';
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

void Basc::decode(){
  int i = 0;
  std::string encoded_bits = "";
  int decoded_num;

  while(i < bits.length()){
    if(bits.at(i) == '0'){
      i++;
      for(int j = 0; j < b; j++){
        encoded_bits += bits.at(i);
        i++;
      }

      int offset = encoded_bits.find("1");

      if(offset == -1){
        b = 0;
      }else{
        b -= offset;
      }

    }else{
      while(bits.at(i) != '0'){
        i++;
        b++;
      }
      i++;
      encoded_bits += "1";
      for(int j = 0; j < b-1; j++){
        encoded_bits += bits.at(i);
        i++;
      }
    }

    std::cout << "encoded_bits: " << encoded_bits << '\n';

    if(encoded_bits.length() == 0){
      decoded_num = 0;
    }else{
      decoded_num = stoi(encoded_bits,0,2);
    }

    encoded_bits.clear();
    std::cout << "Decoded " << decoded_num << '\n';
    nums.push_back(decoded_num);
  }
}
