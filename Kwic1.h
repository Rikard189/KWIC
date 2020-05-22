#ifndef Kwic1_h
#define Kwic1_h

#include <iostream>
#include <vector>
#include <set>
#include "InputFile.h"
#include "Format.h"
#include "CircularShift.h"
#include "AlphabeticalOrder.h"
#include "Output.h"
using namespace std;

class Kwic {
public:
  vector<string> kwic(vector<string> sentences);
private:
  set<string> stop_words;
  bool ascending;
  void add_stop_words();
  void add_stop_words_file();
  void asc_or_dec();
  vector<string> delete_input(vector<string> sentences);
  vector<string> delete_sentences(vector<string> sentences, vector<int> indexes);
  void print_sentences(vector<string> vec);
};

void Kwic::print_sentences(vector<string> vec) {
  int counter = 1;
  for (auto elem : vec) {
    cout << counter << "- " << elem << endl;
    counter ++;
  }
}

vector<string> Kwic::delete_sentences(vector<string> sentences, vector<int> indexes) {
  sort(indexes.begin(), indexes.end(), [](int x1, int x2) {
    return x1 > x2;
  });
  for (auto numero : indexes) {
    sentences.erase(sentences.begin()+numero-1);
  }
  return sentences;
}

void Kwic::asc_or_dec() {
  string user_ans;
  bool ascending = false;
  cout << "Quieres ascendente o descendente? (a/d)" << endl;
  cin >> user_ans;
  if (user_ans == "a") ascending = true;
}

void Kwic::add_stop_words() {
  // pide stop words por consola
  string user_ans;
  cout << "Quieres stop words? (y/n)" << endl;
  cin >> user_ans;
  if (user_ans == "y") {
    bool quiere_mas = true;
    while (quiere_mas) {
      string stop_word;
      cout << "Dame una stop word." << endl;
      cin >> stop_word;
      stop_words.insert(stop_word);
      cout << "Se le ofrece otra stop word? (y/n)" << endl;
      cin >> user_ans;
      if (user_ans != "y") quiere_mas = false;
    }
  }
}

vector<string> Kwic::delete_input(vector<string> sentences) {
  string user_ans;
  cout << "Lineas de input: " << endl;
  print_sentences(sentences);
  vector<int> indexes;
  cout << "Quieres eliminar lineas de entrada? (y/n)" << endl;
  cin >> user_ans;
  if (user_ans == "y") {
    bool quiere_borrar = true;
    int numero;
    while (quiere_borrar) {
      cout << "Dame el número de la linea que deseas borrar." << endl;
      cin >> numero;
      indexes.push_back(numero);
      cout << "Se le ofrece eliminar otra linea? (y/n)" << endl;
      cin >> user_ans;
      if (user_ans != "y") quiere_borrar = false;
    }
    vector<string> final_sentences = delete_sentences(sentences, indexes);
    return final_sentences;
  }
  return sentences;
}

void Kwic::add_stop_words_file() {
  string user_ans;
  cout << "Quieres stop words? (y/n)" << endl;
  cin >> user_ans;
  if (user_ans == "y") {
    InputFile inputter;
    string file_name;
    cout << "Nombre del archivo de input para stop words?" << endl;
    cin >> file_name;
    vector<string> sw_vec = inputter.get_lines(file_name);
    for (auto w : sw_vec) stop_words.insert(w);
  }
}

vector<string> Kwic::kwic(vector<string> sentences){

  Format formatter;
  CircularShift shifter;
  AlphabeticalOrder alphabetizer;


  vector<string> result_sentences;

  // agrega stop words desde consola
  // add_stop_words();

  // agrega stop words desde archivo
  add_stop_words_file();

  // pregunta si quiere asc o dec
  asc_or_dec();

  //lineas de entrada
  vector<string> input_sentences = delete_input(sentences);

  for (string sentence : input_sentences) {

    // formatea oracion sin mayuscula ni punto
    string formatted_sentence = formatter.format_string(sentence);

    // circular shift
    vector<string> shift_sentences = shifter.stop_circ_shift(formatted_sentence, stop_words);

    // agrega oraciones a resultados
    for (auto s : shift_sentences) result_sentences.push_back(s);
  }

  // sortea resultados alfabeticamente -> KWIC
  vector<string> sorted_sentences = alphabetizer.sort_sentences(result_sentences, ascending);

  return sorted_sentences;
}

#endif
