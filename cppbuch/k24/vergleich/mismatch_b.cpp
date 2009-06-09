/* cppbuch/k24/vergleich/mismatch_b.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<cmath>  // fabs
#include<showSequence.h>
#include<Random.h>
using namespace std;

class  VergleichMitToleranz {
public:
   VergleichMitToleranz(double e) 
      : eps(e) {
   }
   bool operator()(double x, double y) {
      return fabs(x-y) < eps;
   }
private:
   double eps;
};

int main() {
   vector<double> v1(8), v2(8);
   Random zufall;
    for(size_t i = 0; i < v1.size(); ++i) {
       v1[i] = i + zufall(100)/10000.0;
       v2[i] = i + zufall(100)/10000.0;
    }
    showSequence(v1);                // Anzeige
    showSequence(v2);

    // Prüfung mit Iterator Paar 'wo'
    pair<vector<double>::iterator, vector<double>::iterator>
       wo = mismatch(v1.begin(), v1.end(), v2.begin(), 
                     VergleichMitToleranz(0.01));
    if(wo.first == v1.end()) {
       cout << "Inhalt der Container stimmt innerhalb der Toleranz überein." 
            << endl;
    }
    else {
      cout << "Der erste Unterschied (" << *wo.first << " != "
           << *wo.second           << ") wurde an Position "
           << (wo.first - v1.begin()) << " gefunden." << endl;
    }
}
