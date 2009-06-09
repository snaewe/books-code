/* cppbuch/k29/reverse.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<vector>
#include<iostream>
#include<iterator>
using namespace std;

int main() {
  vector<int> v(10);
  for(size_t i = 0; i < v.size(); ++i) {
    v[i] = i;
  }
  reverse_iterator<vector<int>::iterator> revIter(v.rbegin());
  // Alternativ: vector<int>::reverse_iterator revIter(v.rbegin());

  // Zahlen verdoppelt umgekehrter Folge ausgeben
  while(revIter != v.rend()) {
    *revIter *= 2;              // Wert über den Iterator ändern
    cout << *revIter++ << ' ';  // nur lesender Zugriff    
  }  
  cout << endl;
  /* Falls Werte NICHT geändert werden sollen, kann der von der Klasse 
     vector bereitgestellte Typ const_reverse_iterator verwendet werden.
     Eine eigene Klasse const_reverse_iterator gibt es nicht.
  */
  cout << "const_iterator:" << endl;
  vector<int>::const_reverse_iterator constRevIter(v.rbegin()), 
                                      constRevIterEnd(v.rend());
  while(constRevIter != constRevIterEnd) {
    cout << *constRevIter++ << ' ';     
  }
  cout << endl;
}
