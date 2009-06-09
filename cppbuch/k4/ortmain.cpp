/* cppbuch/k4/ortmain.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"../include/ort.h"
/* alternativ ist {\tt \#include<ort.h>} möglich, wenn der
Compiler mit der Option -I$HOME/cppbuch/include
aufgerufen wird. (Unix) */

using namespace std;

// Funktion zum Verschieben des Orts um dx und dy
Ort ortsverschiebung(Ort derOrt, int dx, int dy) {
    derOrt.aendern(derOrt.getX() + dx, derOrt.getY() + dy);
    return derOrt;          // Rückgabe des neuen Orts
}

int main() {
   Ort einOrt(10, 300);
   Ort verschobenerOrt = ortsverschiebung(einOrt, 10, -90);
   cout << " alter Ort: ";
   anzeigen(einOrt);
   cout << "\n neuer Ort: ";
   anzeigen(verschobenerOrt);

   cout << "\n mit Typwandlungskonstruktor:\n";
   Ort nochEinOrt(string("21 99"));  // mögliches Format
   anzeigen(nochEinOrt);
   cout << endl;
   Ort einWeitererOrt("(55, 8)");    // weiteres mögliches Format
   anzeigen(einWeitererOrt);

   cout << "\n Typumwandlung eines Parameters:\n";
   string wo("20,400");
   verschobenerOrt = ortsverschiebung(Ort(wo), 10, -90);
   cout << "\n verschobener Ort: ";
   anzeigen(verschobenerOrt);

   Ort o1(0, 0);
//   o1 = wo;              // jetzt ein Fehler!
   o1 = Ort(wo);         // erlaubte explizite Typumwandlung
}
