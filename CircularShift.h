#ifndef CircularShift_h
#define CircularShift_h

#include <algorithm>

using namespace std;

class CircularShift {
public:
  vector<string> circ_shift(string s);
  vector<string> stop_circ_shift(string s, set<string> stop_words);
};

vector<string> CircularShift::circ_shift(string s){

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
}

vector<string> CircularShift::stop_circ_shift(string s, set<string> stop_words){

  vector<string> shift_result;
  vector<string> words;

  string word = "";
   for (auto x : s) {
       if (x == ' ') {
         if (!stop_words.count(word)) {
           words.push_back(word);
         }
         word = "";
       }
       else {
         word = word + x;
       }
   }
   if (!stop_words.count(word)) {
     words.push_back(word);
   }

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
}

#endif
