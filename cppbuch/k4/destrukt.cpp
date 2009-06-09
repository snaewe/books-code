/* cppbuch/k4/destrukt.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

class Beispiel {
    int zahl;
  public:
    Beispiel(int i = 0);                 // Konstruktor
    ~Beispiel();                       // Destruktor
};

Beispiel::Beispiel(int i) : zahl(i) {  // Konstruktor
    cout << "Objekt " << zahl
         << " wird erzeugt.\n";
}

Beispiel::~Beispiel()                  // Destruktor
{    cout << "Objekt " << zahl
          << " wird zerstört.\n";
}

// globale Variable, durch Vorgabewert mit 0 initialisiert
Beispiel ein_globales_Beispiel;

int main() {
    cout << "main wird begonnen\n";
    Beispiel einBeispiel(1); {
         cout << "    neuer Block\n    ";
         Beispiel einBeispiel(2);
         cout << "    Block wird verlassen\n    ";
    }
    cout << "main wird verlassen\n";
}
