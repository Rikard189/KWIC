#ifndef AlphabeticalOrder_h
#define AlphabeticalOrder_h

#include <vector>
#include <algorithm>
using namespace std;

class AlphabeticalOrder {
public:
  vector<string> sort_sentences(vector<string> sentences, bool asc);
};

vector<string> AlphabeticalOrder::sort_sentences(vector<string> sentences, bool asc){
  if (asc) {
    sort(sentences.begin(), sentences.end(), [](string s1, string s2) {
      return s1 < s2;
    });
  } else {
    sort(sentences.begin(), sentences.end(), [](string s1, string s2) {
      return s1 > s2;
    });
  }
  return sentences;
}

#endif
