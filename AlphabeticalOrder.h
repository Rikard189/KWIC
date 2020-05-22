#ifndef AlphabeticalOrder_h
#define AlphabeticalOrder_h

#include <vector>
#include <algorithm>
using namespace std;

class AlphabeticalOrder {
public:
  vector<string> sort_sentences(vector<string> sentences);
};

vector<string> AlphabeticalOrder::sort_sentences(vector<string> sentences){
  sort(sentences.begin(), sentences.end(), [](string s1, string s2) {
    return (asc ? s1 < s2 : s1 > s2);
  });
  return sentences;
}

#endif
