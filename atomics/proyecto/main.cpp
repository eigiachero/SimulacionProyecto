#include <iostream>
#include "numberGenerator.h"

using namespace std;

int main() {
  cout << "Start" << endl;
  list<double> exponencial = genExponentialDistribution(6.0,10);
  vector<double> arreglo_exponencial(exponencial.begin(), exponencial.end());

  for (int i=0; i<10; i++) {
    cout << arreglo_exponencial[i] << " ";
  }
  double first = exponencial.front();
  cout << endl << first;

  cout << endl << "Fin" << endl;

  return 0;
}