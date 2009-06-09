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
// Headerdatei der eigenen Klasse
#include "fstring.hpp"

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

/* Ausgabe auf Stream
 */
void FarbString::printOn (std::ostream& strm) const
{
    // Zeichenfolge mit Farbe in Klammern ausgeben
    String::printOn(strm);
    strm << " (in " << farb << ')';
}

/* Einlesen eines FarbStrings von einem Input-Stream
 */
void FarbString::scanFrom (std::istream& strm)
{
    // Inhalt und Farbe nacheinander einlesen
    String::scanFrom (strm);
    farb.scanFrom (strm);
}

} // **** ENDE Namespace Bsp ********************************

