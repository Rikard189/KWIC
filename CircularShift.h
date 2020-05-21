#ifndef CircularShift_h
#define CircularShift_h

#include <algorithm>

using namespace std;

class CircularShift {
public:
  vector<string> circ_shift(string s);
};

vector<string> CircularShift::circ_shift(string s){

<<<<<<< HEAD
  vector<string> shift_result;
  vector<string> words;

  string word = "";
   for (auto x : s) {
       if (x == ' ') {
           words.push_back(word);
           word = "";
       }
       else {
           word = word + x;
       }
   }
   words.push_back(word);

   string cur = "";
   for (int i=0; i<words.size(); i++) {
     for (int j=0; j<words.size(); j++) {
       cur += words[(i+j)%words.size()] + " ";
     }
     cur.erase(cur.length()-1);
     shift_result.push_back(cur);
     cur = "";
   }
  return shift_result;
=======
  // FIXME : que jale el circular shift

  
  std::vector<std::string> result;
  std::istringstream iss(s);
  string sr = "";
  for(std::string s; iss >> s; ){
    sr = s + " " + sr;
  }

  result.push_back(sr);
  return result;
>>>>>>> e49fcf4519aa02f3d0b5d367186cf84ed0f600bc
}

#endif
