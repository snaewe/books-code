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
#ifndef BRUCH_HPP
#define BRUCH_HPP

// Standard-Headerdateien einbinden
#include <iostream>

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

class Bruch {

  private:
    int zaehler;
    int nenner;

  public:
    /* Default-Konstruktor, Konstruktor aus Zähler und
     * Konstruktor aus Zähler und Nenner
     */
    Bruch (int = 0, int = 1);
    // Multiplikation
    Bruch operator * (const Bruch&) const;
    
    // multiplikative Zuweisung
    const Bruch& operator *= (const Bruch&);
    
    // Vergleich
    bool operator < (const Bruch&) const;

    // neu: Ausgabe mit Streams
    void printOn (std::ostream&) const;

    // neu: Eingabe mit Streams
    void scanFrom (std::istream&);
};

/* Operator *
 * - inline definiert
 */
inline Bruch Bruch::operator * (const Bruch& b) const
{
    /* Zähler und Nenner einfach multiplizieren
     * - das Kürzen sparen wir uns
     */
    return Bruch (zaehler * b.zaehler, nenner * b.nenner);
}

/* neu: Standard-Ausgabeoperator
 * - global überladen und inline definiert
 */
inline
std::ostream& operator << (std::ostream& strm, const Bruch& b)
{
    b.printOn(strm);    // Elementfunktion zur Ausgabe aufrufen
    return strm;        // Stream zur Verkettung zurückliefern
}

/* neu: Standard-Eingabeoperator
 * - global überladen und inline definiert
 */
inline
std::istream& operator >> (std::istream& strm, Bruch& b)
{
    b.scanFrom(strm);   // Elementfunktion zur Eingabe aufrufen
    return strm;        // Stream zur Verkettung zurückliefern
}

} // **** ENDE Namespace Bsp ********************************

#endif  // BRUCH_HPP
