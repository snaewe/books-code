/* cppbuch/k4/delegierenderKonstruktor/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Falls der Compiler delegierende Konstruktoren unterstützt,
// die. Kommentarzeichen // in der nächsten Zeile entfernen,
//#define DELEGIERENDERKONSTRUKTOR

#ifndef DELEGIERENDERKONSTRUKTOR
#include"klasse1.h"
#else
#include"klasse2.h"
#endif
using namespace std;

int main() {             // Attributwerte
   Klasse k1(9, 100);    //     9    100
   Klasse k2(80, 99);    //    80     99
   Klasse k3;            //     1     42
}
