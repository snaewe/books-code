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
// Headerdatei für min() und abs()
#include <algorithm>
#include <cstdlib>

// Headerdatei der eigenen Klasse einbinden
#include "kbruch.hpp"

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

/* ggt()
 * - größter gemeinsamer Teiler von Zähler und Nenner
 */
unsigned KBruch::ggt () const
{
    if (zaehler == 0) {
        return nenner;
    }

    /* Größte Zahl ermitteln, die sowohl Zähler als auch
     * Nenner ohne Rest teilt
     */
    unsigned teiler = std::min(std::abs(zaehler),nenner);
    while (zaehler % teiler != 0  ||  nenner % teiler != 0) {
        teiler--;
    }
    return teiler;
}

/* kuerzen()
 */
void KBruch::kuerzen ()
{
    // falls kürzbar, Zähler und Nenner durch GGT teilen
    if (kuerzbar) {
        int teiler = ggt();

        zaehler /= teiler;
        nenner  /= teiler;

        kuerzbar = false;       // damit nicht mehr kürzbar
    }
}

/* Operator *=
 * - zum Überschreiben mit Typen der Basisklasse neu implementiert
 */
const KBruch& KBruch::operator*= (const Bruch& b)
{
    /* Implementierung der Basisklasse aufrufen
     * - auf nichtöffentliche Komponenten von b besteht kein Zugriff
     */
    Bruch::operator*= (b);

    // weiterhin gekürzt ?
    if (!kuerzbar) {
        kuerzbar = (ggt() > 1);
    }

    return  *this;
}

/* scanFrom()
 */
void KBruch::scanFrom (std::istream& strm)
{
    Bruch::scanFrom (strm);   // scanFrom() der Basisklasse aufrufen

    kuerzbar = (ggt() > 1);   // Kürzbarkeit testen
}

} // **** ENDE Namespace Bsp ********************************
