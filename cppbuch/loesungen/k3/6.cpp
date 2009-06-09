/* cppbuch/loesungen/k3/6.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Aufgabe exp(x) vergleichen
#include<cmath>
#include<iostream>
using namespace std;

double ehoch(double x);

int main() {
   cout << "      x       ehoch(x)        exp(x)     Unterschied in %" << endl;
   for(int i = -40; i <= 40; i += 10) {
      double x = (double)i;
      double e1 = ehoch(x);
      double e2 = exp(x);
      cout.width(7);
      cout << x;
      cout.width(15);
      cout << e1;
      cout.width(15);
      cout << e2;
      cout.width(15);
      cout  << 100.0 *(1.0 - e1/e2) << endl;
   }
}

double ehoch(double x) {
  int vorzeichen = 1;
  if(x < 0.0) {
    x = - x;
    vorzeichen = -1;
  }
  double Summand = 1.0, Summe = 1.0, alteSumme;
  int i = 0;
  do {
    alteSumme = Summe;
    Summand *= x/++i;
    Summe += Summand;
  } while(Summe != alteSumme);
  if(vorzeichen == -1)
    Summe = 1.0/Summe;
  return Summe;
}
