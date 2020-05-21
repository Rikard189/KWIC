
#include<iostream>
#include<vector>
using namespace std;

int main() {

  vector<string> result;

  // llamada a separador lineas en lector de archivo -> vector de lineas
  vector<string> raw_sentences = {"Clouds are white.", "Pittsburgh is beautiful."};

  for (auto sentence : raw_sentences) {

    // llamada a en formateador -> oracion sin mayuscula ni punto

    // llamada a generacion de circular shift -> vector de oraciones shifteadas
    vector<string> shift_sentences = {"clouds are white", "are white clouds", "white clouds are"};

    // agrega oraciones a vector principal
    for (auto s : shift_sentences) result.push_back(s);
  }

  // sortear vector principal alfabeticamente -> KWIC

  // llamada a output

  cout << "pasa la pipa" << endl;
}
