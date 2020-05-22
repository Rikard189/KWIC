#ifndef Output_h
#define Output_h

#include <vector>
#include <fstream>

using namespace std;

class Output {
public:
  template <class T>
  void print_vector(vector<T> vec);
  void output_txt(vector<string> vec);
};

template <class T>
void Output::print_vector(vector<T> vec){
  for (auto elem : vec) cout << elem << endl;
}

void Output::output_txt(vector<string> vec){
  ofstream myfile;
  myfile.open ("output.txt");
  for (auto elem : vec) {
    myfile << elem << "\n";
  }
  myfile.close();
}

#endif
