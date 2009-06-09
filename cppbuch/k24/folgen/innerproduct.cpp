/* cppbuch/k24/folgen/innerproduct.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<numeric>
#include<vector>
#include<cmath>
#include<iostream>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include<ersatziota.h>
#endif

// Funktor zur Berechnung des Quadrats einer Differenz
template<class T>
struct difference_square {
   T operator()(const T& x, const T& y) {
      const T d = x - y;
      return d*d;
   }
};

using namespace std;

int main() {
   const int DIMENSION = 4;
   vector<int> v(DIMENSION, 1);

   cout << "Länge des Vektors v = "
        << sqrt( (double)inner_product(v.begin(), v.end(),
                                       v.begin(), 0))
        << endl;

   // Um die Anwendung anderer mathematischer Operatoren zu zeigen,
   // wird im Folgenden die Entfernung zwischen zwei Punkten berechnet.

   // 2 Punkte  p1 und p2
   vector<double> p1(DIMENSION,1.0);    // Einheitsvektor
   vector<double> p2(DIMENSION);
   iota(p2.begin(), p2.end(), 1.0);     // beliebiger Vektor

   cout << "Entfernung zwischen p1 und p2 = "
        << sqrt( inner_product(p1.begin(), p1.end(),
                               p2.begin(), 0.0,
                               plus<double>(), 
                               difference_square<double>()))
        << endl;
}
