#ifndef Kwic1_h
#define Kwic1_h

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

  // pide stop words por consola
  vector<string> stop_words;
  string user_ans;


  cout << "Quieres stop words? (y/n)" << endl;
  cin >> user_ans;
  if (user_ans == "y") {
    bool quiere_mas = true;
    while (quiere_mas) {
      string stop_word;
      cout << "Dame una stop word." << endl;
      cin >> stop_word;
      stop_words.push_back(stop_word);
      cout << "Se le ofrece otra stop word? (y/n)" << endl;
      cin >> user_ans;
      if (user_ans != "y") quiere_mas = false;
    }
  }

  bool ascending = false;
  cout << "Quieres ascendente o descendente? (a/d)" << endl;
  cin >> user_ans;
  if (user_ans == "a") ascending = true;

  for (string sentence : sentences) {

    // formatea oracion sin mayuscula ni punto
    string formatted_sentence = formatter.format_string(sentence);

    // circular shift
    vector<string> shift_sentences = shifter.circ_shift(formatted_sentence);

    // agrega oraciones a resultados
    for (auto s : shift_sentences) result_sentences.push_back(s);
  }

  // sortea resultados alfabeticamente -> KWIC
  vector<string> sorted_sentences = alphabetizer.sort_sentences(result_sentences, ascending);

  return sorted_sentences;
}

#endif
