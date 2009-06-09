/* cppbuch/k8/logik/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<cstdlib>
// Abschalten der Zusicherungen mit NDEBUG
#define NDEBUG
#include"assertex.h"

// Exception-Klasse ohne Konstruktor-Argument
class GleichNull {
   public:
      const char* what() const {
           return "Fehler GleichNull entdeckt";
      }
};

// Exception-Klasse mit Konstruktor-Argument
class UngleichEins {
   public:
      UngleichEins(int i) : zahl(i) {}
      const char* what() const {
          return  "Fehler UngleichEins entdeckt";
      }
      int wieviel() const { return zahl;}
    private:
      int zahl;
};

using namespace std;

int main() {
     int i;

     cout << "0            : GleichNull-Fehler\n"
          << "1            : normales Ende\n"
          << "!= 1         : UngleichEins-Fehler\n i = ?";
     cin  >>  i;

     try {
          Assert(i, GleichNull());
          Assert(i == 1, UngleichEins(i));
     }

     catch(const GleichNull& fehlerObjekt) {
        cerr << fehlerObjekt.what() << endl
             << "keine weitere Fehlerbehandlung\n";
     }

     catch(const UngleichEins& fehlerObjekt) {
        cerr << fehlerObjekt.what()     << endl
             << fehlerObjekt.wieviel()  << '!'
             << "  Abbruch"             << endl;
        exit(1);                  // Programmabbruch
     }

     cout << "normales Programmende mit i =" << i << endl;
}
