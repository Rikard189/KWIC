
#include <iostream>
#include <vector>
#include "Kwic.h"
#include "InputFile.h"
#include "Output.h"
using namespace std;

int main() {

  Kwic kwic;
  InputFile inputter;
  Output outputter;

  // lee input file y separa lineas
  vector<string> raw_sentences = inputter.get_lines("input.txt");

  // corre el algoritmo kwic
  vector<string> sorted_sentences = kwic.kwic(raw_sentences);

  // output resultados
  outputter.print_vector(sorted_sentences);

}
