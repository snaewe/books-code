/* cppbuch/loesungen/k4/4/main.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// main-Programm zur Simulation des Getränkeautomaten
#include"person.h"
#include"automat.h"
using namespace std;

int zufall(int x) {
  // gibt eine {\tt int}-Pseudo-Zufallszahl zwischen 0 und x zurück
    static long r = 1;
    r = (125 * r) % 8192;
                        // Arithmetik mit impliziter Typumwandlung:
    return static_cast<int>(r/8192.0*(x+1));
}

int main() {
    const int DOSENANZAHL = 50,
              DOSENPREIS  =  2,
              MAX_GELD    = 20;

    // Szenario
    GetraenkeAutomat objektColaAutomat(DOSENANZAHL, DOSENPREIS);

     // Der Konstruktor initialisiert den Automaten mit der
     // gewünschten Anzahl von Dosen und dem Dosenpreis.

    while (!objektColaAutomat.istGesperrt()) {
        // eine Person betritt die Szene:
        Person einePerson(zufall(MAX_GELD));

/*  Der Konstruktor erzeugt ein Objekt der Klasse {\tt Person }(siehe
    Text) mit Namen {\tt einePerson}, wobei das Objekt (das heißt sein
    Geldvorrat) mit einer zufälligen Zahl zwischen 0 und {\tt MAX\_GELD}
    initialisiert wird.
*/

        if(einePerson.genugGeld(
                       objektColaAutomat.getraenkePreis())) {
            // eine zufällig gewählte Anzahl Münzen wird eingeworfen,
            // aber nicht mehr als vorhanden:
            int wieviel = zufall(einePerson.wievielGeld());
            einePerson.geldEinwerfen(
                                 objektColaAutomat, wieviel);

            einePerson.knopfDruecken(objektColaAutomat);

            if (objektColaAutomat.rueckgeldVorhanden())
               einePerson.geldEntnehmen(
                        objektColaAutomat.geldRueckGabe());

            if (objektColaAutomat.doseHerausgegeben()) {
                einePerson.doseEntnehmen(objektColaAutomat);
                einePerson.trinkt();
            }

            if (objektColaAutomat.istGesperrt())
                cout << "Automat gesperrt! (leer)"  <<endl;
        }
        else einePerson.sagt(" Leider zuwenig Geld.");

    } // Blockende: die Studentin verlässt die Szene:
      //    hier automatisch realisiert durch den Destruktor
}
