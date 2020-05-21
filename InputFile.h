#ifndef InputFile_h
#define InputFile_h

#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class InputFile {
public:
  vector<string> get_lines(string name);
};

vector<string> InputFile::get_lines(string name) {
  vector<string> lines;
  string line;
  ifstream my_file(name);
  if (my_file.is_open()) {
    while (getline(my_file, line)) {
      lines.push_back(line);
    }
    my_file.close();
  }
  return lines;
}

#endif
