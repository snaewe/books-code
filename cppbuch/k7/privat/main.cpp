/* cppbuch/k7/privat/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Beispiel zur Warteschlange mit string-Objekten
#include<string>
#include<iostream>
#include"warteschlange.t"
using namespace std;

int main() {
   Warteschlange<string> fifo;
   fifo.push( string("eins"));
   fifo.push( string("zwei"));
   fifo.push( string("drei"));

   while(!fifo.empty()) {
      cout << fifo.size() << " Element(e) vorhanden!\n";
      string buf = fifo.front();  // lesen
      fifo.pop();                 // löschen
      cout << "Element "  << buf << " entnommen\n";
   }
   cout << "Liste ist leer!" << endl;
}
