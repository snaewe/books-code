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
#ifndef LINIE_HPP
#define LINIE_HPP

// Headerdatei für I/O
#include <iostream>

// Headerdatei der Basisklasse
#include "geoobj.hpp"

namespace Geo {

/* Klasse Linie
 * - abgeleitet von GeoObj
 * - ein Linie besteht aus:
 *     - einem Anfangspunkt (Referenzpunkt, geerbt)
 *     - einem Endpunkt (neu)
 */
class Linie : public GeoObj {
  protected:
    Koord p2;    // zweiter Punkt, Endpunkt

  public:
    // Konstruktor für Anfangs- und Endpunkt
    Linie (const Koord& a, const Koord& b)
         : GeoObj(a), p2(b) {
    }

    // Ausgabe (jetzt auch implementiert)
    virtual void draw () const;

    // Verschieben (neu implementiert)
    virtual void move (const Koord&);

    // virtueller Destruktor
    virtual ~Linie () {
    }
};

/* Ausgabe
 * - inline definiert
 */
inline void Linie::draw () const
{
    std::cout << "Linie von " << refpunkt
              << " bis " << p2 << std::endl;
}

/* Verschieben
 * - inline neu implementiert
 */
inline void Linie::move (const Koord& offset)
{
    refpunkt += offset;    // entspricht GeoObj::move(offset);
    p2 += offset;
}

}  // namespace Geo

#endif // LINIE_HPP
