#ifndef Output_h
#define Output_h

#include <vector>
using namespace std;

class Output {
public:
  void print_vector(vector<string> vec);
};

void Output::print_vector(vector<string> vec){
  for (auto s : vec) cout << s << endl;
}

#endif
