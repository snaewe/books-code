/* cppbuch/k24/finden/find_end.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<vector>
#include<iostream>
#include<showSequence.h>
using namespace std;

int main() {
   vector<int> folge;
   vector<int> teilfolge1(3);
   vector<int> teilfolge2(2);

   // Folge und Teilfolgen initialisieren
   for(size_t i = 0; i < 8; ++i) {
      folge.push_back(2*i);    // gerade Zahlen
   }
   teilfolge1[0] = 4; teilfolge1[1] = 6;  teilfolge1[2] = 8;
   teilfolge2[0] = 2; teilfolge2[1] = 1;
   // Teilfolge 1 an Folge anhängen
   folge.insert(folge.end(), teilfolge1.begin(),teilfolge1.end());
   cout << "Folge  ";
   showSequence(folge);
   // Suche nach Teilfolge 1
   cout << "Teilfolge 1  (";
   showSequence(teilfolge1, ") ");
   vector<int>::const_iterator iter
      = find_end(folge.begin(), folge.end(), teilfolge1.begin(), teilfolge1.end());
   if(iter != folge.end()) {
      cout << "ist Teil der Folge. Das letzte Vorkommen beginnt an Position "
           << (iter - folge.begin()) << "." << endl;
   }
   else { 
      cout << "ist nicht Teil der Folge." << endl;
   }
   // Suche nach Teilfolge 2
   cout << "Teilfolge 2  (";
   showSequence(teilfolge2, ") ");
   iter = find_end(folge.begin(), folge.end(), teilfolge2.begin(), teilfolge2.end());
   if(iter != folge.end()) {
      cout << "ist Teil der Folge. Das letzte Vorkommen beginnt an Position "
           << (iter - folge.begin()) << "." << endl;
   }
   else { 
      cout << "ist nicht Teil der Folge." << endl;
   }
}
