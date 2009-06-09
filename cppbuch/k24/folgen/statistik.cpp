/* cppbuch/k24/folgen/statistik.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<vector>
#include<cmath>
#include<numeric>
#include<iostream>
#include<Random.h>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include<ersatziota.h>
#endif

// Funktor zur Berechnung des Quadrats der Differenz zu einem Wert
template<class T>
class Abweichungsquadrat {
public:
   Abweichungsquadrat(T m) 
      : mittel(m) { 
   }
   T operator()(const T& acc, const T& iterWert) {
      const T d = iterWert - mittel;
      return acc + d*d;
   }
private:
   T mittel;
};

using namespace std;

int main() {
   vector<double> v(6);
   iota(v.begin(), v.end(), 1);      // Vektor füllen
   double summe = accumulate(v.begin(), v.end(), 0.0);
   cout << "Summe             : " << summe << endl;
   double mittelwert = summe/v.size();
   cout << "Mittelwert        : " << mittelwert << endl;
   Abweichungsquadrat<double> aq(mittelwert);
   double varianz = accumulate(v.begin(), v.end(), 0.0, aq)/v.size();
   cout << "Varianz           : " << varianz << endl;
   cout << "Standardabweichung: " << sqrt(varianz) << endl;
}
