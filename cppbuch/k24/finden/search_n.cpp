/* cppbuch/k24/finden/search_n.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<iostream>
#include<showSequence.h>
using namespace std;

int main() {
   vector<int> folge(12);
   for(size_t i = 0; i < folge.size(); ++i) {
      folge[i] = i;        // 0 1 2 3 4 5 6 7 8 9 10 11
   }
   folge[6] = folge[5] = folge[4]; // aufeinanderfolgende gleiche Werte
   cout << "Folge = ";
   showSequence(folge);

   int wert = 4; 
   int wieoft = 3;
   vector<int>::const_iterator position = search_n(folge.begin(), folge.end(),
                                                   wieoft, wert);
   if(position != folge.end()) {
      cout << wert << " wurde " << wieoft << "-mal nacheinander ab Position "
           << (position - folge.begin()) << " gefunden." << endl;
   }
   else {
      cout << wert << " wurde nicht " << wieoft 
           << "-mal nacheinander gefunden." << endl;
   }
   position = search_n(folge.begin(), folge.end(),
                       wieoft, wert, greater<int>());
   if(position != folge.end()) {
      cout << "Ab Position " << (position - folge.begin()) 
           << " wurden " << wieoft << "-mal nacheinander Werte größer als "
           << wert << " gefunden." << endl;
   }
   else {
      cout << wieoft << "-mal nacheinander Werte größer als "
           << wert << " sind nicht vorhanden." << endl;
   }
}
