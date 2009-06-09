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
//...
/* Operator <
 * - neu: globale Friend-Funktion
 */
bool operator < (const Bruch& a, const Bruch& b)
{
    // da die Nenner nicht negativ sein können, reicht:
    return a.zaehler * b.nenner < b.zaehler * a.nenner;
}
//...
