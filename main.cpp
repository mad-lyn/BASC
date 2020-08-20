#include "iostream"
#include "basc.h"

using namespace std;

//testcase
//15,6,2,3,0,0,0,0,4,5,1,7,8

int main(int argc, char *argv[]){
  if(argc != 4){
    cout << "WRoNG arguments \n";
    cout << "usage: ./BASC (c/d) <nums/bits> <b> \n";
    return 0;
  }

  Basc Test(5);

  vector<string> arguments(argv,argv + argc);
  string tmp = "";
  vector<int> res;


  switch ( (int) argv[1][0]) {
    case (int) 'c':
      cout << "Im coding \n";
      cout << arguments[2] << '\n';
      for(int i = 0; i < arguments[2].length(); i++){
        if(arguments[2].at(i) == ','){
          res.push_back(stoi(tmp));
          tmp.clear();
        }else{
          tmp += arguments[2].at(i);
        }
      }
      res.push_back(stoi(tmp));

      Test.set_nums(res);
      Test.show_nums();
      Test.encode();
      Test.show_bits();
      cout << "Encoding completed :) \n";
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
