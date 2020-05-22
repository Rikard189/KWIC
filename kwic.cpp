
#include <iostream>
#include <vector>
#include "Kwic1.h"
#include "InputFile.h"
#include "Output.h"
using namespace std;

int main() {

  Kwic kwic;
  InputFile inputter;
  Output outputter;

  // lee input file y separa lineas
  vector<string> raw_sentences = inputter.get_lines("KWIC2_input1.txt");


  // corre el algoritmo kwic
  vector<string> sorted_sentences = kwic.kwic(raw_sentences);
  outputter.output_txt(sorted_sentences, "output1.txt");

  vector<string> final_sentences = kwic.del(sorted_sentences, "salida");

  // output resultados
  outputter.print_vector(final_sentences);
  outputter.output_txt(final_sentences, "output2.txt");
}
