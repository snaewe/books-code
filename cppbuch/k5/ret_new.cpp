/* cppbuch/k5/ret_new.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

class Testobjekt {
    char Name;
    public:
    Testobjekt(char);
    Testobjekt(const Testobjekt& t);
    ~Testobjekt();
    void drucken() const;
};

Testobjekt::Testobjekt(char N) 
   : Name(N) {
    cout << Name << ".Konstruktor aufgerufen! "
         << Name << ".this = "
         << this << endl;     // Adresse ausgeben
}

Testobjekt::Testobjekt(const Testobjekt& t) 
   :  Name(t.Name) {
    cout << "Copy-Konstruktor aufgerufen! Argument: ";
    t.drucken();
    cout << "Copy-Konstruktor wird verlassen."
         << endl;
}

Testobjekt::~Testobjekt() {
    cout <<"Destruktor für "
         << Name << ".this="
         << this << " aufgerufen!" << endl;
}

void Testobjekt::drucken() const {
    cout << "drucken: "
         << Name << ".this= "
         << this << endl;
}

Testobjekt return_Testobjekt(char N) {   // Hier steckt der Fehler!
    cout << "return_Testobjekt() vor return!\n";
    Testobjekt* ptr = new Testobjekt(N);
    return *ptr;      // Rückgabe eines mit new erzeugten Objekts
}

int main() {
    Testobjekt A('A');
    Testobjekt& B = *new Testobjekt('B');
    Testobjekt C  = return_Testobjekt('C');

    cout << "nach Aufruf von return_Testobjekt()\n";
    C.drucken();
    delete &B;  // expliziter Destruktoraufruf für Referenz
}
