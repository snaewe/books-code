/* cppbuch/k5/elfunptr.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"ort.h"
using namespace std;

int main() {
    // Zeiger auf Elementfunktionen

    Ort einOrt(100,200);

    int (Ort::*fp)()const = &Ort::getX;      // Zeiger auf Ort::getX() richten

    cout << (einOrt.*fp)() << endl;  // dasselbe wie einOrt.getX()
    fp = &Ort::getY;                    // Funktionszeiger umschalten

    cout << (einOrt.*fp)() << endl;  // jetzt dasselbe wie einOrt.getY()

    Ort * derZeiger = new Ort(300,400);
    cout << (derZeiger->*fp)() << endl;  // dasselbe wie derZeiger->getY()

    void (Ort::*fpAendern)(int,int) = &Ort::aendern;
    (derZeiger->*fpAendern)(500,600);    // d.h. derZeiger->aendern(500,600)
    anzeigen(*derZeiger);              // geänderter Ort
    delete derZeiger;
}
