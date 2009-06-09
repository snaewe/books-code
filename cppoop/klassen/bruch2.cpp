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
// Headerdatei mit der Klassen-Deklaration einbinden
#include "bruch.hpp"

// Standard-Headerdateien einbinden
#include <iostream>
#include <cstdlib>

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

/* Default-Konstruktor
 */
Bruch::Bruch ()
 : zaehler(0), nenner(1)    // Bruch mit 0 initialisieren
{
    // keine weiteren Anweisungen
}

/* Konstruktor aus ganzer Zahl
 */
Bruch::Bruch (int z)
 : zaehler(z), nenner(1)    // Bruch mit z 1tel initialisieren
{
    // keine weiteren Anweisungen
}

/* Konstruktor aus Zähler und Nenner
 */
Bruch::Bruch (int z, int n)
{
    /* neu: Ein negatives Vorzeichen im Nenner kommt in den Zähler
     * Dies vermeidet u.a. eine Sonderbehandlung beim Operator <
     */
    if (n < 0) {
        zaehler = -z;
        nenner  = -n;
    }
    else {
        zaehler = z;
        nenner  = n;
    }

    // 0 als Nenner ist allerdings nicht erlaubt
    if (n == 0) {
        // Programm mit Fehlermeldung beenden
        std::cerr << "Fehler: Nenner ist 0" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

/* print
 */
void Bruch::print ()
{
    std::cout << zaehler << '/' << nenner << std::endl;
}

/* neu: Operator *
 */
Bruch Bruch::operator * (Bruch b)
{
    /* Zähler und Nenner einfach multiplizieren
     * - das Kürzen sparen wir uns
     */
    return Bruch (zaehler * b.zaehler, nenner * b.nenner);
}

/* neu: Operator *=
 */
Bruch Bruch::operator *= (Bruch b)
{
    // "x *= y"  ==>  "x = x * y"
    *this = *this * b;

    // Objekt, für das die Operation aufgerufen wurde (erster Operand), zurückliefern
    return *this;
}

/* neu: Operator <
 */
bool Bruch::operator< (Bruch b)
{
    /* Ungleichung einfach mit Nennern ausmultiplizieren
     * - da die Nenner nicht negativ sein können, kann
     *     der Vergleich dadurch nicht umgedreht werden
     */
    return zaehler * b.nenner < b.zaehler * nenner;
}

} // **** ENDE Namespace Bsp ********************************
