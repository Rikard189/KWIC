#ifndef Output_h
#define Output_h

#include <vector>
using namespace std;

class Output {
public:
  template <class T>
  void print_vector(vector<T> vec);
};

template <class T>
void Output::print_vector(vector<T> vec){
  for (auto elem : vec) cout << elem << endl;
}

#endif
