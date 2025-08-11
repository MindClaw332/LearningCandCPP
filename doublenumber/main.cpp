#include <vector>
#include <iostream>
std::vector<int> countBy(int x,int n){
  std::vector<int> ret;
  int mult = 0;
  for(int i = 0; i <= n; i++){
    mult += x;
    ret.push_back(mult);
    std::cout << i << '\n';
  }
  return ret;
}

int main(){
    countBy(2,10);
    return 0;
}

