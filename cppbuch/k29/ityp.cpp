/* cppbuch/k29/ityp.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<string>
#include<fstream>
#include<vector>
#include<iterator>
#include<iostream>

using namespace std;

// Funktions-Template zur Ermittlung des Typs (iterator-tag) des Iterators
template<class Iterator>
typename iterator_traits<Iterator>::iterator_category
getIteratortyp(const Iterator&) {
   typename iterator_traits<Iterator>::iterator_category typeobject;
   return typeobject;
}

// überladene Funktionen
void welcherIterator(const input_iterator_tag&) {
    cout << "Input-Iterator!" << endl;
}

void welcherIterator(const output_iterator_tag&) {
    cout << "Output-Iterator!" << endl;
}

void welcherIterator(const forward_iterator_tag&) {
    cout << "Forward-Iterator!" << endl;
}

void welcherIterator(const random_access_iterator_tag&) {
    cout << "Random-Access-Iterator!" << endl;
}


// Anwendung
int main( ) {
    // Bei Grunddatentypen *muss* das iterator_traits-Template
   // benutzt werden
    int *ip;                      // Random-Access-Iterator
    // Anzeige des Iteratortyps
    welcherIterator(getIteratortyp(ip));
    welcherIterator(iterator_traits<int*>::iterator_category());

    // Definition eines Datei-Objekts zum Lesen
    // (eine tatsächliche Datei ist nicht erforderlich, es 
    // geht nur um den Typ)
    ifstream Source;
    // Ein istream_iterator ist ein Input-Iterator
    istream_iterator<string> IPos(Source);
    // Anzeige des Iteratortyps
    welcherIterator(getIteratortyp(IPos));  // oder:
    welcherIterator(iterator_traits<istream_iterator<string> >
            ::iterator_category());

    // Definition eines Datei-Objekts zum Schreiben
    ofstream Destination;
    // Ein ostream_iterator ist ein Output-Iterator
    ostream_iterator<string> OPos(Destination);
    // Anzeige des Iteratortyps
    welcherIterator(getIteratortyp(OPos));  // oder:
    welcherIterator(iterator_traits<ostream_iterator<string> >
            ::iterator_category());

    vector<int> v(10);
    // Anzeige des Iteratortyps
    welcherIterator(getIteratortyp(v.begin()));  
                   // oder ein anderer Iterator als {\tt begin()}
    welcherIterator(iterator_traits<vector<int>::iterator>
            ::iterator_category());
}
