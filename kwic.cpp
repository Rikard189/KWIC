
#include <iostream>
#include <vector>
#include "InputFile.h"
#include "Format.h"
#include "CircularShift.h"
#include "AlphabeticalOrder.h"
#include "Output.h"
using namespace std;

int main() {

  InputFile inputter;
  Format formatter;
  CircularShift shifter;
  AlphabeticalOrder alphabetizer;
  Output outputter;

  vector<string> result_sentences;

  // lee input file y separa lineas
  vector<string> raw_sentences = inputter.get_lines("input.txt");

  for (auto sentence : raw_sentences) {

    // formatea oracion sin mayuscula ni punto
    string formatted_sentence = formatter.format_string(sentence);

    // circular shift
    vector<string> shift_sentences = shifter.circ_shift(formatted_sentence);

    // agrega oraciones a resultados
    for (auto s : shift_sentences) result_sentences.push_back(s);
  }

  // sortea resultados alfabeticamente -> KWIC
  vector<string> sorted_sentences = alphabetizer.sort_sentences(result_sentences);

  // output resultados
  outputter.print_vector(sorted_sentences);

  cout << "pasa la pipa" << endl;
}
