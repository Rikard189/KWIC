#ifndef Output_h
#define Output_h

#include <vector>
#include <fstream>

using namespace std;

class Output {
public:
  template <class T>
  void print_vector(vector<T> vec);
  void output_txt(vector<string> vec, string file);
};

template <class T>
void Output::print_vector(vector<T> vec){
  for (auto elem : vec) cout << elem << endl;
}

void Output::output_txt(vector<string> vec, string file){
  ofstream myfile;
  myfile.open (file);
  for (auto elem : vec) {
    myfile << elem << "\n";
  }
  myfile.close();
}

#endif
