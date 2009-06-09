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
#include "person.hpp"

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

/* neu: statische Klassenkomponenten initialisieren
 */
long Person::personenMaxID = 0;
long Person::personenAnzahl = 0;

/* Konstruktor aus Nachname und Vorname
 * - Default für Vorname: ""
 * - Vor- und Nachname werden mit Initialisierungsliste initialisiert
 * - neu: Die ID wird ebenfalls direkt initialisiert
 */
Person::Person (const std::string& nn, const std::string& vn)
  : nname(nn), vname(vn), pid(++personenMaxID)
{
    ++personenAnzahl;  // Anzahl der existierenden Personen erhöhen
}

/* neu: Copy-Konstruktor
 */
Person::Person (const Person& p)
  : nname(p.nname), vname(p.vname), pid(++personenMaxID)
{
    ++personenAnzahl;  // Anzahl der existierenden Personen erhöhen
}

/* neu: Destruktor
 */
Person::~Person ()
{
    --personenAnzahl;  // Anzahl der existierenden Personen herabsetzen
}

/* neu: Zuweisung
 */
Person& Person::operator = (const Person& p)
{
    if (this == &p) {
        return *this;
    }

    // alles außer ID zuweisen
    nname = p.nname;
    vname = p.vname;

    return *this;
}

} // **** ENDE Namespace Bsp ********************************

