#ifndef BASC_H
#define BASC_H

#include <vector>
#include <string>

class Basc{
private:
  std::vector<int> nums;
  std::string bits;
  int b;

public:
  Basc(int b_init);
  void set_nums(std::vector<int> given_nums);
  void set_bits(std::string given_bits);
  void show_nums();
  void show_bits();
};

#endif // BASC_H
