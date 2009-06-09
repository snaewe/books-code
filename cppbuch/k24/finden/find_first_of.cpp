/* cppbuch/k24/finden/find_first_of.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<iostream>
#include<showSequence.h>
using namespace std;

int main() {
   vector<int> folge(8);
   vector<int> menge(3);
   // Folge und Menge initialisieren
   for(size_t i = 0; i < folge.size(); ++i) {
      folge[i] = 2*i;    // gerade Zahlen
   }
   menge[0] = 1;
   menge[1] = 5;
   menge[2] = 7;
   // Zwei Tests:
   for(int testNummer = 0; testNummer < 2; ++testNummer) {
      if(testNummer == 1) {
         menge[1] = 6;
         cout << endl << "Menge modifiziert:" << endl;
      }
      cout << "Ist eines der Elemente der Menge (";
      showSequence(menge, "");
      cout << ") in der Folge" << endl;
      showSequence(folge, "");
      cout << " enthalten?" << endl;

      // Suche nach Element, das auch in der Menge enthalten ist
      vector<int>::const_iterator iter
         = find_first_of(folge.begin(), folge.end(), 
                         menge.begin(), menge.end());
      if(iter != folge.end()) {
         cout << "Ja. Element " << *iter
              << " ist in beiden Bereichen vorhanden. Sein erstes Vorkommen" 
            " in der Folge ist Position "
              << (iter - folge.begin()) << "." << endl;
      }
      else {
         cout << "Nein." << endl;
      }
   }
}
