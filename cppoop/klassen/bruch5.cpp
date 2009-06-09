/* Die folgenden Code-Beispiele stammen aus dem Buch:
 *  Objektorientiertes Programmieren in C++
 *   Ein Tutorial für Ein- und Umsteiger
 * von Nicolai Josuttis, Addison-Wesley München, 2001
 *
 * (C) Copyright Nicolai Josuttis 2001.
 * Diese Software darf kopiert, verwendet, modifiziert und verteilt
 * werden, sofern diese Copyright-Angabe in allen Kopien vorhanden ist.
 * Diese Software wird "so wie sie ist" zur Verfügung gestellt.
 * Es gibt keine explizite oder implizite Garantie über ihren Nutzen.
 */
// Headerdatei der Klasse einbinden
#include "bruch.hpp"

// Standard-Headerdateien einbinden
#include <cstdlib>

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

/* Default-Konstruktor, Konstruktor aus ganzer Zahl,
 * Konstruktor aus Zähler und Nenner
 * - Default für z: 0
 * - Default für n: 1
 */
Bruch::Bruch (int z, int n)
{
    /* Zähler und Nenner wie übergeben initialisieren
     * - 0 als Nenner ist allerdings nicht erlaubt
     * - ein negatives Vorzeichen des Nenners kommt in den Zähler
     */
    if (n == 0) {
        // neu:
        std::cerr << "Fehler: Nenner ist 0" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    if (n < 0) {
        zaehler = -z;
        nenner  = -n;
    }
    else {
        zaehler = z;
        nenner  = n;
    }
}

/* Operator *=
 */
const Bruch& Bruch::operator *= (const Bruch& b)
{
    // "x *= y"  ==>  "x = x * y"
    *this = *this * b;

    // Objekt (erster Operand) wird zurückgeliefert
    return *this;
}

/* Operator <
 */
bool Bruch::operator < (const Bruch& b) const
{
    // da die Nenner nicht negativ sein können, reicht:
    return zaehler * b.nenner < b.zaehler * nenner;
}

/* neu: printOn()
 * - Bruch auf Stream strm ausgeben
 */
void Bruch::printOn (std::ostream& strm) const
{
    strm << zaehler << '/' << nenner;
}

/* neu: scanFrom()
 * - Bruch von Stream strm einlesen
 */
void Bruch::scanFrom (std::istream& strm)
{
    int z, n;

    // Zähler einlesen
    strm >> z;

    // optionales Trennzeichen '/' und Nenner einlesen
    if (strm.peek() == '/') {
        strm.get();
        strm >> n;
    }
    else {
        n = 1;
    }

    // Lesefehler ?
    if (! strm) {
        return;
    }

    // Nenner == 0 ?
    if (n == 0) {
        // Fail-Bit setzen
        strm.clear (strm.rdstate() | std::ios::failbit);
        return;
    }

    /* OK, eingelesene Zahlen zuweisen
     * - ein negatives Vorzeichen des Nenners kommt in den Zähler
     */
    if (n < 0) {
        zaehler = -z;
        nenner  = -n;
    }
    else {
        zaehler = z;
        nenner  = n;
    }
}

} // **** ENDE Namespace Bsp ********************************
