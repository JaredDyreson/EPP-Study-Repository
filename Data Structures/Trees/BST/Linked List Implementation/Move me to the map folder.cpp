#include <map>
#include <iostream>
#include <string>

// how the fuck do i work
int main(){
  std::string s = "abacadaeafagg";
  std::map<char, int> mp;
  mp['a'] = 0;
  mp['b'] = 0;
  mp['c'] = 0;
  mp['d'] = 0;
  mp['e'] = 0;
  mp['f'] = 0;
  mp['g'] = 0;
  for(auto c : s){
    mp[s[c]].second++;
    }
  }
  return 0;
}
