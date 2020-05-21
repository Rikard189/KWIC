#ifndef Kwic_h
#define Kwic_h

#include <iostream>
#include <vector>
#include "InputFile.h"
#include "Format.h"
#include "CircularShift.h"
#include "AlphabeticalOrder.h"
#include "Output.h"
using namespace std;

class Kwic {
public:
  vector<string> kwic(vector<string> sentences);
};

vector<string> Kwic::kwic(vector<string> sentences){

  Format formatter;
  CircularShift shifter;
  AlphabeticalOrder alphabetizer;

  vector<string> result_sentences;

  for (string sentence : sentences) {

    // formatea oracion sin mayuscula ni punto
    string formatted_sentence = formatter.format_string(sentence);

    // circular shift
    vector<string> shift_sentences = shifter.circ_shift(formatted_sentence);

    // agrega oraciones a resultados
    for (auto s : shift_sentences) result_sentences.push_back(s);
  }

  // sortea resultados alfabeticamente -> KWIC
  vector<string> sorted_sentences = alphabetizer.sort_sentences(result_sentences);

  return sorted_sentences;
}

#endif
