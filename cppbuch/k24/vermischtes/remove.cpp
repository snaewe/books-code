/* cppbuch/k24/vermischtes/remove.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<cstring>
#include<numeric>
#include<showSequence.h>
#if  __GNUC__*10+__GNUC_MINOR__ < 44 
#include<ersatziota.h>
#endif

// Umlaute werden nicht berücksichtigt
bool istVokal(char c) {
   return std::strchr("aeiouyAEIOUY", c) != 0;
}
using namespace std;

int main() {
    vector<char> v(26);
    // Alphabet mit Kleinbuchstaben erzeugen
    iota(v.begin(), v.end(), 'a');
    showSequence(v, "\n","");
    cout << "remove 't': ";
    vector<char>::iterator last = remove(v.begin(), v.end(), 't');
    // last = neues Ende nach der Verschiebung
    // v.end() bleibt unverändert!
    // Die Sequenz wird hier nicht mit showSequence() angezeigt,
    // weil nur die von begin() bis Iterator last signifikant sind
    ostream_iterator<char> ausgabe(cout, "");
    copy(v.begin(), last, ausgabe);  // abcdefghijklmnopqrsuvwxyz   (t fehlt)
    cout << endl;
    last = remove_if(v.begin(), last, istVokal);
    cout << "nur noch Konsonanten übrig: ";
    copy(v.begin(), last, ausgabe);   // bcdfghjklmnpqrsvwxyz
    cout << endl;
    cout << "Vollständige Sequenz bis end() einschließlich "
            " bedeutungsloser Elemente am Ende: ";
    showSequence(v, "\n","");
}
