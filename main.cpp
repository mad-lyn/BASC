#include "iostream"
#include "basc.h"

using namespace std;

int main(int argc, char *argv[]){
  if(argc != 4){
    cout << "WRoNG arguments \n";
    cout << "usage: ./BASC (c/d) <nums/bits> <b> \n";
    return 0;
  }

  Basc Test(5);
  vector<int> v;
  v.push_back(13);

  switch ( (int) argv[1][0]) {
    case (int) 'c':
      cout << "Im coding \n";
      Test.set_nums(v);
      Test.show_nums();
      break;

    case (int) 'd':
        cout << "Im decoding \n";
        Test.set_bits("0110");
        Test.show_bits();
        break;

    default:
      cout << argv[1] << " not supported! \n";
      break;
  }
  
  return 0;
}
