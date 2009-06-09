/* cppbuch/k6/numobj/nummain.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// main.cpp: Demonstration von nummerierten Objekten
#include "numobj.h"
#include<iostream>
using namespace std;

int main() {
    // Testmodus für alle Objekte der Klasse einschalten
    NummeriertesObjekt::testmodus = true;

    NummeriertesObjekt dasNumObjekt_X;       // ... wird erzeugt
    cout << "Die Seriennummer von dasNumObjekt_X ist: "
         << dasNumObjekt_X.seriennummer() << endl;

    // Anfang eines neuen Blocks
    {    NummeriertesObjekt dasNumObjekt_Y;  // ... wird erzeugt

         cout << NummeriertesObjekt::anzahl()
              << " Objekte aktiv" << endl;

         // *p wird dynamisch erzeugt:
         NummeriertesObjekt *p = new NummeriertesObjekt;

         cout << NummeriertesObjekt::anzahl()
              << " Objekte aktiv" << endl;
         delete p;                 // *p wird gelöscht

         cout << NummeriertesObjekt::anzahl()
              << " Objekte aktiv" << endl;

         // cout << "Fehler: ein  delete zuviel:" << endl;
         //       delete p; 
    }              // Blockende: {\tt dasNumObjekt\_Y} wird gelöscht

    cout << " Kopierkonstruktor: " << endl;
    NummeriertesObjekt dasNumObjekt_X1 = dasNumObjekt_X;

    cout << "Die Seriennummer von dasNumObjekt_X ist: "
         << dasNumObjekt_X.seriennummer() << endl;

    cout << "Die Seriennummer von dasNumObjekt_X1 ist: "
         << dasNumObjekt_X1.seriennummer() << endl;

    // Zuweisung wird wegen Konstanz der serienNr vom Compiler verboten
//     dasNumObjekt_X1 = dasNumObjekt_X;  // Fehler

}               // {\tt dasNumObjekt\_X} wird gelöscht
