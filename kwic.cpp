
#include<iostream>
#include<vector>
#include "Format.h"
#include "CircularShift.h"
#include "AlphabeticalOrder.h"
#include "Output.h"
using namespace std;

int main() {

  Format formatter;
  CircularShift shifter;
  AlphabeticalOrder alphabetizer;
  Output outputter;

  vector<string> result_sentences;

  // FIXME : aqui raw_sentences debe ser el resultado del input file
  vector<string> raw_sentences = {"Clouds are white.", "Pittsburgh is beautiful."};

  for (auto sentence : raw_sentences) {

    // formateador -> oracion sin mayuscula ni punto
    string formatted_sentence = formatter.format_string(sentence);

    // circular shift
    vector<string> shift_sentences = shifter.circ_shift(formatted_sentence);

    // agrega oraciones a resultados
    for (auto s : shift_sentences) result_sentences.push_back(s);
  }

  // sortea resultados alfabeticamente -> KWIC
  vector<string> sorted_sentences = alphabetizer.sort_sentences(result_sentences);
  outputter.print_vector(sorted_sentences);

  cout << "pasa la pipa" << endl;
}
