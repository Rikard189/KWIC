#ifndef CircularShift_h
#define CircularShift_h

#include <algorithm>

using namespace std;

class CircularShift {
public:
  vector<string> circ_shift(string s);
};

vector<string> CircularShift::circ_shift(string s){

  // FIXME : que jale el circular shift

  
  std::vector<std::string> result;
  std::istringstream iss(s);
  string sr = "";
  for(std::string s; iss >> s; ){
    sr = s + " " + sr;
  }

  result.push_back(sr);
  return result;
}

#endif
