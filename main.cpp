#include "iostream"

using namespace std;

int main(int argc, char *argv[]){
  cout << "helo world" << endl;

  if(argc != 4){
    cout << "WRoNG arguments \n";
    cout << "usage: ./BASC (c/d) <nums/bits> <b> \n";
    return 0;
  }

  cout << "works" << endl;
  return 0;
}
