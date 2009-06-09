/* cppbuch/loesungen/k4/6/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
/** @file
 * main()-Datei fuer ein Taschenrechner-Programm.
 * Beispiel fuer die Nutzung der Taschenrechner-Klasse.
 * @author    U. Breymann
 * $Revision: 1.0 $
 * @date      2.4.2009
 */
#include"taschenrechner.h"
#include<iostream>

using namespace std;
/** main()-Funktion.
 * Parameter werden nicht benoetigt.
 * main() erwartet nach dem Start eine Eingabe, mit der
 * ein Taschenrechnerobjekt initialisiert wird. 
 */
int main() {
  while(true) {                  // Abbruch mit break
    cout << "\nBitte einen mathematischen Ausdruck eingeben, "
      "z.B. 4*(12+3)\n(Abbruch durch Eingabe einer Leerzeile) : ";
    string anfrage;
    getline(cin, anfrage);
    if(anfrage.length() > 0) {
       Taschenrechner tr(anfrage);
       cout << "Das Ergebnis der Anfrage '" << tr.getAnfrage()
            << "' ist " << tr.getErgebnis() << endl;
    }
    else break;
  }
}
