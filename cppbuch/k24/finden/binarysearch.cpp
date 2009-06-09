/* cppbuch/k24/finden/binarysearch.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<algorithm>
#include<list>
#include<string>
#include<showSequence.h>
using namespace std;

int main() {
    list<string> staedte;
    staedte.push_front("Bremen");
    staedte.push_front("Paris");
    staedte.push_front("Mailand");
    staedte.push_front("Hamburg");
    staedte.sort();                   // Wichtige Vorbedingung!
    showSequence(staedte);

    string stadt;
    cout << "Welche Stadt eintragen/suchen? ";
    cin >> stadt;

    if(binary_search(staedte.begin(), staedte.end(), stadt)) {
       cout << stadt << " existiert.\n";
    }
    else {
       cout << stadt << " existiert noch nicht.\n";
    }
    // an der richtigen Stelle einfügen
    cout << stadt << " wird eingefügt:\n";
    list<string>::iterator i =
        lower_bound(staedte.begin(), staedte.end(), stadt);
    staedte.insert(i, stadt);
    showSequence(staedte);

    // Bereich gleicher Werte
    pair<list<string>::const_iterator, 
              list<string>::const_iterator> 
     p = equal_range(staedte.begin(), staedte.end(), stadt);

    // Die zwei Iteratoren des Paars p begrenzen den Bereich, in dem stadt vorkommt.
    list<string>::difference_type n = distance(p.first, p.second);
    cout << stadt << " ist " << n << " mal in der Liste enthalten\n";
}
