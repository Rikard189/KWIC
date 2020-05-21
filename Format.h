#ifndef Format_h
#define Format_h

using namespace std;

class Format {
public:
  string format_string(string s);
};

string Format::format_string(string s){
  for (int i=0; i<s.length(); i++) {
    s[i] = tolower(s[i]);
  }
  if (s[s.length()-1] == '.') {
    s.erase(s.length()-1);
  }
  return s;
}

#endif
