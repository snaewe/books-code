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
#ifndef KOORD_HPP
#define KOORD_HPP

// Headerdatei für I/O
#include <iostream>

namespace Geo {

/* Klasse Koord
 * - Hilfsklasse für geometrische Objekte
 * - nicht zur Vererbung geeignet
 */
class Koord {
  private:
    int x;     // X-Koordinate
    int y;     // Y-Koordinate

  public:
    // Default-Konstruktor und Konstruktor aus zwei ints
    Koord () : x(0), y(0) {     // Default-Werte: 0
    }
    Koord (int newx, int newy) : x(newx), y(newy) {
    }

    Koord operator + (const Koord&) const;    // Addition
    Koord operator - () const;                // Negation
    void  operator += (const Koord&);         // +=
    void  printOn (ostream& strm) const;      // Ausgabe
};

/* Operator +
 * - X- und Y-Koordinaten addieren
 */
inline Koord Koord::operator + (const Koord& p) const
{
    return Koord(x+p.x,y+p.y);
}

/* einstelliger Operator -
 * - X- und Y-Koordinaten negieren
 */
inline Koord Koord::operator - () const
{
    return Koord(-x,-y);
}

/* Operator +=
 * - Offset auf X- und Y-Koordinaten aufaddieren
 */
inline void Koord::operator += (const Koord& p)
{
    x += p.x;
    y += p.y;
}

/* printOn()
 * - Koordinaten als Wertepaar ausgeben
 */
inline void Koord::printOn (ostream& strm) const
{
    strm << '(' << x << ',' << y << ')';
}

/* Operator <<
 * - Umsetzung für Standard-Ausgabeoperator
 */
inline ostream& operator<< (ostream& strm, const Koord& p)
{
    p.printOn (strm);
    return strm;
}

}  // namespace Geo

#endif // KOORD_HPP
